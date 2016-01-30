/* ____________________________________________________________________
 *
 * Copyright (c) 2003, Andrew N. Sloss, Dominic Symes, Chris Wright
 * All rights reserved.
 * ____________________________________________________________________
 * 
 * NON-COMMERCIAL USE License
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 *
 * 1. For NON-COMMERCIAL USE only.
 * 
 * 2. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 3. Redistributions in binary form must reproduce the above 
 *    copyright notice, this list of conditions and the following 
 *    disclaimer in the documentation and/or other materials provided 
 *    with the distribution. 
 *
 * 4. All advertising materials mentioning features or use of this 
 *    software must display the following acknowledgement:
 *
 *    This product includes software developed by Andrew N. Sloss,
 *    Chris Wright and Dominic Symes. 
 *
 *  THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY 
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 *  PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE CONTRIBUTORS BE 
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
 *  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR 
 *  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
 *  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 *  OF SUCH DAMAGE. 
 *
 * If you have questions about this license or would like a different
 * license please email : andrew@sloss.net
 *
 * 
 */

#include <stdio.h>

#include "regions.h"
#include "mmu.h"

#define uint unsigned int

/* Page Tables */
/* VADDRESS, PTADDRESS, MasterPTADDRESS PTTYPE, DOM */
Pagetable masterPT   = {0x00000000, 0x18000, 0x18000, MASTER, 3};
Pagetable systemPT   = {0x00000000, 0x1c000, 0x18000, COARSE, 3};
Pagetable task1PT    = {0x00400000, 0x1c400, 0x18000, COARSE, 3};
Pagetable task2PT    = {0x00400000, 0x1c800, 0x18000, COARSE, 3};
Pagetable task3PT    = {0x00400000, 0x1cc00, 0x18000, COARSE, 3};


/* REGION TABLES */
/*                        VADDRESS,PAGESIZE,NUMPAGES, AP, CB, PADDRESS,   &PT */
Region kernelRegion     = {0x00000000,    4,   16,  RWNA, WT, 0x00000000, &systemPT};
Region sharedRegion     = {0x00010000,    4,    8,  RWRW, WT, 0x00010000, &systemPT};
Region pageTableRegion  = {0x00018000,    4,    8,  RWNA, WT, 0x00018000, &systemPT};
Region peripheralRegion = {0x10000000, 1024,  256,  RWNA, cb, 0x10000000, &masterPT};

Region transferRegion = {0x00100000,   4,  8, RWNA, WT, 0x00018000, &systemPT};

/*-  Task Process Regions -*/
Region t1Region = {0x00400000,   4,  8, RWRW, WT, 0x00020000, &task1PT};
Region t2Region = {0x00400000,   4,  8, RWRW, WT, 0x00028000, &task2PT};
Region t3Region = {0x00400000,   4,  8, RWRW, WT, 0x00030000, &task3PT};


void activeProcessSet(Region *taskregion)
{
  flushCache();
  flushTLB();
  mmuAttachPT(taskregion->PT);
}


/*
 * Chapter 14 Example 14.1
 */
 
void ttbSet(unsigned int ttb)
{     
  __asm{MRC p15, 0, ttb, c2, c0, 0 } /* set translation table base */
}


/*
 * Chapter 14 Example 14.2
 */
 
int flushTLB(void)
{
  unsigned int c8format = 0 ;

  __asm{MCR p15, 0, c8format, c8, c7, 0 }   /* flush TLB */
  return 0;
}

/*
 * Chapter 14 Example 14.3
 */
 
void controlSet(unsigned int value, unsigned int mask)
{
  uint c1format;
     
  __asm{MRC p15, 0, c1format, c1, c0, 0 } /* read control register */
  c1format &= ~mask;                     /* clear bits that change */
  c1format |= value;                       /* set bits that change */
  __asm{MCR p15, 0, c1format, c1, c0, 0 }/* write control register */
}

/*
 * Chapter 14 Example 14.4
 */
 
void processIDSet(unsigned int value)
{
  unsigned int PID;
  PID = value << 25;

  __asm{MCR p15, 0, PID, c13, c0, 0 } /* write Process ID register */
}


/*
 * Chapter 14 Example 14.5
 */

int mmuInitPT(Pagetable *pt)
{
  int  index;     /* number of lines in PT/entries written per loop*/
  uint PTE, *PTEptr;           /* points to page table entry in PT */
  PTEptr = (uint *) pt->ptAddress;       /* set pointer to base PT */
  PTE = FAULT;
  

  switch (pt->type)
  { 
    case COARSE: {index =  256/32; break;} 
    case MASTER: {index = 4096/32; break;}
    #if defined(__TARGET_CPU_ARM920T) | \
        defined(__TARGET_CPU_ARM922T) | \
        defined(__TARGET_CPU_ARM926EJ_S)

    case FINE: {index = 1024/32; break;}  /* no FINE PT in 720T */
    #endif
    default:
    {
      printf("mmuInitPT: UNKNOWN pagetable type\n");
      return -1;
    } 
  } 
  __asm
  { 
    mov     r0, PTE 
    mov     r1, PTE 
    mov     r2, PTE
    mov     r3, PTE 
  }     
  for (; index != 0; index--) 
  {
    __asm
    {
      STMIA PTEptr!, {r0-r3}      /* write 32 entries to table */
      STMIA PTEptr!, {r0-r3}
      STMIA PTEptr!, {r0-r3} 
      STMIA PTEptr!, {r0-r3}  
      STMIA PTEptr!, {r0-r3}
      STMIA PTEptr!, {r0-r3} 
      STMIA PTEptr!, {r0-r3} 
      STMIA PTEptr!, {r0-r3}
    }     
  }
  return 0; 
}

/*
 * Chapter 14 Example 14.6
 */
 
int mmuMapRegion(Region *region)
{   
  switch (region->PT->type)
  { 
    case SECTION:                          /* map section in L1 PT */
    {
      mmuMapSectionTableRegion(region);
      break;
    }
    case COARSE:               /* map PTE to point to COARSE L2 PT */
    {
      mmuMapCoarseTableRegion(region);
      break;
    }
    #if defined(__TARGET_CPU_ARM920T) | \
    defined(__TARGET_CPU_ARM922T)
    case FINE:                   /* map PTE to point to FINE L2 PT */
    {
      mmuMapFineTableRegion(region);
      break;
    }
    #endif
    default:
    {
      printf("mmuMapRegion: UNKNOWN pagetable type\n");
      return -1;
    }
  }    
  return 0;
}

/*
 * Chapter 14 Example 14.7
 */

void mmuMapSectionTableRegion(Region *region)
{
  int i;
  uint *PTEptr, PTE;
   
  PTEptr = (uint *)region->PT->ptAddress;   /* get base address PT */
  PTEptr += region->vAddress >> 20;  /* set to first PTE in region */
  PTEptr += region->numPages - 1;     /* set to last PTE in region */

  PTE = region->pAddress & 0xfff00000;     /* set physical address */
  PTE |= (region->AP & 0x3) << 10;       /* set Access Permissions */
  PTE |= region->PT->dom    << 5;        /* set domain for section */
  PTE |= (region->CB & 0x3) << 2;     /* set cache & WB attributes */
  PTE |= 0x12;                             /* set as section entry */

  for (i =region->numPages - 1; i >= 0; i--) /* fill PTE in region */
  {
    *PTEptr-- = PTE + (i << 20);  /* i = 1 MB section */
  }
}

/*
 * Chapter 14 Example 14.8
 */

int mmuMapCoarseTableRegion(Region *region)
{
  int i,j;
  uint *PTEptr, PTE;
  uint tempAP = region->AP & 0x3;
   
  PTEptr = (uint *)region->PT->ptAddress; /* PTEptr = base addr PT */
   
  switch (region->pageSize)
  {
    case LARGEPAGE:
    {
      PTEptr += (region->vAddress & 0x000ff000) >> 12;  /* 1st PTE */
      PTEptr += (region->numPages*16) - 1;      /* region last PTE */

      PTE = region->pAddress & 0xffff0000; /* set physical address */
      PTE |= tempAP << 10;    /* set Access Permissions sub page 3 */
      PTE |= tempAP << 8;                            /* sub page 2 */
      PTE |= tempAP << 6;                            /* sub page 1 */
      PTE |= tempAP << 4;                            /* sub page 0 */
      PTE |= (region->CB & 0x3) << 2; /* set cache & WB attributes */
      PTE |= 0x1;                             /* set as LARGE PAGE */

                               /* fill in table entries for region */
      for (i = region->numPages-1; i >= 0; i--)
      {
        for (j = 15 ; j >= 0; j--)
          *PTEptr-- = PTE + (i << 16);     /* i = 64 KB large page */
      }
      break;
    }       
    case SMALLPAGE:
    {
      PTEptr += (region->vAddress & 0x000ff000) >> 12;   /* first  */
      PTEptr += (region->numPages - 1);             /* last PTEptr */

      PTE = region->pAddress & 0xfffff000; /* set physical address */
      PTE |= tempAP<<10;      /* set Access Permissions sub page 3 */
      PTE |= tempAP<<8;                              /* sub page 2 */
      PTE |= tempAP<<6;                              /* sub page 1 */
      PTE |= tempAP<<4;                              /* sub page 0 */
      PTE |= (region->CB & 0x3) << 2;     /* set cache & WB attrib */
      PTE |= 0x2;                             /* set as SMALL PAGE */

                               /* fill in table entries for region */
      for (i = region->numPages - 1; i >= 0; i--)
      {
        *PTEptr-- = PTE + (i << 12);        /* i = 4 KB small page */
      }
      break;             
    }
    default:
    { 
      printf("mmuMapCoarseTableRegion: Incorrect page size\n");
      return -1;
    }
  }
  return 0;
}

/*
 * Chapter 14 Example 14.9
 */

#if defined(__TARGET_CPU_ARM920T) | \
    defined(__TARGET_CPU_ARM922T)

int mmuMapFineTableRegion(Region *region)
{
  int i,j;
  uint *PTEptr, PTE;
  uint tempAP = region->AP & 0x3; 
   
  PTEptr = (uint *)region->PT->ptAddress; /* get base address PT */

  switch (region->pageSize)
  {
    case LARGEPAGE:
    {
      PTEptr += (region->vAddress & 0x000ffc00) >> 10; /* first PTE*/
      PTEptr += (region->numPages*64) - 1;             /* last PTE */

      PTE = region->pAddress & 0xffff0000; /* get physical address */
      PTE |= tempAP<<10;      /* set Access Permissions sub page 3 */
      PTE |= tempAP<<8;                              /* sub page 2 */
      PTE |= tempAP<<6;                              /* sub page 1 */
      PTE |= tempAP<<4;                              /* sub page 0 */
      PTE |= (region->CB & 0x3) << 2;     /* set cache & WB attrib */
      PTE |= 0x1;                             /* set as LARGE PAGE */

                               /* fill in table entries for region */
      for (i = region->numPages-1; i >= 0; i--)    
      {
        for (j = 63 ; j >= 0; j--)
          *PTEptr-- = PTE + (i << 16);     /* i = 64 KB large page */
      }
      break;
    }
    case SMALLPAGE:
    {
      PTEptr += (region->vAddress & 0x000ffc00) >> 10; /* first PTE*/
      PTEptr += (region->numPages*4) - 1;              /* last PTE */

      PTE = region->pAddress & 0xfffff000; /* get physical address */
      PTE |= tempAP<<10;      /* set Access Permissions sub page 3 */
      PTE |= tempAP<<8;                             /*  sub page 2 */
      PTE |= tempAP<<6;                             /*  sub page 1 */
      PTE |= tempAP<<4;                             /*  sub page 0 */
      PTE |= (region->CB & 0x3) << 2;     /* set cache & WB attrib */
      PTE |= 0x2;                             /* set as SMALL PAGE */

                               /* fill in table entries for region */
      for (i = region->numPages-1; i >= 0; i--)
      {
        for (j = 3 ; j >= 0; j--)
          *PTEptr-- = PTE + (i << 12);      /* i = 4 KB small page */
      }
      break;
    }
    case TINYPAGE:
    {
      PTEptr += (region->vAddress & 0x000ffc00) >> 10;    /* first */
      PTEptr += (region->numPages - 1);             /* last PTEptr */

      PTE = region->pAddress & 0xfffffc00; /* get physical address */
      PTE |=  tempAP << 4;               /* set Access Permissions */
      PTE |= (region->CB & 0x3) << 2;    /* set cache & WB attribu */
      PTE |= 0x3;                              /* set as TINY PAGE */

             /* fill table with PTE for region; from last to first */ 
     for (i =(region->numPages) - 1; i >= 0; i--)
      {
        *PTEptr-- = PTE + (i << 10);         /* i = 1 KB tiny page */
      }
      break;
    }
    default:
    { 
      printf("mmuMapFineTableRegion: Incorrect page size\n");
      return -1;
    }
  }
  return 0;
}
#endif

/*
 * Chapter 14 Example 14.10
 */

int mmuAttachPT(Pagetable *pt)     /* attach L2 PT to L1 master PT */
{
  uint *ttb, PTE, offset; 

  ttb = (uint *)pt->masterPtAddress;        /* read ttb from PT */
  offset = (pt->vAddress) >> 20;    /* determine PTE from vAddress */
   
  switch (pt->type)
  { 
    case MASTER:
    {
      __asm{ MCR p15, 0, ttb, c2, c0, 0 } ;   /* TTB -> CP15:c2:c0 */
      break;
    }  
    case COARSE:
    {
                      /* PTE = addr L2 PT | domain | COARSE PT type*/
      PTE = (pt->ptAddress & 0xfffffc00);
      PTE |= pt->dom <<5;
      PTE |= 0x11; 
      ttb[offset] = PTE;             
      break;
    }
    #if defined(__TARGET_CPU_ARM920T) | \
        defined(__TARGET_CPU_ARM922T)
    case FINE:
    {
                        /* PTE = addr L2 PT | domain | FINE PT type*/
      PTE = (pt->ptAddress & 0xfffff000);
      PTE |= pt->dom <<5;
      PTE |= 0x13;
      ttb[offset] = PTE;             
      break;
    }
    #endif
    default:
    {
      printf("mmuAttachPT: UNKNOWN pagetable type\n");
      return -1;
    }
  }  
  return 0;
}

/*
 * Chapter 14 Example 14.11
 */


void domainAccessSet(unsigned value, unsigned mask)
{
  uint c3format;
     
  __asm{MRC p15, 0, c3format, c3, c0, 0 }  /* read domain register */
  c3format &= ~mask;                     /* clear bits that change */
  c3format |= value;                       /* set bits that change */
  __asm{MCR p15, 0, c3format, c3, c0, 0 } /* write domain register */
}


int flushCache(void)
{
  unsigned int c7format = 0 ;
     
  __asm{MCR p15, 0, c7format, c7,c7, 0 }   /* flush i & d Cache */
   return 0;
}


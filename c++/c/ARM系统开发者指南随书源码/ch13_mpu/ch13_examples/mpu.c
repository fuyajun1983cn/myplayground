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

/*
 * Chapter 13 Example 13.1
 */
 
#if defined( __TARGET_CPU_ARM940T)
#define SET_REGION(REGION_NUMBER) \
            /* set Dregion base & size */ \
  __asm{MCR p15, 0, c6f, c6, c ## REGION_NUMBER, 0 } \
            /* set Iregion base & size */ \
  __asm{MCR p15, 0, c6f, c6, c ## REGION_NUMBER, 1 }  
#endif

#if defined(__TARGET_CPU_ARM946E_S) | \
    defined(__TARGET_CPU_ARM1026EJ_S)
#define SET_REGION(REGION_NUMBER) \
            /* set region base & size */ \
  __asm{MCR p15, 0, c6f, c6, c ## REGION_NUMBER, 0 } 
#endif

void regionSet(unsigned region, unsigned address, 
               unsigned sizeN, unsigned enable)
{
  unsigned c6f;

  c6f = enable | (sizeN<<1) | address;
  switch (region)
  {
    case 0: { SET_REGION(0); break;}
    case 1: { SET_REGION(1); break;}
    case 2: { SET_REGION(2); break;}
    case 3: { SET_REGION(3); break;}
    case 4: { SET_REGION(4); break;}
    case 5: { SET_REGION(5); break;}
    case 6: { SET_REGION(6); break;}
    case 7: { SET_REGION(7); break;}
    default: { break; }
  }
}

/*
 * Chapter 13 Example 13.2
 */
   
void regionSetISAP(unsigned region, unsigned ap)
{
  unsigned c5f, shift;
  
  shift = 2*region;
  __asm{ MRC p15, 0, c5f, c5, c0, 1 } /* load standard D AP */
  c5f = c5f &~ (0x3<<shift);          /* clear old AP bits */
  c5f = c5f | (ap<<shift);           /* set new AP bits */
  __asm{ MCR p15, 0, c5f, c5, c0, 1 } /* store standard D AP */
}

void regionSetDSAP(unsigned region, unsigned ap)
{
  unsigned c5f, shift;
  
  shift = 2*region;                   /* set bit field width */
  __asm{ MRC p15, 0, c5f, c5, c0, 0 } /* load standard I AP */
  c5f = c5f &~ (0x3<<shift);          /* clear old AP bits */
  c5f = c5f | (ap<<shift);           /* set new AP bits */
  __asm{ MCR p15, 0, c5f, c5, c0, 0 } /* store standard I AP */
}


/*
 * Chapter 13 Example 13.3
 */
   

void regionSetIEAP(unsigned region, unsigned ap)
{
  unsigned c5f, shift;
  
  shift = 4*region;                   /* set bit field width */
  __asm{ MRC p15, 0, c5f, c5, c0, 3 } /* load extended D AP */
  c5f = c5f &~ (0xf<<shift);          /* clear old AP bits */
  c5f = c5f | (ap<<shift);           /* set new AP bits */
  __asm{ MCR p15, 0, c5f, c5, c0, 3 } /* store extended D AP */
}
void regionSetDEAP(unsigned region, unsigned ap)
{
  unsigned c5f, shift;
  
  shift = 4*region;                   /* set bit field width */
  __asm{ MRC p15, 0, c5f, c5, c0, 2 } /* load extended I AP */
  c5f = c5f &~ (0xf<<shift);          /* clear old AP bits */
  c5f = c5f | (ap<<shift);           /* set new AP bits */
  __asm{ MCR p15, 0, c5f, c5, c0, 2 } /* store extended I AP */
}


/*
 * Chapter 13 Example 13.4
 */
 
/* Set Cache and Buffer Attributes
 * for Instruction and Data Regions
 * 
 */


void regionSetCB(unsigned region, unsigned CB)
{
  unsigned c3f, tempCB;
  
  tempCB = CB; 
  __asm{MRC p15, 0, c3f, c3, c0, 0 }    /* load buffer register */
  c3f = c3f &~ (0x1<<region);           /* clear old buffer bit */
  c3f = c3f | ((tempCB & 0x1)<<region); /* set new buffer bit */
  __asm{MCR p15, 0, c3f, c3, c0, 0 }    /* store buffer info */

  tempCB = CB>>0x1;                     /* shift to D-cache bit */
  __asm{MRC p15, 0, c3f, c2, c0, 0 }    /* load D-cache register */
  c3f = c3f &~ (0x1<<region);           /* clear old D-cache bit */ 
  c3f = c3f | ((tempCB & 0x1)<<region); /* set new D-cache bit */
  __asm{MCR p15, 0, c3f, c2, c0, 0 }    /* store D-cache info */

  tempCB = CB>>0x2;                     /* shift to I-cache bit */
  __asm{MRC p15, 0, c3f, c2, c0, 1 }    /* load I-cache register */
  c3f = c3f &~ (0x1<<region);           /* clear old I-cache bit */ 
  c3f = c3f | ((tempCB & 0x1)<<region); /* set new I-cache bit */
  __asm{MCR p15, 0, c3f, c2, c0, 1 }    /* store I-cache info */
}


/*
 * Chapter 13 Example 13.5
 */
 
void controlSet(unsigned value, unsigned mask)
{
    unsigned int c1f;
     
  __asm{MRC p15, 0, c1f, c1, c0, 0  }  /* read control register */
  c1f = c1f &~ mask;                   /* mask off bit that change */
  c1f = c1f | value;                   /* set bits that change */
  __asm{ MCR p15, 0, c1f, c1, c0, 0  } /* write control register */
}



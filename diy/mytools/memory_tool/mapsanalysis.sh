#!/sbin/sh

MEM_TH="1024"
PROCRANK=/tmp/procrank
PROCMEM=/tmp/procmem
SHOWMAP=/tmp/showmap
procrank | grep '^[ ]*[0-9][0-9]*' > $PROCRANK

Color_Off='\e[0m'
IBlack='\e[0;90m'       # Black
IRed='\e[0;91m'         # Red
IGreen='\e[0;92m'       # Green
IYellow='\e[0;93m'      # Yellow
IBlue='\e[0;94m'        # Blue
IPurple='\e[0;95m'      # Purple
ICyan='\e[0;96m'        # Cyan
IWhite='\e[0;97m'       # White

PSS_SUM=0
ASH_SUM=0
MALI_SUM=0
UMP_SUM=0
ANON_SUM=0
MALI_SUM=0
UMP_SUM=0
MMAP_SUM=0
HEAP_SUM=0
DALVIK_SUM=0
SLIB_SUM=0
DEX_SUM=0
OTHER_SUM=0

if [ $# -eq 1 ]; 
then
  CHECK_PROC_ONLY=$1;
fi
 
echo -e "-------------------------------------------------------------------------------------------------"
echo -e "  ${IBlue} pid   pss   anon (   mali    ump   mmap ) ashmem   heap dalvik   slib    dex  other oom_adj       name ${Color_Off}"
echo -e "-------------------------------------------------------------------------------------------------"

while read line;
do
#   echo $line
    pid=`echo $line | awk '{print $1}'`
    pss=`echo $line | awk '{print $4}' | sed s/K//g`
    name=`echo $line | awk '{print $6}'`
  
    # Only check for user specific process name 
    if ! [ -z $CHECK_PROC_ONLY ]; then
       if ! [ $name == $CHECK_PROC_ONLY ]; then
           continue
       fi
    fi
    
    if [ $pss -lt $MEM_TH ] ; then
    	break;
    fi    
     
    # Based on PSS 
    # showmap
    showmap $pid > $SHOWMAP
    anon=`cat $SHOWMAP | awk '{if($9=="[anon]") print $3}'`
    heap=`cat $SHOWMAP | awk '{if($9=="[heap]") print $3}'`    
    ashmem=`cat $SHOWMAP | grep -v dalvik | grep ashmem | awk 'BEGIN{SUM=0} {SUM+=$3} END{print SUM}'`
    dalvik=`cat $SHOWMAP | grep -v "\.dex" | grep dalvik | awk 'BEGIN{SUM=0} {SUM+=$3} END{print SUM}'`
    slib=`cat $SHOWMAP |grep "\.so" | awk 'BEGIN{SUM=0} {SUM+=$3} END{print SUM}'`
    dex=`cat $SHOWMAP |grep "\.dex$" | awk 'BEGIN{SUM=0} {SUM+=$3} END{print SUM}'`
    rm $SHOWMAP
    
    # procmem
    procmem $pid > $PROCMEM
    mali=`cat $PROCMEM | grep /dev/mali | awk 'BEGIN{SUM=0} {SUM+=$3} END{print SUM}'`
    ump=`cat $PROCMEM | grep /dev/ump | awk 'BEGIN{SUM=0} {SUM+=$3} END{print SUM}'`
    mmap=$((anon-mali-ump))
    rm $PROCMEM
    other=$((pss-ashmem-anon-heap-dalvik-slib-dex)) 
    oom_adj=`cat /proc/$pid/oom_adj`
        
    PSS_SUM=$((PSS_SUM+pss))
    ASH_SUM=$((ASH_SUM+ashmem))    
    ANON_SUM=$((ANON_SUM+anon))
    MALI_SUM=$((MALI_SUM+mali))
    UMP_SUM=$((UMP_SUM+ump))
    MMAP_SUM=$((MMAP_SUM+mmap))
    HEAP_SUM=$((HEAP_SUM+heap))    
    DALVIK_SUM=$((DALVIK_SUM+dalvik))   
    SLIB_SUM=$((SLIB_SUM+slib))
    DEX_SUM=$((DEX_SUM+dex))
    OTHER_SUM=$((OTHER_SUM+other))

    #      pid pss anon (mali ump mmap) ashmem heap dalvik slib dex other oom_adj name       
    printf "%5d %6d %6d ( %6d %6d %6d ) %6d %6d %6d %6d %6d %6d %6d %s\n" $pid $pss $anon $mali $ump $mmap $ashmem $heap $dalvik $slib $dex $other $oom_adj $name

    # Only check for user specific process name
    if ! [ -z $CHECK_PROC_ONLY ]; then
    	exit
    fi
done < $PROCRANK

rm $PROCRANK

echo "-------------------------------------------------------------------------------------------------"
#             pss anon (mali ump mmap) ashmem heap dalvik slib dex other 
printf "      %6d %6d ( %6d %6d %6d ) %6d %6d %6d %6d %6d %6d\n" $PSS_SUM $ANON_SUM $MALI_SUM $UMP_SUM $MMAP_SUM $ASH_SUM $HEAP_SUM $DALVIK_SUM $SLIB_SUM $DEX_SUM $OTHER_SUM

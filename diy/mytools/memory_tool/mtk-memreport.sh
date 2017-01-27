#!/sbin/sh
PROCRANK=/tmp/procrank
MEMMAPS=/tmp/memmaps

Color_Off='\e[0m'
IBlack='\e[0;90m'       # Black
IRed='\e[0;91m'         # Red
IGreen='\e[0;92m'       # Green
IYellow='\e[0;93m'      # Yellow
IBlue='\e[0;94m'        # Blue
IPurple='\e[0;95m'      # Purple
ICyan='\e[0;96m'        # Cyan
IWhite='\e[0;97m'       # White

echo 1 > /proc/sys/vm/drop_caches

#### Show FBM layout 
echo "=== FBM layout ==="
cli_shell "fbm.d_l 7" > /dev/null
cli_shell "fbm.q" | grep  "^\[FBM\]Addr" | grep -v TOTAL | awk 'FS="[(|)| ]" {printf("%s %s %10s ===> %3d MB %s %s\n", $2, $8, $16, $5/(1024*1024))}' | sort -n
cli_shell "fbm.q" | grep  "^\[FBM\]Addr" | grep -w TOTAL | awk 'FS="[(|)| ]" {printf("%s %s %10s ===> %3d MB %s %s\n", $2, $8, $16, $5/(1024*1024))}'
echo ""
 
#### Show overall memory profile
echo "=== Overall Memory Profile ==="
PROCRANK=/tmp/procrank
procrank > $PROCRANK

i_kernel_total=`free | grep Mem: | awk '{print $2}'`
i_used=`free | grep Mem: | awk '{print $3}'`
i_free=`free | grep Mem: | awk '{print $4}'`
i_cache=`cat $PROCRANK | grep RAM | awk '{print $8}' | sed s/K//`
i_pss=`cat $PROCRANK | grep TOTAL | awk '{print $1}' | sed s/K//`
i_uss=`cat $PROCRANK | grep TOTAL | awk '{print $2}' | sed s/K//`

rm $PROCRANK

i_usersum=$((i_cache+i_pss))
i_kernel=$((i_used-i_usersum))
i_shared=$((i_pss-i_uss))

mapsanalysis.sh > $MEMMAPS
i_pss_care=`cat $MEMMAPS | tail -1 | awk '{print $1}'`
i_anon=`cat $MEMMAPS | tail -1 | awk '{print $2}'`
i_mali=`cat $MEMMAPS | tail -1 | awk '{print $4}'`
i_ump=`cat $MEMMAPS | tail -1 | awk '{print $5}'`
i_mmap=`cat $MEMMAPS | tail -1 | awk '{print $6}'`
i_ashmem=`cat $MEMMAPS | tail -1 | awk '{print $8}'`
i_heap=`cat $MEMMAPS | tail -1 | awk '{print $9}'`
i_dalvik=`cat $MEMMAPS | tail -1 | awk '{print $10}'`
i_slib=`cat $MEMMAPS | tail -1 | awk '{print $11}'`
i_dex=`cat $MEMMAPS | tail -1 | awk '{print $12}'`
i_user_other=`cat $MEMMAPS | tail -1 | awk '{print $13}'`

i_pss_ignore=$((i_pss-i_pss_care))

# Get KO size
i_ko=`lsmod | awk '{SUM+=$2} END{ printf("%d\n", SUM/1024)}'`


### Get Kernel reservated memory size from dmesg
# extrac 302 * 1024 from 
#     "Memory: 302MB = 302MB total"
#i_kernel_phy=$((`dmesg |grep "^Memory:" | grep total | awk '{print $2}' | sed s/MB//` * 1024))
#i_kernel_code=$((i_kernel_phy-i_kernel_total))

# extract 293788 from 
#     "Memory: 293788k/293788k available, 15460k reserved, 0K highmem"
#i_kernel_avil=`dmesg | grep "^Memory:" | grep available | awk '{FS="[ /]"; print $2}' | sed s/k//`

#i_resv=$((i_kernel_total-i_kernel_avil))
i_kernel_other=$((i_kernel-i_ko))

i_swap_total=`free | grep Swap | awk '{print $2}'`
i_swap_used=`free | grep Swap | awk '{print $3}'`
i_swap_free=`free | grep Swap | awk '{print $4}'`

echo -e "Kernel Total: $i_kernel_total"
echo -e "  - Free:  ${IRed}$i_free${Color_Off}"
echo -e "  - Used:  $i_used"
echo -e "-----------------"
echo -e "    -- Cache:          $i_cache ($((100*i_cache/i_used))%)"
echo -e ""
echo -e "    -- Kernel:         $i_kernel ($((100*i_kernel/i_used))%)"
echo -e "-------------------------------"
echo -e "       --- ko:    $i_ko"
echo -e "       --- other:   ${IGreen}$i_kernel_other${Color_Off}"
echo -e ""
echo -e "    -- Swap:"
echo -e "-------------------------------"
echo -e "       --- total: $i_swap_total"   
echo -e "       --- used:  $i_swap_used"
echo -e "       --- free:  $i_swap_free"
echo -e ""
echo -e "    -- PSS:             $i_pss_care ($((100*i_pss_care/i_used))%)"
echo -e "-------------------------------"
echo -e "       --- mali:   ($((100*i_mali/i_pss_care))%) $i_mali"
echo -e "       --- ump:    ($((100*i_ump/i_pss_care))%) $i_ump"
echo -e "       --- mmap:   ($((100*i_mmap/i_pss_care))%) $i_mmap"
echo -e "       --- ashmem: ($((100*i_ashmem/i_pss_care))%) $i_ashmem"
echo -e "       --- heap:   ($((100*i_heap/i_pss_care))%) $i_heap"
echo -e "       --- dalvik: ($((100*i_dalvik/i_pss_care))%) $i_dalvik"
echo -e "       --- slib:   ($((100*i_slib/i_pss_care))%) $i_slib"
echo -e "       --- dex:    ($((100*i_dex/i_pss_care))%) $i_dex"
echo -e "       --- others: ($((100*i_user_other/i_pss_care))%) $i_user_other"
echo -e ""
echo -e "    -- Ignore Pss:      $i_pss_ignore ($((100*i_pss_ignore/i_used))%)"
echo -e ""

#### Show detail process memory map
echo "=== Detail Process Profile ==="
cat $MEMMAPS
echo ""

rm $MEMMAPS

#### Show lowmemory killer  
echo "=== Show Low Memory Killer Parameters ==="
echo "/sys/module/lowmemorykiller/parameters/adj"
cat /sys/module/lowmemorykiller/parameters/adj

echo 
echo "/sys/module/lowmemorykiller/parameters/minfree"
cat /sys/module/lowmemorykiller/parameters/minfree

<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1425696768250" ID="ID_372865185" MODIFIED="1425697153064" TEXT="&#x4e2a;&#x4eba;&#x5b66;&#x4e60;&#x8fdb;&#x5ea6;&#x8ddf;&#x8e2a;&#x4e0e;&#x5fae;&#x7b14;&#x8bb0;">
<icon BUILTIN="male1"/>
<node CREATED="1425696788344" ID="ID_144679693" MODIFIED="1425697594321" POSITION="right" TEXT="C++"/>
<node CREATED="1425696795817" ID="ID_1884221012" MODIFIED="1425696799217" POSITION="right" TEXT="Python">
<node CREATED="1425697021014" ID="ID_655518250" MODIFIED="1425697032699" TEXT="Learning Python 4th"/>
</node>
<node CREATED="1425696814301" ID="ID_1263332819" MODIFIED="1425696853125" POSITION="right" TEXT="Linux&#x5185;&#x6838;">
<node CREATED="1425697125410" ID="ID_111836876" MODIFIED="1425697383052" TEXT="pagemap&#x7814;&#x7a76;">
<font NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="help"/>
</node>
<node CREATED="1425711227855" ID="ID_1115887000" MODIFIED="1425711236550" TEXT="dmabuf-fence"/>
<node CREATED="1425716258146" ID="ID_737150402" MODIFIED="1425716259455" TEXT="fuse"/>
<node CREATED="1425715665255" ID="ID_111558705" MODIFIED="1425715672248" TEXT="&#x5185;&#x6838;&#x5e38;&#x7528;&#x51fd;&#x6570;&#x8bb0;&#x5f55;">
<node CREATED="1425715677008" ID="ID_847058680" MODIFIED="1425715691450" TEXT="ktime_to_timeval()">
<node CREATED="1425715693999" ID="ID_686855668" MODIFIED="1425715712062" TEXT="ktime&#x4e0e;timeval&#x7684;&#x8f6c;&#x6362;"/>
</node>
<node CREATED="1425716470779" ID="ID_382907830" MODIFIED="1425716487869" TEXT="msecs_to_jiffies">
<node CREATED="1425716608201" ID="ID_128715679" MODIFIED="1425716616775" TEXT="jiffies_to_msecs"/>
<node CREATED="1425716617260" ID="ID_1988212346" MODIFIED="1425716640394" TEXT="jiffies&#x4e0e;&#x6beb;&#x79d2;&#x76f8;&#x4e92;&#x8f6c;&#x6362;"/>
</node>
<node CREATED="1425716785306" ID="ID_744744666" MODIFIED="1425716791544" TEXT="get_unused_fd()"/>
<node CREATED="1425717011339" ID="ID_387033198" MODIFIED="1425783989637" TEXT="annon_inode_getfile()">
<node CREATED="1425717023130" ID="ID_1519074846" MODIFIED="1425717058688" TEXT="creates a new file instance by hooking it up to an anonymouse inode, and a dentry that describe the &quot;class&quot; of the file"/>
<node CREATED="1425717067188" ID="ID_1961523815" MODIFIED="1425717099375" TEXT="this is useful for file that don&apos;t need to have a full-fledged inode in order to operate correctly"/>
<node CREATED="1425717099802" ID="ID_264646861" MODIFIED="1425717125910" TEXT="all files created with annon_inode_getfile() will share a single inode"/>
</node>
<node CREATED="1425783990903" ID="ID_16956036" MODIFIED="1425784004614" TEXT="annon_inode_getfd(): int fd"/>
<node CREATED="1425783745566" ID="ID_864949710" MODIFIED="1425783779638">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      files_struct: files_fdtable
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425783878465" ID="ID_243855787" MODIFIED="1425783895758" TEXT="fget(fd):struct file"/>
</node>
</node>
<node CREATED="1425696856650" ID="ID_271636846" MODIFIED="1425696863313" POSITION="right" TEXT="Android">
<node CREATED="1425696889186" ID="ID_1784653940" MODIFIED="1425696891751" TEXT="adb"/>
<node CREATED="1425696892825" ID="ID_1480950932" MODIFIED="1425696906309" TEXT="dalvik&#x865a;&#x62df;&#x673a;&#x7814;&#x7a76;"/>
<node CREATED="1425813807785" ID="ID_347950936" MODIFIED="1425813815608" TEXT="binder driver&#x7814;&#x7a76;">
<node CREATED="1425813819930" ID="ID_1037525273" MODIFIED="1425813819930" TEXT=""/>
</node>
<node COLOR="#669900" CREATED="1425711093615" FOLDED="true" ID="ID_154192510" MODIFIED="1427117550461" TEXT="Android Sync Framework">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="button_ok"/>
<node CREATED="1425711666658" ID="ID_601017051" MODIFIED="1425711817025" TEXT="Synchronization between consumers and producers  who are from different hardware components to use a buffer atomically"/>
<node CREATED="1425722337780" ID="ID_1800332804" MODIFIED="1425722349419" TEXT="Sync&#x9a71;&#x52a8;&#x5305;&#x542b;&#x90e8;&#x5206;&#xff1a;">
<node CREATED="1425722358560" ID="ID_548815381" MODIFIED="1425722397426" TEXT="fence&#x7684;&#x901a;&#x7528;&#x64cd;&#x4f5c;&#xff0c;&#x5df2;&#x7ecf;&#x5b9e;&#x73b0;"/>
<node CREATED="1425722367841" ID="ID_1668547385" MODIFIED="1425722431778" TEXT="&#x5404;&#x4e2a;sync &#x9a71;&#x52a8;&#x76f8;&#x5173;&#x7684;&#x4ee3;&#x7801;&#xff0c;&#x7531;&#x5404;&#x4e2a;&#x786c;&#x4ef6;Vendor&#x5b9e;&#x73b0;&#xff0c;&#x5176;&#x4e2d;&#xff0c;&#x5176;&#x4e2d;CPU&#x7684;sync&#x9a71;&#x52a8;&#x5df2;&#x7ecf;&#x63d0;&#x4f9b;"/>
</node>
<node CREATED="1425712415179" ID="ID_179904837" MODIFIED="1425712421007" TEXT="&#x5185;&#x6838;&#x5c42;">
<node CREATED="1425711827200" ID="ID_583329442" MODIFIED="1425711832656" TEXT="&#x4e3b;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node CREATED="1425711836143" ID="ID_73175028" MODIFIED="1425784623867" TEXT="struct sync_timeline_ops">
<node CREATED="1425711948960" ID="ID_660855775" MODIFIED="1425711968409" TEXT="sync&#x5bf9;&#x8c61;&#x9700;&#x8981;&#x5b9e;&#x73b0;&#x7684;&#x4e00;&#x4e9b;&#x64cd;&#x4f5c;"/>
</node>
<node CREATED="1425711973220" ID="ID_966824187" MODIFIED="1425712029888" TEXT="struct sync_timeline">
<node CREATED="1425712039665" ID="ID_1227769499" MODIFIED="1425712047326" TEXT="&#x4ee3;&#x8868;&#x4e00;&#x4e2a;sync&#x5bf9;&#x8c61;&#x7684;&#x63cf;&#x8ff0;"/>
<node CREATED="1425712086907" ID="ID_324805483" MODIFIED="1425712097015" TEXT="&#x5b83;&#x5305;&#x542b;&#x8bb8;&#x591a;struct sync_pt"/>
</node>
<node CREATED="1425712098831" ID="ID_549650238" MODIFIED="1425712104578" TEXT="struct sync_pt">
<node CREATED="1425712107401" ID="ID_250009415" MODIFIED="1425712116978" TEXT="&#x540c;&#x6b65;&#x70b9;"/>
<node CREATED="1425712143034" ID="ID_566154104" MODIFIED="1425712147715" TEXT="&#x6709;&#x4e09;&#x79cd;&#x72b6;&#x6001;">
<node CREATED="1425712149936" ID="ID_1718426410" MODIFIED="1425715511800" TEXT="signaled(status &gt; 0)"/>
<node CREATED="1425712154554" ID="ID_342907459" MODIFIED="1425715552539" TEXT="active(status = 0)"/>
<node CREATED="1425712158609" ID="ID_469977566" MODIFIED="1425715558365" TEXT="error(status &lt; 0)"/>
</node>
<node CREATED="1425712204005" ID="ID_486530130" MODIFIED="1425712236999" TEXT="&#x5b83;&#x4f4d;&#x4e8e;&#x4e00;&#x4e2a;sync_timeline&#x4ee5;&#x53ca;sync_fence&#x4e2d;"/>
</node>
<node CREATED="1425712243416" ID="ID_869531533" MODIFIED="1425712255838" TEXT="struct sync_fence"/>
<node CREATED="1425712333265" ID="ID_150137498" MODIFIED="1425712340274" TEXT="struct sync_fence_waiter">
<node CREATED="1425712360033" ID="ID_1930850029" MODIFIED="1425712389325" TEXT="&#x5bf9;&#x4e00;&#x4e2a;fence&#x4e0a;&#x5f02;&#x6b65;&#x7b49;&#x5f85;&#x7684;waiter&#x7684;&#x76f8;&#x5173;&#x4fe1;&#x606f;"/>
</node>
</node>
<node CREATED="1425712428536" ID="ID_733310547" MODIFIED="1425712435507" TEXT="&#x4e3b;&#x8981;API">
<node CREATED="1425714542673" ID="ID_1648032290" MODIFIED="1425716896006" TEXT="API focomponentsr sync_time implementers">
<node CREATED="1425712475379" ID="ID_1222482388" MODIFIED="1425712488079" TEXT="sync_timeline_create()">
<node CREATED="1425712491331" ID="ID_799007133" MODIFIED="1425712501187" TEXT="  &#x521b;&#x5efa;&#x4e00;&#x4e2a;sync&#x5bf9;&#x8c61;"/>
</node>
<node CREATED="1425712508916" ID="ID_552862214" MODIFIED="1425712516459" TEXT="sync_timeline_destory()">
<node CREATED="1425712522165" ID="ID_1311343818" MODIFIED="1425712531097" TEXT="&#x9500;&#x6bc1;&#x4e00;&#x4e2a;sync&#x5bf9;&#x8c61;"/>
</node>
<node CREATED="1425712540196" ID="ID_1315130700" MODIFIED="1425712550050" TEXT="sync_timeline_signal()">
<node CREATED="1425712552958" ID="ID_1137935979" MODIFIED="1425712574906" TEXT="signal a status change on a sync_timeline"/>
</node>
<node CREATED="1425714378713" ID="ID_1676808303" MODIFIED="1425714388468" TEXT="sync_pt_create()">
<node CREATED="1425714393047" ID="ID_1572604294" MODIFIED="1425714398408" TEXT="&#x521b;&#x5efa;&#x4e00;&#x4e2a;&#x540c;&#x6b65;&#x70b9;"/>
</node>
<node CREATED="1425714407162" ID="ID_832046173" MODIFIED="1425714413594" TEXT="sync_pt_free()">
<node CREATED="1425714417419" ID="ID_1713958985" MODIFIED="1425714438854" TEXT="&#x91ca;&#x653e;&#x4e00;&#x4e2a;&#x540c;&#x6b65;&#x70b9;"/>
<node CREATED="1425714440355" ID="ID_1829060558" MODIFIED="1425714464772" TEXT="&#x8fd9;&#x4e2a;&#x51fd;&#x6570;&#x4ec5;&#x80fd;&#x5728;&#x8be5;&#x540c;&#x6b65;&#x70b9;&#x672a;&#x52a0;&#x5165;&#x5230;&#x4e00;&#x4e2a;fence&#x524d;&#x8c03;&#x7528;"/>
</node>
<node CREATED="1425714471758" ID="ID_954860727" MODIFIED="1425714480583" TEXT="sync_fence_create()">
<node CREATED="1425714485695" ID="ID_1480465760" MODIFIED="1425714495224" TEXT="&#x521b;&#x5efa;&#x4e00;&#x4e2a;sync fence"/>
</node>
</node>
<node CREATED="1425714610755" ID="ID_837927676" MODIFIED="1425714631655" TEXT="API for sync_fence consumers">
<node CREATED="1425714665044" ID="ID_1499757283" MODIFIED="1425714673949" TEXT="sync_fence_merge()">
<node CREATED="1425714676271" ID="ID_1162659605" MODIFIED="1425714685147" TEXT="&#x5408;&#x5e76;&#x4e24;&#x4e2a;fence"/>
<node CREATED="1425717454811" ID="ID_743443029" MODIFIED="1427027227271" TEXT="&#x5355;&#x4e24;&#x4e2a;sync_pt&#x4f4d;&#x4e8e;&#x540c;&#x4e00;&#x4e2a;timeline&#x65f6;&#xff0c;&#x9700;&#x8981;&#x5c06;&#x4ed6;&#x4eec;&#x5408;&#x5e76;&#x6210;&#x4e00;&#x4e2a;sync_pt&#xff0c;&#xa;&#x5e76;&#x4fbf;&#x89e6;&#x53d1;&#x65f6;&#x95f4;&#x6700;&#x665a;&#x4e9b;&#x7684;&#x90a3;&#x4e2a;sync_pt&#x90a3;&#x4e2a;&#x4e3a;&#x51c6;"/>
</node>
<node CREATED="1425714689477" ID="ID_1825355142" MODIFIED="1425714708778" TEXT="sync_fence_fdget()">
<node CREATED="1425714714808" ID="ID_668571668" MODIFIED="1425714749169" TEXT="&#x6839;&#x636e;&#x4e00;&#x4e2a;fd&#x83b7;&#x53d6;&#x5bf9;&#x5e94;&#x7684;fence&#x5bf9;&#x8c61;"/>
</node>
<node CREATED="1425714752527" ID="ID_1023729894" MODIFIED="1425714766751" TEXT="sync_fence_put()">
<node CREATED="1425714770066" ID="ID_1774835384" MODIFIED="1425714792733" TEXT="&#x51cf;&#x5c11;&#x4e00;&#x6b21;&#x5bf9;sync fence&#x7684;&#x5f15;&#x7528;"/>
</node>
<node CREATED="1425714813018" ID="ID_1583046830" MODIFIED="1425714823964" TEXT="sync_fence_install()">
<node CREATED="1425714826656" ID="ID_558768995" MODIFIED="1425714852242" TEXT="&#x5b89;&#x88c5;fence&#x5bf9;&#x4e00;&#x4e2a;&#x6587;&#x4ef6;&#x63cf;&#x8ff0;&#x7b26;&#x4e2d;"/>
</node>
<node CREATED="1425785985645" ID="ID_1578235219" MODIFIED="1425785994437" TEXT="sync_fence_waiter_init()"/>
<node CREATED="1425714888167" ID="ID_1153008811" MODIFIED="1425785979403" TEXT="sync_fence_wait_async()">
<node CREATED="1425714898588" ID="ID_2162590" MODIFIED="1425714928187" TEXT="&#x6ce8;&#x518c;&#x548c;&#x5f02;&#x6b65;&#x7b49;&#x5f85;&#x67d0;&#x4e2a;fence&#x5bf9;&#x5e94;"/>
</node>
<node CREATED="1425714930515" ID="ID_1146924584" MODIFIED="1425714972851" TEXT="sync_fence_cancel_async()">
<node CREATED="1425714974779" ID="ID_906669200" MODIFIED="1425714987269" TEXT="&#x53d6;&#x6d88;&#x4e00;&#x4e2a;&#x5f02;&#x6b65;&#x7b49;&#x5f85;"/>
</node>
<node CREATED="1425714990035" ID="ID_1361184577" MODIFIED="1425715022633" TEXT="sync_fence_wait()">
<node CREATED="1425715031206" ID="ID_1888868809" MODIFIED="1425715047311" TEXT="&#x7b49;&#x5f85;&#x4e00;&#x4e2a;fence&#x72b6;&#x6001;&#x53d8;&#x4e3a;signaled &#x6216;error"/>
</node>
</node>
</node>
<node CREATED="1425715189098" ID="ID_1393822878" MODIFIED="1425788083077" TEXT="&#x4e3b;&#x8981;&#x6709;&#x4e09;&#x79cd;IOCTL&#x547d;&#x4ee4;">
<node CREATED="1425715204230" ID="ID_1755145986" MODIFIED="1425715235415" TEXT="SYNC_IOC_WAIT"/>
<node CREATED="1425715235979" ID="ID_1813985934" MODIFIED="1425715244986" TEXT="SYNC_IOC_MERGE"/>
<node CREATED="1425715245834" ID="ID_1288720259" MODIFIED="1425715261272" TEXT="SYNC_IOC_FENCE_INFO">
<node CREATED="1425718730526" ID="ID_1001212489" MODIFIED="1425718736262" TEXT="fill_driver_data"/>
</node>
</node>
<node CREATED="1425788084373" ID="ID_1181531075" MODIFIED="1425788113246" TEXT="&#x5b9e;&#x73b0;&#x4e00;&#x4e2a;Sync-aware&#x7684;&#x9a71;&#x52a8;">
<node CREATED="1425789035412" ID="ID_719723279" MODIFIED="1425789092917" TEXT="&#x5b9a;&#x4e49;&#x81ea;&#x5df1;&#x7684;timeline, pt&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node CREATED="1425789268572" ID="ID_246698029" MODIFIED="1425789318245">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22914;Mali &#39537;&#21160;&#23450;&#20041;&#30340;&#65306;
    </p>
    <p>
      struct mali_sync_timeline
    </p>
    <p>
      {
    </p>
    <p>
      &#160;&#160;&#160;&#160;struct sync_timeline timeline;
    </p>
    <p>
      &#160;&#160;&#160;&#160;atomic_t counter;
    </p>
    <p>
      &#160;&#160;&#160;&#160;atomic_t signalled;
    </p>
    <p>
      };
    </p>
    <p>
      
    </p>
    <p>
      struct mali_sync_pt
    </p>
    <p>
      {
    </p>
    <p>
      &#160;&#160;&#160;&#160;struct sync_pt pt;
    </p>
    <p>
      &#160;&#160;&#160;&#160;u32 order;
    </p>
    <p>
      &#160;&#160;&#160;&#160;s32 error;
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425789320013" ID="ID_326183733" MODIFIED="1425789432095">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      sw sync&#23450;&#20041;&#30340;&#65306;
    </p>
    <p>
      struct sw_sync_timeline {
    </p>
    <p>
      &#160;&#160;&#160;&#160;struct&#160;&#160;&#160;&#160;sync_timeline&#160;&#160;&#160;&#160;obj;
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;u32&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;value;
    </p>
    <p>
      };
    </p>
    <p>
      
    </p>
    <p>
      struct sw_sync_pt {
    </p>
    <p>
      &#160;&#160;&#160;&#160;struct sync_pt&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;pt;
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;u32&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;value;
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1425788116439" ID="ID_182384062" MODIFIED="1425789510075">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25552;&#20379;&#21019;&#24314;struct sync_timeline, struct sync_pt&#30340;&#25509;&#21475;,&#160;
    </p>
    <p>
      &#24182;&#23454;&#29616;struct sync_timeline_ops&#23450;&#20041;&#30340;&#19968;&#20123;&#22238;&#35843;&#20989;&#25968;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425788153163" ID="ID_299181727" MODIFIED="1425788220202" TEXT="&#x63d0;&#x4f9b;&#x521b;&#x5efa;fence&#x7684;&#x63a5;&#x53e3;"/>
</node>
</node>
<node CREATED="1425718935674" ID="ID_1275880509" MODIFIED="1425788077929" TEXT="userspace">
<node CREATED="1425719728996" ID="ID_993783622" MODIFIED="1425719735182" TEXT="cpu-base sw sync">
<node CREATED="1425719736204" ID="ID_828694306" MODIFIED="1425719783554">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /* timeout in msecs */
    </p>
    <p>
      int sync_wait(int fd, int timeout);
    </p>
    <p>
      int sync_merge(const char *name, int fd1, int fd2);
    </p>
    <p>
      struct sync_fence_info_data *sync_fence_info(int fd);
    </p>
    <p>
      struct sync_pt_info *sync_pt_info(struct sync_fence_info_data *info,
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;struct sync_pt_info *itr);
    </p>
    <p>
      void sync_fence_info_free(struct sync_fence_info_data *info);
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1425784171612" ID="ID_1203156083" MODIFIED="1425784176511" TEXT="mali sync">
<node CREATED="1425784194982" ID="ID_1392782845" MODIFIED="1425784194982" TEXT=""/>
</node>
</node>
<node CREATED="1425722004922" FOLDED="true" ID="ID_744752953" MODIFIED="1425813636339" TEXT="&#x5b66;&#x4e60;&#x8bb0;&#x5f55;">
<arrowlink COLOR="#ef2929" DESTINATION="ID_565756155" ENDARROW="Default" ENDINCLINATION="162;44;" ID="Arrow_ID_1695708305" STARTARROW="None" STARTINCLINATION="-184;30;"/>
<node CREATED="1425722035929" ID="ID_1604576988" MODIFIED="1425722594999">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20219;&#21153;&#65306;&#30740;&#31350;Android Sync Framework
    </p>
    <p>
      &#30446;&#26631;&#65306;&#30740;&#31350;Sync Driver&#20195;&#30721;
    </p>
    <p>
      &#26102;&#38388;&#65306;4&#20010;&#30058;&#33540;&#38047;
    </p>
    <p>
      &#25191;&#34892;&#65306;XXXX
    </p>
    <p>
      
    </p>
    <p>
      &#26102;&#38388;&#65306;2015-03-07
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425722225507" ID="ID_1616222750" MODIFIED="1425789636389">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20219;&#21153;&#65306;&#30740;&#31350;Android Sync Framework
    </p>
    <p>
      &#30446;&#26631;&#65306;&#30740;&#31350;Mali Sync Driver&#20195;&#30721;
    </p>
    <p>
      &#26102;&#38388;&#65306;2&#20010;&#26102;&#38047;
    </p>
    <p>
      &#25191;&#34892;&#65306;XXX
    </p>
    <p>
      2015-03-08
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425789207027" ID="ID_1711221508" MODIFIED="1425800263124">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20219;&#21153;&#65306;&#30740;&#31350;Android Sync Framework
    </p>
    <p>
      &#30446;&#26631;&#65306;&#30740;&#31350;Fence&#31867;
    </p>
    <p>
      &#26102;&#38388;&#65306;1&#20010;&#26102;&#38047;
    </p>
    <p>
      &#25191;&#34892;&#65306;X
    </p>
    <p>
      2015-03-08
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425800202714" ID="ID_415365490" MODIFIED="1425813431368">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19979;&#19968;&#30446;&#26631;&#65306;
    </p>
    <p>
      &#20219;&#21153;&#65306;&#30740;&#31350;Android Sync Framework
    </p>
    <p>
      &#30446;&#26631;&#65306;&#30740;&#31350;DispSync&#31867;
    </p>
    <p>
      &#26102;&#38388;&#65306;4&#20010;&#26102;&#38047;
    </p>
    <p>
      &#25191;&#34892;&#65306;XXXX
    </p>
    <p>
      2015-03-08
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1425810103371" ID="ID_1034186546" MODIFIED="1425810111078" TEXT="SurfaceFlinger">
<node CREATED="1425810118006" ID="ID_232860395" MODIFIED="1425813638612" TEXT="VSync&#x673a;&#x5236;">
<node CREATED="1425810140571" FOLDED="true" ID="ID_432775276" MODIFIED="1425813641676" TEXT="DispSync&#x7c7b;&#x5206;&#x6790;">
<node CREATED="1425810158614" ID="ID_1064489355" MODIFIED="1425810311739">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22312;&#22914;&#19979;&#20004;&#31181;&#24773;&#20917;&#19979;&#65292;&#38656;&#35201;&#21551;&#29992;resynchronization&#36807;&#31243;&#65306;
    </p>
    <p>
      1. &#23631;&#24149;&#25171;&#24320;
    </p>
    <p>
      2. &#24403;addPresentFence&#36820;&#22238;true&#65292;&#34920;&#26126;&#24403;&#21069;&#30340;vysnc&#20107;&#20214;&#27169;&#22411;&#19982;&#30828;&#20214;Vsync&#20107;&#20214;&#28418;&#31227;&#20102;&#12290;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425810339817" ID="ID_59410467" MODIFIED="1425810553151">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19968;&#33324;&#24773;&#20917;&#19979;&#65292;&#24403;&#25191;&#34892;rsynchronization&#26102;&#65292;&#38656;&#35201;&#39034;&#24207;&#25191;&#34892;&#22914;&#19979;
    </p>
    <p>
      &#19977;&#20010;&#20989;&#25968;&#65306;
    </p>
    <p>
      1. &#35843;&#29992;beginResync&#20989;&#25968;
    </p>
    <p>
      2. &#36830;&#32493;&#35843;&#29992;addResyncSample&#65292;&#21521;&#20854;&#20256;&#36882;&#30828;&#20214;&#23454;&#38469;&#21457;&#29983;VSync&#20107;&#20214;&#26102;&#30340;timestamp&#20449;&#24687;
    </p>
    <p>
      3. &#24403;addResyncsample&#36820;&#22238;false&#26102;&#65292;&#34920;&#26126;&#26080;&#38656;&#35201;&#32487;&#32493;&#20256;&#36882;sample&#25968;&#25454;&#65292;&#27492;&#26102;&#35843;&#29992;
    </p>
    <p>
      endResync&#20989;&#25968;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1425812401665" ID="ID_81701370" MODIFIED="1425813185403">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22312;&#27599;&#27425;&#21472;&#22270;&#36807;&#21518;&#65292;&#37117;&#20250;&#35843;&#29992;DispSync&#30340;addPresentFence
    </p>
    <p>
      &#36827;&#34892;&#21028;&#26029;&#65306;Vsync Event Model&#26159;&#21542;&#19982;Hardware vsync event&#30340;timestamp&#30340;
    </p>
    <p>
      &#20559;&#31163;&#36229;&#36807;&#20801;&#35768;&#20540;&#65292;&#22914;&#26524;&#26159;&#30340;&#35805;&#65292;&#23601;&#35201;&#37325;&#26032;&#24320;&#21551;&#30828;&#20214;Vsync&#20107;&#20214;&#65292;&#36827;&#34892;
    </p>
    <p>
      &#37325;&#26032;&#21516;&#27493;&#12290;
    </p>
    <p>
      &#20195;&#30721;&#65306;SurfaceFlinger::postComposition()
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1425813459643" ID="ID_565756155" MODIFIED="1425813761379" TEXT="&#x5b66;&#x4e60;&#x8bb0;&#x5f55;">
<node CREATED="1425813469957" HGAP="22" ID="ID_1428772421" MODIFIED="1425813782972" VSHIFT="-6">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19979;&#19968;&#30446;&#26631;&#65306;
    </p>
    <p>
      &#20219;&#21153;&#65306;&#30740;&#31350;SurfaceFlinger&#31867;
    </p>
    <p>
      &#30446;&#26631;&#65306;&#32534;&#20889;VSync&#26426;&#21046;&#25991;&#26723;
    </p>
    <p>
      &#26102;&#38388;&#65306;2&#20010;&#26102;&#38047;
    </p>
    <p>
      &#25191;&#34892;&#65306;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1425813860114" ID="ID_1614420061" MODIFIED="1425813908196">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19979;&#19968;&#30446;&#26631;&#65306;
    </p>
    <p>
      &#20219;&#21153;&#65306;&#30740;&#31350;binder driver
    </p>
    <p>
      &#30446;&#26631;&#65306;&#20998;&#26512;binder buffer&#30340;&#20998;&#37197;&#19982;&#37322;&#25918;&#20195;&#30721;
    </p>
    <p>
      &#26102;&#38388;&#65306;2&#20010;&#26102;&#38047;
    </p>
    <p>
      &#25191;&#34892;&#65306;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1425696968061" ID="ID_440990229" MODIFIED="1425696981622" POSITION="right" TEXT="Java&#x5b66;&#x4e60;"/>
</node>
</map>

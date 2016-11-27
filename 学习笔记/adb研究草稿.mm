<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node COLOR="#006633" CREATED="1422020905546" ID="ID_977180413" MODIFIED="1429426490419" TEXT="adb">
<node CREATED="1422021459258" ID="ID_380329593" MODIFIED="1422021466388" POSITION="right" TEXT="Components">
<node CREATED="1422021472448" ID="ID_1808342921" MODIFIED="1429427285647" TEXT="The ADB server">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#x5b83;&#x662f;&#x8fd0;&#x884c;&#x4e8e;&#x4e3b;&#x673a;&#x4e0a;&#x7684;&#x4e00;&#x4e2a;&#x540e;&#x53f0;&#x7a0b;&#x5e8f;&#xff0c;&#x4e3b;&#x8981;&#x76ee;&#x7684;&#x662f;&#x4fa6;&#x6d4b;&#x8bbe;&#x5907;&#x7684;&#x63a5;&#x5165;&#x548c;&#x62d4;&#x51fa;&#xff0c;&#x6a21;&#x62df;&#x5668;&#x542f;&#x52a8;&#x548c;&#x505c;&#x6b62;&#x7b49;&#x3002;&#x5e76;&#x534f;&#x8c03;&#x5ba2;&#x6237;&#x7aef;&#xff0c;&#x670d;&#x52a1;&#x548c;&#x8bbe;&#x5907;&#x4e4b;&#x95f4;&#x7684;&#x6570;&#x636e;&#x5305;&#x4f20;&#x9001;&#x3002;
    </p>
    <p>
      &#x8bbe;&#x5907;&#x6709;&#x5982;&#x4e0b;4&#x79cd;&#x72b6;&#x6001;&#xff1a;
    </p>
    <p>
      1. OFFLINE
    </p>
    <p>
      2. BOOTLOADER
    </p>
    <p>
      3. RECOVERY
    </p>
    <p>
      4.ONLINE
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1422021493963" ID="ID_603159665" MODIFIED="1429427488698" TEXT="The ADB daemon (adbd)">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#x5b83;&#x8fd0;&#x884c;&#x4e8e;Android&#x8bbe;&#x5907;&#x6216;&#x6a21;&#x62df;&#x5668;&#x91cc;&#x9762;&#xff0c;&#x5b83;&#x7684;&#x4e3b;&#x8981;&#x4f5c;&#x7528;&#x662f;&#xff1a;
    </p>
    <p>
      1. &#x8fde;&#x63a5;&#x5230;ADB&#x670d;&#x52a1;&#x5668;&#x7aef;&#xff08;&#x901a;&#x8fc7;USB&#x6216;TCP&#x65b9;&#x5f0f;&#xff09;
    </p>
    <p>
      2. &#x4e3a;&#x8fd0;&#x884c;&#x4e8e;&#x4e3b;&#x673a;&#x4e0a;&#x7684;&#x5ba2;&#x6237;&#x7aef;&#x63d0;&#x4f9b;&#x4e00;&#x4e9b;&#x670d;&#x52a1;&#x3002;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1422021496034" ID="ID_1117305377" MODIFIED="1429427732607" TEXT="The ADB command-line client">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#x5b83;&#x6267;&#x884c;&#x6765;&#x81ea;&#x4e8e;Shell&#x6216;Script&#x7684;adb&#x547d;&#x4ee4;&#xff0c;&#x5b83;&#x9996;&#x5148;&#x4f1a;&#x8bd5;&#x56fe;&#x5b9a;&#x4f4d;adb server&#xff0c;&#x5982;&#x679c;&#x6ca1;&#x6709;&#x627e;&#x5230;&#xff0c;&#x4f1a;&#x81ea;&#x52a8;&#x542f;&#x52a8;&#x4e00;&#x4e2a;adb server&#x5b9e;&#x4f8b;&#x3002;
    </p>
    <p>
      &#x5b83;&#x5411;adb server&#x53d1;&#x9001;service&#x8bf7;&#x6c42;&#x3002;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1422021504111" ID="ID_1475198455" MODIFIED="1429427896011" TEXT="Services">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#x6709;&#x4e24;&#x79cd;&#x7c7b;&#x578b;&#x7684;&#x670d;&#x52a1;&#xff1a;
    </p>
    <p>
      1. &#x4e3b;&#x673a;&#x670d;&#x52a1;
    </p>
    <p>
      &#xa0;&#xa0;&#xa0;&#xa0;&#xa0;&#x8fd9;&#x4e9b;&#x670d;&#x52a1;&#x76f4;&#x63a5;&#x8fd0;&#x884c;&#x4e8e;adb server&#x8fdb;&#x7a0b;&#x4e2d;&#xff0c;&#x4e0d;&#x9700;&#x8981;&#x8ddf;&#x8bbe;&#x5907;&#x8fdb;&#x884c;&#x4ea4;&#x4e92;&#x3002;
    </p>
    <p>
      2. &#x672c;&#x5730;&#x670d;&#x52a1;
    </p>
    <p>
      &#xa0;&#xa0;&#xa0;&#xa0;&#x8fd9;&#x4e9b;&#x670d;&#x52a1;&#x8981;&#x4e48;&#x8fd0;&#x884c;&#x4e8e;adbd&#x8fdb;&#x7a0b;&#x4e2d;&#xff0c;&#x90a3;&#x4e48;&#x5728;&#x8bbe;&#x5907;&#x542f;&#x52a8;&#x7684;&#x8fc7;&#x7a0b;&#x4e2d;&#x7531;adbd&#x542f;&#x52a8;&#x3002;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1422021557652" ID="ID_40992646" MODIFIED="1422021562322" POSITION="right" TEXT="Protocols"/>
<node CREATED="1422021578200" ID="ID_402638817" MODIFIED="1422021598550" POSITION="right" TEXT="Source Code Analysis">
<node CREATED="1429427954832" ID="ID_1054525020" MODIFIED="1429427977453" TEXT="adb&#x96c6;&#x6210;&#x4e86;adb server&#x548c;adb command line client&#x7684;&#x529f;&#x80fd;"/>
<node CREATED="1429443101303" ID="ID_1794894639" MODIFIED="1429443142510" TEXT="adb">
<node CREATED="1429442662852" ID="ID_368562157" MODIFIED="1429443152654" TEXT="&#x6e90;&#x7801;&#x6587;&#x4ef6;&#x5217;&#x8868;">
<node CREATED="1429442711270" ID="ID_1513807737" MODIFIED="1429442750214">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      usb_linux.c
    </p>
    <p>
      get_my_path_linux.c
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1429442790221" ID="ID_1876757203" MODIFIED="1429442793174" TEXT="adb.c"/>
<node CREATED="1429442795512" ID="ID_1591428210" MODIFIED="1429442797717" TEXT="console.c"/>
<node CREATED="1429442798192" ID="ID_707909801" MODIFIED="1429442804673" TEXT="transport.c"/>
<node CREATED="1429442805122" ID="ID_433117235" MODIFIED="1429442810325" TEXT="transport_local.c"/>
<node CREATED="1429442810702" ID="ID_1264856309" MODIFIED="1429442817503" TEXT="transport_usb.c"/>
<node CREATED="1429442818070" ID="ID_1968936022" MODIFIED="1429442823514" TEXT="commandline.c"/>
<node CREATED="1429442823941" ID="ID_1335682870" MODIFIED="1429442827311" TEXT="adb_client.c"/>
<node CREATED="1429442827805" ID="ID_1981972533" MODIFIED="1429442833017" TEXT="adb_auth_host.c"/>
<node CREATED="1429442835036" ID="ID_659482392" MODIFIED="1429442837258" TEXT="sockets.c"/>
<node CREATED="1429442844226" ID="ID_1226105812" MODIFIED="1429442850027" TEXT="file_sync_client.c"/>
<node CREATED="1429442861846" ID="ID_450488534" MODIFIED="1429442866210" TEXT="usb_vendors.c"/>
<node CREATED="1429442877541" ID="ID_385739563" MODIFIED="1429442881022" TEXT="fdevent.c"/>
</node>
<node CREATED="1430659763369" ID="ID_1207797462" MODIFIED="1430659773680" TEXT="&#x4ee3;&#x7801;&#x903b;&#x8f91;&#x5206;&#x6790;">
<node CREATED="1430659778269" ID="ID_583991680" MODIFIED="1430659785651" TEXT="&#x5165;&#x53e3;&#x51fd;&#x6570;main">
<node CREATED="1430659788950" ID="ID_313783967" MODIFIED="1430659907318" TEXT="1. adb_sysdeps_init()">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21021;&#22987;&#21270;&#24179;&#21488;&#30456;&#20851;&#30340;&#35774;&#32622;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430659805553" ID="ID_1453021288" MODIFIED="1430660343597" TEXT="2. adb_trace_init()">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25351;&#23450;&#65292;&#21495;&#20998;&#38548;&#26469;&#36319;&#36394;&#28040;&#24687;
    </p>
    <p>
      &#160;1 or all, adb, sockets, packets, rwx, usb, sync, sysdeps, transport, jdwp
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430659813936" ID="ID_1172236755" MODIFIED="1430660638992" TEXT="3. adb_commandline">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#35299;&#26512;&#20256;&#20837;adb&#30340;&#21442;&#25968;&#65292;&#24182;&#20570;&#30456;&#24212;&#22788;&#29702;
    </p>
    <p>
      &#30830;&#23450;&#20197;&#19979;&#21464;&#37327;&#30340;&#20540;&#65306;
    </p>
    <p>
      __adb_transport&#160;&#160;//adb &#36890;&#20449;&#26041;&#24335;&#65306;USB&#25110;TCP
    </p>
    <p>
      __adb_serial
    </p>
    <p>
      __adb_server_port
    </p>
    <p>
      __adb_server_name
    </p>
  </body>
</html>
</richcontent>
<node CREATED="1430660638968" ID="ID_790641223" MODIFIED="1430660765604" TEXT="is_server?">
<node CREATED="1430660645820" ID="ID_462906174" MODIFIED="1430660649192" TEXT="yes">
<node CREATED="1430660663185" ID="ID_1520668638" MODIFIED="1430660773222" TEXT="no_daemon || is_daemon?">
<node CREATED="1430660682171" ID="ID_1231782308" MODIFIED="1430660780563" TEXT="yes">
<node CREATED="1430660786322" ID="ID_979529502" MODIFIED="1430660791233" TEXT="adb_main"/>
</node>
<node CREATED="1430660793725" ID="ID_1531075246" MODIFIED="1430660795435" TEXT="no">
<node CREATED="1430660798348" ID="ID_1521777870" MODIFIED="1430660803649" TEXT="launch_server"/>
</node>
</node>
</node>
<node CREATED="1430660649960" ID="ID_50797299" MODIFIED="1430660652332" TEXT="no">
<node CREATED="1430660987142" ID="ID_687995574" MODIFIED="1430661001228" TEXT="&#x5904;&#x7406;adb devices&#x547d;&#x4ee4;">
<node CREATED="1430661010805" ID="ID_850485978" MODIFIED="1430661014534" TEXT="adb_query"/>
</node>
<node CREATED="1430661001807" ID="ID_996853709" MODIFIED="1430661029765" TEXT="&#x5904;&#x7406;adb connect&#x547d;&#x4ee4;">
<node CREATED="1430661031809" ID="ID_1682450612" MODIFIED="1430661035720" TEXT=" adb_query"/>
</node>
<node CREATED="1430661042927" ID="ID_1934281459" MODIFIED="1430661053870" TEXT="&#x5904;&#x7406;adb disconnce&#x547d;&#x4ee4;">
<node CREATED="1430661067049" ID="ID_333521089" MODIFIED="1430661072797" TEXT="adb query"/>
</node>
<node CREATED="1430661076653" ID="ID_1173550521" MODIFIED="1430661093249" TEXT="&#x5904;&#x7406;adb emu&#x547d;&#x4ee4;">
<node CREATED="1430661095496" ID="ID_126980993" MODIFIED="1430661107373" TEXT="adb_send_emulator_command"/>
</node>
<node CREATED="1430661113684" ID="ID_952762917" MODIFIED="1430661172059" TEXT="&#x5904;&#x7406;adb shell&#x6216;adb hell&#x547d;&#x4ee4;"/>
<node CREATED="1430661207217" ID="ID_226833949" MODIFIED="1430661226644" TEXT="&#x5904;&#x7406;adb kill-server&#x547d;&#x4ee4;"/>
<node CREATED="1430661233051" ID="ID_402763973" MODIFIED="1430661240386" TEXT="&#x5904;&#x7406;adb sideload&#x547d;&#x4ee4;"/>
<node CREATED="1430661330233" ID="ID_1738786821" MODIFIED="1430661369407">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb remount, adb reboot, adb reboot-bootloader, adb tcpip,
    </p>
    <p>
      adb usb, adb root&#31561;&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661380159" ID="ID_286092462" MODIFIED="1430661394392">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb bugreport&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661518374" ID="ID_924540811" MODIFIED="1430661600336">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb_command() wrappter commands
    </p>
    <p>
      adb forward
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661602743" ID="ID_200576402" MODIFIED="1430661613983" TEXT="&#x5904;&#x7406;adb ls&#x547d;&#x4ee4;"/>
<node CREATED="1430661614970" ID="ID_11962738" MODIFIED="1430661623892" TEXT="&#x5904;&#x7406;adb push&#x547d;&#x4ee4;"/>
<node CREATED="1430661630376" ID="ID_355237060" MODIFIED="1430661636262" TEXT="&#x5904;&#x7406;adb pull&#x547d;&#x4ee4;"/>
<node CREATED="1430661641102" ID="ID_819894026" MODIFIED="1430661649654" TEXT="&#x5904;&#x7406;adb install&#x547d;&#x4ee4;"/>
<node CREATED="1430661650140" ID="ID_689418879" MODIFIED="1430661659563" TEXT="&#x5904;&#x7406;adb uninstall&#x547d;&#x4ee4;"/>
<node CREATED="1430661666996" ID="ID_286818126" MODIFIED="1430661674396" TEXT="&#x5904;&#x7406;adb sync&#x547d;&#x4ee4;"/>
<node CREATED="1430661674838" ID="ID_744319967" MODIFIED="1430661720079">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      passthrought commands
    </p>
    <p>
      adb get-state
    </p>
    <p>
      adb get-serialno
    </p>
    <p>
      adb get-devpath
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661726296" ID="ID_1055833742" MODIFIED="1430661739873">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb status-window&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661754038" ID="ID_1005413320" MODIFIED="1430661779364">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb logcat&#21629;&#20196;&#65288;adb lolcat, adb longcat&#65289;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661783039" ID="ID_1542490358" MODIFIED="1430661792966">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb ppp&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661793579" ID="ID_1197298992" MODIFIED="1430661806325">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb start-server&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661817367" ID="ID_1402787068" MODIFIED="1430661826984">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb backup&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661827538" ID="ID_1344831891" MODIFIED="1430661838735">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb restore&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1430661843152" ID="ID_1575482460" MODIFIED="1430661851374">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;adb jdwp&#21629;&#20196;
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1429443157141" ID="ID_602969036" MODIFIED="1429443168647" TEXT="&#x7f16;&#x8bd1;&#x9009;&#x9879;">
<node CREATED="1429443196922" ID="ID_1181358605" MODIFIED="1429443200114" TEXT="adb host tool">
<node CREATED="1429443204239" ID="ID_1436650637" MODIFIED="1429443312217">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      LOCAL_CFLAGS += -O2 -g -D<font color="#f11616"><b>ADB_HOST=1 </b></font>&#xa0;-Wall -Wno-unused-parameter
    </p>
    <p>
      LOCAL_CFLAGS += -D_XOPEN_SOURCE -D_GNU_SOURCE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1429443415687" ID="ID_676259225" MODIFIED="1429443433958" TEXT="adb host tool for device-as-host">
<node CREATED="1429443204239" ID="ID_571176158" MODIFIED="1429443526859">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      LOCAL_CFLAGS += -O2 -g -D<font color="#f11616"><b>ADB_HOST=1 </b></font>-D<font color="#fc0707"><b>ADB_HOST_ON_TARGET=1</b></font>&#xa0; -Wall -Wno-unused-parameter
    </p>
    <p>
      LOCAL_CFLAGS += -D_XOPEN_SOURCE -D_GNU_SOURCE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node CREATED="1429443328836" ID="ID_164322089" MODIFIED="1429443330633" TEXT="adbd">
<node CREATED="1429442900346" ID="ID_251498434" MODIFIED="1429443344753" TEXT="&#x6e90;&#x6587;&#x4ef6;&#x5217;&#x8868;">
<node CREATED="1429442908835" ID="ID_210863809" MODIFIED="1429442912159" TEXT="adb.c"/>
<node CREATED="1429442913457" ID="ID_1664605965" MODIFIED="1429442917770" TEXT="backup_service.c"/>
<node CREATED="1429442918192" ID="ID_1019778890" MODIFIED="1429442922319" TEXT="fdevent.c"/>
<node CREATED="1429442922917" ID="ID_275951230" MODIFIED="1429442926859" TEXT="transport.c"/>
<node CREATED="1429442927335" ID="ID_1918962465" MODIFIED="1429442932990" TEXT="transport_local.c"/>
<node CREATED="1429442933532" ID="ID_400399190" MODIFIED="1429442938256" TEXT="transport_usb.c"/>
<node CREATED="1429442938632" ID="ID_1774101129" MODIFIED="1429442945801" TEXT="adb_auth_client.c"/>
<node CREATED="1429442946167" ID="ID_1414576450" MODIFIED="1429442949623" TEXT="sockets.c"/>
<node CREATED="1429442949994" ID="ID_372687852" MODIFIED="1429442955255" TEXT="services.c"/>
<node CREATED="1429442956115" ID="ID_920866978" MODIFIED="1429442961985" TEXT="file_sync_service.c"/>
<node CREATED="1429442971755" ID="ID_645984065" MODIFIED="1429442979192" TEXT="jdwp_service.c"/>
<node CREATED="1429442979624" ID="ID_1219462771" MODIFIED="1429442987987" TEXT="framebuffer_service.c"/>
<node CREATED="1429442988364" ID="ID_347085621" MODIFIED="1429442993861" TEXT="remount_service.c"/>
<node CREATED="1429442994278" ID="ID_806137654" MODIFIED="1429443003657" TEXT="usb_linux_client.c"/>
<node CREATED="1429443004221" ID="ID_1744226157" MODIFIED="1429443007714" TEXT="log_service.c"/>
</node>
<node CREATED="1429443352371" ID="ID_1071612283" MODIFIED="1429443360188" TEXT="&#x7f16;&#x8bd1;&#x9009;&#x9879;">
<node CREATED="1429443373681" ID="ID_1373462774" MODIFIED="1429443401900">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      LOCAL_CFLAGS := -O2 -g -D<font color="#f61411"><b>ADB_HOST=0</b></font>&#xa0;-Wall -Wno-unused-parameter
    </p>
    <p>
      LOCAL_CFLAGS += -D_XOPEN_SOURCE -D_GNU_SOURCE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</map>

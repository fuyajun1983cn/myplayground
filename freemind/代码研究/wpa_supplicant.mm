<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1409582692451" ID="ID_1076266441" MODIFIED="1409582801934" STYLE="fork" TEXT="wpa_supplicant">
<node CREATED="1409582749786" ID="ID_974424588" MODIFIED="1409582894847" POSITION="right" STYLE="fork" TEXT="wpa_supplicant_init">
<icon BUILTIN="down"/>
<node CREATED="1409582926489" ID="ID_1886215318" MODIFIED="1435373284490">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1409583111993" ID="ID_1729463086" MODIFIED="1409583481886">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      eap_register_methods
    </p>
    <p>
      &#x6ce8;&#x518c;EAP&#x65b9;&#x6cd5;&#x3002;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409584755532" ID="ID_1977533986" MODIFIED="1409584761427">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      eloop_init
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1409582863600" ID="ID_766765819" MODIFIED="1409582888232" POSITION="right" TEXT="wpa_supplicant_add_iface">
<icon BUILTIN="down"/>
</node>
<node CREATED="1409582875063" ID="ID_128970832" MODIFIED="1409582899766" POSITION="right" TEXT="wpa_supplicant_run">
<icon BUILTIN="down"/>
</node>
<node CREATED="1435373331034" ID="ID_1893807389" MODIFIED="1435373339530" POSITION="left" TEXT="&#x4e3b;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node CREATED="1435373346071" ID="ID_154678626" MODIFIED="1435374646295">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct wpa_ctrl&#160;&#160;{
    </p>
    <p>
      ...
    </p>
    <p>
      #ifdef CONFIG_CTRL_IFACE_UNIX
    </p>
    <p>
      int s;
    </p>
    <p>
      struct sockaddr_un local;
    </p>
    <p>
      struct sockaddr_un dest;
    </p>
    <p>
      #endif /* CONFIG_CTRL_IFACE_UNIX */
    </p>
    <p>
      ...
    </p>
    <p>
      };
    </p>
    <p>
      
    </p>
    <p>
      used by the wpas/hostpad control interface library to store internal data.
    </p>
    <p>
      
    </p>
    <p>
      &#30456;&#20851;&#20989;&#25968;&#65306;
    </p>
    <ol>
      <li>
        wpa_ctrl_open
      </li>
      <li>
        wpa_ctrl_attach
      </li>
      <li>
        wpa_ctrl_request
      </li>
      <li>
        wpa_ctrl_recv
      </li>
    </ol>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1435374830169" ID="ID_319921465" MODIFIED="1435388283716">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      eloop&#30456;&#20851;&#25968;&#25454;&#32467;&#26500;&#65306;
    </p>
    <p>
      struct eloop_data&#160;&#160;&#160;&#65288;eloop context&#65289;
    </p>
    <p>
      
    </p>
    <p>
      wpa_cli.c&#20998;&#26512;&#65306; &#23458;&#25143;&#31471;
    </p>
    <p>
      
    </p>
    <p>
      eloop&#30456;&#20851;&#20989;&#25968;&#65306;
    </p>
    <p>
      
    </p>
    <p>
      eloop_register_read_sock(...)
    </p>
    <p>
      
    </p>
    <p>
      
    </p>
    <p>
      eloop_init()
    </p>
    <p>
      
    </p>
    <p>
      eloop_register_timeout(...) &#27880;&#20876;&#19968;&#20010;&#29616;&#22312;&#25110;&#26410;&#26469;&#35201;&#25191;&#34892;&#30340;&#22238;&#35843;&#20989;&#25968;&#12290;
    </p>
    <p>
      eloop_register_signal(...) &#27880;&#20876;&#19968;&#20010;&#20449;&#21495;&#22788;&#29702;&#20989;&#25968;
    </p>
    <p>
      eloop_register_sock(..)&#160;&#160;&#27880;&#20876;sock&#24182;&#30417;&#21548;&#20854;&#35835;&#65292;&#20889;&#21644;&#24322;&#24120;&#20107;&#20214;
    </p>
    <p>
      
    </p>
    <p>
      eloop_run()&#160;&#160;//a looping
    </p>
    <p>
      &#22788;&#29702;3&#20214;&#20107;&#65306;
    </p>
    <ol>
      <li>
        &#21457;&#29983;&#22312;&#19982;wpas&#36830;&#25509;&#30340;socket&#19978;&#30340;&#20107;&#20214;&#65288;&#36755;&#20837;&#65292;&#36755;&#20986;&#25110;&#24322;&#24120;&#65289;
      </li>
      <li>
        &#29305;&#23450;&#26102;&#38388;&#35201;&#27714;&#25191;&#34892;&#30340;&#20989;&#25968;&#12290;
      </li>
      <li>
        &#25429;&#33719;&#20449;&#21495;&#21518;&#30340;&#22788;&#29702;
      </li>
    </ol>
    <p>
      
    </p>
    <p>
      
    </p>
    <p>
      eloop_terminate()
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1435388560082" ID="ID_17449461" MODIFIED="1435390809136">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wpas&#65306; &#26381;&#21153;&#22120;&#31471;
    </p>
    <p>
      
    </p>
    <p>
      &#37325;&#35201;&#25968;&#25454;&#32467;&#26500;&#65306;
    </p>
    <p>
      struct wpa_interface&#160;&#160;//parameters for wpa_supplicant_add_iface()
    </p>
    <p>
      
    </p>
    <p>
      struct wpa_params&#160;&#160;//parameters for wpa_supplicant_init()&#160;
    </p>
    <p>
      
    </p>
    <p>
      struct wpa_global&#160;&#160;//Internal, global data for all wpa_supplicant interfaces
    </p>
    <p>
      
    </p>
    <p>
      struct wpa_supplicant //internal data for wpa_supplicant interface,&#160; contains internal data for core wpa_supplicant
    </p>
    <p>
      
    </p>
    <p>
      
    </p>
    <p>
      struct wpa_driver_ops&#160;&#160;//Driver interface API definition.
    </p>
    <p>
      
    </p>
    <p>
      struct wpa_sm&#160;&#160;&#160;//Internal WPA state machine data
    </p>
    <p>
      
    </p>
    <p>
      struct eapol_sm //Internal data for EAPOL state machines
    </p>
    <p>
      
    </p>
    <p>
      
    </p>
    <p>
      &#30456;&#20851;&#20989;&#25968;&#65306;
    </p>
    <p>
      
    </p>
    <p>
      wpa_supplicant_init(...)
    </p>
    <p>
      wpa_supplicant_add_iface(...)
    </p>
    <p>
      
    </p>
    <p>
      /**
    </p>
    <p>
      &#160;&#160;* Run the wpa_supplicant main event loop
    </p>
    <p>
      &#160;&#160;*/
    </p>
    <p>
      wpa_supplicant_run(...)
    </p>
    <p>
      
    </p>
    <p>
      eloop_run()
    </p>
    <p>
      
    </p>
    <p>
      EVENT_EAPOL_RX
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</map>

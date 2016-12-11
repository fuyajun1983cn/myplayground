<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node COLOR="#000000" CREATED="1474869042230" ID="ID_9369228" MODIFIED="1477477586527">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#24037;&#20316;&#25216;&#33021;&#20462;&#28860;
    </p>
    <p>
      &#65288;2016~&#160;&#160;&#65289;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="20"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties"/>
<node COLOR="#0033ff" CREATED="1474869229849" ID="ID_429611080" MODIFIED="1477477586366" POSITION="right" TEXT="&#x5b9e;&#x8df5;&#x90e8;&#x5206;">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" CREATED="1474869422572" FOLDED="true" ID="ID_1699726114" MODIFIED="1477636686957" TEXT="wpa_supplicant">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869647029" ID="ID_295121931" MODIFIED="1477477586368" TEXT="wpa/wpa2&#x72b6;&#x6001;&#x673a;&#x4ee3;&#x7801;&#x7814;&#x7a76;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1474869661597" ID="ID_748924271" MODIFIED="1477477586404" TEXT="EAP&#x6846;&#x67b6;"/>
<node COLOR="#111111" CREATED="1474869671203" ID="ID_1430625748" MODIFIED="1477477586404" TEXT="EAPOL&#x72b6;&#x6001;&#x673a;&#x6846;&#x67b6;"/>
<node COLOR="#111111" CREATED="1474869681604" ID="ID_95119704" MODIFIED="1477477586404" TEXT="WPS&#x72b6;&#x6001;&#x673a;"/>
</node>
<node COLOR="#990000" CREATED="1474869703397" ID="ID_1571133533" MODIFIED="1477477586404" TEXT="wpa_supplicant&#x5168;&#x5c40;&#x72b6;&#x6001;&#x673a;&#x7814;&#x7a76;">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869430952" FOLDED="true" ID="ID_1927977658" MODIFIED="1477636689047" TEXT="mac80211">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869622475" FOLDED="true" ID="ID_912733262" MODIFIED="1477477586409" TEXT="mac80211_hwsim&#x6e90;&#x7801;&#x5206;&#x6790;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476412277962" ID="ID_1065456441" MODIFIED="1477477586412" TEXT="&#x4e3b;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1476413044373" ID="ID_1058027468" MODIFIED="1477477586412" TEXT="struct mac80211_hwsim_data">
<linktarget COLOR="#ff3333" DESTINATION="ID_1058027468" ENDARROW="Default" ENDINCLINATION="-214;-230;" ID="Arrow_ID_452271799" SOURCE="ID_643930094" STARTARROW="None" STARTINCLINATION="102;-88;"/>
<node COLOR="#111111" CREATED="1476413054677" ID="ID_250182291" MODIFIED="1477477586412">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hw
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_hw *hw;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476415402185" ID="ID_1844829092" MODIFIED="1477477586412" TEXT="struct ieee80211_hw">
<node COLOR="#111111" CREATED="1476415484548" ID="ID_643930094" MODIFIED="1477477586412" TEXT="void *priv">
<arrowlink COLOR="#ff3333" DESTINATION="ID_1058027468" ENDARROW="Default" ENDINCLINATION="-214;-230;" ID="Arrow_ID_452271799" STARTARROW="None" STARTINCLINATION="102;-88;"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476413095695" ID="ID_917629506" MODIFIED="1477477586412">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bands
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_supported_band bands[IEEE80211_NUM_BANDS];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476413114759" ID="ID_1533289128" MODIFIED="1477477586412" TEXT="channels_2ghz">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_channel channels_2ghz[ARRAY_SIZE(hwsim_channels_2ghz)];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476413097343" ID="ID_1577824164" MODIFIED="1477477586412">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      channels_5ghz
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_channel channels_5ghz[ARRAY_SIZE(hwsim_channels_5ghz)];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476413343296" ID="ID_1397592854" MODIFIED="1477477586413">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rates
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_rate rates[ARRAY_SIZE(hwsim_rates)];
    </p>
    <p>
      bitrate definition&#160;&#160;that an 802.11 PHY can operate with.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414241848" ID="ID_963803637" MODIFIED="1477477586413" TEXT="if_combination">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_iface_combination if_combination;
    </p>
    <p>
      possible interface combination
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414280865" ID="ID_1459302242" MODIFIED="1477477586413" TEXT="addresses">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mac address
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414304938" ID="ID_1447085398" MODIFIED="1477477586413" TEXT="regd">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const struct ieee80211_regdomain *regd;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414347828" ID="ID_1593356246" MODIFIED="1477477586413" TEXT="hw_scan_request">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct cfg80211_scan_request *hw_scan_request;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414362828" ID="ID_60716343" MODIFIED="1477477586413" TEXT="hw_scan_vif">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_vif *hw_scan_vif;
    </p>
    <p>
      per-interface data
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414443540" ID="ID_1665774938" MODIFIED="1477477586413" TEXT="channel">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_channel *channel;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414470929" ID="ID_998036270" MODIFIED="1477477586413" TEXT="rx_filter"/>
<node COLOR="#111111" CREATED="1476415620052" ID="ID_611421707" MODIFIED="1477477586413" TEXT="pending">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct sk_buff_head pending; /* packets pending */
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#3333ff" DESTINATION="ID_222075092" ENDARROW="Default" ENDINCLINATION="707;0;" ID="Arrow_ID_853178117" STARTARROW="None" STARTINCLINATION="707;0;"/>
</node>
<node COLOR="#111111" CREATED="1476414515074" ID="ID_1519967614" MODIFIED="1477477586413" TEXT="Stats">
<node COLOR="#111111" CREATED="1476414527363" ID="ID_144152733" MODIFIED="1477477586414" TEXT="tx_pkts"/>
<node COLOR="#111111" CREATED="1476414539011" ID="ID_1052431136" MODIFIED="1477477586414" TEXT="rx_pkts"/>
<node COLOR="#111111" CREATED="1476414547651" ID="ID_892018179" MODIFIED="1477477586414" TEXT="tx_bytes"/>
<node COLOR="#111111" CREATED="1476414554547" ID="ID_1915509624" MODIFIED="1477477586414" TEXT="rx_bytes"/>
<node COLOR="#111111" CREATED="1476414561043" ID="ID_1206183439" MODIFIED="1477477586414" TEXT="tx_dropped"/>
<node COLOR="#111111" CREATED="1476414567003" ID="ID_1733191458" MODIFIED="1477477586414" TEXT="tx_failed"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476414751866" ID="ID_790351648" MODIFIED="1477477586414" TEXT="struct hwsim_new_radio_params ">
<node COLOR="#111111" CREATED="1476414777170" ID="ID_1764052366" MODIFIED="1477477586414" TEXT="channels"/>
<node COLOR="#111111" CREATED="1476414783019" ID="ID_1493793144" MODIFIED="1477477586414" TEXT="reg_alpha2"/>
<node COLOR="#111111" CREATED="1476414789347" ID="ID_1509155196" MODIFIED="1477477586415" TEXT="regd">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const struct ieee80211_regdomain *regd;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414814828" ID="ID_86536830" MODIFIED="1477477586415" TEXT="reg_strict"/>
<node COLOR="#111111" CREATED="1476414816188" ID="ID_1955591649" MODIFIED="1477477586415" TEXT="p2p_device">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support p2p device ?
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414823780" ID="ID_1041874000" MODIFIED="1477477586415" TEXT="use_chanctx">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      use multi-channel ?
    </p>
    <p>
      used with the HWSIM_CMD_CREATE_RADIO
    </p>
    <p>
      command to force use of channel contexts even when only a
    </p>
    <p>
      single channel is supported
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414830189" ID="ID_1332749665" MODIFIED="1477477586415" TEXT="destroy_on_close"/>
<node COLOR="#111111" CREATED="1476414842725" ID="ID_1719598725" MODIFIED="1477477586415" TEXT="hwname"/>
<node COLOR="#111111" CREATED="1476414848814" ID="ID_406619918" MODIFIED="1477477586415" TEXT="no_vif"/>
</node>
<node COLOR="#111111" CREATED="1476415928069" ID="ID_468572009" MODIFIED="1477477586415" TEXT="struct hwsim_vif_priv"/>
</node>
<node COLOR="#111111" CREATED="1476412360197" ID="ID_15260927" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27169;&#22359;&#21442;&#25968;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476412377630" ID="ID_678225509" MODIFIED="1477477586416" TEXT="radios">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Number of simulated radios
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412395301" ID="ID_725201060" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      channels
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Number of concurrent channels
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412422327" ID="ID_946638314" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      paged_rx
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Use paged SKBs for RX instead of linear ones
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412459696" ID="ID_708208550" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rctbl
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Handle rate control table
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412471473" ID="ID_1057188484" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support_p2p_device
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Support P2P-Device interface type
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476412284459" ID="ID_590883249" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>init_mac80211_hwsim()</b>
    </p>
    <p>
      <font color="#999999">mac80211_hwsim.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476412641495" ID="ID_1612920235" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hwsim_init_netlink();
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412671536" ID="ID_1755923890" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mac80211_hwsim_new_radio(...)
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476415011315" ID="ID_805268025" MODIFIED="1477477586417" TEXT="ieee80211_alloc_hw_nm">
<node COLOR="#111111" CREATED="1476415295637" FOLDED="true" ID="ID_655975456" MODIFIED="1477477586417" TEXT="private data">
<node COLOR="#111111" CREATED="1476415311886" ID="ID_655321838" MODIFIED="1477477586417" TEXT="struct mac80211_hwsim_data *data;"/>
</node>
<node COLOR="#111111" CREATED="1476415318574" FOLDED="true" ID="ID_214901893" MODIFIED="1477477586417" TEXT="mac80211_hwsim_ops">
<node COLOR="#111111" CREATED="1476415329831" ID="ID_1198802599" MODIFIED="1477477586417" TEXT="const struct ieee80211_ops "/>
</node>
<node COLOR="#111111" CREATED="1476415662546" ID="ID_222075092" MODIFIED="1477477586417">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21021;&#22987;&#21270;&#25968;&#25454;&#21253;&#21457;&#36865;&#38431;&#21015;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      skb_queue_head_init(&amp;data-&gt;pending);
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#3333ff" DESTINATION="ID_222075092" ENDARROW="Default" ENDINCLINATION="707;0;" ID="Arrow_ID_853178117" SOURCE="ID_611421707" STARTARROW="None" STARTINCLINATION="707;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476416142724" ID="ID_1447743281" MODIFIED="1477477586417" TEXT="ieee80211_hw_set(...)"/>
<node COLOR="#111111" CREATED="1476416155660" ID="ID_1475728718" MODIFIED="1477477586417" TEXT="ieee80211_register_hw(...)"/>
<node COLOR="#111111" CREATED="1476416245847" ID="ID_226441153" MODIFIED="1477477586418" TEXT="hwsim_mcast_new_radio(...)"/>
</node>
<node COLOR="#111111" CREATED="1476412955937" ID="ID_887757595" MODIFIED="1477477586418">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27880;&#20876;&#32593;&#32476;&#35774;&#22791;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      alloc_netdev(...)
    </p>
    <p>
      dev_alloc_name(...)
    </p>
    <p>
      register_netdevice(...)
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1476409717890" FOLDED="true" ID="ID_469100470" MODIFIED="1477636675006" TEXT="mac80211&#x6846;&#x67b6;&#x6e90;&#x7801;&#x5206;&#x6790;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476410841026" ID="ID_1305653455" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20027;&#35201;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411827514" ID="ID_1116728788" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_sub_if_data</b>
    </p>
    <p>
      <font color="#999999">ieee80211_i.h</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      per-interface data
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411858139" ID="ID_132587234" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct wireless_dev wdev;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411879540" ID="ID_1613258345" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct net_device *dev;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411404642" ID="ID_291977835" MODIFIED="1477477586420" TEXT="IEEE80211_DEV_TO_SUB_IF(dev)">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      static inline struct ieee80211_sub_if_data *
    </p>
    <p>
      IEEE80211_DEV_TO_SUB_IF(struct net_device *dev)
    </p>
    <p>
      {
    </p>
    <p>
      &#160;&#160;&#160;&#160;return netdev_priv(dev);
    </p>
    <p>
      }
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476411901004" ID="ID_1550794880" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_local</b>&#160;*local;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411915772" ID="ID_845718201" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;struct ieee80211_tx_queue_params tx_conf[IEEE80211_NUM_ACS];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411936085" ID="ID_1947718430" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct cfg80211_chan_def csa_chandef;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411953734" ID="ID_1825231439" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_if_ap *bss;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411966126" ID="ID_737286586" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_vif vif;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      vif_to_sdata(...)
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477364873115" ID="ID_1698880990" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_local</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477364889012" ID="ID_1227098787" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_hw</b>&#160;hw;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477364909668" ID="ID_1879113428" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const <b>struct ieee80211_ops</b>&#160;*ops;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477364956125" ID="ID_791409041" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct workqueue_struct *workqueue;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      private workqueue to mac80211. mac80211 makes this accessible
    </p>
    <p>
      via ieee80211_queue_work()
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476411478093" ID="ID_1807247391" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_hw</b>
    </p>
    <p>
      <font color="#999999">mac80211.h</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hardware information and state
    </p>
    <p>
      This structure contains the configuration and hardware information for an 802.11 PHY.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411568024" ID="ID_428216736" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_conf conf;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      configuration of the device
    </p>
    <p>
      This struct indicates how the driver shall configure the hardware.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411570376" ID="ID_769222651" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct wiphy *wiphy;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411596657" ID="ID_1623345853" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const char *rate_control_algorithm;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411612778" ID="ID_1572278424" MODIFIED="1477477586421" TEXT="void *priv;">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      private date
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411667213" ID="ID_1368152963" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const struct ieee80211_cipher_scheme *cipher_schemes;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cipher scheme
    </p>
    <p>
      This structure contains a cipher scheme information defining
    </p>
    <p>
      the secure packet crypto handling.
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476414667334" ID="ID_545869730" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_ops</b>
    </p>
    <p>
      <font color="#999999">mac80211.h</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366636745" ID="ID_1459531244" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_tx_queue
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477365098650" ID="ID_55395247" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct sta_info
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477365112291" ID="ID_818817939" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_local</b>&#160;*local;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365115571" ID="ID_348401759" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_sub_if_data</b>&#160;*sdata;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365166277" ID="ID_1995620591" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enum ieee80211_sta_state sta_state;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477365169661" ID="ID_613410836" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IEEE80211_STA_AUTH
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365184669" ID="ID_407247364" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IEEE80211_STA_ASSOC
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365190830" ID="ID_321140248" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IEEE80211_STA_AUTHORIZED
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477365221655" ID="ID_1459936071" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct sta_ampdu_mlme ampdu_mlme;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Aggregation information
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365303290" ID="ID_219455914" LINK="#ID_1094116211" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_sta</b>&#160;sta;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta - station table entry
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477365433551" ID="ID_1094116211" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477365448199" ID="ID_104270344" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta_ht_cap ht_cap;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365451272" ID="ID_776303380" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta_vht_cap vht_cap;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365469248" ID="ID_1982606601" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enum ieee80211_sta_rx_bandwidth bandwidth;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365471584" ID="ID_981652273" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enum ieee80211_smps_mode smps_mode;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365478712" ID="ID_1343141034" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta_rates __rcu *rates;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /**
    </p>
    <p>
      &#160;* struct ieee80211_sta_rates - station rate selection table
    </p>
    <p>
      &#160;*
    </p>
    <p>
      &#160;* @rcu_head: RCU head used for freeing the table on update
    </p>
    <p>
      &#160;* @rate: transmit rates/flags to be used by default.
    </p>
    <p>
      &#160;* Overriding entries per-packet is possible by using cb tx control.
    </p>
    <p>
      &#160;*/
    </p>
    <p>
      struct ieee80211_sta_rates {
    </p>
    <p>
      struct rcu_head rcu_head;
    </p>
    <p>
      struct {
    </p>
    <p>
      s8 idx;
    </p>
    <p>
      u8 count;
    </p>
    <p>
      u8 count_cts;
    </p>
    <p>
      u8 count_rts;
    </p>
    <p>
      u16 flags;
    </p>
    <p>
      } rate[IEEE80211_TX_RATE_TABLE_SIZE];
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365541387" ID="ID_1998999670" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_txq *txq[IEEE80211_NUM_TIDS];
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Software intermediate tx queue
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476409772848" ID="ID_1660223935" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476409807658" ID="ID_613038323" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rc80211_minstrel_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Rate Control Algorithm
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-1"/>
<node COLOR="#111111" CREATED="1476409943006" ID="ID_579598150" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_rate_control_register(...)
    </p>
    <p>
      <font color="#999999">rc80211_minstrel.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476410049250" ID="ID_1118489610" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476410013832" ID="ID_305341745" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct rate_control_ops mac80211_minstrel = {
    </p>
    <p>
      ...
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_305341745" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_1926889873" SOURCE="ID_985864475" STARTARROW="None" STARTINCLINATION="95;0;"/>
</node>
<node COLOR="#111111" CREATED="1476410067083" ID="ID_985864475" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct rate_control_alg {
    </p>
    <p>
      struct list_head list;
    </p>
    <p>
      const struct rate_control_ops *ops;
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_305341745" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_1926889873" STARTARROW="None" STARTINCLINATION="95;0;"/>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_985864475" ENDARROW="Default" ENDINCLINATION="225;0;" ID="Arrow_ID_350388642" SOURCE="ID_41202849" STARTARROW="None" STARTINCLINATION="225;0;"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476409815889" ID="ID_319116633" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rc80211_minstrel_ht_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HT Rate Control Algorithm
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-2"/>
<node COLOR="#111111" CREATED="1476410189304" ID="ID_1025726713" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      init_sample_table()
    </p>
    <p>
      rc80211_minstrel.c
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476410253585" ID="ID_41202849" MODIFIED="1477477586426" TEXT="&#x76f8;&#x5173;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<arrowlink DESTINATION="ID_985864475" ENDARROW="Default" ENDINCLINATION="225;0;" ID="Arrow_ID_350388642" STARTARROW="None" STARTINCLINATION="225;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476409827482" ID="ID_1795631311" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_iface_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-3"/>
<node COLOR="#111111" CREATED="1476410460582" ID="ID_287780463" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>register_netdevice_notifier(...)</b>
    </p>
    <p>
      <font color="#999999">iface.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476410572125" ID="ID_1314326289" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      static struct notifier_block mac80211_netdev_notifier = {
    </p>
    <p>
      .notifier_call = <font color="#0000ff"><b>netdev_notify</b></font>,
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477366221155" FOLDED="true" ID="ID_1726316341" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>TX</b>
    </p>
    <p>
      <font color="#666666">tx.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366224411" FOLDED="true" ID="ID_473692394" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx_skb
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477366352328" ID="ID_513970598" MODIFIED="1477477586434">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx_skb_tid
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366362848" ID="ID_295199690" MODIFIED="1477477586434">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      __ieee80211_tx_skb_tid_band
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366366048" ID="ID_86674733" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_xmit
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366518597" ID="ID_46812627" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366533358" ID="ID_1328078520" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      __ieee80211_tx
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366543342" ID="ID_988063716" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx_frags
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366553727" ID="ID_1372633761" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_drv_tx
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366567079" ID="ID_1299628656" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      drv_wake_tx_queue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366578951" ID="ID_1608980143" LINK="#ID_1459531244" MODIFIED="1477477586436" TEXT="wake_tx_queue">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      call back
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477376395236" ID="ID_612179711" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>RX</b>
    </p>
    <p>
      <font color="#666666">rx.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477376398334" ID="ID_1663416978" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_rx
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-1"/>
</node>
<node COLOR="#111111" CREATED="1477376427815" ID="ID_1348324562" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_rx_irqsafe
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-2"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477376498857" ID="ID_110691889" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cfg80211 hook function</b>
    </p>
    <p>
      <font color="#666666">cfg.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mac80211 configuration hooks for cfg80211
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477376626774" ID="ID_1522221188" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>channel management</b>
    </p>
    <p>
      <font color="#666666">chan.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477376919945" ID="ID_1828687471" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>ethtool hooks for cfg80211</b>
    </p>
    <p>
      <font color="#666666">ethtool.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377228868" ID="ID_364043378" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Interface handling</b>
    </p>
    <p>
      <font color="#666666">iface.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377367417" ID="ID_972313321" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Key handling</b>
    </p>
    <p>
      <font color="#666666">key.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477364629251" ID="ID_214260023" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>aggregate</b>
    </p>
    <p>
      <font color="#666666">agg-tx.c/agg-rx.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477375632408" ID="ID_56377793" MODIFIED="1477477586437" TEXT="buffer reorder"/>
</node>
<node COLOR="#111111" CREATED="1477364685967" ID="ID_331600730" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>rate control algorithm</b>
    </p>
    <p>
      <font color="#666666">rate.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377833466" ID="ID_814060601" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>BSS client mode implementation</b>
    </p>
    <p>
      <font color="#666666">mlme.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377908596" ID="ID_243971160" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Off-channel operation helpers</b>
    </p>
    <p>
      <font color="#666666">offchannel.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377952614" ID="ID_1148949747" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>PM/WOW</b>
    </p>
    <p>
      <font color="#666666">pm.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378228679" ID="ID_1003391081" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Scan</b>
    </p>
    <p>
      <font color="#666666">scan.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378274785" ID="ID_1040895395" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>spectrum management</b>
    </p>
    <p>
      <font color="#666666">spectmgmt.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378459080" ID="ID_923026136" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>STA information housekeeping</b>
    </p>
    <p>
      <font color="#666666">sta_info.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378567892" ID="ID_1041614804" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>TDLS handling</b>
    </p>
    <p>
      <font color="#666666">tdls.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378834565" ID="ID_186851600" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>VHT handling</b>
    </p>
    <p>
      <font color="#666666">vht.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378952546" ID="ID_602896911" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>QoS</b>
    </p>
    <p>
      <font color="#666666">wme.c</font>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869434819" ID="ID_84622656" MODIFIED="1477477586438" TEXT="cfg80211">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869438065" ID="ID_1690035151" MODIFIED="1478090688574" TEXT="mt76x2">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869598426" ID="ID_923886439" MODIFIED="1477477586440" TEXT="Tx">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1474945300464" ID="ID_1192465889" MODIFIED="1477477586440" TEXT="Tx Queue"/>
</node>
<node COLOR="#990000" CREATED="1474869602826" ID="ID_1430499287" MODIFIED="1477477586441" TEXT="Rx">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1474869606018" ID="ID_197727498" MODIFIED="1477477586441" TEXT="Scan">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1478248961400" ID="ID_497449915" MODIFIED="1478248967503">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20869;&#23384;&#31649;&#29702;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1478090693516" ID="ID_34775248" MODIFIED="1478090704396">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#33455;&#29255;&#30456;&#20851;&#25805;&#20316;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1478090710853" ID="ID_1891392343" MODIFIED="1478090728506">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MT76x2_ChipOp
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478090733889" ID="ID_1397915684" MODIFIED="1478090790727">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .AsicDynamicVgaGainControl
    </p>
    <p>
      <b><font color="#0000ff">FALSE CCA</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478090792868" ID="ID_689883021" MODIFIED="1478090802726">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      host_periodic_monitor_rssi_adjust_vga
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478090851740" ID="ID_1401578742" MODIFIED="1478090854270" TEXT="periodic_monitor_rssi_adjust_vga_sta_mode">
<node COLOR="#111111" CREATED="1478091055068" ID="ID_400808686" MODIFIED="1478091064852" TEXT="Only when RSSI &lt; -75">
<node COLOR="#111111" CREATED="1478091066111" ID="ID_3202642" MODIFIED="1478091070816">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      periodic_monitor_false_cca_adjust_init_vga
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1475208168965" ID="ID_1435637780" MODIFIED="1477477586442" TEXT="Rate Selection">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1475208174268" ID="ID_1483442935" MODIFIED="1477477586442" TEXT="for control frames"/>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869441499" ID="ID_975733955" MODIFIED="1478248978952" TEXT="mt7668">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869611115" ID="ID_621820542" MODIFIED="1478610307988" TEXT="Tx">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477559909005" ID="ID_266918801" MODIFIED="1477559914149" TEXT="&#x76f8;&#x5173;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1477559915289" ID="ID_1568168720" MODIFIED="1477559920175">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P_TX_CTRL_T
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477478342856" ID="ID_879454717" MODIFIED="1477478348358">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      main_thread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478396369" ID="ID_1063622589" MODIFIED="1477478432017">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31561;&#24453;&#22914;&#19979;&#20107;&#20214;&#21457;&#29983;
    </p>
    <p>
      <b>wait_event_interruptible</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478435579" ID="ID_1631034660" MODIFIED="1477478707787">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#00ccff"><b>GLUE_FLAG_INT</b></font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477478443635" ID="ID_1951763154" MODIFIED="1477556891715">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#0000cc"><b>GLUE_FLAG_OID_BIT</b></font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478829065" ID="ID_1605852624" MODIFIED="1477478841875">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq-&gt;fgRead
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq = &amp;(prGlueInfo-&gt;OidEntry);
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478845401" ID="ID_1506550129" MODIFIED="1477478850640">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      TRUE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478871394" ID="ID_720722775" MODIFIED="1477478989629">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanQueryInformation
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="243;0;" ID="Arrow_ID_1855677042" STARTARROW="None" STARTINCLINATION="243;0;"/>
<node COLOR="#111111" CREATED="1477479176509" ID="ID_1974889663" MODIFIED="1477479323491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pfnOidQryHandler
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478851186" ID="ID_1101645455" MODIFIED="1477478853856">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478882347" ID="ID_772626705" MODIFIED="1477478995356">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSetInformation
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="229;0;" ID="Arrow_ID_198281093" STARTARROW="None" STARTINCLINATION="229;0;"/>
<node COLOR="#111111" CREATED="1477479143132" ID="ID_1712543043" MODIFIED="1477828994604">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pfnOidSetHandler
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1712543043" ENDARROW="None" ENDINCLINATION="618;0;" ID="Arrow_ID_688335745" SOURCE="ID_1076051513" STARTARROW="None" STARTINCLINATION="618;0;"/>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478936316" ID="ID_483240003" MODIFIED="1477478995356">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq-&gt;rStatus
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="243;0;" ID="Arrow_ID_1855677042" SOURCE="ID_720722775" STARTARROW="None" STARTINCLINATION="243;0;"/>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="229;0;" ID="Arrow_ID_198281093" SOURCE="ID_772626705" STARTARROW="None" STARTINCLINATION="229;0;"/>
<node COLOR="#111111" CREATED="1477479019072" ID="ID_594010182" MODIFIED="1477479024623">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_PENDING
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479498400" ID="ID_1304829124" MODIFIED="1477479523793">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidTimeoutCheck
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This function is called to check if the OID handler needs timeout
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477479064017" ID="ID_1832223950" MODIFIED="1477479065809">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_FAILURE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479554467" ID="ID_291787242" MODIFIED="1477479718564">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      complete(&amp;<b><font color="#0000cc">prGlueInfo-&gt;rPendComp</font></b>);
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="803;0;" ID="Arrow_ID_1875886394" STARTARROW="None" STARTINCLINATION="803;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477479073713" ID="ID_554810430" MODIFIED="1477479075391">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_SUCCESS
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479563443" ID="ID_1536799758" MODIFIED="1477479680068">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      complete(&amp;<font color="#0000cc"><b>prGlueInfo-&gt;rPendComp</b></font>);
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="778;0;" ID="Arrow_ID_146360375" STARTARROW="None" STARTINCLINATION="778;0;"/>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478449828" ID="ID_635894062" MODIFIED="1477559656493">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font color="#cc0099">GLUE_FLAG_TXREQ_BIT</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556834121" ID="ID_317590261" MODIFIED="1477556937895">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalProcessTxReq
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Process Tx Request to main_thread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477557008737" ID="ID_1688843372" MODIFIED="1477560538907">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanProcessMboxMessage
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Process Mailbox Messages
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477560377073" ID="ID_185243011" MODIFIED="1477560541747">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanProcessCommandQueue
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prTxQueue
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477560379585" ID="ID_1161497059" MODIFIED="1477560543898">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalProcessTxPacket
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477560632730" ID="ID_626420708" MODIFIED="1477560658026">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanEnqueueTxPacket
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enqueue a single TX packet into CORE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477560869484" ID="ID_577410772" MODIFIED="1477560977783">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxFillMsduInfo
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fill MSDU info
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_240885290" ENDARROW="Default" ENDINCLINATION="25;0;" ID="Arrow_ID_1955703381" STARTARROW="None" STARTINCLINATION="25;0;"/>
</node>
<node COLOR="#111111" CREATED="1477560961470" ID="ID_240885290" MODIFIED="1477561003303">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxEnqueueMsdu
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enqueues MSDU_INFO_T into queue management, or command queue
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_240885290" ENDARROW="Default" ENDINCLINATION="25;0;" ID="Arrow_ID_1955703381" SOURCE="ID_577410772" STARTARROW="None" STARTINCLINATION="25;0;"/>
<node COLOR="#111111" CREATED="1477561417950" ID="ID_278512211" MODIFIED="1477561420244">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      qmEnqueueTxPackets
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477560526119" ID="ID_1600916599" MODIFIED="1477561526015" TEXT="wlanTxPendingPackets">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477561550340" ID="ID_1350897571" MODIFIED="1477637481969">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      qmDequeueTxPacketsMthread
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477561605153" ID="ID_432925557" MODIFIED="1477637434015">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      qmDequeueTxPackets
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Dequeue TX packets to send to HIF TX
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477561651118" ID="ID_1993111919" MODIFIED="1477637484897">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxMsduInfoListMthread
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      In this function, we'll aggregate frame(PACKET_INFO_T)
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477637619079" ID="ID_1176757452" MODIFIED="1477637716050">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxFillDataDesc
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1176757452" ENDARROW="Default" ENDINCLINATION="41;-1;" ID="Arrow_ID_1976870905" SOURCE="ID_1334761922" STARTARROW="None" STARTINCLINATION="26;0;"/>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477637636989" HGAP="28" ID="ID_1334761922" MODIFIED="1477637705509" TEXT="Loop for push msdu to skb_buffer" VSHIFT="34">
<arrowlink DESTINATION="ID_1176757452" ENDARROW="Default" ENDINCLINATION="41;-1;" ID="Arrow_ID_1976870905" STARTARROW="None" STARTINCLINATION="26;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477561815979" ID="ID_1459388814" MODIFIED="1477637720858">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetTxEvent2Hif
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477561864936" ID="ID_1258386995" MODIFIED="1477561873031">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wakeup hif thread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477561881655" ID="ID_217551308" MODIFIED="1477561910933">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set_bit(<b><font color="#0000cc">GLUE_FLAG_HIF_TX_BIT</font></b>, &amp;pr-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477561885743" ID="ID_435588952" LINK="#ID_343703026" MODIFIED="1477562092797">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_up_interruptible(&amp;<b><font color="#0000cc">pr-&gt;waitq_hif</font></b>);
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478456395" ID="ID_438575857" MODIFIED="1477478746093">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#cc0000">GLUE_FLAG_HALT</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477556862619" ID="ID_1592345369" MODIFIED="1477644582665">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#0000cc">GLUE_FLAG_RX_BIT</font>
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477644555861" ID="ID_1496049418" LINK="#ID_718161628" MODIFIED="1477644593121">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxProcessRFBs
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556895901" ID="ID_1162358599" MODIFIED="1477556903562">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_TX_CMD_DONE_BIT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907850275" ID="ID_1584621015" MODIFIED="1477907856232">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanTxCmdDoneMthread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907893491" ID="ID_385780752" MODIFIED="1477907921081">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      call:&#160;prCmdInfo-&gt;<b><font color="#0000cc">pfCmdDoneHandler</font></b>(...)
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477561926205" ID="ID_1745579825" MODIFIED="1477561929977" TEXT="hif_thread">
<node COLOR="#111111" CREATED="1477561975732" ID="ID_1383351037" MODIFIED="1477561991211">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31561;&#24453;&#22914;&#19979;&#20107;&#20214;&#21457;&#29983;
    </p>
    <p>
      <b>wait_event_interruptible</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562018718" ID="ID_1666106321" MODIFIED="1477899370449">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_INT_BIT
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477647497238" ID="ID_337032423" LINK="#ID_895161077" MODIFIED="1477899368157">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanIST
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477562021141" ID="ID_689005050" MODIFIED="1477562036005">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_TX_CMD_BIT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906936546" ID="ID_1000408848" MODIFIED="1477906938890">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanTxCmdMthread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906973074" ID="ID_88954919" MODIFIED="1477908029761">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27880;&#20876;HIF TX Cmd Done Callback
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907970426" ID="ID_1748134039" MODIFIED="1477907974389">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prCmdInfo-&gt;pfHifTxCmdDoneCb
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907978123" ID="ID_177580910" LINK="#ID_1162358599" MODIFIED="1477908162062">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanTxCmdDoneCb
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wakeup TX thread with <b><font color="#0000cc">GLUE_FLAG_TX_CMD_DONE_BIT</font></b>&#160;set.
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477907090161" ID="ID_927384489" MODIFIED="1477907093210">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxCmd
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907183840" ID="ID_554261837" MODIFIED="1477907254858">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_WRITE_TX_CMD
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907261344" ID="ID_1459002414" MODIFIED="1477907274382">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalDevWriteCmd
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="stop-sign"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477907094001" ID="ID_712382940" LINK="#ID_1162358599" MODIFIED="1477908178706">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      if u4TxDoneQueueSize &gt; 0
    </p>
    <p>
      &#160;&#160;&#160;wakeup main thread to prcess.
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477562041230" ID="ID_343703026" MODIFIED="1477562043044">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_TX_BIT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562116529" ID="ID_1797956064" MODIFIED="1477562119392">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxMsduQueueMthread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562326777" ID="ID_340028714" MODIFIED="1477562328711">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxMsduQueue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562472669" ID="ID_1387322671" MODIFIED="1477829406663">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_WRITE_TX_DATA
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477562480374" ID="ID_555033819" MODIFIED="1477566380381">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_KICK_TX_DATA
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
<icon BUILTIN="stop-sign"/>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477562050143" ID="ID_1324094376" MODIFIED="1477562052092">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_FW_OWN_BIT
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477906175992" ID="ID_1627217765" MODIFIED="1477906186189" TEXT="Command&#x53d1;&#x9001;&#x6d41;&#x7a0b;">
<node COLOR="#111111" CREATED="1477906191632" ID="ID_765521494" MODIFIED="1477906198179">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906199255" ID="ID_747869389" MODIFIED="1477906510143">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      CMD_INFO_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;CMD_INFO_T is used by Glue Layer to send
    </p>
    <p>
      a cluster of Command(OID) information to
    </p>
    <p>
      the TX Path to reduce the parameters of a function call.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906600532" ID="ID_1726095776" MODIFIED="1477906638631">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prCmdInfo-&gt;<b><font color="#0000cc">pucInfoBuffer</font></b>
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_1016984849" ENDARROW="Default" ENDINCLINATION="203;0;" ID="Arrow_ID_1987015028" STARTARROW="None" STARTINCLINATION="203;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477906514781" ID="ID_1016984849" MODIFIED="1477906638630">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WIFI_CMD_T
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1016984849" ENDARROW="Default" ENDINCLINATION="203;0;" ID="Arrow_ID_1987015028" SOURCE="ID_1726095776" STARTARROW="None" STARTINCLINATION="203;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477906667229" ID="ID_1474798058" MODIFIED="1477906670311">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906672548" ID="ID_1908085732" MODIFIED="1477906702975">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalProcessTxReq
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906749579" ID="ID_1186532291" MODIFIED="1477906752495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanProcessCommandQueue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906804427" ID="ID_1219837767" MODIFIED="1477906807051">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSendCommandMthread
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477906807731" ID="ID_1877967967" LINK="#ID_689005050" MODIFIED="1477906902262">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetTxCmdEvent2Hif
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_TX_CMD_BIT
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1474869613147" ID="ID_1634330745" MODIFIED="1478608860820" TEXT="Rx">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1478609026045" ID="ID_371298183" MODIFIED="1478609034379" TEXT="&#x91cd;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1478609035637" ID="ID_1023776888" MODIFIED="1478609039642">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P_SW_RFB_T
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609079287" ID="ID_1174012463" MODIFIED="1478609090265">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HW_MAC_RX_DESC_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RX Descriptor
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477302877779" ID="ID_718161628" MODIFIED="1477645223227" TEXT="nicRxProcessRFBs">
<node COLOR="#111111" CREATED="1477302939309" ID="ID_112670701" MODIFIED="1477477586444" TEXT="management">
<node COLOR="#111111" CREATED="1477302944164" ID="ID_641779340" MODIFIED="1477477586444">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>nicRxProcessMgmtPacket</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477302988454" ID="ID_84848527" MODIFIED="1477477586445" TEXT="apfnProcessRxMgtFrame">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      register the callback function for different subtype management
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477303186470" ID="ID_875353768" LINK="#ID_1750226335" MODIFIED="1477477586445">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanProcessBeaconAndProbeResp
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477303128516" ID="ID_1978593939" MODIFIED="1477477586446">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxReturnRFB
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477644870952" ID="ID_218561813" MODIFIED="1477644874896">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      event
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645048358" ID="ID_1661823962" MODIFIED="1477645050614">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxProcessEventPacket
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645098368" FOLDED="true" ID="ID_549719678" LINK="#ID_1017937243" MODIFIED="1477829659112">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      arEventTable
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645212621" ID="ID_163788232" MODIFIED="1477645214563">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      EVENT_ID_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477645160066" ID="ID_48056886" MODIFIED="1477645162040">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxReturnRFB
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478610354397" ID="ID_455255118" MODIFIED="1478610356852">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      data
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478610387583" ID="ID_1167559123" MODIFIED="1478610389630">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxProcessDataPacket
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477645224397" ID="ID_1017937243" MODIFIED="1477648185753">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Event Callbacks table
    </p>
    <p>
      <b><font color="#0000cc">arEventTable</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645289719" ID="ID_1025007394" MODIFIED="1477645292485">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      EVENT_ID_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477640573759" ID="ID_1225341160" MODIFIED="1477648164495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicEventScanDone
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477640577079" ID="ID_660083946" MODIFIED="1477640582897">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnEventScanDone
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477640583823" ID="ID_820401909" MODIFIED="1477640620036">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmGenerateScanDoneMsg
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477642841544" ID="ID_1883824724" MODIFIED="1477642843495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mboxSendMsg
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477642847424" ID="ID_1480029553" MODIFIED="1477642854968">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_RLM_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477642855816" ID="ID_78243983" LINK="#ID_1156010732" MODIFIED="1477642961662">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_AIS_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477642866904" ID="ID_1128131937" MODIFIED="1477642869514">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_P2P_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477642876521" ID="ID_1632792911" MODIFIED="1477642878884">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_BOW_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477892345158" ID="ID_508142006" MODIFIED="1477894527948">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSteps
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_FSM's state change from <b>SCANNING</b>&#160;to <b>IDLE</b>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
<node COLOR="#111111" CREATED="1477892356417" ID="ID_667278490" MODIFIED="1477892373884">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state <b><font color="#0000cc">SCAN_STATE_IDLE</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1477646797989" ID="ID_1480319569" MODIFIED="1478609313550">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20013;&#26029;&#22788;&#29702;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477647024365" ID="ID_1359664305" MODIFIED="1477647026716">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glBusSetIrq
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647133553" ID="ID_550828570" MODIFIED="1477647139896">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PCIE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477647140425" ID="ID_1912513464" MODIFIED="1477647143295">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SDIO
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647292551" ID="ID_1050159610" MODIFIED="1477647294838">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mtk_sdio_interrupt
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647304527" ID="ID_1912314167" MODIFIED="1477647306372">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetIntEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647316287" ID="ID_1975102463" MODIFIED="1477647320837" TEXT="&#x591a;&#x7ebf;&#x7a0b;">
<node COLOR="#111111" CREATED="1477647322160" ID="ID_969247790" LINK="#ID_1666106321" MODIFIED="1477647455606">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake up hif_thread
    </p>
    <p>
      <b><font color="#0000cc">GLUE_FLAG_INT_BIT</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647353065" ID="ID_517606336" MODIFIED="1477647359542">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21333;&#32447;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647371305" ID="ID_512331115" MODIFIED="1477647397573">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake up main_thread
    </p>
    <p>
      <b><font color="#0000cc">GLUE_FLAG_INT_BIT</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477647143898" ID="ID_625780614" MODIFIED="1477647149375">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      USB
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647515999" ID="ID_895161077" MODIFIED="1477899330864">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanIST
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647560520" ID="ID_487479042" MODIFIED="1477647563756">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessIST
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647583593" ID="ID_1286985491" MODIFIED="1477647869364">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessIST_impl
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_210965563" ENDARROW="Default" ENDINCLINATION="52;-26;" ID="Arrow_ID_1071944013" STARTARROW="None" STARTINCLINATION="-106;-73;"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477647630555" ID="ID_210965563" MODIFIED="1477647869364">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;&#20989;&#25968;
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_210965563" ENDARROW="Default" ENDINCLINATION="52;-26;" ID="Arrow_ID_1071944013" SOURCE="ID_1286985491" STARTARROW="None" STARTINCLINATION="-106;-73;"/>
<node COLOR="#111111" CREATED="1477647642884" ID="ID_97567096" MODIFIED="1477647688681">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_ABNORMAL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647713750" ID="ID_771999360" MODIFIED="1477647715796">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessAbnormalInterrupt
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647654100" ID="ID_154723805" MODIFIED="1477647695543">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_SW_INT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647717974" ID="ID_991248087" MODIFIED="1477647723594">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessSoftwareInterrupt
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647696501" ID="ID_862535768" MODIFIED="1477647701824">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_TX
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647725326" ID="ID_584743851" MODIFIED="1477647731761">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessTxInterrupt
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647702670" ID="ID_1673536404" MODIFIED="1477647707888">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_RX
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647733638" ID="ID_754780600" MODIFIED="1477647748633">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessRxInterrupt
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609381441" ID="ID_665045712" MODIFIED="1478609395507">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halProcessRxInterrupt
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609435460" ID="ID_1778967641" MODIFIED="1478662786861">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halProcessRxInterrupt
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rReceivedRFBList
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609418435" ID="ID_1241315098" MODIFIED="1478609425242">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PCIe
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609425684" ID="ID_994708404" MODIFIED="1478609428398">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SDIO
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478662679747" ID="ID_1780022212" MODIFIED="1478662752482">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#ff0000">halRxSDIOAggReceiveRFBs</font>
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="ksmiletris"/>
</node>
<node COLOR="#111111" CREATED="1478662683027" ID="ID_1378012316" MODIFIED="1478662688956">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxSDIOEnhanceReceiveRFBs
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478662689459" ID="ID_859797908" MODIFIED="1478662695762">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxSDIOReceiveRFBs
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478609429916" ID="ID_1053664668" MODIFIED="1478609434458">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      USB
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609705620" ID="ID_301905827" MODIFIED="1478609708514" TEXT="Event">
<node COLOR="#111111" CREATED="1478609652052" ID="ID_593686293" MODIFIED="1478609654332">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBProcessEventDataComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609655115" ID="ID_788732759" MODIFIED="1478609660826">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBReceiveEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478610014673" ID="ID_1534969678" MODIFIED="1478610014674" TEXT=""/>
</node>
</node>
<node COLOR="#111111" CREATED="1478609716566" ID="ID_28926351" MODIFIED="1478609720819" TEXT="Data">
<node COLOR="#111111" CREATED="1478609731854" ID="ID_438644415" MODIFIED="1478609734279">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBProcessEventDataComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609734775" ID="ID_451164536" MODIFIED="1478609740614">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBReceiveData
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477647893724" ID="ID_1525133000" LINK="#ID_1592345369" MODIFIED="1477647950351">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set <b><font color="#0000cc">GLUE_FLAG_RX_BIT</font></b>
    </p>
    <p>
      wakeup main thread
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1474869614923" FOLDED="true" ID="ID_657070274" MODIFIED="1478608847013">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Scan</b>
    </p>
    <p>
      <font color="#666666">scan.c/scan.h</font>
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477290659350" ID="ID_974125567" MODIFIED="1477477586451" TEXT="&#x4e24;&#x79cd;&#x60c5;&#x666f;">
<node COLOR="#111111" CREATED="1477290294937" ID="ID_1084460299" MODIFIED="1477477586451" TEXT="wlan scan"/>
<node COLOR="#111111" CREATED="1477290286265" ID="ID_1641378073" MODIFIED="1477477586451" TEXT="p2p scan"/>
<node COLOR="#111111" CREATED="1477292109178" ID="ID_780409427" MODIFIED="1477477586451">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SchedScan
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477531726057" ID="ID_276642409" MODIFIED="1477531798552" TEXT="NLO SCAN">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <h1 id="wi-fi-network-list-offload" sourcefile="network/wi-fi-network-list-offload.md" sourcestartlinenumber="7" sourceendlinenumber="7" style="margin-top: 0px; margin-right: 0px; margin-bottom: 20px; margin-left: 0px; font-size: 34px; font-family: Segoe UI, Tahoma, Helvetica, sans-serif; font-weight: 400; line-height: 1.2; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; background-color: rgb(255, 255, 255)">
      Wi-Fi Network List Offload(NLO)
    </h1>
    <p>
      <font color="rgb(51, 51, 51)" face="Segoe UI, Lucida Grande, Verdana, Arial, Helvetica, sans-serif" size="15px">Wi-Fi Network List Offload (NLO) is a feature where certain Wi-Fi profile information </font>
    </p>
    <p>
      <font color="rgb(51, 51, 51)" face="Segoe UI, Lucida Grande, Verdana, Arial, Helvetica, sans-serif" size="15px">is offloaded to the NIC firmware to allow the Wi-Fi NIC to perform logic that optimizes </font>
    </p>
    <p>
      <font color="rgb(51, 51, 51)" face="Segoe UI, Lucida Grande, Verdana, Arial, Helvetica, sans-serif" size="15px">the power efficiency and connectivity of a given system.&#160;</font>
    </p>
    <h1 id="wi-fi-network-list-offload" sourcefile="network/wi-fi-network-list-offload.md" sourcestartlinenumber="7" sourceendlinenumber="7" style="margin-top: 0px; margin-right: 0px; margin-bottom: 20px; margin-left: 0px; font-size: 34px; font-family: Segoe UI, Tahoma, Helvetica, sans-serif; font-weight: 400; line-height: 1.2; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; background-color: rgb(255, 255, 255)">
      
    </h1>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292806051" ID="ID_950525852" MODIFIED="1477477586452" TEXT="&#x4e3b;&#x8981;&#x8fc7;&#x7a0b;">
<node COLOR="#111111" CREATED="1477292818043" ID="ID_802581462" MODIFIED="1477477586452">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnInit
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477292860036" FOLDED="true" ID="ID_519645803" MODIFIED="1477477586453">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21021;&#22987;&#21270;P_SCAN_INFO_T
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477292869405" ID="ID_1519321590" MODIFIED="1477477586453">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.rScanInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292901398" FOLDED="true" ID="ID_1388995380" MODIFIED="1477477586453">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      1. &#35774;&#32622;&#24403;&#21069;&#29366;&#24577;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477292933784" ID="ID_775387935" MODIFIED="1477477586454">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;eCurrentState = SCAN_STATE_IDLE;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292945162" FOLDED="true" ID="ID_192402074" MODIFIED="1477477586454">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      2. &#21021;&#22987;&#21270;&#26410;&#20915;&#28040;&#24687;&#22788;&#29702;&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477292973849" ID="ID_1618147985" MODIFIED="1477477586455">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      LINK_INITIALIZE(&amp;prScanInfo-&gt;rPendingMsgList);
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292991953" ID="ID_281477680" MODIFIED="1477477586455">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      3. &#37325;&#32622;BSS_DESC_T&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477293033548" ID="ID_1051847339" MODIFIED="1477477586455">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;rFreeBSSDescLis
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Bss Desc Pool
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477293036531" ID="ID_541992024" MODIFIED="1477477586456">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;rBSSDescList
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      current scan result list
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477303252296" ID="ID_1750226335" MODIFIED="1477477586457">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>scanProcessBeaconAndProbeResp</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      handling beacon and probe response frames.
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477290572027" FOLDED="true" ID="ID_111598812" MODIFIED="1477554893665">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477290901558" ID="ID_513386577" MODIFIED="1477477586458">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct _BSS_DESC_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      BSS Descriptors
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474038366" ID="ID_1368560812" MODIFIED="1477477586458" TEXT="&#x57fa;&#x672c;&#x4fe1;&#x606f;">
<node COLOR="#111111" CREATED="1477474054446" ID="ID_1056118601" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      BSSID
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474075951" ID="ID_299760844" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Source Mac Addr
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474099280" ID="ID_735465438" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36830;&#25509;&#29366;&#24577;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474106624" ID="ID_731489070" MODIFIED="1477477586459" TEXT="fgIsConnecting"/>
<node COLOR="#111111" CREATED="1477474112961" ID="ID_530925033" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsConnected
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474127736" ID="ID_105800202" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsHiddenSSID
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hidden SSID?
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474153322" ID="ID_1385306444" MODIFIED="1477477586459" TEXT="SSID">
<node COLOR="#111111" CREATED="1477474158715" ID="ID_1744931162" MODIFIED="1477477586460" TEXT="name"/>
<node COLOR="#111111" CREATED="1477474161363" ID="ID_1658090105" MODIFIED="1477477586460" TEXT="len"/>
</node>
<node COLOR="#111111" CREATED="1477474170075" ID="ID_1918106060" MODIFIED="1477477586460" TEXT="&#x66f4;&#x65b0;&#x65f6;&#x95f4;">
<node COLOR="#111111" CREATED="1477474177378" ID="ID_711023715" MODIFIED="1477477586460">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rUpdateTime
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474189260" ID="ID_1890044702" MODIFIED="1477477586460" TEXT="&#x7c7b;&#x578b;">
<node COLOR="#111111" CREATED="1477474193683" ID="ID_1601500759" MODIFIED="1477477586460">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      infra
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474216189" ID="ID_710342362" MODIFIED="1477477586460" TEXT="p2p"/>
<node COLOR="#111111" CREATED="1477474219108" ID="ID_734862467" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ibss
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474223788" ID="ID_1115738656" MODIFIED="1477477586461" TEXT="bow"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477474241501" ID="ID_63678195" MODIFIED="1477477586461" TEXT="802.11&#x534f;&#x8bae;&#x76f8;&#x5173;&#x4fe1;&#x606f;">
<node COLOR="#111111" CREATED="1477474253221" ID="ID_347659196" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Capability Info
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474269662" ID="ID_1722160373" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      u2CapInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474279527" ID="ID_1725706100" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Beacon Interval
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474326616" ID="ID_771943942" MODIFIED="1477477586461" TEXT="&#x57fa;&#x672c;&#x901f;&#x7387;&#x96c6;"/>
<node COLOR="#111111" CREATED="1477474350497" ID="ID_1692244334" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Physic Mode&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474363065" ID="ID_390659831" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsERPPresent
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474366105" ID="ID_1218704099" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsHTPresent
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474374153" ID="ID_1289574445" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsVHTPresent
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474411891" ID="ID_982826160" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474426411" ID="ID_1243014730" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ucChannelNum
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474453358" ID="ID_1561315046" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      eChannelWidth
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bandwidth
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474479230" ID="ID_123455038" MODIFIED="1477477586462" TEXT="eBand">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Band
    </p>
    <ol>
      <li>
        2.4G
      </li>
      <li>
        5G
      </li>
    </ol>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474528440" ID="ID_676069200" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#24687;&#24378;&#24230;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474534088" ID="ID_1853737326" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WMM
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474562457" ID="ID_1721870089" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RSN&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474580017" ID="ID_426129624" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21152;&#23494;&#31639;&#27861;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474585897" ID="ID_1228925074" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#33021;&#21147;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474635099" ID="ID_1203629817" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p&#30456;&#20851;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474671580" ID="ID_828540053" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IE&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474676188" ID="ID_1315522324" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36830;&#25509;&#22833;&#36133;&#32479;&#35745;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477465186451" ID="ID_100076397" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct _STA_RECORD_T
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291055180" ID="ID_555869001" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      used by SCN_FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477290963257" ID="ID_1204016248" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_PARAM_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Used by SCAN FSM
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#ff0099" DESTINATION="ID_1204016248" ENDARROW="Default" ENDINCLINATION="98;0;" ID="Arrow_ID_677627362" SOURCE="ID_1372399135" STARTARROW="None" STARTINCLINATION="98;0;"/>
<node COLOR="#111111" CREATED="1477474730575" ID="ID_1495468912" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#31867;&#22411;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474739247" ID="ID_397143539" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Active Scan
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474746351" ID="ID_4663029" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Passive Scan
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474765576" ID="ID_921106146" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#32593;&#32476;&#31867;&#22411;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474779848" ID="ID_665590202" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Bss Index
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474795088" ID="ID_381116240" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474872156" ID="ID_523300105" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#22810;&#20010;SSID
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474798921" ID="ID_334846117" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31867;&#22411;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474811922" ID="ID_368494423" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25968;&#37327;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474890205" ID="ID_18985290" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#29305;&#23450;SSID
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474918822" ID="ID_1291615766" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p&#35774;&#22791;&#25195;&#25551;&#30456;&#20851;&#35774;&#23450;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474957166" ID="ID_463495081" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      802.11&#21327;&#35758;&#30456;&#20851;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474972127" ID="ID_990116057" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#39547;&#30041;&#26102;&#38388;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474985495" ID="ID_1407102684" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36229;&#26102;&#26102;&#38388;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475005176" ID="ID_264871455" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      OBSS Scan?
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475123789" ID="ID_1765245295" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477475043042" ID="ID_1945440015" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#30340;&#20449;&#36947;&#31867;&#22411;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477475056314" ID="ID_266450065" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      2.4G
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475062962" ID="ID_1422847998" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      5G
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475072818" ID="ID_1447368751" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p social channel
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475081587" ID="ID_295642648" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Specified
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475135557" ID="ID_111714148" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475158526" ID="ID_585445635" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IE&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290992209" ID="ID_769108161" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      NLO_PARAM_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Used by SCAN FSM
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#3333ff" DESTINATION="ID_769108161" ENDARROW="Default" ENDINCLINATION="99;0;" ID="Arrow_ID_855709524" SOURCE="ID_1562519665" STARTARROW="None" STARTINCLINATION="99;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477291101885" ID="ID_1614107042" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_INFO_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo = &amp;(prAdapter-&gt;rWifiVar.rScanInfo);
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291113510" ID="ID_189391468" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      eCurrentState
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Store the STATE variable of SCAN FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477465605000" ID="ID_446536825" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_IDLE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477465618042" ID="ID_1896296839" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_SCANNING
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477291126431" ID="ID_1372399135" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rScanParam
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#ff0099" DESTINATION="ID_1204016248" ENDARROW="Default" ENDINCLINATION="98;0;" ID="Arrow_ID_677627362" STARTARROW="None" STARTINCLINATION="98;0;"/>
</node>
<node COLOR="#111111" CREATED="1477291137479" ID="ID_1562519665" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rNloParam
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#3333ff" DESTINATION="ID_769108161" ENDARROW="Default" ENDINCLINATION="99;0;" ID="Arrow_ID_855709524" STARTARROW="None" STARTINCLINATION="99;0;"/>
</node>
<node COLOR="#111111" CREATED="1477465882818" ID="ID_799012932" MODIFIED="1477477586467" TEXT="BSS&#x4fe1;&#x606f;&#x7ef4;&#x62a4;">
<node COLOR="#111111" CREATED="1477465778336" ID="ID_560950253" MODIFIED="1477477586467" TEXT="u4NumOfBssDesc"/>
<node COLOR="#111111" CREATED="1477465792959" ID="ID_575156288" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aucScanBuffer
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      buffer to store bss list sequecely
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477465695699" ID="ID_1526910999" LINK="#ID_513386577" MODIFIED="1477477586467" TEXT="rBSSDescList">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      current SCAN result list
    </p>
    <p>
      a memory pool
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477465802615" ID="ID_832327262" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rFreeBSSDescList
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      build a free bss list from aucScanBuffer
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475277753" ID="ID_210522264" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN&#35831;&#27714;&#38431;&#21015;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477475289947" ID="ID_1118994445" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rPendingMsgList
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475323580" ID="ID_1289565519" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#32479;&#35745;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475428967" ID="ID_1357471693" MODIFIED="1477477586467" TEXT="mbox&#x4ea4;&#x4e92;&#x6d88;&#x606f;">
<node COLOR="#111111" CREATED="1477291271612" ID="ID_1189256975" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Incoming Mailbox Messages
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291241874" ID="ID_815930803" LINK="#ID_707929156" MODIFIED="1477554534269">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291403345" ID="ID_722449350" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291432041" ID="ID_309507790" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Cancel Scan Request
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291475931" ID="ID_1910306294" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_NLO_REQ
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291492107" ID="ID_1044574123" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_NLO_CANCEL
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477291516493" ID="ID_394372055" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Outgoing Mailbox Messages
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291525813" ID="ID_1163722504" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291570654" ID="ID_1314970388" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_NLO_DONE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290598949" ID="ID_473642935" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31574;&#30053;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291696571" ID="ID_1792220868" MODIFIED="1477477586469" TEXT="remove bss">
<node COLOR="#111111" CREATED="1477293766533" ID="ID_514776937" MODIFIED="1477477586469">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanByPassRemoveBssDesc
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bypass BSS Descriptors from current list according to specific BSSID.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477293839272" ID="ID_1605540210" MODIFIED="1477477586470">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanRemoveBssDescsByPolicy
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Delete BSS Descriptors from current list according to given Remove Policy.
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290607236" ID="ID_1136054535" MODIFIED="1477477586471">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20869;&#23384;&#31649;&#29702;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477476773759" ID="ID_274724165" MODIFIED="1477636862047">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#35843;&#29992;&#27969;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477476783720" ID="ID_1647030433" MODIFIED="1477477675023">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19978;&#23618;&#36890;&#36807;nl80211&#19979;&#36798;SCAN&#21629;&#20196;
    </p>
  </body>
</html></richcontent>
<edge COLOR="#ff0033" WIDTH="2"/>
<cloud/>
<node COLOR="#111111" CREATED="1477476799984" ID="ID_1429711910" MODIFIED="1477477586472">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mtk_cfg80211_scan
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pass down struct <b><font color="#0033ff">cfg80211_scan_request</font></b>&#160;from cfg80211
    </p>
  </body>
</html></richcontent>
<cloud/>
<node COLOR="#111111" CREATED="1477476950174" ID="ID_1767360179" MODIFIED="1477477586473">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIoctl
    </p>
  </body>
</html></richcontent>
<cloud/>
<node COLOR="#111111" CREATED="1477476963967" ID="ID_1069622385" MODIFIED="1477478300908">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Compose the I/O request
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477476987590" ID="ID_1716722940" MODIFIED="1477477586474">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P_GL_IO_REQ_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq = &amp;(prGlueInfo-&gt;OidEntry);
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477133420" FOLDED="true" ID="ID_226621999" MODIFIED="1477477835162">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477288562" ID="ID_912414172" MODIFIED="1477477586475">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prGlueInfo-&gt;prAdapter
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477162974" ID="ID_1076051513" LINK="#ID_1337511987" MODIFIED="1477828994603">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pfnOidHandler
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_1712543043" ENDARROW="None" ENDINCLINATION="618;0;" ID="Arrow_ID_688335745" STARTARROW="None" STARTINCLINATION="618;0;"/>
<node COLOR="#111111" CREATED="1477477314354" ID="ID_46143452" MODIFIED="1477477586476">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetBssidListScanAdv
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477178445" ID="ID_647046274" MODIFIED="1477477586477">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pvInfoBuf
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477902880" ID="ID_1412132363" MODIFIED="1477478000851">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rScanRequest
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      typedef struct _<b><font color="#0033ff">PARAM_SCAN_REQUEST_ADV_T</font></b>&#160;{
    </p>
    <p>
      UINT_32 u4SsidNum;
    </p>
    <p>
      PARAM_SSID_T rSsid[CFG_SCAN_SSID_MAX_NUM];
    </p>
    <p>
      UINT_32 u4IELength;
    </p>
    <p>
      PUINT_8 pucIE;
    </p>
    <p>
      } PARAM_SCAN_REQUEST_ADV_T, *P_PARAM_SCAN_REQUEST_ADV_T;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477184230" ID="ID_1309081189" MODIFIED="1477477586478">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      u4InfoBufLen
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477477190566" ID="ID_823429363" MODIFIED="1477477586478">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pu4QryInfoLen
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477477197310" ID="ID_223307251" MODIFIED="1477477586479">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgRead
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478057757" ID="ID_742691517" MODIFIED="1477478062204">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477204031" ID="ID_842732216" MODIFIED="1477477586479">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgWaitResp
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478064974" ID="ID_970504991" MODIFIED="1477478068371">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477213647" FOLDED="true" ID="ID_185948720" MODIFIED="1477477586480">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rStatus
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477222168" ID="ID_1817955160" MODIFIED="1477477586480">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_FAILURE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477248432" ID="ID_499817139" MODIFIED="1477478101905">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      u4Flag
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Check if we use the command queue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478085902" ID="ID_1807825234" MODIFIED="1477478090605">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478110863" ID="ID_120385381" MODIFIED="1477478515982">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      schedule the OID bit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set_bit(<b><font color="#0033ff">GLUE_FLAG_OID_BIT</font></b>, &amp;prGlueInfo-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477478182810" ID="ID_166748027" LINK="#ID_1951763154" MODIFIED="1477478532787">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Wake up tx thread
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_up_interruptible(&amp;prGlueInfo-&gt;waitq);
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477478211571" ID="ID_879006110" MODIFIED="1477479718565">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Block and wait for event or timeout
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wait_for_completion(&amp;<b><font color="#0033ff">prGlueInfo-&gt;rPendComp</font></b>);
    </p>
    <p>
      timeout value is 2 secs
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="803;0;" ID="Arrow_ID_1875886394" SOURCE="ID_291787242" STARTARROW="None" STARTINCLINATION="803;0;"/>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="778;0;" ID="Arrow_ID_146360375" SOURCE="ID_1536799758" STARTARROW="None" STARTINCLINATION="778;0;"/>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477478270845" ID="ID_1464162105" MODIFIED="1477478314755">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Clear bit for error handling
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      clear_bit(GLUE_FLAG_OID_BIT, &amp;prGlueInfo-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477477108132" ID="ID_1337511987" MODIFIED="1477479788588">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetBssidListScanAdv
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This routine is called to request the driver to perform
    </p>
    <p>
      scanning with attaching information elements(IEs)
    </p>
    <p>
      specified from user space and multiple SSID
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479879727" ID="ID_538709746" MODIFIED="1477551422515">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;fgEnOnlineScan
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      whether allow scanning when already connected to an AP ?
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479889975" ID="ID_835399990" MODIFIED="1477479891981">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      TRUE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479898599" ID="ID_336713407" LINK="#ID_184662158" MODIFIED="1477482543139">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequestAdv
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477479992427" ID="ID_965398900" MODIFIED="1477479997943" TEXT="FALSE">
<node COLOR="#111111" CREATED="1477480044044" ID="ID_908606429" MODIFIED="1477480077462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalGetMediaStateIndicated
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      get connect state
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480079246" ID="ID_900373954" MODIFIED="1477480086179">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PARAM_MEDIA_STATE_CONNECTED
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480167440" ID="ID_1211208977" MODIFIED="1477480202590">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      return <b><font color="#0000cc">WLAN_STATUS_FAILURE</font></b>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477480087309" ID="ID_1032960215" MODIFIED="1477480114382">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PARAM_MEDIA_STATE_DISCONNECTED
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480138375" ID="ID_524430459" LINK="#ID_184662158" MODIFIED="1477482572676">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequestAdv
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477480222475" ID="ID_149967130" MODIFIED="1477480225042">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmTimerStartTimer
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480247091" ID="ID_176351557" MODIFIED="1477480268555">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21551;&#21160;&#25195;&#25551;&#35745;&#26102;&#22120;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.rAisFsmInfo.rScanDoneTimer
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480269997" ID="ID_1741018689" MODIFIED="1477480296900">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36229;&#26102;&#26102;&#38388;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480301214" ID="ID_214715576" MODIFIED="1477480343238">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">AIS_SCN_DONE_TIMEOUT_SEC</font>
    </p>
    <p>
      <b>15 s</b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477477366116" ID="ID_142109904" MODIFIED="1477640370006">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Scan&#32467;&#26463;&#21518;&#22238;&#35843;&#27969;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477829439532" ID="ID_222825614" LINK="#ID_895161077" MODIFIED="1477829513992">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FW&#36890;&#36807;&#20013;&#26029;&#36890;&#30693;SCAN_DONE&#20107;&#20214;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1476693591000" ID="ID_992150334" MODIFIED="1480592258020" TEXT="mbox">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476693664979" ID="ID_692923152" MODIFIED="1477645540850">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>arMsgMapTable</b>
    </p>
    <p>
      <font color="#999999">hem_mbox.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476693720861" ID="ID_1454704760" MODIFIED="1477477586483" TEXT="SCN">
<node COLOR="#111111" CREATED="1477554478206" ID="ID_707929156" LINK="#ID_815930803" MODIFIED="1477554519996">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554494119" ID="ID_207557093" MODIFIED="1477554497100">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554541128" ID="ID_112483751" MODIFIED="1477554547191">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554548536" ID="ID_1555617083" LINK="#ID_1421132781" MODIFIED="1477555058720">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554557481" ID="ID_968488606" MODIFIED="1477554565303">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554570209" ID="ID_1336062308" MODIFIED="1477554572295">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554573681" ID="ID_985885395" MODIFIED="1477554585297">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_P2P_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554588362" ID="ID_1596296588" MODIFIED="1477554600608">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554613138" ID="ID_1444765102" MODIFIED="1477554619618">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_P2P_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554620683" ID="ID_973494335" MODIFIED="1477554626137">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554627587" ID="ID_1459228768" MODIFIED="1477554633289">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_P2P_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554634484" ID="ID_843296139" MODIFIED="1477554640026">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554642995" ID="ID_1732571689" MODIFIED="1477554649683">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_BOW_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554650748" ID="ID_459932698" MODIFIED="1477554656842">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554659020" ID="ID_708950156" MODIFIED="1477554665283">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_BOW_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554666237" ID="ID_886794284" MODIFIED="1477554671778">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554673349" ID="ID_1105551288" MODIFIED="1477554678907">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_BOW_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554680021" ID="ID_1773590875" MODIFIED="1477554686845">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554688981" ID="ID_552679161" MODIFIED="1477554696651">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_RLM_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554697766" ID="ID_1111845697" MODIFIED="1477554704324">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554706030" ID="ID_1980602823" MODIFIED="1477554712148">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_RLM_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554713286" ID="ID_1292966190" MODIFIED="1477554719374">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554721126" ID="ID_1592808333" MODIFIED="1477554726837">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_RLM_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554727775" ID="ID_1329912397" MODIFIED="1477554732908">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554734744" ID="ID_1156010732" MODIFIED="1477554758430">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_AIS_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554750864" ID="ID_801912226" MODIFIED="1477904068823">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventScanDone
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477643165179" ID="ID_1973140841" MODIFIED="1477643171616">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_SCAN
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477643224349" ID="ID_29359823" MODIFIED="1477643270247">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalScanDone
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477643997121" ID="ID_19129868" MODIFIED="1477643999120">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIndicateBssInfo
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477644000576" ID="ID_316460872" MODIFIED="1477644015059">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cfg80211_inform_bss_frame
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477644047514" ID="ID_1742452353" MODIFIED="1477644076048">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIndicateStatusAndComplete
    </p>
    <p>
      <b><font color="#0000cc">WLAN_STATUS_SCAN_COMPLETE</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477644096452" ID="ID_1604316516" MODIFIED="1477644107318">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cfg80211_scan_done
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477643231334" ID="ID_881077698" MODIFIED="1477643272640">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanReportScanResultToAgps
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477643257390" ID="ID_556296207" MODIFIED="1477892106719">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      proceed if state change is necessary
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477643172516" ID="ID_1435505155" MODIFIED="1477643181206">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_ONLINE_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477643182052" ID="ID_1935346127" MODIFIED="1477643189990">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_LOOKING_FOR
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477554795313" ID="ID_1611852008" MODIFIED="1477554797104">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_P2P_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554798313" ID="ID_1923933303" MODIFIED="1477554804136">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pFsmRunEventScanDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554806241" ID="ID_721895666" MODIFIED="1477554813687">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_BOW_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554814666" ID="ID_619759089" MODIFIED="1477554820272">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bowResponderScanDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554822018" ID="ID_1634545795" MODIFIED="1477554827978">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_RLM_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554829090" ID="ID_782010266" MODIFIED="1477642447435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rlmObssScanDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476693728460" ID="ID_301344253" MODIFIED="1477477586484" TEXT="AIS">
<node COLOR="#111111" CREATED="1476693783637" FOLDED="true" ID="ID_1068507575" MODIFIED="1480592302142" TEXT="MID_AIS_SAA_FSM_START">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Start Event for SAA FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476693885977" ID="ID_106165759" MODIFIED="1477477586484" TEXT="saaFsmRunEventStart"/>
</node>
<node COLOR="#111111" CREATED="1476693803586" ID="ID_1561167379" MODIFIED="1480592343615" TEXT="MID_AIS_SAA_FSM_ABORT">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      STOP Event for SAA FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476693894460" ID="ID_966622547" MODIFIED="1477477586484" TEXT="saaFsmRunEventAbort"/>
</node>
<node COLOR="#111111" CREATED="1480592339943" ID="ID_1468307456" MODIFIED="1480592341977">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_OID_AIS_FSM_JOIN_REQ
    </p>
  </body>
</html>
</richcontent>
<node COLOR="#111111" CREATED="1480592348799" ID="ID_1683102159" MODIFIED="1480592355583">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventAbort
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1476693910068" FOLDED="true" ID="ID_1542906064" MODIFIED="1478608826982" TEXT="FSM">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476693913846" ID="ID_1211971427" MODIFIED="1477477586485" TEXT="SAA">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      STA Auth &amp; Assoc
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476694135627" ID="ID_1318692252" MODIFIED="1477829066013" TEXT="AIS">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Ad-hoc, Infra STA&#160;&#160;FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480655538" FOLDED="true" ID="ID_1040396993" MODIFIED="1477554303981" TEXT="STATE">
<node COLOR="#111111" CREATED="1477480659563" ID="ID_1904536252" MODIFIED="1477480665586">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IDLE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480666667" ID="ID_647365706" MODIFIED="1477480672249">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SEARCH
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480673203" ID="ID_701825282" MODIFIED="1477480679153">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480680043" ID="ID_372268151" MODIFIED="1477480686433">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ONLINE_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480687355" ID="ID_1690362886" MODIFIED="1477480692697">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      LOOKING_FOR
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480694363" ID="ID_842509395" MODIFIED="1477480699884">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WAIT_FOR_NEXT_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480700764" ID="ID_285209394" MODIFIED="1477480705994">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      REQ_CHANNEL_JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480706812" ID="ID_1401206678" MODIFIED="1477480712122">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480712996" ID="ID_1965424597" MODIFIED="1477480718738">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      JOIN_FAILURE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480719669" ID="ID_1544181951" MODIFIED="1477480725034">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IBSS_ALONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480726004" ID="ID_1957569222" MODIFIED="1477480731228">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IBSS_MERGE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480732349" ID="ID_609586142" MODIFIED="1477480737539">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      NORMAL_TR
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480738428" ID="ID_1889029" MODIFIED="1477480743651">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      DISCONNECTING
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480745405" ID="ID_16508893" MODIFIED="1477480751404">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      REQ_REMAIN_ON_CHANNEL
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480752286" ID="ID_341853372" MODIFIED="1477480757451">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      REMAIN_ON_CHANNEL
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482754469" ID="ID_622348699" MODIFIED="1477482772683">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FSM Core Functions
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482778742" ID="ID_1682900993" MODIFIED="1477482781405">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisInitializeConnectionSettings
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482782479" ID="ID_1571932236" MODIFIED="1477482787708">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInit
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482788590" ID="ID_775147704" MODIFIED="1477482793772">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmUninit
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482794663" ID="ID_542259582" MODIFIED="1477482800222">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482801367" ID="ID_1534713462" MODIFIED="1477482806893">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_RetryJOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482807783" ID="ID_167274226" MODIFIED="1477482813957">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_IBSS_ALONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482814895" ID="ID_269479070" MODIFIED="1477482820094">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_IBSS_MERGE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482826496" ID="ID_1397501811" MODIFIED="1477553425306">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482847320" ID="ID_540371941" MODIFIED="1477482852655">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482853825" ID="ID_768895720" MODIFIED="1477482859399">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482863977" ID="ID_1543668215" MODIFIED="1477482867271">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_NORMAL_TR
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482871858" ID="ID_11320693" MODIFIED="1477482874217">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_IBSS
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482830744" ID="ID_1572267202" MODIFIED="1477482844616">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477554271798" ID="ID_196946174" MODIFIED="1477554291990">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_SCAN
    </p>
    <p>
      AIS_STATE_ONLINE_SCAN
    </p>
    <p>
      AIS_STATE_LOOKING_FOR
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554329033" ID="ID_1076426446" MODIFIED="1477554331816">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mboxSendMsg
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554362193" ID="ID_311556819" LINK="#ID_112483751" MODIFIED="1477554997358">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_ID: <b><font color="#0000cc">MID_AIS_SCN_SCAN_REQ_V2</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477481694847" FOLDED="true" ID="ID_1548432717" MODIFIED="1477553371834">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Message Handling
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      generally request from other module.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477481708767" ID="ID_1801478820" MODIFIED="1477481710526">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventScanDone
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481711368" ID="ID_278169892" MODIFIED="1477481717045">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventAbort
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481718024" ID="ID_192789954" MODIFIED="1477481726142">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventJoinComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481727112" ID="ID_274098967" MODIFIED="1477481732079">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmJoinCompleteAction
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481732977" ID="ID_1962306271" MODIFIED="1477481738208">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventFoundIBSSPeer
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481739161" ID="ID_1769589146" MODIFIED="1477481744135">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventRemainOnChannel
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481745033" ID="ID_1407959973" MODIFIED="1477481750248">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventCancelRemainOnChannel
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477481787754" ID="ID_510565649" MODIFIED="1477481790314">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Handling for Ad-Hoc Network
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477481791291" ID="ID_379291764" MODIFIED="1477481796753">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmCreateIBSS
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481797834" ID="ID_1553498404" MODIFIED="1477481803769">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmMergeIBSS
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477481873606" ID="ID_1458784061" MODIFIED="1477481959600">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19982;CNM&#30340;&#20132;&#20114;&#25509;&#21475;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477481909880" ID="ID_512879723" MODIFIED="1477482024868">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventChGrant
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Handling of Incoming Mailbox Message from CNM
    </p>
    <p>
      <b>This function is invoked when CNM granted channel privilege</b>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481969002" ID="ID_925279702" MODIFIED="1477482002332">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmReleaseCh
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Generating Outgoing Mailbox Message to CNM&#160;&#160;
    </p>
    <p>
      <b>This function is to inform CNM that channel privilege has been released</b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482107806" ID="ID_758133389" MODIFIED="1477482110221">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Event Indication
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482111375" ID="ID_561891072" MODIFIED="1477482117420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisIndicationOfMediaStateToHost
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482118302" ID="ID_1513822876" MODIFIED="1477482124204">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisPostponedEventOfDisconnTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482128390" ID="ID_55508335" MODIFIED="1477482130701">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForJOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482131687" ID="ID_7347501" MODIFIED="1477482136869">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForCreateIBSS
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482137751" ID="ID_174422105" MODIFIED="1477482142638">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForMergeIBSS
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482143543" ID="ID_1336624121" MODIFIED="1477482149062">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisValidateProbeReq
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482149552" ID="ID_115178411" MODIFIED="1477482156053">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventMgmtFrameTxDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482212658" FOLDED="true" ID="ID_1911764015" MODIFIED="1477553355922">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Disconnection Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482215362" ID="ID_699120501" MODIFIED="1477482222904">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmDisconnect
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482225394" FOLDED="true" ID="ID_1285977921" MODIFIED="1477553353938">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Event Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482237898" ID="ID_739808769" MODIFIED="1477482239521">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisBssBeaconTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482245315" ID="ID_516235715" MODIFIED="1477482246962">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisDeauthXmitComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482247723" ID="ID_729780112" MODIFIED="1477482271154">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Roaming Related Event Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482272476" ID="ID_1547640600" MODIFIED="1477482278139">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventRoamingDiscovery
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482279092" ID="ID_1604579969" MODIFIED="1477482283994">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRoamingScanResultsUpdate
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482288116" ID="ID_16172397" MODIFIED="1477482290155">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRoamingDisconnectPrevAP
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482291021" ID="ID_1286115839" MODIFIED="1477482297306">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForRoamingAP
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477482304149" FOLDED="true" ID="ID_411145601" MODIFIED="1477553352466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Timeout Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482310566" ID="ID_108444415" MODIFIED="1477482312108">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventBGSleepTimeOut
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482312653" ID="ID_1652347518" MODIFIED="1477482318827">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventIbssAloneTimeOut
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482319950" ID="ID_855173321" MODIFIED="1477482324811">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventJoinTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482347182" ID="ID_1804542649" MODIFIED="1477482349174">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventChannelTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482349791" ID="ID_1103620011" MODIFIED="1477482355700">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventDeauthTimeout
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482372104" ID="ID_516326458" MODIFIED="1477482373901">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      OID/IOCTL Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482380512" ID="ID_582067968" MODIFIED="1477482382643">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482383129" ID="ID_184662158" MODIFIED="1477551489019">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequestAdv
    </p>
    <p>
      <font color="#666666">&#25195;&#25551;&#35831;&#27714;</font>
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477551697475" ID="ID_685040129" MODIFIED="1477551781948">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551795262" ID="ID_617807680" MODIFIED="1477552092904">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">P_CONNECTION_SETTINGS_T</font>
    </p>
    <p>
      <b>prConnSettings</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      connection info for this session
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551926931" ID="ID_1074124670" MODIFIED="1477551929674">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.rConnSettings
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477551798686" ID="ID_855321424" MODIFIED="1477552104264">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">P_BSS_INFO_T</font>
    </p>
    <p>
      <b>prAisBssInfo</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bss info we are interseted in
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551907058" ID="ID_250175702" MODIFIED="1477551909944">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;prAisBssInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477551805767" ID="ID_503189351" MODIFIED="1478086905061">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">P_AIS_FSM_INFO_T</font>
    </p>
    <p>
      <b>prAisFsmInfo</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS FSM info
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551941371" ID="ID_1234071593" MODIFIED="1477551945697">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;prAisBssInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552009046" ID="ID_585275497" MODIFIED="1477552017957">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAisFsmInfo-&gt;eCurrentState
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552128402" ID="ID_1492893567" MODIFIED="1477552169226">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_NORMAL_TR
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552241374" ID="ID_341758135" MODIFIED="1477552295224">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAisBssInfo-&gt;eCurrentOPMode
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552321601" ID="ID_1436421379" MODIFIED="1477552367544">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ==OP_MODE_INFRASTRUCTURE
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_897739484" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_178839207" STARTARROW="None" STARTINCLINATION="95;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477552296192" ID="ID_922496490" MODIFIED="1477552312590">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAisFsmInfo-&gt;fgIsInfraChannelFinished
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552325705" ID="ID_897739484" MODIFIED="1477552367544">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ==FALSE
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_897739484" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_178839207" SOURCE="ID_1436421379" STARTARROW="None" STARTINCLINATION="95;0;"/>
<node COLOR="#111111" CREATED="1477552373210" ID="ID_1289000536" LINK="#ID_424155986" MODIFIED="1477552413280">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>aisFsmInsertRequest</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552740432" ID="ID_1178139605" MODIFIED="1477552756120">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with AIS Request Type: <b><font color="#0000cc">AIS_REQUEST_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552419612" ID="ID_72037846" MODIFIED="1477552444701">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      start online scan
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552446301" ID="ID_1615969201" MODIFIED="1477552454740">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanClearScanningResult
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477552455766" ID="ID_1670181784" LINK="#ID_1572267202" MODIFIED="1477553446254">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552664670" ID="ID_400374290" MODIFIED="1477552683117">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state&#160;<b><font color="#0000cc">AIS_STATE_ONLINE_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552136755" ID="ID_1066144195" MODIFIED="1477989988522">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_IDLE
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552538177" ID="ID_1422748046" MODIFIED="1477552601673">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      start a normal scan
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552604659" ID="ID_343938034" MODIFIED="1477552622041">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanClearScanningResult
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477552627180" ID="ID_1106320198" LINK="#ID_1572267202" MODIFIED="1477553376676">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552688598" ID="ID_1814825695" MODIFIED="1477552706668">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state <b><font color="#0000cc">AIS_STATE_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552151010" ID="ID_841361388" MODIFIED="1477552160193">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Other State
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552786794" ID="ID_659698140" LINK="#ID_424155986" MODIFIED="1477552861657">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInsertRequest
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552801570" ID="ID_615325528" MODIFIED="1477552803495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with AIS Request Type: <b><font color="#0000cc">AIS_REQUEST_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477482404400" ID="ID_1434431261" MODIFIED="1477829137520">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Internal State Checking
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482411801" ID="ID_1362202807" MODIFIED="1477482413528">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmIsRequestPending
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482413905" ID="ID_430887369" MODIFIED="1477482419664">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmGetNextRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482420610" ID="ID_424155986" MODIFIED="1477482426615">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInsertRequest
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477553098829" FOLDED="true" ID="ID_245486345" MODIFIED="1477553204421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmMemAlloc
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477553107949" ID="ID_1237715662" MODIFIED="1477553128476">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with message type: <b><font color="#0000cc">RAM_TYPE_MSG</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477553142286" ID="ID_931275561" MODIFIED="1477553198060">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      assign request type
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477553156751" ID="ID_504661177" MODIFIED="1477553200724">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      attach request into pending request list
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477482427585" ID="ID_1862078358" MODIFIED="1477482432767">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmFlushRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482433770" ID="ID_1188343574" MODIFIED="1477482439648">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFuncTxMgmtFrame
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482441410" ID="ID_1586178318" MODIFIED="1477482448617">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventMgmtFrameTx
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482449651" ID="ID_248498561" MODIFIED="1477482455288">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFuncValidateRxActionFrame
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482456234" ID="ID_63423808" MODIFIED="1477482467769">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateSearchAction
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290143319" ID="ID_364510901" MODIFIED="1477829168417" TEXT="SCN">
<node COLOR="#111111" CREATED="1477483035431" ID="ID_1363102828" MODIFIED="1477483041151">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      STATE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483041712" ID="ID_841627897" MODIFIED="1477483088568">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Core API
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483089674" ID="ID_1379640952" MODIFIED="1477483094335">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSteps
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556153585" ID="ID_373698948" MODIFIED="1477556158545">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_SCANNING
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556184122" ID="ID_1604388897" MODIFIED="1477556191170">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanParam-&gt;fgIsScanV2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556194252" ID="ID_544831268" MODIFIED="1477556198001">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      TRUE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556203851" ID="ID_234981231" LINK="#ID_553840708" MODIFIED="1477556246364">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnSendScanReqV2
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556207924" ID="ID_118196463" MODIFIED="1477556210721">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556212099" ID="ID_467165703" LINK="#ID_1563304188" MODIFIED="1477556252362" TEXT="scnSendScanReq"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477556165819" ID="ID_1424889561" MODIFIED="1477556167624">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_IDLE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483096481" ID="ID_662090886" MODIFIED="1477483103800">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Command Routines
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483104914" ID="ID_1563304188" MODIFIED="1477483110384">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnSendScanReq
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483111338" ID="ID_553840708" MODIFIED="1477483116576">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnSendScanReqV2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556295767" ID="ID_1237140055" MODIFIED="1477556302190">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556303415" ID="ID_721505814" MODIFIED="1477556305573">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      CMD_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556308424" ID="ID_713874291" LINK="#ID_1442064134" MODIFIED="1478249736344">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSendSetQueryCmd
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556399315" ID="ID_1957759747" MODIFIED="1477556432843">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with CMD ID: <b><font color="#0000cc">CMD_ID_SCAN_REQ_V2</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483125530" ID="ID_1246221461" MODIFIED="1477483128009">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RX Event Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483129067" ID="ID_1948356942" MODIFIED="1477483134977">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnEventScanDone
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483136099" ID="ID_721898979" MODIFIED="1477483141637">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnEventNloDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483153267" ID="ID_870417098" MODIFIED="1477483155849">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Message Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483162124" ID="ID_1421132781" MODIFIED="1477483163771">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555129397" ID="ID_817452930" MODIFIED="1477555161653">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;eCurrentState
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555163062" ID="ID_371080413" MODIFIED="1477555168988">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_IDLE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555221488" ID="ID_1609708153" MODIFIED="1477637234068">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prMsgHdr-&gt;eMsgId
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477555237329" ID="ID_604881773" MODIFIED="1477555324876">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ
    </p>
    <p>
      MID_BOW_SCN_SCAN_REQ
    </p>
    <p>
      MID_P2P_SCN_SCAN_REQ
    </p>
    <p>
      MID_RLM_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555283426" ID="ID_1791561333" MODIFIED="1477555285369">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsg
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477555303691" ID="ID_605993079" MODIFIED="1477555358028">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ_V2
    </p>
    <p>
      MID_BOW_SCN_SCAN_REQ_V2
    </p>
    <p>
      MID_P2P_SCN_SCAN_REQ_V2
    </p>
    <p>
      MID_RLM_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555366654" ID="ID_621938065" LINK="#ID_29798312" MODIFIED="1477555510664">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsgV2
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477555395911" ID="ID_859121157" MODIFIED="1477637236616">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmMemFree
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      release buffer for msg
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477555428592" ID="ID_172917893" LINK="#ID_1379640952" MODIFIED="1477637239280">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSteps
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477555438272" ID="ID_1344535439" MODIFIED="1477555773229">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state: <b><font color="#0000cc">SCAN_STATE_SCANNING</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477555170055" ID="ID_1386378850" MODIFIED="1477555186301">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_SCANNING
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483164187" ID="ID_1064532520" MODIFIED="1477483170979">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483171908" ID="ID_1858236900" MODIFIED="1477483177737">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsg
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483178612" ID="ID_29798312" MODIFIED="1477556040546">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsgV2
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
<node COLOR="#111111" CREATED="1477555625287" ID="ID_1670424581" MODIFIED="1477555669231">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      setting Scan Param: <b><font color="#0000cc">P_SCAN_PARAM_T</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555677985" ID="ID_1029943358" MODIFIED="1477555681718">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Scan Type
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555686633" ID="ID_260462458" MODIFIED="1477555690766">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Bss Index
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555691177" ID="ID_1720597950" MODIFIED="1477555698847">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID type
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555713026" ID="ID_31823836" MODIFIED="1477555716729">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID Num
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555717314" ID="ID_865993612" MODIFIED="1477555720031">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555726802" ID="ID_1822037584" MODIFIED="1477555730824">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Scan Channel
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555741403" ID="ID_1638400406" MODIFIED="1477555746617">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Timeout Value
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555749275" ID="ID_1473432751" MODIFIED="1477555816278">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Channel Dwell time
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483184908" ID="ID_333681298" MODIFIED="1477483189771">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmRemovePendingMsg
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483194565" ID="ID_1931146536" MODIFIED="1477483197925">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmNloMsgStart
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483202749" ID="ID_823266201" MODIFIED="1477483206139">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmNloMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483211862" ID="ID_421395313" MODIFIED="1477483215203">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleNloMsg
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483237366" ID="ID_449311254" MODIFIED="1477483239766">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Message Generation
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483240799" ID="ID_1307272436" MODIFIED="1477483246340">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmGenerateScanDoneMsg
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483249415" ID="ID_823054938" MODIFIED="1477483256076">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Query for sparse channel
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483257183" ID="ID_1739087059" MODIFIED="1477483262501">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnQuerySparseChannel
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483264375" ID="ID_619991712" MODIFIED="1477483276007">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      OID/IOCTL Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483276967" ID="ID_158068229" MODIFIED="1477483284389">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSchedScanRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483285248" ID="ID_1006944073" MODIFIED="1477483291279">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSchedScanStopRequest
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1478249682855" FOLDED="true" ID="ID_807800814" MODIFIED="1479713641818" TEXT="&#x53d1;&#x9001;CMD&#x5230;FW&#x6d41;&#x7a0b;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477556308424" ID="ID_1442064134" MODIFIED="1477556346897">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSendSetQueryCmd
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556462093" ID="ID_837888381" MODIFIED="1477556463939">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalEnqueueCommand
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556493582" ID="ID_1603600277" MODIFIED="1477556514245">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      put command into <b><font color="#0000cc">prGlueInfo-&gt;rCmdQueue</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556555633" ID="ID_874438551" MODIFIED="1478087062292">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wakeup txServiceThread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556584594" ID="ID_766634053" MODIFIED="1477556591224">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_SET_EVENT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556598546" ID="ID_1613175776" MODIFIED="1477556600367">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556612426" ID="ID_720557484" MODIFIED="1477556629682">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set_bit(<font color="#0000cc"><b>GLUE_FLAG_TXREQ_BIT</b></font>, &amp;pr-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477556631123" ID="ID_1158173467" LINK="#ID_1063622589" MODIFIED="1477556776357">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_up_interruptible(&amp;<b><font color="#0000cc">pr-&gt;waitq</font></b>);
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478249913726" ID="ID_1793318995" MODIFIED="1478249924708" TEXT="&#x603b;&#x7ebf;&#x63a5;&#x53e3;">
<node COLOR="#111111" CREATED="1478249925742" ID="ID_1167897569" MODIFIED="1478249927844" TEXT="USB"/>
<node COLOR="#111111" CREATED="1478249928294" ID="ID_1909585273" MODIFIED="1478249930276" TEXT="SDIO"/>
<node COLOR="#111111" CREATED="1478249930782" ID="ID_1378663722" MODIFIED="1478249933332" TEXT="PCIe"/>
</node>
</node>
<node COLOR="#990000" CREATED="1476253194484" FOLDED="true" ID="ID_1620449917" MODIFIED="1479713645736" TEXT="&#x521d;&#x59cb;&#x5316;&#x5206;&#x6790;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476253223453" ID="ID_1530955501" MODIFIED="1477646873173">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>initWlan</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Module Entry Point
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-1"/>
<node COLOR="#111111" CREATED="1476416604252" ID="ID_1586351889" MODIFIED="1477477586491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanDebugInit()
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476416652366" ID="ID_475015037" MODIFIED="1477477586491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalInitIOBuffer();
    </p>
    <p>
      <font color="#999999">gl_kal.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Pre-allocate I/O buffer
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476416733217" ID="ID_339560446" MODIFIED="1477477586491" TEXT="procInitFs">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      make a proc root directory at /proc/net/
    </p>
    <p>
      ==&gt; /proc/net/wlan
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476416782587" ID="ID_6554090" MODIFIED="1477477586491" TEXT="wlanCreateWirelessDevice">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      for legacy wlan
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476416801739" ID="ID_1935753722" MODIFIED="1477477586491" TEXT="glP2pCreateWirelessDevice">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      for p2p
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476416982706" ID="ID_1103868742" MODIFIED="1477477586491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glRegisterBus
    </p>
    <p>
      <font color="#999999">usb.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476416989538" ID="ID_267677640" MODIFIED="1477477586491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanProbe</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476417211338" ID="ID_1929675884" MODIFIED="1477477586491" TEXT="glBusInit">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &lt;1&gt; Initialize the IO port of the interface
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417247972" ID="ID_1280666140" MODIFIED="1477477586492">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanNetCreate</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &lt;2&gt; Create network device, Adapter, KalInfo, prDevHandler(netdev)
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417306533" FOLDED="true" ID="ID_1427603346" MODIFIED="1478250245442" TEXT="Set the ioaddr to HIF Info">
<node COLOR="#111111" CREATED="1476417308886" ID="ID_403063242" MODIFIED="1477477586492">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /* 4 &lt;2.5&gt; Set the ioaddr to HIF Info */
    </p>
    <p>
      prGlueInfo = (P_GLUE_INFO_T) wiphy_priv(prWdev-&gt;wiphy);
    </p>
    <p>
      gPrDev = prGlueInfo-&gt;prDevHandler;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476417381384" ID="ID_1469202722" LINK="#ID_1359664305" MODIFIED="1477647065648" TEXT="glBusSetIrq">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Setup IRQ
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417473051" ID="ID_1654277280" MODIFIED="1479713618418" TEXT="nicpmWakeUpWiFi">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Trigger the action of switching Pwr state to drv_own
    </p>
    <p>
      prAdapter-&gt;fgIsFwOwn = TRUE --&gt; prAdapter-&gt;fgIsFwOwn = FALSE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417517933" ID="ID_1755090457" MODIFIED="1477477586492" TEXT="glLoadNvram">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      initialize
    </p>
    <p>
      P_REG_INFO_T prRegInfo;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417553206" ID="ID_1610062516" MODIFIED="1477477586492">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanAdapterStart
    </p>
    <p>
      <b><font color="#999999">wlan_lib.c</font></b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      init adapter
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476697193126" ID="ID_347185733" MODIFIED="1477477586492" TEXT="&#x521d;&#x59cb;&#x5316;&#x76f8;&#x5173;&#x961f;&#x5217;">
<icon BUILTIN="full-1"/>
<node COLOR="#111111" CREATED="1476697270233" ID="ID_954325862" MODIFIED="1477477586492" TEXT="rPendingCmdQueue"/>
<node COLOR="#111111" CREATED="1476697282041" ID="ID_1232703709" MODIFIED="1477477586492" TEXT="rTxCmdQueue"/>
<node COLOR="#111111" CREATED="1476697288835" ID="ID_1261094290" MODIFIED="1477477586493" TEXT="rTxCmdDoneQueue"/>
<node COLOR="#111111" CREATED="1476697294474" ID="ID_1001539944" MODIFIED="1477477586493" TEXT="rTxP0Queue"/>
<node COLOR="#111111" CREATED="1476697299234" ID="ID_439519226" MODIFIED="1477477586493" TEXT="rTxP1Queue"/>
<node COLOR="#111111" CREATED="1476697308898" ID="ID_148509828" MODIFIED="1477477586493" TEXT="rTxPQueue">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      for (i = 0; i &lt; TX_PORT_NUM; i++)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;QUEUE_INITIALIZE(&amp;prAdapter-&gt;rTxPQueue[i]);
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476697335092" ID="ID_492671789" MODIFIED="1477477586493" TEXT="rRxQueue"/>
<node COLOR="#111111" CREATED="1476697342627" ID="ID_1188326741" MODIFIED="1477477586493" TEXT="rTxDataDoneQueue"/>
</node>
<node COLOR="#111111" CREATED="1476698228177" ID="ID_251787514" MODIFIED="1477477586493">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22522;&#30784;&#35774;&#26045;&#21021;&#22987;&#21270;
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-2"/>
<node COLOR="#111111" CREATED="1476697435383" ID="ID_859212287" MODIFIED="1477477586493" TEXT="nicInitializeAdapter">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize the Adapter
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476697448720" ID="ID_221522881" MODIFIED="1477477586493" TEXT="nicInitSystemService">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize System Service (MGMT Memory pool and STA_REC)
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476698969078" FOLDED="true" ID="ID_1275113185" MODIFIED="1477477586493">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cnmMemInit</b>
    </p>
    <p>
      <font color="#999999">cnm_mem.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This function is used to initial the MGMT/MSG memory pool.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476952677776" ID="ID_1204769651" MODIFIED="1477477586493">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Management buffer pool
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476952750504" ID="ID_867131635" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /* Initialize Management buffer pool */
    </p>
    <p>
      prBufInfo = &amp;prAdapter-&gt;rMgtBufInfo;
    </p>
    <p>
      kalMemZero(prBufInfo, sizeof(prAdapter-&gt;rMgtBufInfo));
    </p>
    <p>
      prBufInfo-&gt;pucBuf = prAdapter-&gt;pucMgtBufCached;
    </p>
    <p>
      
    </p>
    <p>
      /* Setup available memory blocks. 1 indicates FREE */
    </p>
    <p>
      prBufInfo-&gt;rFreeBlocksBitmap = (BUF_BITMAP) BITS(0, MAX_NUM_OF_BUF_BLOCKS - 1);
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476952682350" ID="ID_1701882237" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Message buffer pool
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476952823114" ID="ID_164532953" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /* Initialize Message buffer pool */
    </p>
    <p>
      prBufInfo = &amp;prAdapter-&gt;rMsgBufInfo;
    </p>
    <p>
      kalMemZero(prBufInfo, sizeof(prAdapter-&gt;rMsgBufInfo));
    </p>
    <p>
      prBufInfo-&gt;pucBuf = &amp;prAdapter-&gt;aucMsgBuf[0];
    </p>
    <p>
      
    </p>
    <p>
      /* Setup available memory blocks. 1 indicates FREE */
    </p>
    <p>
      prBufInfo-&gt;rFreeBlocksBitmap = (BUF_BITMAP) BITS(0, MAX_NUM_OF_BUF_BLOCKS - 1);
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476698976966" ID="ID_766971291" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmStaRecInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize STA Record.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698984014" ID="ID_1555041432" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cmdBufInitialize
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This function is used to initial the MGMT memory pool for CMD Packet.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476953071764" ID="ID_304242022" MODIFIED="1477477586494" TEXT="Tx CMD List">
<node COLOR="#111111" CREATED="1476953122541" ID="ID_1526654098" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rFreeCmdList
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476953128222" ID="ID_1747892283" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Hif Cmd
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476953158815" ID="ID_497254668" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;arHifCmdDesc[i]
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476953170519" ID="ID_761569631" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      attach to prAdapter-&gt;rFreeCmdList
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476698990030" ID="ID_1007772870" LINK="#ID_992150334" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>mboxInitialize </b>
    </p>
    <p>
      <font color="#999999">hem_mbox.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Initialization
    </p>
    <p>
      Inter Component Communication
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476699005431" ID="ID_30928245" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmTimerInitialize
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This routines is called to initialize a root timer.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476953273938" ID="ID_1661580564" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rRootTimer
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476697512825" ID="ID_234952414" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanInitFeatureOption
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Feature Options
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476697548571" ID="ID_1505068549" MODIFIED="1477477586495" TEXT="wlanCfgSetDebugLevel">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Overwrite debug level settings
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476697562499" ID="ID_1198440020" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxInitialize
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_1636214302" ENDARROW="Default" ENDINCLINATION="45;0;" ID="Arrow_ID_1270930188" STARTARROW="None" STARTINCLINATION="45;0;"/>
<icon BUILTIN="full-3"/>
</node>
<node COLOR="#111111" CREATED="1476697593284" ID="ID_1636214302" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanDefTxPowerCfg
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1636214302" ENDARROW="Default" ENDINCLINATION="45;0;" ID="Arrow_ID_1270930188" SOURCE="ID_1198440020" STARTARROW="None" STARTINCLINATION="45;0;"/>
</node>
<node COLOR="#111111" CREATED="1476697629998" ID="ID_699115737" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxInitialize
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Rx
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-4"/>
</node>
<node COLOR="#111111" CREATED="1476697651679" ID="ID_1159233067" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halHifSwInfoInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HIF SW info initialize
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-5"/>
</node>
<node COLOR="#111111" CREATED="1476697673639" ID="ID_764669415" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_ENABLE_FWDL
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Enable HIF cut-through to N9 mode, not visiting CR4
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-6"/>
</node>
<node COLOR="#111111" CREATED="1476697706177" ID="ID_1068859892" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSetChipEcoInfo
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Get ECO Version
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-7"/>
</node>
<node COLOR="#111111" CREATED="1476697724257" ID="ID_511483863" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FW/patch download
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-8"/>
<node COLOR="#111111" CREATED="1476697733721" ID="ID_1736937884" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicDisableInterrupt
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      disable interrupt, download is done by polling mode only
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-1"/>
</node>
<node COLOR="#111111" CREATED="1476697753602" ID="ID_1302411301" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxInitResetResource
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Tx Resource to fw download state
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-2"/>
</node>
<node COLOR="#111111" CREATED="1476697788348" ID="ID_1659241485" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanDownloadFW
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-3"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476698035948" ID="ID_1341094285" MODIFIED="1477477586496" TEXT="wlanCheckWifiFunc">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      check Wi-Fi FW asserts ready bit
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-9"/>
<node COLOR="#111111" CREATED="1476698524926" ID="ID_1459726847" MODIFIED="1477477586496" TEXT="wlanQueryNicResourceInformation"/>
<node COLOR="#111111" CREATED="1476698568223" ID="ID_83799896" MODIFIED="1477477586496" TEXT="NIC Capability"/>
<node COLOR="#111111" CREATED="1476698597353" ID="ID_249368489" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanUpdateBasicConfig
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      update basic configuration
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698617058" ID="ID_192010506" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanUpdateNetworkAddress
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Override network address
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698647234" ID="ID_1034773502" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicApplyNetworkAddress
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Apply Network Address
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698671811" ID="ID_38401754" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIndicateStatusAndComplete
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      indicate disconnection as default status
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698871418" ID="ID_1605530437" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicInitMGMT
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MGMT Initialization
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477292210277" ID="ID_1417113232" MODIFIED="1477477586497" TEXT="cnmInit">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;CNM Module - initialization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292222861" ID="ID_139601233" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rlmFsmEventInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RLM Module - initialization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292275776" ID="ID_1372480492" LINK="#ID_657070274" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCN Module - initialization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292288536" ID="ID_1255259297" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS Module - intiailization
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_444355911" ENDARROW="Default" ENDINCLINATION="94;0;" ID="Arrow_ID_58358806" STARTARROW="None" STARTINCLINATION="94;0;"/>
</node>
<node COLOR="#111111" CREATED="1477292337890" ID="ID_444355911" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisInitializeConnectionSettings
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_444355911" ENDARROW="Default" ENDINCLINATION="94;0;" ID="Arrow_ID_58358806" SOURCE="ID_1255259297" STARTARROW="None" STARTINCLINATION="94;0;"/>
</node>
<node COLOR="#111111" CREATED="1477292351458" ID="ID_695275792" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      roamingFsmInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Roaming Module - intiailization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292396332" ID="ID_1848459893" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      swCrDebugInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Cr Debug Control
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476698892195" ID="ID_960603798" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicSetAvailablePhyTypeSet
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      configure available PHY type set
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698931276" ID="ID_838093706" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmInitDbdcSetting
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476417599680" ID="ID_1687543321" MODIFIED="1477477586498">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27880;&#20876;&#24037;&#20316;&#32447;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476417614800" ID="ID_1917647084" MODIFIED="1477477586498">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalFreeTxMsduWorker
    </p>
    <p>
      <font color="#999999">gl_kal.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476417639802" ID="ID_83269288" MODIFIED="1477477586498" TEXT="prGlueInfo-&gt;rTxMsduFreeWork"/>
</node>
<node COLOR="#111111" CREATED="1476417622025" ID="ID_1492323085" MODIFIED="1477477586498">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halDeAggRxPktWorker
    </p>
    <p>
      <font color="#999999">hal_api.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476417652242" ID="ID_1755700096" MODIFIED="1477477586498" TEXT="prGlueInfo-&gt;rRxPktDeAggWork"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476422690264" ID="ID_860214176" MODIFIED="1477477586498" TEXT="&#x542f;&#x52a8;&#x6838;&#x5fc3;&#x7ebf;&#x7a0b;">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476422700176" ID="ID_1892295768" MODIFIED="1477477586498" TEXT="main_thread"/>
<node COLOR="#111111" CREATED="1476422718825" ID="ID_177512059" MODIFIED="1477477586498" TEXT="hif_thread"/>
<node COLOR="#111111" CREATED="1476422721193" ID="ID_829943756" MODIFIED="1477477586498" TEXT="rx_thread"/>
</node>
<node COLOR="#111111" CREATED="1476422759906" ID="ID_568514442" MODIFIED="1477477586498" TEXT="wlanDownloadBufferBin">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      this function send buffer bin EEPROB_MTxxxx.bin to FW.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476422865510" ID="ID_1260977535" MODIFIED="1477477586498" TEXT="set mac addr">
<node COLOR="#111111" CREATED="1476422878543" ID="ID_1649714784" MODIFIED="1477477586499" TEXT="wlanoidQueryCurrentAddr"/>
</node>
<node COLOR="#111111" CREATED="1476422892007" ID="ID_1756992232" MODIFIED="1477477586499" TEXT="set HW checksum offload">
<node COLOR="#111111" CREATED="1476422894568" ID="ID_1113714161" MODIFIED="1477477586499" TEXT="wlanoidSetCSUMOffload"/>
</node>
<node COLOR="#111111" CREATED="1476422904991" ID="ID_946846497" MODIFIED="1477477586499">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanNetRegister</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register the card
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423075125" ID="ID_1152436874" MODIFIED="1477477586499" TEXT="glRegisterEarlySuspend">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register early suspend callback
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423048709" ID="ID_894165059" MODIFIED="1477477586499" TEXT="wlanRegisterNotifier">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register Notifier callback
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423146528" ID="ID_1057391773" MODIFIED="1477477586499">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>procCreateFsEntry</b>
    </p>
    <p>
      <font color="#999999">gl_proc.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize /proc filesystem
    </p>
    <p>
      create items under directory /proc/net/wlan0/
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423107270" ID="ID_1149342078" MODIFIED="1477477586499">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalMetInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support packet trace using met
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#ff3333" DESTINATION="ID_445354275" ENDARROW="Default" ENDINCLINATION="211;0;" ID="Arrow_ID_1081692357" STARTARROW="None" STARTINCLINATION="211;0;"/>
</node>
<node COLOR="#111111" CREATED="1476423341367" ID="ID_1735719364" MODIFIED="1477477586499" TEXT="glRegisterAmpc">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support Bt Over Wifi
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423431842" ID="ID_718547361" LINK="#ID_343414894" MODIFIED="1478251495391" TEXT="register_set_p2p_mode_handler">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      register p2p mode handler
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" CREATED="1476423578256" ID="ID_288292819" MODIFIED="1477477586500" TEXT="kalIndicateAgpsNotify">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      CFG_SUPPORT_AGPS_ASSIST
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423623033" ID="ID_1229329642" MODIFIED="1477477586500">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanFeatureToFw</b>
    </p>
    <p>
      <font color="#999999">wlan_lib.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This function is to send WLAN feature options to firmware
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423694939" ID="ID_576687482" MODIFIED="1477477586500" TEXT="chip config set">
<node COLOR="#111111" CREATED="1476423699908" ID="ID_1111808765" MODIFIED="1477477586500" TEXT="wlanCfgSetSwCtrl"/>
<node COLOR="#111111" CREATED="1476423707100" ID="ID_1536729572" MODIFIED="1477477586500" TEXT="wlanCfgSetChip"/>
<node COLOR="#111111" CREATED="1476423712372" ID="ID_764313250" MODIFIED="1477477586500" TEXT="wlanCfgSetCountryCode"/>
</node>
<node COLOR="#111111" CREATED="1476423776454" ID="ID_445354275" MODIFIED="1477477586500" TEXT="kalMetInitProcfs">
<arrowlink COLOR="#ff3333" DESTINATION="ID_76164815" ENDARROW="Default" ENDINCLINATION="30;0;" ID="Arrow_ID_875522902" STARTARROW="None" STARTINCLINATION="30;0;"/>
<linktarget COLOR="#ff3333" DESTINATION="ID_445354275" ENDARROW="Default" ENDINCLINATION="211;0;" ID="Arrow_ID_1081692357" SOURCE="ID_1149342078" STARTARROW="None" STARTINCLINATION="211;0;"/>
</node>
<node COLOR="#111111" CREATED="1476423848161" ID="ID_76164815" MODIFIED="1477477586500" TEXT="met_tag_init">
<linktarget COLOR="#ff3333" DESTINATION="ID_76164815" ENDARROW="Default" ENDINCLINATION="30;0;" ID="Arrow_ID_875522902" SOURCE="ID_445354275" STARTARROW="None" STARTINCLINATION="30;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476416990970" ID="ID_1025052093" MODIFIED="1477477586501" TEXT="wlanRemove"/>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1478250384439" FOLDED="true" ID="ID_1897170829" MODIFIED="1478608814396" TEXT="P2P">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1478250398623" ID="ID_1419684146" MODIFIED="1478250410517" TEXT="&#x6a21;&#x5757;&#x521d;&#x59cb;&#x5316;">
<node COLOR="#111111" CREATED="1476423431842" ID="ID_343414894" MODIFIED="1478251506761" TEXT="register_set_p2p_mode_handler">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476423450603" ID="ID_1653732722" MODIFIED="1477477586500" TEXT="set_p2p_mode_handler">
<node COLOR="#111111" CREATED="1478251637336" ID="ID_851851524" MODIFIED="1478251646112">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetP2pMode
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478251753168" ID="ID_81523817" MODIFIED="1478251755328">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pSetMode
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478251755840" ID="ID_680975070" MODIFIED="1478251763785">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pLaunch
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478251795753" ID="ID_865660206" MODIFIED="1478251812479">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glRegisterP2P
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register for cfg80211 for Wi-Fi Direct
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1478251974680" ID="ID_417762647" MODIFIED="1478251978077" TEXT="AP Mode">
<node COLOR="#111111" CREATED="1478251979319" ID="ID_896134631" MODIFIED="1478251985399">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glP2pCreateWirelessDevice
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476423468260" ID="ID_1824222508" LINK="#ID_832323817" MODIFIED="1478250507827">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>p2pNetRegister</b>
    </p>
    <p>
      <font color="#999999">gl_p2p.c</font>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478517890931" ID="ID_86058469" MODIFIED="1478517903596">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p_netdev_ops
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478517905611" ID="ID_823974614" MODIFIED="1478517967348">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_open
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518064880" ID="ID_23677537" MODIFIED="1478518066984">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pOpen
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478517914611" ID="ID_17229058" MODIFIED="1478517980901">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_stop
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518068840" ID="ID_1544808123" MODIFIED="1478518075047">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pStop
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478517922195" ID="ID_1827733909" MODIFIED="1478517993644">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_set_mac_address
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518077057" ID="ID_83582327" MODIFIED="1478518082575">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pSetMACAddress
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478517940803" ID="ID_714661146" MODIFIED="1478518007916">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_set_rx_mode
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518084017" ID="ID_489601002" MODIFIED="1478518089487">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pSetMulticastList
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518008855" ID="ID_127827695" MODIFIED="1478518015289">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_get_stats
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518090953" ID="ID_1109049600" MODIFIED="1478518097096">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pGetStats
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518016023" ID="ID_1133793907" MODIFIED="1478518022549">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_do_ioctl
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518098618" ID="ID_1109832922" MODIFIED="1478518104239">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pDoIOCTL
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518023071" ID="ID_264051546" MODIFIED="1478518029957">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_start_xmit
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518105529" ID="ID_515434686" MODIFIED="1478518146735">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pHardStartXmit
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#111111" CREATED="1478518030559" ID="ID_584981575" MODIFIED="1478518036341">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_select_queue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518117290" ID="ID_1658058633" MODIFIED="1478590330796">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSelectQueue
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      select the tx queue for current packet
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518036831" ID="ID_1475311599" MODIFIED="1478518043126">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_init
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518124866" ID="ID_613642086" MODIFIED="1478518126970">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pInit
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518051831" ID="ID_180543259" MODIFIED="1478518057904">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_uninit
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518128387" ID="ID_498129524" MODIFIED="1478518134129">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pUninit
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478250517475" ID="ID_478695041" MODIFIED="1478250526961" TEXT="&#x5e38;&#x89c1;&#x7684;&#x4e00;&#x4e9b;&#x4fe1;&#x606f;">
<node COLOR="#111111" CREATED="1478250528068" ID="ID_196902979" MODIFIED="1478250553003">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P2P&#20840;&#23616;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478250575278" ID="ID_1949353669" MODIFIED="1478250591289">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      1.&#160;prGlueInfo-&gt;prAdapter-&gt;<b>rP2PNetRegState</b>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478250636911" ID="ID_1614655518" MODIFIED="1478250748669">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      2. prGlueInfo-&gt;prP2PInfo[0]-&gt;<b>prDevHandler</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478250653784" ID="ID_1849229208" MODIFIED="1478250673011">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      only first p2p have this devhandler
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478250761436" ID="ID_1523363705" MODIFIED="1478250774875">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      array: gPrP2pDev
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478597113742" ID="ID_1827615105" MODIFIED="1478597120797" TEXT="FSM">
<node COLOR="#111111" CREATED="1478597121838" ID="ID_1132188160" MODIFIED="1478597132250">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P2P Dev FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478597155150" ID="ID_1463140404" MODIFIED="1478597169575">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.prP2pDevFsmInfo --&gt; P_P2P_DEV_FSM_INFO_T
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478597133062" ID="ID_1295590292" MODIFIED="1478597138765">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P2P Role FSM
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1478249000541" ID="ID_1132934865" MODIFIED="1478249007110">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20869;&#23384;&#31649;&#29702;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1479713652657" ID="ID_1480646121" MODIFIED="1479713663697" TEXT="communication path">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1479713666105" ID="ID_1047064150" MODIFIED="1479713670007" TEXT="control path">
<node COLOR="#111111" CREATED="1479716510591" ID="ID_486355226" MODIFIED="1479717169027">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cfg80211_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">mtk_p2p_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717275911" ID="ID_1193451546" MODIFIED="1479717279966" TEXT="p2p0"/>
<node COLOR="#111111" CREATED="1479717280976" ID="ID_882374824" MODIFIED="1479717282630" TEXT="ap0"/>
</node>
<node COLOR="#111111" CREATED="1479716759292" ID="ID_218382416" MODIFIED="1479717194565">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cfg80211_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">mtk_wlan_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717285304" ID="ID_1913751672" MODIFIED="1479717288053" TEXT="wlan0"/>
</node>
</node>
<node COLOR="#111111" CREATED="1479713670553" ID="ID_735877256" MODIFIED="1479713672959" TEXT="data path">
<node COLOR="#111111" CREATED="1479713687161" ID="ID_128861795" MODIFIED="1479717235956">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct net_device_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">wlan_netdev_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717294783" ID="ID_995363075" MODIFIED="1479717297830" TEXT="wlan0"/>
</node>
<node COLOR="#111111" CREATED="1479713690625" ID="ID_1609941262" MODIFIED="1479717265642">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct net_device_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">p2p_netdev_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717304536" ID="ID_1398572849" MODIFIED="1479717307589" TEXT="p2p0"/>
<node COLOR="#111111" CREATED="1479717308048" ID="ID_1869597694" MODIFIED="1479717310069" TEXT="ap0"/>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1480588887053" ID="ID_159944655" MODIFIED="1480588894818" TEXT="&#x8fde;&#x63a5;AP&#x7684;&#x6d41;&#x7a0b;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1480588895852" ID="ID_796282843" MODIFIED="1480588900470">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mtk_cfg80211_connect
    </p>
  </body>
</html>
</richcontent>
<node COLOR="#111111" CREATED="1480589062637" ID="ID_476434965" MODIFIED="1480589064755">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetInfrastructureMode
    </p>
  </body>
</html>
</richcontent>
</node>
<node COLOR="#111111" CREATED="1480589065234" ID="ID_1857379278" MODIFIED="1480589097963">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetAuthMode
    </p>
  </body>
</html>
</richcontent>
</node>
<node COLOR="#111111" CREATED="1480589098851" ID="ID_1037202621" MODIFIED="1480589110418">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetEncryptionStatus
    </p>
  </body>
</html>
</richcontent>
</node>
<node COLOR="#111111" CREATED="1480589110835" ID="ID_424439526" MODIFIED="1480589136065">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetConnect
    </p>
  </body>
</html>
</richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1480592151569" ID="ID_795076073" LINK="#ID_1468307456" MODIFIED="1480592370010">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_OID_AIS_FSM_JOIN_REQ
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869459380" ID="ID_45824846" MODIFIED="1477477586506" TEXT="iw&#x6e90;&#x7801;&#x5206;&#x6790;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" CREATED="1474869234260" FOLDED="true" ID="ID_800856779" MODIFIED="1477636712974" POSITION="right" TEXT="&#x57fa;&#x7840;&#x7406;&#x8bba;&#x90e8;&#x5206;">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" CREATED="1474869311401" ID="ID_1282649042" MODIFIED="1477477586509" TEXT="&#x65e0;&#x7ebf;&#x6743;&#x5a01;&#x6307;&#x5357;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<icon BUILTIN="button_ok"/>
</node>
<node COLOR="#00b439" CREATED="1474869289572" ID="ID_1890748931" MODIFIED="1477477586510" TEXT="CWNA">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<icon BUILTIN="button_ok"/>
</node>
<node COLOR="#00b439" CREATED="1474869338484" ID="ID_1742793932" MODIFIED="1477477586510" TEXT="CWAP">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869349739" ID="ID_154055323" MODIFIED="1477477586510" TEXT="CWSP">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869358793" ID="ID_548821793" MODIFIED="1477477586513" TEXT="&#x6570;&#x636e;&#x901a;&#x4fe1;&#x4e0e;&#x7f51;&#x7edc;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869557131" ID="ID_1733880194" MODIFIED="1477477586517" TEXT="&#x6df1;&#x5165;&#x7406;&#x89e3;Android&#xff1a;Wi-Fi&#x3001;NFC&#x548c;GPS&#x5377;&#x9605;&#x8bfb;&#x8ba1;&#x5212;  ">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1476424139044" ID="ID_472615066" MODIFIED="1477477586518" TEXT="Netd">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476425820634" ID="ID_847005000" MODIFIED="1477477586518" TEXT="&#x91cd;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1476425830016" ID="ID_14922198" MODIFIED="1477477586519">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font color="#0000ff">CommandListener</font></b>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#3333ff" DESTINATION="ID_14922198" ENDARROW="Default" ENDINCLINATION="-547;0;" ID="Arrow_ID_974328704" SOURCE="ID_1044616497" STARTARROW="None" STARTINCLINATION="-32;1;"/>
</node>
<node COLOR="#111111" CREATED="1476425852041" ID="ID_1070680332" MODIFIED="1477477586520">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#ff0033"><b>NetlinkManager</b></font>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#ff3333" DESTINATION="ID_1070680332" ENDARROW="Default" ENDINCLINATION="-68;14;" ID="Arrow_ID_1933587597" SOURCE="ID_1259682212" STARTARROW="None" STARTINCLINATION="-168;14;"/>
</node>
<node COLOR="#111111" CREATED="1476425868794" ID="ID_1456582559" MODIFIED="1477477586521">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#00ff00"><b>DnsProxyListener</b></font>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#33ff00" DESTINATION="ID_1456582559" ENDARROW="Default" ENDINCLINATION="-15;12;" ID="Arrow_ID_1468996679" SOURCE="ID_701075544" STARTARROW="None" STARTINCLINATION="-339;40;"/>
</node>
<node COLOR="#111111" CREATED="1476425875322" ID="ID_760140278" MODIFIED="1477477586521">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font color="#999900">FwmarkServer</font></b>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#666600" DESTINATION="ID_760140278" ENDARROW="Default" ENDINCLINATION="-11;25;" ID="Arrow_ID_1665500152" SOURCE="ID_1162899669" STARTARROW="None" STARTINCLINATION="-192;63;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476425800583" ID="ID_20267605" MODIFIED="1477477586522" TEXT="&#x6e90;&#x7801;&#x5206;&#x6790;">
<node COLOR="#111111" CREATED="1476425890330" ID="ID_1067223112" MODIFIED="1477477586522" TEXT="&#x5165;&#x53e3;&#x51fd;&#x6570;main()">
<node COLOR="#111111" CREATED="1476425902994" ID="ID_1259682212" MODIFIED="1477477586522">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#ff0033">&#21551;&#21160;NetlinkManager</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#ff3333" DESTINATION="ID_1070680332" ENDARROW="Default" ENDINCLINATION="-68;14;" ID="Arrow_ID_1933587597" STARTARROW="None" STARTINCLINATION="-168;14;"/>
<icon BUILTIN="full-1"/>
</node>
<node COLOR="#111111" CREATED="1476426005134" ID="ID_1044616497" MODIFIED="1477477586523">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#0000ff">&#21019;&#24314;&quot;netd&quot;&#30417;&#21548;Socket</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#3333ff" DESTINATION="ID_14922198" ENDARROW="Default" ENDINCLINATION="-547;0;" ID="Arrow_ID_974328704" STARTARROW="None" STARTINCLINATION="-32;1;"/>
<icon BUILTIN="full-2"/>
</node>
<node COLOR="#111111" CREATED="1476426061032" ID="ID_701075544" MODIFIED="1477477586524">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#00ff00">&#21019;&#24314;&quot;dnsproxyd&quot;&#30417;&#21548;Socket</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#33ff00" DESTINATION="ID_1456582559" ENDARROW="Default" ENDINCLINATION="-15;12;" ID="Arrow_ID_1468996679" STARTARROW="None" STARTINCLINATION="-339;40;"/>
<icon BUILTIN="full-3"/>
</node>
<node COLOR="#111111" CREATED="1476426290568" ID="ID_1162899669" MODIFIED="1477477586525">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#999900">&#21019;&#24314;&quot;fwmarkd&quot; &#30417;&#21548;Socket</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#666600" DESTINATION="ID_760140278" ENDARROW="Default" ENDINCLINATION="-11;25;" ID="Arrow_ID_1665500152" STARTARROW="None" STARTINCLINATION="-192;63;"/>
<icon BUILTIN="full-4"/>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#00b439" CREATED="1474944064418" ID="ID_387179263" MODIFIED="1477477586526" TEXT="802.11&#x534f;&#x8bae;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474944072676" ID="ID_832047714" MODIFIED="1477477586526" TEXT="802.11n">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1474947376635" ID="ID_815124379" MODIFIED="1477477586526" TEXT="&#x7269;&#x7406;&#x5c42;&#x7684;&#x6539;&#x8fdb;">
<node COLOR="#111111" CREATED="1474944079365" ID="ID_717696542" MODIFIED="1477477586526" TEXT="MIMO">
<node COLOR="#111111" CREATED="1474944093949" ID="ID_1247657002" MODIFIED="1477477586526" TEXT="TxBF">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#24403;&#20256;&#36755;&#26041;&#25317;&#26377;&#30340;&#22825;&#32447;&#25968;&#27604;&#25509;&#25910;&#26041;&#22810;&#26102;&#65292;
    </p>
    <p>
      &#21487;&#20197;&#29992;&#22810; &#20313;&#30340;&#22825;&#32447;&#36827;&#34892;&#32858;&#38598;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1474944097102" ID="ID_674180272" MODIFIED="1477477586526" TEXT="MRC">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#24403;&#20256;&#36755;&#26041;&#25317;&#26377;&#30340;&#22825;&#32447;&#25968;&#27604;&#25509;&#25910;&#26041;&#23569;&#26102;&#65292;
    </p>
    <p>
      &#25509;&#25910;&#26041;&#22810;&#20313;&#30340;&#22825;&#32447;&#21487;&#21033;&#29992;&#36215;&#26469;&#26356;&#22909;&#30340;&#25509;&#25910;&#20449;&#21495;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1474947397196" ID="ID_431228921" MODIFIED="1477477586527" TEXT="MAC&#x5c42;&#x7684;&#x6539;&#x8fdb;">
<node COLOR="#111111" CREATED="1474947406540" ID="ID_193088071" MODIFIED="1477477586527" TEXT="TxOP"/>
<node COLOR="#111111" CREATED="1474945254862" ID="ID_1329506623" MODIFIED="1477477586527" TEXT="&#x5e27;&#x805a;&#x5408;">
<node COLOR="#111111" CREATED="1474945269607" ID="ID_1921327568" MODIFIED="1477477586527" TEXT="A-MSDU"/>
<node COLOR="#111111" CREATED="1474945274479" ID="ID_604253040" MODIFIED="1477477586527" TEXT="A-MPDU"/>
</node>
</node>
</node>
</node>
</node>
</node>
</map><map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node COLOR="#000000" CREATED="1474869042230" ID="ID_9369228" MODIFIED="1477477586527">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#24037;&#20316;&#25216;&#33021;&#20462;&#28860;
    </p>
    <p>
      &#65288;2016~&#160;&#160;&#65289;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="20"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties"/>
<node COLOR="#0033ff" CREATED="1474869229849" ID="ID_429611080" MODIFIED="1477477586366" POSITION="right" TEXT="&#x5b9e;&#x8df5;&#x90e8;&#x5206;">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" CREATED="1474869422572" FOLDED="true" ID="ID_1699726114" MODIFIED="1477636686957" TEXT="wpa_supplicant">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869647029" ID="ID_295121931" MODIFIED="1477477586368" TEXT="wpa/wpa2&#x72b6;&#x6001;&#x673a;&#x4ee3;&#x7801;&#x7814;&#x7a76;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1474869661597" ID="ID_748924271" MODIFIED="1477477586404" TEXT="EAP&#x6846;&#x67b6;"/>
<node COLOR="#111111" CREATED="1474869671203" ID="ID_1430625748" MODIFIED="1477477586404" TEXT="EAPOL&#x72b6;&#x6001;&#x673a;&#x6846;&#x67b6;"/>
<node COLOR="#111111" CREATED="1474869681604" ID="ID_95119704" MODIFIED="1477477586404" TEXT="WPS&#x72b6;&#x6001;&#x673a;"/>
</node>
<node COLOR="#990000" CREATED="1474869703397" ID="ID_1571133533" MODIFIED="1477477586404" TEXT="wpa_supplicant&#x5168;&#x5c40;&#x72b6;&#x6001;&#x673a;&#x7814;&#x7a76;">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869430952" FOLDED="true" ID="ID_1927977658" MODIFIED="1477636689047" TEXT="mac80211">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869622475" FOLDED="true" ID="ID_912733262" MODIFIED="1477477586409" TEXT="mac80211_hwsim&#x6e90;&#x7801;&#x5206;&#x6790;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476412277962" ID="ID_1065456441" MODIFIED="1477477586412" TEXT="&#x4e3b;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1476413044373" ID="ID_1058027468" MODIFIED="1477477586412" TEXT="struct mac80211_hwsim_data">
<linktarget COLOR="#ff3333" DESTINATION="ID_1058027468" ENDARROW="Default" ENDINCLINATION="-214;-230;" ID="Arrow_ID_452271799" SOURCE="ID_643930094" STARTARROW="None" STARTINCLINATION="102;-88;"/>
<node COLOR="#111111" CREATED="1476413054677" ID="ID_250182291" MODIFIED="1477477586412">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hw
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_hw *hw;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476415402185" ID="ID_1844829092" MODIFIED="1477477586412" TEXT="struct ieee80211_hw">
<node COLOR="#111111" CREATED="1476415484548" ID="ID_643930094" MODIFIED="1477477586412" TEXT="void *priv">
<arrowlink COLOR="#ff3333" DESTINATION="ID_1058027468" ENDARROW="Default" ENDINCLINATION="-214;-230;" ID="Arrow_ID_452271799" STARTARROW="None" STARTINCLINATION="102;-88;"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476413095695" ID="ID_917629506" MODIFIED="1477477586412">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bands
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_supported_band bands[IEEE80211_NUM_BANDS];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476413114759" ID="ID_1533289128" MODIFIED="1477477586412" TEXT="channels_2ghz">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_channel channels_2ghz[ARRAY_SIZE(hwsim_channels_2ghz)];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476413097343" ID="ID_1577824164" MODIFIED="1477477586412">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      channels_5ghz
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_channel channels_5ghz[ARRAY_SIZE(hwsim_channels_5ghz)];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476413343296" ID="ID_1397592854" MODIFIED="1477477586413">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rates
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_rate rates[ARRAY_SIZE(hwsim_rates)];
    </p>
    <p>
      bitrate definition&#160;&#160;that an 802.11 PHY can operate with.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414241848" ID="ID_963803637" MODIFIED="1477477586413" TEXT="if_combination">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_iface_combination if_combination;
    </p>
    <p>
      possible interface combination
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414280865" ID="ID_1459302242" MODIFIED="1477477586413" TEXT="addresses">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mac address
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414304938" ID="ID_1447085398" MODIFIED="1477477586413" TEXT="regd">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const struct ieee80211_regdomain *regd;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414347828" ID="ID_1593356246" MODIFIED="1477477586413" TEXT="hw_scan_request">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct cfg80211_scan_request *hw_scan_request;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414362828" ID="ID_60716343" MODIFIED="1477477586413" TEXT="hw_scan_vif">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_vif *hw_scan_vif;
    </p>
    <p>
      per-interface data
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414443540" ID="ID_1665774938" MODIFIED="1477477586413" TEXT="channel">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_channel *channel;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414470929" ID="ID_998036270" MODIFIED="1477477586413" TEXT="rx_filter"/>
<node COLOR="#111111" CREATED="1476415620052" ID="ID_611421707" MODIFIED="1477477586413" TEXT="pending">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct sk_buff_head pending; /* packets pending */
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#3333ff" DESTINATION="ID_222075092" ENDARROW="Default" ENDINCLINATION="707;0;" ID="Arrow_ID_853178117" STARTARROW="None" STARTINCLINATION="707;0;"/>
</node>
<node COLOR="#111111" CREATED="1476414515074" ID="ID_1519967614" MODIFIED="1477477586413" TEXT="Stats">
<node COLOR="#111111" CREATED="1476414527363" ID="ID_144152733" MODIFIED="1477477586414" TEXT="tx_pkts"/>
<node COLOR="#111111" CREATED="1476414539011" ID="ID_1052431136" MODIFIED="1477477586414" TEXT="rx_pkts"/>
<node COLOR="#111111" CREATED="1476414547651" ID="ID_892018179" MODIFIED="1477477586414" TEXT="tx_bytes"/>
<node COLOR="#111111" CREATED="1476414554547" ID="ID_1915509624" MODIFIED="1477477586414" TEXT="rx_bytes"/>
<node COLOR="#111111" CREATED="1476414561043" ID="ID_1206183439" MODIFIED="1477477586414" TEXT="tx_dropped"/>
<node COLOR="#111111" CREATED="1476414567003" ID="ID_1733191458" MODIFIED="1477477586414" TEXT="tx_failed"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476414751866" ID="ID_790351648" MODIFIED="1477477586414" TEXT="struct hwsim_new_radio_params ">
<node COLOR="#111111" CREATED="1476414777170" ID="ID_1764052366" MODIFIED="1477477586414" TEXT="channels"/>
<node COLOR="#111111" CREATED="1476414783019" ID="ID_1493793144" MODIFIED="1477477586414" TEXT="reg_alpha2"/>
<node COLOR="#111111" CREATED="1476414789347" ID="ID_1509155196" MODIFIED="1477477586415" TEXT="regd">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const struct ieee80211_regdomain *regd;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414814828" ID="ID_86536830" MODIFIED="1477477586415" TEXT="reg_strict"/>
<node COLOR="#111111" CREATED="1476414816188" ID="ID_1955591649" MODIFIED="1477477586415" TEXT="p2p_device">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support p2p device ?
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414823780" ID="ID_1041874000" MODIFIED="1477477586415" TEXT="use_chanctx">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      use multi-channel ?
    </p>
    <p>
      used with the HWSIM_CMD_CREATE_RADIO
    </p>
    <p>
      command to force use of channel contexts even when only a
    </p>
    <p>
      single channel is supported
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476414830189" ID="ID_1332749665" MODIFIED="1477477586415" TEXT="destroy_on_close"/>
<node COLOR="#111111" CREATED="1476414842725" ID="ID_1719598725" MODIFIED="1477477586415" TEXT="hwname"/>
<node COLOR="#111111" CREATED="1476414848814" ID="ID_406619918" MODIFIED="1477477586415" TEXT="no_vif"/>
</node>
<node COLOR="#111111" CREATED="1476415928069" ID="ID_468572009" MODIFIED="1477477586415" TEXT="struct hwsim_vif_priv"/>
</node>
<node COLOR="#111111" CREATED="1476412360197" ID="ID_15260927" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27169;&#22359;&#21442;&#25968;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476412377630" ID="ID_678225509" MODIFIED="1477477586416" TEXT="radios">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Number of simulated radios
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412395301" ID="ID_725201060" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      channels
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Number of concurrent channels
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412422327" ID="ID_946638314" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      paged_rx
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Use paged SKBs for RX instead of linear ones
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412459696" ID="ID_708208550" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rctbl
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Handle rate control table
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412471473" ID="ID_1057188484" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support_p2p_device
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Support P2P-Device interface type
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476412284459" ID="ID_590883249" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>init_mac80211_hwsim()</b>
    </p>
    <p>
      <font color="#999999">mac80211_hwsim.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476412641495" ID="ID_1612920235" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hwsim_init_netlink();
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476412671536" ID="ID_1755923890" MODIFIED="1477477586416">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mac80211_hwsim_new_radio(...)
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476415011315" ID="ID_805268025" MODIFIED="1477477586417" TEXT="ieee80211_alloc_hw_nm">
<node COLOR="#111111" CREATED="1476415295637" FOLDED="true" ID="ID_655975456" MODIFIED="1477477586417" TEXT="private data">
<node COLOR="#111111" CREATED="1476415311886" ID="ID_655321838" MODIFIED="1477477586417" TEXT="struct mac80211_hwsim_data *data;"/>
</node>
<node COLOR="#111111" CREATED="1476415318574" FOLDED="true" ID="ID_214901893" MODIFIED="1477477586417" TEXT="mac80211_hwsim_ops">
<node COLOR="#111111" CREATED="1476415329831" ID="ID_1198802599" MODIFIED="1477477586417" TEXT="const struct ieee80211_ops "/>
</node>
<node COLOR="#111111" CREATED="1476415662546" ID="ID_222075092" MODIFIED="1477477586417">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21021;&#22987;&#21270;&#25968;&#25454;&#21253;&#21457;&#36865;&#38431;&#21015;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      skb_queue_head_init(&amp;data-&gt;pending);
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#3333ff" DESTINATION="ID_222075092" ENDARROW="Default" ENDINCLINATION="707;0;" ID="Arrow_ID_853178117" SOURCE="ID_611421707" STARTARROW="None" STARTINCLINATION="707;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476416142724" ID="ID_1447743281" MODIFIED="1477477586417" TEXT="ieee80211_hw_set(...)"/>
<node COLOR="#111111" CREATED="1476416155660" ID="ID_1475728718" MODIFIED="1477477586417" TEXT="ieee80211_register_hw(...)"/>
<node COLOR="#111111" CREATED="1476416245847" ID="ID_226441153" MODIFIED="1477477586418" TEXT="hwsim_mcast_new_radio(...)"/>
</node>
<node COLOR="#111111" CREATED="1476412955937" ID="ID_887757595" MODIFIED="1477477586418">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27880;&#20876;&#32593;&#32476;&#35774;&#22791;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      alloc_netdev(...)
    </p>
    <p>
      dev_alloc_name(...)
    </p>
    <p>
      register_netdevice(...)
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1476409717890" FOLDED="true" ID="ID_469100470" MODIFIED="1477636675006" TEXT="mac80211&#x6846;&#x67b6;&#x6e90;&#x7801;&#x5206;&#x6790;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476410841026" ID="ID_1305653455" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20027;&#35201;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411827514" ID="ID_1116728788" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_sub_if_data</b>
    </p>
    <p>
      <font color="#999999">ieee80211_i.h</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      per-interface data
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411858139" ID="ID_132587234" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct wireless_dev wdev;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411879540" ID="ID_1613258345" MODIFIED="1477477586419">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct net_device *dev;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411404642" ID="ID_291977835" MODIFIED="1477477586420" TEXT="IEEE80211_DEV_TO_SUB_IF(dev)">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      static inline struct ieee80211_sub_if_data *
    </p>
    <p>
      IEEE80211_DEV_TO_SUB_IF(struct net_device *dev)
    </p>
    <p>
      {
    </p>
    <p>
      &#160;&#160;&#160;&#160;return netdev_priv(dev);
    </p>
    <p>
      }
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476411901004" ID="ID_1550794880" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_local</b>&#160;*local;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411915772" ID="ID_845718201" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;struct ieee80211_tx_queue_params tx_conf[IEEE80211_NUM_ACS];
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411936085" ID="ID_1947718430" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct cfg80211_chan_def csa_chandef;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411953734" ID="ID_1825231439" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_if_ap *bss;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411966126" ID="ID_737286586" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_vif vif;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      vif_to_sdata(...)
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477364873115" ID="ID_1698880990" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_local</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477364889012" ID="ID_1227098787" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_hw</b>&#160;hw;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477364909668" ID="ID_1879113428" MODIFIED="1477477586420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const <b>struct ieee80211_ops</b>&#160;*ops;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477364956125" ID="ID_791409041" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct workqueue_struct *workqueue;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      private workqueue to mac80211. mac80211 makes this accessible
    </p>
    <p>
      via ieee80211_queue_work()
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476411478093" ID="ID_1807247391" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_hw</b>
    </p>
    <p>
      <font color="#999999">mac80211.h</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hardware information and state
    </p>
    <p>
      This structure contains the configuration and hardware information for an 802.11 PHY.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476411568024" ID="ID_428216736" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_conf conf;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      configuration of the device
    </p>
    <p>
      This struct indicates how the driver shall configure the hardware.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411570376" ID="ID_769222651" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct wiphy *wiphy;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411596657" ID="ID_1623345853" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const char *rate_control_algorithm;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411612778" ID="ID_1572278424" MODIFIED="1477477586421" TEXT="void *priv;">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      private date
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476411667213" ID="ID_1368152963" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      const struct ieee80211_cipher_scheme *cipher_schemes;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cipher scheme
    </p>
    <p>
      This structure contains a cipher scheme information defining
    </p>
    <p>
      the secure packet crypto handling.
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476414667334" ID="ID_545869730" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_ops</b>
    </p>
    <p>
      <font color="#999999">mac80211.h</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366636745" ID="ID_1459531244" MODIFIED="1477477586421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_tx_queue
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477365098650" ID="ID_55395247" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct sta_info
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477365112291" ID="ID_818817939" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_local</b>&#160;*local;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365115571" ID="ID_348401759" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_sub_if_data</b>&#160;*sdata;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365166277" ID="ID_1995620591" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enum ieee80211_sta_state sta_state;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477365169661" ID="ID_613410836" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IEEE80211_STA_AUTH
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365184669" ID="ID_407247364" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IEEE80211_STA_ASSOC
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365190830" ID="ID_321140248" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IEEE80211_STA_AUTHORIZED
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477365221655" ID="ID_1459936071" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct sta_ampdu_mlme ampdu_mlme;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Aggregation information
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365303290" ID="ID_219455914" LINK="#ID_1094116211" MODIFIED="1477477586422">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct ieee80211_sta</b>&#160;sta;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta - station table entry
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477365433551" ID="ID_1094116211" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477365448199" ID="ID_104270344" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta_ht_cap ht_cap;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477365451272" ID="ID_776303380" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta_vht_cap vht_cap;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node CREATED="1474869434819" ID="ID_84622656" MODIFIED="1474869437629" TEXT="cfg80211"/>
<node CREATED="1474869438065" ID="ID_1690035151" MODIFIED="1474869441101" TEXT="mt76x2">
<node CREATED="1474869598426" ID="ID_923886439" MODIFIED="1474869602283" TEXT="Tx">
<node CREATED="1474945300464" ID="ID_1192465889" MODIFIED="1474945304085" TEXT="Tx Queue"/>
</node>
<node CREATED="1474869602826" ID="ID_1430499287" MODIFIED="1474869604146" TEXT="Rx"/>
<node CREATED="1474869606018" ID="ID_197727498" MODIFIED="1474869607843" TEXT="Scan"/>
<node CREATED="1475208168965" ID="ID_1435637780" MODIFIED="1475208172916" TEXT="Rate Selection">
<node CREATED="1475208174268" ID="ID_1483442935" MODIFIED="1475208178987" TEXT="for control frames"/>
</node>
</node>
<node CREATED="1474869441499" FOLDED="true" ID="ID_975733955" MODIFIED="1481467047139" TEXT="mt7668">
<node CREATED="1474869611115" ID="ID_621820542" MODIFIED="1474869612690" TEXT="Tx"/>
<node CREATED="1474869613147" ID="ID_1634330745" MODIFIED="1474869614410" TEXT="Rx">
<node CREATED="1477302877779" ID="ID_718161628" MODIFIED="1477302879592" TEXT="nicRxProcessRFBs">
<node CREATED="1477302939309" ID="ID_112670701" MODIFIED="1477302942866" TEXT="management">
<node CREATED="1477302944164" ID="ID_641779340" MODIFIED="1477302951438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enum ieee80211_sta_rx_bandwidth bandwidth;
    </p>
  </body>
</html></richcontent>
<node CREATED="1477302988454" ID="ID_84848527" MODIFIED="1477303018289" TEXT="apfnProcessRxMgtFrame">
<richcontent TYPE="NOTE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      enum ieee80211_smps_mode smps_mode;
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477303186470" ID="ID_875353768" LINK="#ID_1750226335" MODIFIED="1477303271103">
=======
</node>
<node COLOR="#111111" CREATED="1477365478712" ID="ID_1343141034" MODIFIED="1477477586423">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_sta_rates __rcu *rates;
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
</node>
<node CREATED="1477303128516" ID="ID_1978593939" MODIFIED="1477303131676">
<richcontent TYPE="NODE"><html>
=======
<richcontent TYPE="NOTE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      /**
    </p>
    <p>
      &#160;* struct ieee80211_sta_rates - station rate selection table
    </p>
    <p>
      &#160;*
    </p>
    <p>
      &#160;* @rcu_head: RCU head used for freeing the table on update
    </p>
    <p>
      &#160;* @rate: transmit rates/flags to be used by default.
    </p>
    <p>
      &#160;* Overriding entries per-packet is possible by using cb tx control.
    </p>
    <p>
      &#160;*/
    </p>
    <p>
      struct ieee80211_sta_rates {
    </p>
    <p>
      struct rcu_head rcu_head;
    </p>
    <p>
      struct {
    </p>
    <p>
      s8 idx;
    </p>
    <p>
      u8 count;
    </p>
    <p>
      u8 count_cts;
    </p>
    <p>
      u8 count_rts;
    </p>
    <p>
      u16 flags;
    </p>
    <p>
      } rate[IEEE80211_TX_RATE_TABLE_SIZE];
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
</node>
</node>
</node>
=======
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
<node COLOR="#111111" CREATED="1477365541387" ID="ID_1998999670" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_txq *txq[IEEE80211_NUM_TIDS];
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477290659350" ID="ID_974125567" MODIFIED="1477290664468" TEXT="&#x4e24;&#x79cd;&#x60c5;&#x666f;">
<node CREATED="1477290294937" ID="ID_1084460299" MODIFIED="1477290297302" TEXT="wlan scan"/>
<node CREATED="1477290286265" ID="ID_1641378073" MODIFIED="1477290291294" TEXT="p2p scan"/>
<node CREATED="1477292109178" ID="ID_780409427" MODIFIED="1477292113098">
<richcontent TYPE="NODE"><html>
=======
<richcontent TYPE="NOTE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      Software intermediate tx queue
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
=======
</node>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
</node>
<node COLOR="#111111" CREATED="1476409772848" ID="ID_1660223935" MODIFIED="1477477586423">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477292860036" FOLDED="true" ID="ID_519645803" MODIFIED="1477293055306">
=======
<node COLOR="#111111" CREATED="1476409807658" ID="ID_613038323" MODIFIED="1477477586424">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rc80211_minstrel_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477292869405" ID="ID_1519321590" MODIFIED="1477292872349">
<richcontent TYPE="NODE"><html>
=======
<richcontent TYPE="NOTE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      Rate Control Algorithm
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
</node>
<node CREATED="1477292901398" FOLDED="true" ID="ID_1388995380" MODIFIED="1477293057489">
=======
<icon BUILTIN="full-1"/>
<node COLOR="#111111" CREATED="1476409943006" ID="ID_579598150" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_rate_control_register(...)
    </p>
    <p>
      <font color="#999999">rc80211_minstrel.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476410049250" ID="ID_1118489610" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476410013832" ID="ID_305341745" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct rate_control_ops mac80211_minstrel = {
    </p>
    <p>
      ...
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_305341745" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_1926889873" SOURCE="ID_985864475" STARTARROW="None" STARTINCLINATION="95;0;"/>
</node>
<node COLOR="#111111" CREATED="1476410067083" ID="ID_985864475" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct rate_control_alg {
    </p>
    <p>
      struct list_head list;
    </p>
    <p>
      const struct rate_control_ops *ops;
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_305341745" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_1926889873" STARTARROW="None" STARTINCLINATION="95;0;"/>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_985864475" ENDARROW="Default" ENDINCLINATION="225;0;" ID="Arrow_ID_350388642" SOURCE="ID_41202849" STARTARROW="None" STARTINCLINATION="225;0;"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476409815889" ID="ID_319116633" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rc80211_minstrel_ht_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HT Rate Control Algorithm
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-2"/>
<node COLOR="#111111" CREATED="1476410189304" ID="ID_1025726713" MODIFIED="1477477586424">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      init_sample_table()
    </p>
    <p>
      rc80211_minstrel.c
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476410253585" ID="ID_41202849" MODIFIED="1477477586426" TEXT="&#x76f8;&#x5173;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<arrowlink DESTINATION="ID_985864475" ENDARROW="Default" ENDINCLINATION="225;0;" ID="Arrow_ID_350388642" STARTARROW="None" STARTINCLINATION="225;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476409827482" ID="ID_1795631311" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_iface_init()
    </p>
    <p>
      <font color="#999999">main.c</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-3"/>
<node COLOR="#111111" CREATED="1476410460582" ID="ID_287780463" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>register_netdevice_notifier(...)</b>
    </p>
    <p>
      <font color="#999999">iface.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476410572125" ID="ID_1314326289" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      static struct notifier_block mac80211_netdev_notifier = {
    </p>
    <p>
      .notifier_call = <font color="#0000ff"><b>netdev_notify</b></font>,
    </p>
    <p>
      };
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477366221155" FOLDED="true" ID="ID_1726316341" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>TX</b>
    </p>
    <p>
      <font color="#666666">tx.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366224411" FOLDED="true" ID="ID_473692394" MODIFIED="1477477586426">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx_skb
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477366352328" ID="ID_513970598" MODIFIED="1477477586434">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx_skb_tid
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366362848" ID="ID_295199690" MODIFIED="1477477586434">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      __ieee80211_tx_skb_tid_band
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366366048" ID="ID_86674733" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_xmit
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366518597" ID="ID_46812627" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366533358" ID="ID_1328078520" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      __ieee80211_tx
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366543342" ID="ID_988063716" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_tx_frags
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366553727" ID="ID_1372633761" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_drv_tx
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366567079" ID="ID_1299628656" MODIFIED="1477477586435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      drv_wake_tx_queue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477366578951" ID="ID_1608980143" LINK="#ID_1459531244" MODIFIED="1477477586436" TEXT="wake_tx_queue">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      call back
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477376395236" ID="ID_612179711" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>RX</b>
    </p>
    <p>
      <font color="#666666">rx.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477376398334" ID="ID_1663416978" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_rx
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-1"/>
</node>
<node COLOR="#111111" CREATED="1477376427815" ID="ID_1348324562" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ieee80211_rx_irqsafe
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-2"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477376498857" ID="ID_110691889" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cfg80211 hook function</b>
    </p>
    <p>
      <font color="#666666">cfg.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mac80211 configuration hooks for cfg80211
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477376626774" ID="ID_1522221188" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>channel management</b>
    </p>
    <p>
      <font color="#666666">chan.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477376919945" ID="ID_1828687471" MODIFIED="1477477586436">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>ethtool hooks for cfg80211</b>
    </p>
    <p>
      <font color="#666666">ethtool.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377228868" ID="ID_364043378" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Interface handling</b>
    </p>
    <p>
      <font color="#666666">iface.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377367417" ID="ID_972313321" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Key handling</b>
    </p>
    <p>
      <font color="#666666">key.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477364629251" ID="ID_214260023" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>aggregate</b>
    </p>
    <p>
      <font color="#666666">agg-tx.c/agg-rx.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477375632408" ID="ID_56377793" MODIFIED="1477477586437" TEXT="buffer reorder"/>
</node>
<node COLOR="#111111" CREATED="1477364685967" ID="ID_331600730" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>rate control algorithm</b>
    </p>
    <p>
      <font color="#666666">rate.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377833466" ID="ID_814060601" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>BSS client mode implementation</b>
    </p>
    <p>
      <font color="#666666">mlme.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377908596" ID="ID_243971160" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Off-channel operation helpers</b>
    </p>
    <p>
      <font color="#666666">offchannel.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477377952614" ID="ID_1148949747" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>PM/WOW</b>
    </p>
    <p>
      <font color="#666666">pm.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378228679" ID="ID_1003391081" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Scan</b>
    </p>
    <p>
      <font color="#666666">scan.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378274785" ID="ID_1040895395" MODIFIED="1477477586437">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>spectrum management</b>
    </p>
    <p>
      <font color="#666666">spectmgmt.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378459080" ID="ID_923026136" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>STA information housekeeping</b>
    </p>
    <p>
      <font color="#666666">sta_info.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378567892" ID="ID_1041614804" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>TDLS handling</b>
    </p>
    <p>
      <font color="#666666">tdls.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378834565" ID="ID_186851600" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>VHT handling</b>
    </p>
    <p>
      <font color="#666666">vht.c</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477378952546" ID="ID_602896911" MODIFIED="1477477586438">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>QoS</b>
    </p>
    <p>
      <font color="#666666">wme.c</font>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869434819" ID="ID_84622656" MODIFIED="1477477586438" TEXT="cfg80211">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869438065" ID="ID_1690035151" MODIFIED="1478090688574" TEXT="mt76x2">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869598426" ID="ID_923886439" MODIFIED="1477477586440" TEXT="Tx">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1474945300464" ID="ID_1192465889" MODIFIED="1477477586440" TEXT="Tx Queue"/>
</node>
<node COLOR="#990000" CREATED="1474869602826" ID="ID_1430499287" MODIFIED="1477477586441" TEXT="Rx">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1474869606018" ID="ID_197727498" MODIFIED="1477477586441" TEXT="Scan">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1478248961400" ID="ID_497449915" MODIFIED="1478248967503">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20869;&#23384;&#31649;&#29702;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1478090693516" ID="ID_34775248" MODIFIED="1478090704396">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#33455;&#29255;&#30456;&#20851;&#25805;&#20316;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1478090710853" ID="ID_1891392343" MODIFIED="1478090728506">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MT76x2_ChipOp
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478090733889" ID="ID_1397915684" MODIFIED="1478090790727">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .AsicDynamicVgaGainControl
    </p>
    <p>
      <b><font color="#0000ff">FALSE CCA</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478090792868" ID="ID_689883021" MODIFIED="1478090802726">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      host_periodic_monitor_rssi_adjust_vga
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478090851740" ID="ID_1401578742" MODIFIED="1478090854270" TEXT="periodic_monitor_rssi_adjust_vga_sta_mode">
<node COLOR="#111111" CREATED="1478091055068" ID="ID_400808686" MODIFIED="1478091064852" TEXT="Only when RSSI &lt; -75">
<node COLOR="#111111" CREATED="1478091066111" ID="ID_3202642" MODIFIED="1478091070816">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      periodic_monitor_false_cca_adjust_init_vga
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1475208168965" ID="ID_1435637780" MODIFIED="1477477586442" TEXT="Rate Selection">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1475208174268" ID="ID_1483442935" MODIFIED="1477477586442" TEXT="for control frames"/>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869441499" ID="ID_975733955" MODIFIED="1478248978952" TEXT="mt7668">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474869611115" ID="ID_621820542" MODIFIED="1478610307988" TEXT="Tx">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477559909005" ID="ID_266918801" MODIFIED="1477559914149" TEXT="&#x76f8;&#x5173;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1477559915289" ID="ID_1568168720" MODIFIED="1477559920175">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P_TX_CTRL_T
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477478342856" ID="ID_879454717" MODIFIED="1477478348358">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      main_thread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478396369" ID="ID_1063622589" MODIFIED="1477478432017">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31561;&#24453;&#22914;&#19979;&#20107;&#20214;&#21457;&#29983;
    </p>
    <p>
      <b>wait_event_interruptible</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478435579" ID="ID_1631034660" MODIFIED="1477478707787">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#00ccff"><b>GLUE_FLAG_INT</b></font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477478443635" ID="ID_1951763154" MODIFIED="1477556891715">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#0000cc"><b>GLUE_FLAG_OID_BIT</b></font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478829065" ID="ID_1605852624" MODIFIED="1477478841875">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq-&gt;fgRead
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq = &amp;(prGlueInfo-&gt;OidEntry);
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478845401" ID="ID_1506550129" MODIFIED="1477478850640">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      TRUE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478871394" ID="ID_720722775" MODIFIED="1477478989629">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanQueryInformation
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="243;0;" ID="Arrow_ID_1855677042" STARTARROW="None" STARTINCLINATION="243;0;"/>
<node COLOR="#111111" CREATED="1477479176509" ID="ID_1974889663" MODIFIED="1477479323491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pfnOidQryHandler
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478851186" ID="ID_1101645455" MODIFIED="1477478853856">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478882347" ID="ID_772626705" MODIFIED="1477478995356">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSetInformation
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="229;0;" ID="Arrow_ID_198281093" STARTARROW="None" STARTINCLINATION="229;0;"/>
<node COLOR="#111111" CREATED="1477479143132" ID="ID_1712543043" MODIFIED="1477828994604">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pfnOidSetHandler
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1712543043" ENDARROW="None" ENDINCLINATION="618;0;" ID="Arrow_ID_688335745" SOURCE="ID_1076051513" STARTARROW="None" STARTINCLINATION="618;0;"/>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478936316" ID="ID_483240003" MODIFIED="1477478995356">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq-&gt;rStatus
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="243;0;" ID="Arrow_ID_1855677042" SOURCE="ID_720722775" STARTARROW="None" STARTINCLINATION="243;0;"/>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_483240003" ENDARROW="Default" ENDINCLINATION="229;0;" ID="Arrow_ID_198281093" SOURCE="ID_772626705" STARTARROW="None" STARTINCLINATION="229;0;"/>
<node COLOR="#111111" CREATED="1477479019072" ID="ID_594010182" MODIFIED="1477479024623">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_PENDING
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479498400" ID="ID_1304829124" MODIFIED="1477479523793">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidTimeoutCheck
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This function is called to check if the OID handler needs timeout
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477479064017" ID="ID_1832223950" MODIFIED="1477479065809">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_FAILURE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479554467" ID="ID_291787242" MODIFIED="1477479718564">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      complete(&amp;<b><font color="#0000cc">prGlueInfo-&gt;rPendComp</font></b>);
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="803;0;" ID="Arrow_ID_1875886394" STARTARROW="None" STARTINCLINATION="803;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477479073713" ID="ID_554810430" MODIFIED="1477479075391">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_SUCCESS
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479563443" ID="ID_1536799758" MODIFIED="1477479680068">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      complete(&amp;<font color="#0000cc"><b>prGlueInfo-&gt;rPendComp</b></font>);
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="778;0;" ID="Arrow_ID_146360375" STARTARROW="None" STARTINCLINATION="778;0;"/>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478449828" ID="ID_635894062" MODIFIED="1477559656493">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font color="#cc0099">GLUE_FLAG_TXREQ_BIT</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556834121" ID="ID_317590261" MODIFIED="1477556937895">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalProcessTxReq
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Process Tx Request to main_thread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477557008737" ID="ID_1688843372" MODIFIED="1477560538907">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanProcessMboxMessage
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Process Mailbox Messages
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477560377073" ID="ID_185243011" MODIFIED="1477560541747">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanProcessCommandQueue
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prTxQueue
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477560379585" ID="ID_1161497059" MODIFIED="1477560543898">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalProcessTxPacket
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477560632730" ID="ID_626420708" MODIFIED="1477560658026">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanEnqueueTxPacket
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enqueue a single TX packet into CORE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477560869484" ID="ID_577410772" MODIFIED="1477560977783">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxFillMsduInfo
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fill MSDU info
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_240885290" ENDARROW="Default" ENDINCLINATION="25;0;" ID="Arrow_ID_1955703381" STARTARROW="None" STARTINCLINATION="25;0;"/>
</node>
<node COLOR="#111111" CREATED="1477560961470" ID="ID_240885290" MODIFIED="1477561003303">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxEnqueueMsdu
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      enqueues MSDU_INFO_T into queue management, or command queue
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_240885290" ENDARROW="Default" ENDINCLINATION="25;0;" ID="Arrow_ID_1955703381" SOURCE="ID_577410772" STARTARROW="None" STARTINCLINATION="25;0;"/>
<node COLOR="#111111" CREATED="1477561417950" ID="ID_278512211" MODIFIED="1477561420244">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      qmEnqueueTxPackets
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477560526119" ID="ID_1600916599" MODIFIED="1477561526015" TEXT="wlanTxPendingPackets">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477561550340" ID="ID_1350897571" MODIFIED="1477637481969">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      qmDequeueTxPacketsMthread
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477561605153" ID="ID_432925557" MODIFIED="1477637434015">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      qmDequeueTxPackets
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Dequeue TX packets to send to HIF TX
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477561651118" ID="ID_1993111919" MODIFIED="1477637484897">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxMsduInfoListMthread
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      In this function, we'll aggregate frame(PACKET_INFO_T)
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477637619079" ID="ID_1176757452" MODIFIED="1477637716050">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxFillDataDesc
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1176757452" ENDARROW="Default" ENDINCLINATION="41;-1;" ID="Arrow_ID_1976870905" SOURCE="ID_1334761922" STARTARROW="None" STARTINCLINATION="26;0;"/>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477637636989" HGAP="28" ID="ID_1334761922" MODIFIED="1477637705509" TEXT="Loop for push msdu to skb_buffer" VSHIFT="34">
<arrowlink DESTINATION="ID_1176757452" ENDARROW="Default" ENDINCLINATION="41;-1;" ID="Arrow_ID_1976870905" STARTARROW="None" STARTINCLINATION="26;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477561815979" ID="ID_1459388814" MODIFIED="1477637720858">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetTxEvent2Hif
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477561864936" ID="ID_1258386995" MODIFIED="1477561873031">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wakeup hif thread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477561881655" ID="ID_217551308" MODIFIED="1477561910933">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set_bit(<b><font color="#0000cc">GLUE_FLAG_HIF_TX_BIT</font></b>, &amp;pr-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477561885743" ID="ID_435588952" LINK="#ID_343703026" MODIFIED="1477562092797">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_up_interruptible(&amp;<b><font color="#0000cc">pr-&gt;waitq_hif</font></b>);
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478456395" ID="ID_438575857" MODIFIED="1477478746093">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#cc0000">GLUE_FLAG_HALT</font>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477556862619" ID="ID_1592345369" MODIFIED="1477644582665">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#0000cc">GLUE_FLAG_RX_BIT</font>
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477644555861" ID="ID_1496049418" LINK="#ID_718161628" MODIFIED="1477644593121">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxProcessRFBs
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556895901" ID="ID_1162358599" MODIFIED="1477556903562">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_TX_CMD_DONE_BIT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907850275" ID="ID_1584621015" MODIFIED="1477907856232">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanTxCmdDoneMthread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907893491" ID="ID_385780752" MODIFIED="1477907921081">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      call:&#160;prCmdInfo-&gt;<b><font color="#0000cc">pfCmdDoneHandler</font></b>(...)
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477561926205" ID="ID_1745579825" MODIFIED="1477561929977" TEXT="hif_thread">
<node COLOR="#111111" CREATED="1477561975732" ID="ID_1383351037" MODIFIED="1477561991211">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31561;&#24453;&#22914;&#19979;&#20107;&#20214;&#21457;&#29983;
    </p>
    <p>
      <b>wait_event_interruptible</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562018718" ID="ID_1666106321" MODIFIED="1477899370449">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_INT_BIT
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477647497238" ID="ID_337032423" LINK="#ID_895161077" MODIFIED="1477899368157">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanIST
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477562021141" ID="ID_689005050" MODIFIED="1477562036005">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_TX_CMD_BIT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906936546" ID="ID_1000408848" MODIFIED="1477906938890">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanTxCmdMthread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906973074" ID="ID_88954919" MODIFIED="1477908029761">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27880;&#20876;HIF TX Cmd Done Callback
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907970426" ID="ID_1748134039" MODIFIED="1477907974389">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prCmdInfo-&gt;pfHifTxCmdDoneCb
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907978123" ID="ID_177580910" LINK="#ID_1162358599" MODIFIED="1477908162062">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanTxCmdDoneCb
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wakeup TX thread with <b><font color="#0000cc">GLUE_FLAG_TX_CMD_DONE_BIT</font></b>&#160;set.
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477907090161" ID="ID_927384489" MODIFIED="1477907093210">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxCmd
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907183840" ID="ID_554261837" MODIFIED="1477907254858">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_WRITE_TX_CMD
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477907261344" ID="ID_1459002414" MODIFIED="1477907274382">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalDevWriteCmd
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="stop-sign"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477907094001" ID="ID_712382940" LINK="#ID_1162358599" MODIFIED="1477908178706">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      if u4TxDoneQueueSize &gt; 0
    </p>
    <p>
      &#160;&#160;&#160;wakeup main thread to prcess.
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477562041230" ID="ID_343703026" MODIFIED="1477562043044">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_TX_BIT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562116529" ID="ID_1797956064" MODIFIED="1477562119392">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxMsduQueueMthread
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562326777" ID="ID_340028714" MODIFIED="1477562328711">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxMsduQueue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477562472669" ID="ID_1387322671" MODIFIED="1477829406663">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_WRITE_TX_DATA
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477562480374" ID="ID_555033819" MODIFIED="1477566380381">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_KICK_TX_DATA
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="down"/>
<icon BUILTIN="stop-sign"/>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477562050143" ID="ID_1324094376" MODIFIED="1477562052092">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_FW_OWN_BIT
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477906175992" ID="ID_1627217765" MODIFIED="1477906186189" TEXT="Command&#x53d1;&#x9001;&#x6d41;&#x7a0b;">
<node COLOR="#111111" CREATED="1477906191632" ID="ID_765521494" MODIFIED="1477906198179">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906199255" ID="ID_747869389" MODIFIED="1477906510143">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      CMD_INFO_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;CMD_INFO_T is used by Glue Layer to send
    </p>
    <p>
      a cluster of Command(OID) information to
    </p>
    <p>
      the TX Path to reduce the parameters of a function call.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906600532" ID="ID_1726095776" MODIFIED="1477906638631">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prCmdInfo-&gt;<b><font color="#0000cc">pucInfoBuffer</font></b>
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_1016984849" ENDARROW="Default" ENDINCLINATION="203;0;" ID="Arrow_ID_1987015028" STARTARROW="None" STARTINCLINATION="203;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477906514781" ID="ID_1016984849" MODIFIED="1477906638630">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WIFI_CMD_T
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1016984849" ENDARROW="Default" ENDINCLINATION="203;0;" ID="Arrow_ID_1987015028" SOURCE="ID_1726095776" STARTARROW="None" STARTINCLINATION="203;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477906667229" ID="ID_1474798058" MODIFIED="1477906670311">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906672548" ID="ID_1908085732" MODIFIED="1477906702975">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalProcessTxReq
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906749579" ID="ID_1186532291" MODIFIED="1477906752495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanProcessCommandQueue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477906804427" ID="ID_1219837767" MODIFIED="1477906807051">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSendCommandMthread
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477906807731" ID="ID_1877967967" LINK="#ID_689005050" MODIFIED="1477906902262">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetTxCmdEvent2Hif
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_FLAG_HIF_TX_CMD_BIT
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1474869613147" ID="ID_1634330745" MODIFIED="1478608860820" TEXT="Rx">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1478609026045" ID="ID_371298183" MODIFIED="1478609034379" TEXT="&#x91cd;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1478609035637" ID="ID_1023776888" MODIFIED="1478609039642">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P_SW_RFB_T
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609079287" ID="ID_1174012463" MODIFIED="1478609090265">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HW_MAC_RX_DESC_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RX Descriptor
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477302877779" ID="ID_718161628" MODIFIED="1477645223227" TEXT="nicRxProcessRFBs">
<node COLOR="#111111" CREATED="1477302939309" ID="ID_112670701" MODIFIED="1477477586444" TEXT="management">
<node COLOR="#111111" CREATED="1477302944164" ID="ID_641779340" MODIFIED="1477477586444">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>nicRxProcessMgmtPacket</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477302988454" ID="ID_84848527" MODIFIED="1477477586445" TEXT="apfnProcessRxMgtFrame">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      register the callback function for different subtype management
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477303186470" ID="ID_875353768" LINK="#ID_1750226335" MODIFIED="1477477586445">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanProcessBeaconAndProbeResp
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477303128516" ID="ID_1978593939" MODIFIED="1477477586446">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxReturnRFB
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477644870952" ID="ID_218561813" MODIFIED="1477644874896">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      event
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645048358" ID="ID_1661823962" MODIFIED="1477645050614">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxProcessEventPacket
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645098368" FOLDED="true" ID="ID_549719678" LINK="#ID_1017937243" MODIFIED="1477829659112">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      arEventTable
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645212621" ID="ID_163788232" MODIFIED="1477645214563">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      EVENT_ID_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477645160066" ID="ID_48056886" MODIFIED="1477645162040">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxReturnRFB
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478610354397" ID="ID_455255118" MODIFIED="1478610356852">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      data
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478610387583" ID="ID_1167559123" MODIFIED="1478610389630">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxProcessDataPacket
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477645224397" ID="ID_1017937243" MODIFIED="1477648185753">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Event Callbacks table
    </p>
    <p>
      <b><font color="#0000cc">arEventTable</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477645289719" ID="ID_1025007394" MODIFIED="1477645292485">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      EVENT_ID_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477640573759" ID="ID_1225341160" MODIFIED="1477648164495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicEventScanDone
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477640577079" ID="ID_660083946" MODIFIED="1477640582897">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnEventScanDone
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477640583823" ID="ID_820401909" MODIFIED="1477640620036">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmGenerateScanDoneMsg
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477642841544" ID="ID_1883824724" MODIFIED="1477642843495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mboxSendMsg
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477642847424" ID="ID_1480029553" MODIFIED="1477642854968">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_RLM_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477642855816" ID="ID_78243983" LINK="#ID_1156010732" MODIFIED="1477642961662">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_AIS_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477642866904" ID="ID_1128131937" MODIFIED="1477642869514">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_P2P_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477642876521" ID="ID_1632792911" MODIFIED="1477642878884">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_BOW_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477892345158" ID="ID_508142006" MODIFIED="1477894527948">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSteps
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_FSM's state change from <b>SCANNING</b>&#160;to <b>IDLE</b>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
<node COLOR="#111111" CREATED="1477892356417" ID="ID_667278490" MODIFIED="1477892373884">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state <b><font color="#0000cc">SCAN_STATE_IDLE</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1477646797989" ID="ID_1480319569" MODIFIED="1478609313550">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20013;&#26029;&#22788;&#29702;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477647024365" ID="ID_1359664305" MODIFIED="1477647026716">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glBusSetIrq
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647133553" ID="ID_550828570" MODIFIED="1477647139896">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PCIE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477647140425" ID="ID_1912513464" MODIFIED="1477647143295">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SDIO
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647292551" ID="ID_1050159610" MODIFIED="1477647294838">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mtk_sdio_interrupt
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647304527" ID="ID_1912314167" MODIFIED="1477647306372">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetIntEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647316287" ID="ID_1975102463" MODIFIED="1477647320837" TEXT="&#x591a;&#x7ebf;&#x7a0b;">
<node COLOR="#111111" CREATED="1477647322160" ID="ID_969247790" LINK="#ID_1666106321" MODIFIED="1477647455606">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake up hif_thread
    </p>
    <p>
      <b><font color="#0000cc">GLUE_FLAG_INT_BIT</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647353065" ID="ID_517606336" MODIFIED="1477647359542">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21333;&#32447;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647371305" ID="ID_512331115" MODIFIED="1477647397573">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake up main_thread
    </p>
    <p>
      <b><font color="#0000cc">GLUE_FLAG_INT_BIT</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477647143898" ID="ID_625780614" MODIFIED="1477647149375">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      USB
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647515999" ID="ID_895161077" MODIFIED="1477899330864">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanIST
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647560520" ID="ID_487479042" MODIFIED="1477647563756">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessIST
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647583593" ID="ID_1286985491" MODIFIED="1477647869364">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessIST_impl
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_210965563" ENDARROW="Default" ENDINCLINATION="52;-26;" ID="Arrow_ID_1071944013" STARTARROW="None" STARTINCLINATION="-106;-73;"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477647630555" ID="ID_210965563" MODIFIED="1477647869364">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22788;&#29702;&#20989;&#25968;
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_210965563" ENDARROW="Default" ENDINCLINATION="52;-26;" ID="Arrow_ID_1071944013" SOURCE="ID_1286985491" STARTARROW="None" STARTINCLINATION="-106;-73;"/>
<node COLOR="#111111" CREATED="1477647642884" ID="ID_97567096" MODIFIED="1477647688681">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_ABNORMAL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647713750" ID="ID_771999360" MODIFIED="1477647715796">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessAbnormalInterrupt
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647654100" ID="ID_154723805" MODIFIED="1477647695543">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_SW_INT
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647717974" ID="ID_991248087" MODIFIED="1477647723594">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessSoftwareInterrupt
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647696501" ID="ID_862535768" MODIFIED="1477647701824">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_TX
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647725326" ID="ID_584743851" MODIFIED="1477647731761">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessTxInterrupt
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477647702670" ID="ID_1673536404" MODIFIED="1477647707888">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      INT_EVENT_RX
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477647733638" ID="ID_754780600" MODIFIED="1477647748633">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicProcessRxInterrupt
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609381441" ID="ID_665045712" MODIFIED="1478609395507">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halProcessRxInterrupt
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609435460" ID="ID_1778967641" MODIFIED="1478662786861">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halProcessRxInterrupt
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rReceivedRFBList
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609418435" ID="ID_1241315098" MODIFIED="1478609425242">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PCIe
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609425684" ID="ID_994708404" MODIFIED="1478609428398">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SDIO
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478662679747" ID="ID_1780022212" MODIFIED="1478662752482">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#ff0000">halRxSDIOAggReceiveRFBs</font>
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<icon BUILTIN="ksmiletris"/>
</node>
<node COLOR="#111111" CREATED="1478662683027" ID="ID_1378012316" MODIFIED="1478662688956">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxSDIOEnhanceReceiveRFBs
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478662689459" ID="ID_859797908" MODIFIED="1478662695762">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxSDIOReceiveRFBs
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478609429916" ID="ID_1053664668" MODIFIED="1478609434458">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      USB
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478609705620" ID="ID_301905827" MODIFIED="1478609708514" TEXT="Event">
<node COLOR="#111111" CREATED="1478609652052" ID="ID_593686293" MODIFIED="1478609654332">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBProcessEventDataComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609655115" ID="ID_788732759" MODIFIED="1478609660826">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBReceiveEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478610014673" ID="ID_1534969678" MODIFIED="1478610014674" TEXT=""/>
</node>
</node>
<node COLOR="#111111" CREATED="1478609716566" ID="ID_28926351" MODIFIED="1478609720819" TEXT="Data">
<node COLOR="#111111" CREATED="1478609731854" ID="ID_438644415" MODIFIED="1478609734279">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBProcessEventDataComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478609734775" ID="ID_451164536" MODIFIED="1478609740614">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halRxUSBReceiveData
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477647893724" ID="ID_1525133000" LINK="#ID_1592345369" MODIFIED="1477647950351">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set <b><font color="#0000cc">GLUE_FLAG_RX_BIT</font></b>
    </p>
    <p>
      wakeup main thread
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1474869614923" FOLDED="true" ID="ID_657070274" MODIFIED="1478608847013">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>Scan</b>
    </p>
    <p>
      <font color="#666666">scan.c/scan.h</font>
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477290659350" ID="ID_974125567" MODIFIED="1477477586451" TEXT="&#x4e24;&#x79cd;&#x60c5;&#x666f;">
<node COLOR="#111111" CREATED="1477290294937" ID="ID_1084460299" MODIFIED="1477477586451" TEXT="wlan scan"/>
<node COLOR="#111111" CREATED="1477290286265" ID="ID_1641378073" MODIFIED="1477477586451" TEXT="p2p scan"/>
<node COLOR="#111111" CREATED="1477292109178" ID="ID_780409427" MODIFIED="1477477586451">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SchedScan
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477531726057" ID="ID_276642409" MODIFIED="1477531798552" TEXT="NLO SCAN">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <h1 id="wi-fi-network-list-offload" sourcefile="network/wi-fi-network-list-offload.md" sourcestartlinenumber="7" sourceendlinenumber="7" style="margin-top: 0px; margin-right: 0px; margin-bottom: 20px; margin-left: 0px; font-size: 34px; font-family: Segoe UI, Tahoma, Helvetica, sans-serif; font-weight: 400; line-height: 1.2; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; background-color: rgb(255, 255, 255)">
      Wi-Fi Network List Offload(NLO)
    </h1>
    <p>
      <font color="rgb(51, 51, 51)" face="Segoe UI, Lucida Grande, Verdana, Arial, Helvetica, sans-serif" size="15px">Wi-Fi Network List Offload (NLO) is a feature where certain Wi-Fi profile information </font>
    </p>
    <p>
      <font color="rgb(51, 51, 51)" face="Segoe UI, Lucida Grande, Verdana, Arial, Helvetica, sans-serif" size="15px">is offloaded to the NIC firmware to allow the Wi-Fi NIC to perform logic that optimizes </font>
    </p>
    <p>
      <font color="rgb(51, 51, 51)" face="Segoe UI, Lucida Grande, Verdana, Arial, Helvetica, sans-serif" size="15px">the power efficiency and connectivity of a given system.&#160;</font>
    </p>
    <h1 id="wi-fi-network-list-offload" sourcefile="network/wi-fi-network-list-offload.md" sourcestartlinenumber="7" sourceendlinenumber="7" style="margin-top: 0px; margin-right: 0px; margin-bottom: 20px; margin-left: 0px; font-size: 34px; font-family: Segoe UI, Tahoma, Helvetica, sans-serif; font-weight: 400; line-height: 1.2; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; word-spacing: 0px; background-color: rgb(255, 255, 255)">
      
    </h1>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292806051" ID="ID_950525852" MODIFIED="1477477586452" TEXT="&#x4e3b;&#x8981;&#x8fc7;&#x7a0b;">
<node COLOR="#111111" CREATED="1477292818043" ID="ID_802581462" MODIFIED="1477477586452">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnInit
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477292860036" FOLDED="true" ID="ID_519645803" MODIFIED="1477477586453">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21021;&#22987;&#21270;P_SCAN_INFO_T
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477292869405" ID="ID_1519321590" MODIFIED="1477477586453">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.rScanInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292901398" FOLDED="true" ID="ID_1388995380" MODIFIED="1477477586453">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      1. &#35774;&#32622;&#24403;&#21069;&#29366;&#24577;
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477292933784" ID="ID_775387935" MODIFIED="1477292942670">
=======
<node COLOR="#111111" CREATED="1477292933784" ID="ID_775387935" MODIFIED="1477477586454">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;eCurrentState = SCAN_STATE_IDLE;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292945162" FOLDED="true" ID="ID_192402074" MODIFIED="1477477586454">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      2. &#21021;&#22987;&#21270;&#26410;&#20915;&#28040;&#24687;&#22788;&#29702;&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477292973849" ID="ID_1618147985" MODIFIED="1477477586455">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      LINK_INITIALIZE(&amp;prScanInfo-&gt;rPendingMsgList);
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477292991953" ID="ID_281477680" MODIFIED="1477477586455">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      3. &#37325;&#32622;BSS_DESC_T&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477293033548" ID="ID_1051847339" MODIFIED="1477477586455">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;rFreeBSSDescLis
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Bss Desc Pool
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477293036531" ID="ID_541992024" MODIFIED="1477477586456">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;rBSSDescList
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      current scan result list
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477303252296" ID="ID_1750226335" MODIFIED="1477477586457">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>scanProcessBeaconAndProbeResp</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      handling beacon and probe response frames.
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477290572027" FOLDED="true" ID="ID_111598812" MODIFIED="1477554893665">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477290901558" ID="ID_513386577" MODIFIED="1477477586458">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct _BSS_DESC_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      BSS Descriptors
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474038366" ID="ID_1368560812" MODIFIED="1477477586458" TEXT="&#x57fa;&#x672c;&#x4fe1;&#x606f;">
<node COLOR="#111111" CREATED="1477474054446" ID="ID_1056118601" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      BSSID
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474075951" ID="ID_299760844" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Source Mac Addr
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474099280" ID="ID_735465438" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36830;&#25509;&#29366;&#24577;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474106624" ID="ID_731489070" MODIFIED="1477477586459" TEXT="fgIsConnecting"/>
<node COLOR="#111111" CREATED="1477474112961" ID="ID_530925033" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsConnected
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474127736" ID="ID_105800202" MODIFIED="1477477586459">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsHiddenSSID
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hidden SSID?
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474153322" ID="ID_1385306444" MODIFIED="1477477586459" TEXT="SSID">
<node COLOR="#111111" CREATED="1477474158715" ID="ID_1744931162" MODIFIED="1477477586460" TEXT="name"/>
<node COLOR="#111111" CREATED="1477474161363" ID="ID_1658090105" MODIFIED="1477477586460" TEXT="len"/>
</node>
<node COLOR="#111111" CREATED="1477474170075" ID="ID_1918106060" MODIFIED="1477477586460" TEXT="&#x66f4;&#x65b0;&#x65f6;&#x95f4;">
<node COLOR="#111111" CREATED="1477474177378" ID="ID_711023715" MODIFIED="1477477586460">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rUpdateTime
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474189260" ID="ID_1890044702" MODIFIED="1477477586460" TEXT="&#x7c7b;&#x578b;">
<node COLOR="#111111" CREATED="1477474193683" ID="ID_1601500759" MODIFIED="1477477586460">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      infra
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474216189" ID="ID_710342362" MODIFIED="1477477586460" TEXT="p2p"/>
<node COLOR="#111111" CREATED="1477474219108" ID="ID_734862467" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ibss
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474223788" ID="ID_1115738656" MODIFIED="1477477586461" TEXT="bow"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477474241501" ID="ID_63678195" MODIFIED="1477477586461" TEXT="802.11&#x534f;&#x8bae;&#x76f8;&#x5173;&#x4fe1;&#x606f;">
<node COLOR="#111111" CREATED="1477474253221" ID="ID_347659196" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Capability Info
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474269662" ID="ID_1722160373" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      u2CapInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474279527" ID="ID_1725706100" MODIFIED="1477477586461">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Beacon Interval
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474326616" ID="ID_771943942" MODIFIED="1477477586461" TEXT="&#x57fa;&#x672c;&#x901f;&#x7387;&#x96c6;"/>
<node COLOR="#111111" CREATED="1477474350497" ID="ID_1692244334" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Physic Mode&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474363065" ID="ID_390659831" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsERPPresent
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474366105" ID="ID_1218704099" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsHTPresent
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474374153" ID="ID_1289574445" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgIsVHTPresent
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474411891" ID="ID_982826160" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474426411" ID="ID_1243014730" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ucChannelNum
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474453358" ID="ID_1561315046" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      eChannelWidth
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bandwidth
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474479230" ID="ID_123455038" MODIFIED="1477477586462" TEXT="eBand">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Band
    </p>
    <ol>
      <li>
        2.4G
      </li>
      <li>
        5G
      </li>
    </ol>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474528440" ID="ID_676069200" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#24687;&#24378;&#24230;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474534088" ID="ID_1853737326" MODIFIED="1477477586462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WMM
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474562457" ID="ID_1721870089" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RSN&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474580017" ID="ID_426129624" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21152;&#23494;&#31639;&#27861;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474585897" ID="ID_1228925074" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#33021;&#21147;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474635099" ID="ID_1203629817" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p&#30456;&#20851;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474671580" ID="ID_828540053" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IE&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474676188" ID="ID_1315522324" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36830;&#25509;&#22833;&#36133;&#32479;&#35745;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477465186451" ID="ID_100076397" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct _STA_RECORD_T
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291055180" ID="ID_555869001" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      used by SCN_FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477290963257" ID="ID_1204016248" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_PARAM_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Used by SCAN FSM
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#ff0099" DESTINATION="ID_1204016248" ENDARROW="Default" ENDINCLINATION="98;0;" ID="Arrow_ID_677627362" SOURCE="ID_1372399135" STARTARROW="None" STARTINCLINATION="98;0;"/>
<node COLOR="#111111" CREATED="1477474730575" ID="ID_1495468912" MODIFIED="1477477586463">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#31867;&#22411;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474739247" ID="ID_397143539" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Active Scan
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474746351" ID="ID_4663029" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Passive Scan
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474765576" ID="ID_921106146" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#32593;&#32476;&#31867;&#22411;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474779848" ID="ID_665590202" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Bss Index
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474795088" ID="ID_381116240" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474872156" ID="ID_523300105" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#22810;&#20010;SSID
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474798921" ID="ID_334846117" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31867;&#22411;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474811922" ID="ID_368494423" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25968;&#37327;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474890205" ID="ID_18985290" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#29305;&#23450;SSID
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477474918822" ID="ID_1291615766" MODIFIED="1477477586464">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p&#35774;&#22791;&#25195;&#25551;&#30456;&#20851;&#35774;&#23450;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474957166" ID="ID_463495081" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      802.11&#21327;&#35758;&#30456;&#20851;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477474972127" ID="ID_990116057" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#39547;&#30041;&#26102;&#38388;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477474985495" ID="ID_1407102684" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36229;&#26102;&#26102;&#38388;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475005176" ID="ID_264871455" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      OBSS Scan?
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475123789" ID="ID_1765245295" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477475043042" ID="ID_1945440015" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#25195;&#25551;&#30340;&#20449;&#36947;&#31867;&#22411;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477475056314" ID="ID_266450065" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      2.4G
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475062962" ID="ID_1422847998" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      5G
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475072818" ID="ID_1447368751" MODIFIED="1477477586465">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p social channel
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477475081587" ID="ID_295642648" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Specified
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475135557" ID="ID_111714148" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20449;&#36947;&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475158526" ID="ID_585445635" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IE&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290992209" ID="ID_769108161" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      NLO_PARAM_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Used by SCAN FSM
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#3333ff" DESTINATION="ID_769108161" ENDARROW="Default" ENDINCLINATION="99;0;" ID="Arrow_ID_855709524" SOURCE="ID_1562519665" STARTARROW="None" STARTINCLINATION="99;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477291101885" ID="ID_1614107042" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_INFO_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo = &amp;(prAdapter-&gt;rWifiVar.rScanInfo);
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291113510" ID="ID_189391468" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      eCurrentState
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Store the STATE variable of SCAN FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477465605000" ID="ID_446536825" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_IDLE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477465618042" ID="ID_1896296839" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_SCANNING
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477291126431" ID="ID_1372399135" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rScanParam
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#ff0099" DESTINATION="ID_1204016248" ENDARROW="Default" ENDINCLINATION="98;0;" ID="Arrow_ID_677627362" STARTARROW="None" STARTINCLINATION="98;0;"/>
</node>
<node COLOR="#111111" CREATED="1477291137479" ID="ID_1562519665" MODIFIED="1477477586466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rNloParam
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#3333ff" DESTINATION="ID_769108161" ENDARROW="Default" ENDINCLINATION="99;0;" ID="Arrow_ID_855709524" STARTARROW="None" STARTINCLINATION="99;0;"/>
</node>
<node COLOR="#111111" CREATED="1477465882818" ID="ID_799012932" MODIFIED="1477477586467" TEXT="BSS&#x4fe1;&#x606f;&#x7ef4;&#x62a4;">
<node COLOR="#111111" CREATED="1477465778336" ID="ID_560950253" MODIFIED="1477477586467" TEXT="u4NumOfBssDesc"/>
<node COLOR="#111111" CREATED="1477465792959" ID="ID_575156288" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aucScanBuffer
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      buffer to store bss list sequecely
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477465695699" ID="ID_1526910999" LINK="#ID_513386577" MODIFIED="1477477586467" TEXT="rBSSDescList">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      current SCAN result list
    </p>
    <p>
      a memory pool
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477465802615" ID="ID_832327262" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rFreeBSSDescList
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      build a free bss list from aucScanBuffer
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475277753" ID="ID_210522264" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN&#35831;&#27714;&#38431;&#21015;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477475289947" ID="ID_1118994445" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rPendingMsgList
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475323580" ID="ID_1289565519" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#32479;&#35745;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477475428967" ID="ID_1357471693" MODIFIED="1477477586467" TEXT="mbox&#x4ea4;&#x4e92;&#x6d88;&#x606f;">
<node COLOR="#111111" CREATED="1477291271612" ID="ID_1189256975" MODIFIED="1477477586467">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Incoming Mailbox Messages
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291241874" ID="ID_815930803" LINK="#ID_707929156" MODIFIED="1477554534269">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291403345" ID="ID_722449350" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291432041" ID="ID_309507790" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Cancel Scan Request
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291475931" ID="ID_1910306294" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_NLO_REQ
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291492107" ID="ID_1044574123" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_NLO_CANCEL
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477291516493" ID="ID_394372055" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Outgoing Mailbox Messages
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291525813" ID="ID_1163722504" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_SCAN_DONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477291570654" ID="ID_1314970388" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_SCN_NLO_DONE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290598949" ID="ID_473642935" MODIFIED="1477477586468">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31574;&#30053;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477291696571" ID="ID_1792220868" MODIFIED="1477477586469" TEXT="remove bss">
<node COLOR="#111111" CREATED="1477293766533" ID="ID_514776937" MODIFIED="1477477586469">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanByPassRemoveBssDesc
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bypass BSS Descriptors from current list according to specific BSSID.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477293839272" ID="ID_1605540210" MODIFIED="1477477586470">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanRemoveBssDescsByPolicy
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Delete BSS Descriptors from current list according to given Remove Policy.
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290607236" ID="ID_1136054535" MODIFIED="1477477586471">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20869;&#23384;&#31649;&#29702;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477476773759" ID="ID_274724165" MODIFIED="1477636862047">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#35843;&#29992;&#27969;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477476783720" ID="ID_1647030433" MODIFIED="1477477675023">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19978;&#23618;&#36890;&#36807;nl80211&#19979;&#36798;SCAN&#21629;&#20196;
    </p>
  </body>
</html></richcontent>
<edge COLOR="#ff0033" WIDTH="2"/>
<cloud/>
<node COLOR="#111111" CREATED="1477476799984" ID="ID_1429711910" MODIFIED="1477477586472">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mtk_cfg80211_scan
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pass down struct <b><font color="#0033ff">cfg80211_scan_request</font></b>&#160;from cfg80211
    </p>
  </body>
</html></richcontent>
<cloud/>
<node COLOR="#111111" CREATED="1477476950174" ID="ID_1767360179" MODIFIED="1477477586473">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIoctl
    </p>
  </body>
</html></richcontent>
<cloud/>
<node COLOR="#111111" CREATED="1477476963967" ID="ID_1069622385" MODIFIED="1477478300908">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Compose the I/O request
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477476987590" ID="ID_1716722940" MODIFIED="1477477586474">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P_GL_IO_REQ_T
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prIoReq = &amp;(prGlueInfo-&gt;OidEntry);
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477133420" FOLDED="true" ID="ID_226621999" MODIFIED="1477477835162">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477288562" ID="ID_912414172" MODIFIED="1477477586475">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prGlueInfo-&gt;prAdapter
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477162974" ID="ID_1076051513" LINK="#ID_1337511987" MODIFIED="1477828994603">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pfnOidHandler
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_1712543043" ENDARROW="None" ENDINCLINATION="618;0;" ID="Arrow_ID_688335745" STARTARROW="None" STARTINCLINATION="618;0;"/>
<node COLOR="#111111" CREATED="1477477314354" ID="ID_46143452" MODIFIED="1477477586476">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetBssidListScanAdv
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477178445" ID="ID_647046274" MODIFIED="1477477586477">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pvInfoBuf
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477902880" ID="ID_1412132363" MODIFIED="1477478000851">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rScanRequest
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      typedef struct _<b><font color="#0033ff">PARAM_SCAN_REQUEST_ADV_T</font></b>&#160;{
    </p>
    <p>
      UINT_32 u4SsidNum;
    </p>
    <p>
      PARAM_SSID_T rSsid[CFG_SCAN_SSID_MAX_NUM];
    </p>
    <p>
      UINT_32 u4IELength;
    </p>
    <p>
      PUINT_8 pucIE;
    </p>
    <p>
      } PARAM_SCAN_REQUEST_ADV_T, *P_PARAM_SCAN_REQUEST_ADV_T;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477184230" ID="ID_1309081189" MODIFIED="1477477586478">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      u4InfoBufLen
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477477190566" ID="ID_823429363" MODIFIED="1477477586478">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pu4QryInfoLen
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477477197310" ID="ID_223307251" MODIFIED="1477477586479">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgRead
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478057757" ID="ID_742691517" MODIFIED="1477478062204">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477204031" ID="ID_842732216" MODIFIED="1477477586479">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      fgWaitResp
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478064974" ID="ID_970504991" MODIFIED="1477478068371">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477213647" FOLDED="true" ID="ID_185948720" MODIFIED="1477477586480">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rStatus
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477477222168" ID="ID_1817955160" MODIFIED="1477477586480">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WLAN_STATUS_FAILURE
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477477248432" ID="ID_499817139" MODIFIED="1477478101905">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      u4Flag
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Check if we use the command queue
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477478085902" ID="ID_1807825234" MODIFIED="1477478090605">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477478110863" ID="ID_120385381" MODIFIED="1477478515982">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      schedule the OID bit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set_bit(<b><font color="#0033ff">GLUE_FLAG_OID_BIT</font></b>, &amp;prGlueInfo-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477478182810" ID="ID_166748027" LINK="#ID_1951763154" MODIFIED="1477478532787">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Wake up tx thread
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_up_interruptible(&amp;prGlueInfo-&gt;waitq);
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477478211571" ID="ID_879006110" MODIFIED="1477479718565">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Block and wait for event or timeout
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wait_for_completion(&amp;<b><font color="#0033ff">prGlueInfo-&gt;rPendComp</font></b>);
    </p>
    <p>
      timeout value is 2 secs
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="803;0;" ID="Arrow_ID_1875886394" SOURCE="ID_291787242" STARTARROW="None" STARTINCLINATION="803;0;"/>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_879006110" ENDARROW="None" ENDINCLINATION="778;0;" ID="Arrow_ID_146360375" SOURCE="ID_1536799758" STARTARROW="None" STARTINCLINATION="778;0;"/>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477478270845" ID="ID_1464162105" MODIFIED="1477478314755">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Clear bit for error handling
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      clear_bit(GLUE_FLAG_OID_BIT, &amp;prGlueInfo-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477477108132" ID="ID_1337511987" MODIFIED="1477479788588">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetBssidListScanAdv
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This routine is called to request the driver to perform
    </p>
    <p>
      scanning with attaching information elements(IEs)
    </p>
    <p>
      specified from user space and multiple SSID
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479879727" ID="ID_538709746" MODIFIED="1477551422515">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;fgEnOnlineScan
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      whether allow scanning when already connected to an AP ?
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479889975" ID="ID_835399990" MODIFIED="1477479891981">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      TRUE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477479898599" ID="ID_336713407" LINK="#ID_184662158" MODIFIED="1477482543139">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequestAdv
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477479992427" ID="ID_965398900" MODIFIED="1477479997943" TEXT="FALSE">
<node COLOR="#111111" CREATED="1477480044044" ID="ID_908606429" MODIFIED="1477480077462">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalGetMediaStateIndicated
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      get connect state
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480079246" ID="ID_900373954" MODIFIED="1477480086179">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PARAM_MEDIA_STATE_CONNECTED
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480167440" ID="ID_1211208977" MODIFIED="1477480202590">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      return <b><font color="#0000cc">WLAN_STATUS_FAILURE</font></b>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477480087309" ID="ID_1032960215" MODIFIED="1477480114382">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      PARAM_MEDIA_STATE_DISCONNECTED
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480138375" ID="ID_524430459" LINK="#ID_184662158" MODIFIED="1477482572676">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequestAdv
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477480222475" ID="ID_149967130" MODIFIED="1477480225042">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmTimerStartTimer
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480247091" ID="ID_176351557" MODIFIED="1477480268555">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21551;&#21160;&#25195;&#25551;&#35745;&#26102;&#22120;
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.rAisFsmInfo.rScanDoneTimer
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480269997" ID="ID_1741018689" MODIFIED="1477480296900">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#36229;&#26102;&#26102;&#38388;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480301214" ID="ID_214715576" MODIFIED="1477480343238">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">AIS_SCN_DONE_TIMEOUT_SEC</font>
    </p>
    <p>
      <b>15 s</b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477477366116" ID="ID_142109904" MODIFIED="1477640370006">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Scan&#32467;&#26463;&#21518;&#22238;&#35843;&#27969;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477829439532" ID="ID_222825614" LINK="#ID_895161077" MODIFIED="1477829513992">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FW&#36890;&#36807;&#20013;&#26029;&#36890;&#30693;SCAN_DONE&#20107;&#20214;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1476693591000" ID="ID_992150334" MODIFIED="1480592258020" TEXT="mbox">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476693664979" ID="ID_692923152" MODIFIED="1477645540850">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>arMsgMapTable</b>
    </p>
    <p>
      <font color="#999999">hem_mbox.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476693720861" ID="ID_1454704760" MODIFIED="1477477586483" TEXT="SCN">
<node COLOR="#111111" CREATED="1477554478206" ID="ID_707929156" LINK="#ID_815930803" MODIFIED="1477554519996">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554494119" ID="ID_207557093" MODIFIED="1477554497100">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554541128" ID="ID_112483751" MODIFIED="1477554547191">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554548536" ID="ID_1555617083" LINK="#ID_1421132781" MODIFIED="1477555058720">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554557481" ID="ID_968488606" MODIFIED="1477554565303">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554570209" ID="ID_1336062308" MODIFIED="1477554572295">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554573681" ID="ID_985885395" MODIFIED="1477554585297">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_P2P_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554588362" ID="ID_1596296588" MODIFIED="1477554600608">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554613138" ID="ID_1444765102" MODIFIED="1477554619618">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_P2P_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554620683" ID="ID_973494335" MODIFIED="1477554626137">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554627587" ID="ID_1459228768" MODIFIED="1477554633289">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_P2P_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554634484" ID="ID_843296139" MODIFIED="1477554640026">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554642995" ID="ID_1732571689" MODIFIED="1477554649683">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_BOW_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554650748" ID="ID_459932698" MODIFIED="1477554656842">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554659020" ID="ID_708950156" MODIFIED="1477554665283">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_BOW_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554666237" ID="ID_886794284" MODIFIED="1477554671778">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554673349" ID="ID_1105551288" MODIFIED="1477554678907">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_BOW_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554680021" ID="ID_1773590875" MODIFIED="1477554686845">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554688981" ID="ID_552679161" MODIFIED="1477554696651">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_RLM_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554697766" ID="ID_1111845697" MODIFIED="1477554704324">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554706030" ID="ID_1980602823" MODIFIED="1477554712148">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_RLM_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554713286" ID="ID_1292966190" MODIFIED="1477554719374">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554721126" ID="ID_1592808333" MODIFIED="1477554726837">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_RLM_SCN_SCAN_CANCEL
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554727775" ID="ID_1329912397" MODIFIED="1477554732908">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554734744" ID="ID_1156010732" MODIFIED="1477554758430">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_AIS_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554750864" ID="ID_801912226" MODIFIED="1477904068823">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventScanDone
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477643165179" ID="ID_1973140841" MODIFIED="1477643171616">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_SCAN
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477643224349" ID="ID_29359823" MODIFIED="1477643270247">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalScanDone
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477643997121" ID="ID_19129868" MODIFIED="1477643999120">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIndicateBssInfo
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477644000576" ID="ID_316460872" MODIFIED="1477644015059">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cfg80211_inform_bss_frame
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477644047514" ID="ID_1742452353" MODIFIED="1477644076048">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIndicateStatusAndComplete
    </p>
    <p>
      <b><font color="#0000cc">WLAN_STATUS_SCAN_COMPLETE</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477644096452" ID="ID_1604316516" MODIFIED="1477644107318">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cfg80211_scan_done
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477643231334" ID="ID_881077698" MODIFIED="1477643272640">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scanReportScanResultToAgps
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477643257390" ID="ID_556296207" MODIFIED="1477892106719">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      proceed if state change is necessary
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477643172516" ID="ID_1435505155" MODIFIED="1477643181206">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_ONLINE_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477643182052" ID="ID_1935346127" MODIFIED="1477643189990">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_LOOKING_FOR
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477554795313" ID="ID_1611852008" MODIFIED="1477554797104">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_P2P_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554798313" ID="ID_1923933303" MODIFIED="1477554804136">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pFsmRunEventScanDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554806241" ID="ID_721895666" MODIFIED="1477554813687">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_BOW_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554814666" ID="ID_619759089" MODIFIED="1477554820272">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bowResponderScanDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477554822018" ID="ID_1634545795" MODIFIED="1477554827978">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_SCN_RLM_SCAN_DONE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554829090" ID="ID_782010266" MODIFIED="1477642447435">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rlmObssScanDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476693728460" ID="ID_301344253" MODIFIED="1477477586484" TEXT="AIS">
<node COLOR="#111111" CREATED="1476693783637" FOLDED="true" ID="ID_1068507575" MODIFIED="1480592302142" TEXT="MID_AIS_SAA_FSM_START">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Start Event for SAA FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476693885977" ID="ID_106165759" MODIFIED="1477477586484" TEXT="saaFsmRunEventStart"/>
</node>
<node COLOR="#111111" CREATED="1476693803586" ID="ID_1561167379" MODIFIED="1480592343615" TEXT="MID_AIS_SAA_FSM_ABORT">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      STOP Event for SAA FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476693894460" ID="ID_966622547" MODIFIED="1477477586484" TEXT="saaFsmRunEventAbort"/>
</node>
<node COLOR="#111111" CREATED="1480592339943" ID="ID_1468307456" MODIFIED="1480592341977">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_OID_AIS_FSM_JOIN_REQ
    </p>
  </body>
</html>
</richcontent>
<node COLOR="#111111" CREATED="1480592348799" ID="ID_1683102159" MODIFIED="1480592355583">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventAbort
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1476693910068" FOLDED="true" ID="ID_1542906064" MODIFIED="1478608826982" TEXT="FSM">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476693913846" ID="ID_1211971427" MODIFIED="1477477586485" TEXT="SAA">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      STA Auth &amp; Assoc
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476694135627" ID="ID_1318692252" MODIFIED="1477829066013" TEXT="AIS">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Ad-hoc, Infra STA&#160;&#160;FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477480655538" FOLDED="true" ID="ID_1040396993" MODIFIED="1477554303981" TEXT="STATE">
<node COLOR="#111111" CREATED="1477480659563" ID="ID_1904536252" MODIFIED="1477480665586">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IDLE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480666667" ID="ID_647365706" MODIFIED="1477480672249">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SEARCH
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480673203" ID="ID_701825282" MODIFIED="1477480679153">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480680043" ID="ID_372268151" MODIFIED="1477480686433">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ONLINE_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480687355" ID="ID_1690362886" MODIFIED="1477480692697">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      LOOKING_FOR
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480694363" ID="ID_842509395" MODIFIED="1477480699884">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      WAIT_FOR_NEXT_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480700764" ID="ID_285209394" MODIFIED="1477480705994">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      REQ_CHANNEL_JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480706812" ID="ID_1401206678" MODIFIED="1477480712122">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480712996" ID="ID_1965424597" MODIFIED="1477480718738">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      JOIN_FAILURE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480719669" ID="ID_1544181951" MODIFIED="1477480725034">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IBSS_ALONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480726004" ID="ID_1957569222" MODIFIED="1477480731228">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      IBSS_MERGE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480732349" ID="ID_609586142" MODIFIED="1477480737539">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      NORMAL_TR
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480738428" ID="ID_1889029" MODIFIED="1477480743651">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      DISCONNECTING
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480745405" ID="ID_16508893" MODIFIED="1477480751404">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      REQ_REMAIN_ON_CHANNEL
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477480752286" ID="ID_341853372" MODIFIED="1477480757451">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      REMAIN_ON_CHANNEL
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482754469" ID="ID_622348699" MODIFIED="1477482772683">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FSM Core Functions
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482778742" ID="ID_1682900993" MODIFIED="1477482781405">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisInitializeConnectionSettings
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482782479" ID="ID_1571932236" MODIFIED="1477482787708">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInit
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482788590" ID="ID_775147704" MODIFIED="1477482793772">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmUninit
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482794663" ID="ID_542259582" MODIFIED="1477482800222">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482801367" ID="ID_1534713462" MODIFIED="1477482806893">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_RetryJOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482807783" ID="ID_167274226" MODIFIED="1477482813957">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_IBSS_ALONE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482814895" ID="ID_269479070" MODIFIED="1477482820094">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateInit_IBSS_MERGE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482826496" ID="ID_1397501811" MODIFIED="1477553425306">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482847320" ID="ID_540371941" MODIFIED="1477482852655">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_JOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482853825" ID="ID_768895720" MODIFIED="1477482859399">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_SCAN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482863977" ID="ID_1543668215" MODIFIED="1477482867271">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_NORMAL_TR
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482871858" ID="ID_11320693" MODIFIED="1477482874217">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateAbort_IBSS
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482830744" ID="ID_1572267202" MODIFIED="1477482844616">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477554271798" ID="ID_196946174" MODIFIED="1477554291990">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_SCAN
    </p>
    <p>
      AIS_STATE_ONLINE_SCAN
    </p>
    <p>
      AIS_STATE_LOOKING_FOR
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554329033" ID="ID_1076426446" MODIFIED="1477554331816">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mboxSendMsg
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477554362193" ID="ID_311556819" LINK="#ID_112483751" MODIFIED="1477554997358">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MSG_ID: <b><font color="#0000cc">MID_AIS_SCN_SCAN_REQ_V2</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477481694847" FOLDED="true" ID="ID_1548432717" MODIFIED="1477553371834">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Message Handling
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      generally request from other module.
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477481708767" ID="ID_1801478820" MODIFIED="1477481710526">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventScanDone
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481711368" ID="ID_278169892" MODIFIED="1477481717045">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventAbort
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481718024" ID="ID_192789954" MODIFIED="1477481726142">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventJoinComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481727112" ID="ID_274098967" MODIFIED="1477481732079">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmJoinCompleteAction
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481732977" ID="ID_1962306271" MODIFIED="1477481738208">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventFoundIBSSPeer
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481739161" ID="ID_1769589146" MODIFIED="1477481744135">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventRemainOnChannel
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481745033" ID="ID_1407959973" MODIFIED="1477481750248">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventCancelRemainOnChannel
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477481787754" ID="ID_510565649" MODIFIED="1477481790314">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Handling for Ad-Hoc Network
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477481791291" ID="ID_379291764" MODIFIED="1477481796753">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmCreateIBSS
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481797834" ID="ID_1553498404" MODIFIED="1477481803769">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmMergeIBSS
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477481873606" ID="ID_1458784061" MODIFIED="1477481959600">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#19982;CNM&#30340;&#20132;&#20114;&#25509;&#21475;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477481909880" ID="ID_512879723" MODIFIED="1477482024868">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventChGrant
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Handling of Incoming Mailbox Message from CNM
    </p>
    <p>
      <b>This function is invoked when CNM granted channel privilege</b>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477481969002" ID="ID_925279702" MODIFIED="1477482002332">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmReleaseCh
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Generating Outgoing Mailbox Message to CNM&#160;&#160;
    </p>
    <p>
      <b>This function is to inform CNM that channel privilege has been released</b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482107806" ID="ID_758133389" MODIFIED="1477482110221">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Event Indication
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482111375" ID="ID_561891072" MODIFIED="1477482117420">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisIndicationOfMediaStateToHost
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482118302" ID="ID_1513822876" MODIFIED="1477482124204">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisPostponedEventOfDisconnTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482128390" ID="ID_55508335" MODIFIED="1477482130701">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForJOIN
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482131687" ID="ID_7347501" MODIFIED="1477482136869">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForCreateIBSS
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482137751" ID="ID_174422105" MODIFIED="1477482142638">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForMergeIBSS
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482143543" ID="ID_1336624121" MODIFIED="1477482149062">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisValidateProbeReq
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482149552" ID="ID_115178411" MODIFIED="1477482156053">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventMgmtFrameTxDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482212658" FOLDED="true" ID="ID_1911764015" MODIFIED="1477553355922">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Disconnection Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482215362" ID="ID_699120501" MODIFIED="1477482222904">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmDisconnect
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482225394" FOLDED="true" ID="ID_1285977921" MODIFIED="1477553353938">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Event Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482237898" ID="ID_739808769" MODIFIED="1477482239521">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisBssBeaconTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482245315" ID="ID_516235715" MODIFIED="1477482246962">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisDeauthXmitComplete
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482247723" ID="ID_729780112" MODIFIED="1477482271154">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Roaming Related Event Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482272476" ID="ID_1547640600" MODIFIED="1477482278139">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventRoamingDiscovery
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482279092" ID="ID_1604579969" MODIFIED="1477482283994">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRoamingScanResultsUpdate
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482288116" ID="ID_16172397" MODIFIED="1477482290155">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRoamingDisconnectPrevAP
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482291021" ID="ID_1286115839" MODIFIED="1477482297306">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisUpdateBssInfoForRoamingAP
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477482304149" FOLDED="true" ID="ID_411145601" MODIFIED="1477553352466">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Timeout Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482310566" ID="ID_108444415" MODIFIED="1477482312108">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventBGSleepTimeOut
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482312653" ID="ID_1652347518" MODIFIED="1477482318827">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventIbssAloneTimeOut
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482319950" ID="ID_855173321" MODIFIED="1477482324811">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventJoinTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482347182" ID="ID_1804542649" MODIFIED="1477482349174">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventChannelTimeout
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482349791" ID="ID_1103620011" MODIFIED="1477482355700">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventDeauthTimeout
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477482372104" ID="ID_516326458" MODIFIED="1477482373901">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      OID/IOCTL Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482380512" ID="ID_582067968" MODIFIED="1477482382643">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482383129" ID="ID_184662158" MODIFIED="1477551489019">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmScanRequestAdv
    </p>
    <p>
      <font color="#666666">&#25195;&#25551;&#35831;&#27714;</font>
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477551697475" ID="ID_685040129" MODIFIED="1477551781948">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551795262" ID="ID_617807680" MODIFIED="1477552092904">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">P_CONNECTION_SETTINGS_T</font>
    </p>
    <p>
      <b>prConnSettings</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      connection info for this session
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551926931" ID="ID_1074124670" MODIFIED="1477551929674">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.rConnSettings
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477551798686" ID="ID_855321424" MODIFIED="1477552104264">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">P_BSS_INFO_T</font>
    </p>
    <p>
      <b>prAisBssInfo</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bss info we are interseted in
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551907058" ID="ID_250175702" MODIFIED="1477551909944">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;prAisBssInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477551805767" ID="ID_503189351" MODIFIED="1478086905061">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#666666">P_AIS_FSM_INFO_T</font>
    </p>
    <p>
      <b>prAisFsmInfo</b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS FSM info
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477551941371" ID="ID_1234071593" MODIFIED="1477551945697">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;prAisBssInfo
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552009046" ID="ID_585275497" MODIFIED="1477552017957">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAisFsmInfo-&gt;eCurrentState
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552128402" ID="ID_1492893567" MODIFIED="1477552169226">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_NORMAL_TR
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552241374" ID="ID_341758135" MODIFIED="1477552295224">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAisBssInfo-&gt;eCurrentOPMode
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552321601" ID="ID_1436421379" MODIFIED="1477552367544">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ==OP_MODE_INFRASTRUCTURE
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_897739484" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_178839207" STARTARROW="None" STARTINCLINATION="95;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477552296192" ID="ID_922496490" MODIFIED="1477552312590">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAisFsmInfo-&gt;fgIsInfraChannelFinished
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552325705" ID="ID_897739484" MODIFIED="1477552367544">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ==FALSE
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_897739484" ENDARROW="Default" ENDINCLINATION="95;0;" ID="Arrow_ID_178839207" SOURCE="ID_1436421379" STARTARROW="None" STARTINCLINATION="95;0;"/>
<node COLOR="#111111" CREATED="1477552373210" ID="ID_1289000536" LINK="#ID_424155986" MODIFIED="1477552413280">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>aisFsmInsertRequest</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552740432" ID="ID_1178139605" MODIFIED="1477552756120">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with AIS Request Type: <b><font color="#0000cc">AIS_REQUEST_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552419612" ID="ID_72037846" MODIFIED="1477552444701">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      start online scan
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552446301" ID="ID_1615969201" MODIFIED="1477552454740">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanClearScanningResult
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477552455766" ID="ID_1670181784" LINK="#ID_1572267202" MODIFIED="1477553446254">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552664670" ID="ID_400374290" MODIFIED="1477552683117">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state&#160;<b><font color="#0000cc">AIS_STATE_ONLINE_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552136755" ID="ID_1066144195" MODIFIED="1477989988522">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS_STATE_IDLE
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552538177" ID="ID_1422748046" MODIFIED="1477552601673">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      start a normal scan
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552604659" ID="ID_343938034" MODIFIED="1477552622041">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanClearScanningResult
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477552627180" ID="ID_1106320198" LINK="#ID_1572267202" MODIFIED="1477553376676">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmSteps
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477552688598" ID="ID_1814825695" MODIFIED="1477552706668">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state <b><font color="#0000cc">AIS_STATE_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477552151010" ID="ID_841361388" MODIFIED="1477552160193">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Other State
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552786794" ID="ID_659698140" LINK="#ID_424155986" MODIFIED="1477552861657">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInsertRequest
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477552801570" ID="ID_615325528" MODIFIED="1477552803495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with AIS Request Type: <b><font color="#0000cc">AIS_REQUEST_SCAN</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477482404400" ID="ID_1434431261" MODIFIED="1477829137520">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Internal State Checking
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477482411801" ID="ID_1362202807" MODIFIED="1477482413528">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmIsRequestPending
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482413905" ID="ID_430887369" MODIFIED="1477482419664">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmGetNextRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482420610" ID="ID_424155986" MODIFIED="1477482426615">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInsertRequest
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477553098829" FOLDED="true" ID="ID_245486345" MODIFIED="1477553204421">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmMemAlloc
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477553107949" ID="ID_1237715662" MODIFIED="1477553128476">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with message type: <b><font color="#0000cc">RAM_TYPE_MSG</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477553142286" ID="ID_931275561" MODIFIED="1477553198060">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      assign request type
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477553156751" ID="ID_504661177" MODIFIED="1477553200724">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      attach request into pending request list
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
</node>
<node COLOR="#111111" CREATED="1477482427585" ID="ID_1862078358" MODIFIED="1477482432767">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmFlushRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482433770" ID="ID_1188343574" MODIFIED="1477482439648">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFuncTxMgmtFrame
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482441410" ID="ID_1586178318" MODIFIED="1477482448617">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmRunEventMgmtFrameTx
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482449651" ID="ID_248498561" MODIFIED="1477482455288">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFuncValidateRxActionFrame
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477482456234" ID="ID_63423808" MODIFIED="1477482467769">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmStateSearchAction
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477290143319" ID="ID_364510901" MODIFIED="1477829168417" TEXT="SCN">
<node COLOR="#111111" CREATED="1477483035431" ID="ID_1363102828" MODIFIED="1477483041151">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      STATE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483041712" ID="ID_841627897" MODIFIED="1477483088568">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Core API
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483089674" ID="ID_1379640952" MODIFIED="1477483094335">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSteps
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556153585" ID="ID_373698948" MODIFIED="1477556158545">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_SCANNING
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556184122" ID="ID_1604388897" MODIFIED="1477556191170">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanParam-&gt;fgIsScanV2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556194252" ID="ID_544831268" MODIFIED="1477556198001">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      TRUE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556203851" ID="ID_234981231" LINK="#ID_553840708" MODIFIED="1477556246364">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnSendScanReqV2
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556207924" ID="ID_118196463" MODIFIED="1477556210721">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FALSE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556212099" ID="ID_467165703" LINK="#ID_1563304188" MODIFIED="1477556252362" TEXT="scnSendScanReq"/>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477556165819" ID="ID_1424889561" MODIFIED="1477556167624">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_IDLE
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483096481" ID="ID_662090886" MODIFIED="1477483103800">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Command Routines
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483104914" ID="ID_1563304188" MODIFIED="1477483110384">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnSendScanReq
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483111338" ID="ID_553840708" MODIFIED="1477483116576">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnSendScanReqV2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556295767" ID="ID_1237140055" MODIFIED="1477556302190">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556303415" ID="ID_721505814" MODIFIED="1477556305573">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      CMD_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556308424" ID="ID_713874291" LINK="#ID_1442064134" MODIFIED="1478249736344">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSendSetQueryCmd
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556399315" ID="ID_1957759747" MODIFIED="1477556432843">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with CMD ID: <b><font color="#0000cc">CMD_ID_SCAN_REQ_V2</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483125530" ID="ID_1246221461" MODIFIED="1477483128009">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RX Event Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483129067" ID="ID_1948356942" MODIFIED="1477483134977">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnEventScanDone
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483136099" ID="ID_721898979" MODIFIED="1477483141637">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnEventNloDone
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483153267" ID="ID_870417098" MODIFIED="1477483155849">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Message Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483162124" ID="ID_1421132781" MODIFIED="1477483163771">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgStart
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555129397" ID="ID_817452930" MODIFIED="1477555161653">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prScanInfo-&gt;eCurrentState
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555163062" ID="ID_371080413" MODIFIED="1477555168988">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_IDLE
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555221488" ID="ID_1609708153" MODIFIED="1477637234068">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prMsgHdr-&gt;eMsgId
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477555237329" ID="ID_604881773" MODIFIED="1477555324876">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ
    </p>
    <p>
      MID_BOW_SCN_SCAN_REQ
    </p>
    <p>
      MID_P2P_SCN_SCAN_REQ
    </p>
    <p>
      MID_RLM_SCN_SCAN_REQ
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555283426" ID="ID_1791561333" MODIFIED="1477555285369">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsg
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477555303691" ID="ID_605993079" MODIFIED="1477555358028">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_AIS_SCN_SCAN_REQ_V2
    </p>
    <p>
      MID_BOW_SCN_SCAN_REQ_V2
    </p>
    <p>
      MID_P2P_SCN_SCAN_REQ_V2
    </p>
    <p>
      MID_RLM_SCN_SCAN_REQ_V2
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555366654" ID="ID_621938065" LINK="#ID_29798312" MODIFIED="1477555510664">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsgV2
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477555395911" ID="ID_859121157" MODIFIED="1477637236616">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmMemFree
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      release buffer for msg
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
</node>
<node COLOR="#111111" CREATED="1477555428592" ID="ID_172917893" LINK="#ID_1379640952" MODIFIED="1477637239280">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSteps
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="down"/>
<node COLOR="#111111" CREATED="1477555438272" ID="ID_1344535439" MODIFIED="1477555773229">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      with next state: <b><font color="#0000cc">SCAN_STATE_SCANNING</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477555170055" ID="ID_1386378850" MODIFIED="1477555186301">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_STATE_SCANNING
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483164187" ID="ID_1064532520" MODIFIED="1477483170979">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483171908" ID="ID_1858236900" MODIFIED="1477483177737">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsg
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483178612" ID="ID_29798312" MODIFIED="1477556040546">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleScanMsgV2
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="stop-sign"/>
<node COLOR="#111111" CREATED="1477555625287" ID="ID_1670424581" MODIFIED="1477555669231">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      setting Scan Param: <b><font color="#0000cc">P_SCAN_PARAM_T</font></b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477555677985" ID="ID_1029943358" MODIFIED="1477555681718">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Scan Type
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555686633" ID="ID_260462458" MODIFIED="1477555690766">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Bss Index
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555691177" ID="ID_1720597950" MODIFIED="1477555698847">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID type
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555713026" ID="ID_31823836" MODIFIED="1477555716729">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID Num
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555717314" ID="ID_865993612" MODIFIED="1477555720031">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SSID
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555726802" ID="ID_1822037584" MODIFIED="1477555730824">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Scan Channel
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555741403" ID="ID_1638400406" MODIFIED="1477555746617">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Timeout Value
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477555749275" ID="ID_1473432751" MODIFIED="1477555816278">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Channel Dwell time
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1477483184908" ID="ID_333681298" MODIFIED="1477483189771">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmRemovePendingMsg
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483194565" ID="ID_1931146536" MODIFIED="1477483197925">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmNloMsgStart
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483202749" ID="ID_823266201" MODIFIED="1477483206139">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmNloMsgAbort
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483211862" ID="ID_421395313" MODIFIED="1477483215203">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmHandleNloMsg
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483237366" ID="ID_449311254" MODIFIED="1477483239766">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Message Generation
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483240799" ID="ID_1307272436" MODIFIED="1477483246340">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmGenerateScanDoneMsg
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483249415" ID="ID_823054938" MODIFIED="1477483256076">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Query for sparse channel
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483257183" ID="ID_1739087059" MODIFIED="1477483262501">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnQuerySparseChannel
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477483264375" ID="ID_619991712" MODIFIED="1477483276007">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      OID/IOCTL Handling
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477483276967" ID="ID_158068229" MODIFIED="1477483284389">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSchedScanRequest
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477483285248" ID="ID_1006944073" MODIFIED="1477483291279">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnFsmSchedScanStopRequest
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1478249682855" FOLDED="true" ID="ID_807800814" MODIFIED="1479713641818" TEXT="&#x53d1;&#x9001;CMD&#x5230;FW&#x6d41;&#x7a0b;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1477556308424" ID="ID_1442064134" MODIFIED="1477556346897">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSendSetQueryCmd
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556462093" ID="ID_837888381" MODIFIED="1477556463939">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalEnqueueCommand
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556493582" ID="ID_1603600277" MODIFIED="1477556514245">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      put command into <b><font color="#0000cc">prGlueInfo-&gt;rCmdQueue</font></b>
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1477556555633" ID="ID_874438551" MODIFIED="1478087062292">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wakeup txServiceThread
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477292973849" ID="ID_1618147985" MODIFIED="1477292975735">
=======
<node COLOR="#111111" CREATED="1477556584594" ID="ID_766634053" MODIFIED="1477556591224">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      GLUE_SET_EVENT
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
=======
<node COLOR="#111111" CREATED="1477556598546" ID="ID_1613175776" MODIFIED="1477556600367">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalSetEvent
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1477556612426" ID="ID_720557484" MODIFIED="1477556629682">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      set_bit(<font color="#0000cc"><b>GLUE_FLAG_TXREQ_BIT</b></font>, &amp;pr-&gt;ulFlag);
    </p>
  </body>
</html></richcontent>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
<node COLOR="#111111" CREATED="1477556631123" ID="ID_1158173467" LINK="#ID_1063622589" MODIFIED="1477556776357">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wake_up_interruptible(&amp;<b><font color="#0000cc">pr-&gt;waitq</font></b>);
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477293033548" ID="ID_1051847339" MODIFIED="1477303457018">
=======
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478249913726" ID="ID_1793318995" MODIFIED="1478249924708" TEXT="&#x603b;&#x7ebf;&#x63a5;&#x53e3;">
<node COLOR="#111111" CREATED="1478249925742" ID="ID_1167897569" MODIFIED="1478249927844" TEXT="USB"/>
<node COLOR="#111111" CREATED="1478249928294" ID="ID_1909585273" MODIFIED="1478249930276" TEXT="SDIO"/>
<node COLOR="#111111" CREATED="1478249930782" ID="ID_1378663722" MODIFIED="1478249933332" TEXT="PCIe"/>
</node>
</node>
<node COLOR="#990000" CREATED="1476253194484" FOLDED="true" ID="ID_1620449917" MODIFIED="1479713645736" TEXT="&#x521d;&#x59cb;&#x5316;&#x5206;&#x6790;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476253223453" ID="ID_1530955501" MODIFIED="1477646873173">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>initWlan</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Module Entry Point
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
=======
<icon BUILTIN="full-1"/>
<node COLOR="#111111" CREATED="1476416604252" ID="ID_1586351889" MODIFIED="1477477586491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanDebugInit()
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
<node COLOR="#111111" CREATED="1476416652366" ID="ID_475015037" MODIFIED="1477477586491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalInitIOBuffer();
    </p>
    <p>
      <font color="#999999">gl_kal.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Pre-allocate I/O buffer
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
</node>
=======
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
<node COLOR="#111111" CREATED="1476416733217" ID="ID_339560446" MODIFIED="1477477586491" TEXT="procInitFs">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      make a proc root directory at /proc/net/
    </p>
    <p>
      ==&gt; /proc/net/wlan
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
=======
</node>
<node COLOR="#111111" CREATED="1476416782587" ID="ID_6554090" MODIFIED="1477477586491" TEXT="wlanCreateWirelessDevice">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      for legacy wlan
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476416801739" ID="ID_1935753722" MODIFIED="1477477586491" TEXT="glP2pCreateWirelessDevice">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      for p2p
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476416982706" ID="ID_1103868742" MODIFIED="1477477586491">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glRegisterBus
    </p>
    <p>
      <font color="#999999">usb.c</font>
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477290901558" ID="ID_513386577" MODIFIED="1477290915204">
=======
<node COLOR="#111111" CREATED="1476416989538" ID="ID_267677640" MODIFIED="1477477586491">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanProbe</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
=======
<node COLOR="#111111" CREATED="1476417211338" ID="ID_1929675884" MODIFIED="1477477586491" TEXT="glBusInit">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &lt;1&gt; Initialize the IO port of the interface
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417247972" ID="ID_1280666140" MODIFIED="1477477586492">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanNetCreate</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477290963257" ID="ID_1204016248" MODIFIED="1477291163045">
=======
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &lt;2&gt; Create network device, Adapter, KalInfo, prDevHandler(netdev)
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417306533" FOLDED="true" ID="ID_1427603346" MODIFIED="1478250245442" TEXT="Set the ioaddr to HIF Info">
<node COLOR="#111111" CREATED="1476417308886" ID="ID_403063242" MODIFIED="1477477586492">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /* 4 &lt;2.5&gt; Set the ioaddr to HIF Info */
    </p>
    <p>
      prGlueInfo = (P_GLUE_INFO_T) wiphy_priv(prWdev-&gt;wiphy);
    </p>
    <p>
      gPrDev = prGlueInfo-&gt;prDevHandler;
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476417381384" ID="ID_1469202722" LINK="#ID_1359664305" MODIFIED="1477647065648" TEXT="glBusSetIrq">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Setup IRQ
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417473051" ID="ID_1654277280" MODIFIED="1479713618418" TEXT="nicpmWakeUpWiFi">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Trigger the action of switching Pwr state to drv_own
    </p>
    <p>
      prAdapter-&gt;fgIsFwOwn = TRUE --&gt; prAdapter-&gt;fgIsFwOwn = FALSE
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417517933" ID="ID_1755090457" MODIFIED="1477477586492" TEXT="glLoadNvram">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      initialize
    </p>
    <p>
      P_REG_INFO_T prRegInfo;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476417553206" ID="ID_1610062516" MODIFIED="1477477586492">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanAdapterStart
    </p>
    <p>
      <b><font color="#999999">wlan_lib.c</font></b>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      init adapter
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476697193126" ID="ID_347185733" MODIFIED="1477477586492" TEXT="&#x521d;&#x59cb;&#x5316;&#x76f8;&#x5173;&#x961f;&#x5217;">
<icon BUILTIN="full-1"/>
<node COLOR="#111111" CREATED="1476697270233" ID="ID_954325862" MODIFIED="1477477586492" TEXT="rPendingCmdQueue"/>
<node COLOR="#111111" CREATED="1476697282041" ID="ID_1232703709" MODIFIED="1477477586492" TEXT="rTxCmdQueue"/>
<node COLOR="#111111" CREATED="1476697288835" ID="ID_1261094290" MODIFIED="1477477586493" TEXT="rTxCmdDoneQueue"/>
<node COLOR="#111111" CREATED="1476697294474" ID="ID_1001539944" MODIFIED="1477477586493" TEXT="rTxP0Queue"/>
<node COLOR="#111111" CREATED="1476697299234" ID="ID_439519226" MODIFIED="1477477586493" TEXT="rTxP1Queue"/>
<node COLOR="#111111" CREATED="1476697308898" ID="ID_148509828" MODIFIED="1477477586493" TEXT="rTxPQueue">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      for (i = 0; i &lt; TX_PORT_NUM; i++)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;QUEUE_INITIALIZE(&amp;prAdapter-&gt;rTxPQueue[i]);
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476697335092" ID="ID_492671789" MODIFIED="1477477586493" TEXT="rRxQueue"/>
<node COLOR="#111111" CREATED="1476697342627" ID="ID_1188326741" MODIFIED="1477477586493" TEXT="rTxDataDoneQueue"/>
</node>
<node COLOR="#111111" CREATED="1476698228177" ID="ID_251787514" MODIFIED="1477477586493">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22522;&#30784;&#35774;&#26045;&#21021;&#22987;&#21270;
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477291113510" ID="ID_189391468" MODIFIED="1477291124444">
=======
<icon BUILTIN="full-2"/>
<node COLOR="#111111" CREATED="1476697435383" ID="ID_859212287" MODIFIED="1477477586493" TEXT="nicInitializeAdapter">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize the Adapter
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476697448720" ID="ID_221522881" MODIFIED="1477477586493" TEXT="nicInitSystemService">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize System Service (MGMT Memory pool and STA_REC)
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476698969078" FOLDED="true" ID="ID_1275113185" MODIFIED="1477477586493">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cnmMemInit</b>
    </p>
    <p>
      <font color="#999999">cnm_mem.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This function is used to initial the MGMT/MSG memory pool.
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
<node CREATED="1477291126431" ID="ID_1372399135" MODIFIED="1477291168850">
=======
<node COLOR="#111111" CREATED="1476952677776" ID="ID_1204769651" MODIFIED="1477477586493">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Management buffer pool
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<arrowlink COLOR="#ff0099" DESTINATION="ID_1204016248" ENDARROW="Default" ENDINCLINATION="98;0;" ID="Arrow_ID_677627362" STARTARROW="None" STARTINCLINATION="98;0;"/>
</node>
<node CREATED="1477291137479" ID="ID_1562519665" MODIFIED="1477291174873">
=======
<node COLOR="#111111" CREATED="1476952750504" ID="ID_867131635" MODIFIED="1477477586494">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /* Initialize Management buffer pool */
    </p>
    <p>
      prBufInfo = &amp;prAdapter-&gt;rMgtBufInfo;
    </p>
    <p>
      kalMemZero(prBufInfo, sizeof(prAdapter-&gt;rMgtBufInfo));
    </p>
    <p>
      prBufInfo-&gt;pucBuf = prAdapter-&gt;pucMgtBufCached;
    </p>
    <p>
      
    </p>
    <p>
      /* Setup available memory blocks. 1 indicates FREE */
    </p>
    <p>
      prBufInfo-&gt;rFreeBlocksBitmap = (BUF_BITMAP) BITS(0, MAX_NUM_OF_BUF_BLOCKS - 1);
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<arrowlink COLOR="#3333ff" DESTINATION="ID_769108161" ENDARROW="Default" ENDINCLINATION="99;0;" ID="Arrow_ID_855709524" STARTARROW="None" STARTINCLINATION="99;0;"/>
=======
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
</node>
<node COLOR="#111111" CREATED="1476952682350" ID="ID_1701882237" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Message buffer pool
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477291241874" ID="ID_815930803" MODIFIED="1477291244091">
=======
<node COLOR="#111111" CREATED="1476952823114" ID="ID_164532953" MODIFIED="1477477586494">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      /* Initialize Message buffer pool */
    </p>
    <p>
      prBufInfo = &amp;prAdapter-&gt;rMsgBufInfo;
    </p>
    <p>
      kalMemZero(prBufInfo, sizeof(prAdapter-&gt;rMsgBufInfo));
    </p>
    <p>
      prBufInfo-&gt;pucBuf = &amp;prAdapter-&gt;aucMsgBuf[0];
    </p>
    <p>
      
    </p>
    <p>
      /* Setup available memory blocks. 1 indicates FREE */
    </p>
    <p>
      prBufInfo-&gt;rFreeBlocksBitmap = (BUF_BITMAP) BITS(0, MAX_NUM_OF_BUF_BLOCKS - 1);
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476698976966" ID="ID_766971291" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmStaRecInit
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
<node CREATED="1477291432041" ID="ID_309507790" MODIFIED="1477291446005">
<richcontent TYPE="NODE"><html>
=======
<richcontent TYPE="NOTE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      Initialize STA Record.
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<richcontent TYPE="NOTE"><html>
=======
</node>
<node COLOR="#111111" CREATED="1476698984014" ID="ID_1555041432" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      cmdBufInitialize
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
<node CREATED="1477291475931" ID="ID_1910306294" MODIFIED="1477291478739">
<richcontent TYPE="NODE"><html>
=======
<richcontent TYPE="NOTE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      This function is used to initial the MGMT memory pool for CMD Packet.
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
<node CREATED="1477291492107" ID="ID_1044574123" MODIFIED="1477291494450">
=======
<node COLOR="#111111" CREATED="1476953071764" ID="ID_304242022" MODIFIED="1477477586494" TEXT="Tx CMD List">
<node COLOR="#111111" CREATED="1476953122541" ID="ID_1526654098" MODIFIED="1477477586494">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rFreeCmdList
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476953128222" ID="ID_1747892283" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Hif Cmd
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<node CREATED="1477291525813" ID="ID_1163722504" MODIFIED="1477291528299">
=======
<node COLOR="#111111" CREATED="1476953158815" ID="ID_497254668" MODIFIED="1477477586494">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;arHifCmdDesc[i]
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476953170519" ID="ID_761569631" MODIFIED="1477477586494">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      attach to prAdapter-&gt;rFreeCmdList
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476698990030" ID="ID_1007772870" LINK="#ID_992150334" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>mboxInitialize </b>
    </p>
<<<<<<< HEAD
  </body>
</html></richcontent>
<node CREATED="1477291696571" ID="ID_1792220868" MODIFIED="1477291699832" TEXT="remove bss">
<node CREATED="1477293766533" ID="ID_514776937" MODIFIED="1477293838169">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
=======
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
    <p>
      <font color="#999999">hem_mbox.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Mailbox Initialization
    </p>
    <p>
      Inter Component Communication
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476699005431" ID="ID_30928245" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmTimerInitialize
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This routines is called to initialize a root timer.
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
</node>
</node>
</node>
<node CREATED="1477290607236" ID="ID_1136054535" MODIFIED="1477290644783">
=======
<node COLOR="#111111" CREATED="1476953273938" ID="ID_1661580564" MODIFIED="1477477586495">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rRootTimer
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476697512825" ID="ID_234952414" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanInitFeatureOption
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Feature Options
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476697548571" ID="ID_1505068549" MODIFIED="1477477586495" TEXT="wlanCfgSetDebugLevel">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Overwrite debug level settings
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476697562499" ID="ID_1198440020" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxInitialize
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_1636214302" ENDARROW="Default" ENDINCLINATION="45;0;" ID="Arrow_ID_1270930188" STARTARROW="None" STARTINCLINATION="45;0;"/>
<icon BUILTIN="full-3"/>
</node>
<node COLOR="#111111" CREATED="1476697593284" ID="ID_1636214302" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanDefTxPowerCfg
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1636214302" ENDARROW="Default" ENDINCLINATION="45;0;" ID="Arrow_ID_1270930188" SOURCE="ID_1198440020" STARTARROW="None" STARTINCLINATION="45;0;"/>
</node>
<node COLOR="#111111" CREATED="1476697629998" ID="ID_699115737" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicRxInitialize
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Rx
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-4"/>
</node>
<node COLOR="#111111" CREATED="1476697651679" ID="ID_1159233067" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halHifSwInfoInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HIF SW info initialize
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-5"/>
</node>
<node COLOR="#111111" CREATED="1476697673639" ID="ID_764669415" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      HAL_ENABLE_FWDL
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Enable HIF cut-through to N9 mode, not visiting CR4
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-6"/>
</node>
<node COLOR="#111111" CREATED="1476697706177" ID="ID_1068859892" MODIFIED="1477477586495">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSetChipEcoInfo
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Get ECO Version
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-7"/>
</node>
<node COLOR="#111111" CREATED="1476697724257" ID="ID_511483863" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      FW/patch download
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-8"/>
<node COLOR="#111111" CREATED="1476697733721" ID="ID_1736937884" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicDisableInterrupt
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      disable interrupt, download is done by polling mode only
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-1"/>
</node>
<node COLOR="#111111" CREATED="1476697753602" ID="ID_1302411301" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicTxInitResetResource
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Tx Resource to fw download state
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-2"/>
</node>
<node COLOR="#111111" CREATED="1476697788348" ID="ID_1659241485" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanDownloadFW
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-3"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476698035948" ID="ID_1341094285" MODIFIED="1477477586496" TEXT="wlanCheckWifiFunc">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      check Wi-Fi FW asserts ready bit
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="full-9"/>
<node COLOR="#111111" CREATED="1476698524926" ID="ID_1459726847" MODIFIED="1477477586496" TEXT="wlanQueryNicResourceInformation"/>
<node COLOR="#111111" CREATED="1476698568223" ID="ID_83799896" MODIFIED="1477477586496" TEXT="NIC Capability"/>
<node COLOR="#111111" CREATED="1476698597353" ID="ID_249368489" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanUpdateBasicConfig
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      update basic configuration
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698617058" ID="ID_192010506" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanUpdateNetworkAddress
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Override network address
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698647234" ID="ID_1034773502" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicApplyNetworkAddress
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Apply Network Address
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698671811" ID="ID_38401754" MODIFIED="1477477586496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalIndicateStatusAndComplete
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      indicate disconnection as default status
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698871418" ID="ID_1605530437" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicInitMGMT
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MGMT Initialization
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1477292210277" ID="ID_1417113232" MODIFIED="1477477586497" TEXT="cnmInit">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;CNM Module - initialization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292222861" ID="ID_139601233" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      rlmFsmEventInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      RLM Module - initialization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292275776" ID="ID_1372480492" LINK="#ID_657070274" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCN Module - initialization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292288536" ID="ID_1255259297" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisFsmInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      AIS Module - intiailization
    </p>
  </body>
</html></richcontent>
<arrowlink DESTINATION="ID_444355911" ENDARROW="Default" ENDINCLINATION="94;0;" ID="Arrow_ID_58358806" STARTARROW="None" STARTINCLINATION="94;0;"/>
</node>
<node COLOR="#111111" CREATED="1477292337890" ID="ID_444355911" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      aisInitializeConnectionSettings
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_444355911" ENDARROW="Default" ENDINCLINATION="94;0;" ID="Arrow_ID_58358806" SOURCE="ID_1255259297" STARTARROW="None" STARTINCLINATION="94;0;"/>
</node>
<node COLOR="#111111" CREATED="1477292351458" ID="ID_695275792" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      roamingFsmInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Roaming Module - intiailization
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1477292396332" ID="ID_1848459893" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      swCrDebugInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Cr Debug Control
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1476698892195" ID="ID_960603798" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      nicSetAvailablePhyTypeSet
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      configure available PHY type set
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476698931276" ID="ID_838093706" MODIFIED="1477477586497">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      cnmInitDbdcSetting
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476417599680" ID="ID_1687543321" MODIFIED="1477477586498">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27880;&#20876;&#24037;&#20316;&#32447;&#31243;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476417614800" ID="ID_1917647084" MODIFIED="1477477586498">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalFreeTxMsduWorker
    </p>
    <p>
      <font color="#999999">gl_kal.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476417639802" ID="ID_83269288" MODIFIED="1477477586498" TEXT="prGlueInfo-&gt;rTxMsduFreeWork"/>
</node>
<node COLOR="#111111" CREATED="1476417622025" ID="ID_1492323085" MODIFIED="1477477586498">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      halDeAggRxPktWorker
    </p>
    <p>
      <font color="#999999">hal_api.c</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1476417652242" ID="ID_1755700096" MODIFIED="1477477586498" TEXT="prGlueInfo-&gt;rRxPktDeAggWork"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476422690264" ID="ID_860214176" MODIFIED="1477477586498" TEXT="&#x542f;&#x52a8;&#x6838;&#x5fc3;&#x7ebf;&#x7a0b;">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476422700176" ID="ID_1892295768" MODIFIED="1477477586498" TEXT="main_thread"/>
<node COLOR="#111111" CREATED="1476422718825" ID="ID_177512059" MODIFIED="1477477586498" TEXT="hif_thread"/>
<node COLOR="#111111" CREATED="1476422721193" ID="ID_829943756" MODIFIED="1477477586498" TEXT="rx_thread"/>
</node>
<node COLOR="#111111" CREATED="1476422759906" ID="ID_568514442" MODIFIED="1477477586498" TEXT="wlanDownloadBufferBin">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      this function send buffer bin EEPROB_MTxxxx.bin to FW.
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476422865510" ID="ID_1260977535" MODIFIED="1477477586498" TEXT="set mac addr">
<node COLOR="#111111" CREATED="1476422878543" ID="ID_1649714784" MODIFIED="1477477586499" TEXT="wlanoidQueryCurrentAddr"/>
</node>
<node COLOR="#111111" CREATED="1476422892007" ID="ID_1756992232" MODIFIED="1477477586499" TEXT="set HW checksum offload">
<node COLOR="#111111" CREATED="1476422894568" ID="ID_1113714161" MODIFIED="1477477586499" TEXT="wlanoidSetCSUMOffload"/>
</node>
<node COLOR="#111111" CREATED="1476422904991" ID="ID_946846497" MODIFIED="1477477586499">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanNetRegister</b>
    </p>
    <p>
      <font color="#999999">gl_init.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register the card
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423075125" ID="ID_1152436874" MODIFIED="1477477586499" TEXT="glRegisterEarlySuspend">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register early suspend callback
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423048709" ID="ID_894165059" MODIFIED="1477477586499" TEXT="wlanRegisterNotifier">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register Notifier callback
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423146528" ID="ID_1057391773" MODIFIED="1477477586499">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>procCreateFsEntry</b>
    </p>
    <p>
      <font color="#999999">gl_proc.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize /proc filesystem
    </p>
    <p>
      create items under directory /proc/net/wlan0/
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423107270" ID="ID_1149342078" MODIFIED="1477477586499">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kalMetInit
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support packet trace using met
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#ff3333" DESTINATION="ID_445354275" ENDARROW="Default" ENDINCLINATION="211;0;" ID="Arrow_ID_1081692357" STARTARROW="None" STARTINCLINATION="211;0;"/>
</node>
<node COLOR="#111111" CREATED="1476423341367" ID="ID_1735719364" MODIFIED="1477477586499" TEXT="glRegisterAmpc">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      support Bt Over Wifi
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423431842" ID="ID_718547361" LINK="#ID_343414894" MODIFIED="1478251495391" TEXT="register_set_p2p_mode_handler">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      register p2p mode handler
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" CREATED="1476423578256" ID="ID_288292819" MODIFIED="1477477586500" TEXT="kalIndicateAgpsNotify">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      CFG_SUPPORT_AGPS_ASSIST
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423623033" ID="ID_1229329642" MODIFIED="1477477586500">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>wlanFeatureToFw</b>
    </p>
    <p>
      <font color="#999999">wlan_lib.c</font>
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      This function is to send WLAN feature options to firmware
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1476423694939" ID="ID_576687482" MODIFIED="1477477586500" TEXT="chip config set">
<node COLOR="#111111" CREATED="1476423699908" ID="ID_1111808765" MODIFIED="1477477586500" TEXT="wlanCfgSetSwCtrl"/>
<node COLOR="#111111" CREATED="1476423707100" ID="ID_1536729572" MODIFIED="1477477586500" TEXT="wlanCfgSetChip"/>
<node COLOR="#111111" CREATED="1476423712372" ID="ID_764313250" MODIFIED="1477477586500" TEXT="wlanCfgSetCountryCode"/>
</node>
<node COLOR="#111111" CREATED="1476423776454" ID="ID_445354275" MODIFIED="1477477586500" TEXT="kalMetInitProcfs">
<arrowlink COLOR="#ff3333" DESTINATION="ID_76164815" ENDARROW="Default" ENDINCLINATION="30;0;" ID="Arrow_ID_875522902" STARTARROW="None" STARTINCLINATION="30;0;"/>
<linktarget COLOR="#ff3333" DESTINATION="ID_445354275" ENDARROW="Default" ENDINCLINATION="211;0;" ID="Arrow_ID_1081692357" SOURCE="ID_1149342078" STARTARROW="None" STARTINCLINATION="211;0;"/>
</node>
<node COLOR="#111111" CREATED="1476423848161" ID="ID_76164815" MODIFIED="1477477586500" TEXT="met_tag_init">
<linktarget COLOR="#ff3333" DESTINATION="ID_76164815" ENDARROW="Default" ENDINCLINATION="30;0;" ID="Arrow_ID_875522902" SOURCE="ID_445354275" STARTARROW="None" STARTINCLINATION="30;0;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476416990970" ID="ID_1025052093" MODIFIED="1477477586501" TEXT="wlanRemove"/>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1478250384439" FOLDED="true" ID="ID_1897170829" MODIFIED="1478608814396" TEXT="P2P">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1478250398623" ID="ID_1419684146" MODIFIED="1478250410517" TEXT="&#x6a21;&#x5757;&#x521d;&#x59cb;&#x5316;">
<node COLOR="#111111" CREATED="1476423431842" ID="ID_343414894" MODIFIED="1478251506761" TEXT="register_set_p2p_mode_handler">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1476423450603" ID="ID_1653732722" MODIFIED="1477477586500" TEXT="set_p2p_mode_handler">
<node COLOR="#111111" CREATED="1478251637336" ID="ID_851851524" MODIFIED="1478251646112">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetP2pMode
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478251753168" ID="ID_81523817" MODIFIED="1478251755328">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pSetMode
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478251755840" ID="ID_680975070" MODIFIED="1478251763785">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pLaunch
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478251795753" ID="ID_865660206" MODIFIED="1478251812479">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glRegisterP2P
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Register for cfg80211 for Wi-Fi Direct
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1478251974680" ID="ID_417762647" MODIFIED="1478251978077" TEXT="AP Mode">
<node COLOR="#111111" CREATED="1478251979319" ID="ID_896134631" MODIFIED="1478251985399">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      glP2pCreateWirelessDevice
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1476423468260" ID="ID_1824222508" LINK="#ID_832323817" MODIFIED="1478250507827">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>p2pNetRegister</b>
    </p>
    <p>
      <font color="#999999">gl_p2p.c</font>
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478517890931" ID="ID_86058469" MODIFIED="1478517903596">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2p_netdev_ops
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478517905611" ID="ID_823974614" MODIFIED="1478517967348">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_open
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518064880" ID="ID_23677537" MODIFIED="1478518066984">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pOpen
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478517914611" ID="ID_17229058" MODIFIED="1478517980901">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_stop
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518068840" ID="ID_1544808123" MODIFIED="1478518075047">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pStop
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478517922195" ID="ID_1827733909" MODIFIED="1478517993644">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_set_mac_address
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518077057" ID="ID_83582327" MODIFIED="1478518082575">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pSetMACAddress
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478517940803" ID="ID_714661146" MODIFIED="1478518007916">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_set_rx_mode
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MGMT Initialization
    </p>
  </body>
</html></richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1477292210277" ID="ID_1417113232" MODIFIED="1477292238072" TEXT="cnmInit">
<richcontent TYPE="NOTE"><html>
=======
<node COLOR="#111111" CREATED="1478518084017" ID="ID_489601002" MODIFIED="1478518089487">
<richcontent TYPE="NODE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      p2pSetMulticastList
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518008855" ID="ID_127827695" MODIFIED="1478518015289">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_get_stats
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<richcontent TYPE="NOTE"><html>
=======
<node COLOR="#111111" CREATED="1478518090953" ID="ID_1109049600" MODIFIED="1478518097096">
<richcontent TYPE="NODE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      p2pGetStats
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
=======
</node>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
<node COLOR="#111111" CREATED="1478518016023" ID="ID_1133793907" MODIFIED="1478518022549">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_do_ioctl
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<richcontent TYPE="NOTE"><html>
=======
<node COLOR="#111111" CREATED="1478518098618" ID="ID_1109832922" MODIFIED="1478518104239">
<richcontent TYPE="NODE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      p2pDoIOCTL
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518023071" ID="ID_264051546" MODIFIED="1478518029957">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_start_xmit
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<richcontent TYPE="NOTE"><html>
=======
<node COLOR="#111111" CREATED="1478518105529" ID="ID_515434686" MODIFIED="1478518146735">
<richcontent TYPE="NODE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      p2pHardStartXmit
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<arrowlink DESTINATION="ID_444355911" ENDARROW="Default" ENDINCLINATION="94;0;" ID="Arrow_ID_58358806" STARTARROW="None" STARTINCLINATION="94;0;"/>
=======
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
</node>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
</node>
<node COLOR="#111111" CREATED="1478518030559" ID="ID_584981575" MODIFIED="1478518036341">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_select_queue
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<linktarget COLOR="#b0b0b0" DESTINATION="ID_444355911" ENDARROW="Default" ENDINCLINATION="94;0;" ID="Arrow_ID_58358806" SOURCE="ID_1255259297" STARTARROW="None" STARTINCLINATION="94;0;"/>
</node>
<node CREATED="1477292351458" ID="ID_695275792" MODIFIED="1477292372709">
=======
<node COLOR="#111111" CREATED="1478518117290" ID="ID_1658058633" MODIFIED="1478590330796">
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanSelectQueue
    </p>
  </body>
</html></richcontent>
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      select the tx queue for current packet
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518036831" ID="ID_1475311599" MODIFIED="1478518043126">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_init
    </p>
  </body>
</html></richcontent>
<<<<<<< HEAD
<richcontent TYPE="NOTE"><html>
=======
<node COLOR="#111111" CREATED="1478518124866" ID="ID_613642086" MODIFIED="1478518126970">
<richcontent TYPE="NODE"><html>
>>>>>>> ab98506ee4b8ea762adddac4996861c35d7cd53f
  <head>
    
  </head>
  <body>
    <p>
      p2pInit
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478518051831" ID="ID_180543259" MODIFIED="1478518057904">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      .ndo_uninit
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478518128387" ID="ID_498129524" MODIFIED="1478518134129">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      p2pUninit
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478250517475" ID="ID_478695041" MODIFIED="1478250526961" TEXT="&#x5e38;&#x89c1;&#x7684;&#x4e00;&#x4e9b;&#x4fe1;&#x606f;">
<node COLOR="#111111" CREATED="1478250528068" ID="ID_196902979" MODIFIED="1478250553003">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P2P&#20840;&#23616;&#20449;&#24687;
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478250575278" ID="ID_1949353669" MODIFIED="1478250591289">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      1.&#160;prGlueInfo-&gt;prAdapter-&gt;<b>rP2PNetRegState</b>
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478250636911" ID="ID_1614655518" MODIFIED="1478250748669">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      2. prGlueInfo-&gt;prP2PInfo[0]-&gt;<b>prDevHandler</b>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478250653784" ID="ID_1849229208" MODIFIED="1478250673011">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      only first p2p have this devhandler
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1478250761436" ID="ID_1523363705" MODIFIED="1478250774875">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      array: gPrP2pDev
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1478597113742" ID="ID_1827615105" MODIFIED="1478597120797" TEXT="FSM">
<node COLOR="#111111" CREATED="1478597121838" ID="ID_1132188160" MODIFIED="1478597132250">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P2P Dev FSM
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1478597155150" ID="ID_1463140404" MODIFIED="1478597169575">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      prAdapter-&gt;rWifiVar.prP2pDevFsmInfo --&gt; P_P2P_DEV_FSM_INFO_T
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node COLOR="#111111" CREATED="1478597133062" ID="ID_1295590292" MODIFIED="1478597138765">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      P2P Role FSM
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1478249000541" ID="ID_1132934865" MODIFIED="1478249007110">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20869;&#23384;&#31649;&#29702;
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" CREATED="1479713652657" ID="ID_1480646121" MODIFIED="1479713663697" TEXT="communication path">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1479713666105" ID="ID_1047064150" MODIFIED="1479713670007" TEXT="control path">
<node COLOR="#111111" CREATED="1479716510591" ID="ID_486355226" MODIFIED="1479717169027">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cfg80211_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">mtk_p2p_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717275911" ID="ID_1193451546" MODIFIED="1479717279966" TEXT="p2p0"/>
<node COLOR="#111111" CREATED="1479717280976" ID="ID_882374824" MODIFIED="1479717282630" TEXT="ap0"/>
</node>
<node COLOR="#111111" CREATED="1479716759292" ID="ID_218382416" MODIFIED="1479717194565">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>cfg80211_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">mtk_wlan_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717285304" ID="ID_1913751672" MODIFIED="1479717288053" TEXT="wlan0"/>
</node>
</node>
<node COLOR="#111111" CREATED="1479713670553" ID="ID_735877256" MODIFIED="1479713672959" TEXT="data path">
<node COLOR="#111111" CREATED="1479713687161" ID="ID_128861795" MODIFIED="1479717235956">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct net_device_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">wlan_netdev_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717294783" ID="ID_995363075" MODIFIED="1479717297830" TEXT="wlan0"/>
</node>
<node COLOR="#111111" CREATED="1479713690625" ID="ID_1609941262" MODIFIED="1479717265642">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b>struct net_device_ops</b>
    </p>
    <p>
      <font size="4" color="#666666">p2p_netdev_ops</font>
    </p>
  </body>
</html></richcontent>
<node COLOR="#111111" CREATED="1479717304536" ID="ID_1398572849" MODIFIED="1479717307589" TEXT="p2p0"/>
<node COLOR="#111111" CREATED="1479717308048" ID="ID_1869597694" MODIFIED="1479717310069" TEXT="ap0"/>
</node>
</node>
</node>
<node COLOR="#990000" CREATED="1480588887053" ID="ID_159944655" MODIFIED="1480588894818" TEXT="&#x8fde;&#x63a5;AP&#x7684;&#x6d41;&#x7a0b;">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1480588895852" ID="ID_796282843" MODIFIED="1480588900470">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mtk_cfg80211_connect
    </p>
  </body>
</html>
</richcontent>
<node COLOR="#111111" CREATED="1480589062637" ID="ID_476434965" MODIFIED="1480589064755">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetInfrastructureMode
    </p>
  </body>
</html>
</richcontent>
</node>
<node COLOR="#111111" CREATED="1480589065234" ID="ID_1857379278" MODIFIED="1480589097963">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetAuthMode
    </p>
  </body>
</html>
</richcontent>
</node>
<node COLOR="#111111" CREATED="1480589098851" ID="ID_1037202621" MODIFIED="1480589110418">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetEncryptionStatus
    </p>
  </body>
</html>
</richcontent>
</node>
<node COLOR="#111111" CREATED="1480589110835" ID="ID_424439526" MODIFIED="1480589136065">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wlanoidSetConnect
    </p>
  </body>
</html>
</richcontent>
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" CREATED="1480592151569" ID="ID_795076073" LINK="#ID_1468307456" MODIFIED="1480592370010">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      MID_OID_AIS_FSM_JOIN_REQ
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#00b439" CREATED="1474869459380" ID="ID_45824846" MODIFIED="1477477586506" TEXT="iw&#x6e90;&#x7801;&#x5206;&#x6790;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" CREATED="1474869234260" FOLDED="true" ID="ID_800856779" MODIFIED="1477636712974" POSITION="right" TEXT="&#x57fa;&#x7840;&#x7406;&#x8bba;&#x90e8;&#x5206;">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" CREATED="1474869311401" ID="ID_1282649042" MODIFIED="1477477586509" TEXT="&#x65e0;&#x7ebf;&#x6743;&#x5a01;&#x6307;&#x5357;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<icon BUILTIN="button_ok"/>
</node>
<node COLOR="#00b439" CREATED="1474869289572" ID="ID_1890748931" MODIFIED="1477477586510" TEXT="CWNA">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<icon BUILTIN="button_ok"/>
</node>
<node COLOR="#00b439" CREATED="1474869338484" ID="ID_1742793932" MODIFIED="1477477586510" TEXT="CWAP">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869349739" ID="ID_154055323" MODIFIED="1477477586510" TEXT="CWSP">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869358793" ID="ID_548821793" MODIFIED="1477477586513" TEXT="&#x6570;&#x636e;&#x901a;&#x4fe1;&#x4e0e;&#x7f51;&#x7edc;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" CREATED="1474869557131" ID="ID_1733880194" MODIFIED="1477477586517" TEXT="&#x6df1;&#x5165;&#x7406;&#x89e3;Android&#xff1a;Wi-Fi&#x3001;NFC&#x548c;GPS&#x5377;&#x9605;&#x8bfb;&#x8ba1;&#x5212;  ">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1476424139044" ID="ID_472615066" MODIFIED="1477477586518" TEXT="Netd">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1476425820634" ID="ID_847005000" MODIFIED="1477477586518" TEXT="&#x91cd;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node COLOR="#111111" CREATED="1476425830016" ID="ID_14922198" MODIFIED="1477477586519">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font color="#0000ff">CommandListener</font></b>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#3333ff" DESTINATION="ID_14922198" ENDARROW="Default" ENDINCLINATION="-547;0;" ID="Arrow_ID_974328704" SOURCE="ID_1044616497" STARTARROW="None" STARTINCLINATION="-32;1;"/>
</node>
<node COLOR="#111111" CREATED="1476425852041" ID="ID_1070680332" MODIFIED="1477477586520">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#ff0033"><b>NetlinkManager</b></font>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#ff3333" DESTINATION="ID_1070680332" ENDARROW="Default" ENDINCLINATION="-68;14;" ID="Arrow_ID_1933587597" SOURCE="ID_1259682212" STARTARROW="None" STARTINCLINATION="-168;14;"/>
</node>
<node COLOR="#111111" CREATED="1476425868794" ID="ID_1456582559" MODIFIED="1477477586521">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#00ff00"><b>DnsProxyListener</b></font>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#33ff00" DESTINATION="ID_1456582559" ENDARROW="Default" ENDINCLINATION="-15;12;" ID="Arrow_ID_1468996679" SOURCE="ID_701075544" STARTARROW="None" STARTINCLINATION="-339;40;"/>
</node>
<node COLOR="#111111" CREATED="1476425875322" ID="ID_760140278" MODIFIED="1477477586521">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <b><font color="#999900">FwmarkServer</font></b>
    </p>
  </body>
</html></richcontent>
<linktarget COLOR="#666600" DESTINATION="ID_760140278" ENDARROW="Default" ENDINCLINATION="-11;25;" ID="Arrow_ID_1665500152" SOURCE="ID_1162899669" STARTARROW="None" STARTINCLINATION="-192;63;"/>
</node>
</node>
<node COLOR="#111111" CREATED="1476425800583" ID="ID_20267605" MODIFIED="1477477586522" TEXT="&#x6e90;&#x7801;&#x5206;&#x6790;">
<node COLOR="#111111" CREATED="1476425890330" ID="ID_1067223112" MODIFIED="1477477586522" TEXT="&#x5165;&#x53e3;&#x51fd;&#x6570;main()">
<node COLOR="#111111" CREATED="1476425902994" ID="ID_1259682212" MODIFIED="1477477586522">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#ff0033">&#21551;&#21160;NetlinkManager</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#ff3333" DESTINATION="ID_1070680332" ENDARROW="Default" ENDINCLINATION="-68;14;" ID="Arrow_ID_1933587597" STARTARROW="None" STARTINCLINATION="-168;14;"/>
<icon BUILTIN="full-1"/>
</node>
<node COLOR="#111111" CREATED="1476426005134" ID="ID_1044616497" MODIFIED="1477477586523">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#0000ff">&#21019;&#24314;&quot;netd&quot;&#30417;&#21548;Socket</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#3333ff" DESTINATION="ID_14922198" ENDARROW="Default" ENDINCLINATION="-547;0;" ID="Arrow_ID_974328704" STARTARROW="None" STARTINCLINATION="-32;1;"/>
<icon BUILTIN="full-2"/>
</node>
<node COLOR="#111111" CREATED="1476426061032" ID="ID_701075544" MODIFIED="1477477586524">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#00ff00">&#21019;&#24314;&quot;dnsproxyd&quot;&#30417;&#21548;Socket</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#33ff00" DESTINATION="ID_1456582559" ENDARROW="Default" ENDINCLINATION="-15;12;" ID="Arrow_ID_1468996679" STARTARROW="None" STARTINCLINATION="-339;40;"/>
<icon BUILTIN="full-3"/>
</node>
<node COLOR="#111111" CREATED="1476426290568" ID="ID_1162899669" MODIFIED="1477477586525">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font color="#999900">&#21019;&#24314;&quot;fwmarkd&quot; &#30417;&#21548;Socket</font>
    </p>
  </body>
</html></richcontent>
<arrowlink COLOR="#666600" DESTINATION="ID_760140278" ENDARROW="Default" ENDINCLINATION="-11;25;" ID="Arrow_ID_1665500152" STARTARROW="None" STARTINCLINATION="-192;63;"/>
<icon BUILTIN="full-4"/>
</node>
</node>
</node>
</node>
</node>
<node COLOR="#00b439" CREATED="1474944064418" ID="ID_387179263" MODIFIED="1477477586526" TEXT="802.11&#x534f;&#x8bae;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" CREATED="1474944072676" ID="ID_832047714" MODIFIED="1477477586526" TEXT="802.11n">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" CREATED="1474947376635" ID="ID_815124379" MODIFIED="1477477586526" TEXT="&#x7269;&#x7406;&#x5c42;&#x7684;&#x6539;&#x8fdb;">
<node COLOR="#111111" CREATED="1474944079365" ID="ID_717696542" MODIFIED="1477477586526" TEXT="MIMO">
<node COLOR="#111111" CREATED="1474944093949" ID="ID_1247657002" MODIFIED="1477477586526" TEXT="TxBF">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#24403;&#20256;&#36755;&#26041;&#25317;&#26377;&#30340;&#22825;&#32447;&#25968;&#27604;&#25509;&#25910;&#26041;&#22810;&#26102;&#65292;
    </p>
    <p>
      &#21487;&#20197;&#29992;&#22810; &#20313;&#30340;&#22825;&#32447;&#36827;&#34892;&#32858;&#38598;
    </p>
  </body>
</html></richcontent>
</node>
<node COLOR="#111111" CREATED="1474944097102" ID="ID_674180272" MODIFIED="1477477586526" TEXT="MRC">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#24403;&#20256;&#36755;&#26041;&#25317;&#26377;&#30340;&#22825;&#32447;&#25968;&#27604;&#25509;&#25910;&#26041;&#23569;&#26102;&#65292;
    </p>
    <p>
      &#25509;&#25910;&#26041;&#22810;&#20313;&#30340;&#22825;&#32447;&#21487;&#21033;&#29992;&#36215;&#26469;&#26356;&#22909;&#30340;&#25509;&#25910;&#20449;&#21495;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node COLOR="#111111" CREATED="1474947397196" ID="ID_431228921" MODIFIED="1477477586527" TEXT="MAC&#x5c42;&#x7684;&#x6539;&#x8fdb;">
<node COLOR="#111111" CREATED="1474947406540" ID="ID_193088071" MODIFIED="1477477586527" TEXT="TxOP"/>
<node COLOR="#111111" CREATED="1474945254862" ID="ID_1329506623" MODIFIED="1477477586527" TEXT="&#x5e27;&#x805a;&#x5408;">
<node COLOR="#111111" CREATED="1474945269607" ID="ID_1921327568" MODIFIED="1477477586527" TEXT="A-MSDU"/>
<node COLOR="#111111" CREATED="1474945274479" ID="ID_604253040" MODIFIED="1477477586527" TEXT="A-MPDU"/>
</node>
</node>
</node>
</node>
<node CREATED="1481466731982" ID="ID_1894333841" MODIFIED="1481466750320" TEXT="&#x5c04;&#x9891;&#x7406;&#x8bba;"/>
<node CREATED="1481466750835" ID="ID_705467405" MODIFIED="1481466755467" TEXT="&#x5929;&#x7ebf;&#x7406;&#x8bba;"/>
</node>
</node>
</map>

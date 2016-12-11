<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1474869042230" ID="ID_9369228" MODIFIED="1474869088181">
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
<node CREATED="1474869229849" ID="ID_429611080" MODIFIED="1474869282527" POSITION="right" TEXT="&#x5b9e;&#x8df5;&#x90e8;&#x5206;">
<node CREATED="1474869422572" ID="ID_1699726114" MODIFIED="1474869428038" TEXT="wpa_supplicant">
<node CREATED="1474869647029" ID="ID_295121931" MODIFIED="1474869737188" TEXT="wpa/wpa2&#x72b6;&#x6001;&#x673a;&#x4ee3;&#x7801;&#x7814;&#x7a76;">
<node CREATED="1474869661597" ID="ID_748924271" MODIFIED="1474869670500" TEXT="EAP&#x6846;&#x67b6;"/>
<node CREATED="1474869671203" ID="ID_1430625748" MODIFIED="1474869680630" TEXT="EAPOL&#x72b6;&#x6001;&#x673a;&#x6846;&#x67b6;"/>
<node CREATED="1474869681604" ID="ID_95119704" MODIFIED="1474869693605" TEXT="WPS&#x72b6;&#x6001;&#x673a;"/>
</node>
<node CREATED="1474869703397" ID="ID_1571133533" MODIFIED="1474869717701" TEXT="wpa_supplicant&#x5168;&#x5c40;&#x72b6;&#x6001;&#x673a;&#x7814;&#x7a76;"/>
</node>
<node CREATED="1474869430952" ID="ID_1927977658" MODIFIED="1476416298080" TEXT="mac80211">
<node CREATED="1474869622475" FOLDED="true" ID="ID_912733262" MODIFIED="1477303350122" TEXT="mac80211_hwsim&#x6e90;&#x7801;&#x5206;&#x6790;">
<node CREATED="1476412277962" ID="ID_1065456441" MODIFIED="1476415733915" TEXT="&#x4e3b;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node CREATED="1476413044373" ID="ID_1058027468" MODIFIED="1476415751164" TEXT="struct mac80211_hwsim_data">
<linktarget COLOR="#ff3333" DESTINATION="ID_1058027468" ENDARROW="Default" ENDINCLINATION="-214;-230;" ID="Arrow_ID_452271799" SOURCE="ID_643930094" STARTARROW="None" STARTINCLINATION="102;-88;"/>
<node CREATED="1476413054677" ID="ID_250182291" MODIFIED="1476413249592">
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
<node CREATED="1476415402185" ID="ID_1844829092" MODIFIED="1476415540078" TEXT="struct ieee80211_hw">
<node CREATED="1476415484548" ID="ID_643930094" MODIFIED="1476415566489" TEXT="void *priv">
<arrowlink COLOR="#ff3333" DESTINATION="ID_1058027468" ENDARROW="Default" ENDINCLINATION="-214;-230;" ID="Arrow_ID_452271799" STARTARROW="None" STARTINCLINATION="102;-88;"/>
</node>
</node>
</node>
<node CREATED="1476413095695" ID="ID_917629506" MODIFIED="1476413271462">
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
<node CREATED="1476413114759" ID="ID_1533289128" MODIFIED="1476413268875" TEXT="channels_2ghz">
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
<node CREATED="1476413097343" ID="ID_1577824164" MODIFIED="1476413343300">
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
<node CREATED="1476413343296" ID="ID_1397592854" MODIFIED="1476413384019">
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
<node CREATED="1476414241848" ID="ID_963803637" MODIFIED="1476414274972" TEXT="if_combination">
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
<node CREATED="1476414280865" ID="ID_1459302242" MODIFIED="1476414292479" TEXT="addresses">
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
<node CREATED="1476414304938" ID="ID_1447085398" MODIFIED="1476414314065" TEXT="regd">
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
<node CREATED="1476414347828" ID="ID_1593356246" MODIFIED="1476414356757" TEXT="hw_scan_request">
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
<node CREATED="1476414362828" ID="ID_60716343" MODIFIED="1476414390559" TEXT="hw_scan_vif">
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
<node CREATED="1476414443540" ID="ID_1665774938" MODIFIED="1476414452074" TEXT="channel">
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
<node CREATED="1476414470929" ID="ID_998036270" MODIFIED="1476414472093" TEXT="rx_filter"/>
<node CREATED="1476415620052" ID="ID_611421707" MODIFIED="1476415702872" TEXT="pending">
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
<node CREATED="1476414515074" ID="ID_1519967614" MODIFIED="1476414526034" TEXT="Stats">
<node CREATED="1476414527363" ID="ID_144152733" MODIFIED="1476414533951" TEXT="tx_pkts"/>
<node CREATED="1476414539011" ID="ID_1052431136" MODIFIED="1476414540384" TEXT="rx_pkts"/>
<node CREATED="1476414547651" ID="ID_892018179" MODIFIED="1476414548680" TEXT="tx_bytes"/>
<node CREATED="1476414554547" ID="ID_1915509624" MODIFIED="1476414555512" TEXT="rx_bytes"/>
<node CREATED="1476414561043" ID="ID_1206183439" MODIFIED="1476414562112" TEXT="tx_dropped"/>
<node CREATED="1476414567003" ID="ID_1733191458" MODIFIED="1476414568380" TEXT="tx_failed"/>
</node>
</node>
<node CREATED="1476414751866" ID="ID_790351648" MODIFIED="1476414754071" TEXT="struct hwsim_new_radio_params ">
<node CREATED="1476414777170" ID="ID_1764052366" MODIFIED="1476414782544" TEXT="channels"/>
<node CREATED="1476414783019" ID="ID_1493793144" MODIFIED="1476414788817" TEXT="reg_alpha2"/>
<node CREATED="1476414789347" ID="ID_1509155196" MODIFIED="1476414807669" TEXT="regd">
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
<node CREATED="1476414814828" ID="ID_86536830" MODIFIED="1476414815738" TEXT="reg_strict"/>
<node CREATED="1476414816188" ID="ID_1955591649" MODIFIED="1476414886734" TEXT="p2p_device">
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
<node CREATED="1476414823780" ID="ID_1041874000" MODIFIED="1476415179762" TEXT="use_chanctx">
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
<node CREATED="1476414830189" ID="ID_1332749665" MODIFIED="1476414837162" TEXT="destroy_on_close"/>
<node CREATED="1476414842725" ID="ID_1719598725" MODIFIED="1476414843634" TEXT="hwname"/>
<node CREATED="1476414848814" ID="ID_406619918" MODIFIED="1476414850472" TEXT="no_vif"/>
</node>
<node CREATED="1476415928069" ID="ID_468572009" MODIFIED="1476415929919" TEXT="struct hwsim_vif_priv"/>
</node>
<node CREATED="1476412360197" ID="ID_15260927" MODIFIED="1476412368517">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27169;&#22359;&#21442;&#25968;
    </p>
  </body>
</html></richcontent>
<node CREATED="1476412377630" ID="ID_678225509" MODIFIED="1476412420470" TEXT="radios">
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
<node CREATED="1476412395301" ID="ID_725201060" MODIFIED="1476412412395">
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
<node CREATED="1476412422327" ID="ID_946638314" MODIFIED="1476412446199">
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
<node CREATED="1476412459696" ID="ID_708208550" MODIFIED="1476412470296">
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
<node CREATED="1476412471473" ID="ID_1057188484" MODIFIED="1476412494137">
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
<node CREATED="1476412284459" ID="ID_590883249" MODIFIED="1476412337052">
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
<node CREATED="1476412641495" ID="ID_1612920235" MODIFIED="1476412646204">
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
<node CREATED="1476412671536" ID="ID_1755923890" MODIFIED="1476412677936">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      mac80211_hwsim_new_radio(...)
    </p>
  </body>
</html></richcontent>
<node CREATED="1476415011315" ID="ID_805268025" MODIFIED="1476415739697" TEXT="ieee80211_alloc_hw_nm">
<node CREATED="1476415295637" FOLDED="true" ID="ID_655975456" MODIFIED="1476415745776" TEXT="private data">
<node CREATED="1476415311886" ID="ID_655321838" MODIFIED="1476415313475" TEXT="struct mac80211_hwsim_data *data;"/>
</node>
<node CREATED="1476415318574" FOLDED="true" ID="ID_214901893" MODIFIED="1476415339626" TEXT="mac80211_hwsim_ops">
<node CREATED="1476415329831" ID="ID_1198802599" MODIFIED="1476415338028" TEXT="const struct ieee80211_ops "/>
</node>
<node CREATED="1476415662546" ID="ID_222075092" MODIFIED="1476415797685">
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
<node CREATED="1476416142724" ID="ID_1447743281" MODIFIED="1476416147066" TEXT="ieee80211_hw_set(...)"/>
<node CREATED="1476416155660" ID="ID_1475728718" MODIFIED="1476416163002" TEXT="ieee80211_register_hw(...)"/>
<node CREATED="1476416245847" ID="ID_226441153" MODIFIED="1476416249539" TEXT="hwsim_mcast_new_radio(...)"/>
</node>
<node CREATED="1476412955937" ID="ID_887757595" MODIFIED="1476413021025">
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
<node CREATED="1476409717890" FOLDED="true" ID="ID_469100470" MODIFIED="1481466689408" TEXT="mac80211&#x6846;&#x67b6;&#x6e90;&#x7801;&#x5206;&#x6790;">
<node CREATED="1476410841026" ID="ID_1305653455" MODIFIED="1476410859930">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#20027;&#35201;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node CREATED="1476411827514" ID="ID_1116728788" MODIFIED="1476412151398">
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
<node CREATED="1476411858139" ID="ID_132587234" MODIFIED="1476411877618">
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
<node CREATED="1476411879540" FOLDED="true" ID="ID_1613258345" MODIFIED="1476412051740">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct net_device *dev;
    </p>
  </body>
</html></richcontent>
<node CREATED="1476411404642" ID="ID_291977835" MODIFIED="1476412046083" TEXT="IEEE80211_DEV_TO_SUB_IF(dev)">
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
<node CREATED="1476411901004" ID="ID_1550794880" MODIFIED="1476411903369">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      struct ieee80211_local *local;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1476411915772" ID="ID_845718201" MODIFIED="1476411921187">
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
<node CREATED="1476411936085" ID="ID_1947718430" MODIFIED="1476411938530">
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
<node CREATED="1476411953734" ID="ID_1825231439" MODIFIED="1476411957477">
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
<node CREATED="1476411966126" ID="ID_737286586" MODIFIED="1476411995714">
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
<node CREATED="1476411478093" ID="ID_1807247391" MODIFIED="1476412100539">
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
<node CREATED="1476411568024" ID="ID_428216736" MODIFIED="1476411759592">
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
<node CREATED="1476411570376" ID="ID_769222651" MODIFIED="1476411595741">
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
<node CREATED="1476411596657" ID="ID_1623345853" MODIFIED="1476411602677">
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
<node CREATED="1476411612778" ID="ID_1572278424" MODIFIED="1476411621378" TEXT="void *priv;">
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
<node CREATED="1476411667213" ID="ID_1368152963" MODIFIED="1476411698869">
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
<node CREATED="1476414667334" ID="ID_545869730" MODIFIED="1476414697118">
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
</node>
</node>
<node CREATED="1476409772848" ID="ID_1660223935" MODIFIED="1476410822270">
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
<node CREATED="1476409807658" ID="ID_613038323" MODIFIED="1476416340693">
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
<node CREATED="1476409943006" ID="ID_579598150" MODIFIED="1476410531998">
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
<node CREATED="1476410049250" ID="ID_1118489610" MODIFIED="1476416054372">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node CREATED="1476410013832" ID="ID_305341745" MODIFIED="1476410106761">
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
<node CREATED="1476410067083" ID="ID_985864475" MODIFIED="1476416061572">
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
<node CREATED="1476409815889" ID="ID_319116633" MODIFIED="1476416343173">
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
<node CREATED="1476410189304" ID="ID_1025726713" MODIFIED="1476410215582">
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
<node CREATED="1476410253585" ID="ID_41202849" MODIFIED="1476416061572" TEXT="&#x76f8;&#x5173;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<arrowlink DESTINATION="ID_985864475" ENDARROW="Default" ENDINCLINATION="225;0;" ID="Arrow_ID_350388642" STARTARROW="None" STARTINCLINATION="225;0;"/>
</node>
</node>
<node CREATED="1476409827482" ID="ID_1795631311" MODIFIED="1476416347782">
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
<node CREATED="1476410460582" ID="ID_287780463" MODIFIED="1476416080349">
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
<node CREATED="1476410572125" ID="ID_1314326289" MODIFIED="1476416080349">
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
      <b>nicRxProcessMgmtPacket</b>
    </p>
  </body>
</html></richcontent>
<node CREATED="1477302988454" ID="ID_84848527" MODIFIED="1477303018289" TEXT="apfnProcessRxMgtFrame">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      register the callback function for different subtype management
    </p>
  </body>
</html></richcontent>
<node CREATED="1477303186470" ID="ID_875353768" LINK="#ID_1750226335" MODIFIED="1477303271103">
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
<node CREATED="1477303128516" ID="ID_1978593939" MODIFIED="1477303131676">
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
</node>
</node>
<node CREATED="1474869614923" ID="ID_657070274" MODIFIED="1477291610489">
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
<node CREATED="1477290659350" ID="ID_974125567" MODIFIED="1477290664468" TEXT="&#x4e24;&#x79cd;&#x60c5;&#x666f;">
<node CREATED="1477290294937" ID="ID_1084460299" MODIFIED="1477290297302" TEXT="wlan scan"/>
<node CREATED="1477290286265" ID="ID_1641378073" MODIFIED="1477290291294" TEXT="p2p scan"/>
<node CREATED="1477292109178" ID="ID_780409427" MODIFIED="1477292113098">
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
</node>
<node CREATED="1477292806051" ID="ID_950525852" MODIFIED="1477292815888" TEXT="&#x4e3b;&#x8981;&#x8fc7;&#x7a0b;">
<node CREATED="1477292818043" ID="ID_802581462" MODIFIED="1477292829108">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      scnInit
    </p>
  </body>
</html></richcontent>
<node CREATED="1477292860036" FOLDED="true" ID="ID_519645803" MODIFIED="1477293055306">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#21021;&#22987;&#21270;P_SCAN_INFO_T
    </p>
  </body>
</html></richcontent>
<node CREATED="1477292869405" ID="ID_1519321590" MODIFIED="1477292872349">
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
<node CREATED="1477292901398" FOLDED="true" ID="ID_1388995380" MODIFIED="1477293057489">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      1. &#35774;&#32622;&#24403;&#21069;&#29366;&#24577;
    </p>
  </body>
</html></richcontent>
<node CREATED="1477292933784" ID="ID_775387935" MODIFIED="1477292942670">
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
<node CREATED="1477292945162" FOLDED="true" ID="ID_192402074" MODIFIED="1477293059482">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      2. &#21021;&#22987;&#21270;&#26410;&#20915;&#28040;&#24687;&#22788;&#29702;&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
<node CREATED="1477292973849" ID="ID_1618147985" MODIFIED="1477292975735">
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
<node CREATED="1477292991953" ID="ID_281477680" MODIFIED="1477293016094">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      3. &#37325;&#32622;BSS_DESC_T&#21015;&#34920;
    </p>
  </body>
</html></richcontent>
<node CREATED="1477293033548" ID="ID_1051847339" MODIFIED="1477303457018">
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
<node CREATED="1477293036531" ID="ID_541992024" MODIFIED="1477303500499">
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
<node CREATED="1477303252296" ID="ID_1750226335" MODIFIED="1477303310425">
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
<node CREATED="1477290572027" ID="ID_111598812" MODIFIED="1477290580714">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#30456;&#20851;&#25968;&#25454;&#32467;&#26500;
    </p>
  </body>
</html></richcontent>
<node CREATED="1477290901558" ID="ID_513386577" MODIFIED="1477290915204">
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
</node>
<node CREATED="1477291055180" ID="ID_555869001" MODIFIED="1477291088357">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      used by SCN_FSM
    </p>
  </body>
</html></richcontent>
<node CREATED="1477290963257" ID="ID_1204016248" MODIFIED="1477291163045">
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
</node>
<node CREATED="1477290992209" ID="ID_769108161" MODIFIED="1477291171029">
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
<node CREATED="1477291101885" ID="ID_1614107042" MODIFIED="1477291103952">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      SCAN_INFO_T
    </p>
  </body>
</html></richcontent>
<node CREATED="1477291113510" ID="ID_189391468" MODIFIED="1477291124444">
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
</node>
<node CREATED="1477291126431" ID="ID_1372399135" MODIFIED="1477291168850">
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
<node CREATED="1477291137479" ID="ID_1562519665" MODIFIED="1477291174873">
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
</node>
<node CREATED="1477291271612" ID="ID_1189256975" MODIFIED="1477291276142">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Incoming Mailbox Messages
    </p>
  </body>
</html></richcontent>
<node CREATED="1477291241874" ID="ID_815930803" MODIFIED="1477291244091">
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
<node CREATED="1477291403345" ID="ID_722449350" MODIFIED="1477291406132">
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
<node CREATED="1477291432041" ID="ID_309507790" MODIFIED="1477291446005">
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
<node CREATED="1477291475931" ID="ID_1910306294" MODIFIED="1477291478739">
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
<node CREATED="1477291492107" ID="ID_1044574123" MODIFIED="1477291494450">
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
<node CREATED="1477291516493" ID="ID_394372055" MODIFIED="1477291518685">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Outgoing Mailbox Messages
    </p>
  </body>
</html></richcontent>
<node CREATED="1477291525813" ID="ID_1163722504" MODIFIED="1477291528299">
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
<node CREATED="1477291570654" ID="ID_1314970388" MODIFIED="1477291573096">
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
<node CREATED="1477290598949" ID="ID_473642935" MODIFIED="1477290604932">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#31574;&#30053;
    </p>
  </body>
</html></richcontent>
<node CREATED="1477291696571" ID="ID_1792220868" MODIFIED="1477291699832" TEXT="remove bss">
<node CREATED="1477293766533" ID="ID_514776937" MODIFIED="1477293838169">
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
<node CREATED="1477293839272" ID="ID_1605540210" MODIFIED="1477293858329">
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
<node CREATED="1477290607236" ID="ID_1136054535" MODIFIED="1477290644783">
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
</node>
<node CREATED="1476693591000" ID="ID_992150334" MODIFIED="1476693594000" TEXT="mbox">
<node CREATED="1476693664979" ID="ID_692923152" MODIFIED="1476693689620">
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
<node CREATED="1476693720861" ID="ID_1454704760" MODIFIED="1476693723595" TEXT="SCN"/>
<node CREATED="1476693728460" ID="ID_301344253" MODIFIED="1476693730190" TEXT="AIS">
<node CREATED="1476693783637" ID="ID_1068507575" MODIFIED="1476693886032" TEXT="MID_AIS_SAA_FSM_START">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Start Event for SAA FSM
    </p>
  </body>
</html></richcontent>
<node CREATED="1476693885977" ID="ID_106165759" MODIFIED="1476693887425" TEXT="saaFsmRunEventStart"/>
</node>
<node CREATED="1476693803586" ID="ID_1561167379" MODIFIED="1476693894466" TEXT="MID_AIS_SAA_FSM_ABORT">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      STOP Event for SAA FSM
    </p>
  </body>
</html></richcontent>
<node CREATED="1476693894460" ID="ID_966622547" MODIFIED="1476693895751" TEXT="saaFsmRunEventAbort"/>
</node>
</node>
</node>
</node>
<node CREATED="1476693910068" ID="ID_1542906064" MODIFIED="1476693912161" TEXT="FSM">
<node CREATED="1476693913846" ID="ID_1211971427" MODIFIED="1476693925711" TEXT="SAA">
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
<node CREATED="1476694135627" ID="ID_1318692252" MODIFIED="1476694138247" TEXT="AIS"/>
<node CREATED="1477290143319" ID="ID_364510901" MODIFIED="1477290166418" TEXT="SCN"/>
</node>
<node CREATED="1476253194484" ID="ID_1620449917" MODIFIED="1477292199676" TEXT="&#x521d;&#x59cb;&#x5316;&#x5206;&#x6790;">
<node CREATED="1476253223453" ID="ID_1530955501" MODIFIED="1476694284582">
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
<node CREATED="1476416604252" ID="ID_1586351889" MODIFIED="1476416628859">
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
<node CREATED="1476416652366" ID="ID_475015037" MODIFIED="1476416693657">
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
<node CREATED="1476416733217" ID="ID_339560446" MODIFIED="1476424018755" TEXT="procInitFs">
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
<node CREATED="1476416782587" ID="ID_6554090" MODIFIED="1476416833953" TEXT="wlanCreateWirelessDevice">
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
<node CREATED="1476416801739" ID="ID_1935753722" MODIFIED="1476416872087" TEXT="glP2pCreateWirelessDevice">
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
<node CREATED="1476416982706" ID="ID_1103868742" MODIFIED="1476417093003">
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
<node CREATED="1476416989538" ID="ID_267677640" MODIFIED="1476417121250">
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
<node CREATED="1476417211338" ID="ID_1929675884" MODIFIED="1476417241794" TEXT="glBusInit">
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
<node CREATED="1476417247972" ID="ID_1280666140" MODIFIED="1476423914273">
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
<node CREATED="1476417306533" FOLDED="true" ID="ID_1427603346" MODIFIED="1476423927446" TEXT="Set the ioaddr to HIF Info">
<node CREATED="1476417308886" ID="ID_403063242" MODIFIED="1476417339741">
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
<node CREATED="1476417381384" ID="ID_1469202722" MODIFIED="1476417389071" TEXT="glBusSetIrq">
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
<node CREATED="1476417473051" ID="ID_1654277280" MODIFIED="1476417504587" TEXT="nicpmWakeUpWiFi">
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
<node CREATED="1476417517933" ID="ID_1755090457" MODIFIED="1476417542217" TEXT="glLoadNvram">
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
<node CREATED="1476417553206" ID="ID_1610062516" MODIFIED="1476697202383">
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
<node CREATED="1476697193126" ID="ID_347185733" MODIFIED="1476698300203" TEXT="&#x521d;&#x59cb;&#x5316;&#x76f8;&#x5173;&#x961f;&#x5217;">
<icon BUILTIN="full-1"/>
<node CREATED="1476697270233" ID="ID_954325862" MODIFIED="1476697275999" TEXT="rPendingCmdQueue"/>
<node CREATED="1476697282041" ID="ID_1232703709" MODIFIED="1476697283287" TEXT="rTxCmdQueue"/>
<node CREATED="1476697288835" ID="ID_1261094290" MODIFIED="1476697290095" TEXT="rTxCmdDoneQueue"/>
<node CREATED="1476697294474" ID="ID_1001539944" MODIFIED="1476697295552" TEXT="rTxP0Queue"/>
<node CREATED="1476697299234" ID="ID_439519226" MODIFIED="1476697300807" TEXT="rTxP1Queue"/>
<node CREATED="1476697308898" ID="ID_148509828" MODIFIED="1476697329485" TEXT="rTxPQueue">
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
<node CREATED="1476697335092" ID="ID_492671789" MODIFIED="1476697336513" TEXT="rRxQueue"/>
<node CREATED="1476697342627" ID="ID_1188326741" MODIFIED="1476697344064" TEXT="rTxDataDoneQueue"/>
</node>
<node CREATED="1476698228177" ID="ID_251787514" MODIFIED="1476698335511">
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
<node CREATED="1476697435383" ID="ID_859212287" MODIFIED="1476698154817" TEXT="nicInitializeAdapter">
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
<node CREATED="1476697448720" ID="ID_221522881" MODIFIED="1476698500021" TEXT="nicInitSystemService">
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
<node CREATED="1476698969078" FOLDED="true" ID="ID_1275113185" MODIFIED="1476952933277">
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
<node CREATED="1476952677776" ID="ID_1204769651" MODIFIED="1476952901557">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Management buffer pool
    </p>
  </body>
</html></richcontent>
<node CREATED="1476952750504" ID="ID_867131635" MODIFIED="1476952804744">
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
<node CREATED="1476952682350" ID="ID_1701882237" MODIFIED="1476952898893">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Initialize Message buffer pool
    </p>
  </body>
</html></richcontent>
<node CREATED="1476952823114" ID="ID_164532953" MODIFIED="1476952926749">
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
<node CREATED="1476698976966" ID="ID_766971291" MODIFIED="1476953022290">
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
<node CREATED="1476698984014" ID="ID_1555041432" MODIFIED="1476953068417">
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
<node CREATED="1476953071764" ID="ID_304242022" MODIFIED="1476953116492" TEXT="Tx CMD List">
<node CREATED="1476953122541" ID="ID_1526654098" MODIFIED="1476953125566">
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
<node CREATED="1476953128222" ID="ID_1747892283" MODIFIED="1476953156231">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Hif Cmd
    </p>
  </body>
</html></richcontent>
<node CREATED="1476953158815" ID="ID_497254668" MODIFIED="1476953169733">
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
<node CREATED="1476953170519" ID="ID_761569631" MODIFIED="1476953192266">
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
<node CREATED="1476698990030" ID="ID_1007772870" LINK="#ID_992150334" MODIFIED="1477290225062">
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
<node CREATED="1476699005431" ID="ID_30928245" MODIFIED="1476953240924">
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
<node CREATED="1476953273938" ID="ID_1661580564" MODIFIED="1476953276738">
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
<node CREATED="1476697512825" ID="ID_234952414" MODIFIED="1476698154817">
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
<node CREATED="1476697548571" ID="ID_1505068549" MODIFIED="1476698154817" TEXT="wlanCfgSetDebugLevel">
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
<node CREATED="1476697562499" ID="ID_1198440020" MODIFIED="1476698358549">
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
<node CREATED="1476697593284" ID="ID_1636214302" MODIFIED="1476697605843">
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
<node CREATED="1476697629998" ID="ID_699115737" MODIFIED="1476698370269">
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
<node CREATED="1476697651679" ID="ID_1159233067" MODIFIED="1476698378670">
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
<node CREATED="1476697673639" ID="ID_764669415" MODIFIED="1476698411895">
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
<node CREATED="1476697706177" ID="ID_1068859892" MODIFIED="1476698416407">
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
<node CREATED="1476697724257" ID="ID_511483863" MODIFIED="1476698422543">
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
<node CREATED="1476697733721" ID="ID_1736937884" MODIFIED="1476697825642">
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
<node CREATED="1476697753602" ID="ID_1302411301" MODIFIED="1476697827746">
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
<node CREATED="1476697788348" ID="ID_1659241485" MODIFIED="1476697830186">
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
<node CREATED="1476698035948" ID="ID_1341094285" MODIFIED="1476698468128" TEXT="wlanCheckWifiFunc">
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
<node CREATED="1476698524926" ID="ID_1459726847" MODIFIED="1476698526379" TEXT="wlanQueryNicResourceInformation"/>
<node CREATED="1476698568223" ID="ID_83799896" MODIFIED="1476698574285" TEXT="NIC Capability"/>
<node CREATED="1476698597353" ID="ID_249368489" MODIFIED="1476698611129">
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
<node CREATED="1476698617058" ID="ID_192010506" MODIFIED="1476698627540">
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
<node CREATED="1476698647234" ID="ID_1034773502" MODIFIED="1476698657683">
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
<node CREATED="1476698671811" ID="ID_38401754" MODIFIED="1476698691454">
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
<node CREATED="1476698871418" ID="ID_1605530437" MODIFIED="1477292199690">
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
<node CREATED="1477292210277" ID="ID_1417113232" MODIFIED="1477292238072" TEXT="cnmInit">
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
<node CREATED="1477292222861" ID="ID_139601233" MODIFIED="1477292258375">
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
<node CREATED="1477292275776" ID="ID_1372480492" LINK="#ID_657070274" MODIFIED="1477292438731">
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
<node CREATED="1477292288536" ID="ID_1255259297" MODIFIED="1477292347399">
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
<node CREATED="1477292337890" ID="ID_444355911" MODIFIED="1477292347398">
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
<node CREATED="1477292351458" ID="ID_695275792" MODIFIED="1477292372709">
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
<node CREATED="1477292396332" ID="ID_1848459893" MODIFIED="1477292411157">
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
<node CREATED="1476698892195" ID="ID_960603798" MODIFIED="1476698901123">
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
<node CREATED="1476698931276" ID="ID_838093706" MODIFIED="1476698933563">
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
<node CREATED="1476417599680" ID="ID_1687543321" MODIFIED="1476417613661">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#27880;&#20876;&#24037;&#20316;&#32447;&#31243;
    </p>
  </body>
</html></richcontent>
<node CREATED="1476417614800" ID="ID_1917647084" MODIFIED="1476417673521">
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
<node CREATED="1476417639802" ID="ID_83269288" MODIFIED="1476417640799" TEXT="prGlueInfo-&gt;rTxMsduFreeWork"/>
</node>
<node CREATED="1476417622025" ID="ID_1492323085" MODIFIED="1476417693783">
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
<node CREATED="1476417652242" ID="ID_1755700096" MODIFIED="1476417653711" TEXT="prGlueInfo-&gt;rRxPktDeAggWork"/>
</node>
</node>
<node CREATED="1476422690264" ID="ID_860214176" MODIFIED="1476423945228" TEXT="&#x542f;&#x52a8;&#x6838;&#x5fc3;&#x7ebf;&#x7a0b;">
<font BOLD="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1476422700176" ID="ID_1892295768" MODIFIED="1476422709670" TEXT="main_thread"/>
<node CREATED="1476422718825" ID="ID_177512059" MODIFIED="1476422720654" TEXT="hif_thread"/>
<node CREATED="1476422721193" ID="ID_829943756" MODIFIED="1476422727606" TEXT="rx_thread"/>
</node>
<node CREATED="1476422759906" ID="ID_568514442" MODIFIED="1476422769329" TEXT="wlanDownloadBufferBin">
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
<node CREATED="1476422865510" ID="ID_1260977535" MODIFIED="1476422871971" TEXT="set mac addr">
<node CREATED="1476422878543" ID="ID_1649714784" MODIFIED="1476422879532" TEXT="wlanoidQueryCurrentAddr"/>
</node>
<node CREATED="1476422892007" ID="ID_1756992232" MODIFIED="1476422892988" TEXT="set HW checksum offload">
<node CREATED="1476422894568" ID="ID_1113714161" MODIFIED="1476422902420" TEXT="wlanoidSetCSUMOffload"/>
</node>
<node CREATED="1476422904991" ID="ID_946846497" MODIFIED="1476422988841">
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
<node CREATED="1476423075125" ID="ID_1152436874" MODIFIED="1476423087006" TEXT="glRegisterEarlySuspend">
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
<node CREATED="1476423048709" ID="ID_894165059" MODIFIED="1476423095062" TEXT="wlanRegisterNotifier">
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
<node CREATED="1476423146528" ID="ID_1057391773" MODIFIED="1476423300797">
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
<node CREATED="1476423107270" ID="ID_1149342078" MODIFIED="1476423811852">
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
<node CREATED="1476423341367" ID="ID_1735719364" MODIFIED="1476423354014" TEXT="glRegisterAmpc">
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
<node CREATED="1476423431842" FOLDED="true" ID="ID_718547361" MODIFIED="1476423577204" TEXT="register_set_p2p_mode_handler">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      register p2p mode handler
    </p>
  </body>
</html></richcontent>
<node CREATED="1476423450603" ID="ID_651230664" MODIFIED="1476423456764" TEXT="set_p2p_mode_handler">
<node CREATED="1476423468260" ID="ID_779075025" MODIFIED="1476423492499">
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
<node CREATED="1476423578256" ID="ID_288292819" MODIFIED="1476423587846" TEXT="kalIndicateAgpsNotify">
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
<node CREATED="1476423623033" ID="ID_1229329642" MODIFIED="1476423658352">
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
<node CREATED="1476423694939" ID="ID_576687482" MODIFIED="1476423698610" TEXT="chip config set">
<node CREATED="1476423699908" ID="ID_1111808765" MODIFIED="1476423706569" TEXT="wlanCfgSetSwCtrl"/>
<node CREATED="1476423707100" ID="ID_1536729572" MODIFIED="1476423711978" TEXT="wlanCfgSetChip"/>
<node CREATED="1476423712372" ID="ID_764313250" MODIFIED="1476423717346" TEXT="wlanCfgSetCountryCode"/>
</node>
<node CREATED="1476423776454" ID="ID_445354275" MODIFIED="1476423865598" TEXT="kalMetInitProcfs">
<arrowlink COLOR="#ff3333" DESTINATION="ID_76164815" ENDARROW="Default" ENDINCLINATION="30;0;" ID="Arrow_ID_875522902" STARTARROW="None" STARTINCLINATION="30;0;"/>
<linktarget COLOR="#ff3333" DESTINATION="ID_445354275" ENDARROW="Default" ENDINCLINATION="211;0;" ID="Arrow_ID_1081692357" SOURCE="ID_1149342078" STARTARROW="None" STARTINCLINATION="211;0;"/>
</node>
<node CREATED="1476423848161" ID="ID_76164815" MODIFIED="1476423861572" TEXT="met_tag_init">
<linktarget COLOR="#ff3333" DESTINATION="ID_76164815" ENDARROW="Default" ENDINCLINATION="30;0;" ID="Arrow_ID_875522902" SOURCE="ID_445354275" STARTARROW="None" STARTINCLINATION="30;0;"/>
</node>
</node>
<node CREATED="1476416990970" ID="ID_1025052093" MODIFIED="1476416996068" TEXT="wlanRemove"/>
</node>
</node>
</node>
</node>
<node CREATED="1474869459380" ID="ID_45824846" MODIFIED="1474869466753" TEXT="iw&#x6e90;&#x7801;&#x5206;&#x6790;"/>
</node>
<node CREATED="1474869234260" ID="ID_800856779" MODIFIED="1476424096064" POSITION="right" TEXT="&#x57fa;&#x7840;&#x7406;&#x8bba;&#x90e8;&#x5206;">
<node CREATED="1474869311401" ID="ID_1282649042" MODIFIED="1474869474998" TEXT="&#x65e0;&#x7ebf;&#x6743;&#x5a01;&#x6307;&#x5357;">
<icon BUILTIN="button_ok"/>
</node>
<node CREATED="1474869289572" ID="ID_1890748931" MODIFIED="1474869477907" TEXT="CWNA">
<icon BUILTIN="button_ok"/>
</node>
<node CREATED="1474869338484" ID="ID_1742793932" MODIFIED="1474869415256" TEXT="CWAP"/>
<node CREATED="1474869349739" ID="ID_154055323" MODIFIED="1474869418159" TEXT="CWSP"/>
<node CREATED="1474869358793" ID="ID_548821793" MODIFIED="1474869406677" TEXT="&#x6570;&#x636e;&#x901a;&#x4fe1;&#x4e0e;&#x7f51;&#x7edc;"/>
<node CREATED="1474869557131" ID="ID_1733880194" MODIFIED="1474869559579" TEXT="&#x6df1;&#x5165;&#x7406;&#x89e3;Android&#xff1a;Wi-Fi&#x3001;NFC&#x548c;GPS&#x5377;&#x9605;&#x8bfb;&#x8ba1;&#x5212;  ">
<node CREATED="1476424139044" ID="ID_472615066" MODIFIED="1476426618355" TEXT="Netd">
<node CREATED="1476425820634" ID="ID_847005000" MODIFIED="1476426421321" TEXT="&#x91cd;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node CREATED="1476425830016" ID="ID_14922198" MODIFIED="1476426506548">
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
<node CREATED="1476425852041" ID="ID_1070680332" MODIFIED="1476426458027">
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
<node CREATED="1476425868794" ID="ID_1456582559" MODIFIED="1476426576301">
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
<node CREATED="1476425875322" ID="ID_760140278" MODIFIED="1476426611986">
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
<node CREATED="1476425800583" ID="ID_20267605" MODIFIED="1476425811693" TEXT="&#x6e90;&#x7801;&#x5206;&#x6790;">
<node CREATED="1476425890330" ID="ID_1067223112" MODIFIED="1476426423690" TEXT="&#x5165;&#x53e3;&#x51fd;&#x6570;main()">
<node CREATED="1476425902994" ID="ID_1259682212" MODIFIED="1476426470467">
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
<node CREATED="1476426005134" ID="ID_1044616497" MODIFIED="1476426496172">
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
<node CREATED="1476426061032" ID="ID_701075544" MODIFIED="1476426581798">
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
<node CREATED="1476426290568" ID="ID_1162899669" MODIFIED="1476426598704">
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
<node CREATED="1474944064418" ID="ID_387179263" MODIFIED="1474944331656" TEXT="802.11&#x534f;&#x8bae;">
<node CREATED="1474944072676" ID="ID_832047714" MODIFIED="1474944077771" TEXT="802.11n">
<node CREATED="1474947376635" ID="ID_815124379" MODIFIED="1474947396969" TEXT="&#x7269;&#x7406;&#x5c42;&#x7684;&#x6539;&#x8fdb;">
<node CREATED="1474944079365" ID="ID_717696542" MODIFIED="1474944081930" TEXT="MIMO">
<node CREATED="1474944093949" ID="ID_1247657002" MODIFIED="1475033263662" TEXT="TxBF">
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
<node CREATED="1474944097102" ID="ID_674180272" MODIFIED="1474944246293" TEXT="MRC">
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
<node CREATED="1474947397196" ID="ID_431228921" MODIFIED="1474947404033" TEXT="MAC&#x5c42;&#x7684;&#x6539;&#x8fdb;">
<node CREATED="1474947406540" ID="ID_193088071" MODIFIED="1474947413337" TEXT="TxOP"/>
<node CREATED="1474945254862" ID="ID_1329506623" MODIFIED="1474945268213" TEXT="&#x5e27;&#x805a;&#x5408;">
<node CREATED="1474945269607" ID="ID_1921327568" MODIFIED="1474945274060" TEXT="A-MSDU"/>
<node CREATED="1474945274479" ID="ID_604253040" MODIFIED="1474945277381" TEXT="A-MPDU"/>
</node>
</node>
</node>
</node>
<node CREATED="1481466731982" ID="ID_1894333841" MODIFIED="1481466750320" TEXT="&#x5c04;&#x9891;&#x7406;&#x8bba;"/>
<node CREATED="1481466750835" ID="ID_705467405" MODIFIED="1481466755467" TEXT="&#x5929;&#x7ebf;&#x7406;&#x8bba;"/>
</node>
</node>
</map>

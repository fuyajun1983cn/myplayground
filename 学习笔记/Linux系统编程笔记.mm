<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1420871673598" ID="ID_251841499" MODIFIED="1420871716468" TEXT="Linux Programming Interface">
<node CREATED="1420871726994" ID="ID_1930354188" MODIFIED="1420871733454" POSITION="right" TEXT="Memory">
<node CREATED="1420871810849" ID="ID_563015588" MODIFIED="1420871825636" TEXT="&#x5185;&#x5b58;&#x5206;&#x914d;">
<node CREATED="1420872025069" ID="ID_658228447" MODIFIED="1420872039201" TEXT="&#x5728;&#x5806;&#x4e2d;&#x5206;&#x914d;&#x5185;&#x5b58;">
<node CREATED="1420872044221" ID="ID_93552228" MODIFIED="1420872109044">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#22312;C&#35821;&#35328;&#20013;&#19968;&#33324;&#36890;&#36807;<b><font color="#1f1ff5">malloc</font></b>&#25509;&#21475;&#20174;&#22534;&#20013;&#30003;&#35831;&#20869;&#23384;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1420872972495" ID="ID_1155121307" MODIFIED="1420873117881" TEXT="Program Break:&#x521d;&#x59cb;&#x65f6;&#xff0c;&#x5b83;&#x4f4d;&#x4e8e;&#x8fdb;&#x7a0b;&#x975e;&#x521d;&#x59cb;&#x5316;&#x6570;&#x636e;&#x90e8;&#x5206;&#x7684;&#x865a;&#x62df;&#x5730;&#x5740;&#x672b;&#x7aef;&#x3002;"/>
<node CREATED="1420873125901" ID="ID_1815441198" MODIFIED="1420873553092">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      brk()&#21644;sbrk()&#26159;&#20004;&#20010;&#35843;&#25972;Proram Break&#30340;&#25509;&#21475;&#65292;&#20854;&#20013;brk&#26159;&#19968;&#20010;&#31995;&#32479;&#35843;&#29992;&#65292;&#23427;&#25913;&#21464;&#30340;&#26159;&#24403;&#21069;Progam Break&#25351;&#21521;&#30340;&#34394;&#25311;&#22320;&#22336;&#65292;&#32780;sbrk()&#21017;&#26159;&#22522;&#20110;brk()&#20043;&#19978;&#30340;&#19968;&#20010;&#24211;&#20989;&#25968;&#12290;
    </p>
    <p>
      <font color="#54c33c">#include &lt;unistd.h&gt; </font>
    </p>
    <p>
      <b><font color="#54c33c">int brk(void * end_data_segment );</font></b>
    </p>
    <p>
      <font color="#54c33c">&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;Returns 0 on success, or &#8211;1 on error </font>
    </p>
    <p>
      <b><font color="#54c33c">void *sbrk(intptr_t increment );</font></b>
    </p>
    <p>
      <font color="#54c33c">&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;Returns previous program break on success, or (void *) &#8211;1 on error </font>
    </p>
    <p>
      <font color="#151d13">sbrk(0)&#65306;&#36820;&#22238;&#24403;&#21069;Program Break&#30340;&#20540;&#65288;&#34394;&#25311;&#22320;&#22336;&#65289;</font>
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1420873440590" ID="ID_1857312761" MODIFIED="1420873454366" TEXT="malloc&#x662f;&#x57fa;&#x4e8e;&#x4e0a;&#x8ff0;&#x4e24;&#x4e2a;&#x63a5;&#x53e3;&#x5b9e;&#x73b0;&#x7684;"/>
<node CREATED="1420873676986" ID="ID_700314886" MODIFIED="1420873697737" TEXT="free&#x91ca;&#x653e;&#x7531;malloc&#x7533;&#x8bf7;&#x7684;&#x5185;&#x5b58;"/>
<node CREATED="1420879123612" ID="ID_1438999539" MODIFIED="1420879154417" TEXT="calloc&#x7533;&#x8bf7;&#x4e00;&#x7ec4;&#x76f8;&#x540c;&#x5927;&#x5c0f;&#x7684;&#x5185;&#x5b58;&#xff0c;&#x5e76;&#x521d;&#x59cb;&#x5316;&#x4e3a;&#x96f6;"/>
</node>
<node CREATED="1420877210190" ID="ID_1886161400" MODIFIED="1420877221370" TEXT="&#x5728;&#x6808;&#x4e2d;&#x5206;&#x914d;&#x5185;&#x5b58;">
<node CREATED="1420877226508" ID="ID_1672597381" MODIFIED="1420877269999" TEXT="&#x51fd;&#x6570;alloca&#x4ece;&#x6808;&#x4e2d;&#x52a8;&#x6001;&#x5206;&#x914d;&#x5185;&#x5b58;"/>
<node CREATED="1420877279439" ID="ID_2046581" MODIFIED="1420877305167" TEXT="&#x5185;&#x5b58;&#x5728;&#x51fd;&#x6570;&#x8fd4;&#x56de;&#x540e;&#xff0c;&#x81ea;&#x52a8;&#x91ca;&#x653e;&#xff0c;&#x4e0d;&#x9700;&#x8981;&#x8c03;&#x7528;free&#x91ca;&#x653e;"/>
<node CREATED="1420877306395" ID="ID_1802413512" MODIFIED="1420877362750" TEXT="Using alloca() can be especially useful if we employ longjmp() or siglongjmp()"/>
</node>
</node>
</node>
</node>
</map>

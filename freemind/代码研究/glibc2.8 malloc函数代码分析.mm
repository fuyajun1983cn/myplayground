<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1420878577647" ID="ID_598886810" MODIFIED="1420878595721" TEXT="glibc2.8 malloc&#x51fd;&#x6570;&#x4ee3;&#x7801;&#x5206;&#x6790;">
<node CREATED="1420878604371" ID="ID_468504466" MODIFIED="1420878886705" POSITION="right" TEXT="&#x7b97;&#x6cd5;&#x6982;&#x8ff0;">
<cloud/>
<node CREATED="1420878748159" ID="ID_1177463132" MODIFIED="1420879074747" TEXT="For large (&gt;= 512 bytes) requests, it is a pure best-fit allocator,     &#xa;with ties normally decided via FIFO (i.e. least recently used).">
<icon BUILTIN="edit"/>
</node>
<node CREATED="1420878826187" ID="ID_1062016932" MODIFIED="1420879070908">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      For small (&lt;= 64 bytes by default) requests,
    </p>
    <p>
      it is a caching allocator, that maintains pools of quickly recycled chunks.
    </p>
  </body>
</html>
</richcontent>
<icon BUILTIN="edit"/>
</node>
<node CREATED="1420878964659" ID="ID_142956353" MODIFIED="1420879066861" TEXT="In between, and for combinations of large and small requests, it does     the best it can trying to meet both goals at once.">
<icon BUILTIN="edit"/>
</node>
<node CREATED="1420878970722" ID="ID_1471993016" MODIFIED="1420879077652">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      For very large requests (&gt;= 128KB by default),
    </p>
    <p>
      it relies on system memory mapping facilities,
    </p>
    <p>
      if supported.
    </p>
  </body>
</html>
</richcontent>
<icon BUILTIN="edit"/>
</node>
</node>
<node CREATED="1420879188354" ID="ID_1085753408" MODIFIED="1420879195372" POSITION="right" TEXT="&#x6807;&#x51c6;&#x63a5;&#x53e3;">
<node CREATED="1420879200264" ID="ID_938260636" MODIFIED="1420879260034" TEXT="malloc(size_t n);     &#xa;calloc(size_t n_elements, size_t element_size);     &#xa;free(void* p);     &#xa;realloc(void* p, size_t n);     &#xa;memalign(size_t alignment, size_t n);     &#xa;valloc(size_t n);     &#xa;mallinfo()     &#xa;mallopt(int parameter_number, int parameter_value)"/>
</node>
<node CREATED="1420879278224" ID="ID_1904902243" MODIFIED="1420879303634" POSITION="right" TEXT="&#x91cd;&#x8981;&#x7684;&#x6570;&#x636e;">
<node CREATED="1420879307785" ID="ID_1270587844" MODIFIED="1420879338244" TEXT="&#x652f;&#x6301;&#x6307;&#x9488;&#xff1a;4&#x6216;8&#x5b57;&#x8282;&#x7684;&#x8868;&#x793a;&#x5f62;&#x5f0f;"/>
<node CREATED="1420879353003" ID="ID_1031061785" MODIFIED="1420879390820" TEXT="size_t:4&#x6216;8&#x5b57;&#x8282;&#xff0c;&#x7531;INTERNAL_SIZE_T&#x6765;&#x63a7;&#x5236;"/>
<node CREATED="1420879416505" ID="ID_1941843803" MODIFIED="1420879476773" TEXT="&#x5bf9;&#x9f50;&#xff1a;2&#xd7;sizeof(size_t)&#xff0c;&#x53ef;&#x901a;&#x8fc7;&#x5b9a;&#x4e49;MALLOC_ALIGNMENT&#x7531;&#x8bbe;&#x7f6e;&#x4e3a;&#x5176;&#x4ed6;&#x503c;"/>
<node CREATED="1420879496728" ID="ID_1497233777" MODIFIED="1420879683203" TEXT="&#x6bcf;&#x4e2a;&#x5206;&#x914d;&#x7684;&#x5185;&#x5b58;&#x5757;&#x6700;&#x5c0f;&#x7684;&#x5f00;&#x9500;&#xff1a;4&#x6216;8&#x5b57;&#x8282;"/>
<node CREATED="1420879684003" ID="ID_108782452" MODIFIED="1420880423821">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#26368;&#23567;&#20998;&#37197;&#22823;&#23567;&#65306;4&#23383;&#33410;&#25351;&#38024;&#30340;&#35805;&#65292;&#23601;&#26159;16&#23383;&#33410;&#65292;8&#23383;&#33410;&#25351;&#38024;&#30340;&#35805;&#65292;&#23601;&#26159;24/32&#23383;&#33410;&#12290;
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1420892819579" ID="ID_1269851957" MODIFIED="1420892912157">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#26368;&#22823;&#20998;&#37197;&#22823;&#23567;&#65306;&#24403;size_t&#26159;4&#23383;&#33410;&#22823;&#23567;&#26102;&#65292;2^32-2*page_size
    </p>
    <p>
      &#24403;size_t&#26159;8&#23383;&#33410;&#22823;&#23567;&#26102;&#65292;2^64 - 2*page_size
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1420894400577" ID="ID_102828170" MODIFIED="1420894416555" POSITION="right" TEXT="&#x91cd;&#x8981;&#x6570;&#x636e;&#x7ed3;&#x6784;">
<node CREATED="1420894421921" ID="ID_680159379" MODIFIED="1420894584456" TEXT="struct malloc_chunk {    &#xa;    INTERNAL_SIZE_T      prev_size;  /* Size of previous chunk (if free).  */ &#xa;    INTERNAL_SIZE_T      size;       /* Size in bytes, including overhead. */   &#xa;    struct malloc_chunk* fd;         /* double links -- used only if free. */  &#xa;    struct malloc_chunk* bk;    /* Only used for large blocks: pointer to next larger size.  */   &#xa;    struct malloc_chunk* fd_nextsize; /* double links -- used only if free.*/&#xa;    struct malloc_chunk* bk_nextsize; &#xa;}; "/>
</node>
</node>
</map>

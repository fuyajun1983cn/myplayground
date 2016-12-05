<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1409475047734" ID="ID_313516069" MODIFIED="1409475087821" TEXT="large scale of c++ software design">
<node CREATED="1409475092021" ID="ID_950832884" MODIFIED="1409475099167" POSITION="right" TEXT="Ground Rules">
<node CREATED="1409475104316" ID="ID_1741274859" MODIFIED="1409475108130" TEXT="Major">
<node CREATED="1409475118044" ID="ID_1697301973" MODIFIED="1409475131114" TEXT="Keep class data members private"/>
<node CREATED="1409475719569" ID="ID_800381203" MODIFIED="1409475738615" TEXT="Avoid data with external linkage at file scope"/>
<node CREATED="1409476080783" ID="ID_993973007" MODIFIED="1409476143027" TEXT="Avoid free functions(except operator functions) at file scope in .h files; avoid free functions with external linkage(including operator functions) in .c files."/>
<node CREATED="1409476263935" ID="ID_1936903063" MODIFIED="1409476456042" TEXT="Avoid enumerations, typedefs, and constants at file scope in .h files. nest them into a class definition as possible as you can"/>
<node CREATED="1409476493367" ID="ID_1826066824" MODIFIED="1409476518093" TEXT="Avoid using preprocessor macros in header files except as include guards."/>
<node CREATED="1409476895068" ID="ID_1719911143" MODIFIED="1409476985843" TEXT="Only classes, structures, unions, and free operator functions should be declared at file scope in a .h file; only classes, structures, unions, and inline(member or free operator) functions should be defined at file scope in a .h file."/>
<node CREATED="1409477241840" ID="ID_844565112" MODIFIED="1409477277365" TEXT="Place a unique and predictable (internal) include guard around the contents of each header file."/>
<node CREATED="1409477753952" ID="ID_1707409747" MODIFIED="1409478244981">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Place a redundant (external) include guard around each preprocessor include directive in every header file.
    </p>
    <p>
      <font color="#df3535">Avoid placing #include directives in header files whenever it makes sense to do so.</font>
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409478858532" ID="ID_1505401962" MODIFIED="1409478891535" TEXT="The use of assert statements can help do document the assumptions you make when implementing your code."/>
</node>
<node CREATED="1409475110042" ID="ID_638595169" MODIFIED="1409475113169" TEXT="Minor">
<node CREATED="1409479041833" ID="ID_1347566904" MODIFIED="1409479071610" TEXT="Use a consistent method (such as a d_ prefix) to highlight class data members."/>
<node CREATED="1409479073330" ID="ID_605455390" MODIFIED="1409479101947" TEXT="Use a consistent method (such as an uppercase first letter) to distinguish type names."/>
<node CREATED="1409479164284" ID="ID_367929908" MODIFIED="1409479211659" TEXT="Use a consistent method (such as all uppercase with underscore) to identify immutable values such as enumerators, const data, and preprocessor constants."/>
</node>
</node>
<node CREATED="1409669782281" ID="ID_1126035250" MODIFIED="1409669792362" POSITION="right" TEXT="Phiscal Design">
<node CREATED="1409669843275" ID="ID_850398224" MODIFIED="1409669849591" TEXT="Components">
<node CREATED="1409669938876" ID="ID_1065643901" MODIFIED="1409669981496">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Logical design addresses only architectural issues; physical design address organizational issues.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409670038379" ID="ID_697859879" MODIFIED="1409670241079">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      A Component is the smallest unit of physical design.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409670242599" ID="ID_865355109" MODIFIED="1409670264278" TEXT="A component is the appropriate fundamental unit of design"/>
<node CREATED="1409670665952" ID="ID_1083256837" MODIFIED="1409670709482">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      The logical interface of a component is that which is programmatically accessible or detectable by a client.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409670552045" ID="ID_1998451936" MODIFIED="1409670630909">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      A type is Used-In-The-Interface of a component if the type is used in the public (or protected) interface of any class defined, or any free (operator) function declared at file scope in the .h file for that component.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409670877423" ID="ID_654746112" MODIFIED="1409670905063">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      The physical interface of a component is everything in its header file.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409671077005" ID="ID_1269579233" MODIFIED="1409671120848">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      A type is Used-In-The-Implementation of a component if that type is referred to by name anywhere in the component.
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1409671235754" ID="ID_782917903" MODIFIED="1409671260032">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Physical Design Rules
    </p>
  </body>
</html></richcontent>
<node CREATED="1409671301931" ID="ID_1707484442" MODIFIED="1409671306104" TEXT="Major">
<node CREATED="1409671308428" ID="ID_834435950" MODIFIED="1409671347724">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Logical entities declared within a component should not be defined outside that component.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409671537874" ID="ID_353401466" MODIFIED="1409672050804">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      The .c file of every component should include its own .h file as the first substantive line of code. In this way each component ensures that its own header file is self-sufficient with respect fo compilation.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409672298110" ID="ID_781502985" MODIFIED="1409672345374">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Avoid definitions with external linkage in the .c file of a component that are not declared explicitly in the corresponding .h file.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1409755005494" ID="ID_219197284" MODIFIED="1409755066889">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Avoid accessing a definition with external linkage in another component via a local declaration; instead, include the .h file for that component.
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1409756387612" ID="ID_1347222140" MODIFIED="1409756450121">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      A component defining a function will usually have a physical dependency on any component defining a type used by that function.
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1409757891467" ID="ID_1015986966" MODIFIED="1409757927222">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Avoid granting (long distance) friendship to a logical entity defined in another component.
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node CREATED="1409671434716" ID="ID_1768513243" MODIFIED="1409671438594" TEXT="Minor">
<node CREATED="1409671443396" ID="ID_1690368904" MODIFIED="1409671485549">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      The root names of the .c file and the .h file that comprise a component should match exactly.
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
</node>
</map>

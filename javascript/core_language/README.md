##Javascript语言核心学习笔记  
* 基本语法要素  
  变量名和关键字区分大小写。  
  支持Unicode转义，如
  ```javascript
    "café" === "caf\u00e9"
    // => true
  ```
  javascript的变量名必须以字母，下划线或$字符为开头。  

* 基本数据类型   
  **原始类型**  
  `null` 和 `undefined` 是两个特殊的原始类型值，它们不是数字，字符串或布而型。  

  **对象类型**  
  对象拥有一系列属性，这些属性都有一个名字和对应的值，这些值可以是原始类型，也可以是对象类型。   
  一个普通的JavaScript对象一个有名值垢无序集合，
  `array`，作为一种特殊的对象，代表一组被标记数字的值的有序集合。   
  函数是另一种特殊的对象，它一般关联了可执行的代码。   
  类可认为是对象类型的一个子类型。  
  另外， JavaScript还定义了另外三个有用的类:
  1. `Date`:  定义代表日期的对象。  
  2. `RegExp`: 定义代表正则表达式的类。  
  3. `Error`: 定义对象语法或运行时错误的对象。  
  JavaScript有垃圾回收器自动回收不被使用的对象所占的内存。  
  对象和数组是可修改的类型。 数字，布尔，`null`, 以及`undefined`是不可修改类型，
  字符串也是不可修改的类型。   
  JavaScript的变量是无类型的，你可以给一个变量赋任何类型的值。   
  使用`var`声明一个变量， JavaScript使用`lexical scoping`。  

  JavaScript不区分整型和浮点型，所有数值都被表示为浮点型。  
  复杂的数值运行可以通过Math对象提供的方法。   

  **数值比较**  
  `==` 判断是否相等   
  `!==` 判断是否不相等。(值是否为`true`或`false`)   
  `===` 严格相等 （可以区分`null`和`undefined`)   

  **全局对象**  
  当一个JavaScript解释器启动时，它会创建一个新的全局对象并给它一些属性赋予初始值：  
  * 全局属性如`undefined`, 'Infinity`和`NaN`  
  * 全局函数如`isNaN()`, `parseInt()`和`eval()`   
  * 构造函数如`Date(), RegExp(), String(), Object(), Array()`   
  * 全局对象如Math和JSON    

  全局变量的初始属性虽然不是保留字，但是最好将它们当作保留字看待。  
  在JavaScript的最顶层代码，可以使用关键字`this`来引用全局对象： 
  `var global = this; //Define a global variable to refer to the global object`  
  在客户端JavaScript的代码中，`Window`对象作为运行在浏览器中的所有JavaScript代码的一个全局变量而存在。  
   
  对象比较是`by reference`，而变量变量比较是`by value`，
  两个对象相同当且仅当它们指向相关的对象，
  所以对象之前的比较一般使用`===`和'!==`。   

  转换一个对象为字符串：   
  1. 先查看该对象有没有`toString()`方法，且其返回值是一个原型类型。   
  2. 如果不存在，再看有没有`valueOf()`方法，且其返回值是一个原型类型。  
  3. 如果也不存在，对会抛出`TypeError`异常。   

  转换一个对象为数字：  
  1. 如果不存在，再看有没有`valueOf()`方法，且其返回值是一个原型类型。  
  2. 先查看该对象有没有`toString()`方法，且其返回值是一个原型类型。   
  3. 如果也不存在，对会抛出`TypeError`异常。   

* 语法要点  
  **声明变量**   
  声明一个全局变量可以省略`var`关键字，但是声明一个局部变量则不能省略。   

  **代码作用域**   
  在一些编程语言中， 位于`{
      }`里面的代码块拥有自己的域，代码块内的变量对代码块外的程序不可见。
      JavaScript则不存在这种行为，它只有函数域。 

  **eval()**  
  当使用别名调用`eval()`时，会相当于在最项层执行一个独立的代码，而当直接调用`eval()`时，则相当于在本地域执行一段代码。 
  但是，当使用`use strict`指令后，不允许通过别名调用`eval()`,
  并且`eval()`只能查询或设置一个局部变量，不能定义新的变量或函数。

* strict mode  

    * In strict mode, assignments to nonwritable properties and attempts to create new properties on nonextensible objects throw a TypeError. (In non-strict mode, these attempts fail silently.)
    * In strict mode, code passed to eval() cannot declare variables or define functions in the caller’s scope as it can in non-strict mode. Instead, variable and function definitions live in a new scope created for the eval() . This scope is discarded when the eval() returns.
    * In strict mode, the arguments object (§8.3.2) in a function holds a static copy of the values passed to the function. In non-strict mode, the arguments object has “magical” behavior in which elements of the array and named function parameters both refer to the same value.
    * In strict mode, a SyntaxError is thrown if the delete operator is followed by an unqualified identifier such as a variable, function, or function parameter. (In non- strict mode, such a delete expression does nothing and evaluates to false .) In strict mode, an attempt to delete a nonconfigurable property throws a TypeError. (In non-strict mode, the attempt fails and the delete expression eval-
    * uates to false .)
    * In strict mode, it is a syntax error for an object literal to define two or more prop- erties by the same name. (In non-strict mode, no error occurs.)
    * In strict mode, it is a syntax error for a function declaration to have two or more parameters with the same name. (In non-strict mode, no error occurs.)
    * In strict mode, octal integer literals (beginning with a 0 that is not followed by an x) are not allowed. (In non-strict mode, some implementations allow octal literals.)
    * In strict mode, the identifiers eval and arguments are treated like keywords, and you are not allowed to change their value. You cannot assign a value to these iden- tifiers, declare them as variables, use them as function names, use them as function parameter names, or use them as the identifier of a catch block.
    * In strict mode, the ability to examine the call stack is restricted. argu ments.caller and arguments.callee both throw a TypeError within a strict mode function. Strict mode functions also have caller and arguments properties that throw TypeError when read. (Some implementations define these nonstandard properties on non-strict functions.)




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
   
  对象比较是`by reference`，而变量比较是`by value`，
  两个对象相同当且仅当它们指向相同的对象，
  所以对象之间的比较一般使用`===`和'!==`。   

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

* 对象  
  * 对象一般由属性以及属性值构成, 属性有三种类型： 
    1. 可写的。 
    2. 可迭代的(属性是否可以通过for/in循环返回。 
    3. 可配置的(属性是否可以被删除或更改)。  
  * 每个对象有三个关联的对象属性  
    1. prototype, 对另一个被继承的对象的引用
    2. class , 属性的类别
    3. extensible, 标识新属性是否可以加到对象中。  
  * 每个对象都有一个与之关联的第二个对象，第二个对象称为prototype,
    许多对象的属性都有继承自该prototype对象。  
    Object.prototype是一个特殊的对象，它没有与之关联的prototype对象。  
  * Object.create()  
    这是一个静态方法，  
    ```javascript
    var o1 = Object.create({x:1, y:2}); // o1 inherits properties x and y.
    var o2 = Object.create(null);  //o2 inherits no props or methods. 
    var o3 = Object.create(Object.prototype); // o3 is like {} or new Object().
    ```
  * 属性赋值的时候，会检测prototype链，以决定当前的赋值操作是否被允许。如果当前对象继承了一个只读的属性，则对该属性的赋值是被禁止的。反之，如果当前的赋值是被允许的，则会在当前的对象中创建或设置一个属性，不会改变prototype链，事实上，继承仅发生于查询属性的时候，而不是设置属性的时候，这是JavaScript的一个核心特征，它允许我们有选择性地修改继承过来的属性。针对这个规则的一个例外是，当该属性被当成setter方法的一个访问者属性时，setter方法将会被调用，而不会为当前对象创建一个新的属性。但是，setter方法也是在当前对象上进行调用，而不是定义该属性的prototype对象。  
  * 删除属性  
    删除属性仅删除对象本身的属性，并不会删除继承的属性。当对象的configurable属性为false时，delete无法删除该属性。   
  * 属性测试    
    ```javascript
    var o = { x: 1 }
    "x" in o;  // true: o has an own property "x"
    "y" in o;// false: o doesn't have a property "y"
    "toString" in o // true: o inherits a toString property

    var o = { x: 1 }
    o.hasOwnProperty("x"); // true: o has an own property x
    o.hasOwnProperty("y"); // false: o doesn't have a property y
    o.hasOwnProperty("toString"); // false: toString is an inherited property

    var o = inherit({ y: 2 });
    o.x = 1;
    o.propertyIsEnumerable("x"); // true: o has an own enumerable property x
    o.propertyIsEnumerable("y"); // false: y is inherited, not own
    Object.prototype.propertyIsEnumerable("toString"); // false: not enumerable

    var o = { x: 1 }
    o.x !== undefined; // true: o has a property x
    o.y !== undefined; // false: o doesn't have a property y
    o.toString !== undefined; // true: o inherits a toString property

    ```
  * Getters和Setters属性   
    示例：  
    ```javascript
    var o = {
        // An ordinary data property
        data_prop: value,

        // An accessor property defined as a pair of functions
        get accessor_prop() { /* function body here */ },
        set accessor_prop(value) { /* function body here */ }
    };
    ```

  * 以$开关的属性名，表明它是一个私有属性。   
  * 属性描述符  
    数据类型属性的属性描述符对象有如下名称的属性： value, writable, enumerable,
    configurable.  而访问类型属性的属性描述符对象有如下名称的属性：set,get,
    enumerable, configurable.  
  * 定义一个属性  
    Object.defineProperty()  
    ```javascript
    var o = {}; // Start with no properties at all
    // Add a nonenumerable data property x with value 1.
    Object.defineProperty(o, "x", { value : 1,
                        writable: true,
                        enumerable: false,
                        configurable: true});

    ```
    同时定义多个属性  
    ```javascript
    var p = Object.defineProperties({}, {
        x: { value: 1, writable: true, enumerable:true, configurable:true },
        y: { value: 1, writable: true, enumerable:true, configurable:true },
        r: {
        get: function() { return Math.sqrt(this.x*this.x + this.y*this.y) },
        enumerable:true,
        configurable:true
        }
    });
    ```
  * 属性改变规则   
    * If an object is not extensible, you can edit its existing own properties, but you
    cannot add new properties to it.  
    * If a property is not configurable, you cannot change its configurable or enumerable
    attributes.   
    * If an accessor property is not configurable, you cannot change its getter or setter
    method, and you cannot change it to a data property.   
    * If a data property is not configurable, you cannot change it to an accessor property.   
    * If a data property is not configurable, you cannot change its writable attribute from
    false to true , but you can change it from true to false .    
    * If a data property is not configurable and not writable, you cannot change its value.
    You can change the value of a property that is configurable but nonwritable, how-
    ever (because that would be the same as making it writable, then changing the
    value, then converting it back to nonwritable).    

* 数组
  1. 创建数组
     var arr = [2,3,4]
     var a = new Array(4)
     var a = new Array(5, 4, 3, 2, 1, "test string")

     var a1 = [,,]           //this array is [undefined, undefined, undefined]
     var a2 = new Array(2)   //this array has no values at all

  2. 数组长度
     a = [1, 2, 3]
     a.length
     Object.defineProperty(a, "length", {writable:false});  //make the length property read only.

  3. 添加和删除元素
     a = []
     a.push("zero")
     a.push("one", "two")

     a = [1, 2, 3]
     delete a[1] //delete element in index 1

     spice()
     unshift()
     shift()
     pop()

     forEach()
     var data = [1, 2, 3, 4]
     var sumOfSquares = 0;
     data.forEach(function(x) {
		       sumOfSquares += x * x;
		       });


  4. 常见的数组方法
     join()  //将数据所有的元素转换为字符串并连接起来。
     reverse()  //反转一个数组的元素顺序
     sort()  //数组元素排序， 默认是按字母顺序排序，也可以传递一个比较函数来指定排序的依据
     concat() //返回一个新的数组包含原数组和传递进来的参数
     var a = [1, 2, 3];
     a.concat([4,5], [6, 7])   //Returns [1, 2, 3, 4, 5, 6, 7]
     a.concat(4, [5, [6, 7]])  //Returns [1, 2, 3, 4, 5, [6, 7]]

     slice() //切分数组
     var a = [1, 2, 3, 4, 5]
     a.slice(0, 3)  // returns [1, 2, 3]
     a.slice(3)   // return [4, 5]
     a.slice(1, -1)  //returns [2, 3, 4]
     a.slice(-3, -2)  //returns [3]

     splice()  //通用的数组元素插入和删除函数
     对数组本身进行了修改。
     前两个参数指定要删除的元素，之后的参数指定要插入的元素。
     var a = [1,2,3,4,5];
     a.splice(2,0,'a','b');  // Returns []; a is [1,2,'a','b',3,4,5]
     a.splice(2,2,[1,2],3);  // Returns ['a','b']; a is [1,2,[1,2],3,3,4,5] 

     push()和pop():  让数组可以像栈一样工作。

     unshift()和shift(): 跟push()和pop()函数类似，只不过操作元素的位置是数组的开始处。

     toString()和toLocaleString()

  5. ECMAScript 5数组方法
     forEach()
     data.forEach(function(v, i, a) { a[i] = v + 1; });

     map()
     a = [1, 2, 3];
     b = a.map(function(x) { return x * x; }); // b is [1, 4, 9]

     传递进来的函数必须有返回值

     filter()
     传递进来的函数必须返回true或false
     a = [5, 4, 3, 2, 1];
     smallvalues = a.filter(function(x) { return x < 3 });

     every() 和 some()
     传递进来的函数必须返回true或false
     a = [1, 2, 3, 4, 5];
     a.every(function(x) { return x < 10; }) // true, all values < 10
     a.some(function(x) { return x % 2 === 0; }); // true, a has some even numbers.

     reduce(), reduceRight()
     a = [1,2,3,4,5]
     sum = a.reduce(function(x,y) { return x+y }, 0);  //sum of values
     product = a.reduce(function(x,y) { return x*y }, 1); // Product of values
     max = a.reduce(function(x,y) { return (x>y)?x:y; }); // Largest value


     indexOf(), lastIndexOf()

     Array.isArray()
     var isArray = Function.isArray || function(o) {
               return typeof o === "object" &&
		Object.prototype.toString.call(o) === "[object Array]";
	};

     
     
     



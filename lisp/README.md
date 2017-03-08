##基本数据类型   
1. 八进制数  
   `#o125`

2. 十进制数  
   `#x125`  

3. 二进制数   
   `b1011`

4. 字符L对应的字符对象   
   `#\L`  

5. 函数对象  
   `#'fn`  =>  `(function f)`

6. 复数  
   `C(5 -3)`  

7. 数组   
   `#(1 2 3)`

8. bit vector 
   `#*10110`

9. 结构体  
   `#S(structure-name slot-name1 slot-name2 ...)


backquote "`" signals that the next expression is a template that may
contain commas(,)
这种语法结构代表一个能根据模板创建一个数据结构的程序。（宏）

":" indicate which package a symbol belongs to . 
a symbol noted with a leading colon is in effect a constant that evaluates to itself.

## Scope and Extent   



##函数  
函数是Lisp语言本身以及Lisp应用程序的构建模块。用户自定义的函数与语言内建的函数具有同等地位。
事实上，Lisp语言的核心就是一系列Lisp函数，你可以自由地添加更多的Lisp函数。  

**函数数据类型**  
在Lisp中，函数是Lisp对象，Lisp支持其他语言定义的一些基本数据类型，如整形，浮点型，字符串，数组和数据结构等等。
除此之外，Lisp还将函数作为基本数据类型。这意味着，我们可以在运行时，新建一个函数对象，并将其存储到变量上，可以
将函数作为参数传递给其他函数，并将其作为结果返回。  

**函数定义**  
可以通过`defun`定义一个函数：
```lisp
>(defun double (x) (* x 2))
DOUBLE
```
这样，我们可以通过如下方式调用它：
```lisp
>(double 1)
2
```
`defun`本身是一个函数调用，它创建了一个函数对象，并将其存储变量名为传递进来的第一个参数上。我们可以通过如下方式
获取该函数对象：  
```lisp
> #'double
```
函数是Lisp的第一类对象，跟数字和字符串一样。我们可以将其作为参数传递给其他函数，将其返回并存储在一个数据结构中。
```lisp
> (eq #'double (car (list #'double)))
T
```
我们也可以不用`defun`来创建函数，跟Lisp其他对象一样，我们可以直接引用它。我们可以引用`lambda`表达式代表的一个函数。
```lisp
> #' (lambda (x) (* x 2))
```
我们通过如下方式调用它：  
```lisp
> ((lambda (x) (* x 2)) 3)
6
```
在***Common Lisp***语言中，可以同时拥有一个函数名为double的函数和其他类型的变量。
```lisp
> (setq double 2)
2
> (double double)
4
```
***Common Lisp***提供了两个函数：`symbol-value`和`symbol-function`。这两个函数分别将变量或函数映射到内部生成的符号中。
```lisp
> (symbol-value 'double)
2

> (symbol-function 'double)

```

由于函数就是一般的数据对象，可以将其存储到一个变量上。  
```lisp
> (setq x #'append)

> (eq (symbol-value 'x) (symbol-function 'append))
T
```
在`defun`内部，实质就是设置第一个参数的`symbol-function`为由剩余其他参数构建的函数。
```lisp
(defun double (x) (* x 2))

(setf (symbol-function 'double)
      #'(lambda (x) (* x 2)))
```
`defun`跟其他语言中的过程定义拥有相同的效果。但是，底层机制不一样。我们不需要`defun`来创建函数，函数也不一定
要存储为某个符号的值。在Lisp中，构建一个函数与将其关联到某个名字是两个独立的过程。  

##函数参数  
函数作为Lisp语言中的基本数据类型，我们可以将其作为参数传递给其他的函数。当然，还必须提供调用它们的方式。在Lisp中，我们
可以使用`apply`函数：  
```lisp
(+ 1 2)

(apply #'+ '(1 2))

(apply (symbol-function '+) '(1 2))

(apply #'(lambda (x y) (+ x y)) '(1 2))

```
在***Common Lisp***中，`apply`可以接受任意的参数，所以如下写法与上述造价：  
```lisp
(apply #'+ 1 '(2))
```
如果传递列表不方便的话，可以使用函数`funcall`:
```lisp
(funcall #'+ 1 2)
```

使用函数作为参数的内建函数的例子：  
```lisp
> (mapcar #'(lambda (x) (+ x 10)) '(1 2 3))
(11 12 13)

> (mapcar #'+
          '(1 2 3)
          '(10 100 1000))
(11 102 1003)
```
更多例子：  
```lisp
> (sort '(1 4 2 5 6 7 3) #'<)
(1 2 3 4 5 6 7)


> (remove-if #'evenp '(1 2 3 4 5 6 7))
(1 3 5 7)
```

**函数作为属性**  
如下定义了一个函数`behave`
```lisp
(defun behave (animal)
       (funcall (get animal 'behavior)))
```
为了添加一个动作行为，只需要为其设置一个函数类型的属性：  
```lisp
(setf (get 'dog 'behavior)
      #'(lambda () 
           (wag-tail)
           (bark)))
```

**域作用范围**  
***Common Lisp***是静态域类型的Lisp，而不是动态域类型的Lisp。
这两者之间的区别涉及到具体Lisp实现是怎样处理自由变量。
* 自由变量： 没有绑定任何值的符号。
* 绑定变量：与一个表达式绑定，通常表现形式为：函数参数，或`let`和`do`操作符绑定的变量。  

看下面的例子：  
```lisp
(let ((y 7))
     (defun scope-test (x)
          (list x y)))
```
其中，x是绑定变量，而y是一个自由变量。

在支持动态域的Lisp函数中，在执行`scope-test`时，为了找到自由变量y的值，我们往回看调用它的函数链，如果找到，
它将是函数调用过程中的y的值。如果没有找到，则取y的全局域的值。所以，如下表达式的执行结果是这样的：
```lisp
> (let ((y 5))
       (scope-test 3))
(3 5)
```
但是在只支持静态域的Lisp中，我们只看函数定义时，所处的环境中自由变量所绑定的值，如下表达式的执行结果却是这样的：  
```lisp
> (let ((y 5))
       (scope-test 3))
(3 7)
```

**闭包**  
由于***Common
Lisp***支持静态域，所以，当我们定义的函数中包含自由变量时，系统必须保存在函数定义时，这些自由变量所绑定的值。这种函数
与一系列变量绑定组合称为***闭包***。
```lisp
(defun make-adder (n)
   #'(lambda (x) (+ x n)))

>(setq add2 (make-adder 2)
       add10 (make-adder 10))
>(funcall add2 5)
7
>(funcall add10 3)
13
```

**本地函数**  
lambda表达式定义的函数没有名字，无法引用它。这样，我们无法使用lambda表达式来定义递归函数。
我们要定义一个本地函数，且其是闭包的，即此函数需要引用本地定义的变量，所以该函数不能是其他地方
通过defun定义的函数。为了支持这种需求，Lisp中定义了labels表达式，它的形式如下：
`(<name> <parameters> . <body>)`
在labels表达式内部，<name>指向一个造价于如下形式的函数：
`#'(lambda <paramters> . <body>)`

```lisp
> (labels ((inc (x) (1+ x)))
       (inc 3))
```

**Tail-Recursion**  
递归函数就是自己调用自己的函数。如下函数不属于Tail-Recursion函数：
```lisp
(defun our-length (lst)
     (if (null lst)
        0
        (1+ (our-length (cdr lst)))))

```
因为此函数从递归调用返回后，我们必须将结果传递给1+。
如下函数则属于Tail-Recursion函数：
```lisp
(defun our-find-if (fn lst)
    (if (funcall fn (car lst))
        (car lst)
        (our-find-if fn (cdr lst))))
```

**编译**  
Lisp函数可以单独或包含在整个文件中编译。 
```lisp
>(defun foo (x) ( 1+ x))
FOO
```
许多lisp的实现只是创建了一个解释过的函数。可以通过如下方式检查该函数是否已编译过：
```lisp
>(compiled-function-p #'foo)
NIL
```
我们可以通过如下方式编译一个函数： 
```lisp
> (compile 'foo)
FOO
```

**来自列表的函数**  
在早期的一些Lisp方言中，函数被表示为列表。在***Common
Lisp***中，函数不在由列表构成——好的实现会将它们编译器成本地机器码。但是，你仍然可以编写可以写程序的程序。因为
列表是编译器的输入。   
&#160; &#160; &#160; &#160;Lisp程序可以写Lisp程序的这个特性非常强大且重要。 Lisp宏非常强大。

##函数式编程



##概述  
一个类的主要特征是：成员变量，成员方法和构造方法。  
这些特征分别由`java.lang.reflect.Field`,
`java.lang.reflect.Method`和`java.lang.reflect.Constructor`。我们可以通过Class对象来查询一个类的这些成员。  

Class类提供了两对方法来获取每种特征的类型。一种允许访问一个类的公共特征（包含从父类继承过来的），另一种则允许
访问类中任何声明的公有或非公有的成员，但不包含从父类继承过来的。例子如下：  
* getFields()  返回一个类的所有公有变量，包含它从父类继承过来的。  
* getDeclaredFields() 返回一个类中的所有成员，但是不包含从父类继承过来的。  

* 对于构造函数来说，`getConstructors()`和`getDeclaredConstructors()`之间的主要区别就是是否能访问公有构造函数。  

##API快速参考  

* Field [] getFields();  
>Get all public variables, including inherited ones.

* Field getField(String name);  
Get the specified public variable, which may be inherited.

* Field [] getDeclaredFields();  
Get all public and nonpublic variables declared in this class (not including those inherited from superclasses).

* Field getDeclaredField(String name);  
Get the specified variable, public or nonpublic, declared in this class (inherited variables not considered).

* Method [] getMethods();  
Get all public methods, including inherited ones.

* Method getMethod(String name, Class ... argumentTypes);  
Get the specified public method that has arguments that match the types listed in argumentTypes. The method may be inherited.  

* Method [] getDeclaredMethods();  
Get all public and nonpublic methods declared in this class (not including those inherited from superclasses).

* Method getDeclaredMethod(String name, Class ... argumentTypes);  
Get the specified method, public or nonpublic, that has arguments that match the types listed in argumentTypes, and which is declared in this class (inherited methods not considered).

* Constructor [] getConstructors();  
Get all public constructors of this class.

* Constructor getConstructor(Class ... argumentTypes);  
Get the specified public constructor of this class that has arguments that match the types listed in argumentTypes.

* Constructor [] getDeclaredConstructors();  
 Get all public and nonpublic constructors of this class.
 
* Constructor getDeclaredConstructor(Class ... argumentTypes);  
 Get the specified constructor, public or nonpublic, that has arguments that match the types listed in argumentTypes.
 
* Class [] getDeclaredClasses();   
 Get all public and nonpublic inner classes declared within this class.
 
* Constructor [] getInterfaces();    
 Get all interfaces implemented by this class, in the order in which they are declared.

`java.lang.reflect.Proxy`类可以动态创建实现某个接口的类。  


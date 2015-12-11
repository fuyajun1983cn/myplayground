

function fun(n, o) {
    console.log(o)
    return { fun: Function(m) { return fun(m, n);}};
}

var a = fun(0); //undefined
a.fun(1);  //m = 1, n = 0,    fun(1, 0)
a.fun(2); //m = 2, n = 0, fun(2, 0)
a.fun(3); // m = 3, n = 0, fun(3, 0)

var b = fun(0).fun(1).fun(2).fun(3); //undefined,   0, 1, 2

var c = fun(0).fun(1);   //undefined, 0
c.fun(2);  //1
c.fun(3);  //1


var fn1 = function xxcanaghai {
    console.log("in : fun1<", typeof fn1, ">xxcanghai:<", typeof xxcanghai, ">");
};

console.log("out:fn1<", typeof fn1, ">xxcanghai:<", typeof xxcanghai, ">");

//Function构造函数

Function("alert(1)")

function anonymous() {
    alert(1)
}

new Function("alert(1)")
function anonymous() {
    alert(1)
}

//自执行函数
(function {alert(1);});
(function fn1 {alert(1);});

//在函数表达式内部不能访问存放当前函数的变量。
var o = {
    fn: function {
        console.log(fn);
    }
};
o.fn//ERROR

//非对象内部的函数表达式
var fn = function () {
    console.log(fn);
};
function() {
    console.log(fn);
}


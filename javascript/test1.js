#!/usr/bin/env nodejs

//java script代码
// inherit() returns a newly created object that inherits properties from the
// prototype object p. It uses the ECMAScript 5 function Object.create() if
// it is defined, and otherwise falls back to an older technique.
function inherit(p) {
    if (p == null) throw TypeError(); // p must be a non-null object
    if (Object.create)// If Object.create() is defined...
        return Object.create(p); //then just use it.
    var t = typeof p; // Otherwise do some more type checking
    if (t !== "object" && t !== "function") throw TypeError();
    function f() {};  // Define a dummy constructor function.
    f.prototype = p;// Set its prototype property to p.
    return new f(); // Use f() to create an "heir" of p.
}

//this is a factory function that return a new range object
function range(from, to) {
    var r = inherit(range.methods);
    r.from = from;
    r.to = to;

    return r;
}

// This prototype object defines methods inherited by all range objects.
range.methods = {
    includes: function(x) { return this.from <= x && x <= this.to; },
    foreach: function(f) {
        for(var x = Math.ceil(this.from); x <= this.to; x++) f(x);
    },
    toString: function() { return "(" + this.from + "..." + this.to + ")"; }
}

//test code
var r = range(1, 3);
r.includes(2);
r.foreach(console.log);
console.log(r);

console.log("=================");

function Range(from, to) {
    this.from = from;
    this.to = to;
}

Range.prototype = {
    includes: function(x) { return this.from <= x && x <= this.to; },
    foreach: function(f) {
        for(var x = Math.ceil(this.from); x <= this.to; x++) f(x);
    },
    toString: function() { return "(" + this.from + "..." + this.to + ")"; }   
};

var r2 = new Range(1, 3);
r2.includes(2);
r2.foreach(console.log);
console.log(r2);

var F = function() {}; 
var p = F.prototype;  
var c = p.constructor;
c === F;  //true

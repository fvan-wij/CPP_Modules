### Object composition, Polymorphism and Inheritance in  C++

## Object Composition

The composition of multiple single (simple) objects to form a complex object. 
In essence, a struct or class, is usually a complex object made of its simpler parts (data members of various types)
Structs and/or classes are sometimes also referred to as *composite types*.

Object composition is useful, because it allows us to create complex classes by using more easily managable parts. This reduces complexity and allows us to 
write code faster with less errors.


# Types of object composition
**Composition**
To qualify as a composition, an object and a part must have the following relationship:
- The part (member) is part of the object (class);
- The part (member) can only belong to one object (class) at a time;
- The part (member) has its existence managed by the object (class);
- The part (member) does not know about the existence of the object (class);

**Aggregation**
To qualify as an aggregation, a whole object and its parts must have the following relationship:
- The part (member) is part of the object (class);
- The part (member) can (if desired) belong to more than one object (class) at a time;
- The part (member) does not have its existence managed by the object (class);
- The part (member) does not know about the existence of the object (class);

## Inheritance vs Polymorphism 

**Inheritance** refers to using the structure and behavior of a super class in a subclass.
**Polymorphism** refers to changing the behavior of a super class in the subclass.

Inheritance is the idea of creating a new class, which inherits the properties of the already existing (base) class. 
It supports the concept of code reusability and reduces the length of the code.

Polymorphism is the way in which we perform tasks in multiple forms or ways. It is applied to the functions or methods. 
In essence, polymorphism is PART OF inheritance and cannot exist without it.





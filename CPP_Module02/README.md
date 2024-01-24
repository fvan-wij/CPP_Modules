# Fixed-Point Numbers && Orthodox Canonical Form

## Orthodox Canonical Form

### Defintion

The Orthodox Canonical Form is a programming-convention which implies that a class should always have the following functionalities:
- A default constructor
- A copy constructor
- A copy assignment operator
- A deconstructor

In C++11, the orthodox canonical form has been changed by including two new member functions:
- Move constructor
- Move assignment operator

If we don't implement these functionalities ourselves and attempt to copy or assign objects, the compiler will automatically make the address between all other objects shared. This could lead to problematic behaviour such as implicitly modifying other members of a class or double freeing.

### Operator overloading

Operator overloading is the process of changing the meaning of operators of user-defined types. Operators of built-in C++ types cannot be overloaded.
**Note** 
Not all operators can be overloaded in C++. For instance, "., ::, sizeof, typeid, .* and the only ternary operator ?:"

Operators can be overloaded in the form of functions with special names. 
Operators can be both overloaded as a member function of their left operand's type or as non-member functions.
- Decision between member and non-member
In most cases, implement it as member functions. Usually input and output operators are implemented as non-member functions since you cnanot change the left-operand beheviour within a class.

- Three basic rules of operator overloading 
1. Whenever the meaning of an operator is not obviously clear and undisputed, it should not be overloaded
In other words, only implement overloading when the implications are obvious and behave as expected.
2. Always stick to the operator's well known semantics
For instance, don't change add to subtract
3. Always provide all out of a set of related operations
If you provide the + operator, make sure to implement +=, pre-increment and post-increment as well, etc.

Post-increment overloading can be recognized by the (int) parameter;
Post-increment returns temporary old value, but increments the current object.
Pre-increment increments object and returns it immediately.

### Unary vs. Binary vs. Ternary operators

Operators in general are symbols that tell the compiler to perform specific mathematical or logical manipupulations.
They are used in programs to manipulate data and variables and can be categorized into unary, binary and ternary.

**Unary operators** (++, --, -, +, !, ~, &, \*, sizeof);
Unary operators operatore on a single operand. They are used to perform various operations, such as incrementing/decrementing, negating, or dereferencing a pointer.
The most common operators are:

- Increment/Decrement -> increases or decreases the value by 1. 
Prefix(++x): increments the value of X and then returns the new value;
Postfix (x++): returns x and then increments the value;

- Bitwise NOT (~)
Performs bitwise negation on its operand, inverting each bit;

... and more.

**Binary operators** (+, -, \*, /, %, ==, !=, >, <, >=, <=, &&, ||, !, AND&, OR|, XOR^, <<, >>, =, +=, -=, \*=, %=)
Binary operators are used to perform operations on two operands. These operations are fundamental to performing calculations, making comparisons and manipulating data at the bit level.

**Ternary operators**
Ternary operators are a shorthand way of writing conditional statements. The are a compact form of the if-eles statement nad are often used for simple conditional assignments.
Syntax is "condition ? expression1 : expression2;"

Condition is an expression that evaluates to true or false
expr1 is the value or statement that is executed if true
expr2 is the value or statement that is executed if false

### IO Streams
Allows us to read from and write to the console;
When writing text, each character gets sent to the input-outputstream, and stored in a buffer.
This buffer, will contain chunks of data and will be accessible by the running program. 
E.g., when one presses enter, the buffer gets sent to the program and gets cleared. 

- The point of flushing IO streams:
Usually, an explicit flush is necessary before a call to std::sytem, especially if it performs any screen I/O.
In most other cases, std::endl is redundant and my degrade performance. 


## Fixed-Point numbers

Fixed-Point numbers are a balance of performance, accuracy, range and precision.
In essence, a Fixed-Point number is way for us to represent fractional numbers using bits. 
We simply reserve a portion of the bits for fractional numbers, which is defined by the binary point. 
Shifting the binary point, has impact on the precision of Fixed-Point number. 

- Key conccepts
**Fractional number**
A number that is fractional, in general, numbers after the decimal point are considered fractional numbers

**Binary point**
The width or number of bits used to express fractional numbers. The bits that encompass this area are considered binary fractions.

**Raw bits of the Fixed-Point number**
This is a value that represents the fixed-point number. When you apply some logical operations such as bitshifting, etc. you can convert this to a 
fractional number.




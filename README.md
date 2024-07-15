# C++
- [C++](#c)
	- [Scope Resolution operator](#scope-resolution-operator)
	- [Class](#class)
	- [Functions](#functions)
		- [Inline vs Regular Functions in C++](#inline-vs-regular-functions-in-c)
		- [Inline Functions](#inline-functions)
		- [Regular Functions](#regular-functions)
		- [Difference between cin and getline](#difference-between-cin-and-getline)
		- [Clearing cin](#clearing-cin)
		- [Insertion operator](#insertion-operator)
		- [Const Member Function](#const-member-function)
		- [Defining Functions outside of Class](#defining-functions-outside-of-class)
	- [Object](#object)
	- [Namespaces in C++](#namespaces-in-c)
		- [What are Namespaces?](#what-are-namespaces)
		- [Why Use Namespaces?](#why-use-namespaces)
		- [How to Use Namespaces?](#how-to-use-namespaces)
		- [Standard Library and Namespaces](#standard-library-and-namespaces)
		- [Example](#example)
	- [Constructor and Destructor in C++](#constructor-and-destructor-in-c)
		- [Constructor](#constructor)
		- [Destructor](#destructor)
	- [References in C++](#references-in-c)
		- [References vs Pointers in C++](#references-vs-pointers-in-c)
		- [Dangling References](#dangling-references)
	- [Assignment Operator in C++](#assignment-operator-in-c)
	- [Orthodox canonical form](#orthodox-canonical-form)
	- [Inheritance in C++](#inheritance-in-c)
		- [Virtual Functions in C++](#virtual-functions-in-c)
			- [Virtual Destructor](#virtual-destructor)
		- [Polymorphism in C++](#polymorphism-in-c)
		- [Exception handling](#exception-handling)



42 school C++ projects

## Scope Resolution operator

scope resolution:: operator

## Class

The building block of C++ that leads to Object-Oriented programming is a Class. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A class is like a blueprint for an object. For Example: Consider the Class of Cars. There may be many cars with different names and brands but all of them will share some common properties like all of them will have 4 wheels, Speed Limit, Mileage range, etc. So here, the Car is the class, and wheels, speed limits, and mileage are their properties.

A Class is a user-defined data type that has data members and member functions.
Data members are the data variables and member functions are the functions used to manipulate these variables together these data members and member functions define the properties and behavior of the objects in a Class.
In the above example of class Car, the data member will be speed limit, mileage, etc and member functions can apply brakes, increase speed, etc.
We can say that a Class in C++ is a blueprint representing a group of objects which shares some common properties and behaviors.

## Functions

### Inline vs Regular Functions in C++

### Inline Functions

- **Purpose**: Optimizes small functions by inserting their code directly at the call site.
- **Declaration**: Prefixed with the `inline` keyword in function declaration/definition.
- **Performance**: Can improve performance by avoiding function call overhead.
- **Usage**: Effective for small functions but may increase code size.
- **Example**: `inline int add(int a, int b) { return a + b; }`

Note that all the member functions defined inside the class definition are by default inline, but you can also make any non-class function inline by using the keyword inline with them. Inline functions are actual functions, which are copied everywhere during compilation, like pre-processor macro, so the overhead of function calls is reduced. 

### Regular Functions

- **Purpose**: Provide modularity and code reusability.
- **Declaration**: Separately declared and defined in header and source files.
- **Performance**: Function call involves jumping to function's location, incurring overhead.
- **Usage**: Suitable for larger functions and promoting modular design.
- **Example**:

```cpp

  // Function declaration in header file
  int add(int a, int b);
  
  // Function definition in source file
  int add(int a, int b) { return a + b; }

```

### Difference between cin and getline

The difference between std::cin >> first_name; and std::getline(std::cin, first_name); lies in how they handle whitespace characters:

std::cin >> first_name; This line of code reads input until it encounters a whitespace character (like a space, tab, or newline). For example, if the user enters "John Doe", first_name will only store "John".

std::getline(std::cin, first_name); This line of code reads an entire line of input until it encounters a newline character (which is added when the user presses Enter). In the same example, if the user enters "John Doe", first_name will store the entire string, "John Doe".

So, if you expect the input to contain spaces and you want to store the entire input in a single string, you should use std::getline(). If you only want to store a single word, you can use std::cin >>.

### Clearing cin

After reading an int with cin we have to clear out the remaining '\n' character in the buffer

``` cpp
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

### Insertion operator

In C++, the `<<` operator is known as the insertion or put-to operator. When used with `std::cout`, it inserts the data on its right into the output stream, which is typically the console.

For example, in the line `std::cout << "Hello, World!";`, the string `"Hello, World!"` is inserted into the output stream, causing it to be printed to the console.

The `<<` operator can be chained to insert multiple pieces of data into the output stream in one statement. For example, `std::cout << "Hello, " << "World!";` will print "Hello, World!" to the console.

### Const Member Function

A const member function is a member function that guarantees it will not modify the object and its data members, or call any other member functions that are not const.
This is indicated by the const keyword at the end of the function declaration. The function can be called on both const and non-const objects of the class.

``` cpp
return_type function_name(parameters) const;
```

### Defining Functions outside of Class

``` c++
// C++ program to demonstrate function 
// declaration outside class 

#include <bits/stdc++.h> 
using namespace std; 
class Geeks 
{ 
	public: 
	string geekname; 
	int id; 
	
	// printname is not defined inside class definition 
	void printname(); 
	
	// printid is defined inside class definition 
	void printid() 
	{ 
		cout <<"Geek id is: "<<id; 
	} 
}; 

// Definition of printname using scope resolution operator :: 
void Geeks::printname() 
{ 
	cout <<"Geekname is: "<<geekname; 
} 
int main() { 
	
	Geeks obj1; 
	obj1.geekname = "xyz"; 
	obj1.id=15; 
	
	// call printname() 
	obj1.printname(); 
	cout << endl; 
	
	// call printid() 
	obj1.printid(); 
	return 0; 
}

```

## Object

An Object is an identifiable entity with some characteristics and behavior. An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

## Namespaces in C++

Namespaces in C++ provide a way to organize code, prevent naming conflicts, and improve readability. Here's a quick rundown:

### What are Namespaces?

- Namespaces are a C++ feature that allows you to group related code under a single name.
- They are declared using the `namespace` keyword followed by the namespace name.

### Why Use Namespaces?

- **Avoid Conflicts**: Namespaces help avoid naming conflicts by encapsulating code within a unique namespace.
- **Organize Code**: They allow you to organize code logically, making it easier to manage and understand.
- **Improve Readability**: Namespaces provide context for code elements, enhancing readability and maintainability.

### How to Use Namespaces?

- To access entities within a namespace, prefix them with the namespace name followed by the scope resolution operator (`::`).
- For example, `namespaceName::Entity`.

### Standard Library and Namespaces

- Many elements of the C++ Standard Library, such as `std::string`, `std::vector`, etc., are contained within the `std` namespace.
- Always use `std::` prefix when using standard library entities to avoid conflicts and specify their origin.

### Example

```cpp
#include <iostream>

// Define a namespace
namespace MyNamespace {
    int myFunction() {
        return 42;
    }
}

int main() {
    // Access function from the namespace
    std::cout << MyNamespace::myFunction() << std::endl;
    return 0;
}
```

## Constructor and Destructor in C++

In C++, **constructors** and **destructors** are special member functions of a class. They are automatically called when objects of the class are created and destroyed, respectively.

### Constructor

A **constructor** is used to initialize the object's state. It has the same name as the class and doesn't have a return type. There can be multiple constructors in a class, including:

- **Default constructor**: Takes no parameters.
- **Parameterized constructors**: Takes parameters.
- **Copy constructor**: Takes a reference to an object of the same class as a parameter.

### Destructor

A **destructor** is used to clean up resources that the object may have acquired during its lifetime. It has the same name as the class but is preceded by a tilde (~). There can only be one destructor in a class and it cannot take parameters or return a value.

## References in C++

In C++, a **reference** is a type of alias or nickname for an existing variable. A reference, once initialized with a variable, can then be used to access the variable's value.

Key points about references:

- A reference must be initialized when it is declared.
- The reference itself can't be changed to refer to another variable.
- A reference shares the same memory address as the variable it's referring to.
- References are particularly useful for C++ function arguments, allowing for pass-by-reference semantics where a function can modify the value of the argument.
- References are safer and easier to use than pointers. They always refer to a valid object and can't be null.

### References vs Pointers in C++

Both **references** and **pointers** in C++ are used to indirectly access different variables in memory, but they have some key differences:

- **Initialization**: A reference must be initialized when it is declared and cannot be reseated to refer to another object. A pointer can be declared first and initialized later, and it can be reassigned to point to another object.

- **Nullability**: A reference always refers to an object, it cannot be null. A pointer can be null, indicating that it doesn't point to any object.

- **Indirection**: A reference is used directly as an alias for the original variable and doesn't need dereferencing. A pointer requires dereferencing to access the variable it points to.

- **Arithmetic**: Pointer arithmetic (increment/decrement to move to another memory location) is allowed, but there is no such concept for references.

In general, references are safer and easier to use than pointers. They are often used when you want to establish a simple link to an object. Pointers provide more flexibility and control, but with the added risk of potential issues like null pointers and dangling pointers.

### Dangling References

A dangling reference in C++ occurs when a reference is used to access a variable or object that has already been deallocated or out of scope. This can lead to undefined behavior, as the reference may now point to some other data or be in an invalid state.

```cpp
int& danglingReference() {
	int a = 5;
	return a;
}

int main() {
	int& ref = danglingReference();
	// 'ref' is now a dangling reference because 'a' has gone out of scope
}
```

To avoid dangling references:

Don't return local variables by reference.
Don't let a reference outlive the object it refers to.
Be careful when using references inside classes. If a class has a reference member, make sure the object it refers to doesn't get destroyed before the class instance.

## Assignment Operator in C++

In C++, the **assignment operator** (`operator=`) is a special member function that is used to copy the values from one object to another. It's called when an already initialized object is assigned a new value from another existing object.

The assignment operator:

- Takes a constant reference to another object of the same class as a parameter.
- Returns a reference to the object, allowing for chain assignment like `a = b = c`.
- Performs a deep copy of the values from the other object to the current object.
- Includes a self-assignment check (`if (this != &other)`) to prevent self-assignment, which could lead to unexpected results or wasted resources.

## Orthodox canonical form

In C++98 and C++03 the OCCF had four different methods that the C++ compiler is willing to generate:

- **Default Constructor**
- **Copy Constructor**
- **Destructor**
- **Copy Assignment Operator**

## Inheritance in C++

In C++, we have three types of inheritance: `public`, `protected`, and `private`. Each type affects the access levels of the base class members in the derived class.

- **Public Inheritance**: Public members of the base class become public in the derived class, and protected members of the base class remain protected in the derived class.

- **Protected Inheritance**: Both public and protected members of the base class become protected in the derived class.

- **Private Inheritance**: Both public and protected members of the base class become private in the derived class.

> **Note**: Private members of the base class are always inaccessible to the derived class, regardless of the type of inheritance. But they can be accessed indirectly via getter and setter functions.


### Virtual Functions in C++

Virtual functions are a key part of the polymorphism feature in C++. They are member functions that are declared in the base class and can be overridden in the derived class.

- **Declaration**: Virtual functions are declared in the base class using the `virtual` keyword in the header file.

- **Overriding**: In the derived class, the function signature must be exactly the same as the base class function. The `override` keyword can be used to explicitly specify that a function is intended to override a virtual function in the base class.

- **Dynamic Binding**: When a virtual function is called on an object, the version of the function that gets executed is determined by the type of the object, not by the type of the pointer or reference. This is known as dynamic binding or late binding.

- **Pure Virtual Functions**: A pure virtual function is a virtual function that the base class declares but does not define. This makes the base class abstract, meaning it cannot be instantiated. Derived classes must provide a definition for all pure virtual functions.

Example:
```cpp
class Base {
public:
	virtual void foo() { cout << "Base::foo()"; }
};

class Derived : public Base {
public:
	void foo() override { cout << "Derived::foo()"; }
};
```

#### Virtual Destructor

In C++, when a class is used as a base class for other classes and it's intended to be polymorphic, it should declare a virtual destructor. This ensures that when an object of a derived class is deleted through a pointer to the base class, the destructor of the derived class is called correctly.

### Polymorphism in C++

Polymorphism is a fundamental concept in object-oriented programming. It allows objects of different types to be treated as objects of a common type, enabling more flexible and reusable code.

- **Subtype Polymorphism**: This is the most common form of polymorphism in C++. It's achieved through inheritance and virtual functions. A base class pointer or reference can be used to refer to an object of any class that derives from that base class. The actual function that gets called is determined at runtime, based on the actual type of the object.

- **Parametric Polymorphism**: This is achieved through templates in C++. A function or class can be written to work with different types, and the actual type is specified when the function is called or the class is instantiated.

- **Coercion Polymorphism**: This is where a type can be automatically changed to another type if needed. For example, an `int` can be automatically changed to a `double` in a mathematical expression.

Example:
```cpp
class Base {
public:
	virtual void foo() { cout << "Base::foo()"; }
};

class Derived : public Base {
public:
	void foo() override { cout << "Derived::foo()"; }
};

Base* obj = new Derived();
obj->foo();  // Prints "Derived::foo()"
```

### Exception handling

Exception handling (the `try/catch` block) is typically done at a higher level in the code where you can handle the error appropriately. This could be in the `main` function or in another function that calls `incGrade`.

The reason for this is that `incGrade` itself might not know what to do when an exception occurs. For example, if `incGrade` is part of a larger operation that needs to be rolled back when an error occurs, `incGrade` wouldn't have the necessary context to do that.

#include <sstream>
#include <string>
#include <iostream>

int main() {
    std::string data = "123 3.14 Hello";
    std::istringstream iss(data);
    
    int i;
    double d;
    std::string s;
    
    iss >> i >> d >> s;
    
    std::cout << "Integer: " << i << std::endl;
    std::cout << "Double: " << d << std::endl;
    std::cout << "String: " << s << std::endl;
    
    return 0;
}

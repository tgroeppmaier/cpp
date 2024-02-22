# cpp

42 school cpp projects

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

## Constructor and Destructor


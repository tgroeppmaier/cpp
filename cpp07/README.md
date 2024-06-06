# Cpp Module 07 - Templates

- [Cpp Module 07 - Templates](#cpp-module-07---templates)
  - [Conceptual Overview](#conceptual-overview)
    - [Function Templates](#function-templates)
  - [Exercises](#exercises)
    - [Exercise 00](#exercise-00)
    - [Exercise 01](#exercise-01)

## Conceptual Overview

*A template is a model that serves as a pattern for creating similar objects.*

### Function Templates

Function templates serve as blueprints for creating functions that can operate on various data types. 

Consider a scenario where we need a function to add two integers. We would define a function that takes two integers as parameters and returns their sum. Now, suppose we also need a function to add two floating-point numbers. Instead of duplicating the function (violating the DRY principle) with a different data type, we can use a function template. 

Function templates can work with any data type, allowing us to write the function logic once and use it with different types. The compiler generates the appropriate function at compile time, based on the data types used when the function is called.

**Example:**

```cpp
// int version
int max_int(int x, int y)
{
    return (x < y) ? y : x;
}

// Function template
template <typename T> // template parameter declaration
T max(T x, T y) // function template definition for max<T>
{
    return (x < y) ? y : x;
}

max<int>(5, 6) // compiler instantiates the function template with int and passes (5, 6)
```

## Exercises

In this module, we are required to implement various function templates. Detailed instructions for each exercise can be found in the [instructions](./cpp07.pdf) document.

### Exercise 00

We are required to implement three function templates:

- **swap:** This function swaps the values of two given arguments. It does not return anything.
- **min:** This function compares the two values passed as arguments. It returns the smallest one. If the two values are equal, it returns the second one.
- **max:** Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.

### Exercise 01


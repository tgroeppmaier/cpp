# Cpp Module 08 - STL

- [Cpp Module 08 - STL](#cpp-module-08---stl)
  - [Iterators](#iterators)
    - [Key Features of Iterators:](#key-features-of-iterators)
    - [Usage:](#usage)


C++ STL has 3 major components:

- **Containers**
- **Iterators**
- **Algorithms**

In addition to these, STL also provides several other features, including **function objects**, **smart pointers**, and **exception handling mechanisms**.

STL containers store data and organize them in a specific manner as required.

For example, **vectors** store data of the same type in a sequential order. Whereas, **maps** store data in key-value pairs.

We can classify STL containers into 3 types:

1. **Sequence containers**:
    - Array
    - Vector
    - Queue
    - Deque
    - Forward_list
    - List

2. **Associative containers**:
    - Set
    - Multiset
    - Map
    - Multimap

3. **Unordered associative containers**:
    - Unordered_set
    - Unordered_multiset
    - Unordered_map
    - Unordered_multimap


## Iterators

Iterators in programming, particularly in C++, are objects that facilitate the traversal of a container. They act similarly to pointers but are designed to work with the Standard Template Library (STL) containers like `vector`, `list`, `map`, etc. Iterators abstract the container's internal structure, offering a way to access and manipulate elements sequentially or based on their position without exposing the underlying data representation.

### Key Features of Iterators:

- **Abstraction**: Iterators provide a layer of abstraction, allowing for the manipulation of elements within a container without needing to know the container's internal structure.
- **Compatibility**: They are compatible with STL algorithms, meaning you can use iterators with functions like `std::sort`, `std::find`, and `std::copy`.
- **Types of Iterators**: There are several iterator categories, each supporting different operations:
    - **Input Iterators**: Support reading elements sequentially.
    - **Output Iterators**: Support writing elements sequentially.
    - **Forward Iterators**: Can read or write and move forward through a sequence.
    - **Bidirectional Iterators**: Like forward iterators but can also move backwards.
    - **Random Access Iterators**: Support direct access to elements, allowing for arithmetic operations on the iterator.

### Usage:

Iterators are used by obtaining an iterator to the beginning of a container, then incrementing the iterator to move through the container, and finally comparing the iterator to the end of the container to know when the traversal is complete.

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " "; // Access the element pointed to by the iterator
}

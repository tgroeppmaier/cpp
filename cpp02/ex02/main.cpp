#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// int main(void) 
// {
// 	Fixed a = Fixed(5.05f); 
// 	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	std::cout << "Testing pre-increment operator:\n";
//     for (int i = 0; i < 5; ++i) {
//         std::cout << "Value of a: " << a++ << "\n";
//     }

// 	a = 0;

//     std::cout << "\nTesting post-increment operator:\n";
//     for (int i = 0; i < 5; ++i) {
//         std::cout << "Value of a: " << a-- << "\n";
//     }

// 	std::cout << "Min of a and b: " << Fixed::min(a, b) << "\n";
//     std::cout << "Max of a and b: " << Fixed::max(a, b) << "\n";

// 	return 0;
// }
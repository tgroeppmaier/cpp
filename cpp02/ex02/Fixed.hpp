#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
private:
    int value_;
    static const int fractionalBits_ = 8;

public:
    Fixed();                                // default constructor
    Fixed(const int intValue);              // int constructor
    Fixed(const float floatValue);          // float constructor
    Fixed(const Fixed &other);              // copy constructor
    Fixed& operator=(const Fixed &other);   // copy assignment operator
    ~Fixed();                               // destructor

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt() const;
    
/* ex02 */

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed& operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    };

    std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
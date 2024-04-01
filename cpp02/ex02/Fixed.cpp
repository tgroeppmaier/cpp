#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value_(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called\n";
    value_ = intValue << fractionalBits_;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called\n";
    value_ = roundf(floatValue * (1 << fractionalBits_));
}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        value_ = other.value_;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return value_;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    value_ = raw;
}

/* converts fixed-point value to a floating-point value */

float Fixed::toFloat(void) const {
    return (float) value_ / (1 << fractionalBits_);
}

/* converts fixed-point value to a floating-point value and then rounds to int
    for better accuracy than directly bitshifting value_ >> 8  */

int Fixed::toInt() const {
    float floatValue = this->toFloat();
    return (int) roundf(floatValue);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

/* ex02 */

bool Fixed::operator>(const Fixed &other) const {
    return value_ > other.value_;
}

bool Fixed::operator<(const Fixed &other) const {
    return value_ < other.value_;
}

bool Fixed::operator>=(const Fixed &other) const {
    return value_ >= other.value_;
}

bool Fixed::operator<=(const Fixed &other) const {
    return value_ <= other.value_;
}

bool Fixed::operator==(const Fixed &other) const {
    return value_ == other.value_;
}

bool Fixed::operator!=(const Fixed &other) const {
    return value_ != other.value_;
}

/* creates new Fixed Object wit */

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    value_ += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed& Fixed::operator--() {
    value_ -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    operator--();
    return temp;
}


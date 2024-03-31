#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int value_;
    static const int fractionalBits_ = 8;

public:
    Fixed(); // default constructor
    Fixed(const int intValue); // int contructor
    Fixed(const float floatValue); // float contructor
    Fixed(const Fixed &other); // copy constructor
    Fixed &operator=(const Fixed &other); // copy assignment operator
    ~Fixed(); // destructor

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif
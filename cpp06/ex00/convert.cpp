#include "ScalarConverter.hpp"

using std::string;
using std::cout;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    string str = argv[1];
    ScalarConverter::convert(str);
    return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include <cerrno>  // for errno
#include <cstring>  // for strerror

int main()
{
    std::string fpath_in, fpath_out, line, s1, s2;
    std::fstream file, newfile;

    while (true){
        std::cout << "Enter filename\n";
        std::cin >> fpath_in;
        file.open(fpath_in.c_str(), std::ios::in);
        if(!file.is_open())
            std::cout << std::strerror(errno) << "\n";
        else
            break;
    }
    
    fpath_out = fpath_in + ".replace";
    newfile.open(fpath_out.c_str(), std::ios::out);
    if (!newfile.is_open()) {
        std::cerr << std::strerror(errno) << "\n";
        return 1;
    }

    std::cout << "Enter s1\n";
    std::cin >> s1;
    std::cout << "Enter s2\n";
    std::cin >> s2;
    std::cout << "replacing all " << s1 << " with " << s2 << std::endl;

    while (std::getline(file, line)) {
        std::string::size_type pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) { // pos is position before s1
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        newfile << line << "\n";
    }

    file.close();
    newfile.close();
    return 0;
}


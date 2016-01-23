//
// Created by hamed on 1/7/16.
//

#ifndef ZAEIMCO_CLIENT_UTILS_H
#define ZAEIMCO_CLIENT_UTILS_H

#include <sstream>
#include <string>
#include <iostream>

namespace utils {
    int print_usage();
    bool check_operation(std::string operation);
    bool contains(std::string text, std::string q);
    std::string hash_message(std::string message);
}

#endif //ZAEIMCO_CLIENT_UTILS_H


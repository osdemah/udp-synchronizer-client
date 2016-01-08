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
    std::string get_parameter(char *argv);
    bool check_operation(std::string operation);
}

#endif //ZAEIMCO_CLIENT_UTILS_H

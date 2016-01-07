//
// Created by hamed on 1/7/16.
//

#ifndef ZAEIMCO_CLIENT_UTILS_H
#define ZAEIMCO_CLIENT_UTILS_H

#include <sstream>
#include <string>
#include <iostream>

class Utils {
public:
    static int print_usage();

    static std::string get_parameter(char *argv);
};

#endif //ZAEIMCO_CLIENT_UTILS_H

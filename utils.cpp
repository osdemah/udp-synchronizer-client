//
// Created by hamed on 1/7/16.
//

#include "utils.h"

int utils::print_usage(){
    std::cerr << "Usage: client <host> <port> <CREATE_FILE|CREATE_DIR|REMOVE_FILE|REMOVE_DIR> <file/dir>" << std::endl;
    return 1;
}

std::string utils::get_parameter(char *argv) {
    std::string output;
    std::istringstream iss( argv );
    if (!(iss >> output))
    {
        return "";
    }
    return output;
}
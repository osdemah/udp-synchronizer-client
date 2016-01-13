//
// Created by hamed on 1/7/16.
//

#include "utils.h"

#include <boost/functional/hash.hpp>

int utils::print_usage(){
    std::cerr << "Usage: client <host> <port> <CREATE_FILE|CREATE_DIR|REMOVE_FILE|REMOVE_DIR> <file/dir>" << std::endl;
    return 1;
}

bool utils::check_operation(std::string operation) {
    return operation.compare("CREATE_FILE") == 0 || operation.compare("CREATE_DIR") == 0 ||
        operation.compare("REMOVE_FILE") == 0 || operation.compare("REMOVE_DIR") == 0;
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

std::string utils::hash_message(std::string message) {
    return std::to_string(std::hash<std::string>()(message));
}
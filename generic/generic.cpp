#include <iostream>
#include <fstream>
#include <unistd.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void usage()
{
    std::cout << "Usage:\n"
              << "generic [-f <file>]\n";
    exit(1);
}

int main(int argc, char **argv)
{
    const char *file = "../inputs/sample.json";
    int c = 0;

    while ((c = getopt(argc, argv, "f:?")) != EOF)
    {
        switch (c)
        {
        case 'f':
            file = optarg;
            break;
        case '?':
            usage();
            break;
        default:
            std::cerr << "Unexpected arg " << (char)c << "\n";
            usage();
        }
    }

    std::ifstream i(file);
    json j;
    i >> j;
    std::cout << "Loaded " << file << "\n";

    // Pretty print
    //std::cout << j << std::endl;

    if (j.count("top-string"))
    {
        std::cout << "top-string: " << j["top-string"].get<std::string>() << "\n";
    }

    if (j.count("top-int")) {
        std::cout << "top-int: " << j["top-int"].get<int>() << "\n";
    }

    if (j.count("top-bool")) {
        std::cout << "top-bool: " << j["top-bool"].get<bool>() << "\n";
        //std::cout << "top-bool: " << j["top-bool"].get<std::string>() << "\n";
    }

    if (j.count("top-list")) {
        // 3rd item of list
        std::cout << "top-list[2]: " << j["top-list"][2].get<std::string>() << "\n";
    }

    if (j.count("top-dict")) {
        // value for key "key2"
        std::cout << "top-dict[\"key2\"]: " << j["top-dict"]["key2"].get<std::string>() << "\n";
    }
}
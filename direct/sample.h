#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "nlohmann/json.hpp"

using nlohmann::json;

// Sample user-provided datatype matching ../inputs/sample.json

struct Sample
{
    std::string top_string;
    int top_int;
    bool top_bool;

    std::vector<std::string> top_list;

    std::map<std::string, std::string> top_dict;

    std::vector<std::vector<std::string>> nested_list;

    std::map<std::string, std::map<std::string, std::string>> nested_dict;

    bool operator==(const Sample &rhs) const;
};

std::ostream &operator<<(std::ostream &os, const Sample &s);

void to_json(json &j, const Sample &s);
// {
//     j = json{
//         {"top-string",s.top_string}, 
//         {"top-int", s.top_int}, 
//         {"top-bool", s.top_bool},
//         {"top-list", s.top_list},
//         {"top-dict", s.top_dict}
//     };
// }

void from_json(const json &j, Sample &s);
// {
//     j.at("top-string").get_to(s.top_string);
//     j.at("top-int").get_to(s.top_int);
//     j.at("top-bool").get_to(s.top_bool);
// }






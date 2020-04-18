#pragma once

#include <string>
#include <iostream>
#include <map>
using std::string;

namespace family{
    class Tree {
        public:
            std::map<std::string, std::string> father;
            std::map<std::string, std::string> mother;
            Tree(std::string iname);
            Tree& addFather(std::string name, std::string father);
            Tree& addMother(std::string name, std::string mather);
            void display();
            std::string relation(std::string relative_name);
            std::string find(std::string relation);
            void remove(std::string relative_name);
    };
};

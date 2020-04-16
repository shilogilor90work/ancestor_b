#include "FamilyTree.hpp"

#include <iostream>
namespace family{

    std::string repeat(const std::string& input, unsigned num)
    {
        std::string ret;
        ret.reserve(input.size() * num);
        while (num--)
            ret += input;
        return ret;
    }

    Tree::Tree(std::string iname){
        father.insert(std::pair<std::string,std::string>("__root__", iname) );
    }
    Tree& Tree::addFather(std::string my_name, std::string my_father) {
        std::string key = "__null__";
        std::string key_son = "__null__";
        for (auto &i : this->father) {
           if (i.second == my_name) {
              key = i.first;
           }
           if (i.first == my_name) {
              key_son = i.first;
           }
        }
        for (auto &i : this->mother) {
           if (i.second == my_name) {
              key = i.first;
           }
        }
        if (key != "__null__" && key_son == "__null__") {
            father.insert(std::pair<std::string,std::string>(my_name, my_father));
            return *this;
        } else {
            throw std::exception();
        }
    }
    Tree& Tree::addMother(std::string my_name, std::string my_mather) {
        std::string key = "__null__";
        std::string key_son = "__null__";
        for (auto &i : this->father) {
           if (i.second == my_name) {
              key = i.first;
           }
        }
        for (auto &i : this->mother) {
           if (i.second == my_name) {
              key = i.first;
           }
           if (i.first == my_name) {
              key_son = i.first;
           }
        }
        if (key != "__null__" && key_son == "__null__") {
            mother.insert(std::pair<std::string,std::string>(my_name, my_mather));
            return *this;
        } else {
            throw std::exception();
        }
    }
    void Tree::display() {
        for (auto &i : this->father) {
            std::cout << i.first + " F: " + i.second + "\n";
        }
        for (auto &i : this->mother) {
            std::cout << i.first + " M: " + i.second + "\n";
        }
    }
    std::string Tree::relation(std::string relative_name) {
        std::string key = "__null__";
        int counter = 0;
        bool is_mother = false;
        std::string message = "";
        std::string old_key = "__null__";
        for (auto &i : this->father) {
           if (i.second == relative_name) {
              key = i.first;
              break; // to stop searching
           }
        }
        for (auto &i : this->mother) {
           if (i.second == relative_name) {
              key = i.first;
              is_mother = true;
              break; // to stop searching
           }
        }
        if (key != "__null__") {
            while (key != "__root__") {
                old_key = key;
                for (auto &i : this->father) {
                   if (i.second == old_key) {
                      key = i.first;
                      break; // to stop searching
                   }
                }
                for (auto &i : this->mother) {
                   if (i.second == old_key) {
                      key = i.first;
                      break; // to stop searching
                   }
                }
                counter = counter + 1;
            }
        } else {
            return "unrelated";
        }
        if (counter > 2) {
            message = message + repeat("great-", counter - 2);
        }
        if (counter > 1) {
            message = message + "grand";
        }
        if (counter > 0){
            if(is_mother) {
                message = message + "mother";
            } else {
                message = message + "father";
            }
        } else {
            message = message + "me";
        }
        return message;
    }
    std::string Tree::find(std::string relation) {
        for (auto &i : this->mother) {
            if (this->relation(i.first) == relation){
                return i.first;
            }
            if (this->relation(i.second) == relation){
                return i.second;
            }
        }
        for (auto &i : this->father) {
            if (this->relation(i.first) == relation){
                return i.first;
            }
            if (this->relation(i.second) == relation){
                return i.second;
            }
        }
        throw std::exception();
        // return "unrelated";
    }
    void Tree::remove(std::string relative_name) {
        if (this->relation(relative_name) == "unrelated") {
            throw std::exception();
        }
        std::string root = "__null__";
        for (auto &i : this->father) {
           if (i.first == "__root__") {
              root = i.second;
           }
        }
        if (relative_name == root) {
            throw std::exception();
        }
        std::cout << relative_name + "\n";
        if (this->mother.count(relative_name) > 0) {
            this->remove(this->mother.find(relative_name)->second);
        }
        if (this->father.count(relative_name) > 0) {
            this->remove(this->father.find(relative_name)->second);
        }
        std::string key = "__null__";
        for (auto &i : this->mother) {
            if (i.second == relative_name){
                key = i.first;
                break;
            }
        }
        if (key != "__null__") {
            this->mother.erase(this->mother.find(key));
        }
        key = "__null__";
        for (auto &i : this->father) {
            if (i.second == relative_name){
                key = i.first;
                break;
            }
        }
        if (key != "__null__") {
            this->father.erase(this->father.find(key));
        }
    }
}

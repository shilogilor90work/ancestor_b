#pragma once

#include <string>
#include <iostream>
#include <map>

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





//
// class TreeNode
// {
//     private:
//         std::string textContent;
//         std::string tagName;
//
//         TreeNode *parent;
//
//         std::vector<TreeNode *> children;
//
//         int countNodesRec(TreeNode *root, int& count);
//
//     public:
//         TreeNode();
//         TreeNode(std::string iTextContent, std::string iTagName);
//
//         void appendChild(TreeNode *child);
//         void setParent(TreeNode *parent);
//
//         void popBackChild();
//         void removeChild(int pos);
//
//         bool hasChildren();
//         bool hasParent();
//
//         TreeNode* getParent();
//         TreeNode* getChild(int pos);
//
//         int childrenNumber();
//         int grandChildrenNum();
//
//         std::string getTextContent();
//         std::string getTagName();
// };

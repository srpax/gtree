#include "node.hpp"

#include <iostream>
#include <cstdint>

std::string tree_node::_prev_formed_padding = "";

std::string tree_node::get_child_padding()
{
    if (is_last_sibling())
    {
        return "   ";
    }
    else
    {
        return "│  ";
    }
}

std::string tree_node::get_header()
{
    // get the header before the name is printed
    if (this->is_last_sibling())
    {
        return "└──";
    }
    else
    {
        return "├──";
    }
}

void tree_node::print(std::ostream& os, std::string padding, uint32_t depth)
{
    std::string header = "";
    std::string child_padding = "";
    if (!is_root())
    {
        header = get_header();
        child_padding = get_child_padding();
    }
    
    os << padding << header << _name << std::endl;

    tree_node* child = _child;
    while(child)
    {
        child->print(os, padding + child_padding, depth + 1);
        child = child->_next_rel;
        if (child == _child) break;
    }
}

void tree_node::add_child(tree_node* child)
{
    if (this->is_parent())
    {
        // create next sibling
        child->link_prev_relative(this->_child->_prev_rel);
    }
    else
    {
        // create the first child
        child->link_parent(this);
        child->link_prev_relative(child);
    }

    // regardless, new child links to itself or existing link node
    child->link_next_relative(this->_child);
}

tree_node* tree_node::build_tree()
{
    // prompt for and get name from std::cin
    std::string input;
    std::cout << "name: " << std::flush; 
    std::cin >> input;
    tree_node* root = new tree_node(input);

    // prompt for and create child nodes
    while (true)
    {
        std::cout << "(Y/n) Create child for \"" << root->_name << "\"? ";
        std::cin >> input;
    
        if (input == "n") break;
        if (input == "Y")
        {
            tree_node* child = build_tree();
            root->add_child(child);
        }
    }
    return root;
}

void tree_node::destroy_siblings()
{
    while (!is_only_child())
    {
        tree_node* sibling = _next_rel;
        this->link_next_relative(sibling->_next_rel);
        destroy_node(sibling);
    }
}

void tree_node::destroy_node(tree_node* doomed)
{
    // dne
    if (!doomed) return;

    // destroy child node
    if (doomed->is_parent())
    {
        destroy_node(doomed->_child);
        doomed->_child = nullptr;
    }

    // if the one child node, destroy would-be orphans first
    if (doomed->is_child())
    {
        doomed->destroy_siblings();
    }
    else
    {
        if (!doomed->is_root())
        {
            doomed->_prev_rel->link_next_relative(doomed->_next_rel);
        }
    }

    doomed->_child = nullptr;
    doomed->_next_rel = nullptr;
    doomed->_prev_rel = nullptr;
    doomed->_parent = nullptr;

    delete doomed;
}

std::ostream& operator<<(std::ostream& os, tree_node* node)
{
    node->print(os, "", 0);
    os << std::flush;
    return os; 
}

std::istream& operator>>(std::istream& is, tree_node& node)
{
    //ignore whitespace until first line

    //get first char column position

    //if next line column character equals branch 
    return is;
}
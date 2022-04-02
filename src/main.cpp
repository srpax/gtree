#include "node.hpp"
#include "cmd.hpp"

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    bool quit = false;
    tree_node* root = nullptr;

    while(!quit)
    {
        std::string input = "";
        std::cout << ">";
        std::cin >> input;
        tree_cmd cmd = parse_command(input);

        switch (cmd)
        {
            case tree_cmd::create:
                if (root)
                {
                    std::cout << "Existing Tree. See \"reset\" command." << std::endl;
                }
                else
                {
                    root = tree_node::build_tree();
                }
                break;

            case tree_cmd::load:
                if (root)
                {
                    std::cout << "Existing Tree. See \"reset\" command." << std::endl;
                }
                else
                {
                    root = tree_node::build_tree();
                }
                break;

            case tree_cmd::print:
                if (root)
                {
                    std::cout << root << std::endl;
                }
                else
                {
                    std::cout << "No tree. See \"create\" or \"load\" commands." << std::endl;
                }
                break;
            case tree_cmd::quit:
                tree_node::destroy_node(root);
                quit = true;
                break;

            case tree_cmd::reset:
                tree_node::destroy_node(root);
                break;
                
            case tree_cmd::edit:
                break;

            default:
                std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
#include "cmd.hpp"

#include <stdexcept>

void to_lower(std::string& str)
{
    for (uint32_t i = 0; i < str.length(); i++)
    {
        str[i] = std::tolower(str[i]);
    }
}

tree_cmd parse_command(std::string cmd)
{
    to_lower(cmd);

    try
    {
        return tree_cmd_map.at(cmd);
    }
    catch (std::out_of_range&) {}
    
    return tree_cmd::unknown;
}
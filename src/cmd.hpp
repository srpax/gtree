#ifndef CMD_HPP
#define CMD_HPP

#include <string>
#include <map>

enum class tree_cmd
{
    unknown =   0,
    print =     1,
    create =    2,
    load =      3,
    reset =     4,
    quit =      5,
    edit =      6,
    help =      7,
};

const std::map<std::string, tree_cmd> tree_cmd_map =
{
    std::make_pair("reset", tree_cmd::reset),
    std::make_pair("r", tree_cmd::reset),

    std::make_pair("quit", tree_cmd::quit),
    std::make_pair("q", tree_cmd::quit),

    std::make_pair("create", tree_cmd::create),
    std::make_pair("c", tree_cmd::create),

    std::make_pair("print", tree_cmd::print),
    std::make_pair("p", tree_cmd::print),

    std::make_pair("load", tree_cmd::load),
    std::make_pair("l", tree_cmd::load),

    std::make_pair("edit", tree_cmd::edit),
    std::make_pair("e", tree_cmd::edit),

    std::make_pair("help", tree_cmd::help),
    std::make_pair("h", tree_cmd::help)
};

tree_cmd parse_command(std::string cmd);

#endif
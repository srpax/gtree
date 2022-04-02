#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <iostream>

class tree_node
{
private:
    std::string _name;
    tree_node* _parent;
    tree_node* _next_rel;
    tree_node* _prev_rel;
    tree_node* _child;

    static std::string _prev_formed_padding;
    std::string get_header();
    std::string get_child_padding();
    void print(std::ostream& os, std::string padding, uint32_t depth);
    
    inline void link_next_relative(tree_node* relative) { this->_next_rel = relative; relative->_prev_rel = this; }
    inline void link_prev_relative(tree_node* relative) { this->_prev_rel = relative; relative->_next_rel = this; }
    inline void link_parent(tree_node* parent) { this->_parent = parent; parent->_child = this; }

public:
    tree_node(std::string name) : _name(name) {} 
    ~tree_node() {}

    // root is special, all nodes besides child are null
    inline bool is_root() { return (_parent == nullptr) && (_next_rel == nullptr) && (_prev_rel == nullptr); }
    inline bool is_parent() { return _child != nullptr; }
    inline bool is_child() { return _parent != nullptr; }
    inline bool is_only_child () { return _next_rel == this; }
    inline bool is_last_sibling() { return is_root() || _next_rel->is_child(); }

    /**
     * @brief Adds a new node as a child. If the instance calling this 
     * function has no child, the new node is marked as the link node.
     * 
     * @param child the node to add.
     */
    void add_child(tree_node* child);
    
    /**
     * @brief Destroys all siblings of this node, including link nodes.
     * 
     */
    void destroy_siblings();
    
    /**
     * @brief Create a new tree while prompting for and taking user input from standard I/O streams.
     * @returns Newly created tree node.
     */
    static tree_node* build_tree();

    /**
     * @brief Destroy a node and all its children.
     * 
     * @param doomed the node to be destroyed.
     */
    static void destroy_node(tree_node* doomed);

    /**
     * @brief Deserializes a node object from file.
     * 
     * @param file 
     * @return tree_node* 
     */
    static tree_node* load_node(std::string file);

    /**
     * @brief Outputs the given node to the output stream. Guarantees std::flush on success.
     * 
     * @param os the output stream
     * @param node the node to export to the file stream
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, tree_node* node);

    /**
     * @brief Parses a tree from an input stream. Consumes stream until a blank line or parsing fails.
     * 
     * @param is the input stream
     * @param node the node to parse
     * @return std::istream& 
     */
    friend std::istream& operator>>(std::istream& is, tree_node* node);
};

#endif
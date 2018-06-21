#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Tree::Tree() : root(NULL), parent(NULL) {} 

Node* Tree::newNode(int data)
{
        Node* temp = new Node;
        temp -> value = data;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
}

Node* Tree::insert(Node* parent, int data)
{
        if ( parent == NULL ) {
                parent = newNode (data);           
        } else if ( data <= parent -> value ) {
                parent -> left = insert(parent -> left, data);
        } else {
                parent -> right = insert(parent -> right, data);
        }
        return parent;        
}

void Tree::insert_data(int data)
{
        if ( root == NULL ) {
                root = newNode(data);
        } else {
                insert (root, data);
        }
}

int Tree::left_count(Node* parent, int count)
{
        if (parent != NULL ) {
                if ( parent->left != NULL) {
                        left_count(parent->left, ++count);
                }
        }
        return count;
}

void Tree::postorder(Node* parent, int indent = 4)
{
        //char c = '\';
        if (parent != NULL) {
                std::cout << "  " << parent->value << std::endl;
                if (parent->left != NULL) {
                        std::cout << "/" << "   \\" <<std::endl;
                        postorder(parent->left,indent+4);
                } else {
                        std::cout << "NULL       ";
                }
                if (parent->right != NULL) {
                        postorder(parent->right,indent +4);
                } else {
                        std::cout << "\\" << std::endl;
                        std::cout << "NULL";
                }
                /*if (parent->left != NULL) {
                        std::cout << parent->left->value << "    ";
                }
                if (parent->right != NULL) {
                        std::cout << parent->right->value;
                }
                if(p->left) postorder(p->left, indent+4);
                if(p->right) postorder(p->right, indent+4);
                if (indent) {
                        std::cout << std::setw(indent) << ' ';
                }*/
                std::cout << std::endl;
        }
}       

void Tree::print_postorder()
{
     postorder(root);
}

Node* Tree::min_node(Node* parent)
{
        if(parent == NULL)
                return NULL;
        else if(parent->left == NULL)
                return parent;
        else
                return min_node(parent->left);
}

bool Tree::search(Node* parent, int data)
{

        if ( parent == NULL ) {
                std::cout << "Not found" << std::endl;
                return false;
        }
        if ( data == parent -> value ) {
                std::cout << "Found!!!" << std::endl;
                return true;
        } else if ( data < parent -> value ) {
                search(parent -> left, data);
        } else {
                search(parent -> right, data);
        }      
}

void Tree::find(int data)
{
        search(root, data);
}

Node* Tree::remove_node(Node* parent, int data)
{
        Node* temp;
        if (parent == NULL) {
                return parent;
        } else if ( data < parent -> value) {
                parent -> left = remove_node ( parent -> left, data );
        } else if ( data > parent ->value) {
                parent -> right = remove_node ( parent -> right, data );
        } else {
                if ( (parent -> left == NULL) && (parent -> right == NULL)) {
                        delete parent;
                        parent = NULL;
                        return parent;
                } else if (parent -> left == NULL) {
                        parent = parent -> left;
                        return parent;
                } else if (parent -> right == NULL) {
                        parent =parent -> right;
                        return parent;
                } else {
                        Node* temp = min_node(parent->right);
                        parent->value = temp->value;
                        parent->right = remove_node(parent->right, temp->value);                        
        }
}
}
void Tree::remove(int data)
{
        remove_node(root, data);
}

int get_height( Node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

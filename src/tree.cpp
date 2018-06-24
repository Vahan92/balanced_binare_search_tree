#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

Tree::Tree() : root(NULL), parent(NULL) {} 

Node* Tree::newNode(int data)
{
        Node* temp = new Node;
        temp -> value = data;
        temp -> left = NULL;
        temp -> right = NULL;
        temp -> height = 0;
        return temp;
}

Node* Tree::insert(Node* parent, int data)
{
        if ( parent == NULL ) {
                parent = newNode (data);           
        } else if ( data < parent -> value ) {
                parent -> left = insert(parent -> left, data);
                if(get_height(parent->left) - get_height(parent->right) == 2) {
                if(data < parent->left->value)
                    parent = single_right_rotate(parent);
                else
                    parent = left_right_rotate(parent);
                }
        } else {
                parent -> right = insert(parent -> right, data);
                if(get_height(parent->right) - get_height(parent->left) == 2) {
                if(data > parent->right->value)
                    parent = single_left_rotate(parent);
                else
                    parent = right_left_rotate(parent);
                }
        }
        parent->height = max(get_height(parent->left), get_height(parent->right))+1;
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

int Tree::get_height( Node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

    Node* Tree::single_right_rotate(Node* parent)
    {
        Node* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        parent->height = max(get_height(parent->left), get_height(parent->right))+1;
        temp->height = max(get_height(temp->left), parent->height)+1;
        return temp;
    }

    Node* Tree::single_left_rotate(Node* parent)
    {
        Node* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        parent->height = std::max(get_height(parent->left), get_height(parent->right))+1;
        temp->height = max(get_height(parent->right), parent->height)+1 ;
        return temp;
    }

    Node* Tree::right_left_rotate(Node* parent)
    {
        parent->right = single_right_rotate(parent->right);
        return single_left_rotate(parent);
    }

    Node* Tree::left_right_rotate(Node* parent)
    {
        parent->left = single_left_rotate(parent->left);
        return single_right_rotate(parent);
}

void Tree::print_2d(Node* parent, int indent)
{
    if (parent != nullptr)
    {
        print_2d(parent->right, indent + 4);
        if (indent > 0) {
            std::cout << std::setw(indent) << " ";
        }
        std::cout << parent->value << std::endl;
        print_2d(parent->left, indent + 4);
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
                        temp = min_node(parent->right);
                        parent->value = temp->value;
                        parent->right = remove_node(parent->right, temp->value);   
                }                     
        }
        if(parent == NULL)
            return parent;

        parent->height = max(get_height(parent->left), get_height(parent->right))+1;

        if(get_height(parent->left) - get_height(parent->right) == 2)
        {
            if(get_height(parent->left->left) - get_height(parent->left->right) == 1)
                return single_left_rotate(parent);
            else
                return right_left_rotate(parent);
        }
        else if(get_height(parent->right) - get_height(parent->left) == 2)
        {
            if(get_height(parent->right->right) - get_height(parent->right->left) == 1)
                return single_right_rotate(parent);
            else
                return left_right_rotate(parent);
        }
        return parent;        
}
void Tree::remove(int data)
{
        remove_node(root, data);
}

#include "node.hpp"
#include <string>

class Tree
{
        public:
                Tree();
                Node* newNode(int);
                Node* insert(Node*, int);
                //remove();
                void insert_data(int);
                void postorder(Node*, int);
                void print_postorder();
                bool search(Node*, int);
                void find(int);
                void remove(int);
                Node* remove_node(Node*, int);
                Node* min_node(Node*);
                Node* single_right_rotate(Node*);
                Node* single_left_rotate(Node*);
                Node* double_left_rotate(Node*);
                Node* double_right_rotate(Node*);
                int left_count(Node*, int);
                int get_height(Node*);
                Node* get_root() { return root;};
                void print_2d(Node*, int);
        private:
                Node* root;
                Node* parent;
};

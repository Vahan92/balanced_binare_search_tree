#include "node.hpp"
#include "tree.hpp"
#include <iostream>

int main()
{
        Tree t;
        t.insert_data(90);
        t.insert_data(4);
        t.insert_data(188);
        t.insert_data(3);
        t.insert_data(5);
        t.insert_data(189);
        t.insert_data(15);
        //t.left_count();
        //t.find(189);
        //t.find(35);
        //t.print_postorder();
        //t.remove(189);
        t.print_2d(t.get_root(),1);
        t.remove(4);
        t.print_2d(t.get_root(),1);
        return 0;
}

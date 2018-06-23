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
        t.insert_data(27);
        t.insert_data(9);
        t.insert_data(91);
        t.insert_data(119);
        t.insert_data(129);
        t.insert_data(39);
        t.insert_data(49);
        t.insert_data(59);
        t.insert_data(69);
        t.insert_data(79);
        t.insert_data(29);
        t.insert_data(77);
        t.insert_data(30);
        t.insert_data(21);
        t.insert_data(16);
        //t.left_count();
        //t.find(189);
        //t.find(35);
        //t.print_postorder();
        //t.remove(189);
        t.print_2d(t.get_root(),1);
        t.remove(69);
        t.print_2d(t.get_root(),1);
        return 0;
}

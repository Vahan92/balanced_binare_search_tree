#include "node.hpp"
#include "tree.hpp"
#include <iostream>

int main()
{
        Tree t;
        for(int i = 0; i<= 5; i++) {
                t.insert_data(i);
                t.print_2d(t.get_root(),1);
                std::cout << std::endl << std::endl;
                std::cout << std::endl << std::endl;
        }
        /*t.insert_data(189);
        t.insert_data(27);
        t.insert_data(91);
        t.insert_data(119);
        t.insert_data(129);
        t.insert_data(39);
        t.insert_data(49);*/       
        //t.left_count();
        //t.find(189);
        //t.find(35);
        //t.print_postorder();
        //t.remove(189);
        t.print_2d(t.get_root(),1);
        std::cout << std::endl << std::endl;
        //t.remove(12);
        t.print_2d(t.get_root(),1);
        std::cout << std::endl << std::endl;
        //t.remove(15);
        t.print_2d(t.get_root(),1);
        return 0;
}

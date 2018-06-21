#include <iostream>
#include <errno.h>

void func(int arg)
{
        if (arg < 0) {
                errno = E2BIG; 
        }
}

int main()
{
        func(-35);
        if (E2BIG == errno) {
                std::cout << E2BIG << std::endl;     //notify about the error
        }
        
}

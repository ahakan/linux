#include <iostream>
#include <unistd.h>

int main(int argc, const char** argv)
{
    int i = 0;

    while(1)
    {
        std::cout << "Index: " << i << std::endl;

        i++;

        sleep(10);
    }

    return 0;
}
//
// main.cpp
// Created on 21/10/2018
//

#include "multimedia.h"
using namespace std;
/**
 * @brief main entry point of the program (executable)
 * It is the main function
 *
 * @param argc
 * @param argv
 * @return 0
 */
int main(int argc, const char* argv[])
{
    Multimedia m = Multimedia("my photo", "./media");
    Multimedia *m2 = new Multimedia();
    std::cout << "Hello brave new world" << std::endl;
    m.print(std::cout);
    m2->print(std::cout);
    return (0);
}

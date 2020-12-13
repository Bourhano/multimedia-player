//
// main.cpp
// Created on 21/10/2018
//

#include "multimedia.h"
#include "photo.h"

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
    // initiate things
    //    Multimedia *m = new Photo("my photo", "./media");
    //    Multimedia *m2 = new Photo();
    Photo *p = new Photo(12.3, 3.7, "my first pic", "./media/img1.jpg");
    Photo *p2 = new Photo();

    // output things to std::cout
    std::cout << "Hello brave new world" << std::endl;
    //    m->print(std::cout);
    //    m2->print(std::cout);
    p->print(std::cout);
    p2->print(std::cout);
    //      p->play();

    //destruct all
    std::cout<<std::endl;
    //    delete(m);
    //    delete(m2);
    delete(p);
    delete(p2);
    return (0);
}

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
    Multimedia *m = new Photo("my photo", "./media");
    //    Multimedia *m2 = new Multimedia();
    //    Photo p = Photo(12.3, 3.7, "my first pic", "./media/img1.jpg");
    //    Photo p2 = Photo();

    std::cout << "Hello brave new world" << std::endl;
    m->print(std::cout);
    delete(m);
    //    m2->print(std::cout);
    //    std::cout << "wow" << p.getLatitude() << std::endl;
    //    p.print(std::cout);
    //    p2.print(std::cout);
    return (0);
}

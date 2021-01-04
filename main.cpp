//
// main.cpp
// Created on 21/10/2018
//
#define MAIN_5

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"

/**
 * @brief main entry point of the program (executable)
 * It is the main function
 *
 * @param argc
 * @param argv
 * @return 0
 */
#ifdef MAIN_5
int main(int argc, const char* argv[])
{
    // initialize things
    Photo *p = new Photo();
    Video *v = new Video();
    //int chaps[3] = new int[3](2, 1, 2);
    int *chaps = new int[3];
    chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    Film  *f = new Film("my first vid", "./media/vid1.mp4", 5, 3, chaps);//new int[3] {2, 1, 2});
    Group grp = new Group("first");

    // output things to std::cout
    std::cout << "Hello brave new world" << std::endl;
    p->print(std::cout);
    v->print(std::cout);
    f->print(std::cout);
    grp->print(std::cout);

    // implementation de la septieme etape, ajout des free et delete dans main pour eviteer les fuites.
    delete(v);
    delete(p);
    delete(f);
    return (0);
}
#endif

#ifdef MAIN_4
int main(int argc, const char* argv[])
{
    // initialize things
    Photo *p = new Photo();
    Video *v = new Video();
    //int chaps[3] = new int[3](2, 1, 2);
    int *chaps = new int[3];
    chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    Film  *f = new Film("my first vid", "./media/vid1.mp4", 5, 3, chaps);//new int[3] {2, 1, 2});

    // output things to std::cout
    std::cout << "Hello brave new world" << std::endl;
    p->print(std::cout);
    v->print(std::cout);
    f->print(std::cout);
    chaps = f->getChapters();
    delete[] chaps;
    f->print(std::cout);
    // implementation de la septieme etape, ajout des free et delete dans main pour eviteer les fuites.
    delete(v);
    delete(p);
    delete(f);
    return (0);
}
#endif

#ifdef MAIN_3
int main(int argc, const char* argv[])
{
    // initialize things
    Photo *p = new Photo();
    Video *v = new Video();
    //int chaps[3] = new int[3](2, 1, 2);
    int *chaps = new int[3];
    chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    Film  *f = new Film("my first vid", "./media/vid1.mp4", 5, 3, chaps);//new int[3] {2, 1, 2});

    // output things to std::cout
    std::cout << "Hello brave new world" << std::endl;
    p->print(std::cout);
    v->print(std::cout);
    f->print(std::cout);
    chaps = f->getChapters();
    delete chaps;
    f->print(std::cout);
    delete(v);
    delete(p);
    delete(f);
    return (0);
}
#endif


#ifdef MAIN_2
int main(int argc, const char* argv[])
{
    // initialize things
    int i = 0;
    Photo *p = new Photo("my first pic", "./media/img1.jpg", 12.3, 3.7);
    Photo *p2 = new Photo();
    Video *v = new Video("my first vid", "./media/vid1.mp4", 5);
    Video *v2 = new Video();
    Multimedia *library[2];
    library[0] = p;
    library[1] = v;

    // output things to std::cout
    for (i; i<2; i++)
        library[i]->play();
    p->print(std::cout);
    p2->print(std::cout);
    v->print(std::cout);
    v2->print(std::cout);
    delete(v);
    delete(v2);
    delete(p);
    delete(p2);
    return (0);
}
#endif


#ifdef MAIN_1
int main(int argc, const char* argv[])
{
    // initiate things
    //    Multimedia *m = new Photo("my photo", "./media");
    //    Multimedia *m2 = new Photo();
    Photo *p = new Photo(12.3, 3.7, "my first pic", "./media/img1.jpg");
    Photo *p2 = new Photo();
    Video *v = new Video("5", "my first vid", "./media/vid1.mp4");
    Video *v2 = new Video();
    Multimedia *library[2];
    library[0] = p;
    library[1] = v;

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
#endif

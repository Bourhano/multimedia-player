//
// main.cpp
// Created on 21/10/2018
//
#define MAIN_10
#define PORT 3331
//#define LOW_SECURITY  // only define LOW_SECURITY with MAIN_7 or lower.

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manager.h"
#include "cppsocket.h"
#include "tcpserver.h"

using namespace cppu;

/**
 * @brief main entry point of the program (executable)
 * It is the main function
 *
 * @param argc
 * @param argv
 * @return 0
 */
#ifdef MAIN_10
int main(int argc, const char* argv[])
{
    // create the TCP server
    shared_ptr<TCPServer> server(new TCPServer());

    //populate the 'set-top box' with media
    shared_ptr<Manager> m(new Manager());
    GroupPtr mediaGroup = m->addGroup("mediaGrp");
    MultimediaPtr v = m->addVideo("catVideo", "./media/vid1.mp4", 5, "mediaGrp");
    MultimediaPtr p = m->addPhoto("dogPhoto", "./media/img1.jpg", 12.3, 3.7, "mediaGroup");
    int *chaps = new int[3]; chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    MultimediaPtr f = m->addFilm("catFilm", "./media/vid1.mp4", 5, 3, chaps, "mediaGroup2");
    int status = 0;

    // the server calls this method on each request
    server->setCallback(*m, &Manager::processRequest);

    // start endless server loop guarded with try-catch clause
    try
      {
        cout << "Starting Server on port " << PORT << endl;
        status = server->run(PORT);
        if (status < 0)
            throw(runtime_error("Error launching server!"));
      }
      catch (exception& e)
      {
        cerr << "Could not start Server on port " << PORT << endl;
        cerr << "Exception caught: " << e.what() << '\n';
        return (1);
      }
    return (0);
}
#endif

#ifdef MAIN_9
int main(int argc, const char* argv[])
{
    // create the TCP server
    shared_ptr<TCPServer> server(new TCPServer());

    //populate the 'set-top box' with media
    shared_ptr<Manager> m(new Manager());
    GroupPtr mediaGroup = m->addGroup("mediaGrp");
    MultimediaPtr v = m->addVideo("catVideo", "./media/vid1.mp4", 5, "mediaGrp");
    MultimediaPtr p = m->addPhoto("dogPhoto", "./media/img1.jpg", 12.3, 3.7, "mediaGroup");
    int *chaps = new int[3]; chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    MultimediaPtr f = m->addFilm("catFilm", "./media/vid1.mp4", 5, 3, chaps, "mediaGroup2");
    int status = 0;


    m->searchMultimedia("catFilm", cout);
    //m->playMultimedia("dogFilm", cout);

    // the server calls this method on each request
    server->setCallback(*m, &Manager::processRequest);

    // start endless server loop
    cout << "Starting Server on port " << PORT << endl;
    status = server->run(PORT);

    // in case of error
    if (status < 0) {
        cerr << "Could not start Server on port " << PORT << endl;
        return (1);
    }


    return (0);
}
#endif

#ifdef MAIN_8 //the one where we implement security with
int main(int argc, const char* argv[])
{
    //begin tests
    Manager *m = new Manager();
    GroupPtr mediaGroup = m->addGroup("mediaGrp");
    MultimediaPtr v = m->addVideo("dogFilm", "./media/vid1.mp4", 5, "mediaGrp");
    MultimediaPtr p = m->addPhoto("my first pic", "./media/img1.jpg", 12.3, 3.7, "mediaGroup");
    int *chaps = new int[3]; chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    MultimediaPtr f = m->addFilm("my first film", "./media/vid1.mp4", 5, 3, chaps, "mediaGroup2");

    m->searchMultimedia("dogFilm", std::cout);
    m->playMultimedia("dogFilm", std::cout);

    // terminaison propre
    delete(m);

    return (0);
}
#endif


#ifdef MAIN_7
int main(int argc, const char* argv[])
{
    // initialize things
    MultimediaPtr p(new Photo("my first pic", "./media/img1.jpg", 12.3, 3.7));
    MultimediaPtr v(new Video("my first vid", "./media/vid1.mp4", 5));
    int *chaps = new int[3];
    chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    MultimediaPtr f(new Film("my first film", "./media/vid1.mp4", 5, 3, chaps));

    std::unique_ptr<Group> grp(new Group("firstGrp1"));
    std::unique_ptr<Group> grp2(new Group("secondGrp2"));

    grp->push_front(p);
    grp->push_front(v);
    grp->push_front(f);
    grp2->push_front(f);

    //begin tests
    Manager *m = new Manager();
    GroupPtr mediaGroup = m->addGroup("mediaGrp");
    MultimediaPtr mov = m->addVideo("dogFilm", "./media/vid1.mp4", 5, "mediaGrp");
    m->searchMultimedia("dogFilm", std::cout);
    m->playMultimedia("dogFilm", std::cout);

    // terminaison propre
    delete(m);

    return (0);
}
#endif

#ifdef MAIN_6
int main(int argc, const char* argv[])
{
    // initialize things
    MultimediaPtr p(new Photo());
    MultimediaPtr v(new Video());
    int *chaps = new int[3];
    chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    MultimediaPtr f(new Film("my first vid", "./media/vid1.mp4", 5, 3, chaps));

    Group *grp = new Group("first");
    std::unique_ptr<Group> grp2(new Group("second"));

    // output things to std::cout
    std::cout << "Hello brave new world" << std::endl;
    grp->print(std::cout);
    std::cout << "\nNothing there..." << std::endl;

    // implementation de la septieme etape, ajout des free et delete dans main pour eviteer les fuites.
    grp->push_front(p);
    grp->push_front(v);
    grp->push_front(f);
    grp2->push_front(f);
    grp->pop_front();
    grp->print(std::cout);

    std::cout << "\nThat's all, for now!" << std::endl;

    // terminaison propre
    delete(grp);

    return (0);
}
#endif

#ifdef MAIN_5
int main(int argc, const char* argv[])
{
    // initialize things
    Photo *p = new Photo(); // il faut tester qu'il n'est pas nul!!!
    Video *v = new Video();
    //int chaps[3] = new int[3](2, 1, 2);
    int *chaps = new int[3];
    chaps[0] = 1, chaps[1] = 3, chaps[2] = 2;
    Film  *f = new Film("my first vid", "./media/vid1.mp4", 5, 3, chaps);//new int[3] {2, 1, 2});
    Group *grp = new Group("first");
    Group *grp2 = new Group("second");

    // output things to std::cout
    std::cout << "Hello brave new world" << std::endl;

    grp->print(std::cout);

    std::cout << "\nNothing there..." << std::endl;

    // implementation de la septieme etape, ajout des free et delete dans main pour eviteer les fuites.
    grp->push_front(p);
    grp->push_front(v);
    grp->push_front(f);
    grp->print(std::cout);

    std::cout << "\nThat's all, for now!" << std::endl;

    // terminaison propre
    delete(grp);
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

#ifndef MANAGER_H
#define MANAGER_H
#include <map>
#include "group.h"
#include "film.h"
#include "photo.h"
typedef shared_ptr<Group> GroupPtr;

class Manager
{
private:
    map<string, MultimediaPtr>  media;
    map<string, GroupPtr>       groups;

public:
    Manager(){}

    ~Manager(){std::cout << "au revoir mon geant ordannanceur!" << groupName << "." << std::endl;}

    MultimediaPtr addPhoto(string desc, string path, float lon, float lat, string groupName){
        MultimediaPtr p = new Photo(desc, path, lon, lat);
        media[desc] = p;
        groups[groupName] = p;
        return p;
    }
    MultimediaPtr addVideo(string desc, string path, int duration, string groupName){
        MultimediaPtr vid = new Video(desc, path, duration);
        media[desc] = vid;
        groups[groupName] = vid;
        return vid;
    }
    MultimediaPtr addFilm(string desc, string path, int duration, int *chaps, string groupName){
        MultimediaPtr film = new Film(desc, path, duration, chaps);
        media[desc] = film;
        groups[groupName] = film;
        return film;
    }
}

#endif // MANAGER_H

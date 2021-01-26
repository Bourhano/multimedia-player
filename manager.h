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

    ~Manager(){std::cout << "au revoir mon geant ordannanceur magistrale et magnifique!" << std::endl;}

    MultimediaPtr addPhoto(string desc, string path, float lon, float lat, string groupName){
        MultimediaPtr p(new Photo(desc, path, lon, lat), deletephoto);
        media[desc] = p;
        auto it = groups.find(groupName);
        if(it == groups.end())
            addGroup(groupName);
        groups[groupName]->push_back(p);
        return p;
    }
    MultimediaPtr addVideo(string desc, string path, int duration, string groupName){
        MultimediaPtr vid(new Video(desc, path, duration), deletevideo);
        media[desc] = vid;
        auto it = groups.find(groupName);
        if(it == groups.end())
            addGroup(groupName);
        groups[groupName]->push_back(vid);
        return vid;
    }
    MultimediaPtr addFilm(string desc, string path, int duration, int nbChaps, int *chaps, string groupName){
        MultimediaPtr film(new Film(desc, path, duration, nbChaps, chaps), deletefilm);
        media[desc] = film;
        //check if group exists
        auto it = groups.find(groupName);
        if(it == groups.end())
            addGroup(groupName);
        groups[groupName]->push_back(film);
        return film;
    }
    GroupPtr addGroup(string name){
        GroupPtr group(new Group(name), deletegroup);
        groups[name] = group;
        return group;
    }
    void searchGroup(string name, ostream &outstream){
            auto it = groups.find(name);
            if(it == groups.end())
                outstream << "Le groupe " << name << " n'existe pas." << std::endl;
            else
            {
                outstream << "Here is your requested group:" << std::endl;
                it->second->print(outstream);
            }
    }
    void searchMultimedia(string name, ostream &outstream){
            auto it = media.find(name);
            if(it == media.end())
                outstream << "The multimedia named " << name << " doesn't exist." << std::endl;
            else
            {
                outstream << "Here is your requested media:" << std::endl;
                it->second->print(outstream);
            }
    }
    void playMultimedia(string name, ostream &outstream){
            auto it = media.find(name);
            if(it == media.end())
                outstream << "Unable to play " << name << ". The file was not found." << std::endl;
            else
            {
                outstream << "Your requested media is being played." << std::endl;
                it->second->play();
            }
    }

    //TODO: void deleteMultimedia(string name);
    //TODO: void deleteGroup(string groupName);
};

#endif // MANAGER_H

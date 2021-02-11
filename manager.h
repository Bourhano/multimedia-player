#ifndef MANAGER_H
#define MANAGER_H
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include "group.h"
#include "film.h"
#include "photo.h"
#include "cppsocket.h"
#include "tcpserver.h"

using namespace cppu;

typedef shared_ptr<Group> GroupPtr;

class Manager
{
private:
    map<string, MultimediaPtr>  media;
    map<string, GroupPtr>       groups;

    // a quick correspondence between a string and its relevant function
    // this helps avoid a switch-case conditional
    // in a standard response or no response application type.
    // we implement it that way in this application.
    map<string, void (Manager::*)(string, ostream&)> functions;

public:
    Manager(){
        functions["play"] = &Manager::playMultimedia;
        functions["find-multimedia"] = &Manager::searchMultimedia;
        functions["find-group"] = &Manager::searchGroup;
        functions["list"] = &Manager::listGroups;
    }

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
            outstream << "The group " << name << " does not exist." << std::endl;
        else
        {
            outstream << "Here is your requested group:" << std::endl;
            it->second->print(outstream);
        }
    }

    void listGroups(string none, ostream &outstream){
        outstream << "Here are the available groups with their content:" << std::endl;
        for (auto it = groups.begin(); it != groups.end(); ++it)
        {
          outstream << "- Group '" << it->first << "':" << std::endl;
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
    /**
     * @brief plays the requested multimedia
     * @param name: the name of the requested multimedia element.
     * @param outstream: the output stream to reply to in case of error or success.
     */
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

    /**
     * @brief This function handles the request of any client, treats it and sends back the answer.
     *
     * @param cnx: the TCPConnection in the origin of the request.
     * @param request: the string containing the request to treat.
     * @param response: the string containing the response to return.
     */
    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
        stringstream requestStream, responseStream;
        string action, eltName, terminal;

        cerr << "\nRequest: '" << request << "'" << endl;

        requestStream << request;
        requestStream >> action >> eltName;

        TCPLock lock(cnx);

        auto it = functions.find(action);
        if (it != functions.end()){
            (this->*functions[action])(eltName, responseStream);
            response = responseStream.str();
            terminal = response; //object copy
            std::replace(response.begin(), response.end(), '\n', '%');
        }
        else
            response = "The requested function was not found!%";

        cerr << "response: " << terminal << endl;

        // return false in case you want to close the client's connection with the server
        return true;
    }
    //TODO: void deleteMultimedia(string name);   map::erase() remove it from any other group.
    //TODO: void deleteGroup(string groupName);
};

#endif // MANAGER_H

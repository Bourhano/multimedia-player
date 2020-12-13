#include "multimedia.h"

Multimedia::Multimedia(){
    title = "untitled";
    pathName = "./";
}

Multimedia::Multimedia(string fileTitle,string fullPath){
    title = fileTitle;
    pathName = fullPath;
}

Multimedia::~Multimedia(){
    std::cout<< "au revoir" << std::endl;
}

string Multimedia::getTitle() const{
    return title;
}

string Multimedia::getPathName() const{
    return pathName;
}

void Multimedia::setTitle(string name){
    title = name;
}

void Multimedia::setPathName(string fullpath){
    pathName = fullpath;
}

void Multimedia::print(ostream &outstream) const{
    outstream << "Title: " << getTitle()
              << "\nPath: " << getPathName()
              << std::endl; //better than \n when multi-threading
}


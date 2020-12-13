#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <string>
using namespace std;

class Multimedia
{
private:
    string title;
    string pathName;

public:
    /**
     * @brief Multimedia::Multimedia default constructor for the class Multimedia
     */
    Multimedia();

    /**
     * @brief Multimedia::Multimedia constructor that takes arguments as initial values
     *
     * @param fileTitle: chosen file name
     * @param fullPath: full file path with extension
     */
    Multimedia(string fileTitle, string fullPath);

    /**
     * @brief Multimedia::~Multimedia : class destructor, goodbye!
     */
    virtual ~Multimedia();

    /**
     * @brief Multimedia::getTitle
     *
     * @return value of the title
     */
    string getTitle() const;

    /**
     * @brief Multimedia::getPathName
     *
     * @return value of the full path name
     */
    string getPathName()const;

    /**
     * @brief Multimedia::setTitle
     *
     * @param name value to set as title
     */
    void setTitle(string name);

    /**
     * @brief Multimedia::setPathName
     *
     * @param fullpath value of the full path to be set
     */
    void setPathName(string fullpath);

    /**
     * @brief Multimedia::print
     *
     * @param outstream the output stream to be specified to write into
     */
    virtual void print(ostream &outstream) const;

    /**
     * @brief play a virtual method to play the referenced multimedia
     * @param m the multimedia to play
     */
    //virtual void play(Multimedia m);

};

#endif // MULTIMEDIA_H

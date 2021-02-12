#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"

class Video : public Multimedia
{
private:
    int duration{};

#ifdef LOW_SECURITY
public:
#endif

    /**
     * @brief Trivial Video constructor
     */
    Video(){}

    Video(string desc, string path):Multimedia(desc, path){}

    Video(string desc, string path, int d):Multimedia(desc, path){duration = d;}

    ~Video(){std::cout<< "au revoir bon video" << std::endl;}

#ifndef LOW_SECURITY
public:
    friend class Manager;
    friend class Film;
    friend void deletevideo(Video *);
#endif

    void setDuration(int d) {duration = d;}

    float getDuration() const {return duration;}

    /**
     * @brief print: sends the Video description to the defined stream
     * @param outstream: where to send the output
     */
    void print(ostream &outstream) const override {
        Multimedia::print(outstream);
        outstream << "Duration: " << duration << std::endl;
    }

    /**
     * @brief play: calls the command to play the video
     */
    void play() const override{
        string cmd = "mpv " + getPathName() + " &";
        system(cmd.c_str());
    }
};

void deletevideo(Video *v){
    delete v;
}
#endif // VIDEO_H

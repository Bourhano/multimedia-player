#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"

class Photo : public Multimedia
{
private:
    float longitude{}, latitude{};
    friend class Manager;

#ifdef LOW_SECURITY
public:
#endif
    /**
     * @brief Photo
     */
    Photo(){}

    /**
     * @brief Photo
     * @param desc is the title of the Photo
     * @param path is the full path of the Photo
     */
    Photo(string desc, string path):Multimedia(desc, path){}

    /**
     * @brief Photo
     * @param lon is the longitude of the Photo
     * @param lat is the latitude of the Photo
     * @param desc is the title of the Photo
     * @param path is the full path of the Photo
     */
    Photo(string desc, string path, float lon, float lat):Multimedia(desc, path){longitude = lon; latitude = lat;}

    ~Photo(){std::cout<< "au revoir bonne image" << std::endl;}

#ifndef LOW_SECURITY
public:
    friend class Manager;
    friend void deletephoto(Photo *);
#endif

    void setLongitude(float lon) {longitude = lon;}
    void setLatitude(float lat) {latitude = lat;}

    float getLongitude() const {return longitude;}
    float getLatitude() const {return latitude;}

    void print(ostream &outstream) const override {
        Multimedia::print(outstream);
        outstream << "Longitude: " << longitude << std::endl <<
                     "Latitude: " << latitude << std::endl;
    }

    void play() const override{
        string cmd = "imagej " + getPathName() + " &";
        system(cmd.c_str());
    }
};
void deletephoto(Photo *p){
    delete p;
}
#endif // PHOTO_H

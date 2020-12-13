#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"

class Photo : public Multimedia
{
private:
    float longitude{}, latitude{};
public:
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
    Photo(float lon, float lat, string desc, string path):Multimedia(desc, path){longitude = lon; latitude = lat;}

    ~Photo(){std::cout<< "au revoir bonne image" << std::endl;}

    float getLongitude() const {return longitude;}
    float getLatitude() const {return latitude;}

    void print(ostream &outstream) const override {
        Multimedia::print(outstream);
        outstream << "Longitude: " << longitude << std::endl <<
                     "Latitude: " << latitude << std::endl;
    }

    void play() const override{
        string cmd = "imagej " + getPathName();// + " &";
        system(cmd.c_str());
    }
};
#endif // PHOTO_H

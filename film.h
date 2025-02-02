#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video
{
private:
    int chaptersNb{}, *chapters = nullptr;

#ifdef LOW_SECURITY
public:
#endif

    /**
     * @brief Trivial Video constructor
     */
    Film(){}

    Film(const string desc, const string path):Video(desc, path){}

    Film(const string desc, const string path, int d, int nb, int *chaps):Video(desc, path, d){
        chaptersNb = nb;
        chapters = new int[chaptersNb];
        for (int i = 0; i < nb; i++)
            chapters[i] = chaps[i];
    }

    ~Film(){
        delete[] chapters;
        std::cout<< "au revoir bon video chapitre'" << std::endl;
    }
#ifndef LOW_SECURITY
public:
    friend class Manager;
    friend void deletefilm(Film *);
#endif
    void setChaptersNb(int nb) {chaptersNb = nb;}
    void setChapters (int *chaps, int nb) {
        if (chapters)
            delete[] chapters;
        if (chaptersNb != nb)
            chaptersNb = nb;
        chapters = new int[chaptersNb];
        for (int i = 0; i < nb; i++)
            chapters[i] = chaps[i];
    }

    int getChaptersNb() const {return chaptersNb;}
    int *getChapters() const {
        int * t = new int[chaptersNb];
        for (int i = 0; i < chaptersNb; i++)
            t[i] = chapters[i];
        return (t);
    }

    /**
     * @brief print outputs the Film description to the @outstream
     * @param outstream
     */
    void print(ostream &outstream) const override {
        Video::print(outstream);
        outstream << "Chapters: " << std::endl;
        for (int i = 0; i < chaptersNb; i++)
            outstream << "  Chapter " << i + 1 << ": " << chapters[i] << "s" << std::endl;
    }
};

void deletefilm(Film *f){
    delete f;
}
#endif // FILM_H

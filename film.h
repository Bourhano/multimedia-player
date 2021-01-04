#ifndef FILM_H
#define FILM_H

class Film : public Video
{
private:
    int chaptersNb{}, *chapters = nullptr;
public:
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

    void print(ostream &outstream) const override {
        Video::print(outstream);
        outstream << "Chapters: " << std::endl;
        for (int i = 0; i < chaptersNb; i++)
            outstream << "  Chapter " << i + 1 << ": " << chapters[i] << "s" << std::endl;
    }
};

#endif // FILM_H

#ifndef FILM_H
#define FILM_H

class Film : public Video
{
private:
    int chaptersNb = 0, *chapters = nullptr;
public:
    /**
     * @brief Trivial Video constructor
     */
    Film(){}

    Film(string desc, string path):Video(desc, path){}

    Film(string desc, string path, int d, int nb, int *chaps):Video(desc, path, d){
        chaptersNb = nb;
        chapters = new int[chaptersNb];
        for (int i = 0; i < nb; i++)
            *(chapters++) = *(chaps++);
    }

    ~Film(){
        delete[] chapters;
        std::cout<< "au revoir bon video chapitre'" << std::endl;
    }

    void setChaptersNb(int nb) {chaptersN = nb;}
    void setChapters (int *chaps, int nb) {
        if (chapters)
            delete[] chapters;
        if (chaptersNb != nb)
            chaptersNb = nb;
        chapters = new int[chaptersNb];
        for (int i = 0; i < nb; i++)
            *(chapters++) = *(chaps++);
    }

    void print(ostream &outstream) const override {
        Video::print(outstream);
        outstream << "Chapters: " << duration << std::endl;
        for (int i = 0; i < chaptersNb; i++)
            outstream << "Chapter" << i << ": " << chapters[i] << std::endl;
    }
};

#endif // FILM_H

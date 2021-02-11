#ifndef GROUP_H
#define GROUP_H
#include "multimedia.h"
#include <memory>
#include <list>

typedef shared_ptr<Multimedia> MultimediaPtr;

//class Group : public list<Multimedia *> //: public Multimedia to inherit or not to inherit, that is the question
class Group : public list<MultimediaPtr>
{
private:
    //int nbMedia{};
    string groupName{};

#ifdef LOW_SECURITY
public:
#endif

    Group(const string name){
        groupName = name;
    }

    ~Group(){std::cout << "au revoir ma chouette groupe " << groupName << "." << std::endl;}

#ifndef LOW_SECURITY
public:
    friend class Manager;
    friend void deletegroup(Group *);
#endif

    string getGroupName() const {return groupName;}

    void print(ostream &outstream) const{
        //outstream << "Here is the group:" << std::endl;
        for (auto it = this->begin(); it != this->end(); it++) {
            (*it)->print(outstream);
        }
        outstream << "----------------------------" << std::endl;
    }
};

void deletegroup(Group *g){
    delete g;
}
#endif // GROUP_H

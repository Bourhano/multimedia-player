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
public:
    Group(const string name){
        groupName = name;
    }

    ~Group(){std::cout << "au revoir ma chouette groupe " << groupName << "." << std::endl;}

    string getGroupName() const {return groupName;}

    void print(ostream &outstream) const{
        outstream << "Here is the group:" << std::endl;
        for (auto it = this->begin(); it != this->end(); it++) {
            (*it)->print(outstream);
        }
        outstream << "----------------------------" << std::endl;
    }
};
#endif // GROUP_H

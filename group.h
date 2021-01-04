#ifndef GROUP_H
#define GROUP_H
#include "multimedia.h"
#include <list>

class Group : public list<Multimedia> //: public Multimedia to inherit or not to inherit, that is the question
{
private:
    int nbMedia{};
    string groupName{};
public:
    Group(const string name){
        groupName = name;
    }

    ~Group(){std::cout << "au revoir ma chouette groupe " << groupName << "." << std::endl;}

    string getGroupName() const {return groupName;}

    void print(ostream &outstream) const{
        for (Multimedia medium : this) {
            medium.print(std::cout);
        }
    }
};
#endif // GROUP_H

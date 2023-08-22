//
// Created by Matteo Annunziata on 18/08/2023.
//

#ifndef MATTEOANNUNZIATA_PROGETTOLABORATORIO_OBSERVER_H
#define MATTEOANNUNZIATA_PROGETTOLABORATORIO_OBSERVER_H


#include <string>

using namespace std;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(const string &listName) = 0;

};


#endif //MATTEOANNUNZIATA_PROGETTOLABORATORIO_OBSERVER_H

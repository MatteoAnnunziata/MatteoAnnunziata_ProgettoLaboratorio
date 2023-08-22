//
// Created by Matteo Annunziata on 18/08/2023.
//

#ifndef MATTEOANNUNZIATA_PROGETTOLABORATORIO_SUBJECT_H
#define MATTEOANNUNZIATA_PROGETTOLABORATORIO_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o) = 0;

    virtual void unsubscribe(Observer *o) = 0;

    virtual void notify() = 0;

    virtual ~Subject() = default;
};

#endif //MATTEOANNUNZIATA_PROGETTOLABORATORIO_SUBJECT_H

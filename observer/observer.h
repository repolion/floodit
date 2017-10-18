#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

namespace oli{

class Observable;

/*!
 * \brief The Observer class
 * Implemented by the class that have to Observe another class(observable)
 */
class Observer{

protected:
    std::list<Observable*> m_list;
    typedef std::list<Observable*>::iterator iterator;
    typedef std::list<Observable*>::const_iterator const_iterator;
    virtual ~Observer() = 0;

public:
    virtual void Update()=0;

    void AddObs(Observable* obs);
    void DelObs(Observable* obs);
};

}

#endif // OBSERVER_H

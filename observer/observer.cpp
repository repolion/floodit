#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "observer.h"
#include "observable.h"

namespace oli{

Observer::~Observer(){

    const_iterator ite=m_list.end();

    for(iterator itb=m_list.begin();itb!=ite;++itb){
        (*itb)->DelObs(this);
    }
}

void Observer::AddObs( Observable* obs){
    m_list.push_back(obs);
}

void Observer::DelObs(Observable* obs){

    iterator it= std::find(m_list.begin(),m_list.end(),obs);
    if(it != m_list.end())
        m_list.erase(it);
}

}

#include "observable.h"
#include "observer.h"

namespace oli{

void Observable::AddObs( Observer* obs){
    m_list.push_back(obs);
    obs->AddObs(this);
}

void Observable::DelObs(Observer* obs){
    iterator it= find(m_list.begin(),m_list.end(),obs);
    if(it != m_list.end())
        m_list.erase(it);
}

Observable::~Observable(){
    iterator itb=m_list.begin();
    const_iterator ite=m_list.end();

    for(;itb!=ite;++itb){
        (*itb)->DelObs(this);
    }
}

void Observable::Notify(void){
    iterator itb=m_list.begin();
    const_iterator ite=m_list.end();

    for(;itb!=ite;++itb){
        (*itb)->Update();
    }
}

}

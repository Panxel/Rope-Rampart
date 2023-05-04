#include "sujet.hpp"

void Sujet :: addObserver(observer_ptr observer){
    vectorObserver_.push_back(observer);
}
void Sujet :: removeObserver(observer_ptr observer){
    vectorObserver_.erase(std::find(vectorObserver_.begin(),vectorObserver_.end(),observer));
}
void Sujet :: notifyObserver(){
    for(observer_ptr observer : vectorObserver_){
        observer->update();
    }
}
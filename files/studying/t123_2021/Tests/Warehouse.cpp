#include <iostream>
#include "Warehouse.h"

Warehouse::Warehouse() {}

list<Packer> Warehouse::getPackers(){
    return packers;
}

void Warehouse::addPacker(const Packer &p) {
    packers.push_back(p);
}

list<stack<Order *>> Warehouse::getOrders() const {
    return processedOrders;
}

void Warehouse::setOrders(list<stack<Order *> > so) {
    processedOrders = so;
}


//=============================================================================
//TODO:



void Warehouse::sortPackers() {
    packers.sort();
}


//TODO:
unsigned Warehouse::removePackers(unsigned nOrders) {
    unsigned result = 0;
    for(auto it = packers.begin(); it != packers.end(); it++){
        if(it->getOrderQueue().size() < nOrders){
            result+= it->getOrderQueue().size();
            it = packers.erase(it);
            it--;
        }
    }
    return result;
}

//TODO:
void Warehouse::addPacker(unsigned idPacker, string namePacker) {
    Packer packer(idPacker,namePacker);
    for(auto it = packers.begin(); it != packers.end(); it++){
        if(it->getOrderQueue().size() >= 2){
            packer.addOrder(it->getOrderQueue().front());
            it->removeOrder();
        }
    }
    packers.push_back(packer);
}

//TODO:
bool Warehouse::addToShorterQueue(Order* o) {
    if(packers.empty()) return false;
    int min = -30000, id;
    bool equal = false;
    for(auto it = packers.begin() ; it != packers.end(); it++){
        if(it->getOrderQueue().size() <= min){
            if(!it->getOrderQueue().size() == min){
                min = it->getOrderQueue().size();
                id = it->getIdPacker();
            }else{
                equal = true;
            }

        }
    }
    for(auto it = packers.begin() ; it != packers.end(); it++){
        if(id == it->getIdPacker()){
            it->addOrder(o);
            return true;
        }
    }
    return true;
}

//TODO:
unsigned Warehouse::processOrderByDeliveryType(string deliveryType, unsigned n) {
    unsigned num_max= n;
    unsigned orders=0;
    stack<Order*> selected;
    auto order=processedOrders.begin();
    for( auto it = processedOrders.begin(); it!= processedOrders.end(); it++){
        if (it->top()->getDeliveryType()==deliveryType){
            selected= *it;
            order=it;
            break;
        }
    }
    if (n > selected.size()){
        orders=selected.size();
        processedOrders.erase(order);
    }
    else if (n== selected.size()){
        orders=n;
        processedOrders.erase(order);
    }
    else{
        orders=n;
        for(int i = 0; i < n; i++){
            order->pop();
        }
    }
    return orders;
}

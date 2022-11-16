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
    auto last = packers.end();
    last--;
    for(auto it1 = packers.begin(); it1 != last; it1++){
        for(auto it = packers.begin(); it != last;){
            auto next = it++;
            if(it->getOrderQueue().size() < next->getOrderQueue().size()  ){
                swap(it,next);
            }else if(it->getOrderQueue().size() == next->getOrderQueue().size()){
                if(it->getNamePacker() > next->getNamePacker()){
                    swap(it,next);
                }else if(it->getNamePacker() == next->getNamePacker()){
                    if(it->getIdPacker() > next->getIdPacker()){
                        swap(it,next);
                    }
                }
            }
            it++;

        }
    }

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
    if(packers.size() == 0) return false;
    int min = INT32_MAX, i = 0, num, another;
    for(auto it = packers.begin(); it != packers.end(); it++){
        if(it->getOrderQueue().size() < min){
            num = i;
        }else if(it->getOrderQueue().size() == min){
            another = 1;
        }
        i++;
    }
    i = 0;
    for(auto it = packers.begin(); it != packers.end(); it++){
        if(another == 1){
            packers.front().addOrder(o);
            return true;
        }
        if(i == num){
            it->addOrder(o);
            return true;
        }
        i++;
    }
}

//TODO:
unsigned Warehouse::processOrderByDeliveryType(string deliveryType, unsigned n) {
    unsigned num_max= n;
    unsigned orders=0;
    stack<Order*> selected;
    auto itr=processedOrders.begin();
    for( auto it = processedOrders.begin(); it!= processedOrders.end(); it++){
        if ((*it).top()->getDeliveryType()==deliveryType){
            selected= *it;
            itr=it;
            break;
        }
    }
    if (n > selected.size()){
        orders=selected.size();
        processedOrders.erase(itr);
    }
    else if (n== selected.size()){
        orders=n;
        processedOrders.erase(itr);
    }
    else{
        orders=n;
        for(int i = 0; i < n; i++){
            itr->pop();
        }
    }
    return orders;
}

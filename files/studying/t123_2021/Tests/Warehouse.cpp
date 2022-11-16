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
/*
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
    que ordena a lista de trabalhadores (packers) por ordem decrescente de volume de encomendas na sua
bancada (número de encomendas em myOrderQueue). Em caso de igualdade, a ordenação é realizada por
ordem alfabética do nome do trabalhador (namePacker) e, em caso de nova igualdade, a ordenação é
realizada por ordem crescente do código de identificação do trabalhador (idPacker)



}*/

bool comparePackers(const Packer &p1,const Packer &p2 ){
    //decrescente
    if( p1.getOrderQueue().size() > p2.getOrderQueue().size()){
        return true;
    }
    if( p1.getOrderQueue().size() < p2.getOrderQueue().size()){
        return false;
    }
    //alfabetica
    if( p1.getNamePacker() < p2.getNamePacker()){
        return true;
    }
    if( p1.getNamePacker() > p2.getNamePacker()){
        return false;
    }
    return p1.getIdPacker() < p2.getIdPacker();
}
void Warehouse::sortPackers() {
    packers.sort(comparePackers);
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
    int pos;
    int min  = (int)packers.begin()->getOrderQueue().size();
    bool equal = false;
    for(auto it = packers.begin(); it != packers.end(); it++){
        if(it->getOrderQueue().size() <= min){
            min = (int)it->getOrderQueue().size();
            pos = (int)distance(packers.begin(),it);
            if(it->getOrderQueue().size() == min) equal = true;
        }
    }
    if(equal){packers.begin()->addOrder(o);return true;}

    for(auto it = packers.begin(); it != packers.end(); it++){
        if(distance(packers.begin(),it) == pos){
            it->addOrder(o);
            return true;
        }
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

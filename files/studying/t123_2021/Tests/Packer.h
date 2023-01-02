#ifndef AED2122_CI1_PACKER_H
#define AED2122_CI1_PACKER_H

#include <string>
#include <queue>
#include "Order.h"

using namespace std;

class Packer {
    unsigned idPacker;
    string namePacker;
    queue<Order *> myOrderQueue;
public:
    Packer(unsigned idPacker, string namePacker);
    unsigned getIdPacker() const;
    string getNamePacker() const;
    queue<Order *> getOrderQueue() const;
    void addOrder(Order *o);
    void removeOrder();
    bool operator==(const Packer& packer){
        return this->idPacker == packer.idPacker;
    }
    bool operator<(const Packer& p2){
        if( getOrderQueue().size() > p2.getOrderQueue().size()){
            return true;
        }
        if( getOrderQueue().size() < p2.getOrderQueue().size()){
            return false;
        }
        //alfabetica
        if( getNamePacker() < p2.getNamePacker()){
            return true;
        }
        if( getNamePacker() > p2.getNamePacker()){
            return false;
        }
        return getIdPacker() < p2.getIdPacker();
    }
};

#endif //AED2122_CI1_PACKER_H

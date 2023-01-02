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
};

#endif //AED2122_CI1_PACKER_H

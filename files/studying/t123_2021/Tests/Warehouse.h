#ifndef AED2122_CI1_WAREHOUSE_H
#define AED2122_CI1_WAREHOUSE_H

#include <vector>
#include <list>
#include <stack>
#include "Packer.h"

class Warehouse {
    list<Packer> packers;
    list<stack<Order *>> processedOrders;
public:
    Warehouse();
    list<Packer> getPackers();
    void addPacker(const Packer &p);
    list<stack<Order *>> getOrders() const;
    void setOrders(list<stack<Order *> > so);
    void sortPackers();
    unsigned removePackers(unsigned nOrders);
    void addPacker(unsigned idPacker, string namePacker);
    bool addToShorterQueue(Order *o);
    unsigned processOrderByDeliveryType(string deliveryType, unsigned n);
};

#endif //AED2122_CI1_WAREHOUSE_H

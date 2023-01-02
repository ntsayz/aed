#ifndef AED2122_CI1_ORDER_H
#define AED2122_CI1_ORDER_H

#include <string>

using namespace std;

class Order {
    string orderNumber;
    string deliveryType;
public:
    Order(string orderNumber, string deliveryType);
    string getOrderNumber() const;
    string getDeliveryType() const;
};

#endif //AED2122_CI1_ORDER_H

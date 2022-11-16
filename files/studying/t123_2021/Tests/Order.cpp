#include "Order.h"

Order::Order(string orderNumber, string deliveryType) : orderNumber(orderNumber),
                                                        deliveryType(deliveryType) {}

string Order::getOrderNumber() const {
    return orderNumber;
}

string Order::getDeliveryType() const {
    return deliveryType;
}

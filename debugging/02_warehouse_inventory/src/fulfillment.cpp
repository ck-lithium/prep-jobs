#include "fulfillment.h"

#include <stdexcept>

Fulfillment::Fulfillment(Inventory& inventory) : inventory_(inventory) {}

int Fulfillment::placeOrder(const std::vector<OrderLine>& lines) {
    for (const OrderLine& line : lines) {
        if (!inventory_.reserve(line.sku, line.quantity)) return -1;
    }
    int id = ++lastId_;
    orders_.emplace(id, Order{lines, OrderStatus::Placed});
    return id;
}

void Fulfillment::cancel(int orderId) {
    Order& order = orders_.at(orderId);
    for (const OrderLine& line : order.lines) inventory_.release(line.sku, line.quantity);
    order.status = OrderStatus::Cancelled;
}

void Fulfillment::ship(int orderId) {
    Order& order = orders_.at(orderId);
    if (order.status != OrderStatus::Placed) {
        throw std::logic_error("order " + std::to_string(orderId) + " can't be shipped");
    }
    for (const OrderLine& line : order.lines) inventory_.ship(line.sku, line.quantity);
    order.status = OrderStatus::Shipped;
}

OrderStatus Fulfillment::status(int orderId) const { return orders_.at(orderId).status; }

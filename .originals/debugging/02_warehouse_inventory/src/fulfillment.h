#pragma once

#include <map>
#include <ostream>
#include <string>
#include <vector>

#include "inventory.h"

struct OrderLine {
    std::string sku;
    unsigned quantity;
};

enum class OrderStatus { Placed, Shipped, Cancelled };

inline std::ostream& operator<<(std::ostream& out, OrderStatus status) {
    switch (status) {
        case OrderStatus::Placed: return out << "Placed";
        case OrderStatus::Shipped: return out << "Shipped";
        case OrderStatus::Cancelled: return out << "Cancelled";
    }
    return out;
}

// Takes customer orders and keeps the inventory in step with them.
//
// Rules:
//   - An order is all or nothing: if any line can't be reserved, the order is
//     rejected and nothing stays reserved for it.
//   - Cancelling an order gives its units back. Cancelling an order that is
//     already cancelled does nothing. A shipped order can't be cancelled.
class Fulfillment {
public:
    explicit Fulfillment(Inventory& inventory);

    // Reserves stock for every line. Returns the new order's ID (IDs start
    // at 1), or -1 if the order was rejected for lack of stock.
    int placeOrder(const std::vector<OrderLine>& lines);

    // Throws std::logic_error if the order has already shipped, and
    // std::out_of_range for an unknown order ID.
    void cancel(int orderId);

    // Ships a placed order. Throws std::logic_error if it isn't Placed, and
    // std::out_of_range for an unknown order ID.
    void ship(int orderId);

    // Throws std::out_of_range for an unknown order ID.
    OrderStatus status(int orderId) const;

private:
    struct Order {
        std::vector<OrderLine> lines;
        OrderStatus status;
    };

    Inventory& inventory_;
    std::map<int, Order> orders_;
    int lastId_ = 0;
};

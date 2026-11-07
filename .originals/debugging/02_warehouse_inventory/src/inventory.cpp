#include "inventory.h"

#include <stdexcept>

void Inventory::receive(const std::string& sku, unsigned quantity) {
    stock_[sku].onHand += quantity;
}

bool Inventory::reserve(const std::string& sku, unsigned quantity) {
    auto it = stock_.find(sku);
    if (it == stock_.end()) return false;
    Stock& stock = it->second;
    if (stock.onHand - stock.reserved - quantity < 0) return false;
    stock.reserved += quantity;
    return true;
}

void Inventory::release(const std::string& sku, unsigned quantity) {
    stock_.at(sku).reserved -= quantity;
}

void Inventory::ship(const std::string& sku, unsigned quantity) {
    Stock& stock = stock_.at(sku);
    if (quantity > stock.reserved) {
        throw std::logic_error("can't ship more units of " + sku + " than were reserved");
    }
    stock.reserved -= quantity;
    stock.onHand -= quantity;
}

unsigned Inventory::available(const std::string& sku) {
    Stock& stock = stock_[sku];
    return stock.onHand - stock.reserved;
}

unsigned Inventory::onHand(const std::string& sku) {
    return stock_[sku].onHand;
}

std::vector<std::string> Inventory::lowStock(unsigned threshold) const {
    std::vector<std::string> skus;
    for (const auto& entry : stock_) {
        const Stock& stock = entry.second;
        if (stock.onHand - stock.reserved <= threshold) skus.push_back(entry.first);
    }
    return skus;
}

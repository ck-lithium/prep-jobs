#pragma once

#include <map>
#include <string>
#include <vector>

// Stock levels per SKU (product code) in one warehouse.
//
// "On hand" is what is physically on the shelves. Part of it can be
// "reserved" for orders that haven't shipped yet. The rest is "available"
// to sell.
class Inventory {
public:
    // Puts `quantity` new units of `sku` on the shelves.
    void receive(const std::string& sku, unsigned quantity);

    // Reserves `quantity` units for an order. Returns false, and reserves
    // nothing, if fewer than `quantity` units are available.
    bool reserve(const std::string& sku, unsigned quantity);

    // Gives back units that were reserved, e.g. for a cancelled order.
    void release(const std::string& sku, unsigned quantity);

    // Ships reserved units: they leave the shelves and stop being reserved.
    void ship(const std::string& sku, unsigned quantity);

    // Units that can still be sold. 0 for a SKU we have never stocked.
    unsigned available(const std::string& sku);

    // Units physically on the shelves. 0 for a SKU we have never stocked.
    unsigned onHand(const std::string& sku);

    // SKUs we stock that have `threshold` or fewer units available, so
    // purchasing can reorder them. Sorted by SKU.
    std::vector<std::string> lowStock(unsigned threshold) const;

private:
    struct Stock {
        unsigned onHand = 0;
        unsigned reserved = 0;
    };
    std::map<std::string, Stock> stock_;
};

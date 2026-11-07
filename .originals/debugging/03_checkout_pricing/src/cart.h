#pragma once

#include <string>
#include <vector>

struct CartItem {
    std::string sku;
    int unitPriceCents = 0;
    int quantity = 0;
    bool inStock = true;
};

// A shopping cart. Prices are in cents, to avoid floating-point rounding.
class Cart {
public:
    // Adds units of a product. Adding a SKU that is already in the cart
    // increases its quantity instead of adding a second line.
    void add(const std::string& sku, int unitPriceCents, int quantity);

    // Marks a product as in or out of stock. Unknown SKUs are ignored.
    void setInStock(const std::string& sku, bool inStock);

    // Removes every out-of-stock item and keeps the others in their order.
    void removeOutOfStock();

    // Sum of unit price × quantity over all items.
    int subtotalCents() const;

    const std::vector<CartItem>& items() const;

private:
    std::vector<CartItem> items_;
};

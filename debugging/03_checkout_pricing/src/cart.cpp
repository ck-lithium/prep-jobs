#include "cart.h"

void Cart::add(const std::string& sku, int unitPriceCents, int quantity) {
    for (CartItem& item : items_) {
        if (item.sku == sku) {
            item.quantity += quantity;
            return;
        }
    }
    items_.push_back({sku, unitPriceCents, quantity, true});
}

void Cart::setInStock(const std::string& sku, bool inStock) {
    for (CartItem& item : items_) {
        if (item.sku == sku) item.inStock = inStock;
    }
}

void Cart::removeOutOfStock() {
    for (std::size_t i = 0; i < items_.size(); i++) {
        if (!items_[i].inStock) items_.erase(items_.begin() + i);
    }
}

int Cart::subtotalCents() const {
    int total = 0;
    for (const CartItem& item : items_) total += item.unitPriceCents * item.quantity;
    return total;
}

const std::vector<CartItem>& Cart::items() const { return items_; }

#pragma once

#include <string>
#include <vector>

#include "cart.h"
#include "coupon.h"

struct Receipt {
    int subtotalCents = 0;
    int discountCents = 0;
    int shippingCents = 0;
    int totalCents = 0;  // subtotal - discount + shipping
};

// Prices a cart: coupons first, then shipping.
//
// Rules:
//   - Coupon codes are case-insensitive: "save10" and "SAVE10" are the same coupon.
//   - A coupon can only be applied if the cart's subtotal is at least the
//     coupon's minimum, and each coupon can be applied only once. Different
//     coupons can be combined.
//   - Each coupon takes its percentage off the subtotal, rounded down to whole
//     cents. The discounts from different coupons add up.
//   - Shipping costs €4.99. It's free when the subtotal minus discounts is
//     €25.00 or more.
class Checkout {
public:
    explicit Checkout(const std::vector<Coupon>& coupons);

    // Returns false, and changes nothing, if the code is unknown, the cart is
    // below the coupon's minimum, or the coupon is already applied.
    bool applyCoupon(const std::string& code, const Cart& cart);

    // Codes of the applied coupons, in upper case, in the order they were applied.
    const std::vector<std::string>& appliedCoupons() const;

    Receipt price(const Cart& cart) const;

private:
    static constexpr int kShippingCents = 499;
    static constexpr int kFreeShippingFromCents = 2500;

    const Coupon* findCoupon(const std::string& code) const;

    std::vector<Coupon> coupons_;
    std::vector<std::string> applied_;
};

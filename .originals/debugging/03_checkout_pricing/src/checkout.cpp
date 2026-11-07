#include "checkout.h"

#include <algorithm>
#include <cctype>

namespace {

std::string toUpper(std::string text) {
    for (char& c : text) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    return text;
}

}  // namespace

Checkout::Checkout(const std::vector<Coupon>& coupons) : coupons_(coupons) {}

bool Checkout::applyCoupon(const std::string& code, const Cart& cart) {
    const Coupon* coupon = findCoupon(toUpper(code));
    if (coupon == nullptr) return false;
    if (cart.subtotalCents() < coupon->minSubtotalCents) return false;
    if (std::find(applied_.begin(), applied_.end(), code) != applied_.end()) return false;
    applied_.push_back(coupon->code);
    return true;
}

const std::vector<std::string>& Checkout::appliedCoupons() const { return applied_; }

Receipt Checkout::price(const Cart& cart) const {
    Receipt receipt;
    receipt.subtotalCents = cart.subtotalCents();
    for (const std::string& code : applied_) {
        const Coupon* coupon = findCoupon(code);
        receipt.discountCents += receipt.subtotalCents * (coupon->percentOff / 100);
    }
    receipt.shippingCents = receipt.subtotalCents >= kFreeShippingFromCents ? 0 : kShippingCents;
    receipt.totalCents = receipt.subtotalCents - receipt.discountCents + receipt.shippingCents;
    return receipt;
}

const Coupon* Checkout::findCoupon(const std::string& code) const {
    for (const Coupon& coupon : coupons_) {
        if (coupon.code == code) return &coupon;
    }
    return nullptr;
}

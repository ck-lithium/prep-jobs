// HIDDEN TESTS: these stand in for the assessment's hidden tests.
// Don't read this file until you've finished the exercise.
#include <string>
#include <vector>

#include "cart.h"
#include "checkout.h"
#include "minitest.hpp"

namespace {

const std::vector<Coupon> kCoupons = {
    {"SAVE10", 10, 0},
    {"BIG20", 20, 5000},
    {"WELCOME5", 5, 0},
};

Cart cartWorth(int cents) {
    Cart cart;
    cart.add("ITEM", cents, 1);
    return cart;
}

std::vector<std::string> skus(const Cart& cart) {
    std::vector<std::string> result;
    for (const CartItem& item : cart.items()) result.push_back(item.sku);
    return result;
}

}  // namespace

TEST(HiddenCoupons, CodesAreCaseInsensitive) {
    Cart cart = cartWorth(3800);
    Checkout checkout(kCoupons);
    EXPECT_TRUE(checkout.applyCoupon("save10", cart));
    std::vector<std::string> expected = {"SAVE10"};
    EXPECT_EQ(checkout.appliedCoupons(), expected);
}

TEST(HiddenCoupons, SameCodeInAnotherCaseIsRejected) {
    Cart cart = cartWorth(3800);
    Checkout checkout(kCoupons);
    EXPECT_TRUE(checkout.applyCoupon("SAVE10", cart));
    EXPECT_FALSE(checkout.applyCoupon("save10", cart));
    EXPECT_FALSE(checkout.applyCoupon("Save10", cart));
    EXPECT_EQ(checkout.price(cart).discountCents, 380);
}

TEST(HiddenCoupons, LowerCaseCodeTwiceIsRejected) {
    Cart cart = cartWorth(3800);
    Checkout checkout(kCoupons);
    EXPECT_TRUE(checkout.applyCoupon("save10", cart));
    EXPECT_FALSE(checkout.applyCoupon("save10", cart));
    std::vector<std::string> expected = {"SAVE10"};
    EXPECT_EQ(checkout.appliedCoupons(), expected);
}

TEST(HiddenCoupons, DifferentCouponsCombine) {
    Cart cart = cartWorth(6000);
    Checkout checkout(kCoupons);
    EXPECT_TRUE(checkout.applyCoupon("SAVE10", cart));
    EXPECT_TRUE(checkout.applyCoupon("big20", cart));
    Receipt receipt = checkout.price(cart);
    EXPECT_EQ(receipt.discountCents, 600 + 1200);
    EXPECT_EQ(receipt.totalCents, 4200);
}

TEST(HiddenShipping, ThresholdUsesThePriceAfterDiscounts) {
    Cart cart = cartWorth(2600);  // €26.00, €23.40 after SAVE10
    Checkout checkout(kCoupons);
    checkout.applyCoupon("SAVE10", cart);
    Receipt receipt = checkout.price(cart);
    EXPECT_EQ(receipt.shippingCents, 499);
    EXPECT_EQ(receipt.totalCents, 2340 + 499);
}

TEST(HiddenShipping, ExactlyTwentyFiveAfterDiscountsShipsFree) {
    Cart cart = cartWorth(2777);  // 10% off is 277 cents, leaving exactly €25.00
    Checkout checkout(kCoupons);
    checkout.applyCoupon("SAVE10", cart);
    Receipt receipt = checkout.price(cart);
    EXPECT_EQ(receipt.shippingCents, 0);
    EXPECT_EQ(receipt.totalCents, 2500);
}

TEST(HiddenCart, RemoveOutOfStockAtTheEnd) {
    Cart cart;
    for (std::string sku : {"A", "B", "C"}) cart.add(sku, 100, 1);
    cart.setInStock("B", false);
    cart.setInStock("C", false);
    cart.removeOutOfStock();
    std::vector<std::string> expected = {"A"};
    EXPECT_EQ(skus(cart), expected);
}

TEST(HiddenCart, RemoveWhenEverythingIsOutOfStock) {
    Cart cart;
    for (std::string sku : {"A", "B", "C"}) {
        cart.add(sku, 100, 1);
        cart.setInStock(sku, false);
    }
    cart.removeOutOfStock();
    EXPECT_EQ(skus(cart), std::vector<std::string>{});
    EXPECT_EQ(cart.subtotalCents(), 0);
}

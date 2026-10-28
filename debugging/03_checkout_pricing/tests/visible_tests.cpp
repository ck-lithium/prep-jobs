#include <string>
#include <vector>

#include "cart.h"
#include "checkout.h"
#include "minitest.hpp"

namespace {

const std::vector<Coupon> kCoupons = {
    {"SAVE10", 10, 0},       // 10% off
    {"BIG20", 20, 5000},     // 20% off orders of €50 or more
    {"WELCOME5", 5, 0},      // 5% off
};

Cart makeCart() {  // €38.00
    Cart cart;
    cart.add("BOOK", 1500, 2);
    cart.add("MUG", 800, 1);
    return cart;
}

std::vector<std::string> skus(const Cart& cart) {
    std::vector<std::string> result;
    for (const CartItem& item : cart.items()) result.push_back(item.sku);
    return result;
}

}  // namespace

TEST(Cart, AddingTheSameSkuIncreasesQuantity) {
    Cart cart;
    cart.add("BOOK", 1500, 1);
    cart.add("BOOK", 1500, 2);
    ASSERT_EQ(cart.items().size(), 1u);
    EXPECT_EQ(cart.items()[0].quantity, 3);
    EXPECT_EQ(cart.subtotalCents(), 4500);
}

TEST(Cart, RemoveOutOfStockKeepsTheRestInOrder) {
    Cart cart;
    for (std::string sku : {"A", "B", "C", "D"}) cart.add(sku, 100, 1);
    cart.setInStock("B", false);
    cart.setInStock("C", false);
    cart.removeOutOfStock();
    std::vector<std::string> expected = {"A", "D"};
    EXPECT_EQ(skus(cart), expected);
}

TEST(Pricing, NoCoupons) {
    Checkout checkout(kCoupons);
    Receipt receipt = checkout.price(makeCart());
    EXPECT_EQ(receipt.subtotalCents, 3800);
    EXPECT_EQ(receipt.discountCents, 0);
    EXPECT_EQ(receipt.shippingCents, 0);
    EXPECT_EQ(receipt.totalCents, 3800);
}

TEST(Pricing, SmallOrderPaysShipping) {
    Cart cart;
    cart.add("MUG", 800, 1);
    Checkout checkout(kCoupons);
    Receipt receipt = checkout.price(cart);
    EXPECT_EQ(receipt.shippingCents, 499);
    EXPECT_EQ(receipt.totalCents, 1299);
}

TEST(Coupons, TenPercentOff) {
    Cart cart = makeCart();
    Checkout checkout(kCoupons);
    EXPECT_TRUE(checkout.applyCoupon("SAVE10", cart));
    Receipt receipt = checkout.price(cart);
    EXPECT_EQ(receipt.discountCents, 380);
    EXPECT_EQ(receipt.totalCents, 3420);
}

TEST(Coupons, DiscountRoundsDownToWholeCents) {
    Cart cart;
    cart.add("PEN", 1999, 1);
    Checkout checkout(kCoupons);
    checkout.applyCoupon("SAVE10", cart);
    Receipt receipt = checkout.price(cart);
    EXPECT_EQ(receipt.discountCents, 199);
    EXPECT_EQ(receipt.totalCents, 1999 - 199 + 499);
}

TEST(Coupons, UnknownCodeIsRejected) {
    Cart cart = makeCart();
    Checkout checkout(kCoupons);
    EXPECT_FALSE(checkout.applyCoupon("FREE100", cart));
    EXPECT_EQ(checkout.appliedCoupons(), std::vector<std::string>{});
}

TEST(Coupons, MinimumSubtotalIsEnforced) {
    Cart cart = makeCart();  // €38.00, BIG20 needs €50.00
    Checkout checkout(kCoupons);
    EXPECT_FALSE(checkout.applyCoupon("BIG20", cart));
}

TEST(Coupons, SameCodeTwiceIsRejected) {
    Cart cart = makeCart();
    Checkout checkout(kCoupons);
    EXPECT_TRUE(checkout.applyCoupon("SAVE10", cart));
    EXPECT_FALSE(checkout.applyCoupon("SAVE10", cart));
    std::vector<std::string> expected = {"SAVE10"};
    EXPECT_EQ(checkout.appliedCoupons(), expected);
}

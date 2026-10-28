// HIDDEN TESTS: these stand in for the assessment's hidden tests.
// Don't read this file until you've finished the exercise.
#include <stdexcept>
#include <string>
#include <vector>

#include "fulfillment.h"
#include "inventory.h"
#include "minitest.hpp"

TEST(HiddenInventory, LookingUpUnknownSkusDoesNotAddThem) {
    Inventory inventory;
    inventory.receive("A-1", 10);
    EXPECT_EQ(inventory.available("TYPO-123"), 0u);
    EXPECT_EQ(inventory.onHand("TYPO-456"), 0u);
    std::vector<std::string> expected = {"A-1"};
    EXPECT_EQ(inventory.lowStock(100), expected);
}

TEST(HiddenInventory, ReserveUnknownSkuFails) {
    Inventory inventory;
    EXPECT_FALSE(inventory.reserve("NOPE-1", 1));
    EXPECT_EQ(inventory.lowStock(10), std::vector<std::string>{});
}

TEST(HiddenInventory, ReserveExactlyWhatIsAvailable) {
    Inventory inventory;
    inventory.receive("A-1", 3);
    EXPECT_TRUE(inventory.reserve("A-1", 2));
    EXPECT_TRUE(inventory.reserve("A-1", 1));
    EXPECT_FALSE(inventory.reserve("A-1", 1));
    EXPECT_EQ(inventory.available("A-1"), 0u);
}

TEST(HiddenOrders, RejectedOrderKeepsEarlierLinesAvailable) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    inventory.receive("B-1", 5);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> rejected = {{"A-1", 1}, {"B-1", 2}, {"C-1", 1}};  // C-1 not stocked
    EXPECT_EQ(fulfillment.placeOrder(rejected), -1);
    EXPECT_EQ(inventory.available("A-1"), 5u);
    EXPECT_EQ(inventory.available("B-1"), 5u);
    std::vector<OrderLine> everything = {{"A-1", 5}, {"B-1", 5}};
    EXPECT_EQ(fulfillment.placeOrder(everything), 1);
}

TEST(HiddenOrders, SameSkuOnTwoLines) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> order = {{"A-1", 3}, {"A-1", 3}};
    EXPECT_EQ(fulfillment.placeOrder(order), -1);
    EXPECT_EQ(inventory.available("A-1"), 5u);
}

TEST(HiddenOrders, CancellingTwiceGivesUnitsBackOnce) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> order = {{"A-1", 3}};
    int id = fulfillment.placeOrder(order);
    fulfillment.cancel(id);
    fulfillment.cancel(id);
    EXPECT_EQ(inventory.available("A-1"), 5u);
    EXPECT_EQ(inventory.onHand("A-1"), 5u);
    EXPECT_EQ(fulfillment.status(id), OrderStatus::Cancelled);
}

TEST(HiddenOrders, ShippedOrderCannotBeCancelled) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> order = {{"A-1", 2}};
    int id = fulfillment.placeOrder(order);
    fulfillment.ship(id);
    EXPECT_THROW(fulfillment.cancel(id), std::logic_error);
    EXPECT_EQ(inventory.onHand("A-1"), 3u);
    EXPECT_EQ(inventory.available("A-1"), 3u);
    EXPECT_EQ(fulfillment.status(id), OrderStatus::Shipped);
}

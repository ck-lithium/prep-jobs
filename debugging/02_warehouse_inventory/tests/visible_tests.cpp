#include <stdexcept>
#include <string>
#include <vector>

#include "fulfillment.h"
#include "inventory.h"
#include "minitest.hpp"

TEST(Inventory, ReceiveAndReserve) {
    Inventory inventory;
    inventory.receive("BOOK-1", 10);
    EXPECT_TRUE(inventory.reserve("BOOK-1", 4));
    EXPECT_EQ(inventory.available("BOOK-1"), 6u);
    EXPECT_EQ(inventory.onHand("BOOK-1"), 10u);
}

TEST(Inventory, CannotReserveMoreThanAvailable) {
    Inventory inventory;
    inventory.receive("LAMP-7", 3);
    EXPECT_FALSE(inventory.reserve("LAMP-7", 5));
    EXPECT_EQ(inventory.available("LAMP-7"), 3u);
}

TEST(Inventory, ShipTakesUnitsOffTheShelf) {
    Inventory inventory;
    inventory.receive("BOOK-1", 10);
    inventory.reserve("BOOK-1", 4);
    inventory.ship("BOOK-1", 4);
    EXPECT_EQ(inventory.onHand("BOOK-1"), 6u);
    EXPECT_EQ(inventory.available("BOOK-1"), 6u);
}

TEST(Inventory, LowStockListsSkusAtOrBelowThreshold) {
    Inventory inventory;
    inventory.receive("A-1", 2);
    inventory.receive("B-1", 10);
    inventory.receive("C-1", 5);
    inventory.reserve("B-1", 6);  // 4 left
    std::vector<std::string> expected = {"A-1", "B-1"};
    EXPECT_EQ(inventory.lowStock(4), expected);
}

TEST(Orders, PlaceOrderReservesEveryLine) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    inventory.receive("B-1", 5);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> order = {{"A-1", 2}, {"B-1", 1}};
    EXPECT_EQ(fulfillment.placeOrder(order), 1);
    EXPECT_EQ(inventory.available("A-1"), 3u);
    EXPECT_EQ(inventory.available("B-1"), 4u);
    EXPECT_EQ(fulfillment.status(1), OrderStatus::Placed);
}

TEST(Orders, RejectedOrderReservesNothing) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    inventory.receive("B-1", 1);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> order = {{"A-1", 2}, {"B-1", 3}};
    EXPECT_EQ(fulfillment.placeOrder(order), -1);
    EXPECT_EQ(inventory.available("A-1"), 5u);
    EXPECT_EQ(inventory.available("B-1"), 1u);
}

TEST(Orders, CancelGivesUnitsBack) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> order = {{"A-1", 2}};
    int id = fulfillment.placeOrder(order);
    fulfillment.cancel(id);
    EXPECT_EQ(inventory.available("A-1"), 5u);
    EXPECT_EQ(fulfillment.status(id), OrderStatus::Cancelled);
}

TEST(Orders, ShipOrder) {
    Inventory inventory;
    inventory.receive("A-1", 5);
    Fulfillment fulfillment(inventory);
    std::vector<OrderLine> order = {{"A-1", 2}};
    int id = fulfillment.placeOrder(order);
    fulfillment.ship(id);
    EXPECT_EQ(inventory.onHand("A-1"), 3u);
    EXPECT_EQ(fulfillment.status(id), OrderStatus::Shipped);
    EXPECT_THROW(fulfillment.ship(id), std::logic_error);
}

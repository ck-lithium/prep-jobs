#pragma once

#include <string>

struct Coupon {
    std::string code;          // in upper case, e.g. "SAVE10"
    int percentOff = 0;        // 10 means 10% off the subtotal
    int minSubtotalCents = 0;  // the cart's subtotal must be at least this much
};

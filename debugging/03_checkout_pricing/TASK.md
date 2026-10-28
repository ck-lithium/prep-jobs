# Exercise 03: Checkout pricing

**Time limit: 45 minutes.** Start a timer before reading on.

## The codebase

The part of an online shop that prices a shopping cart: it applies coupon codes and adds shipping. All amounts are in cents. The pricing rules are in the comment at the top of `src/checkout.h`.

| File | What's in it |
|---|---|
| `src/cart.h`, `.cpp` | The shopping cart |
| `src/coupon.h` | The `Coupon` struct |
| `src/checkout.h`, `.cpp` | Applying coupons and computing the receipt |
| `tests/visible_tests.cpp` | The tests you're given. Some of them fail. |
| `tests/hidden_tests.cpp` | Stands in for the assessment's hidden tests. Don't open it until you've finished. |

## Your task

Customer support reported the bugs below. Fix all of them.

Some bugs make visible tests fail. Others aren't covered by any visible test, so reproduce them with a test of your own first. You can change anything in `src/` and add tests to `tests/visible_tests.cpp`. Keep the public functions' names and parameters as they are, because the hidden tests call them.

### Bug reports

1. "SAVE10 is accepted at checkout, but the total doesn't change."
2. "Two items next to each other in my cart went out of stock, and only one of them was removed."
3. "A customer used SAVE10 twice on the same order by typing it once in lower case and once in capitals."
4. "An order of €26.00 with SAVE10 cost €23.40 and still shipped for free. Free shipping should start at €25 *after* discounts."

## Commands

Run these in this folder:

```bash
make test             # build and run the visible tests
make test T=Coupons   # run only the tests whose name contains "Coupons"
make check            # visible + hidden tests: your final score
```

When you're done, or the timer runs out, run `make check`, then compare with [../ANSWERS.md](../ANSWERS.md).

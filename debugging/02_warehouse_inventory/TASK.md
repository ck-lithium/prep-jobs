# Exercise 02: Warehouse inventory

**Time limit: 45 minutes.** Start a timer before reading on.

## The codebase

The stock-keeping part of a warehouse system. It tracks how many units of each product (SKU) are on the shelves and how many are reserved for orders. It also places, cancels and ships customer orders. The rules are in the comments in `src/inventory.h` and `src/fulfillment.h`.

| File | What's in it |
|---|---|
| `src/inventory.h`, `.cpp` | Stock per SKU: receiving, reserving, releasing and shipping units, plus the low-stock report |
| `src/fulfillment.h`, `.cpp` | Customer orders, which reserve, release and ship stock |
| `tests/visible_tests.cpp` | The tests you're given. Some of them fail. |
| `tests/hidden_tests.cpp` | Stands in for the assessment's hidden tests. Don't open it until you've finished. |

## Your task

The warehouse team reported the bugs below. Fix all of them.

Some bugs make visible tests fail. Others aren't covered by any visible test, so reproduce them with a test of your own first. You can change anything in `src/` and add tests to `tests/visible_tests.cpp`. Keep the public functions' names and parameters as they are, because the hidden tests call them.

### Bug reports

1. "We oversold LAMP-7. Three were in stock, and the site accepted an order for five. The stock page now says 4294967294 are available."
2. "An order was rejected because one item was out of stock, but the other items in it stayed reserved. Nobody can buy them now."
3. "The low-stock report lists SKUs we have never stocked, such as TYPO-123. Nobody knows where they come from."
4. "A customer clicked Cancel twice, and now we have more units available than there are on the shelf. Also, an order was cancelled after it had shipped, and its items went back into stock."

## Commands

Run these in this folder:

```bash
make test               # build and run the visible tests
make test T=Inventory   # run only the tests whose name contains "Inventory"
make check              # visible + hidden tests: your final score
```

When you're done, or the timer runs out, run `make check`, then compare with [../ANSWERS.md](../ANSWERS.md).

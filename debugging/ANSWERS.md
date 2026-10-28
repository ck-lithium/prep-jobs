# Answers

**Spoilers.** Read an exercise's section only after you've finished it or the timer has run out.

## The patterns behind these bugs

Each of the twelve bugs is a classic type that shows up in real code and in assessments. When you know roughly where a bug is but can't see it, check for these:

| Pattern | What it looks like |
|---|---|
| Changing a copy instead of the original | a loop over a vector of copies, a function that returns by value |
| A value computed from state that changes later | an ID derived from a list that shrinks |
| Off by one at a boundary | `>` where the rule says "or more" |
| Counting events instead of distinct things | `count++` on every click instead of a set of who clicked |
| Unsigned arithmetic going below zero | `a - b < 0` with unsigned values is never true |
| A lookup that inserts | `map[key]` on a key that might not exist |
| No undo when a multi-step action fails halfway | reserve line 1, fail on line 2, return without releasing line 1 |
| A missing state check | cancelling twice, or cancelling something already shipped |
| Integer division | `percent / 100` is 0 for any percentage under 100 |
| Comparing values normalised differently | the stored value is upper case, the compared one is raw input |
| A rule applied to the wrong value | a threshold checked before discounts instead of after |
| Erasing from a container while looping by index | the element after each erased one is skipped |

## 01: Pull request review service

1. **Bob gets every review.** In `Team::pickReviewers` (`src/team.cpp`), `candidates` holds *copies* of the team members. `member.activeReviews++` changes the copy, which is then thrown away. Nobody's real load ever goes up, so the same person always looks least busy.
   - *Fix:* increment the matching entry in `members_`, for example by looking it up by name.
   - *How to find it:* the visible test shows `activeReviews("bob")` is still 0 right after Bob was assigned. So the `++` never reaches `members_`. Look at what the `++` is applied to.

2. **A 200-line PR needs only one approval.** In `ReviewService::requiredApprovals`, `>` should be `>=`, because the rule says "200 lines or more".
   - *How to find it:* the failing test uses exactly 200 lines. When a bug appears at one exact value, look at the comparison against that value.

3. **Two PRs get the same ID.** `ReviewService::nextId` returns "highest open ID + 1", but merged PRs leave `open_`. Merge the newest PR, and its ID is handed out again.
   - *Fix:* keep a counter that only goes up: a member `int lastId_ = 0;` and `return ++lastId_;`. The function can no longer be `const`.
   - *How to find it:* write the test from the bug report: open two PRs, merge #2, open another one, and print the IDs. Then ask what `nextId` depends on, and whether that can ever go *down*.

4. **The same reviewer approving twice counts as two approvals.** `ReviewService::approve` counts clicks (`approvals++`) instead of distinct reviewers.
   - *Fix:* record who approved, for example in a `std::set<std::string> approvedBy` in `PullRequest`, and compare its size with the approvals needed.
   - *How to find it:* the bug report is the test. Approve twice as the same reviewer, then check that the PR is still `Open`.

## 02: Warehouse inventory

1. **Overselling.** In `Inventory::reserve`, `stock.onHand - stock.reserved - quantity < 0` works on `unsigned` values, which can never be negative: 3 − 5 wraps around to 4294967294. The check never fails, so every reservation succeeds.
   - *Fix:* `if (quantity > stock.onHand - stock.reserved) return false;`
   - *How to find it:* the compiler warns that this comparison "is always false". Also, 4294967294 is 2³² − 2: a huge number coming out of a small subtraction almost always means unsigned underflow.

2. **A rejected order keeps its other items reserved.** `Fulfillment::placeOrder` returns `-1` as soon as one line fails, without releasing the lines it has already reserved.
   - *Fix:* before returning `-1`, release every line reserved so far. Checking availability first and reserving afterwards is trickier than it looks, because the same SKU can appear on two lines.
   - *How to find it:* the visible test keeps failing after you fix bug 1, but for a new reason. When a fix changes the failure message, read the new one instead of assuming the fix was wrong.

3. **SKUs nobody stocked appear in the low-stock report.** `available` and `onHand` use `stock_[sku]`. On a `std::map`, `operator[]` *inserts* a default entry when the key is missing, so looking up an unknown SKU adds it with 0 units.
   - *Fix:* use `find`, and return 0 when the SKU is missing. Both functions can then be `const`.
   - *How to find it:* "where do these entries come from?" means finding every line that can add to `stock_`. Searching for `stock_[` finds them all.

4. **Cancelling twice, or after shipping, puts stock back.** `Fulfillment::cancel` doesn't check the order's status, so every call releases the units again. Releasing more than was reserved takes `reserved` below zero (it's unsigned), and `available` ends up larger than `onHand`.
   - *Fix:* return early if the order is already `Cancelled`, and throw `std::logic_error` if it's `Shipped`.
   - *How to find it:* compare the function with the rules in the header comment. Each rule ("cancelling twice does nothing", "a shipped order can't be cancelled") should match a line of code, and here neither does.

## 03: Checkout pricing

1. **SAVE10 doesn't change the total.** In `Checkout::price`, `coupon->percentOff / 100` is integer division: 10 / 100 = 0.
   - *Fix:* multiply first, `subtotal * percentOff / 100`, which also rounds down as the rules require.
   - *How to find it:* print the discount for a single coupon. It's 0, so evaluate the expression by hand with the real numbers.

2. **Only one of two adjacent out-of-stock items is removed.** `Cart::removeOutOfStock` erases at index `i` and then moves on to `i + 1`, skipping the item that just slid into position `i`.
   - *Fix:* use `std::remove_if` followed by `erase`, or only move to the next index when nothing was erased.
   - *How to find it:* walk through the loop on paper with `[A, B (out), C (out), D]`.

3. **The same coupon twice in a different case.** `Checkout::applyCoupon` stores the upper-case code but checks for duplicates with the raw input `code`. After "SAVE10", the input "save10" isn't in `["SAVE10"]`, so it's accepted again.
   - *Fix:* check for `coupon->code`, the normalised code.
   - *How to find it:* the bug report gives the exact steps for a test. Then follow which variable each line uses: `code` or `coupon->code`.

4. **Free shipping is decided before discounts.** `Checkout::price` compares `subtotalCents` with the threshold instead of `subtotalCents - discountCents`.
   - *Fix:* `receipt.subtotalCents - receipt.discountCents >= kFreeShippingFromCents`
   - *How to find it:* work out the expected receipt by hand from the rules, then compare it field by field with what the code returns.

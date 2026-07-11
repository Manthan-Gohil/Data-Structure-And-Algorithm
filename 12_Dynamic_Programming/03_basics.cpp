// 2D dp problems
// 0/1 knapsack problem

// The idea

// Imagine you have:

// A backpack (knapsack) that can carry at most W kilograms.
// n items.
// Each item has:
// a weight
// a value (profit)

// Your goal is to maximize the total value without exceeding the weight limit.

// Why is it called 0/1 Knapsack?

// For each item, you have exactly two choices:

// 0 → Don't take it.
// 1 → Take it.

// You cannot take half an item or take the same item multiple times.

// For each item:

// Take it?
//       /      \
//     Yes      No
// DP State

// Let

// dp[i][w]

// be the maximum value you can obtain using the first i items with a knapsack capacity of w.

// Transition

// For every item, there are two options:

// Don't take the item
// dp[i][w] = dp[i-1][w]
// Take the item (if it fits)
// dp[i][w] = value[i] + dp[i-1][w-weight[i]]

// Take the better option:

// dp[i][w] = max(
//     dp[i-1][w],
//     value[i] + dp[i-1][w-weight[i]]
// )

// This is the classic 0/1 Knapsack recurrence.

// Time Complexity

// If there are n items and capacity W:

// Time: O(n × W)
// Space: O(n × W) (can often be optimized to O(W))
# Crux of Two Pointers Method

## Definition

The Two Pointers Method uses two pointers to iterate through arrays, adjusting segments dynamically to solve problems efficiently.

## When to Use

### Merging Two Sorted Arrays

**Target**: Merge into a single sorted array.

**Adjustment**: Compare elements at both pointers, move the smaller one, and advance the pointer.

### Number of Smaller Elements

**Target**: Count elements in `a` smaller than each element in `b`.

**Adjustment**: Sort both arrays. Use two pointers to count elements in `a` that are smaller than elements in `b`.

### Segment with Good Sum

**Target**: Find the longest subarray with sum ≤ `s`.

**Adjustment**: Use two pointers to maintain a segment and adjust to keep the sum within the limit.

### Segment with Small Set

**Target**: Find the longest subarray with ≤ `k` distinct numbers.

**Adjustment**: Use counters to track occurrences and adjust pointers to maintain the distinct count within the limit.

### Segment with Small Spread

**Target**: Find the longest subarray where max - min ≤ `k`.

**Adjustment**: Use auxiliary data structures to track the minimum and maximum within the current segment. Adjust pointers to maintain this condition.

## Summary

Adjust the common two-pointer approach to fit the specific problem requirements, focusing on maintaining and recalculating necessary properties within the segment. This method often leads to efficient, linear-time solutions.

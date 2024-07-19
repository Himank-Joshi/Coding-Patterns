### Revise Questions

- Static Range Sum Queries
- Breed Counting
- Subsequences Summing to Sevens
- Subarray Sums II
- Subarray Divisibility

### Crux of Prefix Sum:

**Definition**:

- Prefix sum is an array `prefix_sum` where `prefix_sum[i]` is the sum of the array elements from the start up to the i-th position.

**When to Use**:

- When you need to quickly calculate the sum of elements in a subarray multiple times.
- Useful in scenarios involving range queries or when dealing with cumulative data (static).
  - Sum, XOR, Product
  - Frequency count - for every i create `pre[]` array

### Learning Points from Each Problem:

1. **Static Range Sum Queries (CSES)**

   - **Problem**: Compute the sum of elements in given subarrays.
   - **Key Logic**:
     - **Prefix Sum**: Build a prefix sum array to quickly compute the sum of any subarray.
     - **Formula**: For subarray sum from index `l` to `r`, use `prefix_sum[r + 1] - prefix_sum[l]`.

2. **Odd Queries (Codeforces)**

   - **Problem**: Compute the sum of elements in subarrays that meet certain conditions (e.g., sum of odd numbers).
   - **Key Logic**:
     - **Prefix Sum**: Modify the prefix sum approach to handle specific constraints, such as counting the number of odd numbers in subarrays.
     - **Formula**: Maintain a prefix sum for odd numbers and use it to answer range queries efficiently.

3. **Breed Counting (Vjudge)**

   - **Problem**: Count occurrences of different breeds within subarrays.
   - **Key Logic**:
     - **Prefix Sum**: Use multiple prefix sum arrays to count occurrences of different types of elements.
     - **Formula**: Maintain separate prefix sums for each breed and use them to compute counts for any subarray.

4. **Kuriyama Mirai's Stones (Codeforces)**

   - **Problem**: Compute sums of elements in original and sorted arrays within given subarrays.
   - **Key Logic**:
     - **Prefix Sum**: Apply prefix sums to both the original array and a sorted version of the array.
     - **Formula**: Use prefix sums to handle queries on both original and sorted arrays efficiently.

5. **Subsequences Summing to Sevens (USACO)**

   - **Problem**: Find the longest subarray whose sum is a multiple of 7.
   - **Key Logic**:
     - **Prefix Sum + Modular Arithmetic**: Use prefix sums and modular arithmetic to find subarrays with sums divisible by a given number.
     - **Formula**: Use a hashmap to store the first occurrence of each modulo value and calculate the longest subarray with sum divisible by 7.

6. **Subarray Sums II (CSES)**

   - **Problem**: Count the number of subarrays with a specific sum.
   - **Key Logic**:
     - **Prefix Sum + Hashmap**: Use prefix sums and a hashmap to count the number of subarrays that sum to a specific value.
     - **Formula**: Track the count of each prefix sum and use it to find the number of subarrays that match the target sum.

7. **Subarray Divisibility (CSES)**
   - **Problem**: Count the number of subarrays where the sum is divisible by the length of the array.
   - **Key Logic**:
     - **Prefix Sum + Modular Arithmetic**: Use prefix sums and modular arithmetic to count subarrays with sums divisible by the array length.
     - **Formula**: Use a hashmap to store the frequency of prefix sums modulo the array length and count the valid subarrays.

### Summary:

By solving these problems, you will learn how to apply prefix sums effectively in various scenarios, optimize range queries, and handle complex constraints. Prefix sums can greatly simplify and speed up computations involving subarray sums, making them a powerful tool in competitive programming.

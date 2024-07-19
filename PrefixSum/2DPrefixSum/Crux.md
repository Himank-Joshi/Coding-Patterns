# 2D Prefix Sums

2D prefix sums are a powerful tool to efficiently calculate the sum of elements within any subrectangle of a 2D matrix. This technique is particularly useful when dealing with multiple queries for submatrix sums, as it significantly reduces the computational complexity compared to naive methods.

## Key Concepts

### Definition

The 2D prefix sum for a matrix is defined as:

```
prefix[a][b] = sum(arr[i][j] for i in range(1, a+1) for j in range(1, b+1))
```

This represents the sum of all elements from the top-left corner to the \((a, b)\) cell.

### Calculation

For each cell \((i, j)\) in the prefix sum matrix, it can be calculated using:

```
prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j]
```

This formula ensures that each element in the original matrix is counted exactly once.

### Querying Submatrix Sums

To find the sum of a submatrix from \((a, b)\) to \((A, B)\), use the relation:

```
sum(arr[i][j] for i in range(a, A+1) for j in range(b, B+1)) = prefix[A][B] - prefix[a-1][B] - prefix[A][b-1] + prefix[a-1][b-1]
```

Here, we leverage the precomputed prefix sums to quickly calculate the desired submatrix sum.

## Use Cases

2D prefix sums are especially useful when:

- You have multiple queries asking for the sum of different submatrices within the same 2D matrix.
- You need to optimize the time complexity from \(\mathcal{O}(NM)\) per query (naive approach) to \(\mathcal{O}(1)\) per query with \(\mathcal{O}(NM)\) preprocessing.

This method ensures efficient query processing, making it suitable for problems with large matrices and numerous sum queries.

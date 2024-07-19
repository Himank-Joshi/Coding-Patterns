# 2D Prefix Sums

2D prefix sums are a powerful tool to efficiently calculate the sum of elements within any subrectangle of a 2D matrix. This technique is particularly useful when dealing with multiple queries for submatrix sums, as it significantly reduces the computational complexity compared to naive methods.

## Key Concepts

### Definition

The 2D prefix sum for a matrix is defined as:
\[
\texttt{prefix}[a][b] = \sum*{i=1}^{a} \sum*{j=1}^{b} \texttt{arr}[i][j]
\]
This represents the sum of all elements from the top-left corner to the \((a, b)\) cell.

### Calculation

For each cell \((i, j)\) in the prefix sum matrix, it can be calculated using:
\[
\texttt{prefix}[i][j] = \texttt{prefix}[i-1][j] + \texttt{prefix}[i][j-1] - \texttt{prefix}[i-1][j-1] + \texttt{arr}[i][j]
\]
This formula ensures that each element in the original matrix is counted exactly once.

### Querying Submatrix Sums

To find the sum of a submatrix from \((a, b)\) to \((A, B)\), use the relation:
\[
\sum\_{i=a}^{A} \sum{j=b}^{B} \texttt{arr}[i][j] = \texttt{prefix}[A][B] - \texttt{prefix}[a-1][B] - \texttt{prefix}[A][b-1] + \texttt{prefix}[a-1][b-1]
\]
Here, we leverage the precomputed prefix sums to quickly calculate the desired submatrix sum.

## Use Cases

2D prefix sums are especially useful when:

- You have multiple queries asking for the sum of different submatrices within the same 2D matrix.
- You need to optimize the time complexity from \(\mathcal{O}(NM)\) per query (naive approach) to \(\mathcal{O}(1)\) per query with \(\mathcal{O}(NM)\) preprocessing.

This method ensures efficient query processing, making it suitable for problems with large matrices and numerous sum queries.

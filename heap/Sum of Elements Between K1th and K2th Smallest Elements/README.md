# Sum Between K1-th and K2-th Smallest Elements

## Problem

Given an array of positive integers `arr[]` and two integers `k1` and `k2`, find the **sum of all elements whose values lie strictly between the k1-th smallest and the k2-th smallest elements**.

> **Note:** The k1-th and k2-th smallest elements are **not included** in the sum.

---

## Example 1

**Input**

```text
arr = [20, 8, 22, 4, 12, 10, 14]
k1 = 3
k2 = 6
```

**Output**

```text
26
```

**Explanation**

Sorted array:

```text
[4, 8, 10, 12, 14, 20, 22]
```

- 3rd smallest = **10**
- 6th smallest = **20**

Elements between them are:

```text
12 + 14 = 26
```

---

## Example 2

**Input**

```text
arr = [1, 2, 3, 4, 5]
k1 = 1
k2 = 5
```

**Output**

```text
9
```

**Explanation**

Sorted array:

```text
[1, 2, 3, 4, 5]
```

Elements between **1** and **5** are:

```text
2 + 3 + 4 = 9
```

---

## Approach (Max Heap)

We use **two Max Heaps**.

- **Heap 1** stores the **k1 smallest elements**.
- **Heap 2** stores the **(k2 - 1) smallest elements**.

After processing the array:

- Find the sum of elements in Heap 1 (`sum1`).
- Find the sum of elements in Heap 2 (`sum2`).

The required answer is:

```text
sum2 - sum1
```

because:

- `sum2` contains the first `(k2 - 1)` smallest elements.
- `sum1` contains the first `k1` smallest elements.

Subtracting them leaves only the elements strictly between the **k1-th** and **k2-th** smallest elements.

---

## Why do we use a Max Heap?

A **Max Heap** keeps the largest element at the top.

- Store only the required smallest elements.
- If a smaller element is found, replace the largest element in the heap.
- Heap size always remains fixed.

This makes the solution efficient.

---

## Algorithm

1. Create two Max Heaps.
2. Store the first `k1` elements in Heap 1.
3. Store the first `(k2 - 1)` elements in Heap 2.
4. Traverse the remaining array.
5. Update both heaps whenever a smaller element is found.
6. Calculate:
   - `sum1` = sum of Heap 1
   - `sum2` = sum of Heap 2
7. Return:

```text
sum2 - sum1
```

---

## Time Complexity

```text
O(n log k2)
```

---

## Space Complexity

```text
O(k2)
```

---

## Key Idea

| Task | Heap Used |
|------|-----------|
| Kth Smallest Element | Max Heap |
| Kth Largest Element | Min Heap |
| Sum Between K1-th and K2-th Smallest | Two Max Heaps |

### Easy Trick

- **Smallest → Max Heap**
- **Largest → Min Heap**
- **Between K1 & K2 Smallest → Two Max Heaps**
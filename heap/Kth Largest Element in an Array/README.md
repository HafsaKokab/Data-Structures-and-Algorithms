# Kth Largest Element in an Array

## Problem

Given an integer array `nums` and an integer `k`, find the **kth largest element** in the array.

### Example 1

**Input**

```text
nums = [3, 2, 1, 5, 6, 4]
k = 2
```

**Output**

```text
5
```

**Explanation**

The array in sorted order is:

```text
[1, 2, 3, 4, 5, 6]
```

The **2nd largest element** is **5**.

---

## Approach

### Why do we use a Min Heap?

To find the **kth largest element**, we maintain a **Min Heap** of size `k`.

- Insert the first `k` elements into the Min Heap.
- The top of the Min Heap always contains the **smallest element among the current k largest elements**.
- Traverse the remaining elements:
  - If the current element is greater than the heap's top, remove the top element and insert the current element.
  - Otherwise, ignore it.
- After processing the entire array, the top of the Min Heap is the **kth largest element**.

---

## Rule to Remember

| Problem | Heap Used |
|---------|-----------|
| Kth Smallest | Max Heap |
| Kth Largest | Min Heap |

---

## Algorithm

1. Create a Min Heap.
2. Insert the first `k` elements.
3. Traverse the remaining elements.
4. If the current element is greater than the heap's top:
   - Remove the top element.
   - Insert the current element.
5. Return the top element.

---

## Time Complexity

- **Time:** `O(n log k)`

## Space Complexity

- **Space:** `O(k)`  
# Kth Smallest Element in an Array

## Problem
Given an integer array and an integer `k`, find the **kth smallest element** in the array.

---

## Approach

### Why do we use a Max Heap?

To find the **kth smallest element**, we maintain a **Max Heap** of size `k`.

- Insert the first `k` elements into the Max Heap.
- The top of the Max Heap always contains the **largest element among the current k smallest elements**.
- Traverse the remaining elements:
  - If the current element is **smaller** than the heap's top, remove the top element and insert the current element.
  - Otherwise, ignore it.
- After processing the entire array, the top of the Max Heap is the **kth smallest element**.

---

## Why not a Min Heap?

A Min Heap stores the smallest element at the top. If we insert all elements into a Min Heap, we must remove the smallest element `k - 1` times before reaching the kth smallest element.

This approach works, but it requires storing all `n` elements and is less efficient.

---

## Rule to Remember

- ✅ **Kth Smallest Element → Max Heap (size = k)**
- ✅ **Kth Largest Element → Min Heap (size = k)**

### Easy Trick

| Problem | Heap Used |
|---------|-----------|
| Kth Smallest | Max Heap |
| Kth Largest | Min Heap |

**Reason:**

- To find the **smallest** element, we keep the **largest** among the current `k` candidates at the top (**Max Heap**).
- To find the **largest** element, we keep the **smallest** among the current `k` candidates at the top (**Min Heap**).

---

## Time Complexity

- **Time:** `O(n log k)`
- **Space:** `O(k)`

---

## Algorithm

1. Create a Max Heap.
2. Insert the first `k` elements.
3. Traverse the remaining elements.
4. If the current element is smaller than the heap's top:
   - Remove the top element.
   - Insert the current element.
5. Return the top element of the heap.
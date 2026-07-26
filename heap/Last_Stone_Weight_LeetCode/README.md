# 1046. Last Stone Weight

## Problem Statement

You are given an array `stones`, where each element represents the weight of a stone.

On each turn:

- Select the **two heaviest stones**.
- Smash them together.
- If both stones have the same weight, both are destroyed.
- Otherwise, the heavier stone becomes `y - x` and is added back.

Return the weight of the last remaining stone. If no stones remain, return **0**.

---

## Approach

This problem is solved using a **Max Heap (Priority Queue)**.

Since we always need the two largest stones, a Max Heap allows us to efficiently retrieve them.

### Algorithm

1. Insert all stone weights into a Max Heap.
2. While more than one stone remains:
   - Remove the largest stone.
   - Remove the second largest stone.
   - Calculate their difference.
   - If the difference is greater than 0, insert it back into the heap.
3. Return the remaining stone if it exists; otherwise return 0.

---

## Data Structure Used

- Priority Queue (Max Heap)

---

## C++ STL Used

```cpp
priority_queue<int> pq;
```

---

## Example

### Input

```
stones = [2,7,4,1,8,1]
```

### Output

```
1
```

### Explanation

```
Initial Heap:
8 7 4 2 1 1

Step 1:
8 - 7 = 1
Heap:
4 2 1 1 1

Step 2:
4 - 2 = 2
Heap:
2 1 1 1

Step 3:
2 - 1 = 1
Heap:
1 1 1

Step 4:
1 - 1 = 0
Heap:
1

Answer = 1
```

---

## Time Complexity

```
O(n log n)
```

- Building the heap: **O(n log n)**
- Each smash operation takes **O(log n)**.

---

## Space Complexity

```
O(n)
```

---

## Concepts Learned

- Priority Queue
- Max Heap
- Heap Operations
- C++ STL
- Simulation
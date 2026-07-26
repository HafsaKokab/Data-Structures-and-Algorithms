# Magician and Chocolates

## Problem Statement
A magician has **N** bags, where each bag contains some chocolates.

A kid can eat chocolates from only one bag in one minute. After the kid eats all chocolates from the selected bag, the magician refills that bag with **floor(chocolates / 2)** chocolates.

Find the **maximum number of chocolates** the kid can eat in **A** minutes.

---

## Approach

This problem is solved using a **Max Heap (Priority Queue)**.

### Algorithm
1. Insert all bags into a Max Heap.
2. Repeat for **A** minutes:
   - Remove the bag with the maximum chocolates.
   - Add its chocolates to the answer.
   - Insert `floor(chocolates / 2)` back into the heap.
3. Return the final answer modulo **1000000007**.

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
A = 3
B = [6, 5]
```

### Output

```
14
```

### Explanation

```
Initial Heap:
6 5

Minute 1:
Take 6
Total = 6
Push 3

Heap:
5 3

Minute 2:
Take 5
Total = 11
Push 2

Heap:
3 2

Minute 3:
Take 3
Total = 14
Push 1
```

Final Answer

```
14
```

---

## Time Complexity

```
O((N + A) log N)
```

---

## Space Complexity

```
O(N)
```  

---

## Concepts Learned
- Priority Queue
- Max Heap
- STL in C++
- Greedy Approach
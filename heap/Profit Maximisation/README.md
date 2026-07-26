
# Seats

## Problem Statement

You are given an array **A**, where each element represents the number of vacant seats in a row of a stadium.

Each ticket costs equal to the number of vacant seats in the row from which it is sold.

Your task is to sell tickets to **B** people such that the **total profit is maximum**.

---

## Approach

This problem is solved using a **Max Heap (Priority Queue)**.

Since the ticket price depends on the number of vacant seats, we should always sell a ticket from the row with the **maximum vacant seats**.

After selling one ticket:
- Profit increases by the current number of vacant seats.
- The vacant seats in that row decrease by **1**.
- The updated value is inserted back into the Max Heap if seats are still available.

---

## Algorithm

1. Create a Max Heap.
2. Insert all rows into the heap.
3. Repeat while `B > 0`:
   - Remove the row with the maximum vacant seats.
   - Add its value to the total profit.
   - Decrease the vacant seats by **1**.
   - If seats are still available, insert the updated value back into the heap.
4. Return the maximum profit.

---

## Data Structure Used

- Priority Queue (Max Heap)

---

## C++ STL Used

```cpp
priority_queue<int> pq;
```

---

## Example 1

### Input

```
A = [2, 3]
B = 3
```

### Output

```
7
```

### Explanation

```
Initial Heap:
3 2

Sell Ticket:
Profit = 3
Push 2

Heap:
2 2

Sell Ticket:
Profit = 5
Push 1

Heap:
2 1

Sell Ticket:
Profit = 7
Push 1

Final Answer = 7
```

---

## Example 2

### Input

```
A = [1, 4]
B = 2
```

### Output

```
7
```

### Explanation

```
Initial Heap:
4 1

Sell Ticket:
Profit = 4
Push 3

Heap:
3 1

Sell Ticket:
Profit = 7
Push 2

Final Answer = 7
```

---

## Time Complexity

```
O((N + B) log N)
```

- Building the heap: **O(N log N)**
- Each ticket sale takes **O(log N)**

---

## Space Complexity

```
O(N)
```

---

## Concepts Learned

- Priority Queue
- Max Heap
- Greedy Algorithm
- Heap Operations
- C++ STL
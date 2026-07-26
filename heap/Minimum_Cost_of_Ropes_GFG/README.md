# Minimum Cost to Connect Ropes

## Problem
Given an array of rope lengths, connect all the ropes into one rope with the minimum possible cost.

The cost of connecting two ropes is equal to the sum of their lengths.

## Approach
This problem is solved using a **Min Heap (Priority Queue)**.

### Algorithm
1. Insert all rope lengths into a Min Heap.
2. Remove the two smallest ropes.
3. Connect them and calculate the cost.
4. Add the new rope back into the Min Heap.
5. Repeat until only one rope remains.
6. Return the total cost.

## Time Complexity
- **O(n log n)**

## Space Complexity
- **O(n)**

## Data Structure Used
- Priority Queue (Min Heap)

## C++ STL Used
```cpp
priority_queue<int, vector<int>, greater<int>>
```

## Example

**Input**
```
4 2 7 6 9
```

**Output**
```
62
```

### Explanation

```
2 + 4 = 6
Cost = 6

6 + 6 = 12
Cost = 18

7 + 9 = 16
Cost = 34

12 + 16 = 28
Cost = 62
```

## Learning
- Priority Queue
- Min Heap
- Greedy Algorithm
- STL in C++

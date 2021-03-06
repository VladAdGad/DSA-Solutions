# Array
## Duplicate Zeros
Given a fixed length array **arr** of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array **in place**, do not return anything from your function.

**Example 1:**
```
Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
```
**Example 2:**
```
Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
```

**Note:**
- **1 <= arr.length <= 10000**
- **0 <= arr[i] <= 9**

**Hide Hint #1**
This is a great introductory problem for understanding and working with the concept of in-place operations. The problem statement clearly states that we are to modify the array in-place. That does not mean we cannot use another array. We just don't have to return anything.

**Hide Hint #2**
A better way to solve this would be without using additional space. The only reason the problem statement allows you to make modifications in place is that it hints at avoiding any additional memory.

**Hide Hint #3** 
The main problem with not using additional memory is that we might override elements due to the zero duplication requirement of the problem statement. How do we get around that?

**Hide Hint #4**
If we had enough space available, we would be able to accommodate all the elements properly. The new length would be the original length of the array plus the number of zeros. Can we use this information somehow to solve the problem?

## Find Numbers with Even Number of Digits
Given an array **nums** of integers, return how many of them contain an **even number** of digits.

**Example 1:**
```
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
```
**Example 2:**
```
Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
```
**Constraints:**
- **1 <= nums.length <= 500**
- **1 <= nums[i] <= 10^5**

## Find Pivot Index
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

**Example 1:**
```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
```
**Example 2:**
```
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
```
**Constraints:**
- The length of **nums** will be in the range **[0, 10000]**.
- Each element **nums[i]** will be an integer in the range **[-1000, 1000]**.

## Largest Number At Least Twice of Others
In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

**Example 1:**
```
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
```
**Example 2:**
```
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
```

**Note:**
- **nums** will have a length in the range **[1, 50]**.
- Every **nums[i]** will be an integer in the range **[0, 99]**.

**Hint #1** 
Scan through the array to find the unique largest element `m`, keeping track of it's index `maxIndex`. Scan through the array again. If we find some `x != m` with `m < 2*x`, we should return `-1`. Otherwise, we should return `maxIndex`.

## Max Consecutive Ones
Given a binary array, find the maximum number of consecutive 1s in this array.

**Example 1:**
```
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. 
             The maximum number of consecutive 1s is 3.
```
**Note:**
- The input array will only contain 0 and 1.
- The length of input array is a positive integer and will not exceed 10,000

**Hint #1**
You need to think about two things as far as any window is concerned. One is the starting point for the window. 
How do you detect that a new window of 1s has started? The next part is detecting the ending point for this window. 
How do you detect the ending point for an existing window? If you figure these two things out, you will be able to detect the windows of consecutive ones. 
All that remains afterward is to find the longest such window and return the size.

## Plus One

Given a **non-empty** array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

**Example 1:**
```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
```
**Example 2:**
```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
```
**Example 3:**
```
Input: digits = [0]
Output: [1]
```

**Constraints:**
- **1 <= digits.length <= 100**
- **0 <= digits[i] <= 9**

##Reverse String
Write a function that reverses a string. The input string is given as an array of characters **char[]**.
Do not allocate extra space for another array, you must do this by **modifying the input array in-place** with O(1) extra memory.
You may assume all the characters consist of **printable ascii characters**.
  
**Example 1:**
```
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```
**Example 2:**
```
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```
**Hide Hint #1**  
The entire logic for reversing a string is based on using the opposite directional two-pointer approach!

## Squares of a Sorted Array
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

**Example 1:**
```
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
```
**Example 2:**
```
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**Note:**
- **1 <= A.length <= 10000**
- **-10000 <= A[i] <= 10000**
- **A** is sorted in non-decreasing order.

# LinkedList
## Design Doubly Linked List
Design your implementation of the linked list.
A node in a doubly linked list should have two attributes: **val**, **next** and **prev**. **val** is the value of the current node, and **next** is a pointer/reference to the next node.
Assume all nodes in the linked list are **0-indexed**.

Implement the **MyLinkedList** class:
- **MyLinkedList()** Initializes the **MyLinkedList** object.
- **int get(int index)** Get the value of the **indexth** node in the linked list. If the index is invalid, return -1.
- **void add_at_head(int val)** Add a node of value **val** before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- **void add_at_tail(int val)** Append a node of value **val** as the last element of the linked list.
- **void add_at_index(int index, int val)** Add a node of value **val** before the **indexth** node in the linked list. If **index** equals the length of the linked list, the node will be appended to the end of the linked list. If **index** is greater than the length, the **node will not be inserted**.
- **void delete_at_index(int index)** Delete the **indexth** node in the linked list, if the index is valid.**

**Example 1:**
```
Input
["MyLinkedList", "add_at_head", "add_at_tail", "add_at_index", "get", "delete_at_index", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.add_at_head(1);
myLinkedList.add_at_tail(3);
myLinkedList.add_at_index(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.delete_at_index(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
```
 
Constraints:
- **0 <= index, val <= 1000**
- Please do not use the built-in LinkedList library.
- At most **2000** calls will be made to **get**, **add_at_head**, **add_at_tail**, **add_at_index** and **delete_at_index**.

## Design Singly Linked List
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. 
Assume all nodes in the linked list are **0-indexed**.

Implement the **MyLinkedList** class:
- **MyLinkedList()** Initializes the **MyLinkedList** object.
- **int get(int index)** Get the value of the **indexth** node in the linked list. If the index is invalid, return **-1**.
- **void add_at_head(int val)** Add a node of value **val** before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- **void add_at_tail(int val)** Append a node of value **val** as the last element of the linked list.
- **void add_at_index(int index, int val)** Add a node of value **val** before the **indexth** node in the linked list. If **index** equals the length of the linked list, the node will be appended to the end of the linked list. If **index** is greater than the length, the node **will not be inserted**.
- **void delete_at_index(int index)** Delete the **indexth** node in the linked list, if the index is valid.

**Example 1:**
```
Input
["MyLinkedList", "add_at_head", "add_at_tail", "add_at_index", "get", "delete_at_index", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.add_at_head(1);
myLinkedList.add_at_tail(3);
myLinkedList.add_at_index(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.delete_at_index(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
```
**Constraints:**
- **0 <= index, val <= 1000**
- Please do not use the built-in LinkedList library.
- At most **2000** calls will be made to **get**, **add_at_head**, **add_at_tail**,  **add_at_index** and **delete_at_index**.

## Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

**Example 1:**
```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```
**Example 2:**
```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
```
**Example 3:**
```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
```

**Constraints:**
- The number of the nodes in the list is in the range **[0, 104]**.
- **-105 <= Node.val <= 105**
- **pos** is **-1** or a valid index in the linked-list.

 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

## Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.


**Example 1:**
```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```
**Example 2:**
```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```
**Example 3:**
```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

**Constraints:**
- The number of the nodes in the list is in the range **[0, 104]**.
- **-105 <= Node.val <= 105**
- **pos** is **-1** or a **valid index** in the linked-list.

**Follow up:** Can you solve it using **O(1)** (i.e. constant) memory?

# Queue
## Design Circular Queue
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
  
One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.
  
Your implementation should support following operations:
- **circular_queue(k)**: Constructor, set the size of the queue to be k.
- **front**: Get the front item from the queue. If the queue is empty, return -1.
- **rear**: Get the last item from the queue. If the queue is empty, return -1.
- **enqueue(value)**: Insert an element into the circular queue. Return true if the operation is successful.
- **dequeue()**: Delete an element from the circular queue. Return true if the operation is successful.
- **is_empty()**: Checks whether the circular queue is empty or not.
- **is_full()**: Checks whether the circular queue is full or not.
  
**Example:**
```
circular_queue circularQueue = new circular_queue(3); // set the size to be 3
circularQueue.enqueue(1);  // return true
circularQueue.enqueue(2);  // return true
circularQueue.enqueue(3);  // return true
circularQueue.enqueue(4);  // return false, the queue is full
circularQueue.rear();  // return 3
circularQueue.is_full();  // return true
circularQueue.dequeue();  // return true
circularQueue.enqueue(4);  // return true
circularQueue.rear();  // return 4
```  

**Note:**
- All values will be in the range of [0, 1000].
- The number of operations will be in the range of [1, 1000].
- Please do not use the built-in Queue library.

# Stack
## Daily Temperatures
Given a list of daily temperatures **T**, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. 
If there is no future day for which this is possible, put **0** instead.

For example, given the list of temperatures **T = [73, 74, 75, 71, 69, 72, 76, 73]**, your output should be **[1, 1, 4, 2, 1, 1, 0, 0]**.

Note: The length of **temperatures** will be in the range **[1, 30000]**. Each temperature will be an integer in the range **[30, 100]**. 

**Hint #1**
If the temperature is say, 70 today, then in the future a warmer temperature must be either 71, 72, 73, ..., 99, or 100. We could remember when all of them occur next.

## Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- get_min() -- Retrieve the minimum element in the stack.

**Example 1:**
```
Input
["min_stack","push","push","push","getMin","pop","top","get_min"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
min_stack minStack = new min_stack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.get_min(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.get_min(); // return -2
```
**Constraints:**
- Methods **pop**, **top** and **get_min** operations will always be called on **non-empty** stacks.

## Valid Parentheses
Given a string **s** containing just the characters **'('**, **')'**, **'{'**, **'}'**, **'\['** and **'\]'**, determine if the input string is valid.
  
An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.

**Example 1:**
```
Input: s = "()"
Output: true
```

**Example 2:**
```
Input: s = "()[]{}"
Output: true
```
**Example 3:**
```
Input: s = "(]"
Output: false
```
**Example 4:**
```
Input: s = "([)]"
Output: false
```
**Example 5:**
```
Input: s = "{[]}"
Output: true
```
**Constraints:**
- **1 <= s.length <= 104**
- **s** consists of parentheses only **'()[]{}'**.

**Hint #1**
An interesting property about a valid parenthesis expression is that a sub-expression of a valid expression should also be a valid expression. (Not every sub-expression) e.g.
```
{ { } [ ] [ [ [ ] ] ] } is VALID expression
          [ [ [ ] ] ]    is VALID sub-expression
  { } [ ]                is VALID sub-expression
```
Can we exploit this recursive structure somehow?
**Hint #2**
What if whenever we encounter a matching pair of parenthesis in the expression, we simply remove it from the expression? This would keep on shortening the expression. e.g.
```
{ { ( { } ) } }
      |_|

{ { (      ) } }
    |______|

{ {          } }
  |__________|

{                }
|________________|

VALID EXPRESSION!
```
**Hint #3**
The **stack** data structure can come in handy here in representing this recursive structure of the problem. 
We can't really process this from the inside out because we don't have an idea about the overall structure. But, the stack can help us process this recursively i.e. from outside to inwards.

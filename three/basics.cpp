#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

/*
================================================================================
WEEK 3 — STACKS, QUEUES, AND STL
================================================================================

This file continues the algorithm foundation:
- Stack and queue abstractions
- STL usage of stack / queue / deque / vector
- Circular queue
- Recursion tree method
- Basic applications of stacks and queues

Main idea:
- A data structure is not just syntax.
- It is a control over how data is stored and accessed.

================================================================================
1) STACK
================================================================================

Definition:
- Stack follows LIFO:
  Last In, First Out

Real-world analogy:
- Stack of plates:
  You add from top, remove from top.

Core operations:
- push(x)   -> insert at top
- pop()     -> remove top
- top()     -> view top element
- empty()   -> check if stack is empty
- size()    -> number of elements

Complexity:
- push/pop/top: O(1)

Use stack when:
- you need reverse order processing
- you need nested structure matching
- you need backtracking-style behavior

Common applications:
- balanced parentheses
- undo operation
- expression evaluation
- next greater element
- recursion simulation

-------------------------------------------------------------------------------
STL stack
-------------------------------------------------------------------------------
*/
void demoStackSTL() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "stack top = " << st.top() << '\n'; // 30
    st.pop();
    cout << "stack top after pop = " << st.top() << '\n'; // 20
}

/*
Balanced parentheses:
- '(' must match ')'
- '[' must match ']'
- '{' must match '}'

Why stack works:
- Most recent opening bracket must be closed first.
*/
bool isBalanced(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char t = st.top();
            st.pop();
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

/*
Next greater element:
For each element, find the first greater element on the right.

Brute force:
- O(n^2)

Stack method:
- O(n)

Idea:
- Keep a decreasing stack.
- When a larger value arrives, it resolves smaller ones.
*/
vector<int> nextGreaterElement(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> ans(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] > a[st.top()]) {
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

/*
================================================================================
2) QUEUE
================================================================================

Definition:
- Queue follows FIFO:
  First In, First Out

Real-world analogy:
- People standing in a line.

Core operations:
- push(x) / enqueue(x)
- pop() / dequeue()
- front()
- back()
- empty()
- size()

Complexity:
- all core operations: O(1)

Use queue when:
- order of arrival matters
- level order traversal
- task scheduling
- buffering

STL queue is a restricted queue:
- you can only access front and back
- no random access
*/

void demoQueueSTL() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "queue front = " << q.front() << '\n'; // 1
    cout << "queue back = " << q.back() << '\n';   // 3

    q.pop();
    cout << "queue front after pop = " << q.front() << '\n'; // 2
}

/*
Simple queue with an array:
- easiest conceptual implementation
- but normal array queue can waste space if we keep popping from front

That leads us to circular queue.
*/

class SimpleQueue {
private:
    vector<int> data;
    int frontIndex;
public:
    SimpleQueue() : frontIndex(0) {}

    void enqueue(int x) {
        data.push_back(x);
    }

    void dequeue() {
        if (!empty()) frontIndex++;
    }

    int front() const {
        return data[frontIndex];
    }

    bool empty() const {
        return frontIndex >= (int)data.size();
    }

    int size() const {
        return (int)data.size() - frontIndex;
    }
};

/*
================================================================================
3) CIRCULAR QUEUE
================================================================================

Why circular queue is needed:
- In a simple array queue, after many dequeues, space at the beginning becomes unused.
- Circular queue reuses that space.

Idea:
- Treat the array like a ring.
- Move indices using modulo arithmetic.

Typical variables:
- front
- rear
- count or size
- capacity

Conditions:
- empty: size == 0
- full : size == capacity

This is a key interview / implementation topic.
*/

class CircularQueue {
private:
    vector<int> arr;
    int frontIndex;
    int rearIndex;
    int sz;
    int cap;

public:
    CircularQueue(int capacity)
        : arr(capacity), frontIndex(0), rearIndex(-1), sz(0), cap(capacity) {}

    bool empty() const { return sz == 0; }
    bool full() const { return sz == cap; }
    int size() const { return sz; }

    bool push(int x) {
        if (full()) return false;
        rearIndex = (rearIndex + 1) % cap;
        arr[rearIndex] = x;
        sz++;
        return true;
    }

    bool pop() {
        if (empty()) return false;
        frontIndex = (frontIndex + 1) % cap;
        sz--;
        return true;
    }

    int front() const {
        return arr[frontIndex];
    }

    int back() const {
        return arr[rearIndex];
    }
};

/*
================================================================================
4) DEQUE
================================================================================

Deque = double-ended queue

You can insert and remove from both ends.

STL deque operations:
- push_back
- push_front
- pop_back
- pop_front
- front
- back

Why deque is powerful:
- It is the building block of many sliding-window optimization problems.
- It also behaves like a very flexible queue.

Typical use:
- sliding window maximum
- monotonic queue patterns
*/

void demoDeque() {
    deque<int> d;
    d.push_back(10);
    d.push_front(5);
    d.push_back(20);

    cout << "deque front = " << d.front() << '\n';
    cout << "deque back = " << d.back() << '\n';

    d.pop_front();
    cout << "deque front after pop_front = " << d.front() << '\n';
}

/*
Sliding window maximum:
For every subarray of size k, print the maximum element.

Efficient solution:
- Use deque to store indices of useful elements.
- Keep deque decreasing by value.
- Front always gives maximum of current window.

Brute force: O(nk)
Deque method: O(n)
*/
vector<int> slidingWindowMaximum(const vector<int>& a, int k) {
    vector<int> result;
    deque<int> d; // stores indices

    for (int i = 0; i < (int)a.size(); i++) {
        while (!d.empty() && d.front() <= i - k) d.pop_front();

        while (!d.empty() && a[d.back()] <= a[i]) d.pop_back();

        d.push_back(i);

        if (i >= k - 1) result.push_back(a[d.front()]);
    }
    return result;
}

/*
================================================================================
5) VECTORS
================================================================================

Vector = dynamic array.

Why vectors are important:
- safe and flexible
- resize automatically
- support random access
- much better than raw arrays for most modern C++ work

Common operations:
- push_back
- pop_back
- size
- empty
- front / back
- insert
- erase
- clear
- begin / end iteration

Difference from raw array:
- raw array has fixed size
- vector can grow

Important concept:
- capacity can be larger than size
- size = actual elements
- capacity = allocated storage

*/
void vectorBasicsDemo() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "vector size = " << v.size() << '\n';
    cout << "vector front = " << v.front() << '\n';
    cout << "vector back = " << v.back() << '\n';

    v.insert(v.begin() + 1, 15); // 10, 15, 20, 30
    v.erase(v.begin() + 2);      // 10, 15, 30

    cout << "vector after insert/erase: ";
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

/*
================================================================================
6) RECURSION TREE METHOD
================================================================================

This is used for time complexity of recursive algorithms.

Idea:
- Draw recursive calls as a tree.
- Count the work at each level.
- Count how many levels exist.

Example 1: T(n) = T(n-1) + O(1)
- This is a straight chain, not a branching tree.
- Total = O(n)

Example 2: T(n) = 2T(n/2) + O(n)
- Merge sort
- Each level does O(n) work
- Number of levels = log n
- Total = O(n log n)

Example 3: T(n) = 2T(n/2) + O(1)
- Total = O(n)

Example 4: T(n) = T(n/2) + O(1)
- Binary search
- Total = O(log n)

Important habit:
- Before coding recursion, ask:
  "What is the recurrence?"
  "How many calls?"
  "How big is each subproblem?"
  "What is the merge/combine cost?"

================================================================================
7) BASIC APPLICATIONS OF STACKS AND QUEUES
================================================================================

A) Stack application: undo model
- last action undone first

B) Stack application: parentheses checking
- already implemented above

C) Stack application: next greater element
- already implemented above

D) Queue application: level-order traversal in trees
- process nodes in arrival order

E) Queue application: scheduling
- first request handled first

F) Queue application: BFS in graphs
- explore nearest nodes before far ones

================================================================================
8) SUMMARY COMPARISON
================================================================================

Stack
- order: LIFO
- access: only top
- use: nesting, reversal, backtracking patterns

Queue
- order: FIFO
- access: front and back
- use: scheduling, BFS, buffering

Deque
- order: both ends
- access: front and back
- use: sliding window optimization, flexible queue behavior

Vector
- order: index-based dynamic array
- access: random
- use: almost everything general-purpose

================================================================================
9) DEMO MAIN
================================================================================
*/

template <typename T>
void printVector(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    cout << "=== WEEK 3 DEMO ===\n\n";

    // Stack
    demoStackSTL();
    cout << "isBalanced(\"{[()]}\") = " << isBalanced("{[()]}") << '\n';
    cout << "isBalanced(\"{[(])}\") = " << isBalanced("{[(])}") << '\n';

    vector<int> ngeInput = {4, 5, 2, 25};
    vector<int> nge = nextGreaterElement(ngeInput);
    cout << "next greater elements: ";
    printVector(nge);

    // Queue
    demoQueueSTL();
    SimpleQueue sq;
    sq.enqueue(10);
    sq.enqueue(20);
    sq.enqueue(30);
    cout << "SimpleQueue front = " << sq.front() << '\n';
    sq.dequeue();
    cout << "SimpleQueue front after dequeue = " << sq.front() << '\n';

    // Circular queue
    CircularQueue cq(4);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    cq.push(5);
    cout << "CircularQueue front = " << cq.front() << '\n';
    cout << "CircularQueue back = " << cq.back() << '\n';

    // Deque
    demoDeque();

    vector<int> sw = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> swm = slidingWindowMaximum(sw, 3);
    cout << "slidingWindowMaximum(k=3): ";
    printVector(swm);

    // Vector
    vectorBasicsDemo();

    cout << "\nEnd of Week 3 notes.\n";
    return 0;
}

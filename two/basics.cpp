#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

/*
================================================================================
WEEK 2 — RECURSION AND SEARCHING / SORTING TECHNIQUES
================================================================================

This file is written as a teaching note + example code.

What this week should do for you:
- Move you from "I can write loops" to "I can structure algorithmic thinking".
- Make recursion feel mechanical, not magical.
- Teach binary search, merge sort, and quick sort from the ground up.
- Introduce the idea of a data model using structures and classes.
- Introduce common interview patterns:
  - Two pointers
  - Sliding window
  - Hash maps
  - Sets / unordered sets

Style used here:
- First: concept summary
- Then: method / technique
- Then: comparison where relevant
- Then: C++ example code

Important reading rule:
- Do not memorize code blindly.
- Understand:
  1) what the function expects,
  2) what it guarantees,
  3) what it changes,
  4) its complexity.

================================================================================
1) RECURSION
================================================================================

Definition:
- Recursion means a function calls itself.
- It is not "infinite self-calling" because each call must move toward a base case.
- Every call gets its own stack frame.
- Local variables of each call are separate.

There are only 2 requirements for correct recursion:
1) Base case
2) Recursive progress toward the base case

Mental model:
- Base case = "stop condition"
- Recursive case = "reduce the problem"

Common mistakes:
- Missing base case
- Base case exists but is unreachable
- Problem size does not reduce
- Returning the wrong combined result

Good recursive functions are usually:
- smaller versions of the same problem
- easier to prove correct
- often harder to debug if you do not track the call stack

-------------------------------------------------------------------------------
Example 1: factorial
-------------------------------------------------------------------------------
Time: O(n)
Space: O(n) due to call stack
*/
long long factorialRecursive(int n) {
    if (n <= 1) return 1;            // base case
    return 1LL * n * factorialRecursive(n - 1);  // recursive case
}

/*
-------------------------------------------------------------------------------
Example 2: power a^b
-------------------------------------------------------------------------------
Naive recursion: O(b)
Can be improved using exponentiation by squaring: O(log b)
*/
long long powerRecursive(long long a, int b) {
    if (b == 0) return 1;
    return a * powerRecursive(a, b - 1);
}

/*
Better version: exponentiation by squaring.
Why it matters:
- When b is large, cutting the problem in half is much faster than reducing by 1.
*/
long long powerFast(long long a, long long b) {
    if (b == 0) return 1;
    long long half = powerFast(a, b / 2);
    if (b % 2 == 0) return half * half;
    return half * half * a;
}

/*
-------------------------------------------------------------------------------
Example 3: gcd (Euclid's algorithm)
-------------------------------------------------------------------------------
If b == 0, answer is a.
Otherwise gcd(a, b) = gcd(b, a % b)

Time: O(log min(a, b))
*/
int gcdRecursive(int a, int b) {
    if (b == 0) return a;
    return gcdRecursive(b, a % b);
}

/*
-------------------------------------------------------------------------------
Example 4: sum of array recursively
-------------------------------------------------------------------------------
Idea:
- sum(arr, n) = arr[n-1] + sum(arr, n-1)

This is a classic "reduce by one element" recursion.
*/
int sumArrayRecursive(const vector<int>& arr, int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumArrayRecursive(arr, n - 1);
}

/*
-------------------------------------------------------------------------------
Example 5: reverse a string recursively
-------------------------------------------------------------------------------
Useful to understand:
- function call stack
- recursion with two indices
*/
void reverseStringRecursive(string& s, int l, int r) {
    if (l >= r) return;
    swap(s[l], s[r]);
    reverseStringRecursive(s, l + 1, r - 1);
}

/*
-------------------------------------------------------------------------------
How to prove recursion correct
-------------------------------------------------------------------------------
A strong proof checklist:
1. Base case is correct.
2. Recursive step makes a smaller valid subproblem.
3. The smaller problem eventually reaches the base case.
4. Combining the subproblem result gives the correct answer.

If these 4 hold, the recursion is sound.

================================================================================
2) BINARY SEARCH
================================================================================

Binary search only works on a sorted array / sorted monotonic space.

Core idea:
- Do not scan everything.
- Cut the search space in half each step.

Requirements:
- Array must be sorted.
- You need an ordering relation.
- The middle element tells you which half to discard.

Comparison with linear search:
- Linear search: O(n)
- Binary search: O(log n)
- Binary search is much faster, but only on sorted data.

Common invariant:
- If key exists, it is always inside [l, r].

-------------------------------------------------------------------------------
Iterative binary search
-------------------------------------------------------------------------------
Time: O(log n)
Space: O(1)
*/
int binarySearchIterative(const vector<int>& a, int key) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;   // safer than (l + r) / 2
        if (a[mid] == key) return mid;
        if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

/*
-------------------------------------------------------------------------------
Recursive binary search
-------------------------------------------------------------------------------
This version is conceptually elegant.
*/
int binarySearchRecursive(const vector<int>& a, int l, int r, int key) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key) return binarySearchRecursive(a, mid + 1, r, key);
    return binarySearchRecursive(a, l, mid - 1, key);
}

/*
Binary search variants:
- first occurrence
- last occurrence
- lower bound
- upper bound
These matter when duplicates exist.

Example:
- first occurrence = first index with value >= key
- last occurrence = last index with value <= key
These are common interview patterns.

================================================================================
3) MERGE SORT
================================================================================

Idea:
- Split array into two halves.
- Sort left half.
- Sort right half.
- Merge two sorted halves.

Why merge sort matters:
- It is the cleanest introduction to divide and conquer.
- Stable sorting algorithm.
- Guaranteed O(n log n) time.

Trade-off:
- Uses extra memory, O(n)

Comparison:
- Merge sort = predictable and stable
- Quick sort = often faster in practice, but worst-case can be bad

-------------------------------------------------------------------------------
Merge helper
-------------------------------------------------------------------------------
*/
void mergeSortedParts(vector<int>& a, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while (i <= mid) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    for (int k = 0; k < (int)temp.size(); k++) {
        a[l + k] = temp[k];
    }
}

/*
-------------------------------------------------------------------------------
Merge sort
-------------------------------------------------------------------------------
*/
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    mergeSortedParts(a, l, mid, r);
}

/*
Merge sort properties:
- Time: O(n log n)
- Extra space: O(n)
- Stable: yes
- Good when you need guaranteed performance or stable order

================================================================================
4) QUICK SORT
================================================================================

Idea:
- Pick a pivot.
- Put pivot in correct position.
- All smaller elements go left, all larger go right.
- Sort left and right sides recursively.

This is also divide and conquer.

Comparison with merge sort:
- Merge sort merges after sorting subproblems.
- Quick sort partitions before sorting subproblems.
- Quick sort is in-place (typically), merge sort is not.

Average time: O(n log n)
Worst-case: O(n^2)
Worst-case happens when pivot choices are poor.

Pivot strategies:
- First element
- Last element
- Middle element
- Random pivot
- Median of three

Good practical choice:
- random pivot or median-of-three to reduce worst-case risk.

-------------------------------------------------------------------------------
Partition using Lomuto scheme
-------------------------------------------------------------------------------
*/
int partitionLomuto(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = partitionLomuto(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

/*
Quick sort properties:
- Average: O(n log n)
- Worst: O(n^2)
- Extra space: O(log n) average recursion depth
- Usually very fast in practice

================================================================================
5) STRUCTURES
================================================================================

A structure groups related data together.

Why use a structure?
- To model a real object with multiple fields
- To make code readable
- To pass a single logical entity around instead of many separate variables

Example:
- Student { roll, name, marks }
- Point { x, y }
- Product { id, price, quantity }

Key idea:
- struct is a custom data type.

*/
struct Student {
    int roll;
    string name;
    double marks;
};

/*
Access:
- Use dot operator for objects: s.name
- Use arrow operator for pointers: ptr->name

Structure vs class:
- In C++, struct and class are almost the same.
- The only default difference:
  - struct members are public by default
  - class members are private by default

================================================================================
6) CLASSES AND CONSTRUCTORS (BASIC UNDERSTANDING)
================================================================================

Class = blueprint for objects.

Encapsulation:
- Keep data private
- Expose methods to operate on that data

Constructor:
- Special function with the same name as the class
- Called automatically when object is created
- Used to initialize members

Types of constructors:
1. Default constructor
2. Parameterized constructor
3. Copy constructor (advanced, later)

*/
class Box {
private:
    int length;
    int width;
    int height;

public:
    // default constructor
    Box() : length(0), width(0), height(0) {}

    // parameterized constructor
    Box(int l, int w, int h) : length(l), width(w), height(h) {}

    int volume() const {
        return length * width * height;
    }

    void print() const {
        cout << "Box(" << length << ", " << width << ", " << height << ")";
    }
};

/*
Why constructors matter:
- They guarantee initialized objects.
- They remove repeated setup code.
- They prevent partially valid objects.

================================================================================
7) TWO POINTER TECHNIQUE
================================================================================

Idea:
- Use two indices instead of one.
- Move them strategically instead of scanning with nested loops.

Used in:
- sorted pair sum
- reverse array / reverse string
- remove duplicates
- container-like problems
- partition-like problems

Comparison:
- Brute force often O(n^2)
- Two pointers often O(n)

-------------------------------------------------------------------------------
Example: reverse an array in place
-------------------------------------------------------------------------------
*/
void reverseArrayTwoPointers(vector<int>& a) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}

/*
-------------------------------------------------------------------------------
Example: pair sum in sorted array
-------------------------------------------------------------------------------
Given sorted array and target, find whether a pair exists.

Why it works:
- If sum is too small, increase left pointer.
- If sum is too large, decrease right pointer.
*/
bool pairSumSorted(const vector<int>& a, int target) {
    int l = 0, r = (int)a.size() - 1;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == target) return true;
        if (sum < target) l++;
        else r--;
    }
    return false;
}

/*
================================================================================
8) SLIDING WINDOW TECHNIQUE
================================================================================

Idea:
- Maintain a "window" over a subarray / substring.
- Expand and shrink it without restarting from scratch.

Types:
1. Fixed-size window
2. Variable-size window

Why useful:
- Converts many O(n^2) brute force ideas into O(n)
- Very common in substring and subarray problems

-------------------------------------------------------------------------------
Fixed-size window: maximum sum of size k
-------------------------------------------------------------------------------
*/
int maxSumSubarrayOfSizeK(const vector<int>& a, int k) {
    if (k <= 0 || k > (int)a.size()) return 0;

    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += a[i];

    int best = windowSum;
    for (int i = k; i < (int)a.size(); i++) {
        windowSum += a[i];
        windowSum -= a[i - k];
        best = max(best, windowSum);
    }
    return best;
}

/*
-------------------------------------------------------------------------------
Variable-size window: longest substring without repeating characters
-------------------------------------------------------------------------------
Core idea:
- Expand right pointer
- If repetition appears, shrink from left
- Track last seen positions using a hash map

This is a premium interview pattern.
*/
int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> last;
    int best = 0;
    int l = 0;

    for (int r = 0; r < (int)s.size(); r++) {
        char c = s[r];
        if (last.count(c) && last[c] >= l) {
            l = last[c] + 1;
        }
        last[c] = r;
        best = max(best, r - l + 1);
    }
    return best;
}

/*
================================================================================
9) HASH MAPS
================================================================================

In C++:
- unordered_map = hash map
- map = balanced tree map

Comparison:
- unordered_map: average O(1) for insert/find
- map: O(log n) for insert/find, keys are ordered

Use unordered_map when:
- you need fast frequency counts
- order does not matter
- average-case speed is important

Use map when:
- you need sorted keys
- you need lower/upper bound-like operations on keys

-------------------------------------------------------------------------------
Example 1: frequency count
-------------------------------------------------------------------------------
*/
unordered_map<int, int> frequencyCount(const vector<int>& a) {
    unordered_map<int, int> freq;
    for (int x : a) freq[x]++;
    return freq;
}

/*
-------------------------------------------------------------------------------
Example 2: two sum using hash map
-------------------------------------------------------------------------------
Time: O(n) average
Space: O(n)

Idea:
- For each value x, check whether target - x already appeared.
*/
bool twoSumHashMap(const vector<int>& a, int target) {
    unordered_set<int> seen;
    for (int x : a) {
        if (seen.count(target - x)) return true;
        seen.insert(x);
    }
    return false;
}

/*
-------------------------------------------------------------------------------
Example 3: first non-repeating character
-------------------------------------------------------------------------------
Illustrates frequency + second pass.
*/
char firstNonRepeatingChar(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (char c : s) {
        if (freq[c] == 1) return c;
    }
    return '#'; // sentinel: no unique character
}

/*
================================================================================
10) SETS AND UNORDERED SETS
================================================================================

set:
- unique elements
- sorted order
- O(log n) insert / find

unordered_set:
- unique elements
- no ordering guarantee
- average O(1) insert / find

Comparison:
- Use set when ordering matters
- Use unordered_set when only membership matters

Common use cases:
- remove duplicates
- membership testing
- detecting repeated values
- tracking visited states

-------------------------------------------------------------------------------
Example: remove duplicates while keeping one copy
-------------------------------------------------------------------------------
*/
vector<int> uniqueValuesUnordered(const vector<int>& a) {
    unordered_set<int> seen;
    vector<int> out;
    for (int x : a) {
        if (!seen.count(x)) {
            seen.insert(x);
            out.push_back(x);
        }
    }
    return out;
}

/*
-------------------------------------------------------------------------------
Example: sorted unique values
-------------------------------------------------------------------------------
Using set gives you sorted output automatically.
*/
vector<int> uniqueValuesSorted(const vector<int>& a) {
    set<int> s(a.begin(), a.end());
    vector<int> out(s.begin(), s.end());
    return out;
}

/*
================================================================================
11) C++ CODING TECHNIQUES YOU SHOULD INTERNALIZE
================================================================================

1. Use const reference for read-only large inputs:
   void f(const vector<int>& a)

2. Use reference when you want to modify original values:
   void swap(int& a, int& b)

3. Use iterative style when recursion depth may get large.

4. Use long long when integer overflow is possible.

5. Prefer mid = l + (r - l) / 2 in binary search.

6. Know the complexity of every function you write.

7. Do not use a hash map when a simple array is enough, and do not use
   a simple array when the key space is too large or unknown.

================================================================================
12) SMALL DEMO MAIN
================================================================================
*/

template <typename T>
void printVector(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    cout << "=== WEEK 2 DEMO ===\n\n";

    // Recursion
    cout << "factorialRecursive(5) = " << factorialRecursive(5) << '\n';
    cout << "powerFast(2, 10) = " << powerFast(2, 10) << '\n';
    cout << "gcdRecursive(48, 18) = " << gcdRecursive(48, 18) << '\n';

    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "sumArrayRecursive = " << sumArrayRecursive(arr, (int)arr.size()) << '\n';

    string s = "recursion";
    reverseStringRecursive(s, 0, (int)s.size() - 1);
    cout << "reversed string = " << s << '\n';

    // Binary search
    vector<int> sorted = {2, 5, 8, 12, 16, 23, 38, 56, 72};
    cout << "binarySearchIterative(sorted, 23) = " << binarySearchIterative(sorted, 23) << '\n';
    cout << "binarySearchRecursive(sorted, 0, n-1, 16) = "
         << binarySearchRecursive(sorted, 0, (int)sorted.size() - 1, 16) << '\n';

    // Merge sort
    vector<int> m = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(m, 0, (int)m.size() - 1);
    cout << "mergeSort result: ";
    printVector(m);

    // Quick sort
    vector<int> q = {10, 7, 8, 9, 1, 5};
    quickSort(q, 0, (int)q.size() - 1);
    cout << "quickSort result: ";
    printVector(q);

    // Structures / classes
    Student st{101, "Sonu", 91.5};
    cout << "Student: " << st.roll << ", " << st.name << ", " << st.marks << '\n';

    Box b1;
    Box b2(3, 4, 5);
    cout << "Box default volume = " << b1.volume() << '\n';
    cout << "Box parameterized volume = " << b2.volume() << '\n';

    // Two pointers
    vector<int> rp = {1, 2, 3, 4, 5, 6};
    reverseArrayTwoPointers(rp);
    cout << "reverseArrayTwoPointers: ";
    printVector(rp);

    vector<int> pairArr = {1, 2, 4, 7, 11, 15};
    cout << "pairSumSorted(target=15) = " << pairSumSorted(pairArr, 15) << '\n';

    // Sliding window
    vector<int> sw = {2, 1, 5, 1, 3, 2};
    cout << "maxSumSubarrayOfSizeK(k=3) = " << maxSumSubarrayOfSizeK(sw, 3) << '\n';
    cout << "lengthOfLongestSubstring(\"abcabcbb\") = "
         << lengthOfLongestSubstring("abcabcbb") << '\n';

    // Hash maps / sets
    auto freq = frequencyCount({1, 2, 2, 3, 3, 3});
    cout << "frequencyCount(3) = " << freq[3] << '\n';
    cout << "twoSumHashMap([2,7,11,15], 9) = "
         << twoSumHashMap({2, 7, 11, 15}, 9) << '\n';
    cout << "firstNonRepeatingChar(\"aabbcdde\") = "
         << firstNonRepeatingChar("aabbcdde") << '\n';

    vector<int> dup = {5, 1, 2, 5, 3, 2, 4};
    vector<int> uniq1 = uniqueValuesUnordered(dup);
    vector<int> uniq2 = uniqueValuesSorted(dup);
    cout << "uniqueValuesUnordered: ";
    printVector(uniq1);
    cout << "uniqueValuesSorted: ";
    printVector(uniq2);

    cout << "\nEnd of Week 2 notes.\n";
    return 0;
}

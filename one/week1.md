## Week 1 — C++ Basics and Elementary Algorithms

### Topics

* Variables and Data Types..
* Loops and Conditional Statements..
* Functions..
* Arrays and Arrays in Functions..
* Selection Sort..
* Bubble Sort..
* Insertion Sort..
* Pointers..
* 2D Arrays..
* character arrays and using them in functions..
* Strings and String Functions..
* Passing by Value and Passing by Reference..
* Time Complexity Analysis..

### CLRS Reading

* Chapters 2 and 3

### Week 1 Practice Set (Based on Completed Topics)
========================================================

PHASE 1 — FUNDAMENTALS
--------------------------------------------------------

[ ] Running Sum of 1D Array                (#1480)

void runningSum(int *nums, int numsSize, int *returnSize){
    int cum[numsSize];
    int sum=0;
    for(int i=0; i<numsSize;i++){
        sum += nums[i];
        nums[i]=sum;
    }
}

[ ] Richest Customer Wealth                (#1672)
[ ] Maximum Consecutive Ones               (#485)
[ ] Find Numbers with Even Number of Digits (#1295)

[ ] To Lower Case                          (#709)
[ ] Length of Last Word                    (#58)
[ ] Defanging an IP Address                (#1108)
char * defangIPaddr(char * address){
    int count=0;
    for(int i = 0; i<strlen(address); i++){
        if(address[i]=='.')count++;
    }
    int length=strlen(address)+2*count;
    char* a = (char*)malloc(length + 1);
    for(int i=0,j=0;i<length&&j<strlen(address);){
        if(address[j]!='.') {
            a[i]=address[j];
            i++;
            j++;
        }    
        else{
            a[i]='[';
            a[i+1]='.';
            a[i+2]=']';
            i+=3;
            j++;
        }
    }
    a[length]='\0';
    return a;
}

[ ] Matrix Diagonal Sum                    (#1572)

[ ] Swap Numbers                           (Custom)
[ ] Linear Search                          (Custom)
[ ] Find Maximum and Minimum Element       (Custom)
[ ] Check if Array is Sorted               (Custom)
[ ] Reverse Array                          (Custom)

--------------------------------------------------------

PHASE 2 — CORE EASY
--------------------------------------------------------

[ ] Move Zeroes                            (#283)
[ ] Missing Number                         (#268)
[ ] Two Sum (Brute Force)                  (#1)

[ ] Reverse String                         (#344)
[ ] Find Index of First Occurrence         (#28)

[ ] Transpose Matrix                       (#867)------
[ ] Reshape Matrix                         (#566)

[ ] Sort Array by Parity                   (#905)
[ ] Height Checker                         (#1051)

--------------------------------------------------------

PHASE 3 — UPPER EASY
--------------------------------------------------------

[ ] Remove Duplicates from Sorted Array    (#26)
[ ] Find Pivot Index                       (#724)
[ ] Majority Element (Brute Force)         (#169)

[ ] Valid Anagram                          (#242)
[ ] Longest Common Prefix                  (#14)
[ ] Reverse Words in a String III          (#557)

[ ] Flipping an Image                      (#832)
[ ] Lucky Numbers in a Matrix              (#1380)

[ ] Relative Sort Array                    (#1122)
[ ] Sort Integers by Number of 1 Bits      (#1356)

========================================================
FIRST MEDIUMS
========================================================

PHASE 4 — EASY → MEDIUM TRANSITION
--------------------------------------------------------

[ ] Rotate Array                           (#189)
[ ] String Compression                     (#443)
[ ] Reverse Words in a String              (#151)
[ ] Set Matrix Zeroes                      (#73)
[ ] Product of Array Except Self           (#238)

--------------------------------------------------------

PHASE 5 — IMPORTANT INTERVIEW PATTERNS
--------------------------------------------------------

[ ] Longest Substring Without Repeating Characters (#3)
      Pattern: Sliding Window

[ ] Spiral Matrix                          (#54)
      Pattern: Matrix Traversal

[ ] Container With Most Water              (#11)
      Pattern: Two Pointers

--------------------------------------------------------

PHASE 6 — ADVANCED MEDIUMS
--------------------------------------------------------

[ ] Rotate Image                           (#48)
      Pattern: Matrix Manipulation

[ ] 3Sum                                   (#15)
      Pattern: Sorting + Two Pointers

--------------------------------------------------------

PHASE 7 — CHALLENGE MEDIUMS
--------------------------------------------------------

[ ] Find All Duplicates in an Array        (#442)

[ ] Zigzag Conversion                      (#6)

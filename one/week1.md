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

[ ] Move Zeroes                            (#283)
[ ] Missing Number                         (#268)
[ ] Two Sum (Brute Force)                  (#1)

[ ] Reverse String                         (#344)
[ ] Find Index of First Occurrence         (#28)


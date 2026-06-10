// //selection sort
// Basic idea:
// • Find the largest number.
// • Exchange it with the element in the last position.
// • We have made progress:
// • the last position now contains the largest, as we would like it to.
// • Now we can apply the same idea to the first N-1 elements of the array,
// where N = length of the array.
// • Then to first N-2 elements, and so on.
#include<iostream>
using namespace std;  

int posMax(int* a, int n){
    int maxInd = 0;
    for(int i=0;i<n;i++) if(a[maxInd]<a[i]) maxInd=i;
    return maxInd;
}

void selsort(int* a, int n ){
    for (int i=n; i>1;i--){
        int temp = a[i-1];
        a[i-1] = a[posMax(a,i)];
        a[posMax(a,i)] = temp;
    }
}

void rselsort(int* a, int n){
    if(n==1) return;
    else{
        int temp = a[n-1];
        a[n-1] = a[posMax(a,n)];
        a[posMax(a,n)] = temp;
        rselsort(a,n-1);
    }
}

// Bubble Sort — Core Idea

// Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

// Think of it like bubbles in water:

// Larger elements "bubble up" to the end of the array after each pass.
// After the first pass, the largest element is guaranteed to be in its correct position.
// After the second pass, the second-largest element is in its correct position.
// Continue until the array is sorted.

void swap(int &a, int &b){//& means we are passing the variables by reference, so any changes made to a and b inside the function will affect the original variables passed to the function.
    int temp = a;
    a = b;
    b = temp;
}

void bubsort(int* a,int n){
    //no of watys of selecting 2 are n-1 ways so
    for(int j=0;j<n-1;j++){//we have to do n-1 times
        for (int i=1; i<n-j; i++){//after j times the last j elements are in correct position so we can ignore them
        if (a[i-1]>a[i]){
            swap(a[i-1], a[i]);
        }
        else continue;
    }}
}

void rbubsort(int* a, int n){
    if(n==2){//basecase
        if (a[0]>a[1]){
            swap(a[0],a[1]);
            return;
        }
    }    
    else {
        for (int i=1; i<n; i++){//after j times the last j elements are in correct position so we can ignore them
            if (a[i-1]>a[i]){
            swap(a[i-1], a[i]);
            } 
        }
        rbubsort(a,n-1);
    }
}

void inssort(int* a, int n){
    for (int i=0;i<n;i++){
        int ins =a[i];
        int j = i-1;
        while(j>=0&&ins<a[j]){
            a[j+1]=a[j];
            j--;//j can become negative
        }
    a[j+1]=ins;    
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 78, 45, 3};
    //___sort(arr,10);
    for(int i=0; i<10; i++){
    cout<<arr[i]<<endl;
    }
}

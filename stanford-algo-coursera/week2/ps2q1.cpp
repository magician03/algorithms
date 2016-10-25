#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;


int partition1(int A[], int pivot, int low, int high);
void quicksort1(int A[], int low, int high);
int partition2(int A[], int pivot, int low, int high);
void quicksort2(int A[], int low, int high);
void quicksort3(int A[], int low, int high);


int n = 10000;
int A[10000];
int B[10000];
int C[10000];
int cmp1 = 0;
int cmp2 = 0;
int cmp3 = 0;
int main(void) {
    /* code */
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    for ( int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[i] = B[i] = C[i] = x;
    }
    quicksort3(C, 0, n-1);
    quicksort2(B, 0, n-1);
    quicksort1(A, 0, n-1);
    std::cout << std::endl;
    std::cout << cmp1 << std::endl;
    std::cout << cmp2 << std::endl;
    std::cout << cmp3 << std::endl;
    return 0;
}

int partition1(int A[], int pivot, int low, int high) {


    if(low < high){
        int i = low;
        int j = low+1;
        for (int x = low+1; x <= high; x++) {
            if(A[x] < A[pivot]){
                int tmp = A[x];
                A[x] = A[i+1];
                A[i+1] = tmp;
                i++;j++;
            } else {
                j++;
            }
        }
        int xtmp = A[i];
        A[i] = A[pivot];
        A[pivot] = xtmp;

        return i;
    } else return pivot;


}

void quicksort1(int A[], int low, int high) {
    if (low < high){
        int pivot = low;
        int mid = partition1(A, pivot, low, high);
        cmp1 += (high-low);
        quicksort1(A, low, mid-1);
        quicksort1(A, mid+1, high);
    }
}

void quicksort2(int A[], int low, int high) {
    if (low < high){
        int pivot = high;
        int tmp = A[low];
        A[low] = A[high];
        A[high] = tmp;
        int mid = partition1(A, low, low, high);
        cmp2 += (high-low);
        quicksort2(A, low, mid-1);
        quicksort2(A, mid+1, high);
    }
}

void quicksort3(int A[], int low, int high) {
    if (low < high){
        int a = low;
        int b = (low+high)/2;
        int c = high;
        int median = 0;
        if(( A[a] > A[c] && A[a] < A[b] )||( A[a] > A[b] && A[a] < A[c] ))
            median = a ;
        if(( A[b] > A[c] && A[b] < A[a] )||( A[b] > A[a] && A[b] < A[c] ))
            median = b;
        if(( A[c] > A[b] && A[c] < A[a] )||( A[c] > A[a] && A[c] < A[b] ))
            median = c;
        int tmp = A[low];
        A[low] = A[median];
        A[median] = tmp;
        int mid = partition1(A, low, low, high);
        cmp3 += (high-low);
        quicksort3(A, low, mid-1);
        quicksort3(A, mid+1, high);
    }
}

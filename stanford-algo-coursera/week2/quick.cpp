#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;


int partition1(int A[], int pivot, int low, int high);
void quicksort1(int A[], int low, int high);
//int partition2(int A[], int pivot, int low, int high);
//void quicksort2(int A[], int low, int high);
//void quicksort3(int A[], int low, int high);


int n = 1000;
int A[1000];
//int B[1000];
//int C[1000];
int cmp1 = 0;
//int cmp2 = 0;
//int cmp3 = 0;
int main(void) {
    /* code */
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);

    for ( int i = 0; i < n; i++) {
        cin >> A[i];
        //cin >> B[i];
        //cin >> C[i];
    }
    //quicksort3(C, 0, n-1);
    //quicksort2(B, 0, n-1);
    quicksort1(A, 0, n-1);
    for (int i = 0; i < n-1; i++) {
        std::cout << A[i] << "-" ;
    }
    std::cout << std::endl;
    std::cout << cmp1 << std::endl;
    //std::cout << cmp2 << std::endl;
    //std::cout << cmp3 << std::endl;
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

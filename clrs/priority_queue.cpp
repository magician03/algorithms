#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
function for getting the left child, right child, and parent node of index passedi in as parameter :)

Following obey he property of heap.


*/
int left(int i) {
    return 2*i ;
}

int right(int i) {
    return 2*i + 1 ;
}

int parent(int i) {
    return i/2 ;
}

/*
Max-Heapify -> Function to make sure that the subtree of a given node index,
follows the max-heap property.
-> Recursive Function
->T(n) = T(2n/3) + O(1)
using master method 
->T(n) = O(log n)
*/

void maxHeapify(int A[], int* length, int* heapSize, int i ){
    int l = left(i);
    int r = right(i);
    int largest;
    if ( (l < *heapSize) && (A[l] > A[i]) ){
        largest = l;
    } else largest = i;
    if ( ( r < *heapSize) && (A[r] > A[i])){
        largest = r;
    }
    
    if (largest != i){
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        
        maxHeapify( A, length, heapSize, largest);
        
    }
}

int Max(int A[], int* length, int* heapSize){
    return A[1];
}


/*
This extracts the maximum element and then replaces the pos with last and builds max-heap ;)
Time Complexity -> O(logn)
*/
int extractMax(int A[], int* length, int* heapSize){
    if ( *heapSize < 1){
        cout << "underflow while extracting max" << endl;
        return -1;
    }
    int max = A[1];
    A[1] = A[*heapSize];
    (*heapSize)-= 1 ;
    maxHeapify(A, length, heapSize, 1);
    
    return max;
}

//Time complexity = O(height of a tree) = O(logn)

void heapIncKey(int A[], int* length, int* heapSize, int i, int key){
    if(A[i] >= key ){
        cout << "Error while increasing the key: Improper Arguments" << endl;
        return ;
    }
    A[i] = key;
    while ( (i > 1) && (A[parent(i)] < A[i])){
        int temp = A[i];
        A[i] = A[parent(i)] ;
        A[parent(i)] = temp;
        
        i = parent(i);
    }
}


void heapInsertKey(int A[], int* length, int* heapSize, int key) {
    (*heapSize) += 1;
    A[*heapSize] = -10000;
    heapIncKey(A, length, heapSize, *heapSize, key);
}


int A[1000];
int main(void) {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i] ;
    }
    int  length;
    int heapSize;
    
    
    length = n;
    heapSize = n;
    
    while ( true ){
        cout << "choose one of the following numbers" << endl;
        cout <<"1.Give the maximum element" << endl;
        cout << "2.Extract the maximum element" << endl;
        cout << "3.Increase the key" << endl;
        cout << "4.Insert a new key" << endl;
        
        int x;
        cin >> x;
        if(x == 1){
            cout << Max(A, &length, &heapSize) << endl;;
            
        } else if (x == 2){
            cout << extractMax(A, &length, &heapSize);
            
        } else if (x == 3){
            cout << "Position/Index of key to be incremented: "  ;
            int pos;
            cin >> pos;
            cout << endl;
            cout << "New key value: "  ;
            int newKey;
            cin >> newKey ;
            heapIncKey(A, &length, &heapSize, pos, newKey);
            
        } else if (x == 4) {
            int newKey;
            cout << "New key to be added to the queue: " ;
            cin >> newKey ;
            cout << endl;
            heapInsertKey(A, &length, &heapSize, newKey);
            
        } else {
            cout << "Invalid number provided" << endl;
        }
        
        cout << "Press 1 to exit or 0 to repeat the process" << endl;
        int y;
        cin >> y;
        if ( y == 1){
            break;
        }
    
    }
    
    return 0;
}
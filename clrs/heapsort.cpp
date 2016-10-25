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

void maxHeapify ( int A[], int* length, int* heapSize, int i) {
    int l = left(i);
    int r = right(i);
    int largest;
    if ( (l <= *heapSize) && (A[l] > A[i]) ){
        largest = l;
    } else largest = i;
    if ( (r <= *heapSize) && (A[r] > A[largest]) ) {
        largest = r;
    }
    
    if (largest != i){
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        
        maxHeapify( A, length, heapSize, largest);
        
    }
    
}
/*
This generates max heap from a random heap by calling max heap function from
level h-1 . 
T(n) = O(n*logn)
*/
void buildMaxHeap( int A[], int* length, int* heapSize) {
    *heapSize = *length ;
    cout << *length << endl;
    for (int i = *length/2 ; i >= 1; i--) {
        
        maxHeapify(A, length, heapSize, i);
        //cout << A[1] <<endl;
    }
    //cout << "hello" << endl;
   
}
    
/*
This makes sure that the largest element(i.e. at the root always go to the last)
and sits there and then heapsize is decremented. In the next iteration that
thing isn't involved and sits there. This way after the loop terminates all the
elements are present at the decreasing order from last to first.
T(n) = O(n*logn) + O(n*logn) = O(n*logn)
*/
void heapSort( int A[], int* length, int* heapSize) {
    buildMaxHeap(A, length, heapSize);
    
    *heapSize = *length;
    
    for(int i = *length; i >= 2 ; i--){
        
        int temp = A[i];
        A[i] = A[1];
        A[1]= temp;
        
        *heapSize -= 1;
        
        maxHeapify(A, length, heapSize, 1);
    }
    
    
    return ;
    
}



int main(void) {
    
    int n;
    cin >> n;
    int A[n];
    for (int i = 1; i <= n; i++) {
        cin >> A[i] ;
    }
    int  length;
    int heapSize;
    
    
    length = n;
    heapSize = n;
    
    heapSort(A, &length, &heapSize) ;
    
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " " ;
    }
    cout << endl;
    
    
    return 0;
}
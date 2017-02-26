#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void printMatrix(int ** matrix, int r, int c) {
    int i,j;
    printf("\n\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    return ;
}

void insert(int ** queue, int index, int queueRowSize, int maxRowSize, int currHeight, int currCount) {
    //printf ("%d--%d\n", currHeight, currCount);
    int i = queueRowSize+1;
    while( i > index ) {
        //printf("here -- %d\n", index);
        queue[i][0] = queue[i-1][0];
        queue[i][1] = queue[i-1][1];
        i--;
    }
    
    queue[index][0] = currHeight;
    queue[index][1] = currCount;
    //printf("----\n");
    //printMatrix(queue, 6, 2);
    //printf("----\n");
    return;
}

void insertAtEnd(int ** queue, int queueRowSize, int maxRowSize, int currHeight, int currCount) {
    queue[queueRowSize+1][0] = currHeight;
    queue[queueRowSize+1][1] = currCount;

    //printf("--\n");
    //printMatrix(queue, 6, 2);
    //printf("--\n");
    return;
}

void allocatePeople(int ** people, int ** queue, int queueRowSize, int maxRowSize, int currAllocPerson) {
    if ( queueRowSize >= maxRowSize) return ;
    if ( currAllocPerson >= maxRowSize) return ;
    //printf("Hello\n");
    int currHeight = people[currAllocPerson][0];
    int currCount = people[currAllocPerson][1];
    
    int GHeightCount = 0;
    int flag = 0;
    for(int i = 0; i <= queueRowSize; i++) {
        
        if( (GHeightCount >= currCount) ) {
            insert(queue, i, queueRowSize, maxRowSize, currHeight, currCount);
            flag = 1;
            break ;
        }
        if( queue[i][0] >= currHeight) GHeightCount++;
    }
    if (flag == 0) insertAtEnd(queue, queueRowSize, maxRowSize, currHeight, currCount);
    
    currAllocPerson++;
    queueRowSize++;
    allocatePeople(people, queue, queueRowSize, maxRowSize, currAllocPerson);

    return ;
    
    
}
int partition(int ** arr, int low, int high) {
	int pivot = arr[high][0];
	int pivotIndex = low -1;
	int i;
	for(i = low; i <= high-1; i++) {
		if(arr[i][0] >= pivot){
			//swap A[j], A[i]
			int temp0, temp1;
			pivotIndex+= 1;
			temp0 = arr[pivotIndex][0];
            temp1 = arr[pivotIndex][1];
			arr[pivotIndex][0] = arr[i][0];
            arr[pivotIndex][1] = arr[i][1];
			arr[i][0] = temp0;
            arr[i][1] = temp1;
			
		}

	}

	int temp0, temp1;
    pivotIndex+= 1;
    temp0 = arr[pivotIndex][0];
    temp1 = arr[pivotIndex][1];
    arr[pivotIndex][0] = arr[high][0];
    arr[pivotIndex][1] = arr[high][1];
    arr[high][0] = temp0;
    arr[high][1] = temp1;
	
	

	return pivotIndex;

}

void quickSort(int ** arr, int low, int high)  {

	int pivot;
	// check for quick sort or bubble sort
	if(high - low > 0){
		// proceed to quick sort
		pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot+1, high);
	}
}

int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize) {
    int ** queue = (int **)malloc(peopleRowSize * sizeof(int *));
    for(int i =0; i < peopleRowSize; i++) {
        queue[i] = (int *)malloc(peopleColSize * sizeof(int));
    }
    quickSort(people, 0, 5);
    //printMatrix(people, 6, 2);
    //printf("people\n");
    int queueRowSize = 0;
    
    int currAllocPerson = 1;
    queue[0][0] = people[0][0];
    queue[0][1] = people[0][1];
    
    allocatePeople(people, queue, queueRowSize, peopleRowSize, currAllocPerson);
    //rintMatrix(queue, 6, 2);
    return queue;
}


int main(void) {

    int ** arr;

    arr = (int **)malloc(6 * sizeof(int *));
    for(int i = 0; i < 6; i++){
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    //arr =   {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};

    arr[0][0] = 7;
    arr[1][0] = 4;
    arr[2][0] = 7;
    arr[3][0] = 5;
    arr[4][0] = 6;
    arr[5][0] = 5;
    arr[0][1] = 0;
    arr[1][1] = 4;
    arr[2][1] = 1;
    arr[3][1] = 0;
    arr[4][1] = 1;
    arr[5][1] = 2;

    //arr = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]];
    
    int returnSize = 6;

    int ** queue = reconstructQueue(arr, 6, 2, &returnSize);

    printMatrix(queue, 6, 2);

    return 0;
}
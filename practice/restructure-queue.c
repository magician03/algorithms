void printMatrix(int ** matrix, int r, int c) {
    int i,j;
    printf("\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    return ;
}

void insert(int ** queue, int index, int queueRowSize, int maxRowSize, int currHeight, int currCount) {
    //printf ("%d--%d-I-%d\n", currHeight, currCount, index);
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
    //printMatrix(queue, maxRowSize, 2);
    //printf("----\n");
    return;
}

void insertAtEnd(int ** queue, int queueRowSize, int maxRowSize, int currHeight, int currCount) {
    queue[queueRowSize+1][0] = currHeight;
    queue[queueRowSize+1][1] = currCount;
    //printf ("%d--%d-I-%d\n", currHeight, currCount, queueRowSize);
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
	int pivot = high;
	int pivotIndex = low -1;
	int i;
	for(i = low; i <= high-1; i++) {
		if(arr[i][0] > arr[pivot][0]){
			//swap A[j], A[i]
			int temp0, temp1;
			pivotIndex+= 1;
			temp0 = arr[pivotIndex][0];
            temp1 = arr[pivotIndex][1];
			arr[pivotIndex][0] = arr[i][0];
            arr[pivotIndex][1] = arr[i][1];
			arr[i][0] = temp0;
            arr[i][1] = temp1;
			
		} else if (arr[i][0] == arr[pivot][0]) {
		    if(arr[i][1] <= arr[pivot][1]) {
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
    quickSort(people, 0, peopleRowSize-1);
    //printMatrix(people, 6, 2);
    //printf("people\n");
    int queueRowSize = 0;
    
    int currAllocPerson = 1;
    queue[0][0] = people[0][0];
    queue[0][1] = people[0][1];
    
    allocatePeople(people, queue, queueRowSize, peopleRowSize, currAllocPerson);
    (*returnSize) = peopleRowSize;
    //rintMatrix(queue, 6, 2);
    return queue;
}

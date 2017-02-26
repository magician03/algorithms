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

int partition(int ** arr, int low, int high) {
	int pivot = high;
	int pivotIndex = low -1;
	int i;
	for(i = low; i <= high-1; i++) {
		if(arr[i][0] < arr[pivot][0]){
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


int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize) {
    quickSort(points, 0, pointsRowSize - 1);
    //printMatrix(points, pointsRowSize, pointsColSize);
    if (pointsRowSize == 0) return 0;
    int shots = 1;
    int i = 1;
    int currReach = points[0][1];
    while(i < pointsRowSize) {
       
        if (points[i][0] <= currReach) {
             //printf("%d---\n", i);
             if(points[i][1] < currReach) currReach = points[i][1];
            i++;
        } else {
            currReach = points[i][1];
             //printf("%d++\n", i);
            i++;
            shots++;
        }
    }
    
    return shots;
}
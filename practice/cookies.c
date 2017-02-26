// Leetcode assign-ccokies

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int pivotIndex = low -1;
	int i;
	for(i = low; i <= high-1; i++) {
		if(arr[i] < pivot){
			//swap A[j], A[i]
			int temp;
			pivotIndex+= 1;
			temp = arr[pivotIndex];
			arr[pivotIndex] = arr[i];
			arr[i] = temp;
			
		}

	}

	int temp;
	pivotIndex += 1;
	temp = arr[pivotIndex];
	arr[pivotIndex] = arr[high];
	arr[high] = temp;
	
	

	return pivotIndex;

}

void quickSort(int arr[], int low, int high)  {

	int pivot;
	// check for quick sort or bubble sort
	if(high - low > 0){
		// proceed to quick sort
		pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot+1, high);
	}
}


int findContentChildren(int* g, int gSize, int* s, int sSize) {
    quickSort(g, 0, gSize-1);
    quickSort(s, 0, sSize-1);

    int count = 0;
    int g_x = 0, s_x = 0 ;
    while ((g_x < gSize) && (s_x < sSize)) {
        if (g[g_x] <= s[s_x]) {
            g_x++;
            s_x++;
            count++;
        } else {
            s_x++;
        }
    }
    return count ;
}


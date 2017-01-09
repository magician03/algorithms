# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high, int k);
void hybridSort(int *,int);

int main()
{
  int *arr,n;
  srand((unsigned int)time(NULL));
  scanf("%d",&n);
  arr = (int *)malloc(n*sizeof(int));
  hybridSort(arr,n);
  return 0;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int pivotIndex = low -1;
	int i;
	for(i = low; i <= high-1; i++) {
		if(arr[i] < pivot){
			//swap A[j], A[i]
			int temp;
			temp = arr[pivotIndex];
			arr[pivotIndex] = arr[i];
			arr[i] = temp;
			pivotIndex+= 1;
		}

	}

	int temp;
	temp = arr[pivotIndex];
	arr[pivotIndex] = arr[high];
	arr[high] = temp;
	pivotIndex += 1;

	return pivotIndex;

}

void quickSort(int arr[], int low, int high, int k)  {

	int pivot;
	// check for quick sort or bubble sort
	if(high - low > k){
		// proceed to quick sort
		pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1, k);
		quickSort(arr, pivot+1, high, k);
	} else {
		// proceed to bubble sort
		int i,j,k;
		for(i = low; i <= high; i++){
			for(j = low; j < high; j++){
				if(arr[j+1] < arr[j]){
					int temp;
					temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}



void hybridSort(int *arr, int n)
{

  /* write your program here.....
	 use the following block of code to find out the time of running a particular routine */
	 clock_t begin,end;

	int i = 0;
	for ( i = 0 ; i < n; i++)
		arr[i] = 10*i;
		 
	int k = 0;
	for(k = 2; k < 100; k++){

		begin = clock();
		
		quickSort(arr, 0, n-1, k);
		//perform your computation here

		end = clock();

		//time required will be end-begin


		//For random input use the following code

		//arr[i] = rand();


		//output should be printed in the following way for each k.
		 double tt = end-begin;
		printf("%d,%d\n",k,tt);

	}

}

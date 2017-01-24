# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high, int k);
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

void merge(int arr[], int low, int mid, int high){

	int A1[mid-low+1];
	int A2[high-mid];

	int i = 0, j = 0;

	for(i = low; i <= mid; i++)
		A1[i-low] = arr[i];
	
	for(j = mid+1; j <= high; j++)
		A2[j-mid-1] = arr[j];

	int k = low;
	j = 0;
	i = 0;

	while(k <= high && i <= mid-low && j <= high-mid-1){

	if(A1[i] > A2[j])
		arr[k++] = A1[i++];

	if(A2[j] >= A1[i])
		arr[k++] = A2[j++];

	}

	while(i <= mid-low && k <= high)
		arr[k++] = A1[i++];

	while(j <= high-mid-1 && k <= high)
		arr[k++] = A2[j++];

}

void mergeSort(int arr[], int low, int high, int k){

  if (high -low > k){
    int mid = (high + low)/2;
    mergeSort(arr, low, mid, k);
    mergeSort(arr, mid+1, high, k);
		merge(arr, low, mid, high);
  } else if ( high > low) {
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
  } else return ;

}


void hybridSort(int *arr, int n)
{

  /* write your program here.....
	 use the following block of code to find out the time of running a particular routine */
	 clock_t begin,end;

	int i = 0;
	for ( i = 0 ; i < n; i++)
		arr[i] = i*i;
		 
	int k = 0;
	for(k = 2; k < 100; k++){

		begin = clock();
		
		mergeSort(arr, 0, n-1, k);
		//perform your computation here

		end = clock();

		//time required will be end-begin


		//For random input use the following code

		//arr[i] = rand();


		//output should be printed in the following way for each k.
		 double tt = (double)(end-begin);
		 tt /= CLOCKS_PER_SEC;
		printf("%d,%lf\n",k,tt);

	}

}

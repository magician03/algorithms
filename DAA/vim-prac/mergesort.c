#include <stdio.h>

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int main(void){

	int n;
	scanf("%d", &n);
	int arr[n];
	int i = 0;
	for(i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);

	mergeSort(arr, 0, n-1);

	for(i = 0; i < n ; i++)
		printf("%d->", arr[i]);

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

void mergeSort(int arr[], int low, int high){

	//base case
	if(low >= high){
		return;
	}

	int mid = (low + high)/2;

	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);

}

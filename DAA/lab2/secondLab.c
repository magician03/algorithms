# include <stdio.h>
# include <stdlib.h>

int parent(int , int);
int left_ch(int, int);
int right_ch(int , int);
void max_Heapify(int *, int, int, int);
int check_MAX_heap(int *,int, int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int*, int);
void insert(int *,int*,int,int);
void change(int *,int,int,int,int);
void print(int *, int);
void heapSort(int *, int, int);

int main()
{
  char ch=' ';
  int *arr,n,k,i,new;
  scanf("%d",&k);
  scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
  arr = (int *)malloc(2*n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
  if(!check_MAX_heap(arr,n,k))
    build_MAX_heap(arr,n,k);

   print(arr, n);
	 //heapSort(arr, n, k);
	 //print(arr, n);
  do
    {
      while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
      ch=getchar();
      switch(ch)
	{
	case 'i':
	  scanf("%d",&new);
	  insert(arr,&n,k,new);
	  print(arr, n);
	  n++;
	  break;
	case 'd':
	  printf("%d",extract_MAX(arr,&n,k));
	  print(arr, n);
	  n--;
	  break;
	case 'c':
	  scanf("%d",&i);
	  scanf("%d",&new);
	  change(arr,n,k,i,new);
	  print(arr, n);
	  break;
	case 's':
	printf("sorting array\n");
	heapSort(arr, n ,k);
	print(arr, n);
	}
    }while(ch!='q');
  return 0;
}

void print(int arr[], int n) {
	int i = 0;
	printf("------------------\n");
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n-------------\n");
}

int parent(int i, int k)
{
	return (i-1)/k ;
}

int left_ch(int i, int k) {
	return (i*k)+1 ;
}

int right_ch(int i, int k){
	return (i+1)*k ;
}
void max_Heapify(int arr[], int i, int n, int k) {
	
	while(1 == 1){

		int l_most = left_ch(i, k);
		int r_most = right_ch(i, k);

		int largest = i;

		int x;

		for( x = l_most ; x <= r_most ; x++) {
			if (x < n) {
				largest = ((arr[largest]) > (arr[x]) ? largest : x);
			}
		}

		if (largest == i){
			return ;
		}

		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		
		i = largest;
	}

}

int check_MAX_heap(int arr[],int n,int k)
{
  /* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
	int i;
	for(i = n-1; i > 0; i--) {
		if( arr[parent(i, k)] < arr[i] )
			return 0;
	}
}

void build_MAX_heap(int arr[],int n,int k)
{
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	int i = (n-1)/k;

	for( i = (n-1)/k ; i >= 0; i--) {
		max_Heapify(arr, i, n, k);
	}
}

void insert(int arr[],int* n,int k,int new)
{
  /* This function inserts a new element into the k-ary MAX-heap arr*/

	arr[(*n)++]  = new;
	int i = (*n)-1;
	while( i >= 0 && arr[parent(i, k)] < arr[i]) {
		int temp = arr[parent(i, k)];
		arr[parent(i, k)] = arr[i];
		arr[i] = temp;

		i = parent(i, k);

	}
}

int extract_MAX(int arr[],int* n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/

	int max = arr[0];

	arr[0] = arr[(*n)-1];

	(*n)--;

	max_Heapify(arr, 0, *n, k);

	return max;
	

}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
	if (new > arr[i]) {
		arr[i] = new;
		while(i >= 0 && arr[parent(i, k)] < arr[i]) {
			int temp = arr[parent(i, k)];
			arr[parent(i, k)] = arr[i];
			arr[i] =  temp;

			i = parent(i, k);
		}
		
	} else if (new < arr[i]){
		arr[i] = new;
		max_Heapify(arr, i, n, k);
	} else  return ;


}

void heapSort(int arr[], int n, int k) {
	/* function to sort the max-heap*/

	int len = n;

	while(len > 1) {

		int temp = arr[0];
		arr[0] = arr[len-1];
		arr[len-1] = temp;

		len--;

		max_Heapify(arr, 0, len, k);

	}

}

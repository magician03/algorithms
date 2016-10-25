#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int merge_count (int array[], int temp[], int low, int mid, int high);
int countinv (int array[], int temp[], int low, int high);


int main() {
	// your code goes here
	int array[6] = {6,5,4,3,2,100} ;
	int temp[6] ;
	
	cout << countinv(array, temp, 0, 5) << endl ;
	return 0;
}

int merge_count(int array[], int temp[], int low, int mid, int high) {
	int count = 0;
	
	int i = low, j = mid+1, k= low;
	
	while ( (i <= mid) && (j <= high)) {
			if (array[i] <= array [j]) {
			temp[k++] = array[i++];
		} else {
			temp[k++] = array[j++];
			count += mid-i+1 ;
		}	
	}
	 while (i <= mid ) {
	 	temp[k++] = array[i++] ;
	 }
	 while ( j <= high ) {
	 	temp[k++] = array[j++];
	 }
	 for (int x = low ; x <= high; x++) {
	 	array[x] = temp[x] ;
	 }
	
	return count;
	
}

int countinv(int array[], int temp[], int low, int high) {
	int count = 0 ;
	if (low < high ) {
		int mid = low + (high-low) / 2 ;
		
		count += countinv(array, temp, low, mid);
		count += countinv(array, temp, mid+1, high);
		count += merge_count(array, temp, low, mid, high);
	}
	return count ;
}



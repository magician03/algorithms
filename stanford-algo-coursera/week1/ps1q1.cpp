#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

long long int merge_count (int array[], int temp[], int low, int high);
long long int countinv (int array[], int temp[], int low, int high);

int n = 100000;
int array[100000];
int temp[100000];
int main() {
	// your code goes here
    /*std::fstream myfile("sample.txt", std::ios_base::in);
    int i = 0;
    int a;

    while (myfile >> a)
    {
        array[i++] = a ;
    }*/

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for ( int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    

	cout << countinv(array, temp, 0, n-1) << endl ;
	return 0;
}

long long int merge_count(int array[], int temp[], int low, int mid, int high) {
	long long int count = 0;
	if(low < high ) {
		
		int i = low, j = mid+1, k= low;
		//cout << i << "-" << j << "-" << k << endl;
		//cout << temp[k] << " " << array[k] << endl;
		while ( i <= mid && j <= high) {
				if (array[i] < array [j]) {
				temp[k++] = array[i++];
				//cout << "-" << temp[k] << "-" ;
			} else {
				temp[k++] = array[j++];
				count += mid-i+1 ;
				//cout << "-" << temp[k] << "-" ;
			}
		}
		/*for(int m = low; m <=high;m++) {
		 	cout << "-" <<temp[m] ;
		 }*/
		 while (i <= mid ) {
		 	temp[k++] = array[i++] ;
		 }
		 while ( j <= high ) {
		 	temp[k++] = array[j++];
		 }
		 
		 
		 for (int x = low ; x <= high; x++) {
		 	array[x] = temp[x] ;

		 }

	}
	return count;
}

long long int countinv(int array[], int temp[], int low, int high) {
	long long int count = 0 ;
	if (low < high ) {
		int mid = (high+low) / 2 ;
		//cout << low << " " << mid << " " << high << endl;
		count += countinv(array, temp, low, mid);
		count += countinv(array, temp, mid+1, high);
		count += merge_count(array, temp, low, mid, high);
	}
	return count ;
}

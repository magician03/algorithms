#include <stdio.h>
#include <stdlib.h>

void multiply(int arr[], int num, int* len){
    //multiply each index of array, add with carry, replace it %10 and proceed with carry
    int i = 0;
    int x, carry = 0;
    for ( i = 0; i < *len; i++){
        x = arr[i] * num;
        x += carry;
        arr[i] = x % 10;
        carry = x / 10;
    }
    
    //if any carry is left after total array is multiplied
    while( carry > 0){
        arr[(*len)++] = carry % 10;
        carry /= 10;
    }
    
}

int main(void){
    int n;
    scanf("%d", &n);
    int a[200];
    a[0] = 1;
    int i = 1;
    int len = 1;
    for(i = 2; i <= n; i++){
        multiply(a, i, &len) ;
    }

    for(i = len-1; i >= 0; i--)
        printf("%d", a[i]);
}

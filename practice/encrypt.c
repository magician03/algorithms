#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void findFactors(int arr[], int len){
    double x = sqrt((double)len);
    int low = (int)x;
    if(low * low != len){
        int high = (int)x + 1;
        arr[1] = high;
    }
    if(low * arr[1] < len){
        //printf("true");
        arr[0] = arr[1];
    } else 
        arr[0] = low;    
}

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    int len = strlen(s);
    int arr[2];
    findFactors(arr, len);
    //printf("%d %d %d\n", arr[0], arr[1], len);
    
    int i,j;
   

    for(i = 0; i < arr[1]; i++){
        for(j = 0 ; j < arr[0]; j++){
            printf("%c", s[arr[1]*j + i]);
        }
        printf(" ");
    }
    printf("\--/*+b");
    return 0;
}

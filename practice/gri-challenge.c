#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printMatrix(char ** matrix, int n) {
    int i,j;
    printf("\n\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    return ;
}


// A function to implement bubble sort
void bubbleSort(char arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              {
                  char temp;
                  temp = arr[j+1];
                  arr[j+1] = arr[j];
                  arr[j] = temp;
              }
}

void challenge(char** matrix, int n) {
    //sort individual rows
    //printMatrix(matrix, n);
    for(int i =0; i < n; i++){
        bubbleSort(matrix[i], n);
        if( i > 0) {
            for(int j =0; j < n; j++) {
                if (matrix[i-1][j] > matrix[i][j]) {
                    printf("NO\n");
                    return;
                }
            }
        }
        
    }
    //printMatrix(matrix, n);
    for(int j = 0; j < n; j++){
        for(int i =0; i < n-1; i++) {
            if (matrix[i][j] > matrix[i+1][j]) {
                printf("NO\n");
                return;
            }
        }
    }

    printf("YES\n");
    return;

}




int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char ** matrix;
        matrix = (char **)malloc(n * sizeof(char *));
        int i;
        for(i = 0; i < n; i++) {
            matrix[i] = (char *) malloc(n * sizeof(char));
            scanf("%s", matrix[i]);
        }

        

        challenge(matrix, n);

    }
    
    
    return 0;
}

/*
ebacd
fghij
olmkn
trpqs
xywuv
*/

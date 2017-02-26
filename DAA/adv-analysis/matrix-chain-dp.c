#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

void printMatrix(int ** mat, int n){
    int i,j;
    for(i = 1; i < n; i++) {
        for(j = 1; j < n; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void matrixChainMul(int ** m, int ** s, int n, int dim[]) {
    for(int i = 1; i < n; i++)                                  //for all chains of length 1
        m[i][i] = 0;
        printf("initialised zeros\n");
    for(int l = 2; l < n; l++ ) {                               // chain lengths
        for(int i = 1; i <= n-l; i++) {                          //bottom-top DP arroach
            int j = i + l - 1;                                  //matrix range from i to l 
            m[i][j] = INT_MAX;                                  // assign -infinity as min possible complexity
            for(int k = i; k < j ; k++) {                        // iterate for dif values of k
                int temp = m[i][k] + m[k+1][j] + dim[(i-1)]*dim[k]*dim[j] ;    
                if ( temp < m[i][j]) {
                    m[i][j] = temp;
                    s[i][j] = k;                                // cut to be made a k, to range i, j where j-i = l
                }
            }
        }
    }

}

void printParenth(int **s, int i, int j){
    if(i == j){
        printf("%d", i);
    } else {
        printf("(");
        printParenth(s, i, s[i][j]);
        printParenth(s, s[i][j]+1, j);
        printf(")");
    }
    //printf("\n");
}


int main(void) {

    /*
    int** mat;
    mat = (int **)malloc(10* sizeof(int*));
    for(int i = 0; i < 10; i++){
        mat[i] = (int*)malloc(10 * sizeof(int));
        for(int j = 0; j < 10; j++){
            mat[i][j] = i*i + j*j;
        }
    }
    printMatrix(mat);
    */
    int ** m;
    int ** s;
    int dim[7] = {30, 35, 15, 5, 10, 20, 25};
    m = (int **)malloc(7*sizeof(int *));
    s = (int **)malloc(7*sizeof(int *));

    for(int i = 0; i < 7; i++) {
        m[i] = (int *)malloc(7*sizeof(int));
        s[i] = (int *)malloc(7*sizeof(int));
        for(int j = 0; j < 7; j++){
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    //printMatrix(m, n);
    //printMatrix(s);
    matrixChainMul(m, s, 7, dim);
    printMatrix(m, 7);
    printf("\n\n\n");
    printMatrix(s, 7);
    printf("\n\n");
    printParenth(s, 1, 6);

    return 0;
}
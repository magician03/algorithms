#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

void recursiveActivitySelector(int s[], int f[], int k, int n, int opt[], int optSize ) {
    
    if(k >= n-1) return ;
    
    int m = k + 1;
    //printf("here at %d", k);
    while (m < n && s[m] < f[k]) { //select the 11st job that starts just after f[k]
        //printf("%d %d", s[m], f[k]);
        m++;
    }

    opt[++optSize] = m;
    recursiveActivitySelector(s, f, m, n, opt, optSize);

    return ;
}


int main(void) {

    int s[12] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int f[12] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int optSize = -1;
    int opt[11] = {-1};

    recursiveActivitySelector(s, f, 0, 12, opt, optSize);

    for(int i = 0; i < 12; i++){
        printf("%d ", opt[i]);
    }

    printf("\n");

    return 0;
}
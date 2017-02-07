#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    //for each test case
    for(int a0 = 0; a0 < t; a0++){
        int R; 
        int C; 
        scanf("%d %d",&R,&C);
        char* G[R];
        for(int G_i = 0; G_i < R; G_i++){
           G[G_i] = (char *)malloc(1024 * sizeof(char));
           scanf("%s",G[G_i]);
        }
        int r; 
        int c; 
        scanf("%d %d",&r,&c);
        char* P[r];
        for(int P_i = 0; P_i < r; P_i++){
           P[P_i] = (char *)malloc(1024 * sizeof(char));
           scanf("%s",P[P_i]);
        }
        //printf("------------\n");
        //printf("segcheck-0");
        char* prev = "\0";
        int k = 0;
        int i;
        int arr[R];
        
        for( i = 0 ; i < R; i++) {
            //printf("segcheck- 1");
            char* c = strstr(G[i], P[k]) ;
            //printf("segcheck-2");
            int x = c - G[i];
            if ( x >= 0 ) {
                k++;
            }
            arr[i] = x;
            //printf("%d", x);
        }
        int flag = 0;
        for( i = 0 ; i < R; i++) {
            if (arr[i] > 0 && ( arr[i] == arr[i-1] || arr[i] == arr[i+1])) {
                flag += 1;
                //printf("%d\n", flag);
                if(flag == r) {
                    printf("YES\n");
                    break;
                }
            } else 
                flag = 0;
        }
            if(flag == r) continue;
            printf("NO\n");
            
        //printf("\n");
    }
    return 0;
}

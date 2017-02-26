#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int rodCutRecursive( int prices[], int k) {
    int curr = INT_MIN;
    if (k == 0) {
        return 0;
    } else {
        for(int i = 1; i <= k; i++){
            int temp = (prices[i] + rodCutRecursive(prices, k-i));
            curr = (curr > temp) ? curr : temp;
        }

        return curr ;
    }

}

int rodCutTopDownMemoAux(int prices[], int k, int r[]) {
    if(r[k] > 0)
        return r[k];
    else {
        if (k == 0){
            return 0;
        } else {
            int curr = INT_MIN;
            for(int i = 1; i <= k; i++){
                int temp = prices[i] + rodCutTopDownMemoAux(prices, k-i, r);
                curr = (curr > temp) ? curr : temp;
            }
            
            r[k] = curr;
            return r[k];
        }
    }
}

int * rodCutTopDownMemo(int prices[], int k) {
    int r[11] = {INT_MIN};
    int kOpt = rodCutTopDownMemoAux(prices, k, r);

    for(int i = 1; i < 11; i++) {
        printf("%d ", r[i]);
    }  
    return kOpt;
}

int * rodCutBottomUp(int prices[], int k) {
    int r[11];
    r[0] = 0;

    for(int i = 1; i <= k; i++){
        int curr = INT_MIN;
        for(int j = 1; j <= i; j++) {
            int temp = prices[j] + r[i-j];
            //if( i - j != 0) temp -= 2;
            curr = (curr > temp) ? curr : temp;
        }
        r[i] = curr;
    }
    for(int i = 1; i < 11; i++) {
        printf("%d ", r[i]);
    }
    return r;    

}





int main(void) {

    int prices[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    //printf("%d", rodCutRecursive(prices, 4));

    int * r = rodCutTopDownMemo(prices, 10);




    return 0;
}
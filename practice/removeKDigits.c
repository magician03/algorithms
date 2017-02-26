char* removeKdigits(char* num, int k) {
    if(strlen(num) == 1) {
        if(k == 1) return "0";
        else return num;
    }
    int pastlen = strlen(num);
    int i = 0;
    while ( i < k ) {
        int index = 0;
        int len = strlen(num);
        while(index < len-1) {
            if(num[index] > num[index+1]) {
                memmove(&num[index], &num[index+1], len - index);
                len -= 1;
                break;
            }
            
            index++;
        }
        i++;
    }
    /*
    int currlen = strlen(num);
    if (currlen != (pastlen-k)) {
        while (currlen > (pastlen-k)) {
            int maxIndex = -1;
            int max = 0;
            int i = 0;
            while (i < currlen) {
                if (num[i] > max){
                    max = num[i];
                    maxIndex = i;
                }
                i++;
            }
            //printf("%d--%s", currlen, num);
            memmove(&num[maxIndex], &num[maxIndex+1], currlen - maxIndex);
            currlen -= 1;
        }
    }*/
    
    int currlen = strlen(num);
    if(currlen != (pastlen-k)) {
        char* temp = (char*)malloc((pastlen-k+1)* sizeof(char));
        strncpy(temp, num, (pastlen-k));
        //printf("%s", temp);
        temp[pastlen-k] = '\0';
        //printf("%s", temp);
        if ( strlen(temp) != 0) return temp;
        else return "0";
    }
    
    //printf("%d\n", strlen(num));
    i = 0;
    int len = strlen(num);
    while((i < len) && (num[i] == '0')){
        //printf("%s\n", num);
        memmove(&num[i], &num[i+1], len - i);
        len -= 1;
    }
    //printf("%d", strlen(num));
    if ( strlen(num) != 0) return num;
    else return "0";
}
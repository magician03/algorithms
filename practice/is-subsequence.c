bool isSubsequence(char* s, char* t) {
    int s_i = 0, t_i = 0;
    int slen = strlen(s), tlen = strlen(t);
    while ( (s_i < slen) && (t_i < tlen)) {
        if (s[s_i] == t[t_i]){
            s_i++;
        }
        t_i++;
    }
    
    if(s_i == strlen(s) ) return true;
    
    return false;
}
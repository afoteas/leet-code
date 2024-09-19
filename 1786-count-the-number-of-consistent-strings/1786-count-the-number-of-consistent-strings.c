int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int ret = 0;
    for(int i=0; i< wordsSize;i++) {
        bool found = true;
        char *p=words[i];
        while(*p != '\0'){
            char* result = strchr(allowed, *p);
            if (result == NULL) {
                found = false;
                break;
            }
            p++;
        }
        if (found) ret++;
    }
    return ret;
}

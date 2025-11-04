int finalValueAfterOperations(char** operations, int operationsSize) {
    int ret = 0;
    for(int i = 0; i < operationsSize; i++)
    {
        ret = operations[i][1] == '+' ? ++ret : --ret;
    }
    return ret;
}
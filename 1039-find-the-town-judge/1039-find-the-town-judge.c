int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* numTrust = (int*)calloc(n + 1, sizeof(int)); // Allocate memory for numTrust array
    int i;
    printf("%d,%d,%d\n",n,trustSize,trustColSize);

    for(i=0;i<trustSize;++i) {
        numTrust[trust[i][0]]--;
        numTrust[trust[i][1]]++;
    }
    
    for(i=1; i<(n+1);i++){
        printf("%d\n", numTrust[i]);
        if(numTrust[i] == n-1) {
            return i;
        }
    }
    
    return -1;
    
}


        // numTrust = [0] * (n + 1)
        // print(numTrust)

        // # Increase trust value of trustee and decrease trust value of truster for each pair
        // for person1, person2 in trust:
        //     numTrust[person1] -= 1
        //     numTrust[person2] += 1
        
        // # Check if anyone achieves n-1 trust. This person is the town judge
        // for i in range(1, len(numTrust)):
        //     if numTrust[i] == n - 1:
        //         return i
        
        // # If no one achieves n-1 trust, then there is no town judge
        // return -1
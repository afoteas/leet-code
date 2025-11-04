int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for(int i = triangleSize-2; i > -1 ; i--) {
        for(int j = 0; j < triangleColSize[i]; j++) {
            int l = triangle[i + 1][j];
            int r = triangle[i + 1][j + 1];
            triangle[i][j] += l > r ? r : l;
        }
    }
    return triangle[0][0];
    
}
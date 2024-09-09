/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for returnSize
    *returnSize = m;  // Set the size to the number of rows

    // Allocate memory for returnColumnSizes
    *returnColumnSizes = (int*)malloc(m * sizeof(int)); 
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;  // Each row has 'n' columns
    }
    int** matrix = (int**)malloc(m * sizeof(int*));  // Allocate memory for rows
    for(int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));  // Allocate memory for each row
        for(int j = 0; j < n; j++) {
            matrix[i][j] = -1;  // Initialize all elements to -1
        }
    }
    int m_min=0, m_max = n-1;
    int n_min=0, n_max = m-1;
    while(head) {
        for(int i=m_min; i < m_max+1; i++) {
            if (head) {
                matrix[n_min][i]=head->val;
                head = head->next;
            } 
            else return matrix;
        }
        n_min++;
        for(int i=n_min; i < n_max+1; i++) {
            if (head)
            {
                matrix[i][m_max]=head->val;
                head = head->next;
            } 
            else return matrix;
        }
        m_max--;
        for(int i=m_max; i > m_min-1; i--) {
            if (head)
            {
                matrix[n_max][i]=head->val;
                head = head->next;
            } 
            else return matrix;
        }
        n_max--;
        for(int i=n_max; i > n_min-1; i--) {
            if (head)
            {
                matrix[i][m_min]=head->val;
                head = head->next;
            } 
            else return matrix;
        }
        m_min++;

    }
    return matrix;
    
}
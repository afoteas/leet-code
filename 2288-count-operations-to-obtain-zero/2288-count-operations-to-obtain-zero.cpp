class Solution {
    int operations = 0;
public:
    int countOperations(int num1, int num2) {
        // cout << "num1: " << num1 << ", num2: " << num2 << "\n";
        if (num1 == 0 || num2 == 0) {
            return operations;
        }
        // if (num1 == num2) {
        //     return operations +1;
        // }
        if (num1 > num2) {
            num1 -= num2;
        }
        else {
            num2 -= num1;
        }
        operations++;
        return countOperations(num1, num2);
    }
};
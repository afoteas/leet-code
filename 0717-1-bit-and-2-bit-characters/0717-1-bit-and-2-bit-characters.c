#include <stdbool.h>
bool isOneBitCharacter(int* bits, int bitsSize) {
    bool second = false;
    bool ret = true;
    for(int i; i < bitsSize; i++) {
        if (second) {
            second = false;
            ret = false;
        }
        else {
            if (bits[i]) {
                second = true;
            } else {
                second = false;
                ret = true;
            }
        }
    }
    return ret;
}
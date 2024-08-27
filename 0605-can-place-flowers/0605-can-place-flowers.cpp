class Solution {
public:
    bool canPlaceFlowersMine(vector<int>& flowerbed, int n) {
        int fsize = flowerbed.size();
        if (n == 0) {
            return true;
        }
        if(fsize < 3) {
            if (flowerbed.at(0) == 1) {
                return false;
            } else if (fsize == 2 && (flowerbed.at(0) == 1 || flowerbed.at(1) == 1)) {
                return false;
            } else {
                return n < 2;
            }

        }
        if (flowerbed.at(0) == 0 && flowerbed.at(1) == 0) {
            n--;
            flowerbed[0]=1;
        }
        for(int i=1; i < fsize-1; i++) {
            if (n==0) {
                return true;
            }
            if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                n--;
                flowerbed[i] = 1;
            }
        }
        if (flowerbed.at(fsize-1) == 0 && flowerbed.at(fsize-2) == 0 && n == 1) {
            return true;
        }
        return n == 0;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            bool left = i == 0 || flowerbed[i - 1] == 0;
            bool right = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
            
            if (left && right && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;        
    }
};
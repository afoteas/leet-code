class Solution {
public:
    int minLength(string s) {
    std::string tmp = s;

    // Loop until no more "AB" or "CD" can be replaced
    while (true) {
        std::size_t pos_ab = tmp.find("AB");
        // Erase "AB" if found
        if (pos_ab != std::string::npos) {
            tmp.erase(pos_ab, 2);
        }

        std::size_t pos_cd = tmp.find("CD");
         // Erase "CD" if found
        if (pos_cd != std::string::npos) {
            tmp.erase(pos_cd, 2);
        }

        // If neither "AB" nor "CD" is found, break the loop
        if (pos_ab == std::string::npos && pos_cd == std::string::npos) {
            break;
        }

    }

    return tmp.length();

    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;
        if (haystack.size() < needle.size()) return -1;
        int index = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack[i] != needle[index]) continue;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i+j] != needle[index+j]) {
                    break;
                }
            }

        }
        return -1;
    }
};
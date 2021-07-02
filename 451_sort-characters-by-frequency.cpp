//
// Created by 71401 on 2021/7/3.
//

class Solution {
private:
    struct Count {
        char alphabet;
        int num;
    };

    int getIndex(char c, vector <Count> alphabets) {
        for (int i = 0; i < alphabets.size(); ++i) {
            if (alphabets[i].alphabet == c) {
                return i;
            }
        }
        return -1;
    }

public:
    string frequencySort(string s) {
        vector <Count> alphabets;
        for (char c : s) {
            int index = getIndex(c, alphabets);
            if (index != -1) {
                alphabets[index].num++;
            } else {
                alphabets.push_back({c, 1});
            }

        }

        sort(alphabets.begin(), alphabets.end(), [](Count x, Count y) { return x.num > y.num; });

        string rslt = "";
        for (int i = 0; i < alphabets.size(); ++i) {
            for (int j = 0; j < alphabets[i].num; ++j) {
                rslt += alphabets[i].alphabet;
            }
        }
        return rslt;
    }
};
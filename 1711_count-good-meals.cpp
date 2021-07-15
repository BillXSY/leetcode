//
// Created by 71401 on 2021/7/7.
//

#include <vector>
#include <cmath>

class Solution {
private:
    vector<int> Delicious = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152};

    void setDelicious() {
        for (int i = 1; i < 22; ++i) {
            Delicious.push_back(pow(2, i));
        }
    }

    bool isDelicious(int num) {
        for (int i:Delicious) {
            if (i == num) {
                return true;
            }
        }
        return false;

//        int left = 0, right = 20;
//        while (left <= right) {
//            int mid = (left + right) / 2;
//            if (num == Delicious[mid]) {
//                return true;
//            } else if (num < Delicious[mid]) {
//                right = mid - 1;
//                continue;
//            } else if (num > Delicious[mid]) {
//                left = mid;
//                continue;
//            }
//        }
//        return false;
    }

public:
    int countPairs(vector<int> &deliciousness) {
//        setDelicious();

        int count = 0;
        for (int i = 0; i < deliciousness.size(); ++i) {
            for (int j = i + 1; j < deliciousness.size(); ++j) {
//                cout << "checking " << deliciousness[i] << ' ' << deliciousness[j];
                if (isDelicious(deliciousness[i] + deliciousness[j])) {
//                    cout << " marked";
                    count++;
                    count = count % 1000000007;
                }
//                cout << endl;
            }
        }
        return count;

    }
};
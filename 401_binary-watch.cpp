//
// Created by 71401 on 2021/6/21.
//

class Solution {
public:
    vector <string> readBinaryWatch(int turnedOn) {
        vector <string> rslt;
        for (int h = 0; h < 11; ++h) {
            for (int min = 0; min < 59; ++min) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    rslt.push_back(to_string(h) + ":" + (min < 10 ? "0" : "") + to_string(min));
                }
            }
        }
        return rslt;
    }
};
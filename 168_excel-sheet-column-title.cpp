//
// Created by 71401 on 2021/6/29.
//

class Solution {
private:
    vector<string> alphabets = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
public:
    string convertToTitle(int columnNumber) {
        string rslt = "";
        while (columnNumber > 0) {
            columnNumber--;
            int curr = columnNumber % 26;
            rslt = alphabets[curr] + rslt;
            columnNumber /= 26;

        }
        return rslt;
    }
};
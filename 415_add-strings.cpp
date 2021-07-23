//
// Created by 71401 on 2021/7/23.
//
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int index = 0;
        int length1 = num1.size();
        int length2 = num2.size();
        string rslt;

        while (index < length1 || index < length2) {
            char bit1 = index < length1 ? num1[length1 - 1 - index] : '0';
            char bit2 = index < length2 ? num2[length2 - 1 - index] : '0';

            char curr_bit = bit1 + bit2 - '0' + carry;
            if (curr_bit > '9') {
                carry = 1;
                curr_bit = curr_bit - 10;
            } else {
                carry = 0;
            }
            rslt = curr_bit + rslt;
            index++;
        }
        if (carry) {
            rslt = '1' + rslt;

        }
        return rslt;
    }
};
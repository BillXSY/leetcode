//
// Created by 71401 on 2021/5/26.
//

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for (char ch: s) {
            if (ch == '(') {
                stk.push(str);
            } else if (ch == ')') {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            } else {
                str += ch;
            }
        }
    }
};
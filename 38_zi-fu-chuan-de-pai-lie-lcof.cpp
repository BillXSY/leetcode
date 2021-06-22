//
// Created by 71401 on 2021/6/22.
//

class Solution {
private:
    string pop(int i, string s, int count) {
        s[i] = s[count - 1];
        return s;
    }

    void push(string s, vector <string> &rslt, bool dup) {
        if (dup) {
            for (int i = rslt.size() - 1; i >= 0; --i) {
                if (rslt[i] == s) {
                    return;
                }
            }
            // cout << s << endl;
            rslt.push_back(s);
        } else {
            // cout << s << endl;
            rslt.push_back(s);
        }

    }

    void permutation_helper(string Chars, vector <string> &rslt, string s, int count, bool dup) {
        if (count == 1) {
            push(s + Chars[0], rslt, dup);
        }
        for (int i = 0; i < count; ++i) {
            permutation_helper(pop(i, Chars, count), rslt, s + Chars[i], count - 1, dup);
        }
    }

    bool Check_duplicate(string s) {
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                if (s[i] == s[j]) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    vector <string> permutation(string s) {
        bool dup = Check_duplicate(s);
        vector <string> rslt;
        permutation_helper(s, rslt, "", s.length(), dup);
        return rslt;
    }
};
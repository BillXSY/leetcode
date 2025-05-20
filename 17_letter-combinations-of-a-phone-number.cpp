//
// Created by 71401 on 2021/4/29.
//

class Solution {

public:
    vector<string> letterCombinations(string digits) {
        vector<string> rslt;
        rslt.push_back("");
        string s;
        int size;
        for (char c : digits) {
            switch (c) {
                case '2':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 'a');
                        rslt.push_back(s + 'b');
                        rslt.push_back(s + 'c');
                    }
                    break;
                case '3':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 'd');
                        rslt.push_back(s + 'e');
                        rslt.push_back(s + 'f');
                    }
                    break;
                case '4':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 'g');
                        rslt.push_back(s + 'h');
                        rslt.push_back(s + 'i');
                    }
                    break;
                case '5':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 'j');
                        rslt.push_back(s + 'k');
                        rslt.push_back(s + 'l');
                    }
                    break;
                case '6':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 'm');
                        rslt.push_back(s + 'n');
                        rslt.push_back(s + 'o');
                    }
                    break;
                case '7':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 'p');
                        rslt.push_back(s + 'q');
                        rslt.push_back(s + 'r');
                        rslt.push_back(s + 's');
                    }
                    break;
                case '8':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 't');
                        rslt.push_back(s + 'u');
                        rslt.push_back(s + 'v');
                    }
                    break;
                case '9':
                    size = rslt.size();
                    for (int i = 0; i < size; ++i) {
                        s = rslt.front();
                        rslt.erase(rslt.begin());
                        rslt.push_back(s + 'w');
                        rslt.push_back(s + 'x');
                        rslt.push_back(s + 'y');
                        rslt.push_back(s + 'z');
                    }
                    break;
            }
        }
        if (rslt.size() == 1) rslt.pop_back();
        return rslt;
    }
};
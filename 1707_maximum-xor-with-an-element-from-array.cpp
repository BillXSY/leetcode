//
// Created by 71401 on 2021/5/23.
//
struct Trie {
    Trie *left = nullptr;
    Trie *right = nullptr;

    Trie(){};
};


class Solution {
private:
    Trie *root = new Trie();
    static constexpr int HIGH_BIT = 30;

public:
//    add a new number into the Trie Tree
    void add(int num){
        Trie *curr = root;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!curr->left) {
                    curr->left = new Trie();
                }
                curr = curr->left;
            } else {
                if (!curr->right) {
                    curr->right = new Trie();
                }
                curr = curr->right;
            }
        }
//        cout << num << " is added" << endl;
    }

//    return the XOR value basing on the existing trie tree
    int check_XOR(int num){
        Trie *curr = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0 ; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (curr->right) {
                    curr = curr->right;
                    x = 2 * x + 1;
                } else {
                    curr = curr->left;
                    x *= 2;
                }
            } else {
                if (curr->left) {
                    curr = curr->left;
                    x = 2 * x + 1;

                } else {
                    curr = curr->right;
                    x *= 2;
                }
            }

        }
//        cout << num << " is checked, the result is " << x << ' ';
        return x;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        int m_size = queries.size(), n_size = nums.size();
        vector<int> rslt(m_size);


        for (int i = 0; i < m_size; ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const vector<int> &x,  const vector<int> &y) {
            return x[1] < y[1];
        });

        sort(nums.begin(), nums.end());
        int m_index = 0, n_index = 0;
        while (nums[0] > queries[m_index][1]) {
            rslt[queries[m_index][2]] = -1;
            m_index++;
        }
        while ( n_index < n_size && m_index < m_size) {
            vector<int> curr_q = queries[m_index];
            int x_i = curr_q[0], m_i = curr_q[1], posi =  curr_q[2];
            for (int i = n_index; i < n_size; ++i) {
                if (nums[i] <= m_i) {
                    add(nums[i]);
                } else {
                    n_index = i;
                    break;
                }
            }

            rslt[ posi ] = check_XOR(x_i);
            m_index++;


        }
        return rslt;

    }
};
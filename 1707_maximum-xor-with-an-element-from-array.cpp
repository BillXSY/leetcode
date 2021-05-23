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

    int get_index(vector<int> target, vector<vector<int>>& queries, vector<int> rslt){
        int s = queries.size();
        for (int i = 0; i < s; ++i) {
            if (queries[i][0] == target[0] && queries[i][1] == target[1] && rslt[i] == 0) {
                cout << "the index is: " << i << '\n';
                return i;
            }
        }
        return -1;
    }
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
        cout << num << " is added" << endl;
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
        cout << num << " is checked, the result is " << x << ' ';
        return x;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> q = queries;
        sort(q.begin(), q.end(), [](const vector<int> &x,  const vector<int> &y) {
            return x[1] < y[1];
        });

        std::sort(nums.begin(), nums.end());

/*       for (vector<int> v : queries) {
            cout << "[" << v[0] << ', ' << v[1] << '], ';
        }
        for (int i : nums) {
            cout << i << ' ';
        }
        return queries[0];*/


        int m_index = 0, n_index = 0;
        int m_size = q.size(), n_size = nums.size();
        vector<int> rslt(m_size);

        while (( n_index < n_size && m_index < m_size)) {
            if (nums[0] > q[m_index][1]) {
                cout << q[m_index][1] << " is too small" << endl;
                rslt[get_index(q[m_index++],queries, rslt)] = -1;
            }
            for (int i = n_index; i < n_size; ++i) {
                if (nums[i] <= q[m_index][1]) {
                    add(nums[i]);
                } else {
                    n_index = i;
                    break;
                }
            }
            int sth = get_index(q[m_index], queries, rslt);
            rslt[sth] = check_XOR(q[m_index][0]);
            m_index++;


        }
        return rslt;

    }
};
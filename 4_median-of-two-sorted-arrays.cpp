//
// Created by 71401 on 2021/7/20.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        /*int n1 = nums1.size();
        int n2 = nums2.size();
        if (!n1) {
            double mid1 = n1 % 2 ? nums1[n1 / 2] : (nums1[(n1 - 2) / 2] + nums1[n1 / 2]) / 2.0;
        } else {

        }
        if (!) {}
        double mid2 = n2 % 2 ? nums2[n2 / 2] : (nums2[(n2 - 2) / 2] + nums2[n2 / 2]) / 2.0;
        return (mid1 + mid2) / 2.0;*/

    }
};

int main() {
    vector<int> vec1 = {1, 2};
    vector<int> vec2 = {3, 4};
    Solution solution;
    cout << solution.findMedianSortedArrays(vec1, vec2);


}
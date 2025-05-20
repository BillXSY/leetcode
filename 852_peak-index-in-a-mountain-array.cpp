//
// Created by 71401 on 2021/6/15.
//

class Solution {
public:
//    int peakIndexInMountainArray(vector<int>& arr) {
//        int size = arr.size();
//        int temp = arr[0];
//        for (int i = 1; i < size; ++i) {
//            if (arr[i]<temp) {
//                return i-1;
//            } else {
//                temp = arr[i];
//            }
//        }
//    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid + 1] < arr[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
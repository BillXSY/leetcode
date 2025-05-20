class Solution {
public:
    int findMin(vector<int>& nums) {
        int l_it = 0, r_it = nums.size() - 1;
        while (l_it < r_it){
            int pivot = (l_it + r_it) / 2;
            if (nums[l_it] == nums[r_it]){
                if (r_it - l_it == 1) break;
                else l_it++;
            }
            else if (nums[pivot] > nums[r_it]){
                l_it = pivot + 1;
            }
            else if (nums[pivot] <= nums[r_it]){
                r_it = pivot;
            }
        }
        return nums[l_it];
    }
};
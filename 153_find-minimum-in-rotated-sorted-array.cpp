class Solution {
public:
    //遍历数组
    //时间复杂度 O(n) 
    //空间复杂度 O(1)
    int findMin(vector<int>& nums) {
      int temp = nums[0];
      for (size_t i = 1; i < nums.size(); i++) {
        temp = temp < nums[i] ? temp : nums[i];
      }
      return temp;
    }

    //二分查找!
    int findMin(vector<int>& nums) {
        int l_it = 0, r_it = nums.size() - 1;
        while (l_it < r_it){
            int pivot = (l_it + r_it) / 2;
            if (nums[r_it] > nums[pivot]){
                r_it = pivot;
            }
            else{
                l_it = pivot + 1;
            }

        }
        return nums[l_it];



    }
};

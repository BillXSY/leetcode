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

    //二分查找
    int findMin(vector<int>& nums) {
    


    }
};

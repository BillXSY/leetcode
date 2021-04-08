class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int i = 0, dup = 1;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]){
                if (dup >= 2){
                    nums[i+1] = nums[i];
                    nums[i+2] = nums[j];
                    i+=2;
                }
                else nums[++i] = nums[j];
                dup = 1;
            }
            else{
                dup++;
                nums[i+1] = nums[i];
            }
        }
        return i + (dup > 1 ? 2 : 1);
    }
};

class Solution {
public:
    //mine
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

    //leetcode official
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; //when size of nums[] is eq or les than 2, we can directly return it
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }

};

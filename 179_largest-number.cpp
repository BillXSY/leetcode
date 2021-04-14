class Solution {
public:
    string largestNumber(vector<int>& nums) {
        quicksort(0, nums.size() - 1, nums);
       /* sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });*/

//        for (int& x : nums)  cout << x << ' '; cout << endl;
        if (nums[0] == 0) return "0";
        string rslt;
        for (int& num : nums){
            rslt += to_string(num);
        }
        return rslt;
    }

    //降序
    void quicksort(int begin, int end, vector<int>& nums){
        if (end <= begin) return;
        int l_it = begin, r_it = end;
//        srand( (unsigned)time(NULL) );
//        int pivot = rand()%(end - begin + 1) + begin;
        int pivot = begin;
        while (true){
            while (my_compare(nums[pivot], nums[r_it])) {
                --r_it;
                if (r_it == begin) break;

            }
            while (my_compare(nums[l_it] ,nums[pivot])) {
                ++l_it;
                if (l_it == end) break;

            }
            if (l_it >= r_it) break;
            if (nums[l_it] == nums[r_it]) break;
            int temp = nums[r_it];
            nums[r_it] = nums[l_it];
            nums[l_it] = temp;
        }
        int temp = nums[r_it];
        nums[r_it] = nums[pivot];
        nums[pivot] = temp;
        quicksort(begin, r_it - 1, nums);
        quicksort(r_it + 1, end, nums);
    }

    bool my_compare(int x, int y){
        long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
    }
};
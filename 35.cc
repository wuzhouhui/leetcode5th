#include <vector>

using std::vector;

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l, r;

        l = -1;
        r = nums.size();
        while (l + 1 != r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m;
            else
                r = m;
        }

        if (r < nums.size() && nums[r] >= target)
            return(r);
        else if (l == -1)
            return(0);
        else
            return(nums.size());
    }
};

int main(void){}

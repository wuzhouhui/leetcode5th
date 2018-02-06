#include <vector>

using std::vector;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> pair;
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
        if (r == nums.size() || nums[r] != target) {
            pair.push_back(-1);
            pair.push_back(-1);
            return(pair);
        }

        pair.push_back(r);
        l = -1;
        r = nums.size();
        while (l + 1 != r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
                r = m;
            else
                l = m;
        }
        pair.push_back(l);
        return(pair);
    }
};

int main(void){}

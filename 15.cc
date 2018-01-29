#include <vector>

using std::vector;

class Solution {
  public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        vector<vector<int> > res;
        int t;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                t = nums[i] + nums[j] + nums[k];
                if (t < 0) {
                    ++j;
                    continue;
                } else if (t > 0) {
                    --k;
                    continue;
                } else {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    res.push_back(v);
                    t = nums[j];
                    while (j < k && nums[j] == t)
                        ++j;
                    t = nums[k];
                    while (j < k && nums[k] == t)
                        --k;
                }
                
            }
            t = nums[i];
            while (i < nums.size() && nums[i] == t)
                ++i;
        }

        return(res);
    }
};

int main(void){}

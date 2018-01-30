#include <vector>
#include <climits>

using std::vector;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        long sum, di = LONG_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                long tsum = nums[i] + nums[j] + nums[k];
                long tdi = labs(tsum - target);
                if (tdi == 0)
                    return(target);
                else if (tdi < di) {
                    di = tdi;
                    sum = tsum;
                }
                if (tsum < target)
                    ++j;
                else
                    --k;
            }
        }
        return(sum);
    }
};

int main(void){}

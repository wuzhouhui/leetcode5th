#include <vector>
#include <climits>

using std::vector;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int i, j;
        long prev = LONG_MAX;
        for (i = j = 0; i < nums.size(); i++)
            if (nums[i] == prev)
                continue;
            else {
                nums[j++] = nums[i];
                prev = nums[i];
            }
        return(j);
    }
};

int main(void){}

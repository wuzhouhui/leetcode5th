#include <vector>

using std::vector;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int i, j;
        for (i = j = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[j++] = nums[i];
        return(j);
    }
};

int main(void){}

#include <vector>
#include <iostream>

using std::vector;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    int i, j;

    for (i = 0; i < nums.size(); i++) {
      for (j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          res.push_back(i);
          res.push_back(j);
          break;
        }
      }
      if (j < nums.size())
        break;
    }
    return(res);
  }
};

int main(void)
{
  class Solution sol;
  vector<int> arr(4, 4);
  vector<int> sum = sol.twoSum(arr, 8);
  std::cout << sum[0] << sum[1] << std::endl;
}

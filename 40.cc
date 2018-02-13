#include <vector>
#include <algorithm>

using std::vector;

class Solution {
  public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int> > res;
        vector<int> buf;
        sort(candidates.begin(), candidates.end());
        do_comb(candidates, target, res, buf, 0, 0);
        return(res);
    }

  private:
    void do_comb(vector<int> &candidates, int target, vector<vector<int> > &res,
            vector<int> &buf, int sum, int start)
    {
        if (sum == target) {
            res.push_back(buf);
            return;
        }
        if (sum > target || start >= candidates.size())
            return;

	for (int i = start; i < candidates.size(); i++) {
		if (i && candidates[i] == candidates[i - 1] && i > start)
			continue;
		int t = sum + candidates[i];
		if (t > target)
			break;
		buf.push_back(candidates[i]);
		do_comb(candidates, target, res, buf, t, i + 1);
		buf.pop_back();
	}
    }
};

int main(void)
{
	vector<int> arr;
	arr.push_back(10);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(7);
	arr.push_back(6);
	arr.push_back(1);
	arr.push_back(5);
	(new Solution())->combinationSum2(arr, 8);
}

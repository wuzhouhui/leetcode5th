#include <vector>

using std::vector;

class Solution {
  public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> buf;
        do_comb(candidates, buf, res, 0, 0, target);
        return(res);
    }

  private:
    void do_comb(vector<int> &candidates, vector<int> &buf,
            vector<vector<int> > &res, int start, int sum, int target)
    {
        if (sum == target) {
            res.push_back(buf);
            return;
        }

        if (start >= candidates.size() || sum > target)
            return;

        for (int i = start; i < candidates.size(); i++) {
            int t = sum + candidates[i];
            if (t > target)
                break;
            buf.push_back(candidates[i]);
            do_comb(candidates, buf, res, i, t, target);
            buf.pop_back();
        }
    }
};

int main(void){}

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        do_gen(n, n, res, "");
        return(res);
    }

  private:
    void do_gen(int l, int r, vector<string> &res, string tmp)
    {
        if (l > r)
            return;
        if (l == 0 && r == 0) {
            res.push_back(tmp);
            return;
        }
        if (l > 0)
            do_gen(l - 1, r, res, tmp + '(');
        if (r > 0)
            do_gen(l, r - 1, res, tmp + ')');
    }
};

int main(void){}

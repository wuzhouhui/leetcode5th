#include <vector>

using std::vector;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int> >&matrix)
    {
        vector<int> res;
        if (matrix.size() == 0)
            return(res);
        int i, up = 0, low = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (up < low && left < right) {
            for (i = left; i < right; i++)
                res.push_back(matrix[up][i]);
            for (i = up; i < low; i++)
                res.push_back(matrix[i][right]);
            for (i = right; i > left; i--)
                res.push_back(matrix[low][i]);
            for (i = low; i > up; i--)
                res.push_back(matrix[i][left]);
            up++, low--, left++, right--;
        }
        if (left == right && up < low)
            for (i = up; i <= low; i++)
                res.push_back(matrix[i][left]);
        else if (up == low && left < right)
            for (i = left; i <= right; i++)
                res.push_back(matrix[up][i]);
        else if (up == low && left == right)
            res.push_back(matrix[up][left]);
        return(res);
    }
};

int main(void){}

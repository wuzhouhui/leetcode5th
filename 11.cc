#include <vector>

using std::vector;

class Solution {
  public:
    int maxArea(vector<int> &height)
    {
        int area = 0, t, i, j;

        for (i = 0, j = height.size() - 1; i < j;) {
            if (height[i] < height[j]) {
                t = height[i] * (j - i);
                i++;
            } else {
                t = height[j] * (j - i);
                j--;
            }
            if (t > area)
                area = t;
        }

        return(area);
    }
};

int main(void){}

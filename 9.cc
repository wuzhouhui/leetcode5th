class Solution {
  public:
    bool isPalindrome(int x)
    {
        int r = 0;

        if (x == 0)
            return(true);

        if (x < 0 || x % 10 == 0)
            return(false);

        while (x > r) {
            r = r * 10 + (x % 10);
            x /= 10;
        }

        return(x == r || r / 10 == x);
    }
};

int main(void){}

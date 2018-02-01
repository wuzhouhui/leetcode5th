#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
  public:
    bool isValid(string s)
    {
        stack<char> stack;
        bool res = false;

        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    stack.push(c);
                    break;
                case ')':
                    if (stack.empty() || stack.top() != '(')
                        goto out;
                    stack.pop();
                    break;
                case ']':
                    if (stack.empty() || stack.top() != '[')
                        goto out;
                    stack.pop();
                    break;
                case '}':
                    if (stack.empty() || stack.top() != '{')
                        goto out;
                    stack.pop();
                    break;
                default:
                    goto out;
            }
        }
        if (stack.empty())
            res = true;
out:
        while (stack.empty())
            stack.pop();
        return(res);
    }
};

int main(void){}

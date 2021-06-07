// Note -> push and size should work in constant time. pop and top should work in linear time.
#include <bits/stdc++.h>
using namespace std;
class stacks
{
    queue<int> mainQ, helperQ;

public:
    void push(int x)
    {
        mainQ.push(x);
    }

    void pop()
    {

        if (mainQ.size() == 0)
        {
            cout << "Stack underflow";
            return;
        }
        else
        {
            while (mainQ.size() > 1)
            {
                helperQ.push(mainQ.front());
                mainQ.pop();
            }
            int val = mainQ.front();
            mainQ.pop();
            // helperQ.push(val);
            while (helperQ.size() > 0)
            {
                mainQ.push(helperQ.front());
                helperQ.pop();
            }
            cout << val << "\n";
        }
    }

    void top()
    {
        if (mainQ.size() == 0)
        {
            cout << "Stack underflow";
            return;
        }
        else
        {
            while (mainQ.size() > 1)
            {
                helperQ.push(mainQ.front());
                mainQ.pop();
            }
            int val = mainQ.front();
            mainQ.pop();
            helperQ.push(val);
            while (helperQ.size() > 0)
            {
                mainQ.push(helperQ.front());
                helperQ.pop();
            }
            cout << val << "\n";
        }
    }

    void size()
    {
        cout << mainQ.size() << "\n";
        return;
    }
};
int main()
{
    // 1 -> push
    // 2 - > pop
    // 3 -> size
    // 4 -> top
    // 5 - > min
    string s;
    stacks ob;
    while (cin >> s)
    {
        if (s == "push")
        {
            int x;
            cin >> x;
            ob.push(x);
        }

        else if (s == "top")
        {
            ob.top();
        }
        else if (s == "pop")
        {
            ob.pop();
        }
        else if (s == "size")
        {
            ob.size();
        }
        else if (s == "quit")
        {
            break;
        }
    }
}
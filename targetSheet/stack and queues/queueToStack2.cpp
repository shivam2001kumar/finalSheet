// pop efficient
#include <bits/stdc++.h>
using namespace std;
class stacks
{
    queue<int> mainQ, helperQ;

public:
    void push(int x)
    {
        while (mainQ.size() > 0)
        {
            helperQ.push(mainQ.front());
            mainQ.pop();
        }
        mainQ.push(x);
        while (helperQ.size() > 0)
        {
            mainQ.push(helperQ.front());
            helperQ.pop();
        }
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
            cout << mainQ.front() << "\n";
            mainQ.pop();
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
            cout << mainQ.front() << "\n";
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
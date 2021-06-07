#include<bits/stdc++.h>
using namespace std;
int calc(int a, int b, char c)
{
  if (c == '+') return a + b;
  else if (c == '-') return a - b;
  else if (c == '*') return a * b;
  else return a / b;
}
int main()
{
  string s;
  getline(cin, s);
  stack<int>val;
  stack<string>inf;
  stack<string>post;

  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (isdigit(s[i]))
    {
      string temp;
      temp.push_back(s[i]);
      inf.push(temp);
      post.push(temp);
      val.push(s[i] - '0');
    }
    else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
    {
      // val stack
      int val1 = val.top();
      val.pop();
      int val2 = val.top();
      val.pop();
      int res = calc(val1, val2, s[i]);
      val.push(res);

      // infix stack
      string temp;
      temp.push_back(s[i]);
      string in1 = inf.top();
      inf.pop();
      string in2 = inf.top();
      inf.pop();
      string resIn = "(" + in1 + temp + in2 + ")";
      inf.push(resIn);

      // post stack
      string pos1 = post.top();
      post.pop();
      string pos2 = post.top();
      post.pop();
      string resPos = pos1 + pos2 + temp;
      post.push(resPos);

    }
  }
  cout << val.top() << "\n";
       cout << inf.top() << "\n";
       cout << post.top() << "\n";
       return 0;
}
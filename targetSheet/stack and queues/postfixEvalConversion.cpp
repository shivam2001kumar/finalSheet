#include<bits/stdc++.h>
using namespace std;
int calc(int a, int b, char ch)
{
  if (ch == '+') return a + b;
  else if (ch == '-') return a - b;
  else  if (ch == '*') return a * b;
  else return a / b;

}
int main()
{
  string s;
  getline(cin, s);
  stack<int>val;
  stack<string>pre;
  stack<string>inf;

  for (int i = 0; i < s.size(); i++)
  {
    if (isdigit(s[i]))
    {
      string temp;
      temp.push_back(s[i]);
      pre.push(temp);
      inf.push(temp);
      val.push(s[i] - '0');
    }
    else if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
    {
      // val stack
      int val2 = val.top();
      val.pop();
      int val1 = val.top();
      val.pop();

      int res = calc(val1, val2, s[i]);
      val.push(res);

      // prefix stack
      string oprator ;
      oprator.push_back(s[i]);
      string pre2 = pre.top();
      pre.pop();
      string pre1 = pre.top();
      pre.pop();
      string resPre = oprator + pre1 + pre2;

      // infix stack
      string in2 = inf.top();
      inf.pop();
      string in1 = inf.top();
      inf.pop();
      string resin = "(" + in1 + oprator + in2 + ")";

      pre.push(resPre);
      inf.push(resin);
    }
  }
  cout << val.top() << "\n";
       cout << inf.top() << "\n";
       cout << pre.top();


  return 0;
}
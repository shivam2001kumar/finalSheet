#include<bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if(ch=='+' or ch=='-')
        return 1;
    else return 2;
}
int main()
{
    string s;
    getline(cin,s);
    stack<string>pre;
    stack<string>post;
    stack<char>opr;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            opr.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(opr.top()!='(')
            {
                char oper=opr.top();
                string oprator;
                oprator.push_back(oper);
                opr.pop();
                string val2 = post.top();
                post.pop();
                string val1 = post.top();
                post.pop();
                string res1 = val1+val2+oprator; 
                // cout<<res1<<" ";
                // prefix stack
                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();
                string res2 = oprator+v1+v2; 
                // cout<<res2<<" ";
                post.push(res1);
                pre.push(res2);
            }
            opr.pop();
        }
        else if(isdigit(s[i]) or isalpha(s[i]))
        {
            string preS,postS;
            preS.push_back(s[i]);
            postS.push_back(s[i]);
            pre.push(preS);
            post.push(postS);
        }
        else if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/')
        {
            while(opr.size()>0 && opr.top()!='(' && prec(opr.top())>=prec(s[i]) )
            {
                char oper=opr.top();
                string oprator;
                oprator.push_back(oper);
                opr.pop();
                string val2 = post.top();
                post.pop();
                string val1 = post.top();
                post.pop();
                string res1 = val1+val2+oprator; 
                // cout<<res1<<" ";
                // prefix stack
                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();
                string res2 = oprator+v1+v2; 
                // cout<<res2<<" ";
                post.push(res1);
                pre.push(res2);
            }
            opr.push(s[i]);
        }
    }
    while(opr.size()!=0 )
            {
                char oper=opr.top();
                string oprator;
                oprator.push_back(oper);
                opr.pop();
                string val2 = post.top();
                post.pop();
                string val1 = post.top();
                post.pop();
                string res1 = val1+val2+oprator; 
                // cout<<res1<<" ";
                // prefix stack
                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();
                string res2 = oprator+v1+v2; 
                // cout<<res2<<" ";
                post.push(res1);
                pre.push(res2);
            }
    cout<<post.top()<<"\n";
    cout<<pre.top()<<"\n";
}
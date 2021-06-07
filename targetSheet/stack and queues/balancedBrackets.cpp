#include<bits/stdc++.h>
using namespace std;
bool isBalanced(char a,char b)
{
    if(a==')' and b=='(') return true;
    if(a=='}' and b=='{') return true;
    if(a==']' and b=='[') return true;
    return false;
}
int main()
{
    string s;
    getline(cin,s);
    int flag=1;
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            st.push(s[i]);
        else if(s[i]==')' or s[i]=='}' or s[i]==']')
        {
            if(st.size()==0)
            {
                flag=0;
                cout<<"false";
                break;
            }
            else 
            {
                if(isBalanced(s[i],st.top())==false)
                {
                    flag=0;
                    cout<<"false";
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    if(flag==1)
        cout<<"true";
}
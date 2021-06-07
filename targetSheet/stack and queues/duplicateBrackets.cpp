#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    stack<char>st;
    int flag=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==')')
        {
            if(st.top()=='(')
            {
                flag=0;
                cout<<"true";
                break;
            }
            else
            {
                while(st.top()!='(')
                    st.pop();
                st.pop();
            }
        }
        else
        {
            st.push(s[i]);
        }
        
    }
    if(flag==1) cout<<"false";
    
    return 0;
}
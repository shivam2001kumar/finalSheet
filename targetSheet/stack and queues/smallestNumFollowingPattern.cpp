// smallest number following pattern
#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string temp;
        stack<int>s;
        int num=1;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='D')
            {
                s.push(num);
                
                num++;
            }
            else 
            {
                s.push(num);
                num++;
                while(s.size()>0)
                {
                    temp.push_back(s.top()+'0');
                    s.pop();
                }
            }
        }
        s.push(num);
        
        while(s.size()>0)
        {
           
        temp.push_back(s.top()+'0');
        s.pop();
        }
        
        return temp;
        
    }
};
int main()
{
    Solution ob;
    string str;
    cin>>str;
    cout<<ob.printMinNumberForPattern(str);

}
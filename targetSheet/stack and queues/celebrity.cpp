// celebrity doesnt know anyone
// and everyone knows celebrity
#include<bits/stdc++.h>
using namespace std;

// Approach 1 two pointer approach
int celebrity(vector<vector<int> >& M, int n) 
{
    int x=0,y=n-1;
    while(x<y)
    {
        if(M[x][y]==1)
        {
            x++;
        }
        else 
            y--;
    }
    // reach here when x==y
    // check if that candidate is celebrity or not

    
    for(int i=0;i<n;i++)
    {
        if(i!=y) // no need to check himself
        {
        // check if everyone knows him or not 
        if(M[i][y]!=1 ) // even if any one person doesnt know the candidate then he is not celebrity
        {
            return -1;
        }
        // check if he doesnt know anyone
        if(M[y][i]!=0) // even if he knows any one person he is not the celebrity
        {
            return -1;
        }
        }
    }
    return y; // hurray we found the element     
}

// Approach 2 using stack

int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int>s;
    for(int i=0;i<n;i++)
        s.push(i);
    while(s.size()>=2)
    {
        int a = s.top();
        s.pop();
        int b= s.top();
        s.pop();
        if(M[a][b]==1) // a knows b then a cannot be celebrity
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
        
    }
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(i!=s.top())
        {
            if(M[i][s.top()]==0 or M[s.top()][i]==1) // Anyone don't know him or he knows anyone 
            {
                return -1;
            }
        }
    }
    return s.top();
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n,i,j,k,r,l,p,x,root;
    vector<int>divisor;
    vector<int>::iterator it;
    vector<int>result;
    cin>>tc;
    for(i=1;i<=tc;i++)
    {
        cin>>p>>l;
        k=p-l;
        if(k<=l)
        {
            cout<<"Case "<<i<<": "<<"impossible"<<endl;
        }
        else
        {
            root=sqrt(k);
            for(j=1;j<root;j++)
            {
                if(k%j==0)
                {
                    divisor.push_back(j);
                    x=k/j;
                    divisor.push_back(x);
                }

            }
            x=root*root;
            if(x==k)
            {
                divisor.push_back(root);
            }
            else
            {
                if(k%root==0)
                {
                    divisor.push_back(root);
                    x=k/root;
                    divisor.push_back(x);
                }

            }
            for(it=divisor.begin();it!=divisor.end();it++)
            {
                x=*it;
                r=p%x;
                if(r==l)
                {
                    result.push_back(x);
                }
            }
            sort(result.begin(),result.end());
            x=result.size();
            j=0;
            cout<<"Case "<<i<<": ";
            for(it=result.begin();it!=result.end();it++)
            {
                cout<<*it;
                j++;
                if(j==x)
                {
                    cout<<endl;
                    break;
                }
                cout<<" ";
            }

        }
        result.clear();
        divisor.clear();
    }
    return 0;

}

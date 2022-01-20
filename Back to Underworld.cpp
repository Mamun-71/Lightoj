#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
set<int>fighter;
int vis[200005];
int tc,n,maxAns;

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    int A=1,B=0;
    vis[s]=1;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();

        for(int i=0; i<adj[f].size(); i++)
        {
            int x=adj[f][i];
            if(vis[x]==0)
            {
                if(vis[f]==1)
                {
                    q.push(x);
                    vis[x]=2;
                    B++;
                }
                else
                {
                    q.push(x);
                    vis[x]=1;
                    A++;
                }
            }
        }
    }

    maxAns=maxAns+max(A,B);
}

int main()
{
    cin>>tc;
    int c=0;
    while(tc--)
    {
        c++;
        cin>>n;///Dual fight or number of edge

        for(int i=0; i<n; i++)
        {
            int u,v;
            cin>>u>>v;

            fighter.insert(u);
            fighter.insert(v);

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(vis,0,sizeof vis);


        maxAns=0;
        for(auto it=fighter.begin(); it!=fighter.end(); it++)
        {
            int x=*it;

            if(vis[x]==0)
            {
                bfs(x);
            }
        }

        cout<<"Case "<<c<<": "<<maxAns<<endl;

        for(auto it=fighter.begin(); it!=fighter.end(); it++)
        {
            int x=*it;
            adj[x].clear();
        }
        fighter.clear();

    }
}

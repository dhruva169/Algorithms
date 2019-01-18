#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
#define endl        '\n'

bool visited[100]={false};
vector<int>G[10000];

void dfs(int node){
    visited[node]=true;
    cout<<node<<" ";
    tr(G[node], it){
        if(!visited[*it]){
            dfs(*it);
        }
    }
}

int main()
{
    fastio;
    
    int nodes,edges,x,y;
    cin>>nodes>>edges;
    for(long long int i=0;i<edges;i++){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);

    return 0;
}
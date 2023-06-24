// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++)
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define elif else if

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

int a[MaxN], hig1[MaxN], hig2[MaxN], mark[MaxN]; // ? any 1 means Odd and any 2 means Even
vector<int> adj[MaxN];
queue<int> q1, q2;

void bfs(bool b){
    queue<int> q = (b ? q1 : q2);

    while(!q.empty()){
        int h = q.front();

        for(int u: adj[h]){
            if(mark[u]) continue;

            if(b) hig1[u] = hig1[h] + 1;
            else hig2[u] = hig2[h] + 1;
            
            mark[u] = 1;
            q.push(u);

        }

        q.pop();
    }
}


main()
{IOS;

    int n; cin >> n;
    forn(i,1,n + 1) cin >> a[i];

    forn(i,1,n + 1){
        if( i - a[i] > 0 )
            adj[i - a[i]].pb(i);

        if( i + a[i] <= n )
            adj[i + a[i]].pb(i);
    }

    forn(i,1,n + 1)
        if(a[i] % 2) q1.push(i), mark[i] = 1;
        else q2.push(i);

    bfs(1);

    memset(mark, 0, sizeof(mark));
    forn(i,1,n + 1) 
        if( !(a[i] % 2) ) mark[i] = 1;

    bfs(0);

    forn(i,1,n + 1)
        if(a[i] % 2) cout << (!hig2[i] ? -1 : hig2[i]) << ' ';
        else cout << (!hig1[i] ? -1 : hig1[i]) << ' ';

}
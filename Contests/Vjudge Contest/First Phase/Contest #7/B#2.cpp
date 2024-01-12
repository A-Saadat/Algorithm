#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int par[MAX], sz[MAX]; 
int cnt;

int Find_par(int A){
    if(par[A] == A) return A;
    return par[A] = Find_par(par[A]);
}

void merge(int A, int B){
    A = Find_par(A);
    B = Find_par(B);

    if(A != B) cnt++;
    else return;

    if(sz[A] > sz[B]) swap(A, B);
    sz[B] += sz[A];
    par[A] = B;
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        par[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;

        merge(x, y);
    }

    cout << m - cnt << endl;

}
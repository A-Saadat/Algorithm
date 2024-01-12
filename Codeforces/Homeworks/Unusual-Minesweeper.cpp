// ? I Bet You Can't Understand my Code

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
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int timer[MAX], sz[MAX], par[MAX];
map< pair<int, int>, int > id;
map< int, vector<int> > mpX, mpY;

vector<int> s;

int n, k;

int Find_par(int A){
    if(par[A] == A) return A;
    return par[A] = Find_par( par[A] );
}

inline void merge(int A, int B){
    A = Find_par(A);
    B = Find_par(B);
    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);
    par[A] = B;
    sz[B] += A;
    timer[B] = min(timer[A], timer[B]);
}

inline void Union_Mines(){
    fort(itr, mpX){
        sort(all(itr->S));
        for(int i = 0; i < itr->S.size() - 1; i++){
            int y1 = mpX[itr->F][i], y2 = mpX[itr->F][i + 1];
            int idx1 = id[ {itr->F, mpX[itr->F][i]} ];
            int idx2 = id[ {itr->F, mpX[itr->F][i + 1]} ];

            if(abs(y1 - y2) > k) continue;

            merge(idx1, idx2);
        }
    }

    fort(itr, mpY){
        sort(all(itr->S));
        for(int i = 0; i < itr->S.size() - 1; i++){
            int x1 = mpY[itr->F][i], x2 = mpY[itr->F][i + 1];
            int idx1 = id[ {mpY[itr->F][i], itr->F} ];
            int idx2 = id[ {mpY[itr->F][i + 1], itr->F} ];

            if(abs(x1 - x2) > k) continue;

            merge(idx1, idx2);
        }
    }
}

inline void Solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x, y, t; cin >> x >> y >> t;
        id[ {x, y} ] = i;
        sz[i] = 1;
        par[i] = i;
        timer[i] = t;
        mpX[x].pb(y);
        mpY[y].pb(x);
    }

    Union_Mines();

    for(int i = 1; i <= n; i++)
        if(par[i] == i) s.pb(timer[i]);

    int cnt = -1;
    sort(s.rbegin(), s.rend());
    for(int u: s){
        cnt++;
        if(u < cnt) {
            cnt--;
            break;
        }
    }

    cout << cnt << endl;
}

inline void Clear_Arr(){
    mpX.clear();
    mpY.clear();
    id.clear();
    s.clear();
}

main()
{IOS;

    int tt; cin >> tt;
    while(tt--){
        Clear_Arr();
        Solve();
    } 
}
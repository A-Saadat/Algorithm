
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

int a[MAX], b[MAX]; 

int n;
int mini = INF;

vector<int> S, T;

void BT(int id){
    if(id == n + 1){
        vector<int> s, t;
        for(int i = 1; i <= n; i++) {
            if(b[i] == 0) s.pb(a[i]);
            else t.pb(a[i]);
        }
        int tt = 0, ss = 0;
        for(int i = 0; i < (int)(s.size()) - 1; i++){
            if(s[i] < s[i + 1]) ss++;
        }

        for(int i = 0; i < (int)(t.size()) - 1; i++){
            if(t[i] < t[i + 1]) tt++;
        }   


        if(tt + ss > mini) return;

        mini = tt + ss;
        S = s;
        T = t;

        // for(int u: s) cout << u << ' ';
        // cout << endl;
        // for(int u: t) cout << u << " ";


        // cout << endl << ss << " + " << tt << endl;
        // cout << "\n----------------------\n";
        return;
    }

    b[id] = 0;
    BT(id + 1);
    b[id] = 1;
    BT(id + 1);
    b[id] = 0;
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    BT(1);    

    cout << mini << endl;

    for(int u: S) cout << u << ' ';
    cout << endl;
    for(int u: T) cout << u << ' ';

}
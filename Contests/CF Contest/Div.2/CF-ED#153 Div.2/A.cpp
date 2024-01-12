#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX]; 
int n;

inline void Solve(string s){
    if(s == "()") {
        cout << "NO\n";
        return;
    }

    int cnt = 1, maxi = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1])
            cnt++;
        else{
            maxi = max(cnt, maxi);
            cnt = 1;
        }
    }
    maxi = max(cnt, maxi);

    cout << "YES\n";
    if(maxi > 1) {
        for(int i = 1; i <= n; i++)
            cout << "()";
        
        cout << endl;
    }
    else{
        for(int i = 1; i <= n; i++)
            cout << "(";
        for(int i = 1; i <= n; i++)
            cout << ")";

        cout << endl;
    }
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        n = s.size();
        Solve(s);
    }

}
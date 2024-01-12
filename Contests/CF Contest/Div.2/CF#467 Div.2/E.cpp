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

const int MAX = 2000 + 10; 
const int INF = 1e9 + 7; 

deque<char> a;
map<char, int> mp1, mp2;
char b[MAX]; 
int n; 

void _shift(int idx){
    vector<char> c;
    reverse(all(a));
    while(idx--){
        c.pb(a.front());
        a.pop_front();
    }
    reverse(all(c));
    for(char u: c) a.pb(u);
    reverse(all(a));
}

void rev(int idx){
    if(idx == 0) cout << 0 << ' ' << 0 << " " << 0 << " ";
    else{
        cout << n << " " << idx << " " << 1 << " "; 
        _shift(n);
        _shift(idx);
        _shift(1);
    }
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        a.pb(c);
        mp1[c]++;
    }
    for(int i = 1; i <= n; i++) cin >> b[i], mp2[b[i]]++;

    for(auto u: mp1)
        if(u.S != mp2[u.F]) return puts("-1");
 
    cout << 3 * n << endl;
    for(int i = n; i >= 1; i--){
        int idx = -1;
        for(int j = n - i; j < n; j++){
            if(a[j] == b[i]) {idx = j; break;}
        }
        rev(idx);
    }

}
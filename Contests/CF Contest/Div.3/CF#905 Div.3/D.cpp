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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

main()
{IOS;

    multiset<int> L, R;
    int q; cin >> q;
    while(q--){
        char c;
        int l, r;
        cin >> c >> l >> r;

        if(c == '+'){
            L.insert(l);
            R.insert(r);
        }
        else{
            auto it1 = L.find(l);
            auto it2 = R.find(r);
            L.erase(it1);
            R.erase(it2);
        }

        if(R.size() == 0 || L.size() == 0) cout << "NO" << endl; // ? i Couldn't accepte this shit because i didn't write this condition
        else{
            if(*R.begin() < *L.rbegin()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

}
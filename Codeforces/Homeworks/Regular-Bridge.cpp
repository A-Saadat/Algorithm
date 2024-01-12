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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

set< pair<int, int> > edg;

main()
{IOS;

    int k; cin >> k;
    if(!(k % 2)) return puts("NO"), 0;
    if(k == 1) {
        cout << "YES\n";
        cout << "2 1\n";
        cout << "1 2";
        return 0;
    }
    
    for(int i = 1; i <= k + 2; i++)
        for(int j = i + 1; j <= k + 2; j++)
            edg.insert( {i, j} );

    for(int i = k + 3; i <= 2 * k + 4; i++)
        for(int j = i + 1; j <= 2 * k + 4; j++)
            edg.insert( {i, j} );

    edg.insert( {k + 2, 2 * k + 4} );

    for(int i = 3; i <= k; i += 2){
        edg.erase( {i, i + 1} );
        edg.erase( {i + 1, i} );
    }

    edg.erase( {k + 2, 1} );
    edg.erase( {1, k + 2} );
    edg.erase( {k + 2, 2} );
    edg.erase( {2, k + 2} );

    for(int i = k + 5; i <= 2 * k + 2; i += 2){
        edg.erase( {i, i + 1} );
        edg.erase( {i + 1, i} );
    }

    edg.erase( {2 * k + 4, k + 3} );
    edg.erase( {k + 3, 2 * k + 4} );
    edg.erase( {2 * k + 4, k + 4} );
    edg.erase( {k + 4, 2 * k + 4} );

    cout << "YES\n";
    cout << 2 * k + 4 << " " << ((2 * k + 4) * k) / 2 << endl;
    fort(itr, edg)
        cout << itr->F << " " << itr->S << endl;
}
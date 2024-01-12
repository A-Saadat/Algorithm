#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        if(m == 1){
            cout << 0 << endl;
            for(int i = 1; i <= n; i++) cout << 0 << endl;
            continue;
        }
        if(m > n){
            cout << n + 1 << endl;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << (i + j) % m << ' ';
                }
                cout << endl;
            }
        }
        else{
            cout << m << endl;
            for(int i = 0; i < m - 1; i++){
                for(int j = 0; j < m; j++){
                    cout << (i + j) % m << ' ';
                }
                cout << endl;
            }
            for(int i = m - 1; i < n; i++){
                for(int j = 0; j < m; j++) cout << j % m << ' ';
                cout << endl;
            }
        }
    }

}
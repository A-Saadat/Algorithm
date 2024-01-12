#include <bits/stdc++.h> 
using namespace std; 


const int maxn = 1e6; 

int a[maxn]; 

main()
{

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int m = 10000000;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                m = min(m, a[j] - a[i]);
            }
        }

        if(m < 0){
            cout << 0 << endl; 
            continue;
        } 

        cout << (m / 2) + 1 << endl;
    }

}
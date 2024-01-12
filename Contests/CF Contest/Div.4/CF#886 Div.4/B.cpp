#include <bits/stdc++.h> 
using namespace std; 

vector< pair<int, int> > v;

main()
{

    int t; cin >> t;
    while(t--){
        v.clear();
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            int a, b; 
            cin >> a >> b;
            if(a <= 10){
                v.push_back( {b, i} );
            }
        }

        sort( v.begin(), v.end() );

        int ff = v.size() - 1;
        cout << v[ff].second << endl;
        
    }

}
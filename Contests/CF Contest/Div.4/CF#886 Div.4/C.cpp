#include <bits/stdc++.h> 
using namespace std;

char c[20][20];
vector<char> a; 

main()
{

    int t; cin >> t;
    while(t--){
        a.clear();
        for(int i = 1; i <= 8; i++)
            for(int j = 1; j <= 8; j++) cin >> c[i][j];

        for(int i = 1; i <= 8; i++)
            for(int j = 1; j <= 8; j++)
                if(c[i][j] != '.') a.push_back(c[i][j]);

        for(char u: a) cout << u;
        cout << endl;
    }

}
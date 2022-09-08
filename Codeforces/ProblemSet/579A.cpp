#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int intl; 
typedef vector<intl> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 

intl Solve(int x) {
    intl cnt = 0;
    while(x > 0){
        if(x % 2 != 0)
            cnt++;

        x /= 2;
    }

    return cnt;
}

int main (void)
{
    intl x; cin >> x;
    cout << Solve(x);
}
#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,t,n) for(int i=t;i<n;i++) 
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

string Binary(int x) {
    string ans;
    while(x > 0){
        if(x % 2 == 0)
            ans += "0";
        else
            ans += "1";

        x /= 2;
    }
    
    return ans;
}

intl a[def];

int main (void)
{
    intl n, m, k;
    cin >> n >> m >> k;
    
    forn(i,1,(m + 2)) cin >> a[i];

    intl Fedor = a[m + 1], sum = 0;
    forn(i,1,(m + 1)){
        string Check = Binary((Fedor ^ a[i]));

        intl cnt = 0;
        forn(i,0,(Check.size()))
            if(Check[i] == '1') cnt++;

        if(cnt <= k) sum++;
    }

    cout << sum;
}
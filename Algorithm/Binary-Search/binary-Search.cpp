#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=1;i<=n;i++) 
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

intl a[def], lastDigit[def];

int main (void)
{
    intl n; 
    cin >> n;

    forn(i,n) cin >> a[i];
    forn(i,n) lastDigit[i] = lastDigit[i - 1] + a[i];

    intl t, k;
    cin >> t;
    while(t--){
        intl R = n, L = 1;
        cin >> k;

        while(R - L != 1){
            intl mid = (R + L) / 2;

            if(lastDigit[mid] < k) L = mid + 1;
            else R = mid;
        }

        cout << R;
    }
}
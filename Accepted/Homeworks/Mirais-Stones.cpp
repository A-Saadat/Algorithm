#include <bits/stdc++.h> 
using namespace std; 

#define def 1000000
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

intl arr1[def], arr2[def];
intl Sum1[def], Sum2[def];


int main (void)
{
    intl n;
    cin >> n;
    forn(i,n){
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    sort(arr2 + 1, arr2 + n + 1);
    
    for(intl i = 1; i <= n; i++){
        Sum1[i] = Sum1[i - 1] + arr1[i]; 
        Sum2[i] = Sum2[i - 1] + arr2[i]; 
    }

    vci ans;

    intl t;
    cin >> t;
    intl type, l, r;
    forn(i,t) {
        cin >> type >> l >> r;

        if(type == 1){
            cout << Sum1[r] - Sum1[l - 1] << endl;
        }
        elif(type == 2)
            cout << Sum2[r] - Sum2[l - 1] << endl;
    }

}

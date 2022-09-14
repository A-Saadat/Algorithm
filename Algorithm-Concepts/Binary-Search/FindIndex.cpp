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

int main (void)
{
    intl arr[] = {1,2,4,5,6,10,12,29,39};

    intl L = -1;
    intl R = 9;

    intl n;
    cin >> n;

    intl MID;
    bool flag = true;
    while(R - L > 1){

        MID = (R + L) / 2;

        if(arr[MID] > n) R = MID;
        elif(arr[MID] <= n) L = MID;
        // else{
        //     cout << MID;
        //     flag = false;
        //     break;
        // }
    }

    if(flag) cout << L;
}
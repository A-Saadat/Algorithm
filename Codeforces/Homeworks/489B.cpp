#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=0;i<n;i++) 
typedef long long int intl; 
typedef vector<int> vci;
typedef pair<int,int> pii; 
intl boyLen, boys[def];
intl girlLen, girls[def];
intl cnt;

intl solve(intl minArr[], intl maxArr[], intl maxLen, intl minLen);

int main (void)
{
    cin >> boyLen;
    forn(i,boyLen) cin >> boys[i];
    sort(boys, boys + boyLen);

    cin >> girlLen;
    forn(i,girlLen) cin >> girls[i];
    sort(girls, girls + girlLen);

    if(girlLen >= boyLen)
        cout << solve(boys, girls, girlLen, boyLen);
    else if(girlLen < boyLen)
        cout << solve(girls, boys, boyLen, girlLen);

}

intl solve(intl minArr[], intl maxArr[], intl maxLen, intl minLen){
    forn(i,minLen){
        forn(j,maxLen){
            if((maxArr[j] == (minArr[i] - 1)) or (maxArr[j] == (minArr[i] + 1)) or (maxArr[j] == minArr[i])){
                maxArr[j] = 999;
                minArr[i] = 999;
                cnt++;
                break;
            }
        }
    }

    return cnt;
}
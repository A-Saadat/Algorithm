#include <bits/stdc++.h> 
using namespace std; 

#define def 10000 
#define forn(i,n) for(int i=0;i<n;i++) 
#define pb push_back 
typedef long long int intl; 
typedef vector<int> vci;
typedef pair<int,int> pii; 

intl len, n; 
string str;
vci ans;
intl solve(intl start, intl end, char letter);

int main (void)
{
    cin >> n;

    while(n--){
        cin >> len >> str;
        ans.pb(solve(0, len - 1, 'a'));
    }

    forn(i,ans.size()) cout << ans[i] << endl;
}

intl solve(intl start, intl end, char letter){
    if(start == end)
        return str[start] != letter;
    
    intl mid = (start + end) / 2;
    intl firstHalf = 0, SecondHalf = 0;

    for(intl i = start; i <= mid; i++){
        if(str[i] != letter)
            firstHalf++;
    }
    for(intl i = mid + 1; i <= end; i++){
        if(str[i] != letter)
            SecondHalf++;
    }

    SecondHalf += solve(start, mid, letter + 1);
    firstHalf += solve(mid + 1, end, letter + 1);

    return min(SecondHalf, firstHalf);
}
#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 1000
#define forN(i,n) for(int i = 0; i < n; i++)

int main (void)
{
    intl n;
    cin >> n;
    
    intl a[def], resArrr = 0;
    forN(i,n){
        cin >> a[i];
        resArrr += a[i];
    }

    sort(a, a + n, greater<int>());

    intl x = 0, y = 0, cnt = 0;
    forN(i, n){
        x += a[i];
        y = resArrr - x;
        cnt++;

        if(x > y)
            break;
    }

    cout << cnt;
}
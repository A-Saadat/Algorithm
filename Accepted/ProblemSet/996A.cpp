#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 

int main (void)
{
    intl n;
    cin >> n;

    intl nums[] = {1, 5, 10, 20, 100}, ans = 0;
    for(intl i = 4; i >= 0; i--){
        if(n >= nums[i]){
            ans += n / nums[i];
            n %= nums[i];
        }
    }

    cout << ans;
}
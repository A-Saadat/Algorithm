#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    intl x, min = 1000000, max = 9999999, a[def], sum = 0;
    
    for(int i = min; i < max; i++){
        x = i;
        for(int j = 0; j < 7; j++){
            a[j] = x % 10;
            x /= 10;
        }
        bool Check = true;
        sort(a, a + 7);
        for(int j = 0; j < 7; j++){
            if(a[j] != j + 1){
                Check = false;
                break;
            }
        }

        if(Check == false)
            continue;
        
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                Check = false;
                break;
            }
        }

        if(Check == true)
            sum += i;   
    }

    cout << sum;
    
}
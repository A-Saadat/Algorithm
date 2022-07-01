#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100000 

int main (void)
{

    char letters[def], mainArr[def];
    intl j = 0, cnt = 0;
    bool isUnique[def];
    
    for(intl i = 0; i < def; i++)
        isUnique[i] = true;
    
    for(intl i = 0; i >= 0; i++){
        cin >> mainArr[i];

        if(mainArr[i] == '}')
            break;
        else if(mainArr[i] >= 'a' and mainArr[i] <= 'z'){
            j++;
            letters[j] = mainArr[i];

            for(intl idx = j - 1; idx >= 0; idx--){
                if(letters[j] == letters[idx]){
                    isUnique[j] = false;
                    break;
                } 
            }

            if(isUnique[j])
                cnt++;

        }
        
    }

    cout << cnt;


}
#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 
#define fort(i, t) for(intl i = 0; i < t; i++)
#define def 50

int main (void)
{   
    intl n, t;
    cin >> n >> t;

    string queue;
    cin >> queue;

    while(t--){
        for(intl i = 0; i < n; i++){
            if(queue[i] == 'B' and queue[i + 1] == 'G'){
                queue[i] = 'G';
                queue[i + 1] = 'B';
                ++i;
            }
        }
    }

    cout << queue;

    
}

#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100000

int main (void)
{
    intl n, t, b[def];
    cin >> n >> t;

    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    for (int i = 0; i < n; i++) // Sorting Array
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] >= b[j])
            {
                int tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }

    }
    
    intl sum = 0, cnt = 1;
    for(int i = 0; i < n; i++){ // adding arr togther and check the condition of the question
        sum += b[i]; // 1, 1, 2, 3, 3
        // cout << sum << " " << "count: " << cnt << ";";
        if (sum < t)
            cnt++;
        else if(sum == t){
            break;
        }
        else if(sum > t){
            cnt--;
            break;
        }
    }

    cout << cnt;


}

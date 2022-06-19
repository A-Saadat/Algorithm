#include <bits/stdc++.h> 

using namespace std; 

#define intl long long int 

int main (void)
{
    string players;
    cin >> players;

    bool isDanger = false;
    intl cnt = 1;
    for(intl i = 0; i < players.size() - 1; i++){
        if(players[i] == players[i + 1])
            cnt++;
        else
            cnt = 1;

        // cout << cnt << ' ';
        if(cnt == 7){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
    #include <bits/stdc++.h>
     
    using namespace std; 
     
    #define intl long long int 
    #define def 10000
     
     
    int main (void)
    {
     
        intl n, a[def], ch[def], bi[def], ba[def];
     
        cin >> n;
     
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
     
        for (int i = 1; i <= n; i++)
        {
            ch[i] = a[3 * i - 2];
        }
     
        for (int i = 1; i < n; i++)
        {
            bi[i] = a[3 * i - 1];
        }
     
        for (int i = 1; i < n; i++)
        {
                ba[i] = a[3 * i];
        }

        intl ans1 = 0, ans2 = 0, ans3 = 0, tmp = 0;

        for(int i = 1; i < 100; i++)
        {
            tmp = ch[i];
            ans1 += tmp;
            tmp = 0;
        }

        for(int i = 1; i < 100; i++)
        {
            tmp = bi[i];
            ans2 += tmp;
            tmp = 0;
        }

        for(int i = 1; i < 100; i++)
        {
            tmp = ba[i];
            ans3 += tmp;
            tmp = 0;
        }

        if (ans1 > ans2 && ans1 > ans3)
        {
            cout << "chest";
        }
        else if (ans2 > ans1 && ans2 > ans3)
        {
            cout << "biceps";       
        }
        else if (ans3 > ans1 && ans3 > ans2)
        {
            cout << "back";
        }


        return 0;
    }
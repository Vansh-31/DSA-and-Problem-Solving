#include <bits/stdc++.h> 
using namespace std;
int frogJump(int n, vector<int> &v)

{
    int f = 0;

    int s = abs(v[1] - v[0]);

    if(n <= 1)

        return 0;

    if(n == 2)

        return s;

    for(int i = 2; i < n; ++i)

    {

        int val1 = abs(v[i] - v[i - 1]) + s;

        int val2 = abs(v[i] - v[i - 2]) + f;

        int curr = min(val1, val2);

        f = s;

        s = curr;

    }

    return s;

}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1e9 + 7
#define PI 3.14
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int Petrol = 0;
    int start = 0;
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        if (gas[i] + Petrol >= cost[i])
        {
            Petrol += gas[i] - cost[i];
        }
        else
        {
            deficit += gas[i] + Petrol - cost[i];
            start = i + 1;
            Petrol = 0;
        }
    }
    if (Petrol + deficit >= 0)
    {
        return start;
    }
    return -1;
}
int main()
{

    return 0;
}
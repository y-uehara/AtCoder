#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long int> V(N);
    long long int total = 0;

    for(auto &v : V)
    {
        cin >> v;
        total += v;
    }
    
    long long int answer = 0;

    sort(V.begin(), V.end());

    for(int i = 0; i < N; i++)
    {
        total -= V[i];
        answer += total - (N-i-1) * V[i];
    }

    // for(int i = 0; i < N; i++)
    //     for(int j = i+1; j < N; j++)
    //         answer += abs(V[i] - V[j]);

    cout << answer << endl;
    return 0;
}
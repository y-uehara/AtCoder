#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, tmp;
    int Alice = 0, Bob = 0;
    cin >> N;
    vector<int> v = {};

    for(int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());

    while(true)
    {
        Alice += v.back();
        v.pop_back();
        if(v.empty()) break;
        Bob += v.back();
        v.pop_back();
        if(v.empty()) break;
    }

    cout << (Alice - Bob) << endl;

    return 0;
}
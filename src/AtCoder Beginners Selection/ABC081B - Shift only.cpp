#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, tmp, result = 0;
    vector<int> v = {};
    bool allEven;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);     
    }

    while(true)
    {
        for(int i = 0; i < N; i++)
        {
            if(v[i] % 2 == 0)
            {
                v[i] = v[i] / 2;
            }
            else
            {
                cout << result;
                return 0;
            }
        }
      
        result++;        
    }

    return 0;
}
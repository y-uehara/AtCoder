#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct City
{
    long long int A;
    long long int B;

    long long int score;
};

int main()
{
    int N;
    cin >> N;
    auto cities = vector<City>(N);

    long long int target = 0;

    for(auto& c : cities)
    {
        cin >> c.A >> c.B;
        c.score = c.A * 2 + c.B;

        target += c.A;
    }

    long long int A = 0;
    long long int B = 0;
    for(auto& c : cities)
    {
        A += c.A;
        B += c.B;
    }
    
    sort(cities.begin(), cities.end(), [](auto l, auto r){ return l.score > r.score; });

    // //debug
    // for(auto c : cities)
    //     cout << "city " << "A: " << c.A << " B: " << c.B << " Score: " << c.score << endl;

    int ret = 0;
    for(int i = 0; i < N; i++)
    {
        if(target < 0)
            break;

        target -= cities[i].score;

        ret++;
    }

    cout << ret << endl;
    return 0;
}
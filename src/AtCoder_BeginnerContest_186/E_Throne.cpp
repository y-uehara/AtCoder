#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct Throne
{
    long long int N; // num of seat
    long long int T; // pos of Takahashi
    long long int K; // step
    unordered_set<long long int> History;
};

bool isThrone(Throne &Th)
{
    return Th.T == 0;
}

void move(Throne &Th)
{
    Th.T = Th.T + Th.K;
    if(Th.T >= Th.N)
    {
        Th.T = Th.T % Th.N;
        Th.History.insert(Th.T);
    }
}


int main()
{
    int T;
    cin >> T;

    vector<Throne> Th(T);
    for(int i = 0; i < T; i++)
    {
        cin >> Th[i].N >> Th[i].T >> Th[i].K;
        Th[i].History.clear();
    }

    long long int ret = 0;
    for(int i = 0; i < T; i++)
    {
        //cout << "TestCase " << i << endl;
        ret = 0;
        while(!isThrone(Th[i]))
        {
            //cout << "Step: " << ret << endl;
            if(Th[i].History.find(Th[i].K) != Th[i].History.end())
            {
                ret = -1;
                break;
            }
            move(Th[i]);
            ret++;
        }
        cout << ret << endl;
    }

    return 0;
}
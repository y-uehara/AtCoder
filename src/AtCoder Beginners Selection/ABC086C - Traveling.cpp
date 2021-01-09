#include <iostream>
#include <vector>

using namespace std;

bool canMove(int dt, int dx, int dy)
{
    return dt >= (dx + dy) && (dt - (dx + dy)) % 2 == 0;
}


int main()
{
    int N, tmp;
    vector<int> t = {};
    vector<int> x = {};
    vector<int> y = {};

    t.push_back(0);
    x.push_back(0);
    y.push_back(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> tmp;
        t.push_back(tmp);
        cin >> tmp;
        x.push_back(tmp);
        cin >> tmp;
        y.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        if(!canMove(t[i+1] - t[i], abs(x[i+1] - x[i]), abs(y[i+1] - y[i])))
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
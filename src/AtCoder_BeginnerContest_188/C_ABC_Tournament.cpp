#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int players = pow(2, N);
    auto A = vector<pair<int, int>>(players);
    auto B = vector<pair<int, int>>();

    for(int i = 0; i < players; i++)
    {
        cin >> A[i].first;
        A[i].second = i + 1;
    }

    while(A.size() > 2)
    {
        for(int i = 0; i < A.size() / 2; i++)
        {
            //*dbg*/ cout << A[2*i].second << " vs " << A[2*i+1].second << endl;
            if(A[2*i].first < A[2*i+1].first)
            {
                //*dbg*/ cout << A[2*i+1].second << "wins" << endl;
                B.push_back(A[2*i+1]);
            }
            else
            {
                //*dbg*/ cout << A[2*i].second << "wins" << endl;
                B.push_back(A[2*i]);
            }
        }
        A.clear();
        A.swap(B);
    }

    //*dbg*/ cout << "Final " << A[0].second << " vs " << A[1].second << endl;

    if(A[0].first < A[1].first)
        cout << A[0].second << endl;
    else
        cout << A[1].second << endl;

    return 0;
}
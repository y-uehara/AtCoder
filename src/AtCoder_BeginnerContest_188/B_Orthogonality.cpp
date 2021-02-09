#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    int acc = 0;

    for (auto &v : A)
    {
        cin >> v;
    }
    for (auto &v : B)
    {
        cin >> v;
    }

    for (int i = 0; i < N; i++)
    {
        acc += A[i] * B[i];
    }

    if (acc == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;   

    return 0;
}
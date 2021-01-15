#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    auto A = vector<int>(N);
    auto B = vector<int>(N);

    int acc = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
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
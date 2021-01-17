#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int S(string S)
{
    return (S[0] - '0') + (S[1] - '0') + (S[2] - '0');
}


int main()
{
    string A, B;

    cin >> A >> B;

    cout << max(S(A), S(B)) << endl;

    return 0;
}
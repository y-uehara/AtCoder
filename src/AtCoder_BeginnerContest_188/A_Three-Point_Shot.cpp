#include <iostream>

using namespace std;

int main()
{
    int X, Y, tmp;

    cin >> X >> Y;

    if (Y > X)
    {
        tmp = Y;
        Y = X;
        X = tmp;
    }

    if (X < Y+3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

bool solve(int n, int base)
{
    //cout << "solve " << n << " by " << base << endl;
    bool ret = true;

    do
    {
        ret = ret && (7 != n % base);
        n = n / base;
    } while (n != 0);
    
    //cout << ret << endl;
    return ret;
}



int main()
{
    int N;
    cin >> N;

    int ret = 0;
    for(int i = 1; i <= N; i++)
    {
        if(solve(i, 10) && solve(i, 8))
            ret++;
    }

    cout << ret << endl;
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

auto memo = unordered_map<long long int, long long int>();

long long int calcHands(long long int X, long long int Y)
{
    //*dbg*/ cout << "call calcHands(" << X << " " << Y << ")" << endl;
    auto m = memo.find(Y);
    if(m != memo.end())
    {
        //*dbg*/ cout << "calcHands(" << X << " " << Y << ") returns " << m->second << " from memo" << endl;
        return m->second;
    }

    long long int ret;
 
    if(1 == Y)
    {
        ret = abs(X-Y);
    }
    else if(0 == Y % 2)
    {
        ret = min( abs(X-Y), calcHands(X, Y/2)+1 );
    }
    else
    {
        ret = min( { abs(X-Y), calcHands(X, (Y+1)/2)+2, calcHands(X, (Y-1)/2)+2 } );
    }
    
    //*dbg*/ cout << "calcHands(" << X << " " << Y << ") returns " << ret << endl;
    memo[Y] = ret;
    return ret;
}

int main()
{
    long long int X, Y;

    cin >> X >> Y;

    cout << calcHands(X, Y) << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int N, A, B;
    int sum, result = 0;
    cin >> N >> A >> B;

    for(int i = 1; i <= N; i++)
    {
        sum = i / 10000 + (i % 10000) / 1000 + (i % 1000) / 100 + (i % 100) / 10 + i % 10;
        if(sum >= A && sum <= B)
            result += i;
    }

    cout << result;

    return 0;
}
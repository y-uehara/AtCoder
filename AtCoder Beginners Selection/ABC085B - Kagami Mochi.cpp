#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int N, tmp;
    unordered_set<int> s = {};
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }

    cout << s.size() << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int result = 0;
    string s;

    cin >> s;

    for(int i = 0; i < 3; i++)
    {
        if(s[i] == '1')
            result++;
    }
    
    cout << result;

    return 0;
}
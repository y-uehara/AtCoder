#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    string s1 = "dream";
    string s2 = "dreamer";
    string s3 = "erase";
    string s4 = "eraser";

    while(true)
    {
        if(S.empty())
        {
            cout << "YES";
            break;
        }
        else if(S.length() >= s1.length() && 0 == s1.compare(S.substr(S.length() - s1.length())))
        {
            S.erase(S.length() - s1.length(), s1.length());
        }
        else if(S.length() >= s2.length() && 0 == s2.compare(S.substr(S.length() - s2.length())))
        {
            S.erase(S.length() - s2.length(), s2.length());
        }
        else if(S.length() >= s3.length() && 0 == s3.compare(S.substr(S.length() - s3.length())))
        {
            S.erase(S.length() - s3.length(), s3.length());
        }
        else if(S.length() >= s4.length() && 0 == s4.compare(S.substr(S.length() - s4.length())))
        {
            S.erase(S.length() - s4.length(), s4.length());
        }
        else
        {
            cout << "NO";
            break;
        }
    }
    return 0;
}
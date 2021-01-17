#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    auto s = vector<string>(N);

    for(auto& elm_s : s)
    {
        cin >> elm_s;
        reverse(elm_s.begin(), elm_s.end());
    }

    sort(s.begin(), s.end());

    // //debug
    // cout << "dump" << endl;
    // for(auto s_elm : s)
    //     cout << s_elm << endl;

    bool satisfiable = true;
    string ret;
    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i].size() +1 == s[i+1].size() &&
           0 == s[i].compare(s[i+1].substr(0, s[i].size())) &&
           s[i+1][s[i+1].size() -1] == '!')
        {
            //*dbg*/ cout << s[i] << " and " << s[i+1] << endl;
            satisfiable = false;
            ret = s[i];
            reverse(ret.begin(), ret.end());
            break;
        }
    }

    if(satisfiable)
        cout << "satisfiable" << endl;
    else
        cout << ret << endl;
}
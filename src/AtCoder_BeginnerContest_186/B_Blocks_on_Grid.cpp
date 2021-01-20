#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    
    vector<int> G(H * W);

    for(int i = 0; i < H*W; i++)
        cin >> G[i];

    sort(G.begin(), G.end());

    int ret = 0;
    for(auto& g : G)
        ret += g - G[0];

    cout << ret << endl;

    return 0;
}
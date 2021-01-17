#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool calcSlope(Point p1, Point p2)
{
    //*dbg*/ cout << "calcSlope (" << p1.x << "," << p1.y << ") (" << p2.x << "," << p2.y << ")" << endl;
    int dx = abs(p1.x - p2.x);
    int dy = abs(p1.y - p2.y);

    //*dbg*/ cout << "slope: " << (dx==0 ? "NaN" : to_string(double(dy) / double(dx))) << " result:" << (dx >= dy) << endl;
    return dx >= dy;
}

int main()
{
    int N;
    cin >> N;

    auto p = vector<Point>(N);
    for(auto &p_elm : p)
    {
        cin >> p_elm.x >> p_elm.y;
    }

    int result = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(calcSlope(p[i], p[j]))
                result++;
        }
    }

    cout << result << endl;
    return 0;
}
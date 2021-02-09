#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event
{
    long long int date;
    long long int price;
};

int main()
{
    long long int N, C;
    cin >> N >> C;

    long long int dStart, dEnd, price;
    vector<Event> events;

    for(long long int i = 0; i < N; i++)
    {
        cin >> dStart >> dEnd >> price;
        events.push_back({dStart, price});
        events.push_back({dEnd + 1, -1 * price});
    }

    sort(events.begin(), events.end(), [](auto l, auto r) { return (l.date < r.date); });

    long long int currentDay = 0;
    long long int dayPrice = 0;
    long long int totalPrice = 0;

    for(auto e : events)
    {
        if(e.date != currentDay)
        {
            totalPrice += min(dayPrice, C) * (e.date - currentDay);
            currentDay = e.date;
        }
        dayPrice += e.price;        
    }

    cout << totalPrice << endl;

    return 0;
}
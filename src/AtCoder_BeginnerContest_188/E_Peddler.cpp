#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct City
{
    long long int price;
    vector<struct City *> next;

    bool calculated;
    long long int maxPrice; // max price in all cities from here
};

long long int calcMaxPrice(struct City *city)
{
    if(city->calculated)
        return city->maxPrice;

    if(city->next.empty())
        return city->price;

    long long int maxPrice = calcMaxPrice(city->next[0]);

    for(unsigned int i = 1; i < city->next.size(); i++)
    {
        maxPrice = max(maxPrice, calcMaxPrice(city->next[i]) );
    }

    city->calculated = true;
    city->maxPrice = maxPrice;
    return maxPrice;
}

int main()
{
    long long int N, M;

    cin >> N >> M;

    auto cities = vector<struct City>(N);

    for(int i = 0; i < N; i++)
    {
        long long int price;
        cin >> price;
        cities[i].price = price;
        cities[i].calculated = false;
    }
    for(int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        cities[from-1].next.push_back( &cities[to-1] );
    }

    long long int maxBenefit = 0;
    bool first = true; 

    for(int i = 0; i < N; i++)
    {
        if(!cities[i].next.empty())
        {
            if(first)
            {
                maxBenefit = calcMaxPrice( &cities[i] ) - cities[i].price;
                first = false;
            }
            else
            {
                maxBenefit = max(maxBenefit, calcMaxPrice( &cities[i] ) - cities[i].price);
            }
        }
    }

    cout << maxBenefit << endl;

    return 0;
}
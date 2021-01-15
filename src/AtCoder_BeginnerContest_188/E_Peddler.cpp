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

bool isEnd(struct City *city);
long long int calcMaxPriceInNexts(struct City *city);
long long int calcMaxPrice(struct City *city);
long long int calcMaxBenefit(struct City *city);

bool isEnd(struct City *city)
{
    return city->next.empty();
}

long long int calcMaxPriceInNexts(struct City *city)
{
    auto p = vector<long long int>();

    for(unsigned int i = 0; i < city->next.size(); i++)
        p.push_back(calcMaxPrice(city->next[i]));

    long long int maxPrice = *(max_element(p.begin(), p.end()));

    return maxPrice;
}

long long int calcMaxPrice(struct City *city)
{
    if(isEnd(city))
        return city->price;

    if(city->calculated)
        return city->maxPrice;

    long long int maxPrice = max(calcMaxPriceInNexts(city), city->price);

    city->calculated = true;
    city->maxPrice = maxPrice;
    return maxPrice;
}

long long int calcMaxBenefit(struct City *city)
{

    long long int maxPrice = calcMaxPriceInNexts(city);

    return maxPrice - city->price;
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

    auto p = vector<long long int>();

    for(int i = 0; i < N; i++)
    {
        if(!isEnd(&cities[i]))
            p.push_back(calcMaxBenefit(&cities[i]));
    }

    long long int maxBenefit = *max_element(p.begin(), p.end());

    cout << maxBenefit << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

struct Node
{
    bitset<18> next;
};

bool isPerfect(vector<Node> &nodes, unsigned long member)
{
    bitset<18> bs(member);

    bool ret;

    if(bs.count() == 1)
    {
        ret = true;
    }
    else
    {
        ret = true;
        for(unsigned int i = 0; i < 18; i++)
        {
            if(bs.test(i))
            {
                bitset<18> next = bs;
                next.reset(i);
                if((nodes[i].next & next) != next)
                    ret = false;
            }
        }
    }
    return ret;
}

int solve(vector<Node> &nodes, unsigned long member, vector<int> &resultMemo)
{
    if(resultMemo[member] != -1)
        return resultMemo[member];

    if(isPerfect(nodes, member))
    {
        resultMemo[member] = 1;
        return 1;
    }

    int minResult = nodes.size();

    //cout << "try to count " << bs << endl;
    unsigned long i = member;
    int result;
    do
    {
        if(member != i && (member & i) == i && i != 0 )
        {
            result = solve(nodes, i, resultMemo) + solve(nodes, (member & ~i), resultMemo);

            if(minResult > result)
                minResult = result;
        }
        i = (i - 1) & member;
    } while(i != member);

    resultMemo[member] = minResult;
    return minResult;
}



int main()
{
    int N, M;
    cin >> N >> M;
    vector<Node> nodes(N);
    vector<int>  resultMemo(pow(2, N), -1);

    for(int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        nodes[A].next.set(B);
        nodes[B].next.set(A);
    }


    cout << solve(nodes, pow(2, N)-1, resultMemo) << endl;
    return 0;
}
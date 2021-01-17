#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Node
{
    int id;
    long long int c;
    long long int diff;
    int depth;
    vector<Node *> next;
};

void travel(Node *curr, long long int currentDiff, Node *from = nullptr)
{
    currentDiff += curr->diff;
    curr->c = currentDiff;

    for(auto &n : curr->next)
    {
        if(n != from)
            travel(n, currentDiff, curr);
    }
}

void setDepth(Node *curr, Node *from = nullptr)
{
    if(from == nullptr)
        curr->depth = 0;
    else
        curr->depth = from->depth + 1;

    for(auto &n : curr->next)
    {
        if(n != from)
            setDepth(n, curr);
    }
}

int main()
{
    int N, Q;
    cin >> N;
    
    auto nodes = vector<Node>(N);
    auto edges = vector<pair<int,int>>(N-1);

    int id = 1;
    for(auto& n : nodes)
    {
        n.id = id++;
        n.next = vector<Node *>();
        n.diff = 0;
        n.c = 0;
    }

    for(auto& e : edges)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        e.first = a;
        e.second = b;
        nodes[a].next.push_back(&nodes[b]);
        nodes[b].next.push_back(&nodes[a]);
    }

    // set depth, nodes[0] is root
    Node *root = &nodes[0];
    setDepth(root);

    cin >> Q;

    for(int i = 0; i < Q; i++)
    {
        int t, e, x;
        int start, goal;
        cin >> t >> e >> x;

        e--;
        Node *a = &(nodes[edges[e].first]);
        Node *b = &(nodes[edges[e].second]);

        if(t == 2)
            swap(a, b);

        if( a->depth >= b->depth )
        {
            a->diff += x;
        }
        else
        {
            root->diff += x;
            b->diff -= x;
        }
    }

    long long int currentDiff = 0;
    travel(root, currentDiff);

    for(auto n : nodes)
    {
        cout << n.c << endl;
    }
    return 0;
}

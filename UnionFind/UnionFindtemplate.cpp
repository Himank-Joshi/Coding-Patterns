#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
    vector<int> rank;
    vector<int> parent;
    int size;
    UnionFind(int sz)
    {
        size = sz;

        for (int i = 0; i <= size; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int findParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void Union(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu > pv)
        {
            parent[v] = parent[u];
            rank[u]++;
        }
        else if (pu < pv)
        {
            parent[u] = parent[v];
            rank[v]++;
        }
        else
        {
            parent[v] = parent[u];
        }
    }
};
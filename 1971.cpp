#include <iostream>
#include <vector>
using namespace std;

// using dfs
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> al(n+1);
    vector<bool> seen(n+1, false);
    for (auto &e : edges) { al[e[0]].push_back(e[1]); al[e[1]].push_back(e[0]); }

    return dfs(al, source, destination, seen);
}

bool dfs(vector<vector<int>> &al, int source, int destination, vector<bool> &seen) {
    if (source == destination) return true;
    seen[source] = true;

    for (auto &v : al[source]) {
        if (!seen[v] && dfs(al, v, destination, seen)) return true;
    }

    return false;
}



// but actually, we only need to know if source and destination are in the same component, so we may use union find
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    for (auto &e : edges) unionize(e[0], e[1], parent);

    // we must never rely on the parent vector, so we have to find parent first
    return findParent(source, parent) == findParent(destination, parent);
}

// we only union the top level parents
void unionize(int u, int v, vector<int> &parent) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    parent[pu] = pv;
}

// hence, we have to dynamically change the parent of a child whose parent recently changed as we search through
int findParent(int u, vector<int> &parent) {
    return parent[u] == u ? u : (parent[u] = findParent(parent[u], parent));
}

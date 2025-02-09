
#include <bits/stdc++.h>
using namespace std;

// Maximum number of servers (vertices)
const int MAXN = 100005;

// Global variables
int n, m;

// We store for each cable (edge) its endpoints (1-indexed)
int uEdge[MAXN], vEdge[MAXN];

// For Tarjan’s algorithm we need dfn, low arrays.
int dfn[MAXN], low[MAXN], timer;
int parent[MAXN];

// We will use an “adjacency list” that stores (neighbor, edge id) pairs.
struct Edge {
    int to, id;
};

vector<Edge> adj[MAXN];

// isBridge[i] will be true if cable (edge) i is a bridge.
bool isBridge[MAXN];

//-----------------------------------------------------
// Tarjan DFS – find bridges.
void dfs(int u, int p_edge){
    dfn[u] = low[u] = ++timer;
    for(auto &edge : adj[u]){
        int v = edge.to;
        int id = edge.id;
        if(!dfn[v]){
            parent[v] = u;
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                // edge u-v (with id) is a bridge.
                isBridge[id] = true;
            }
        } else if(id != p_edge){
            low[u] = min(low[u], dfn[v]);
        }
    }
}

//-----------------------------------------------------
// Now “contract” non–bridge edges into one “block.”
int comp[MAXN]; // comp[u] is the id of the block containing vertex u.

void dfsComp(int u, int cid){
    comp[u] = cid;
    for(auto &edge : adj[u]){
        int v = edge.to, id = edge.id;
        // Only travel using non–bridge edges.
        if(comp[v] == 0 && !isBridge[id]){
            dfsComp(v, cid);
        }
    }
}

//-----------------------------------------------------
// Main function
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> uEdge[i] >> vEdge[i];
        // Build the undirected graph – add both directions.
        adj[uEdge[i]].push_back({vEdge[i], i});
        adj[vEdge[i]].push_back({uEdge[i], i});
    }

    // Run Tarjan DFS to compute dfn and low values.
    timer = 0;
    for (int i = 1; i <= n; i++){
        if(!dfn[i])
            dfs(i, -1);
    }

    // Now, contract the graph by doing a DFS that goes only along non–bridge edges.
    int cid = 0;
    for (int i = 1; i <= n; i++){
        if(comp[i] == 0){
            cid++;
            dfsComp(i, cid);
        }
    }
    // Now cid = number of blocks (2–edge–connected components)

    // For each block we choose a representative vertex (here, the smallest–numbered vertex in that block)
    vector<int> rep(cid+1, 0);
    for (int i = 1; i <= n; i++){
        int c = comp[i];
        if(rep[c] == 0 || i < rep[c])
            rep[c] = i;
    }

    // Next, for every block we want to “find” a redundant cable – one that is not a bridge.
    // (Because the block has a cycle, at least one such cable exists.)
    vector<int> spareCable(cid+1, 0); // spareCable[c] = id of a non–bridge cable inside block c
    vector<int> spareVertex(cid+1, 0); // one endpoint (in that block) for that cable
    for (int i = 1; i <= m; i++){
        if(!isBridge[i]){
            // (For non–bridge edges, both endpoints lie in the same block.)
            int c = comp[uEdge[i]];
            if(spareCable[c] == 0){
                spareCable[c] = i;
                spareVertex[c] = uEdge[i]; // choose the u–endpoint arbitrarily.
            }
        }
    }

    // We now “connect” the blocks.
    // We choose the block that contains vertex 1 as our base.
    int base = comp[1];
    // (It would be best if the base block has a spare cable – in our “good” input it does.)
    if(spareCable[base] == 0){
        // (If none of the blocks has a spare cable, our method won’t work; we then output -1.)
        cout << -1 << "\n";
        return 0;
    }

    // For every block other than the base, we “reassign” one spare cable from that block so that
    // one of its endpoints is re–connected to rep[base]. (Since the cable is redundant, this doesn’t
    // disconnect its block; but it does “bridge” the block to the base block.)
    vector<tuple<int,int,int>> ops; // each operation: (cable id, original endpoint, new endpoint)
    for (int c = 1; c <= cid; c++){
        if(c==base) continue;
        if(spareCable[c] == 0){
            // This should not happen in a "good" input.
            cout << -1 << "\n";
            return 0;
        }
        int cableId = spareCable[c];
        int origVertex = spareVertex[c]; // from block c
        int newVertex = rep[base];         // from the base block
        ops.push_back({cableId, origVertex, newVertex});
    }

    // Our method uses exactly (cid – 1) operations.
    cout << ops.size() << "\n";
    for(auto &op : ops){
        int id, orig, nw;
        tie(id, orig, nw) = op;
        cout << id << " " << orig << " " << nw << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

//Max Flow Solver

// the maximum number of vertices + 1
#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// cost per unit of flow matrix (fill this up)
int cost[NN][NN] = {0};

// flow network and adjacency list
int fnet[NN][NN], adj[NN][NN], deg[NN];

// Dijkstra's predecessor, depth and priority queue
int par[NN], d[NN], q[NN], inq[NN], qs;

// Labelling function
int pi[NN];

#define Inf (INT_MAX/2)
#define BUBL { \
t = q[i]; q[i] = q[j]; q[j] = t; \
t = inq[q[i]]; inq[q[i]] = inq[q[j]]; inq[q[j]] = t; }

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t )
{
  fill(d, d+NN, Inf);
  fill(par, par+NN, -1);
  fill(inq, inq+NN, -1);

  d[s] = qs = 0;
  inq[q[qs++] = s] = 0;
  par[s] = n;

  while (qs) {
    // get the minimum from q and bubble down
    int u = q[0];
    inq[u] = -1;
    q[0] = q[--qs];
    if( qs ) inq[q[0]] = 0;
    for (int i = 0, j = 2*i + 1, t; j < qs; i = j, j = 2*i + 1) {
      if (j + 1 < qs && d[q[j + 1]] < d[q[j]]) j++;
      if (d[q[j]] >= d[q[i]]) break;
      BUBL;
    }

    // relax edge (u,i) or (i,u) for all i;
    for (int k = 0, v = adj[u][k]; k < deg[u]; v = adj[u][++k]) {
      // try undoing edge v->u
      if (fnet[v][u] && d[v] > Pot(u,v) - cost[v][u])
        d[v] = Pot(u,v) - cost[v][par[v] = u];

      // try using edge u->v
      if (fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v])
        d[v] = Pot(u,v) + cost[par[v] = u][v];

      if (par[v] == u) {
        // bubble up or decrease key
        if( inq[v] < 0 ) { inq[q[qs] = v] = qs; qs++; }
        for( int i = inq[v], j = ( i - 1 )/2, t;
            d[q[i]] < d[q[j]]; i = j, j = ( i - 1 )/2 )
          BUBL;
      }
    }
  }

  for( int i = 0; i < n; i++ ) if( pi[i] < Inf ) pi[i] += d[i];

  return par[t] >= 0;
}

int mcmf( int n, int s, int t, int &fcost )
{
  // build the adjacency list
  fill(deg, deg+NN, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (cap[i][j] || cap[j][i]) adj[i][deg[i]++] = j;
  }
  for (int i = 0; i < NN; i++) {
    fill(fnet[i], fnet[i]+NN, 0);
  }
  fill(pi, pi+NN, 0);

  int flow = fcost = 0;

  // repeatedly, find a cheapest path from s to t
  while (dijkstra(n, s, t)) {
    // get the bottleneck capacity
    int bot = INT_MAX;
    for (int v = t, u = par[v]; v != s; u = par[v = u]) {
      bot = min(bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ));
    }

    // update the flow network
    for (int v = t, u = par[v]; v != s; u = par[v = u])
      if (fnet[v][u]) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
      else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }

    flow += bot;
  }

  return flow;
}

int main()  {
  int blocks;
  cin >> blocks;
  //Read in the data correctly
  for (int i = 1; i < blocks+1; i++) {
    int revenue, cost;
    cin >> revenue >> cost;
    cap[0][i] = revenue;
    cap[i][blocks+2] = cost;
    int blocking;
    cin >> blocking;
    for (int j = 0; j < blocking; j++) {
      int blocked;
      cin >> blocked;
      cap[blocked][i] = Inf;
    }
  }

  int fcost;
  mcmf(blocks+3, 0, blocks+2, fcost);
  //Calculate the answer
  int answer = 0;
  for (int i = 1; i < blocks+1; i++) {
    answer -= fnet[0][i] - fnet[i][0];
    answer += cap[0][i];
  }
  cout << answer << endl;
  return 0;
}

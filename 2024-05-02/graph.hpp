#ifndef __LIB_GRAPH_HPP
#define __LIB_GRAPH_HPP

#include <random>
#include <vector>
#include <ctime>
#include <algorithm>
#include <set>
#include <iostream>
#include <chrono>

using namespace std;

#ifndef _rep
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#endif
#ifndef rep
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#endif

namespace graph_rnd {

mt19937 _rnd(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

pair <int, int> arr[1000005];

} // namespace graph_rnd

vector <pair <int, int> > tree(int n, bool chain, bool flower, int tn){
	//n -> 节点数 chain -> 链 flower -> 菊花 tn -> 树高
	vector <pair <int, int> > edges;
	if (flower) {
		rep (i, 2, n) edges.push_back(make_pair(1, i));
	}
	else if (!chain) {
		rep (i, 1, tn) graph_rnd::arr[i].first = i, graph_rnd::arr[i].second = i + 1;
		rep (i, tn + 1, n - 1) graph_rnd::arr[i].first = i + 1, graph_rnd::arr[i].second = graph_rnd::rnd(1, i);
		rep (i, 1, n - 1) {
			edges.push_back(graph_rnd::arr[i]);
		}
		shuffle(edges.begin(), edges.end(), graph_rnd::_rnd);
	}
	else {
		rep (i, 1, n - 1) edges.push_back({i, i + 1});
	}
	return edges;
}

vector <pair <int, int> > DAG(int n, int m) {
	vector <pair <int, int> > edges;
	if (m < n - 1) return edges;
	edges = tree(n, 0, 0, 0);
	set <pair <int, int> > uni;
	for (auto v : edges) uni.insert(make_pair(min(v.first, v.second), max(v.first, v.second)));
	while ((int) uni.size() < m) {
		int u = graph_rnd::rnd(1, n);
		int v = graph_rnd::rnd(1, n);
		if (u == v) continue;
		if (u > v) swap(u, v);
		uni.insert({u, v});
	}
	edges.clear();
	for (auto v : uni) edges.push_back(v);
	shuffle(edges.begin(), edges.end(), graph_rnd::_rnd);
	return edges;
}

vector <pair <int, int> > graph_wcon_dir(int n, int m) {
	vector <pair <int, int> > edges;
	if (m < n - 1) return edges;
	edges = tree(n, 0, 0, 0);
	set <pair <int, int> > uni;
	for (auto v : edges) uni.insert(v);
	while ((int) uni.size() < m) {
		int u = graph_rnd::rnd(1, n);
		int v = graph_rnd::rnd(1, n);
		if (u == v) continue;
		uni.insert({u, v});
	}
	edges.clear();
	for (auto v : uni) edges.push_back(v);
	shuffle(edges.begin(), edges.end(), graph_rnd::_rnd);
	return edges;
}
#endif

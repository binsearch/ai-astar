#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;

#define INF 100000000
#define lim 1000


int openlist[lim];
int closedlist[lim];
int parent[lim];
int g[lim];
int h[lim];
int c[lim][lim];
int n;//number of nodes

int leastf(){
	int val;
	int node = -1;
	for(int i = 0; i < n; i++){
		if(openlist[i]){
			if(node == -1){
				val = h[i] + g[i];
				node = i;
			}
			else{
				if(val > h[i] + g[i]){
					val = h[i] + g[i];
					node = i;
				}
			} 
		}
	}
	return node;
}

void backtrackpath(int node){
	cout << "--" << node ;
	if(parent[node] == -1) return;
	backtrackpath(parent[node]);
	return;
}

int main(){
	
	
	memset(c, -1, sizeof c);
	
	
	cout << "enter the number of nodes: ";
	cin >> n;
	cout << endl;

	cout << "enter the cost of edges in the following form" << endl;
	cout << "node1 node2 cost" << endl;
	cout << "enter '-1' in the end" << endl;
	while(1){
		int n1, n2, cost;

		cin >> n1;
		if(n1 == -1) break;
		cin >> n2 >> cost;
		c[n1][n2] = cost;
		c[n2][n1] = cost; 
	}

	int start, target;
	cout << "enter the indices of start node and target node" << endl;
	cin >> start >> target;


	
	cout << "enter the value of heuristic for each node" << endl;
	for(int i = 0; i < n; i++){
		cout << "value of 'h' for node " << i << " : ";
		cin >> h[i];
		cout << endl;
	}

	
	memset(openlist, 0, sizeof openlist);
	memset(closedlist, 0, sizeof closedlist);
	memset(parent, -1, sizeof parent);

	openlist[start] = 1;
	g[start] = 0;

	while(1){
		int node;
		if((node = leastf()) == -1) break;
		openlist[node] = 0;
		closedlist[node] = 1;
		if(node == target){
			backtrackpath(target);
			break;
		}
		//if heuristic is monotone.
		for(int i = 0; i < n; i++){
			//updating for neighbours
			if(c[node][i] != -1){
				if(closedlist[i] == 0){
					int tent_gval = c[node][i] + g[node];
					if(openlist[i] == 0 || tent_gval < g[i]){
						openlist[i] = 1;
						g[i] = tent_gval;
						parent[i] = node;
					}
				}
			}
		}

	}
	cout << endl;
	return 0;

}
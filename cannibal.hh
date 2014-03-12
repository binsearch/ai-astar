#include <iostream>
using namespace std;
typedef long long int lli;
#define DEBUG 1
#define MONOTONE 4

class cannibal
{
	lli snode;




	public:
		cannibal(lli);
		lli start();
		int h(lli);
		std::vector<pair<lli, int> > get_neighs(lli);
		void print(lli);
		// lli gen_node(std::vector<vector<int> >);

	/* data */
};

void cannibal::print(lli node){
	cout << endl;
	int dir = node % 10;
	node = node / 10;
	int can = node % 10;
	node = node / 10;
	int mis = node % 10;

	if(dir){
		cout << "Boat is on the right bank\n";
	}
	else{
		cout << "Boat is on the left bank\n";
	}

	cout << "No. of Missionaries on the left bank: " << mis << endl;
	cout << "No. of Cannibals on the left bank: " << can << endl;  
	cout << endl;
}

cannibal::cannibal(lli start){
	snode = start;
} 

lli cannibal::start(){
	return snode;
} 

int cannibal::h(lli node){
	
	int dir = node % 10;
	node = node / 10;
	int can = node % 10;
	node = node / 10;
	int mis = node % 10;
	return MONOTONE*(can + mis - 1) ;
}


/*
int cannibal::h(lli node){
	return 0;
}
*/

std::vector<pair<lli, int> > cannibal::get_neighs(lli node){

	std::vector<pair<lli,int> > neighbours;
	int dir = node % 10;
	node = node / 10;
	int can = (1-dir)*(node % 10) + dir*(3- (node%10));
	node = node / 10;
	
	int mis = (1-dir)*(node % 10) + dir*(3- (node%10));

	int cost = 1;
	if(DEBUG){
		cout << "mis: " << mis << " can: " << can << " dir: " << dir << endl;
	}

	//one mis one can
	if(can >= 1 && mis >= 1){
		if(can == mis){
			if(DEBUG)
				cout << "one mis one can" << endl;
			lli neigh_node;
			neigh_node = (1-dir)*(mis -1) + dir*(4-mis);
			neigh_node = (neigh_node * 10) + (1-dir)*(can -1) + dir*(4-can);
			neigh_node = (neigh_node*10) + abs(dir-1);
			neighbours.push_back(pair<lli,int>(neigh_node, cost));
		}
	}

	//two mis
	if(mis >= 2){
		if(((mis-2 >= can) || ((mis-2) == 0)) && (5-mis >= 3-can)){
			if(DEBUG)
				cout << "two mis" << endl;
			lli neigh_node;
			neigh_node = (1-dir)*(mis - 2) + dir*(5 - mis) ;
			neigh_node = (neigh_node * 10) + (1-dir)*can + dir*(3-can);
			neigh_node = (neigh_node*10) + abs(dir-1);
			neighbours.push_back(pair<lli,int>(neigh_node, cost));			
		}
	}

	//two can
	if(can >= 2){
		if(((mis >= can-2) || (mis == 0)) && ( ((3-mis) == 0) || (3-mis >= 5-can))) {
			if(DEBUG)
				cout << "two cans" << endl;
			lli neigh_node;
			neigh_node = (1-dir)*mis + dir*(3-mis);
			neigh_node = (neigh_node * 10) + (1-dir)*(can-2) + dir * (5 - can);
			neigh_node = (neigh_node*10) + abs(dir-1);
			neighbours.push_back(pair<lli,int>(neigh_node, cost));
		}
	}

	//one mis
	if(mis >= 1){
		if(( ((mis-1) == 0) || (mis - 1 >= can)) && (4-mis >= 3-can)) {
			if(DEBUG)
				cout << "one mis" << endl;
			lli neigh_node;
			neigh_node = (1-dir)*(mis - 1) + dir*(4 - mis);
			neigh_node = (neigh_node * 10) + (1-dir)*can + dir*(3-can);
			neigh_node = (neigh_node*10) + abs(dir-1);
			neighbours.push_back(pair<lli,int>(neigh_node, cost));						
		}
	}

	//one can
	if(can >= 1){
		if(( (mis == 0) || (mis >= can - 1) ) && ( ((3-mis) == 0) || (3-mis >= 4-can)) ) {
			if(DEBUG)
				cout << "one can" << endl;
			lli neigh_node;
			neigh_node = (1-dir)*(mis) + dir*(3 - mis);
			neigh_node = (neigh_node * 10) + (1-dir)*(can - 1) + dir*(4-can);
			neigh_node = (neigh_node*10) + abs(dir-1);
			neighbours.push_back(pair<lli,int>(neigh_node, cost));						
		}
	}

	return neighbours;	
}	

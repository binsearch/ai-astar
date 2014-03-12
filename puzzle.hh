#include <iostream>
using namespace std;
typedef long long int lli;
#define MONOTONE 8

class puzzle
{
	lli snode;




	public:
		puzzle(lli);
		lli start();
		int h(lli);
		std::vector<pair<lli, int> > get_neighs(lli);
		void print(lli);
		lli gen_node(std::vector<vector<int> >);

	/* data */
};

puzzle::puzzle(lli start){
	snode = start;
} 

lli puzzle::start(){
	return snode;
} 

//heuristic for number of displaced tiles.
int puzzle::h(lli node){
	int count = 0;
	if(node%10) count++;
	node = node / 10;
	for(int i = 8; i > 0; i--){
		if(node % 10 != i) count++;
		node = node /10;
	}
	return MONOTONE*count;

}


// heuristic using manhattan distance
/*
int puzzle::h(lli node){
	int cnt = 0;
	for(int i = 2; i >= 0; i--){
		for(int j = 2; j >= 0; j--){
			int rem = node % 10;
			if(rem == 0){
				cnt+= abs(2-i) + abs(2-j);
			}
			else{
				int row = (rem -1)/3;
				int col = (rem-1)%3;
				cnt+= abs(row-i) + abs(col-j);
			}
			node = node / 10;
		}
	}
	return MONOTONE*cnt;
}
*/
lli puzzle::gen_node(std::vector<vector<int> > digit_rep){
	lli node = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			node = node * 10 + digit_rep[i][j];
		}
	}
	return node;
}

//print the present configuration of
// the puzzle.
void puzzle::print(lli node){
	stack<int> print_stack;
	for(int i = 0; i < 9; i++){
		int rem = node % 10;
		node = node / 10;
		print_stack.push(rem);
	}
	int cnt = 0;
	while(!print_stack.empty()){
		if(cnt%3 == 0) cout << endl;
		int print_tile = print_stack.top();
		print_stack.pop();
		if(print_tile == 0) cout << "+";
		else cout << print_tile;
		cnt++;
		cout << " ";
	}
	cout << endl;
}

//returns the set of neighbours of a node
//along with the cost.
std::vector<pair<lli, int> > puzzle::get_neighs(lli node){
	std::vector<pair<lli,int> > neighs;
	vector<int> v1(3);
	std::vector<std::vector<int> > digit_rep(3,v1);
	lli temp_node = node;
	pair<int,int> em_pos;


	for(int i = 2; i >=0; i--){
		for(int j = 2; j >= 0; j--){
			digit_rep[i][j] = temp_node % 10; 
			if(temp_node % 10 == 0){
				em_pos = pair<int,int> (i,j);  
			}
			temp_node = temp_node /10;
		}
	}

	std::vector<std::vector<int> > temp_neigh;

	if(em_pos.first -1 >= 0){
		temp_neigh = digit_rep;
		int tswap;
		temp_neigh[em_pos.first][em_pos.second] = temp_neigh[em_pos.first-1][em_pos.second];
		temp_neigh[em_pos.first-1][em_pos.second] = 0;
		neighs.push_back(pair<lli, int>(gen_node(temp_neigh), 1));
	}

	if(em_pos.second - 1 >= 0){
		temp_neigh = digit_rep;
		int tswap;
		temp_neigh[em_pos.first][em_pos.second] = temp_neigh[em_pos.first][em_pos.second-1];
		temp_neigh[em_pos.first][em_pos.second-1] = 0;
		neighs.push_back(pair<lli, int> (gen_node(temp_neigh),1));

	}

	if(em_pos.first + 1 < 3){
		temp_neigh = digit_rep;
		int tswap;
		temp_neigh[em_pos.first][em_pos.second] = temp_neigh[em_pos.first+1][em_pos.second];
		temp_neigh[em_pos.first+1][em_pos.second] = 0;
		neighs.push_back(pair<lli, int> (gen_node(temp_neigh), 1));		
	}

	if(em_pos.second + 1 < 3){
		temp_neigh = digit_rep;
		int tswap;
		temp_neigh[em_pos.first][em_pos.second] = temp_neigh[em_pos.first][em_pos.second+1];
		temp_neigh[em_pos.first][em_pos.second+1] = 0;
		neighs.push_back(pair<lli, int> (gen_node(temp_neigh), 1));		
	}

	return neighs;
}
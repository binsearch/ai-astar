#include <iostream>
using namespace std;
typedef long long int lli;

class puzzle
{
	lli snode;




	public:
		puzzle(lli);
		lli start();
		int h(lli);


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
	return count;
}
#include <iostream>
using namespace std;

class puzzle8
{
	lli snode;




	public:
		8puzzle(lli);
		lli start();
		int h(lli);


	/* data */
};

8puzzle::8puzzle(lli start){
	snode = start;
} 

lli 8puzzle::start(){
	return snode;
} 

//heuristic for number of displaced tiles.
int h(lli node){
	int count = 0;
	if(node%10) count++;
	node = node / 10;
	for(int i = 9; i > 0; i--){
		if(node % 10 != i) count++;
	}
	return count;
}
#include <iostream>
using namespace std;

class puzzle8
{
	lli snode;




	public:
		puzzle8(lli);
		lli start();
		int h(lli);


	/* data */
};

puzzle8::puzzle8(lli start){
	snode = start;
} 

lli puzzle8::start(){
	return snode;
} 

//heuristic for number of displaced tiles.
int puzzle8::h(lli node){
	int count = 0;
	if(node%10) count++;
	node = node / 10;
	for(int i = 8; i > 0; i--){
		if(node % 10 != i) count++;
		node = node /10;
	}
	return count;
}
/* Simple implementation of K- Nearest Neighbour Algorithim*/

/* 
#Attempts to be as generic as possible

 * author @ fifinonz
 * https://github.com/fifinonz
 *
*/

#include <iostream>
#include "knn.h"

using namespace std;



int main (int argc, char*argv[])
{
	// Create query instance object
		
	Classify P(3,0);
	// Classify and print result
	cout<<"Point ("<<P.getXvalue()<<"," <<P.getYvalue()<<")\n K-NN classification:\n "<<P.getCategory()<<"\n"<<endl;


}

/* Simple implementation of K- Nearest Neighbour Algorithim
 #Attempts to be as customizable as possible
 * author @ fifinonz
 * https://github.com/fifinonz
 *
*/

#include <iostream>
#include "knn.h"
#include <cmath>

#define K 3 //set value of K step 1 <---- Edit to add as many neighbours as needed ---->

using namespace std;

// Constructor initializes point to be classified

	Classify::Classify (double x, double y)
{
	double xValue=x;
	double yValue=y;
	nearNeighbours(xValue,yValue); // Step 2 find neighbours

} // end constructor

// Initialise training data
void Classify::setTrainingData()
{
	trainingData T;

	T[0][0]=7;
	T[0][1]=7;
	T[0][2]=0;
	T[1][0]=7;
	T[1][1]=4;
	T[1][2]=0;
	T[2][0]=3;
	T[2][1]=4;
	T[2][2]=1;
	T[3][0]=1;
	T[3][1]=4;
	T[3][2]=1;
}
// Function to calculate Eucledian Distances
void Classify::nearNeighbours(double x, double y)
{	
	double sqrDistance;

	for(int i=0; i<20; i++)
	{
		for(int j=0; j<=1; j++ )
		{			
			sqrDistance=pow((T[i][j]-x),2) + pow((T[i][j+1]-y),2);
			catDistance[i][j]=sqrDistance;
			catDistance[i][j+1]=T[i][j+2];
		}	 //end inner for
	}// end outer for
			sortDistance(); // call sorting function
} // end distance function

// Function sorts the squared distances 
void Classify::sortDistance()
{
	    sort(catDistance.begin(), catDistance.end(), [](const vector< double >& a, const vector< double >& b){ return a[1] > b[1]; } ); //step 3

		
}//End Function

//Function to catgorise
string Classify::categoryClass()  // step 5
{	
	double label, majority=0;
	
	while( majority=0 || K/majority<=0.5)
	{
		for (int m=0; m<K; m++)
			{	
				label=catDistance[m][1];

			for (int n=0; n<1; n++)
				{	// calculate simple majority
				if (T[m][n+1]==label)
					{	
					majority++;				
					} //end-if
				}// end inner for
			}// end outer for
	}// end while-loop
	
	// Return Category	
		if (label==1){
		category="Category 1";
		}
		else if (label==2){
		category = "Category 2";
		}
		else{
		category = "Category 3";
		} 	//<---- Edit to add as many categories as needed ---->
return category;
}//End Function
/*Training Data*/

// Third column represents the category i.e
// 1 == Category 1, 2 == Category 2 etc



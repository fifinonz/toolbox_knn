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
	nearNeighbours(x,y); // Step 2 find neighbours

} // end constructor

// Function to calculate Eucledian Distances
void Classify::nearNeighbours(double x, double y)
{	
	double sqrDistance;

	for(int i=0; i<20; i++)
	{
		for(int j=0; j<=1; j++ )
		{			
			sqrDistance=pow((trainingData[i][j]-x),2) + pow((trainingData[i][j+1]-y),2);
			catDistance[i][j]=sqrDistance;
			catDistance[i][j+1]=trainingData[i][j+2];
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
				if (trainingData[m][n+1]==label)
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

void Classify::setTrainingData()
{

	trainingData[0][0]=7;
	trainingData[0][1]=7;
	trainingData[0][2]=0;
	trainingData[1][0]=7;
	trainingData[1][1]=4;
	trainingData[1][2]=0;
	trainingData[2][0]=3;
	trainingData[2][1]=4;
	trainingData[2][2]=1;
	trainingData[3][0]=1;
	trainingData[3][1]=4;
	trainingData[3][2]=1;
}

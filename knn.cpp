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
	/*Training Data*/

// Third column represents the category i.e
// 1 == Category 1, 2 == Category 2 etc

/*Category 1*/
	trainingData.push_back(vector<double>(3,0)); // create 3-element row
	// store values
	trainingData.back().at(0)=7; 	
	trainingData.back().at(1)=7;
	trainingData.back().at(2)=0;
	
/*Category 2*/
	trainingData.push_back(vector<double>(3,0)); // create 3-element row
	// store values
	trainingData.back().at(0)=3; 	
	trainingData.back().at(1)=4;
	trainingData.back().at(2)=1;
/*Category 3*/
	trainingData.push_back(vector<double>(3,0)); // create 3-element row
	// store values
	trainingData.back().at(0)=1; 	
	trainingData.back().at(1)=4;
	trainingData.back().at(2)=1;
	
}
// Function to calculate Eucledian Distances
void Classify::nearNeighbours(double xValue, double yValue)
{	
	double sqrDistance, temp1, temp2;
	
	for(double i =0; i<(double)trainingData.size(); i++)
	{
		for(double j =0; j<(double)trainingData.size(); j++)
		{	
			temp1 = trainingData.at(i).at(j);
			temp1-=xValue;
			temp1=temp1*temp1;	
		
			temp2 =  trainingData.at(i).at(j+1);
			temp1-=yValue;
			temp2=temp2*temp2;	
	
			sqrDistance=temp1+temp2;

 // create 2-element row to store result
	catDistance.push_back(vector<double>(2,0));
	
	//store values	
	catDistance.back().at(0)=sqrDistance; 	
	catDistance.back().at(1)= trainingData.at(i).at(j+2);
	
			
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
	double label;
	double majority=0;
	
	while( majority=0 || K/majority<=0.5)
	{
		for (int m=0; m<K; m++)
			{	
				label=catDistance.at(m).at(1);

			for (int n=0; n<1; n++)
				{	// calculate simple majority
				if (trainingData.at(m).at(n+1)==label)
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



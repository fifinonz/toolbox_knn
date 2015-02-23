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
	
	xValue=x;
	yValue=y;

	setTrainingData(); // Initialise training data
	nearNeighbours(xValue,yValue); // Step 2 & 3 find neighbours
	sortDistance(); // step 4 sort
	categoryClass(); // step 5 determine classification
} // end constructor

/*Training Data*/

// Third column represents the category i.e
// 0 == Category 1, 
// 1 == Category 2...  etc

void Classify::setTrainingData()
{
	

/*Row 1*/
	trainingData.push_back(vector<double>(3,0)); // create 3-element row
	// store values
	trainingData.back().at(0)=7; 	
	trainingData.back().at(1)=7;
	trainingData.back().at(2)=0;
	
/*Row 2*/
	trainingData.push_back(vector<double>(3,0)); // create 3-element row
	// store values
	trainingData.back().at(0)=3; 	
	trainingData.back().at(1)=4;
	trainingData.back().at(2)=1;
/*Row 3*/
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
		for(double j =0; j<1; j++)
		{	
			temp1 = trainingData.at(i).at(j);
			temp1-=xValue;
			temp1=temp1*temp1;	
		
			temp2 =  trainingData.at(i).at(j+1);
			temp2-=yValue;
			temp2=temp2*temp2;	
	
			sqrDistance=temp1+temp2;

 // create 2-element row to store result
	catDistance.push_back(vector<double>(2,0));
	
	//store values	
	catDistance.back().at(0)=sqrDistance; 	
	catDistance.back().at(1)= trainingData.at(i).at(2);
	
			
		}	 //end inner for
	}// end outer for
			
} // end distance function

// Function sorts the squared distances 
void Classify::sortDistance()
{
	    sort(catDistance.begin(), catDistance.end(), [](const vector< double >& a, const vector< double >& b){ return a[1] > b[1]; } ); 

		
}//End Function

//Function to catgorise
void Classify::categoryClass() 
{	
	double countCat1=0;
	double countCat2=0;
	double countCat3=0;
	double value;
	
		for (double m=0; m<K; m++)
			{	
		for (double n=0; n<1; n++)
			{				
				value = catDistance.at(m).at(n+1);
				// calculate simple majority
				if (value==0)
					{	
					countCat1++;				
					} //end-if
				else if (value==1)
					{	
					countCat2++;				
					} //end-if
				else 
					{	
					countCat3++;				
					} //end-if
			}// end outer for-loop	
			}// end outer for-loop
		
	
	// Categorize	
		if (countCat1>countCat2 && countCat1>countCat3){
		category="Category 1";
		}
		else if (countCat2>countCat1 && countCat2>countCat3){
		category = "Category 2";
		}
		else { 
		category = "Category 3";
		} 
	//<---- Edit to add as many categories as needed ---->

}//End Function

// return category
string Classify::getCategory()
{
	return category;
}

// return x value
double Classify::getXvalue()
{
	return xValue;
}

// return y value
double Classify::getYvalue()
{
	return yValue;
}

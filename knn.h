/* Simple implementation of K- Nearest Neighbour Algorithim
 #Attempts to be as generic as possible
 * author @ fifinonz
 * https://github.com/fifinonz
 *
*/
#ifndef KNN_H
#define KNN_H
// Training Data Class definition
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Classify
{
	public:
	double xValue;
	double yValue;
	Classify (double,double); // constructor that initialises query object
	void nearNeighbours(double,double); //calculate distance to each training instance
	void sortDistance(); // rank K neighbours
	string categoryClass(); // determine classification
	void setTrainingData();

	private:
	typedef vector<vector<double>> trainingData;
	typedef vector<vector<double>> catDistance;
	string category;
};

#endif

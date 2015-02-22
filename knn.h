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
#include <string>
#define MAX 50

 //  declares empty 2D-arrays constructed from STL vectors
	
class Classify
{
	public:
	double xValue;
	double yValue;

	Classify (double,double); // constructor that initialises query object
	void nearNeighbours(double,double); //calculate distance to each training instance
	void sortDistance(); // rank K neighbours
	std::string categoryClass(); // determine classification
	void setTrainingData();

	private:
	std::vector<std::vector<double>> trainingData;
	std::vector<std::vector<double>> catDistance;

	std::string category;
};

#endif

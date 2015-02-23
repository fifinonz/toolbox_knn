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



	
class Classify
{
	public:
	
	Classify (double,double); // constructor that initialises query object
	void nearNeighbours(double,double); //calculate distance to each training instance
	void sortDistance(); // rank K neighbours
	void categoryClass(); // determine classification
	void setTrainingData();
	double getXvalue();
	double getYvalue();
	std::string getCategory(); //return category
	private:
	double xValue;
	double yValue;	
//  declares empty 2D-arrays constructed from STL vectors	
	std::vector<std::vector<double>> trainingData;
	std::vector<std::vector<double>> catDistance;
	std::string category;

};

#endif

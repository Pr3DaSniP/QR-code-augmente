#include <opencv2/opencv.hpp>
#include <iostream>

#include "Composeur.h"
#include "Decomposeur.h"

using namespace std;

const bool AFFICHER_IMAGE = true;

void compose()
{
	Composeur c;
	c.compose(AFFICHER_IMAGE);
}

void decompose() {
	Decomposeur d;
	d.decompose(AFFICHER_IMAGE);
}

int main()
{
	compose();
	
	cv::waitKey(0);

	decompose();

	return 0;
}
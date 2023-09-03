#pragma once

#include <opencv2/opencv.hpp>

struct vec4
{
	int v1, v2, v3, v4;
};

class Decomposeur
{
private:
	int getValue(int y, int x, cv::Mat augmente);

	bool isValid(int min, int value, int max);

	vec4 getValues(int value);

	cv::Mat finalImage(int h, int w);
public:	
	void decompose(bool affiche);
};


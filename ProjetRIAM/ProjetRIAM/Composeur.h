#pragma once

#include <opencv2/opencv.hpp>

class Composeur
{
private:
	cv::Mat binaryImage(cv::Mat image);

	cv::Mat resizeDPI(cv::Mat image);

	int combine(int y, int x, cv::Mat q1, cv::Mat q2, cv::Mat q3);

	int getValue(int y, int x, cv::Mat porteur, int value);
public:
	void compose(bool affiche);
};
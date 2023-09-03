#include "Decomposeur.h"

int Decomposeur::getValue(int y, int x, cv::Mat augmente)
{
	return (int)augmente.at<uchar>(y, x);
}

bool Decomposeur::isValid(int min, int value, int max)
{
	return value >= min && value <= max;
}

vec4 Decomposeur::getValues(int value)
{
	if (isValid(0, value, 8) || isValid(249, value, 255))
	{
		if (value == 4) return { 0,0,0,0 };
		else if (value == 252) return { 1,0,0,0 };
	}
	else if (isValid(9, value, 16) || isValid(241, value, 248))
	{
		if (value == 12) return { 0,1,0,0 };
		else if (value == 244) return { 1,1,0,0 };
	}
	else if (isValid(17, value, 24) || isValid(233, value, 240))
	{
		if (value == 20) return { 0,0,1,0 };
		else if (value == 236) return { 1,0,1,0 };
	}
	else if (isValid(25, value, 32) || isValid(225, value, 232))
	{
		if (value == 28) return { 0,1,1,0 };
		else if (value == 228) return { 1,1,1,0 };
	}
	else if (isValid(33, value, 40) || isValid(217, value, 224))
	{
		if (value == 36) return { 0,0,0,1 };
		else if (value == 220) return { 1,0,0,1 };
	}
	else if (isValid(41, value, 48) || isValid(209, value, 216))
	{
		if (value == 44) return { 0,1,0,1 };
		else if (value == 212) return { 1,1,0,1 };
	}
	else if (isValid(49, value, 56) || isValid(201, value, 208))
	{
		if (value == 52) return { 0,0,1,1 };
		else if (value == 204) return { 1,0,1,1 };
	}
	else if (isValid(57, value, 64) || isValid(192, value, 200))
	{
		if (value == 60) return { 0,1,1,1 };
		else if (value == 196) return { 1,1,1,1 };
	}
}

cv::Mat Decomposeur::finalImage(int h, int w) {
	cv::Mat test = cv::Mat::zeros(h, w, CV_8UC1);
	for (int y = 0; y < test.rows; y++)
	{
		for (int x = 0; x < test.cols; x++)
		{
			test.at<uchar>(y, x) = 127;
		}
	}
	return test;
}

void Decomposeur::decompose(bool affiche)
{
	cv::Mat qrAugmente = cv::imread("qraugmente/qrAugmente.png", cv::IMREAD_GRAYSCALE);

	// 2.15 MINIMUM
	cv::Mat qrFinal = finalImage(qrAugmente.rows * 2, qrAugmente.cols * 2);

	for (int y = 0; y < qrAugmente.rows; y++)
	{
		for (int x = 0; x < qrAugmente.cols; x++)
		{
			int v = (int)qrAugmente.at<uchar>(y, x);
			vec4 values = getValues(v);
			qrFinal.at<uchar>(y, x) = values.v1 * 255;
			qrFinal.at<uchar>(y, x + qrAugmente.cols) = values.v2 * 255;
			qrFinal.at<uchar>(y + qrAugmente.rows, x) = values.v3 * 255;
			qrFinal.at<uchar>(y + qrAugmente.rows, x + qrAugmente.cols) = values.v4 * 255;
		}
	}

	cv::imwrite("output/qrFinal.png", qrFinal);

	if (affiche)
	{
		cv::imshow("QR Final", qrFinal);
		cv::waitKey(0);
	}
}
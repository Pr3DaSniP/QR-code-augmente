#include "Composeur.h"

cv::Mat Composeur::binaryImage(cv::Mat image) {
	cv::Mat grayImage;
	cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
	cv::Mat binaryImage;
	cv::threshold(grayImage, binaryImage, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	return binaryImage;
}

cv::Mat Composeur::resizeDPI(cv::Mat image) {
	cv::Mat resizedImage;
	cv::resize(image, resizedImage, cv::Size(), 300.0 / image.cols, 300.0 / image.cols, cv::INTER_NEAREST);
	return resizedImage;
}

int Composeur::combine(int y, int x, cv::Mat q1, cv::Mat q2, cv::Mat q3) {
	int v1 = (int)q1.at<uchar>(y, x);
	int v2 = (int)q2.at<uchar>(y, x);
	int v3 = (int)q3.at<uchar>(y, x);

	// Blanc Blanc Blanc
	if (v1 == 255 && v2 == 255 && v3 == 255) {
		return 7;
	}
	// Noir Blanc Blanc
	else if (v1 == 0 && v2 == 255 && v3 == 255) {
		return 6;
	}
	// Blanc Noir Blanc
	else if (v1 == 255 && v2 == 0 && v3 == 255) {
		return 5;
	}
	// Noir Noir Blanc
	else if (v1 == 0 && v2 == 0 && v3 == 255) {
		return 4;
	}
	// Blanc Blanc Noir
	else if (v1 == 255 && v2 == 255 && v3 == 0) {
		return 3;
	}
	// Noir Blanc Noir
	else if (v1 == 0 && v2 == 255 && v3 == 0) {
		return 2;
	}
	// Blanc Noir Noir
	else if (v1 == 255 && v2 == 0 && v3 == 0) {
		return 1;
	}
	// Noir Noir Noir
	else if (v1 == 0 && v2 == 0 && v3 == 0) {
		return 0;
	}
}

int Composeur::getValue(int y, int x, cv::Mat porteur, int value) {
	int cur = (int)porteur.at<uchar>(y, x);
	switch (cur) {
		// Noir
	case 0:
		switch (value) {
		case 0:
			return 4;
		case 1:
			return 12;
		case 2:
			return 20;
		case 3:
			return 28;
		case 4:
			return 36;
		case 5:
			return 44;
		case 6:
			return 52;
		case 7:
			return 60;
		}
		// Blanc
	case 255:
		switch (value) {
		case 0:
			return 252;
		case 1:
			return 244;
		case 2:
			return 236;
		case 3:
			return 228;
		case 4:
			return 220;
		case 5:
			return 212;
		case 6:
			return 204;
		case 7:
			return 196;
		}
	}
}

void Composeur::compose(bool affiche) {
	cv::Mat qrPorteur = resizeDPI(binaryImage(cv::imread("input/qrPorteur.png")));
	cv::Mat qr1 = resizeDPI(binaryImage(cv::imread("input/qr1.png")));
	cv::Mat qr2 = resizeDPI(binaryImage(cv::imread("input/qr2.png")));
	cv::Mat qr3 = resizeDPI(binaryImage(cv::imread("input/qr3.png")));

	cv::Mat qrAugmente = qrPorteur.clone();

	for (int y = 0; y < qrPorteur.rows; y++) {
		for (int x = 0; x < qrPorteur.cols; x++) {
			int value = combine(y, x, qr1, qr2, qr3);
			int newValue = getValue(y, x, qrPorteur, value);
			qrAugmente.at<uchar>(y, x) = newValue;
		}
	}
	cv::imwrite("qraugmente/qrAugmente.png", qrAugmente);

	if (affiche) {
		cv::imshow("QR Porteur", qrPorteur);
		cv::imshow("QR 1", qr1);
		cv::imshow("QR 2", qr2);
		cv::imshow("QR 3", qr3);
		cv::imshow("QR Augmenté", qrAugmente);
		cv::waitKey(0);
	}
}
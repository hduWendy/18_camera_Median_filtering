// 18_camera_Median_filtering.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()  //��ֵ�˲�
{
	VideoCapture cap(0);
	double scale = 0.5;

	while (1)
	{
		cv::Mat frame;
		cv::Mat hsvMat;
		cv::Mat medianMat;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		medianBlur(rFrame, medianMat, 5);//��ֵ�˲�

		cv::imshow("whie: in the Median filtering", medianMat);
		cv::imshow("frame", rFrame);

		waitKey(30);
	}
}


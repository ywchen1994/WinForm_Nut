#pragma once

#include"FlyCapture2.h"
#include<opencv2\opencv.hpp>
#include <opencv2\highgui.hpp>
using namespace FlyCapture2;
using namespace std;
using namespace cv;

class CapFromCam
{
public:
	CapFromCam();
	bool open(int index=0);
	
	Mat getImage();
	void close();

private:
	Camera camera;
};


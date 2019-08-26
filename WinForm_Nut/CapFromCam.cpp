#include "CapFromCam.h"



CapFromCam::CapFromCam()
{
}

bool CapFromCam::open(int index)
{
	try
	{
		
		FlyCapture2::Error err = camera.Connect((PGRGuid*)index);
		if (err != PGRERROR_OK)
			throw string(err.GetDescription()+(string)"Error in lines:"+to_string(__LINE__));
	/*	FlyCapture2::Format7ImageSettings fset;
		fset.height = 1500;
		fset.mode = MODE_0;
		fset.offsetX = 288;
		fset.offsetY = 274;
		fset.pixelFormat = PIXEL_FORMAT_MONO8;
		fset.width = 1472;
		fset.pixelFormat = UNSPECIFIED_PIXEL_FORMAT;
		err = camera.SetFormat7Configuration(&fset, (uint)5520);*/
		if (err != PGRERROR_OK)
			throw string(err.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));
		err = camera.StartCapture();
		if (err != PGRERROR_OK)
			throw string(err.GetDescription() + (string)"Error in lines:" + to_string(__LINE__));
		
	}
	catch (const std::string e)
	{
		cerr << e << endl;
		assert(0);
	}
	return true;
}


Mat CapFromCam::getImage()
{
	try
	{
		Image rawImage;
		FlyCapture2::Error err = camera.RetrieveBuffer(&rawImage);
		if(err != PGRERROR_OK)
			throw exception(err.GetDescription());
		Image rgbImage;
	
		rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);
		unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize() / (double)rgbImage.GetRows();

		return cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes).clone();
	}
	catch (const std::string e)
	{
		cerr << e << endl;
		assert(0);
	}


}

void CapFromCam::close()
{
	camera.StopCapture();
}



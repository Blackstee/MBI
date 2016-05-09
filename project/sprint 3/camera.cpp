#include "opencv2/highgui/highgui.hpp"
#include "opencv\cv.h" 
#include "opencv\highgui.h"
#include "iostream"
using namespace cv;
using namespace std;

int main() {
	VideoCapture cap(0);   //0 is the id of video device.0 if you have only one camera.

	if (!cap.isOpened())  //check video device has been initialised
	{
		cout << "ERROR: Cannot open the video Device";
		return -1;
	}     while (1)
	{
		Mat cameraFrame;
		cap.read(cameraFrame);
		imshow("frame", cameraFrame);
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}

#include<opencv2/opencv.hpp>
#include"cartoon.h"

using namespace cv;
using namespace std;




int main()
{
	VideoCapture camera;
	camera.open("my_video.avi");
	if(!camera.isOpened())
	{
		cerr << "ERROR: Could not access the camera or video"<<endl;
		exit(1);
	}
	camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	while(true)
	{
		Mat cameraFrame;
		camera>>cameraFrame;
		if( cameraFrame.empty())
		{
			cerr<<"ERROR: Couldn't grab a camera frame."<<endl;
			exit(1);
		}
		//creat a blank output image, that we will draw onto 
		Mat displaydFrame(cameraFrame.size(), CV_8UC3 );
		// run the cartoonifier filter on the camera frame.
		cartoonifyImage(cameraFrame, displaydFrame);

		//display the processed image onto the screen
		imshow("cartoonifier", displaydFrame);

		char keypress = waitKey(20);
		if(keypress == 27)
		{
			//quit the program!!!!
			break;
		}

	}//end while

}
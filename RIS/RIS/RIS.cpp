#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <iostream>
#include "Sift.h"
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;



int main(int argc, char** argv)
{

    // Add results to image and save.
    cv::Mat output = sift("lena.jpg");
    return 0;
}

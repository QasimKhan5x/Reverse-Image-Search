#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "SubIndex.cpp"
#include <unordered_map>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

class MainIndex {
	float g1;
	unordered_map<int, SubIndex> map;
};
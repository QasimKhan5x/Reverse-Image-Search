#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "SubIndex.cpp"
#include <unordered_map>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

class MainIndex {
private:
	int g1;
	unordered_map<vector<uchar>, SubIndex> map;

public:

	MainIndex(vector<uchar> g1) {

	}


	int combine_g1(vector<uchar> g1) {
		// convert g1 vector to binaries and then combine all those binaries to
		// int 32
	}

};
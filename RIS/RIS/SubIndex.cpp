#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "Keypoints.cpp"

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

class SubIndex{
private:
	vector<Keypoint> keypoints;
	vector<uchar> g2;

public:
	SubIndex(vector<uchar> g2, Mat G2, vector<Keypoint> kps, Mat Descriptors) {
		this->g2 = g2;
		
		for (int i = 0; i < G2.rows; i++) {
			vector<uchar> temp;
			G2.row(i).copyTo(temp);
			if (g2 == temp) {
				vector<uchar> desc_temp;
				Descriptors.row(i).copyTo(desc_temp);
				kps.at(i).setDescriptor(desc_temp);
				keypoints.push_back(kps.at(i));
			}
		}
	}
};
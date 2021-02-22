#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "Keypoints.cpp"

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

/*
This class should contains 2 attributes:
1. An int32 g2
Suppose we have a function convertToInt32(vector<uchar> g2)
Then the "index" g2 of the ith SubIndex object is convertToInt32(G2[i])
where G2 is the 1070x16 matrix of G2 hash values.

2. vector<Keypoint> keypoints
Procedure to populate:
	for i = 1 to G2.rows
		if convertToInt32(G2[i]) == g2 {
				// where kps is the original vector of all keypoints
				// and Descriptors is the original matrix of all descriptors
				kps.get(i).setDescriptor(Descriptors[i])
				keypoints.add(kps.get(i)) 
		}
*/
class SubIndex{
private:
	vector<Keypoint> keypoints;
	// this should be an int called "index"
	vector<uchar> g2;

public:
	/*
	The constructor takes as arguments
		- G2, which is the original matrix of G2 hashes
		- kps, which is the original vector of all keypoints
		- Descriptors, which is the original matrix of all descriptors

	It should perform two operations:
		1. Create index g2:
			- If we are making the ith SubIndex object, it should access G2[i]
		2. Create keypoints vector
	*/
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
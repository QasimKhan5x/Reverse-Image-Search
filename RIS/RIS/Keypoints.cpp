#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <vector>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

class Keypoint {
private:
	Point2f pos;
	float size;
	float rotation;
	vector<uchar> descriptor;

public:
	Keypoint(KeyPoint kp) {
		setSize(kp);
		setPosition(kp);
		setRotation(kp);
	}

	float getSize() {
		return size;
	}

	Point2f getPosition() {
		return pos;
	}

	void setSize(KeyPoint kp) {
		size = kp.size;
	}

	void setPosition(KeyPoint kp) {
			pos = kp.pt;
	}

	float getRotation() {
		return rotation;
	}

	void setRotation(KeyPoint kp) {
		rotation = kp.angle;
	}

	void setDescriptor(vector<uchar> desc) {
		descriptor = desc;
	}

};
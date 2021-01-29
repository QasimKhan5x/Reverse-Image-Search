#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <vector>
#include <iostream>

using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

class HashGeneration
{
public:

	Mat generateHash(const Mat mat) {
		vector<vector<float>> Temp;
		for (int d = 0; d < 1070; d++) {
			vector<float> Desc;
				for (int n = 0; n < 16; n++) {
					float sum = 0;
					for (int i = 0; i < 4; i++) {
						sum += pow(mat.ptr<float>(d)[16*i + n], 2);
					}
					Desc.push_back(0.25 * sum);
				}
				Temp.push_back(Desc);
				
		}

		Mat tempMat(Temp.size(), Temp.at(0).size(), CV_64FC1);
		for (int i = 0; i < tempMat.rows; ++i)
			for (int j = 0; j < tempMat.cols; ++j)
				tempMat.at<double>(i, j) = Temp.at(i).at(j);


		
		return tempMat;
	}
	
};
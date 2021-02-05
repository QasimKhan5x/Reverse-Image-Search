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
private:
	Mat g1 = Mat(1070,16, CV_64FC1);
	Mat g2 = Mat(1070, 16, CV_64FC1);
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
					sum = sum * 4.0;
					Desc.push_back(sum);
					g1.ptr<double>(d)[n] = floor(sum + 0.5) >= 4.0 ? 3 : floor(sum + 0.5);
					int part = sum / 1;
					double fractional = sum - (double)part;
					if (fractional < 0.3) {
						g2.ptr<double>(d)[n] = g1.ptr<double>(d)[n] - 1 < 0 ? 0 : g1.ptr<double>(d)[n] - 1;
					}
					else if (fractional > 0.7) {
						g2.ptr<double>(d)[n] = g1.ptr<double>(d)[n] + 1;
					}
					else {
						g2.ptr<double>(d)[n] = g1.ptr<double>(d)[n];
					}
				}
				Temp.push_back(Desc);
				

		}
		//cout << g1;
		//cout << g2;
	//	cout << (int) g1.ptr<double>(0)[0];

		Mat tempMat(Temp.size(), Temp.at(0).size(), CV_64FC1);
		for (int i = 0; i < tempMat.rows; ++i)
			for (int j = 0; j < tempMat.cols; ++j)
				tempMat.at<double>(i, j) = Temp.at(i).at(j);


		
		return tempMat;
	}
	

};
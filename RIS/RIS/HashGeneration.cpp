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

	vector<float*> generateHash(const Mat mat) {
		vector<float*> S = vector<float*>();
		for (int d = 0; d < 1070; d++) {
			float Desc[16];
				for (int n = 0; n < 16; n++) {
					float sum = 0;
					for (int i = 0; i < 4; i++) {
						sum += pow(mat.ptr<float>(d)[16*i + n], 2);
					}
					Desc[n] = 0.25 * sum;
				}
				S.push_back(Desc);
				
		}
		return S;
	}



	
};
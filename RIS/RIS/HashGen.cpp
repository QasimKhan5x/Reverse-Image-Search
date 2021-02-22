#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

struct HashGen {
	
	Mat g1, g2, mat;

	HashGen(const Mat mat) {
		this->mat = mat;
		g1 = Mat(mat.rows, 16, CV_8UC3);
		g2 = Mat(mat.rows, 16, CV_8UC3);
	}
	
	void computeHash() {
	/*	for (int d = 0; d < g1.rows; d++) {
			for (int n = 0; n < 16; n++) {
				float sum = 0;
				for (int i = 0; i < 4; i++) {
					sum += pow(mat.ptr<float>(d)[16*i + n], 2);
				}
				sum *= 4.0;
				g1.ptr<uchar>(d)[n] = floor(sum + 0.5) >= 4.0 ? (uchar) 3 : (uchar) floor(sum + 0.5);
				double intpart;
				double fractpart = modf(sum, &intpart);
				if (fractpart < 0.3) {
					g2.ptr<uchar>(d)[n] = g1.ptr<uchar>(d)[n] - 1 < 0 ? 0 : g1.ptr<uchar>(d)[n] - 1;
				}
				else if (fractpart > 0.7) {
					g2.ptr<uchar>(d)[n] = g1.ptr<uchar>(d)[n] + 1;
				}
				else {
					g2.ptr<uchar>(d)[n] = g1.ptr<uchar>(d)[n];
				}
			}
		}
	*/
	}
	
};
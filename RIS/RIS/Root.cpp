#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "MainIndex.cpp"
#include "FeatureDetector.h"
#include "HashGen.cpp"

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

class Root {
private:
	unordered_map<int, MainIndex> map;
	
public:
	Root(String filename) {
        // Add results to image and save.
        cv::Mat img = imread(filename);
        int r1 = img.rows;
        int c1 = img.cols;

        cv::Mat mat = surf(filename);
        const int rows = mat.rows;
        int cols = mat.cols;

        cout << "Rows: " << rows << endl;
        cout << "Cols: " << cols << endl;

        HashGen h = HashGen(mat);
        h.computeHash();

     /*   for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                cout << (int)h.g1.ptr<uchar>(i)[j] << " ";
            cout << endl;
        }

        cout << "===============================" << endl;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                cout << (int)h.g2.ptr<uchar>(i)[j] << " ";
            cout << endl;
        }*/

	}


    void fillUnorderedMap() {

    }
};
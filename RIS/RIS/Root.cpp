#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "MainIndex.cpp"
#include "FeatureDetector.h"
#include "HashGen.cpp"
#include <math.h>
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

class Root {
private:
//	unordered_map<int, MainIndex> map;
	
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

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                cout << (int)h.g1.ptr<uchar>(i)[j] << " ";
            cout << endl;
        }
        /*
        cout << "===============================" << endl;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                cout << (int)h.g2.ptr<uchar>(i)[j] << " ";
            cout << endl;
        }*/

        vector<uchar> temp;
        h.g1.row(0).copyTo(temp);
      //  int check = combine_g1(temp);
      //  cout << endl << endl << "Mehnat rang lai: "<< check << endl << endl;
	}




    int combine_g1(vector<uchar> g1) {
        // convert g1 vector to binaries and then combine all those binaries to
        // int 32
        int* binary = new int[32];
        for (int i = g1.size() - 1, count = 0; i > 0; i--) {
            if (g1.at(i) == 0) {
                binary[count++] = 0;
                binary[count++] = 0;
            }
            else if (g1.at(i) == 1) {
                binary[count++] = 0;
                binary[count++] = 0;
            }
            else if (g1.at(i) == 2) {
                binary[count++] = 0;
                binary[count++] = 0;
            }
            else {
                binary[count++] = 0;
                binary[count++] = 0;
            }
        }
        cout << endl << endl<< "Yahan tk theek chalta hai" << endl << endl;
        int g1_val=0;
        for (int i = 31, j = 0; i > 0; i--, j++) {
            g1_val += binary[i]*(pow(2, j));
        }

        return g1_val;
    }
};
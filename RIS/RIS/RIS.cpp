#include <opencv2/core.hpp>
#include <iostream>
#include "FeatureDetector.h"
#include <algorithm>
#include <functional>
#include "HashGeneration.cpp"


using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;


int main(int argc, char** argv)
{
    // Add results to image and save.
    cv::Mat img = imread("lena.jpg");
    int r1 = img.rows;
    int c1 = img.cols;
    cout << "Rows: " << r1 << endl;
    cout << "Cols: " << c1 << endl;
    cv::Mat mat = surf("lena.jpg");
    const int rows = mat.rows;
    int cols = mat.cols;
        
    HashGeneration h = HashGeneration();
    h.generateHash(mat);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << h.g1.ptr<double>(i)[j] << " ";
        cout << endl;
    }
        
    cout << "===============================" << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << h.g2.ptr<double>(i)[j] << " ";
        cout << endl;
    }



    
    
    return 0;
}
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace cv;
using namespace cv::xfeatures2d;

Mat sift(String filename) {
    const Mat input = imread(filename);
    Ptr<SIFT> siftPtr = SIFT::create();
    std::vector<KeyPoint> keypoints;
    siftPtr->detect(input, keypoints);
    Mat output;
    siftPtr->compute(input, keypoints, output);
    return output;
}

Mat surf(String filename) {
    const Mat input = imread(filename);
    Ptr<SURF> surfPtr = SURF::create();
    std::vector<KeyPoint> keypoints;
    surfPtr->detect(input, keypoints);
    Mat output;
    surfPtr->compute(input, keypoints, output);
    return output;
}

std::vector<KeyPoint> getKeypoints(String filename) {
    const Mat input = imread(filename);
    Ptr<SURF> surfPtr = SURF::create();
    std::vector<KeyPoint> keypoints;
    surfPtr->detect(input, keypoints);
    return keypoints;
}
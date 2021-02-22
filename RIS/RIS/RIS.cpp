#include <opencv2/core.hpp>
#include <iostream>
#include "Root.cpp"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Root r = Root("lena.jpg");
    return 0;
}
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include "SubIndex.cpp"
#include <unordered_map>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

/*
The class should contain 2 attributes:

1. Index (int32 g1)
This index is obtained by performing convertToInt32(G1[i]) 
for the ith row of G1. In the case where we encounter the scenario
G1[i] = G1[j] but i != j, the situations can arise:
	1. G2 is different
	2. G2 is the same as G1[i] where i < j
We IGNORE Case 2. For case 1, we create a list of SubIndex objects that
we map to.

2. Map from g2 to SubIndex
Procedure to populate:
	for i = 1 to G2.length


Process for creation:
	1. Provide g1 "index" to constructor
	2. for i = 1 to G1.length:
		if G1[i] == g1:
			map.put(convertToInt32(G2[i]), SubIndex(G2[i]))
*/

class MainIndex {
	float g1;
	unordered_map<int, SubIndex> map;
};
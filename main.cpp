#include <stdio.h>
#include <opencv2/opencv.hpp>

#include<vector>

#include "FocusStacking.h"




using namespace cv;
using namespace std;

int main (int argc, char *argv[])
{
//cv::String path("/home/femust/cpp_workspace/tooploox/task/build/bug/*.png");
//vector<cv::String> fn;
//vector<cv::Mat> images;
//cv::glob(path,fn,false);

//for (size_t it=0; it<1/*fn.size()*/; ++it){
//     //cv::Mat im = cv::imread(fn[it]);
//     Mat im = Mat::ones(10, 10, CV_32F);
//     if (im.empty()) continue;
//     images.push_back(im);
//     //im.release();
//}
//if ( images.size()==0 ) {
//    std::cout <<  "No photos (wo)man.";
//    return -1;
//}else {
//    std::cout << "main Loaded: " << images.size() << " images. " << std::endl;
//}

//FocusStacking focusstacker(FilterFactory::make_filter(EdgeDetectionMethod::ZeroFilter));
//for (auto it=images.begin();it<images.end();it++){
//    focusstacker.addInputImage(*it);
//}
//focusstacker.debug(true);
//focusstacker.run_filter();


cv::Mat C = (cv::Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

std::cout << C;
    return 0;
}

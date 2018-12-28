#include <stdio.h>
#include <opencv2/opencv.hpp>

#include<vector>

#include "FocusStacking.h"




using namespace cv;
using namespace std;

int main (int argc, char *argv[])
{
cv::String path("/home/femust/cpp_workspace/tooploox/task/build/bug/*.png");
vector<cv::String> fn;
vector<cv::Mat> images;
cv::glob(path,fn,false);

//for (size_t it=0; it<fn.size(); ++it){
//     cv::Mat im = cv::imread(fn[it]);

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



cv::Mat im = (cv::Mat_<int>(5,5) <<    0, 1, 2, 3, 4,
                                       0, 1, 2, 3, 4,
                                       0, 1, 2, 3, 4,
                                       0, 1, 2, 3, 4,
                                       0, 1, 2, 3, 4);
cv::Mat im2 = (cv::Mat_<int>(5,5) <<   1, 0, 3, 5, 2,
                                       1, 0, 3, 5, 5,
                                       1, 0, 3, 5, 5,
                                       1, 0, 3, 5, 5,
                                       1, 0, 3, 5, 2);
cv::Mat im3 = (cv::Mat_<int>(5,5) <<   1, 0, 4, 5, 2,
                                       1, 0, 4, 5, 5,
                                       1, 0, 4, 5, 15,
                                       1, 0, 4, 5, 5,
                                       1, 0, 4, 5, 12);


images.push_back(im);
images.push_back(im2);
images.push_back(im3);


FocusStacking focusstacker(FilterFactory::make_filter(EdgeDetectionMethod::Laplace4),MergeFactory::make_merge(MergeMethod::Maximum));
for (auto it=images.begin();it<images.end();it++){
    focusstacker.addInputImage(*it);
}

//focusstacker.run_filter();
focusstacker.run_merger();


    return 0;
}

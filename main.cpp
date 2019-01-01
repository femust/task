#include <stdio.h>
#include <opencv2/opencv.hpp>

#include<vector>

#include "FocusStacking.h"

using namespace cv;
using namespace std;

int main ()
{
cv::String path("/home/femust/cpp_workspace/tooploox/task/build/bug/*.png");
vector<cv::String> fn;
vector<cv::Mat> images;
cv::glob(path,fn,false);
 cv::Mat imToLoad;
for (size_t it=0; it<fn.size(); ++it){
     imToLoad = cv::imread(fn[it],cv::IMREAD_COLOR);
     if (imToLoad.empty()) continue;
     images.push_back(imToLoad);
}
imToLoad.release();
if ( images.size()==0 ) {
    std::cout <<  "No photos (wo)man.";
    return -1;
}else {
    std::cout << "In main file there are " << images.size() << " images loaded. " << std::endl;
}

FocusStacking focusstacker(FilterFactory::make_filter(EdgeDetectionMethod::Laplace8),MergeFactory::make_merge(MergeMethod::Maximum));
for (auto it=images.begin();it<images.end();it++){
    focusstacker.addInputImage(*it);
}

focusstacker.run();

    return 0;
}

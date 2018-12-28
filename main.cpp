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

for (size_t it=0; it<fn.size(); ++it){
     cv::Mat im = cv::imread(fn[it],IMREAD_GRAYSCALE);
     if (im.empty()) continue;
     images.push_back(im);
     //im.release();
}
if ( images.size()==0 ) {
    std::cout <<  "No photos (wo)man.";
    return -1;
}else {
    std::cout << "main Loaded: " << images.size() << " images. " << std::endl;
}

FocusStacking focusstacker(FilterFactory::make_filter(EdgeDetectionMethod::Laplace4));
for (auto it=images.begin();it<images.end();it++){
    focusstacker.addInputImage(*it);
}
focusstacker.debug(true);
focusstacker.run_filter();



    return 0;
}

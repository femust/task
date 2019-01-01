#include <stdio.h>
#include <opencv2/opencv.hpp>

#include<vector>
#include<string>

#include "FocusStacking.h"

using namespace cv;
using namespace std;

int main (int argc, char *argv[]){
    string path;
    cv::Mat imToLoad;
    vector<string> fn;
    vector<cv::Mat> images;
    cv::ImreadModes mode;

    if (argc<3){
        std::cout << "Give name of the folder with a bug." << std::endl;
        std::cout << "Write gray or rgb after the folder." <<std::endl;
        return 0;
    } else if (argc==3){
        path=argv[1];
        std::cout << "Loading from the folder: " << path << std::endl;
        std::cout << "argv2: " << argv[2] << std::endl;
        if (!strcmp(argv[2], "gray")){
            mode=cv::IMREAD_GRAYSCALE;
            std::cout <<"hehe" << std::endl;
        } else if (!strcmp(argv[2], "rgb")){
            mode=cv::IMREAD_COLOR;
        } else {std::cout << "No mode." <<std::endl; return 0;}
        std::cout << "Mode of loaded image: " << argv[2] << std::endl;
    }

    cv::glob(path+"/*.png",fn,false);
    for (size_t it=0; it<fn.size(); ++it){
         imToLoad = cv::imread(fn[it],mode);
         if (imToLoad.empty()) continue;
         std::cout << "Image loaded from a file: " << fn[it] << std::endl;
         images.push_back(imToLoad);
         imToLoad.release();
    }

    if ( images.size()==0 ) {
        std::cout <<  "No photos.";
        return -1;
    }else {
        std::cout << "In main.cpp file there are " << images.size()  << std::endl;
    }
    FocusStacking focusstacker(FilterFactory::make_filter(EdgeDetectionMethod::Laplace8),MergeFactory::make_merge(MergeMethod::Maximum));
    for (auto it=images.begin();it<images.end();it++){
        focusstacker.addInputImage(*it);
    }

    focusstacker.run();

    return 0;
}

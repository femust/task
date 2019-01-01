#include "Merge.h"

std::shared_ptr<Merge> MergeFactory::make_merge(MergeMethod method){
    if (method==MergeMethod::Maximum){
        std::cout << "Maximum method chose"<<std::endl;
        return std::make_shared<Maximum>();
    }else{
        std::cout << "Wrong method" << std::endl;
        //throw error
    }
}

void Maximum::execute(std::vector<cv::Mat> &images,cv::Mat &lookup, cv::Mat &merged){
    //Lut to optimize
    int distance;
    int max;
    lookup=cv::Mat::zeros(images[0].rows, images[0].cols, CV_32SC1);;
    merged=cv::Mat::zeros(images[0].rows, images[0].cols, CV_8UC1);
    for (auto i=0; i<images[0].rows; i++){
        for (auto j=0; j<images[0].cols; j++){
            max=0;
            distance=0;
            for (auto it=images.begin();it<images.end();it++){
                distance=std::distance(images.begin(),it);
                if (max <= int(it->at<uchar>(i,j))){
                    max = int(it->at<uchar>(i,j));
                    lookup.at<int>(i,j)=distance;
                }
            }
            merged.at<uchar>(i,j)=images[lookup.at<int>(i,j)].at<uchar>(i,j);
        }
    }
}


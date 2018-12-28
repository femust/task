#include "FocusStacking.h"

FocusStacking::FocusStacking(std::shared_ptr<Filter> filter){
    filter_=filter;
}
FocusStacking::~FocusStacking(){}
void FocusStacking::addInputImage(cv::Mat image){
    images_.emplace_back(image);
    if(debug_){
        std::cout << "Added image: " << images_.size() << std::endl;
    }
}
void FocusStacking::run(){}
void FocusStacking::debug(bool debug=false)
{}

#include "Filter.h"

std::shared_ptr<Filter> FilterFactory::make_filter(EdgeDetectionMethod method) {
    if (method == EdgeDetectionMethod::Laplace4) {
         std::cout << "Laplace4 method chosen" << std::endl;
         return std::make_shared<Laplace4>();
    }else if (method == EdgeDetectionMethod::Laplace8) {
        std::cout << "Laplace8 method chosen" << std::endl;
        return std::make_shared<Laplace8>();
    }else if (method == EdgeDetectionMethod::ZeroFilter) {
        std::cout << "Laplace8 method chosen" << std::endl;
        return std::make_shared<ZeroFilter>();
    }else {
        std::cout << "Wrong method" << std::endl;
        //throw error
    }
}

cv::Mat Filter::execute(cv::Mat image,cv::Mat kernel){
    cv::Mat filtered;
    cv::filter2D(image,filtered,-1,kernel);
    return filtered;
}








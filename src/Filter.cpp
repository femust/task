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

cv::Mat Filter::execute(cv::Mat image){
    cv::Mat filtered(image);
    std::vector< std::vector<int>> kernel=get_kernel();
    float sum;
    uchar x1,y1;
    std::cout << " KErnel will be printed" << std::endl;
    for(auto it=kernel.begin();it<kernel.end();it++)
    {
        for (auto it2=(*it).begin();it2<(*it).end();it2++)
        {
            std::cout << *it2 << " " ;
        }
        std::cout << std::endl;
    }
    std::cout << " image will be printed" << std::endl;
    std::cout << image << std::endl;


    //cv::filter2D(image,filtered,image.depth(),kernel,)



    return image;
}








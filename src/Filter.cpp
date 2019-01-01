#include "Filter.h"

std::shared_ptr<Filter> FilterFactory::make_filter(EdgeDetectionMethod method) {
    if (method == EdgeDetectionMethod::Laplace4) {
         std::cout << "Laplace4 method chosen." << std::endl;
         return std::make_shared<Laplace4>();
    }else if (method == EdgeDetectionMethod::Laplace8) {
        std::cout << "Laplace8 method chosen." << std::endl;
        return std::make_shared<Laplace8>();
    }else if (method == EdgeDetectionMethod::ZeroFilter) {
        std::cout << "Zero filter for debugging purposes." << std::endl;
        return std::make_shared<ZeroFilter>();
    }else {
        throw std::invalid_argument( "Wrong method");
    }
}

cv::Mat Filter::execute(cv::Mat image,cv::Mat kernel){
    cv::Mat filtered_temp(image.rows,image.cols,CV_32FC1);
    cv::Mat output = cv::Mat(image.rows, image.cols, CV_8UC1);
    float sum_temp;

    for (int i=0;i<image.rows;i++){
        for (int j=0;j<=image.cols;j++){
            if (i==0 || j==0 || i ==image.rows-1 || j ==image.cols-1){
                output.at<uchar>(i,j) = 0;
                continue;
            }
            sum_temp=0;
            for (int m=0;m<kernel.rows;m++){
                for (int n=0;n<kernel.cols;n++){
                    sum_temp=sum_temp+kernel.at<float>(m,n)*int(image.at<uchar>(i+m-1,j+n-1));
                }
            }
            filtered_temp.at<float>(i,j)=sum_temp;
            output.at<uchar>(i,j) = (sum_temp>255.0) ? 255.0 : ((sum_temp<0.0) ? 0.0 : static_cast<uchar>(sum_temp));
        }
    }
    return output;
}










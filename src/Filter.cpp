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
    cv::Mat filtered2(image.rows,image.cols,CV_32FC1);
    cv::Mat output = cv::Mat(image.rows, image.cols, CV_8UC1);

    int image_height=image.rows;
    int image_width=image.cols;
    int kernel_height=kernel.rows;
    int kernel_width=kernel.cols;
    float sum;

    for (int i=0;i<image_height;i++){
        for (int j=0;j<=image_width;j++){
            if (i==0 || j==0 || i ==image_height-1 || j ==image_width-1){
                output.at<uchar>(i,j) = 0;
                continue;
            }
            sum=0;
            for (int m=0;m<kernel_height;m++){
                for (int n=0;n<kernel_width;n++){
                    sum=sum+kernel.at<float>(m,n)*int(image.at<uchar>(i+m-1,j+n-1));
                }
            }
            filtered2.at<float>(i,j)=sum;
            output.at<uchar>(i,j) = (sum>255.0) ? 255.0 : ((sum<0.0) ? 0.0 : static_cast<uchar>(sum));
        }
    }
    return output;
    }










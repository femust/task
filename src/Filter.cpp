#include "Filter.h"

Filter::Filter(){}
Filter::~Filter(){}
void Filter::set_filter(EdgeDetectionMethod method) {
    if (method == EdgeDetectionMethod::Laplace4) {
         std::cout << "Laplace4 method chosen" << std::endl;
         filter_=std::make_shared<Laplace4>();
    }else if (method == EdgeDetectionMethod::Laplace8) {
        std::cout << "Laplace8 method chosen" << std::endl;
        filter_= std::make_shared<Laplace8>();
    }else {
        std::cout << "Wrong method" << std::endl;
        //throw error
    }
}

Laplace4::Laplace4(){}
Laplace4::~Laplace4(){}
void Laplace4::display(){
    std::cout << "Kernel Laplace4" << std::endl;
    for (auto it=kernel_.begin();it<kernel_.end();it++){
        for (auto it2=it[0].begin(); it2 < it[0].end(); it2++){
            std::cout << *it2 << " ";
        }
        std::cout  << std::endl;
    }
}

Laplace8::Laplace8(){}
Laplace8::~Laplace8(){}
void Laplace8::display(){
    std::cout << "Kernel Laplace8" << std::endl;
    for (auto it=kernel_.begin();it<kernel_.end();it++){
        for (auto it2=it[0].begin(); it2 < it[0].end(); it2++){
            std::cout << *it2 << " ";
        }
        std::cout  << std::endl;
    }
}






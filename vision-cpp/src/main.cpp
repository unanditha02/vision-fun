#include <iostream>
#include <fstream>
#include "image_reader.hpp"

int main(int argc, char** argv)  {
    try {
        if (argc < 3) {
            std::cerr << "Provide arguments: <filepath> <grayscale>" << std::endl;
            return 1;
        }
        std::string filename = argv[1];
        bool grayscale = true ? (std::string(argv[2]) == "grayscale") : false;
        
        std::shared_ptr<ImageReader> my_img = std::make_shared<ImageReader>(ImageReader());

        // Setting up variables to calculate processing time
        clock_t time_begin;
        clock_t time_end;
        
        std::cout << "Reading image ... " << argv[2] << std::endl;
        time_begin = clock();
        my_img->read_image(filename, grayscale);

        time_end = clock();
        std::cout << "Time taken: " << double(time_end - time_begin) / CLOCKS_PER_SEC << " seconds" << std::endl;

        my_img->print_details();
    }
    catch(cv::Exception& e) {
        const char* err_msg = e.what();
        std::cout << "exception caught: " << err_msg << std::endl;
    }
    return 0;
}

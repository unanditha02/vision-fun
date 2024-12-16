# include "image_reader.hpp"

void ImageReader::read_image(std::string filepath, bool grayscale=true){
    cv::Mat img_cv = cv::imread(filepath, cv::IMREAD_COLOR); 
    if (img_cv.empty()) {
        std::cerr << "Could not read file. Check filepath. " << filepath << std::endl;
    }

    cv::imshow("Original Image", img_cv);
    cv::waitKey(0);
    
    rows = img_cv.rows;
    cols = img_cv.cols;
    channels = img_cv.channels();
    img_data.reserve(rows * cols * channels);

    if (img_cv.isContinuous()) {
        std::cout << "Image is continuous " << img_cv.total() << std::endl;
        img_data.assign(img_cv.datastart, img_cv.dataend);
    } 
    else {
        for (int i = 0; i < rows; ++i) {
            img_data.insert(img_data.end(), img_cv.ptr<uchar>(i), img_cv.ptr<uchar>(i)+img_cv.cols*channels);
        }
    }
}

void ImageReader::print_details(void) {
    std::cout << "This image object holds an image of size (" << rows << ", " << cols << ")" << std::endl;
}
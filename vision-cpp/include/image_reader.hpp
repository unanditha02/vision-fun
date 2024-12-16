#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp> // Include OpenCV headers

class ImageReader {
    private:
        int rows, cols, channels;

    public:
        std::vector<unsigned char> img_data;
        std::vector<std::vector<uchar>> v;

        void read_image(std::string filepath, bool grayscale);
        void display_image(void);
        void print_details(void);
};
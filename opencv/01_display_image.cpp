#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    std::string imageName("HappyFish.jpg");
    if (argc > 1)
    {
        imageName = argv[1];
    }
    try
    {
        std::string temp = cv::samples::findFile(imageName);
        imageName = temp;
    }
    catch (...)
    {
    }

    cv::Mat image;
    std::cout << "Image name: " << imageName << std::endl;
    image = cv::imread(imageName, cv::IMREAD_COLOR);
    if (image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::namedWindow("DIsplay window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}
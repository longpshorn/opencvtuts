#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    char *imageName = argv[1];

    cv::Mat image;
    image = cv::imread(imageName, cv::IMREAD_COLOR);
    if (argc < 2 || !image.data)
    {
        printf("No image data\n");
        return -1;
    }

    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);

    cv::imwrite("./gray_image.jpg", gray_image);

    cv::namedWindow(imageName, cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Gray Image", cv::WINDOW_AUTOSIZE);

    cv::imshow(imageName, image);
    cv::imshow("Gray Image", gray_image);

    cv::waitKey(0);
    return 0;
}
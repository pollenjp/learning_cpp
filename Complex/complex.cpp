/**
 *  @author pollenjp
 *  @email polleninjp@gmail.com
 */

#include <iostream>
#include <complex>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
  cv::Mat A = cv::Mat(/* int rows= */ 4,
                      /* int cols= */ 4,
                      /* int type= */ cv::DataType<std::complex<double>>::type,
                      /* */ CV_RGB(50, 50, 50));

  cv::Mat B = cv::Mat_<std::complex<double>>(3, 3);

  std::cout << "rows     : " << A.rows        << std::endl
            << "cols     : " << A.cols        << std::endl
            << "depth    : " << A.depth()     << std::endl
            << "CV_64F   : " << CV_64F        << std::endl
            << "channels : " << A.channels()  << std::endl
            << "type     : " << A.type()      << std::endl
            << "CV_64FC2 : " << CV_64FC2      << std::endl;
 
  std::cout << "rows     : " << B.rows        << std::endl
            << "cols     : " << B.cols        << std::endl
            << "depth    : " << B.depth()     << std::endl
            << "CV_64F   : " << CV_64F        << std::endl
            << "channels : " << B.channels()  << std::endl
            << "type     : " << B.type()      << std::endl
            << "CV_64FC2 : " << CV_64FC2      << std::endl;

  for (int y = 0; y < B.rows; y++){
    for (int x = 0; x < B.cols; x++){
      B.at<std::complex<double>>(x,y) = std::complex<double>(5+x, 50+y);
    }
  }
  for (int y = 0; y < B.rows; y++){
    for (int x = 0; x < B.cols; x++){
      std::cout << B.at<std::complex<double>>(x,y) << std::endl;
    }
  }

  return 0;
}


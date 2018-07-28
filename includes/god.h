#ifndef GOD_H
#define GOD_H

#include "opencv2/imgproc.hpp"


class God
{
  public:
  cv::String name;
  cv::Scalar color;

  public:
  God(cv::String const &name, cv::Scalar const &color);
};

#endif

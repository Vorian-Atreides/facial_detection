#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "detector.h"

Detector::Detector(std::string const &fileName)
{
  this->algo.load(fileName);
}

bool Detector::isLoaded() const
{
  return !this->algo.empty();
}

void Detector::localise(cv::Mat const &frame, std::vector<cv::Rect> &faces)
{
  cv::Mat frameGray;
  cv::cvtColor(frame, frameGray, cv::COLOR_BGR2GRAY);
  cv::equalizeHist(frameGray, frameGray);
  this->algo.detectMultiScale(frameGray, faces, 1.1, 2, 0, cv::Size(100, 100));
}
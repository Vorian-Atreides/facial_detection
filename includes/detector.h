#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>

#include "opencv2/objdetect.hpp"

class Detector
{
  private:
    cv::CascadeClassifier algo;

  public:
    Detector(std::string const &fileName);
    bool isLoaded() const;
    void localise(cv::Mat const &frame, std::vector<cv::Rect> &faces);
};

#endif

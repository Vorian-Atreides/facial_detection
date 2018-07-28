#ifndef STREAM_H
#define STREAM_H

#include <string>
#include "opencv2/videoio.hpp"

#include "detector.h"
#include "renderer.h"

class Stream
{
  private:
    cv::VideoCapture capture;

  public:
    Stream(int device);
    Stream(std::string const &fileName);
    ~Stream();
    void run(Detector &detector, Renderer const &renderer);
    bool isOpen() const;
};

#endif

#ifndef RENDERER_H
#define RENDERER_H

#include "opencv2/objdetect.hpp"
#include "god.h"

class Renderer
{
  private:
    std::vector<God> gods;

  public:
    Renderer();
    void render(cv::Mat &frame, std::vector<cv::Rect> const &faces) const;
};

#endif

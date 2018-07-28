#include "opencv2/imgproc.hpp"

#include "renderer.h"

Renderer::Renderer()
{
  God arr[] = {
    God("Ma'at", cv::Scalar(221,221,221)),
    God("Ash", cv::Scalar(221,221,221)),
    God("Babi", cv::Scalar(221,221,221)),
    God("Seth", cv::Scalar(187,221,255)),
    God("Hatmehit", cv::Scalar(238,238,187)),
    God("Nut", cv::Scalar(238,238,187)),
    God("Aten", cv::Scalar(238,238,187)),
    God("Hapi", cv::Scalar(255,204,204)),
    God("Imhotep", cv::Scalar(255,204,204)),
    God("Anubis", cv::Scalar(255,204,204)),
    God("Maftet", cv::Scalar(221,187,255)),
    God("Bastet", cv::Scalar(221,187,255)),
    God("Serqet", cv::Scalar(221,187,255)),
    God("Hathor", cv::Scalar(221,187,255)),
    God("Anuket", cv::Scalar(221,187,255)),
    God("Khepry", cv::Scalar(221,187,255)),
    God("Aker", cv::Scalar(221,187,255)),
    God("Atum", cv::Scalar(221,187,255)),
    God("Apis", cv::Scalar(221,187,255))
  };
  std::vector<God> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
  this->gods = vec;
}

void Renderer::render(cv::Mat &frame, std::vector<cv::Rect> const &faces) const {
  int godId = rand() % this->gods.size();
  God const &god = this->gods[godId];
  // cv::Scalar color(0, 0, 255);
  for (int i = 0; i < faces.size(); i++)
  {
    cv::Rect face = faces[i];
    cv::Point2i textPosition(face.x, face.y - 10);
    cv::putText(frame, god.name, textPosition, 0, 0.6, god.color, 1);
    cv::rectangle(frame, face, god.color, 5);
  }
}
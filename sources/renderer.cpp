#include "opencv2/imgproc.hpp"

#include "renderer.h"

Renderer::Renderer()
{
  // God cats[] = {
  //   God("Seth", cv::Scalar(187,221,255)),
  //   God("Sekhmet", cv::Scalar(187,221,255)),
  //   God("Anubis", cv::Scalar(255,204,204)),
  //   God("Bastet", cv::Scalar(221,187,255)),
  // };
  // God humans[] = {
  //   God("Ma'at", cv::Scalar(221,221,221)),
  //   God("Nut", cv::Scalar(238,238,187)),
  //   God("Aten", cv::Scalar(238,238,187)),
  //   God("Hatmehyt", cv::Scalar(238,238,187)),
  // };
  // God others[] = {
  //   God("Atum", cv::Scalar(221,187,255)),
  //   God("Neith", cv::Scalar(221,187,255)),
  //   God("Khonsou", cv::Scalar(221,187,255)),
  //   God("Bes", cv::Scalar(221,187,255)),
  // };
  // std::vector<God> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
  // this->gods = vec;
}

void Renderer::render(cv::Mat &frame, std::vector<cv::Rect> const &faces, std::vector<God> const &gods) const {
  int godId = rand() % gods.size();
  God const &god = gods[godId];
  // cv::Scalar color(0, 0, 255);
  for (int i = 0; i < faces.size(); i++)
  {
    cv::Rect face = faces[i];
    cv::Point2i textPosition(face.x, face.y - 10);
    cv::putText(frame, god.name, textPosition, 0, 0.6, god.color, 1);
    cv::rectangle(frame, face, god.color, 5);
  }
}
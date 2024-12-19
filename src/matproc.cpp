#include "matproc.h"
#include <cmath>
#include <vector>
MatProc::MatProc() : t(0), array(nullptr), R(1000) {}
void MatProc::setArray(std::vector<Eigen::Vector2d> *p) {
  t = 0;
  array = p;
  size_t n = array->size();

  for (size_t i = 0; i < n; ++i) {
    const Eigen::Vector2d &p1 = array->at(i);
    const Eigen::Vector2d &p2 = array->at((i + 1) % n);
    Eigen::Vector2d tangent = (p2 - p1).normalized();
    Eigen::Vector2d normal(-tangent.y(), tangent.x());
    Eigen::Vector2d center = Eigen::Vector2d::Zero();

    Eigen::Vector2d toCenter = (center - p1).normalized();
    if (normal.dot(toCenter) < 0) {
      normal = -normal;
    }

    v.push_back(normal);
  }
}
double MatProc::G(Eigen::Vector2d x, Eigen::Vector2d y) {
  return std::log(std::pow((x - y).norm(), 2)) -
         std::log(std::pow((y * R / std::pow(y.norm(), 2) - x).norm(), 2)) -
         std::log(R * R / y.norm() / y.norm());
}
double MatProc::getlnL() {
  double perimeter = 0.;
  size_t n = array->size();

  for (size_t i = 0; i < n; ++i) {
    const Eigen::Vector2d &p1 = array->at(i);
    const Eigen::Vector2d &p2 = array->at((i + 1) % n);
    perimeter += (p2 - p1).norm();
  }

  return std::log(perimeter);
}
double MatProc::getlnA() {
  double area = 0.;
  size_t n = array->size();

  for (size_t i = 0; i < n; ++i) {
    const Eigen::Vector2d &p1 = array->at(i);
    const Eigen::Vector2d &p2 = array->at((i + 1) % n);
    area += p1.x() * p2.y() - p2.x() * p1.y();
  }

  return std::log(std::abs(area) / 2.);
}
bool MatProc::isReady() { return array != nullptr; }
unsigned MatProc::gett() { return t; }
void MatProc::updateArray() {
  t++;
  size_t n = array->size();
  std::vector<Eigen::Vector2d> tmp(n);
  for (size_t i = 0; i < n; ++i) {
    double sc = 0.;
    for (size_t j = 0; j < n; ++j) {
      const Eigen::Vector2d &p1 = array->at(j);
      const Eigen::Vector2d &p2 = array->at((j + 1) % n);
      sc += (p1 - p2).norm() * (G(array->at(i), p1) - G(array->at(i), p2)) /
            0.01 * v[i].norm();
    }
    tmp[i] = sc * v[i].normalized();
  }
  for (size_t i = 0; i < n; ++i) {
    v[i] = tmp[i];
    array->at(i) += v[i];
  }
}

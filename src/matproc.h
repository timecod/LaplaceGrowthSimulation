#pragma once
#include <Eigen/Dense>
#include <QObject>
#include <qtmetamacros.h>
#include <vector>

class MatProc : public QObject {
  Q_OBJECT
  std::vector<Eigen::Vector2d> *array;
  std::vector<Eigen::Vector2d> v;
  unsigned t;
  double R;
  double G(Eigen::Vector2d x, Eigen::Vector2d y);
public slots:

  void updateArray();

public:
  MatProc();
  void setArray(std::vector<Eigen::Vector2d> *);
  bool isReady();
  double getlnA();
  double getlnL();
  unsigned gett();
};

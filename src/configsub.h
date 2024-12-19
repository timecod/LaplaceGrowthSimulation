#pragma once

#include <Eigen/Dense>
#include <QWidget>
#include <qcontainerfwd.h>
#include <vector>
namespace Ui {
class ConfigSub;
}
class ConfigSub : public QWidget {
  Q_OBJECT

public:
  explicit ConfigSub(QWidget *parent = nullptr);
  ~ConfigSub();
  void setArray(std::vector<Eigen::Vector2d> *);
signals:
  void updatedArray();
private slots:
  void browse();
  void process();

private:
  Ui::ConfigSub *ui;
  QString file;
  std::vector<Eigen::Vector2d> *array;
};

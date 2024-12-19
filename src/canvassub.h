#pragma once

#include <Eigen/Dense>
#include <QValueAxis>
#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <qtmetamacros.h>
class CanvasSub : public QWidget {
  Q_OBJECT

public:
  explicit CanvasSub(QWidget *parent = nullptr);
  ~CanvasSub();

  void setData(std::vector<Eigen::Vector2d> *);
public slots:
  void updateCanvas();

private:
  QChart *chart;
  QLineSeries *series;
  QChartView *chartView;
  std::vector<Eigen::Vector2d> *array;
};

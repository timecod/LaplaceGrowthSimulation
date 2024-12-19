#include "canvassub.h"
#include <Eigen/Dense>
#include <QVBoxLayout>
#include <qlogging.h>
#include <vector>
CanvasSub::CanvasSub(QWidget *parent)
    : QWidget(parent), chart(new QChart()), series(new QLineSeries()),
      chartView(new QChartView(chart)) {
  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(chartView);
  setLayout(layout);
  chart->legend()->hide();
  // qDebug() << "fail"; chart->addSeries(series);
  qDebug() << "nofail";
  chart->createDefaultAxes();
  chart->setTitle("Simulate");
  chartView->setRenderHint(QPainter::Antialiasing);
}

CanvasSub::~CanvasSub() {}

void CanvasSub::setData(std::vector<Eigen::Vector2d> *points) {
  array = points;
}
void CanvasSub::updateCanvas() {
  series->clear();
  for (auto i : *array) {
    series->append(i.x(), i.y());
  }
}

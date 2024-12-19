#pragma once

#include "canvassub.h"
#include "configsub.h"
#include "matproc.h"
#include <Eigen/Dense>
#include <QMainWindow>
#include <QMdiArea>
#include <QXYSeries>
#include <qobjectdefs.h>
#include <qtmetamacros.h>
#include <vector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
private slots:
  void startMat();
  void stopMat();
  void setMat();

private:
  Ui::MainWindow *ui;
  QMdiArea *mdiArea;
  ConfigSub *configSub;
  std::vector<Eigen::Vector2d> *array;
  CanvasSub *canvas;
  MatProc *mat;
  QTimer *timer;
};

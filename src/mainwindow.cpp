#include "mainwindow.h"
#include "canvassub.h"
#include "configsub.h"
#include "ui_mainwindow.h"
#include <Eigen/Dense>
#include <QAction>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QTimer>
#include <qlogging.h>
#include <qmessagebox.h>
#include <qtimer.h>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mdiArea(new QMdiArea),
      configSub(new ConfigSub), canvas(new CanvasSub),
      array(new std::vector<Eigen::Vector2d>), mat(new MatProc),
      timer(new QTimer) {
  ui->setupUi(this);
  configSub->setArray(array);
  canvas->setData(array);
  QMenuBar *menuBar = this->menuBar();
  QMenu *processMenu = menuBar->addMenu(tr("&Procces"));
  QAction *aStart = new QAction(tr("&Start"), this);
  QAction *aStop = new QAction(tr("&Stop"), this);
  processMenu->addAction(aStart);
  processMenu->addAction(aStop);
  setCentralWidget(mdiArea);
  QMdiSubWindow *subWindow = mdiArea->addSubWindow(configSub);
  subWindow->setWindowTitle("Set config");
  subWindow->show();
  QMdiSubWindow *subWindow2 = mdiArea->addSubWindow(canvas);
  subWindow2->setWindowTitle("Canvas");
  subWindow2->show();
  connect(configSub, &ConfigSub::updatedArray, canvas,
          &CanvasSub::updateCanvas);
  connect(configSub, &ConfigSub::updatedArray, this, &MainWindow::setMat);
  connect(timer, &QTimer::timeout, mat, &MatProc::updateArray);
  connect(aStart, &QAction::triggered, this, &MainWindow::startMat);
  connect(aStop, &QAction::triggered, this, &MainWindow::stopMat);
  connect(timer, &QTimer::timeout, this, &MainWindow::debugD);
}
void MainWindow::setMat() { mat->setArray(array); }
void MainWindow::startMat() {
  if (!mat->isReady()) {
    QMessageBox::information(this, "Error", "No configuration");
    return;
  }
  timer->start();
}
void MainWindow::stopMat() { timer->stop(); }
void MainWindow::debugD() {
  qDebug() << "Step " << mat->gett() << ": D = " << mat->getlnA() << " / "
           << mat->getlnL() << " = " << mat->getlnA() / mat->getlnL();
}
MainWindow::~MainWindow() { delete ui; }

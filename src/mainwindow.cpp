#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mdiArea(new QMdiArea),
      subWindow1(new QMdiSubWindow), subWindow2(new QMdiSubWindow),
      textEdit1(new QTextEdit), textEdit2(new QTextEdit) {
  ui->setupUi(this);

  setCentralWidget(mdiArea);

  subWindow1->setWidget(textEdit1);
  subWindow2->setWidget(textEdit2);

  mdiArea->addSubWindow(subWindow1);
  mdiArea->addSubWindow(subWindow2);

  subWindow1->setWindowTitle("SubWindow 1");
  subWindow2->setWindowTitle("SubWindow 2");

  textEdit1->setText("This is the first MDI subwindow.");
  textEdit2->setText("This is the second MDI subwindow.");

  mdiArea->tileSubWindows();
}

MainWindow::~MainWindow() { delete ui; }

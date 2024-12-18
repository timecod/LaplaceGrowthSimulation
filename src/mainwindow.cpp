#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qwidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mdiArea(new QMdiArea),
      subWindow1(), subWindow2(new QMdiSubWindow), textEdit1(new QTextEdit),
      textEdit2(new QTextEdit) {
  ui->setupUi(this);

  setCentralWidget(mdiArea);
  QWidget *ww = new QWidget;
  QVBoxLayout *layout = new QVBoxLayout(ww);
  QPushButton *button = new QPushButton("clik me", ww);
  layout->addWidget(button);
  subWindow2->setWidget(textEdit2);
  subWindow1 = mdiArea->addSubWindow(ww);
  mdiArea->addSubWindow(subWindow2);

  subWindow1->setWindowTitle("SubWindow button");
  subWindow2->setWindowTitle("SubWindow 2");

  textEdit1->setText("This is the first MDI subwindow.");
  textEdit2->setText("This is the second MDI subwindow.");

  mdiArea->tileSubWindows();
  connect(button, &QPushButton::clicked, this, &MainWindow::click);
}
void MainWindow::click() {
  QMessageBox::information(this, "clixk", "button click");
}
MainWindow::~MainWindow() { delete ui; }

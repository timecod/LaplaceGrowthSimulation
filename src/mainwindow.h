#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  QMdiArea *mdiArea;
  QMdiSubWindow *subWindow1;
  QMdiSubWindow *subWindow2;
  QTextEdit *textEdit1;
  QTextEdit *textEdit2;
};

#endif // MAINWINDOW_H

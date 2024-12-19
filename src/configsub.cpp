#include "configsub.h"
#include "Eigen/src/Core/Matrix.h"
#include "ui_configsub.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <qmessagebox.h>
#include <qtmetamacros.h>
#include <vector>
ConfigSub::ConfigSub(QWidget *parent) : QWidget(parent), ui(new Ui::ConfigSub) {
  ui->setupUi(this);

  connect(ui->browseButton, &QPushButton::clicked, this, &ConfigSub::browse);
  connect(ui->processButton, &QPushButton::clicked, this, &ConfigSub::process);
}

ConfigSub::~ConfigSub() { delete ui; }
void ConfigSub::setArray(std::vector<Eigen::Vector2d> *p) { array = p; }
void ConfigSub::browse() {
  file = QFileDialog::getOpenFileName(this, "Select File");
  if (!file.isEmpty()) {
    ui->filePathLabel->setText(file);
  }
}

void ConfigSub::process() {
  if (file.isEmpty()) {
    QMessageBox::warning(this, "Warning", "No file selected!");
    return;
  }
  std::ifstream f(file.toStdString());

  if (!f.is_open()) {
    QMessageBox::warning(this, "Error", "Error opening file");
    return;
  }

  std::string line;
  array->clear();
  while (std::getline(f, line)) {
    std::istringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    if (tokens.size() == 2) {
      Eigen::Vector2d p;
      p(0) = std::stod(tokens[0]);
      p(1) = std::stod(tokens[1]);
      array->push_back(p);
    }
  }

  f.close();
  // Process the selected file
  QMessageBox::information(this, "File Processed",
                           "File processed successfully!");
  emit updatedArray();
}

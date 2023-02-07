#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QPushButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

class MainWindow : public QWidget {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow() = default;
  bool getDigits();
  void setDigits(bool a);

 private:
  QGridLayout* defLayout;
  QGridLayout* simpleLayout;
  QGridLayout* engLayout;
  QGridLayout* mainLayout;
  QWidget* defWidget;
  QWidget* simpleWidget;
  QWidget* engWidget;
  QRadioButton* simpleRButton;
  QRadioButton* engRButton;
  QLineEdit* lineEdit;
  bool dot_one = false;
  bool digits = true;

  void CreateDef();
  void CreateSimple();
  void CreateEng();
  void SimpleMode();
  void EngMode();
  void OneDot(bool b);

 private slots:
  void Clear();
  void Equal();
  void Switched();
  void numClicked();
  void DotClicked();
  void UnaryFuncClicked();
  void BinaryFuncClicked();
};

#endif  // MAINWINDOW_H

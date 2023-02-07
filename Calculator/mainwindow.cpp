#include "mainwindow.h"

#include <cctype>
#include <cmath>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  if (objectName().isEmpty()) setObjectName(QString::fromUtf8("MainWindow"));
  resize(160, 160);
  QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
  setSizePolicy(sizePolicy);

  simpleRButton = new QRadioButton(this);
  simpleRButton->setObjectName(QString::fromUtf8("SimpleRadioButton"));
  simpleRButton->setGeometry(QRect(0, 0, 84, 22));

  engRButton = new QRadioButton(this);
  engRButton->setObjectName(QString::fromUtf8("EngRadioButton"));
  engRButton->setGeometry(QRect(0, 0, 105, 22));

  QFont font;
  font.setPointSize(14);
  font.setBold(true);

  lineEdit = new QLineEdit(this);
  lineEdit->setFont(font);
  lineEdit->setObjectName(QString::fromUtf8("LineEdit"));
  lineEdit->setGeometry(QRect(0, 0, 108, 22));
  lineEdit->setAlignment(Qt::AlignRight);

  simpleRButton->setText(tr("Обычный"));
  engRButton->setText(tr("Инженерный"));
  QMetaObject::connectSlotsByName(this);

  setWindowTitle(tr("Калькулятор (обычный)"));
  setMinimumSize(500, 400);
  setMaximumSize(500, 400);

  lineEdit->setPlaceholderText("0");
  lineEdit->setReadOnly(true);
  simpleRButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  engRButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  simpleRButton->setChecked(true);
  connect(simpleRButton, SIGNAL(toggled(bool)), SLOT(Switched()));

  CreateSimple();
  CreateEng();
  CreateDef();
  SimpleMode();
}

void MainWindow::Switched() {
  simpleWidget->setParent(this);
  engWidget->setParent(this);
  if (!simpleRButton->isChecked()) {
    delete mainLayout;
    setWindowTitle(tr("Калькулятор(инженерный)"));
    EngMode();
  } else {
    delete mainLayout;
    setWindowTitle(tr("Калькулятор(обычный)"));
    SimpleMode();
  }
}

void MainWindow::SimpleMode() {
  mainLayout = new QGridLayout;
  mainLayout->setSpacing(2);
  engWidget->hide();
  mainLayout->addWidget(defWidget, 0, 0, 1, 3);
  mainLayout->addWidget(simpleWidget, 1, 0, 2, 3);
  setLayout(mainLayout);
}

void MainWindow::EngMode() {
  mainLayout = new QGridLayout;
  mainLayout->setSpacing(2);
  mainLayout->addWidget(defWidget, 0, 0, 1, 9);
  mainLayout->addWidget(engWidget, 1, 0, 2, 4);
  mainLayout->addWidget(simpleWidget, 1, 4, 2, 5);
  engWidget->show();
  setLayout(mainLayout);
}

void MainWindow::CreateSimple() {
  QPushButton* pushButton0 = new QPushButton("0", this);
  QPushButton* pushButton1 = new QPushButton("1", this);
  QPushButton* pushButton2 = new QPushButton("2", this);
  QPushButton* pushButton3 = new QPushButton("3", this);
  QPushButton* pushButton4 = new QPushButton("4", this);
  QPushButton* pushButton5 = new QPushButton("5", this);
  QPushButton* pushButton6 = new QPushButton("6", this);
  QPushButton* pushButton7 = new QPushButton("7", this);
  QPushButton* pushButton8 = new QPushButton("8", this);
  QPushButton* pushButton9 = new QPushButton("9", this);
  QPushButton* pushButtonDot = new QPushButton(".", this);
  QPushButton* pushButtonPlus = new QPushButton("+", this);
  QPushButton* pushButtonMinus = new QPushButton(QString::fromUtf8("-"), this);
  QPushButton* pushButtonMult =
      new QPushButton(QString::fromUtf8("\u00D7"), this);
  QPushButton* pushButtonDivide =
      new QPushButton(QString::fromUtf8("\u00F7"), this);
  QPushButton* pushButtonEquals = new QPushButton("=", this);
  QPushButton* pushButtonSqrt =
      new QPushButton(QString::fromUtf8("\u221Ax"), this);
  QPushButton* pushButtonInvert = new QPushButton("1/x", this);
  QPushButton* pushButtonPlusMinus =
      new QPushButton(QString::fromUtf8("\u00B1"), this);

  QString style =
      "background-color: #E6E6E6;"
      "border-style: outset;"
      "border-width: 2px;"
      "border-radius: 10px;"
      "border-color: beige;"
      "font: bold 14px;"
      "padding: 6px;";

  pushButton0->setStyleSheet(style);
  pushButton1->setStyleSheet(style);
  pushButton2->setStyleSheet(style);
  pushButton3->setStyleSheet(style);
  pushButton4->setStyleSheet(style);
  pushButton5->setStyleSheet(style);
  pushButton6->setStyleSheet(style);
  pushButton7->setStyleSheet(style);
  pushButton8->setStyleSheet(style);
  pushButton9->setStyleSheet(style);
  pushButtonPlus->setStyleSheet(style);
  pushButtonMinus->setStyleSheet(style);
  pushButtonDot->setStyleSheet(style);
  pushButtonMult->setStyleSheet(style);
  pushButtonDivide->setStyleSheet(style);
  pushButtonEquals->setStyleSheet(style);
  pushButtonPlusMinus->setStyleSheet(style);
  pushButtonInvert->setStyleSheet(style);
  pushButtonSqrt->setStyleSheet(style);

  QSizePolicy sPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  pushButton0->setSizePolicy(sPolicy);
  pushButton1->setSizePolicy(sPolicy);
  pushButton2->setSizePolicy(sPolicy);
  pushButton3->setSizePolicy(sPolicy);
  pushButton4->setSizePolicy(sPolicy);
  pushButton5->setSizePolicy(sPolicy);
  pushButton6->setSizePolicy(sPolicy);
  pushButton7->setSizePolicy(sPolicy);
  pushButton8->setSizePolicy(sPolicy);
  pushButton9->setSizePolicy(sPolicy);
  pushButtonPlus->setSizePolicy(sPolicy);
  pushButtonMinus->setSizePolicy(sPolicy);
  pushButtonDot->setSizePolicy(sPolicy);
  pushButtonMult->setSizePolicy(sPolicy);
  pushButtonDivide->setSizePolicy(sPolicy);
  pushButtonEquals->setSizePolicy(sPolicy);
  pushButtonPlusMinus->setSizePolicy(sPolicy);
  pushButtonInvert->setSizePolicy(sPolicy);
  pushButtonSqrt->setSizePolicy(sPolicy);

  simpleLayout = new QGridLayout(this);
  simpleLayout->setSpacing(4);
  simpleLayout->setContentsMargins(5, 0, 5, 5);

  simpleLayout->addWidget(pushButton7, 0, 0, 1, 1);
  simpleLayout->addWidget(pushButton8, 0, 1, 1, 1);
  simpleLayout->addWidget(pushButton9, 0, 2, 1, 1);
  simpleLayout->addWidget(pushButtonDivide, 0, 3, 1, 1);
  simpleLayout->addWidget(pushButtonSqrt, 0, 4, 1, 1);
  simpleLayout->addWidget(pushButton4, 1, 0, 1, 1);
  simpleLayout->addWidget(pushButton5, 1, 1, 1, 1);
  simpleLayout->addWidget(pushButton6, 1, 2, 1, 1);
  simpleLayout->addWidget(pushButtonMult, 1, 3, 1, 1);
  simpleLayout->addWidget(pushButtonInvert, 1, 4, 1, 1);
  simpleLayout->addWidget(pushButton1, 2, 0, 1, 1);
  simpleLayout->addWidget(pushButton2, 2, 1, 1, 1);
  simpleLayout->addWidget(pushButton3, 2, 2, 1, 1);
  simpleLayout->addWidget(pushButtonMinus, 2, 3, 1, 1);
  simpleLayout->addWidget(pushButtonEquals, 3, 4, 1, 1);
  simpleLayout->addWidget(pushButton0, 3, 0, 1, 2);
  simpleLayout->addWidget(pushButtonDot, 3, 2, 1, 1);
  simpleLayout->addWidget(pushButtonPlus, 3, 3, 1, 1);
  simpleLayout->addWidget(pushButtonPlusMinus, 2, 4, 1, 1);

  simpleWidget = new QWidget(this);
  simpleWidget->setLayout(simpleLayout);

  connect(pushButton0, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton1, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton2, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton3, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton4, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton5, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton6, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton7, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton8, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButton9, SIGNAL(clicked()), this, SLOT(numClicked()));
  connect(pushButtonPlus, SIGNAL(clicked()), this, SLOT(BinaryFuncClicked()));
  connect(pushButtonMinus, SIGNAL(clicked()), this, SLOT(BinaryFuncClicked()));
  connect(pushButtonMult, SIGNAL(clicked()), this, SLOT(BinaryFuncClicked()));
  connect(pushButtonDivide, SIGNAL(clicked()), this, SLOT(BinaryFuncClicked()));
  connect(pushButtonSqrt, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonDot, SIGNAL(clicked()), this, SLOT(DotClicked()));
  connect(pushButtonEquals, SIGNAL(clicked()), this, SLOT(Equal()));
  connect(pushButtonInvert, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonPlusMinus, SIGNAL(clicked()), this,
          SLOT(UnaryFuncClicked()));
}

void MainWindow::CreateEng() {
  QPushButton* pushButtonSinh = new QPushButton("sinh", this);
  QPushButton* pushButtonSin = new QPushButton("sin", this);
  QPushButton* pushButtonExp =
      new QPushButton(QString::fromUtf8("e\u207F"), this);
  QPushButton* pushButtonXSq =
      new QPushButton(QString::fromUtf8("x\u00B2"), this);
  QPushButton* pushButtonCosh = new QPushButton("cosh", this);
  QPushButton* pushButtonCos = new QPushButton("cos", this);
  QPushButton* pushButtonLn = new QPushButton("ln", this);
  QPushButton* pushButtonXCubed =
      new QPushButton(QString::fromUtf8("x\u00B3"), this);
  QPushButton* pushButtonTanh = new QPushButton("tanh", this);
  QPushButton* pushButtonTan = new QPushButton("tan", this);
  QPushButton* pushButtonLog = new QPushButton("log", this);
  QPushButton* pushButtonXNed =
      new QPushButton(QString::fromUtf8("x\u207F"), this);
  QPushButton* pushButtonFact = new QPushButton("n!", this);
  QPushButton* pushButtonPi =
      new QPushButton(QString::fromUtf8("\u03C0"), this);
  QPushButton* pushButtonCubeRoot =
      new QPushButton(QString::fromUtf8("\u00B3\u221A"), this);
  QPushButton* pushButtonNRoot =
      new QPushButton(QString::fromUtf8("\u207F\u221A"), this);

  QString style =
      "background-color: #E6E6E6;"
      "border-style: outset;"
      "border-width: 2px;"
      "border-radius: 10px;"
      "border-color: beige;"
      "font: bold 14px;"
      "padding: 6px;";

  pushButtonSin->setStyleSheet(style);
  pushButtonExp->setStyleSheet(style);
  pushButtonXSq->setStyleSheet(style);
  pushButtonCos->setStyleSheet(style);
  pushButtonLn->setStyleSheet(style);
  pushButtonXCubed->setStyleSheet(style);
  pushButtonTan->setStyleSheet(style);
  pushButtonLog->setStyleSheet(style);
  pushButtonXNed->setStyleSheet(style);
  pushButtonPi->setStyleSheet(style);
  pushButtonFact->setStyleSheet(style);
  pushButtonCubeRoot->setStyleSheet(style);
  pushButtonNRoot->setStyleSheet(style);
  pushButtonSinh->setStyleSheet(style);
  pushButtonCosh->setStyleSheet(style);
  pushButtonTanh->setStyleSheet(style);

  QSizePolicy sPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  pushButtonSin->setSizePolicy(sPolicy);
  pushButtonExp->setSizePolicy(sPolicy);
  pushButtonXSq->setSizePolicy(sPolicy);
  pushButtonCos->setSizePolicy(sPolicy);
  pushButtonLn->setSizePolicy(sPolicy);
  pushButtonXCubed->setSizePolicy(sPolicy);
  pushButtonTan->setSizePolicy(sPolicy);
  pushButtonLog->setSizePolicy(sPolicy);
  pushButtonXNed->setSizePolicy(sPolicy);
  pushButtonPi->setSizePolicy(sPolicy);
  pushButtonFact->setSizePolicy(sPolicy);
  pushButtonCubeRoot->setSizePolicy(sPolicy);
  pushButtonNRoot->setSizePolicy(sPolicy);
  pushButtonSinh->setSizePolicy(sPolicy);
  pushButtonCosh->setSizePolicy(sPolicy);
  pushButtonTanh->setSizePolicy(sPolicy);

  engLayout = new QGridLayout(this);
  engLayout->setSpacing(4);
  engLayout->setContentsMargins(5, 0, 2, 5);

  engLayout->addWidget(pushButtonSin, 0, 0, 1, 1);
  engLayout->addWidget(pushButtonXSq, 1, 2, 1, 1);
  engLayout->addWidget(pushButtonCos, 0, 2, 1, 1);
  engLayout->addWidget(pushButtonXCubed, 1, 3, 1, 1);
  engLayout->addWidget(pushButtonTan, 1, 0, 1, 1);
  engLayout->addWidget(pushButtonLog, 3, 0, 1, 1);
  engLayout->addWidget(pushButtonXNed, 2, 0, 1, 1);
  engLayout->addWidget(pushButtonPi, 3, 2, 1, 1);
  engLayout->addWidget(pushButtonFact, 3, 3, 1, 1);
  engLayout->addWidget(pushButtonCubeRoot, 2, 3, 1, 1);
  engLayout->addWidget(pushButtonNRoot, 2, 2, 1, 1);
  engLayout->addWidget(pushButtonExp, 2, 1, 1, 1);
  engLayout->addWidget(pushButtonLn, 3, 1, 1, 1);
  engLayout->addWidget(pushButtonSinh, 0, 1, 1, 1);
  engLayout->addWidget(pushButtonCosh, 0, 3, 1, 1);
  engLayout->addWidget(pushButtonTanh, 1, 1, 1, 1);

  engWidget = new QWidget(this);
  engWidget->setLayout(engLayout);

  connect(pushButtonSin, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonSinh, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonCos, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonCosh, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonFact, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonTan, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonTanh, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonLn, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonLog, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonXNed, SIGNAL(clicked()), this, SLOT(BinaryFuncClicked()));
  connect(pushButtonXSq, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonXCubed, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonCubeRoot, SIGNAL(clicked()), this,
          SLOT(UnaryFuncClicked()));
  connect(pushButtonNRoot, SIGNAL(clicked()), this, SLOT(BinaryFuncClicked()));
  connect(pushButtonExp, SIGNAL(clicked()), this, SLOT(UnaryFuncClicked()));
  connect(pushButtonPi, SIGNAL(clicked()), this, SLOT(numClicked()));
}

void MainWindow::CreateDef() {
  QPushButton* pushButtonClear = new QPushButton(QString::fromUtf8("C"), this);

  QString style =
      "background-color: #E6E6E6;"
      "border-style: outset;"
      "border-width: 2px;"
      "border-radius: 10px;"
      "border-color: beige;"
      "font: bold 14px;"
      "padding: 6px;";
  pushButtonClear->setStyleSheet(style);

  pushButtonClear->setSizePolicy(QSizePolicy::Preferred,
                                 QSizePolicy::Preferred);

  defLayout = new QGridLayout(this);
  defLayout->setSpacing(4);
  defLayout->setContentsMargins(5, 5, 5, 5);

  defLayout->addWidget(lineEdit, 0, 0, 2, 5);
  defLayout->addWidget(simpleRButton, 2, 0, 1, 3);
  defLayout->addWidget(engRButton, 3, 0, 1, 3);
  defLayout->addWidget(pushButtonClear, 2, 4, 2, 1);

  defWidget = new QWidget(this);
  defWidget->setLayout(defLayout);
  connect(pushButtonClear, SIGNAL(clicked()), this, SLOT(Clear()));
}

bool MainWindow::getDigits() { return digits; }

void MainWindow::OneDot(bool b) { dot_one = b; }

void MainWindow::setDigits(bool a) { digits = a; }

void MainWindow::numClicked() {
  QString number = ((QPushButton*)sender())->text();
  if (number == "\u03C0") {
    constexpr double pi = 3.1415926535897932384626433832795;
    lineEdit->setText(lineEdit->text() + QString(std::to_string(pi).c_str()));
  } else
    lineEdit->setText(lineEdit->text() + number);
}

void MainWindow::DotClicked() {
  if (dot_one == true) return;
  OneDot(true);
  if (lineEdit->text().length()) {
    if (lineEdit->text().at(lineEdit->text().length() - 1) != '.')
      lineEdit->setText(lineEdit->text() + '.');
  } else
    lineEdit->setText("0" + '.' + lineEdit->text());
}

void MainWindow::BinaryFuncClicked() {
  if (lineEdit->text().isEmpty()) return;

  OneDot(false);
  if (getDigits()) {
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
      QString symbol = btn->text();
      if (lineEdit->text().length()) {
        if (symbol == "x\u207F")
          lineEdit->setText(lineEdit->text() + ", x\u207F n = ");
        else if (symbol == "\u207F\u221A")
          lineEdit->setText(lineEdit->text() + ", \u207F\u221Ax n = ");
        else
          lineEdit->setText(lineEdit->text() + symbol);
        setDigits(false);
      } else if (symbol == "-")
        lineEdit->setText(symbol + lineEdit->text());
    }
  }
}

double fact(double N) {
  if (N < 0) return 0;
  if (N == 0.0)
    return 1;
  else
    return N * fact((int)floor(N) - 1);
}

void MainWindow::UnaryFuncClicked() {
  if (lineEdit->text().toStdString() == "") return;
  Equal();
  setDigits(true);
  QPushButton* btn = qobject_cast<QPushButton*>(sender());
  if (btn) {
    std::string symbol = btn->text().toStdString();
    std::string expression = lineEdit->text().toStdString();
    double number = std::stod(expression);
    if (symbol == "\u221Ax")
      number = std::sqrt(number);
    else if (symbol == "sin")
      number = std::sin(number);
    else if (symbol == "sinh")
      number = std::sinh(number);
    else if (symbol == "e\u207F")
      number = std::exp(number);
    else if (symbol == "x\u00B2")
      number *= number;
    else if (symbol == "cosh")
      number = std::cosh(number);
    else if (symbol == "cos")
      number = std::cos(number);
    else if (symbol == "ln")
      number = std::log(number);
    else if (symbol == "\u00B3\u221A")
      number = std::cbrt(number);
    else if (symbol == "x\u00B3")
      number *= (number * number);
    else if (symbol == "tanh")
      number = std::tanh(number);
    else if (symbol == "tan")
      number = std::tan(number);
    else if (symbol == "\u00B1")
      number = -number;
    else if (symbol == "log")
      number = std::log10(number);
    else if (symbol == "n!") {
      if (std::floor(number) != number) {
        lineEdit->setText(QString("nan"));
        return;
      } else
        number = fact(number);
    } else if (symbol == "1/x") {
      number = 1 / number;
      expression = std::to_string(number);
      lineEdit->setText(QString(expression.c_str()));
    }
    expression = std::to_string(number);
    while (*(expression.rbegin()) == '0') {
      expression.pop_back();
    }
    if (*(expression.rbegin()) == '.') expression.pop_back();
    lineEdit->setText(QString(expression.c_str()));
  }
}

void MainWindow::Clear() {
  OneDot(false);
  lineEdit->clear();
  setDigits(true);
}

void Delete0s(std::string& line) {
  while (*(line.rbegin()) == '0') line.pop_back();
  if (*(line.rbegin()) == '.') line.pop_back();
}

void MainWindow::Equal() {
  setDigits(true);
  std::string expression = lineEdit->text().toStdString();
  std::string answer = "";
  if (expression == "") {
    return;
  } else if (expression.find('+') != std::string::npos) {
    std::string::size_type position;
    double left_number = std::stod(expression, &position);
    double right_number = std::stod(expression.substr(position + 1));
    double answer_number = left_number + right_number;
    answer = std::to_string(answer_number);
    Delete0s(answer);
    lineEdit->setText(QString(answer.c_str()));
  } else if (expression.find('-') != std::string::npos) {
    std::string::size_type position;
    double left_number = std::stod(expression, &position);
    double right_number = std::stod(expression.substr(position + 1));
    double answer_number = left_number - right_number;
    answer = std::to_string(answer_number);
    Delete0s(answer);
    lineEdit->setText(QString(answer.c_str()));
  } else if (expression.find("\u00D7") != std::string::npos) {
    std::string::size_type position;
    double left_number = std::stod(expression, &position);
    double right_number = std::stod(expression.substr(position + 2));
    double answer_number = left_number * right_number;
    answer = std::to_string(answer_number);
    Delete0s(answer);
    lineEdit->setText(QString(answer.c_str()));
  } else if (expression.find("\u00F7") != std::string::npos) {
    std::string::size_type position;
    double left_number = std::stod(expression, &position);
    double right_number = std::stod(expression.substr(position + 2));
    double answer_number = left_number / right_number;
    answer = std::to_string(answer_number);
    Delete0s(answer);
    lineEdit->setText(QString(answer.c_str()));
  } else if (expression.find(", x\u207F n = ") != std::string::npos) {
    std::string::size_type position;
    double left_number = std::stod(expression, &position);
    double right_number =
        std::stod(lineEdit->text().split(", x\u207F n = ")[1].toStdString());
    double answer_number = std::pow(left_number, right_number);
    answer = std::to_string(answer_number);
    Delete0s(answer);
    lineEdit->setText(QString(answer.c_str()));
  } else if (expression.find(", \u207F\u221Ax n = ") != std::string::npos) {
    std::string::size_type position;
    double left_number = std::stod(expression, &position);
    double right_number = std::stod(
        lineEdit->text().split(", \u207F\u221Ax n = ")[1].toStdString());
    double answer_number = std::pow(left_number, (1 / right_number));
    answer = std::to_string(answer_number);
    Delete0s(answer);
    lineEdit->setText(QString(answer.c_str()));
  }
  bool fl = false;
  auto a = std::find(answer.begin(), answer.end(), '.');
  for (; a != answer.end(); a++)
    if (*a != '0') fl = true;
  if (fl == true) {
    OneDot(true);
  } else {
    OneDot(false);
  }
}

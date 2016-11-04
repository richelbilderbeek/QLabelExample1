#include "qtdialog.h"

#include <cmath>
#include <fstream>
#include "ui_qtdialog.h"

QtDialog::QtDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtDialog)
{
  ui->setupUi(this);
  on_start_clicked();
}

QtDialog::~QtDialog()
{
  delete ui;
}

void QtDialog::create_output()
{
  std::ofstream f("result.csv");
  for (int i=0; i!=100; ++i)
  {
    f << i << "," << std::sqrt(static_cast<double>(i)) << '\n';
  }
}

void QtDialog::create_r_script()
{
  std::ofstream f("script.R");
  f
    << "png(\"result.png\")"            << '\n'
    << "df <- read.csv(\"result.csv\")" << '\n'
    << "plot(df)"                       << '\n'
    << "dev.off()"                      << '\n'
  ;
}

void QtDialog::run_r_script()
{
  std::system("Rscript script.R");
}

void QtDialog::show_result()
{
  QPixmap p;
  p.load("result.png");
  ui->result->setPixmap(p);
}

void QtDialog::on_start_clicked()
{
  create_output();
  create_r_script();
  run_r_script();
  show_result();
}

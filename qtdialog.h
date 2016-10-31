#ifndef QTDIALOG_H
#define QTDIALOG_H

#include <QDialog>

namespace Ui {
  class QtDialog;
}

class QtDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtDialog(QWidget *parent = 0);
  ~QtDialog();

private slots:
  void on_start_clicked();

private:
  Ui::QtDialog *ui;

  void create_output();
  void create_r_script();
  void run_r_script();
  void show_result();
};

#endif // QTDIALOG_H

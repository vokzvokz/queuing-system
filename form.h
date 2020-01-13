#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "response.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_back_button_clicked();

    void on_execute_button_clicked();

private:
    Ui::Form *ui;
    Response *response;
    QString path_to_resourses;
    //QFile datafile;
    //QTextStream outstream;
};

#endif // FORM_H

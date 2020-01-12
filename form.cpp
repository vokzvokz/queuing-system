#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "imitation.h"
#include "response.h"
#include <QRegExp>
#include <ctime>
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->mean_arrive_spinbox->setSingleStep(0.1);
    ui->mean_service_spinbox->setSingleStep(0.1);
    QFile datafile("datafile.txt");

    if (datafile.open(QIODevice::ReadWrite)){
        QTextStream outstream(&datafile);
        qDebug()<<"Файл открылся";
        outstream<<("AAAAAAAAAAAAAAAAAAAA");
        //*out << "The magic number is: " << 49 << "\n";
    } else{
        qDebug()<<"Всё плохо, файл не открылся";
    }
}

Form::~Form()
{
    delete ui;
}

void Form::on_back_button_clicked()
{
    hide();

}

void Form::on_execute_button_clicked()
{
    QRegExp reg("\\d*");  // a digit (\d), zero or more times (*)
    int n_requests;
    double mean_arrive, mean_service;

    //TODO ПОМЕНЯТЬ!!!
    QString wrong_data_response("Введены неверные данные");

    QString buf = ui->n_requests_line_edit->text();
    mean_service = ui->mean_service_spinbox->value();
    mean_arrive = ui->mean_arrive_spinbox->value();
    QString qreport;
    if(reg.exactMatch(buf) && mean_arrive != 0.0 && mean_service != 0.0){
        n_requests = buf.toInt();
        srand(time(NULL));
        if(n_requests>0){
            Imitation queuing_system(mean_service, mean_arrive, n_requests);
            queuing_system.run();
            string report = queuing_system.report();
            qreport = QString::fromStdString(report);
        } else {
            qreport = wrong_data_response;
        }

    } else {
        qreport = wrong_data_response;
    }
    response = new Response(this, qreport);
    //hide();
    response->show();
   // ui->setupUi(response);
}

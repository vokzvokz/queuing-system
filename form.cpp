#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "imitation.h"
#include "response.h"
#include <QRegExp>
#include <ctime>
#include <QDebug>
#include <QProcess>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->mean_arrive_spinbox->setSingleStep(0.1);
    ui->mean_service_spinbox->setSingleStep(0.1);
    path_to_resourses = "C:/Users/Vladimir/queuing_system_resourses/";
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

    QString wrong_data_response("Введены неверные данные");

    QString buf = ui->n_requests_line_edit->text();

    mean_service = ui->mean_service_spinbox->value();
    mean_arrive = ui->mean_arrive_spinbox->value();
    QString qreport, qto_logs_file, qto_arrivings_file, qto_services_file;
    if(reg.exactMatch(buf) && mean_arrive != 0.0 && mean_service != 0.0){
        n_requests = buf.toInt();
        srand(time(NULL));
        if(n_requests>0){
            Imitation queuing_system(mean_service, mean_arrive, n_requests);
            queuing_system.run();

            string report = queuing_system.report();
            qreport = QString::fromStdString(report);

            string to_datafile = queuing_system.get_timing_stats();
            qto_logs_file = QString::fromStdString(to_datafile);

            to_datafile = queuing_system.get_arrivings();
            qto_arrivings_file = QString::fromStdString(to_datafile);

            to_datafile = queuing_system.get_services();
            qto_services_file = QString::fromStdString(to_datafile);
        } else {
            qreport = wrong_data_response;
        }

    } else {
        qreport = wrong_data_response;
    }

    QFile logs_file(path_to_resourses+"logs_file.txt");
    QFile arrivings_file(path_to_resourses+"arrivings_file.txt");
    QFile services_file(path_to_resourses+"services_file.txt");

    //запись файла логов
    if (logs_file.open(QIODevice::ReadWrite | QFile::Truncate)){
        QTextStream outstream(&logs_file);
        qDebug()<<"Файл открылся";
        outstream<<qto_logs_file;
        logs_file.close();
    } else{
        qDebug()<<"Всё плохо, файл логов не открылся";
    }

    //запись файла прибытий
    if (arrivings_file.open(QIODevice::ReadWrite | QFile::Truncate)){
        QTextStream outstream(&arrivings_file);
        qDebug()<<"Файл открылся";
        outstream<<qto_arrivings_file;
        arrivings_file.close();
    } else{
        qDebug()<<"Всё плохо, файл прибытий не открылся";
    }

    //запись файла обслуживаний
    if (services_file.open(QIODevice::ReadWrite | QFile::Truncate)){
        QTextStream outstream(&services_file);
        qDebug()<<"Файл открылся";
        outstream<<qto_services_file;
        services_file.close();
    } else{
        qDebug()<<"Всё плохо, файл прибытий не открылся";
    }

//    QString path = QCoreApplication::applicationDirPath();
    QString  command("python");
    QStringList params = QStringList() << "plot_script.py";

    QProcess *process = new QProcess();
    process->startDetached(command, params, path_to_resourses);
    if(process->waitForFinished(10000)){
        qDebug()<<"Процесс завершен";
    } else {
        qDebug()<<"Что-то пошло не так: "<<process->error();
    }
    process->close();
//    QProcess p;
//    QStringList params;

//    params << path_to_resourses + "plot_script.py";
//    p.start("python", params);
//    p.waitForFinished(-1);

//    QString p_stdout = p.readAll();
//    ui->lineEdit->setText(p_stdout);

    response = new Response(this, qreport);
    response->show();
}

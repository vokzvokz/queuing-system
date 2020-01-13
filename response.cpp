#include "response.h"
#include "ui_response.h"
#include <QProcess>
#include <QDebug>

Response::Response(QWidget *parent, QString data) :
    QWidget(parent),
    ui(new Ui::Response)
{
    ui->setupUi(this);
    ui->response_text->setText(data);
//    std::string filename = "C:/Users/Vladimir/queuing_system_resourses/plot_script.py";
//    std::string filename = "--version";
//    std::string command = "python ";
//    command += filename;
//    system(command.c_str());
}

Response::~Response()
{
    delete ui;
}

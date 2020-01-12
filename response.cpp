#include "response.h"
#include "ui_response.h"

Response::Response(QWidget *parent, QString data) :
    QWidget(parent),
    ui(new Ui::Response)
{
    ui->setupUi(this);
    ui->response_text->setText(data);
}

Response::~Response()
{
    delete ui;
}

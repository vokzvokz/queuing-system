#ifndef RESPONSE_H
#define RESPONSE_H

#include <QWidget>

namespace Ui {
class Response;
}

class Response : public QWidget
{
    Q_OBJECT

public:
    explicit Response(QWidget *parent = nullptr, QString data = "No data found");
    ~Response();

private:
    Ui::Response *ui;
    QString data;
};

#endif // RESPONSE_H

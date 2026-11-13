#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // possible variant
    /*
    connect(ui->incButton, &QPushButton::clicked, [this]() {
        counter++;
        ui->label->setText(QString::number(counter));
    });
    */
    // but better use function with context (this) argument
    connect(ui->incButton, &QPushButton::clicked, this, [this]() {
        counter++;
        ui->label->setText(QString::number(counter));
    });
    // connection is connected with context live

    connect(ui->exitButton, &QPushButton::clicked, this, &Widget::quit);
}

Widget::~Widget()
{
    delete ui;
}

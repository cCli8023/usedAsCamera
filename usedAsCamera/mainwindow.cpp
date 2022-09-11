#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTimeMod();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete _timeMod;
}

void MainWindow::initTimeMod()
{
    _timeMod = new timeMod;

    //渲染时间列表
    QList<QByteArray> tzList = _timeMod->timeZoneList();

    for (auto & tz : tzList ){
        ui->boxTz->addItem(tz.toStdString().c_str());
    }
    on_boxTz_currentTextChanged(ui->boxTz->currentText());
    //定时器更新时间
    QTimer * t = new QTimer(this);
    t->setInterval(333);
    connect(t, &QTimer::timeout, this, [this](){
        ui->labLocalValue->setText(_timeMod->time().toString("yyyy-MM-dd hh:mm:ss"));
        ui->labUtcValue->setText(_timeMod->time().toUTC().toString("yyyy-MM-dd hh:mm:ss"));
    });
    t->start();
}


void MainWindow::on_boxTz_currentTextChanged(const QString &arg1)
{
    QByteArray tz = arg1.toLocal8Bit();
    QDateTime dt = _timeMod->timeById(tz);
    ui->labLocalValue->setText(dt.toString("yyyy-MM-dd hh:mm:ss"));
    ui->labUtcValue->setText(dt.toUTC().toString("yyyy-MM-dd hh:mm:ss"));
}


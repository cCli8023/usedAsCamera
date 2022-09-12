#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timeMod.h"
#include "discoverMod.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_boxTz_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    void initTimeMod();
    void initDiscoverMod();
private:
    Ui::MainWindow *ui;

    timeMod * _timeMod;
    discoverMod * _discoverMod;
};
#endif // MAINWINDOW_H

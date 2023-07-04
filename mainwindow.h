#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "jogo.h"
#include "login.h"
#include "rank.h"
#include "registrar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool logado=false;
    int id;

private slots:
    void on_btn_logar_clicked();

    void on_btn_registrar_clicked();

    void on_btn_jogar_clicked();

    void on_btn_tutorial_clicked();

    void on_btn_rank_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

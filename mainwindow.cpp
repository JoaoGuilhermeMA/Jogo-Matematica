#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logado = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_logar_clicked()
{
    Login form4;
    form4.setFixedSize(463,155);
    form4.setWindowTitle("LOGAR");
    form4.exec();
    id=form4.getId();
    logado= form4.getLogado();
    qDebug() << "\nID: " << id;
}


void MainWindow::on_btn_registrar_clicked()
{
    Registrar form3;
    form3.setFixedSize(463,152);
    form3.setWindowTitle("REGISTRAR");
    form3.exec();
}


void MainWindow::on_btn_jogar_clicked()
{
    if(logado){
        qDebug() << "\nID: " << id;
        Jogo form1;
        form1.setFixedSize(593, 390);
        form1.setId(id);
        form1.setWindowTitle("JOGAR");
        form1.exec();
    }else{
        QMessageBox::warning(this,"ERRO","Você não está logado!");
    }
}


void MainWindow::on_btn_tutorial_clicked()
{
    QMessageBox::about(this,"TUTORIAL","O jogo foi feitos para ajudar as crianças a aprender as operações básicas matemáticas!");
}


void MainWindow::on_btn_rank_clicked()
{
    Rank form2;
    form2.setFixedSize(500, 300);
    form2.setWindowTitle("RANK");
    form2.exec();
}


void MainWindow::on_pushButton_clicked()
{
    logado=false;
    id=0;
}


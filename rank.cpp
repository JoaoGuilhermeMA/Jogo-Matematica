#include "rank.h"
#include "ui_rank.h"

Rank::Rank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);

    if(!con.abrir()){
        QMessageBox::warning(this,"ERRO","Erro ao conectar ao banco de dados");
    }else{
        QSqlQuery q;
        q.prepare("SELECT * FROM tb_player ORDER BY player_pontos DESC LIMIT 5;");
        if(q.exec()){
            int linha=0;
            ui->tw_top5->setColumnCount(4);
            while(q.next()){
                ui->tw_top5->insertRow(linha);
                ui->tw_top5->setItem(linha,0,new QTableWidgetItem(q.value(0).toString()));
                ui->tw_top5->setItem(linha,1,new QTableWidgetItem(q.value(1).toString()));
                ui->tw_top5->setItem(linha,2,new QTableWidgetItem(q.value(2).toString()));
                ui->tw_top5->setItem(linha,3,new QTableWidgetItem(q.value(4).toString()));
                ui->tw_top5->setRowHeight(linha,20);
                linha++;
                QStringList listaCab = {"ID","LOGIN","NOME","PONTOS"};

                ui->tw_top5->setColumnWidth(0,20);
                ui->tw_top5->setColumnWidth(1,200);
                ui->tw_top5->setColumnWidth(2,177);
                ui->tw_top5->setColumnWidth(3,70);

                ui->tw_top5->setHorizontalHeaderLabels(listaCab);
                ui->tw_top5->setEditTriggers(QAbstractItemView::NoEditTriggers);
                ui->tw_top5->setSelectionBehavior(QAbstractItemView::SelectRows);
                ui->tw_top5->verticalHeader()->setVisible(false);
            }
        }else{
            QMessageBox::warning(this,"ERRO","Erro ao pesquisar no banco de dados");
        }
    }
}

Rank::~Rank()
{
    delete ui;
}

void Rank::on_btn_sair_clicked()
{
    close();
}


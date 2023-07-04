#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btn_cancelar_clicked()
{
    logado=false;
    close();
}


void Login::on_btn_logar_clicked()
{
    if(!con.abrir()){
        QMessageBox::warning(this,"ERRO","Erro ao conectar com o banco de dados");
    }else{
        QString login, senha;
        login = ui->campo_login->text();
        senha = ui->campo_senha->text();
        qDebug() << "Login= " << login << " |senha= " << senha;
        QSqlQuery query;
        query.prepare("SELECT * FROM tb_player WHERE player_login = :login AND player_senha = :senha");
        query.bindValue(":login", login);
        query.bindValue(":senha", senha);
        if(query.exec()){
            query.first();
            if(query.value(1) == login && query.value(3) == senha){
                id = query.value(0).toInt();
                qDebug() << "\id: " << id;
                con.fechar();
                close();
                logado=true;
            }else{
                QMessageBox::warning(this,"ERRO","Jogador não encontrado");
            }
        }else{
            QMessageBox::warning(this,"ERRO","Falha em logar");
        }
    }
}

bool Login::getLogado(){
    return logado;
}

int Login::getId(){
    return id;
}




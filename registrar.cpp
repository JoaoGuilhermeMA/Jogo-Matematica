#include "registrar.h"
#include "ui_registrar.h"

Registrar::Registrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrar)
{
    ui->setupUi(this);
}

Registrar::~Registrar()
{
    delete ui;
}

void Registrar::on_btn_registrar_clicked()
{
    if(!con.abrir()){
            QMessageBox::warning(this,"ERRO","Erro ao conectar com o banco de dados");
        }else{
            QString nome, login, senha, confirma;
            nome = ui->line_nome->text();
            senha = ui->line_senha->text();
            confirma = ui->line_confirma->text();
            login = ui->line_login->text();
            if(nome==""||senha==""||confirma==""||login==""){
                QMessageBox::warning(this,"ERROR","por favor não deixar nada em branco");
                ui->line_nome->clear();
                ui->line_login->clear();
                ui->line_senha->clear();
                ui->line_confirma->clear();
            }else{
                if(senha == confirma){
                    QSqlQuery query;
                    query.prepare("INSERT INTO tb_player (player_login, player_nome, player_senha) VALUES ('"+login+"', '"+nome+"', '"+senha+"')");
                    if(query.exec()){
                        QMessageBox::about(this,"CONFIRMAÇÃO","jogador cadastrado com sucesso!");
                        close();
                    }else{
                        QMessageBox::warning(this,"ERRO","Já existe um jogador com esse login!");
                    }
                }else{
                    QMessageBox::warning(this,"ERRO","As senhas não são iguais!!");
                }
            }
        }
    con.fechar();
}


void Registrar::on_btn_cancelar_clicked()
{
    close();
}


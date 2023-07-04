#ifndef CONEXAO_H
#define CONEXAO_H

#include <QtSql>

class Conexao{
public:
    QSqlDatabase bancoDeDados;
    Conexao(){
        bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
    }
    void fechar(){
        bancoDeDados.close();
    }
    bool abrir(){
        QString local = qApp->applicationDirPath();
        QString banco = local+"/db/db";
        bancoDeDados.setDatabaseName(banco);

        if(!bancoDeDados.open()){
            return false;
        }else{
            return true;
        }
    }
};

#endif // CONEXAO_H

#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "conexao.h"
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool logado=false;
    Conexao con;
    int id;
    int getId();
    bool getLogado();

private slots:
    void on_btn_cancelar_clicked();

    void on_btn_logar_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H

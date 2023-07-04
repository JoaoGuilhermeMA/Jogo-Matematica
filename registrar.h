#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>
#include <conexao.h>
#include <QMessageBox>

namespace Ui {
class Registrar;
}

class Registrar : public QDialog
{
    Q_OBJECT

public:
    explicit Registrar(QWidget *parent = nullptr);
    ~Registrar();
    Conexao con;

private slots:
    void on_btn_registrar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::Registrar *ui;
};

#endif // REGISTRAR_H

#ifndef RANK_H
#define RANK_H

#include <QDialog>
#include "jogo.h"
#include "conexao.h"

namespace Ui {
class Rank;
}

class Rank : public QDialog
{
    Q_OBJECT

public:
    explicit Rank(QWidget *parent = nullptr);
    ~Rank();
    Conexao con;

private slots:
    void on_btn_sair_clicked();

private:
    Ui::Rank *ui;
};

#endif // RANK_H

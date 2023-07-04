#ifndef JOGO_H
#define JOGO_H

#include <QDialog>
#include <vector>
#include "conexao.h"
#include <QMessageBox>

namespace Ui {
class Jogo;
}

class Jogo : public QDialog
{
    Q_OBJECT

public:
    explicit Jogo(QWidget *parent = nullptr);
    ~Jogo();
    int getPontos();
    void setId(int id);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Jogo *ui;
    int id;
    std::vector<int> respostasDigitadas;
    std::vector<int> respostasCertas;
    void temporizador();
    QString geraOperacao();
    bool primeiraVez =true;
    int contador;
    QTimer* temp;
    bool jogoComecou=false;
    int iterador=-1;
    int pontos=0;
    Conexao con;
};

#endif // JOGO_H

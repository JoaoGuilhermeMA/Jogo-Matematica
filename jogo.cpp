#include "jogo.h"
#include "ui_jogo.h"
#include <random>
#include <chrono>

using namespace std;

Jogo::Jogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Jogo)
{
    ui->setupUi(this);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    temp = new QTimer(this);
    connect(temp, &QTimer::timeout, this, &Jogo::temporizador);
}

Jogo::~Jogo()
{
    delete ui;
}

QString Jogo::geraOperacao()
{
    inicio:
    // gera numeros aleatorios
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 10);
    int n1 = dis(gen);
    int n2 = dis(gen);
    int a = n1, b = n2, resultado;
    //gera o operador de forma aleatoria
    char operadores[] = {'+', '-', '/', '*'};
    int tamanho = sizeof(operadores) / sizeof(operadores[0]);
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> dis2(0, tamanho - 1);
    int posicao_aleatoria = dis2(gen2);
    char operador_aleatorio = operadores[posicao_aleatoria];
    switch (operador_aleatorio) {
    case '+':
        resultado = a+b;
        break;
    case '-':
        resultado = a-b;
        break;
    case '*':
        resultado = a*b;
        break;
    case '/':
        if(a%b != 0){
            goto inicio;
        }
        resultado = a/b;
        break;
    default:
        break;
    }
    QString operacao;
    operacao = QString::number(a) + " " + operador_aleatorio + " " + QString::number(b);
    qDebug() << "Número aleatório: " << a << ", " << b;
        qDebug() << "\nOperação aleatória: " << operador_aleatorio;
        qDebug() << operacao;
    qDebug() << "\nResutado " << resultado;
    respostasCertas.push_back(resultado);
    return operacao;
}

void Jogo::temporizador(){
        if (contador > 0) {
            QString mensagem = "Tempo restante: " + QString::number(contador) + "s";
            ui->temporizador->setText(mensagem);
            --contador;
        } else {
            ui->temporizador->setText("Tempo restante: 0s");
            jogoComecou=false;
            QString msg = "Sua pontuação foi: " + QString::number(pontos);
            QMessageBox::about(this,"PONTUAÇÃO",msg);
            respostasDigitadas.clear();
            respostasCertas.clear();
            if(respostasDigitadas.empty() && respostasCertas.empty()){
                qDebug() << "Vector zerado";
            }
            if (!con.abrir()) {
                QMessageBox::warning(this,"ERROR","Banco de dados não aberto!");
            }else{
                QSqlQuery query;
                qDebug() << "\nID: " << id;
                query.prepare("UPDATE tb_player SET player_pontos = :pontos WHERE player_id = :id");
                query.bindValue(":pontos", pontos);
                query.bindValue(":id", id);
                if (query.exec()) {
                    qDebug() << "Pontuação atualizada no banco de dados!";
                } else {
                    qDebug() << "\nId" << id;
                    qDebug() << "\nErro ao atualizar a pontuação no banco de dados:" << query.lastError().text();
                }
            }
            iterador=-1;
            pontos=0;
            close();
        }
}

void Jogo::on_pushButton_clicked()
{
        if(primeiraVez){
            QString operacao = geraOperacao();
            ui->txt_op->setText("Operacao: " + operacao);
        }
        contador = 60;
        jogoComecou=true;
        temporizador();
        if(!temp->isActive()){
            temp->start(1000);  // 1 segundo
        }
}

void Jogo::on_pushButton_2_clicked()
{
    respostasDigitadas.clear();
    respostasCertas.clear();
    if(respostasDigitadas.empty() && respostasCertas.empty()){
        qDebug() << "Vector zerado";
    }
    pontos=0;
    close();
}


void Jogo::on_pushButton_3_clicked()
{
    if(jogoComecou){
        QString resultado = ui->txt_resultado->text();
        int res = resultado.toInt();
        respostasDigitadas.push_back(res);
        if(respostasDigitadas.size() != 0){
                qDebug() << "\n Valor acrescentado ao vector!";
        }
        iterador++;
        if(respostasDigitadas[iterador]==respostasCertas[iterador]){
                pontos++;
        }
        ui->txt_resultado->clear();
        QString op = Jogo::geraOperacao();
        ui->txt_op->setText("Operacao: " + op);
    }else{
        QMessageBox::warning(this,"ERRO","Jogo não foi iniciado!");
    }
}

int Jogo::getPontos(){
    return pontos;
}

void Jogo::setId(int id){
    this->id = id;
}

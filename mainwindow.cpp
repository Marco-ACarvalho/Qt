#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inicializa();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inicializa(){
    esperandoNum = true;
    valorEsquerda = 0;
    valorDireita = 0;
    valorResultado = 0;
    opSelecionada = "";

    ui->visor->setText("0");
}

void MainWindow::digitoClick(){

    //Encontrando o botão que foi clicado
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    if(esperandoNum){
        ui->visor->clear();
        esperandoNum = false;
    }

    ui->visor->setText(ui->visor->text() + btn->text()[1]);

}

void MainWindow::opClick(){

    // Encontrando o botão que foi clicado
    QPushButton *btn = qobject_cast<QPushButton *>(sender());

    opSelecionada = btn->text();

    valorEsquerda = ui->visor->text().toDouble();

    esperandoNum = true;
}

void MainWindow::igualClick(){

    valorDireita = ui->visor->text().toDouble();

    if(opSelecionada == "+"){
        valorResultado = valorEsquerda + valorDireita;
    }
    else if(opSelecionada == "-"){
        valorResultado = valorEsquerda - valorDireita;
    }
    else if(opSelecionada == "*"){
        valorResultado = valorEsquerda * valorDireita;
    }
    else if(opSelecionada == "/"){
        valorResultado = valorEsquerda / valorDireita;
    }
    else{
        qDebug("OPERAÇÂOINVALIDA");
    }

    ui->visor->setText(QString::number(valorResultado));
}

void MainWindow::limparClick(){
    inicializa();
}

void MainWindow::apagaClick(){

    if(esperandoNum){
        return; //não faz nada
    }

    QString text = ui->visor->text();

    //Retira o ultimo caractere
    text.chop(1);

    if(text.isEmpty()){
        text = "0";
        esperandoNum = true;
    }

    ui->visor->setText(text);

}

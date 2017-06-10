#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool esperandoNum;
    QString opSelecionada;
    double valorEsquerda;
    double valorDireita;
    double valorResultado;
    void inicializa();

private slots:
    void digitoClick();
    void opClick();
    void igualClick();
    void limparClick();
    void apagaClick();
};

#endif // MAINWINDOW_H

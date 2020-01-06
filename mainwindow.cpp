#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

hashTable<hashEntry> tableEng(1000);
hashTable<hashEntry> tableRus(1000);
int tab[1000];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    string word, buf;
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(generate()));

    ifstream file("C:\\Qt Projects\\lab4\\tab.txt");
    if(file.is_open())
    {
        while(!file.eof())
        {
            file >> word;
            hashEntry n1(word);
            tableRus.push(n1);
            buf = word;
            file >> word;
            hashEntry r1(word);
            tableEng.push(r1);
            tab[tableRus.getKey(buf)] = tableEng.getKey(word);
        }
    }
    file.close();

}

void MainWindow::generate()
{
    hashEntry buf;

    string orig = ui->lineEdit->text().toUtf8().constData();

    buf = tableEng.getValue((tab[tableRus.getKey(orig)]));
    buf.print(ui->textEdit);
}
MainWindow::~MainWindow()
{
    delete ui;
}


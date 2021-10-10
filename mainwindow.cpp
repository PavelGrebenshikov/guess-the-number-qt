#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <random>
#include <ctime>
#include <stdlib.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// CustomFunction start
int randomNumber(int MIN_NUMBER, int MAX_NUMBER);

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString userInput = ui->lineEdit->text();
    QString minNumber = ui->lineEdit_2->text();
    QString maxNumber = ui->lineEdit_3->text();
    int minNumberInt;
    int maxNumberInt;
    int userInputInt;

    if (minNumber != "") {
        minNumberInt = minNumber.toInt();
    }
    if (maxNumber != ""){
        maxNumberInt = maxNumber.toInt();
    }
    if (userInput != ""){
        userInputInt = userInput.toInt();
    }

    int currentNumber = randomNumber(minNumberInt, maxNumberInt);
    QString numString = QString::number(currentNumber);
    if (userInputInt == currentNumber) {
        ui->label_2->setText("You have won, congratulations!");
    } else {
        ui->label_2->setText("You've lost, try again");
        ui->label_3->setText("The correct number: " + numString);
    }

}


int randomNumber(int MIN_NUMBER, int MAX_NUMBER) {
    if (MIN_NUMBER == 0 && MAX_NUMBER != 0) {
        std::srand(time(0));
        return std::rand() % MAX_NUMBER;
    }
    if (MIN_NUMBER == 0 && MAX_NUMBER == 0) {
        std::srand(time(0));
        return std::rand();
    }
    if (MIN_NUMBER != 0 && MAX_NUMBER == 0) {
        std::srand(time(0));
        return MIN_NUMBER + rand();
    }
    if (MIN_NUMBER != 0 && MAX_NUMBER != 0) {
        std::srand(time(0));
        return MIN_NUMBER + std::rand() % (MAX_NUMBER - MIN_NUMBER + 1);
    }
    return 0;
}

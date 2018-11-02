#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "../store/AgeGroupStore.hpp"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->listView->setModel(AgeGroupStore::getSingleton().get());
}

MainWindow::~MainWindow()
{
	delete ui;
}

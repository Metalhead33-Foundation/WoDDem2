#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "../store/JobStore.hpp"
#include "../store/AgeGroupStore.hpp"
#include "../store/GenderStore.hpp"
#include "../store/RaceStore.hpp"
#include "../store/ReligionStore.hpp"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->tabWidget->setTabText(0,"Jobs");
	ui->tabWidget->setTabText(1,"Groups with job preferences");
	ui->tabWidget->setTabText(2,"Geographical areas");
	ui->tabWidget->setTabText(3,"Pops");

	ui->jobList->setModel(JobStore::getSingleton().get());
	ui->jobPreferenceTabs->setTabText(0,"Genders");
	ui->genderList->setModel(GenderStore::getSingleton().get());
	ui->jobPreferenceTabs->setTabText(1,"Age Groups");
	ui->ageGroupList->setModel(AgeGroupStore::getSingleton().get());
	ui->jobPreferenceTabs->setTabText(2,"Races");
	ui->raceList->setModel(RaceStore::getSingleton().get());
	ui->jobPreferenceTabs->setTabText(3,"Religions");
	ui->religionList->setModel(ReligionStore::getSingleton().get());
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_genderList_clicked(const QModelIndex &index)
{
	auto agegrp = GenderStore::getSingleton()->get(index.row());
	if(agegrp)
	{
		ui->jobPreferences->setModel(agegrp.get());
	} else ui->jobPreferences->setModel(nullptr);
}

void MainWindow::on_ageGroupList_clicked(const QModelIndex &index)
{
	auto agegrp = AgeGroupStore::getSingleton()->get(index.row());
	if(agegrp)
	{
		ui->jobPreferences->setModel(agegrp.get());
	} else ui->jobPreferences->setModel(nullptr);
}

void MainWindow::on_raceList_clicked(const QModelIndex &index)
{
	auto agegrp = RaceStore::getSingleton()->get(index.row());
	if(agegrp)
	{
		ui->jobPreferences->setModel(agegrp.get());
	} else ui->jobPreferences->setModel(nullptr);
}

void MainWindow::on_religionList_clicked(const QModelIndex &index)
{
	auto agegrp = ReligionStore::getSingleton()->get(index.row());
	if(agegrp)
	{
		ui->jobPreferences->setModel(agegrp.get());
	} else ui->jobPreferences->setModel(nullptr);
}

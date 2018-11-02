#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

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

private slots:

	void on_genderList_clicked(const QModelIndex &index);

	void on_ageGroupList_clicked(const QModelIndex &index);

	void on_raceList_clicked(const QModelIndex &index);

	void on_religionList_clicked(const QModelIndex &index);

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP

#include <QApplication>
#include "gui/MainWindow.hpp"
#include "store/AgeGroupStore.hpp"
#include "store/JobStore.hpp"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	JobStore::getSingleton()->create("Criminal");
	JobStore::getSingleton()->create("Noble");
	AgeGroupStore::getSingleton()->create("Children");
	AgeGroupStore::getSingleton()->create("Elderly");
	MainWindow win;
	win.show();
	return a.exec();
}

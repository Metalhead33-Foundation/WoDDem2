#include <QApplication>
#include "gui/MainWindow.hpp"
#include "store/AgeGroupStore.hpp"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AgeGroupStore::getSingleton()->create("Children");
	AgeGroupStore::getSingleton()->create("Elderly");
	MainWindow win;
	win.show();
	return a.exec();
}

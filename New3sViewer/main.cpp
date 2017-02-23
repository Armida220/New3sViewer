#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "SingleViewerWiget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainwindow w;
	w.show();

	a.connect(&a , SIGNAL(lastWindowClosed()) , &a , SLOT(quit())) ;
	return a.exec();
}

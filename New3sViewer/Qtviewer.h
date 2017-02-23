#include <osg/ArgumentParser>
#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>
#include <QtCore/QString>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>
#include <QtOpenGL/QGLWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiSubWindow>
#include <QtWidgets/QMdiArea>
#include<qtgui/qtgui>
#include <iostream> 
#include <osgWidget/Widget>
#include <osgQt/GraphicsWindowQt>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include "AdaptWidget.h"


class ViewerQT : public osgViewer::Viewer, public AdapterWidget
{
public:
	ViewerQT(QWidget * parent=0,const char * name=0,const QGLWidget * shareWidget=0,WindowFlags f=0):AdapterWidget(parent ,name,shareWidget ,f)
	{
		getCamera()->setViewport(new osg::Viewport(0,0,width(),height()));
		getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(width())/static_cast<double>(height()), 1.0f, 10000.0f);
		getCamera()->setGraphicsContext(getGraphicsWindow());

		setThreadingModel(osgViewer::Viewer::SingleThreaded);
		connect(&_timer,SIGNAL(timeout()),this,SLOT(updateGL()));//���Ұ�����timeout()���ӵ��ʵ��Ĳۡ������ʱ���ȥ�ˣ������ᷢ��timeout()�źš� 

		_timer.start(10);//ʹ��start()����ʼ

	}

	virtual void paintGL()
	{
		frame();
	}
protected:
	QTimer _timer;
};
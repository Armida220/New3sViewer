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

using Qt::WindowFlags;

class AdapterWidget:public QGLWidget
{
public:
	AdapterWidget(QWidget *parent=0,const char* name=0,const QGLWidget * shareWidget=0,WindowFlags f=0);

	virtual ~AdapterWidget()
	{

	}

	osgViewer::GraphicsWindow* getGraphicsWindow()
	{
		return _gw.get();
	}

	const osgViewer::GraphicsWindow* getGraphicsWidow()const
	{
		return _gw.get();
	}
protected:
	void init();
	virtual void resizeGL(int width,int height);
	virtual void keyPressEvent(QKeyEvent* event);
	virtual void keyReleaseEvent(QKeyEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);

	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _gw;

};


// AdapterWidget::AdapterWidget(QWidget *parent/* =0 */,const char* name/* =0 */,const QGLWidget * shareWidget/* =0 */,WindowFlags f/* =0 */)
// 	:QGLWidget(parent , shareWidget , f)
// {
// 	_gw = new osgViewer::GraphicsWindowEmbedded(0 , 0 , width() , height()) ;
// 	setFocusPolicy(Qt::ClickFocus) ;//接受鼠标单击做焦点
// }
// 
// void AdapterWidget::resizeGL(int width, int height)
// {
// 	_gw->getEventQueue()->windowResize(0,0,width,height);
// 	_gw->resized(0,0,width,height);
// 
// }
// void AdapterWidget::keyPressEvent(QKeyEvent* event)
// {
// 	_gw->getEventQueue()->keyPress( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toLocal8Bit().data() ) );
// 
// }
// 
// void AdapterWidget::keyReleaseEvent(QKeyEvent* event)
// {
// 	_gw->getEventQueue()->keyRelease(  (osgGA::GUIEventAdapter::KeySymbol)*(event->text().toLocal8Bit().data()));
// 
// }
// 
// 
// void AdapterWidget::mousePressEvent(QMouseEvent* event)
// {
// 	int button=0;
// 	switch (event->button())
// 	{
// 	case(Qt::LeftButton):
// 		button=1;
// 		break;
// 	case (Qt::MidButton):
// 		button=2;
// 		break;
// 	case (Qt::RightButton):
// 		button=3;
// 		break;
// 	case (Qt::NoButton):
// 		button=0;
// 		break;
// 	default:
// 		button=0;
// 		break;
// 
// 	}
// 
// 	_gw->getEventQueue()->mouseButtonPress(event->x(),event->y(),button);
// 
// }
// 
// void AdapterWidget::mouseReleaseEvent( QMouseEvent* event )
// {
// 	int button = 0;
// 	switch(event->button())
// 	{
// 	case(Qt::LeftButton):
// 		button = 1;
// 		break;
// 	case(Qt::MidButton): 
// 		button = 2;
// 		break;
// 	case(Qt::RightButton):
// 		button = 3; 
// 		break;
// 	case(Qt::NoButton): 
// 		button = 0; 
// 		break;
// 	default: 
// 		button = 0;
// 		break;
// 	}
// 	_gw->getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);
// }
// 
// 
// void  AdapterWidget::mouseMoveEvent(QMouseEvent* event)
// {
// 	_gw->getEventQueue()->mouseMotion(event->x(),event->y());
// 
// }
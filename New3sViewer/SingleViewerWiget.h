#pragma once
#include <osgViewer/Viewer>
#include <QtOpenGL/QGLWidget>
#include <QtCore/QTimer>


class SingleViewerWiget :
	public osgViewer::Viewer , public QGLWidget
{
public:
	SingleViewerWiget(QWidget * parent = 0, const QGLWidget * shareWidget = 0, Qt::WindowFlags f = 0) ;
	virtual ~SingleViewerWiget(void);

protected:
	virtual void paintGL() ;
	void resizeGL(int w, int h) ;
private:
	QTimer m_timer ;
	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> gw ;
};


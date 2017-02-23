#include "SingleViewerWiget.h"


SingleViewerWiget::SingleViewerWiget(QWidget * parent /* = 0 */, const QGLWidget * shareWidget /* = 0 */, Qt::WindowFlags f /* = 0 */):QGLWidget(parent , shareWidget , f)
{
	getCamera()->setViewport(new osg::Viewport(0 , 0 , width() , height())) ;
	getCamera()->setProjectionMatrixAsPerspective(30.0f , static_cast<double>(width()/height()) , 1.0f , 10000.0f) ;

	gw = new osgViewer::GraphicsWindowEmbedded(0 , 0 , width() , height()) ;
	getCamera()->setGraphicsContext(gw.get()) ;
	setFocusPolicy(Qt::ClickFocus) ;
	setThreadingModel(osgViewer::Viewer::SingleThreaded) ;
	connect(&m_timer , SIGNAL(timeout()) , this , SLOT(updateGL())) ;
	m_timer.start(10) ;
}


SingleViewerWiget::~SingleViewerWiget(void)
{
}

void SingleViewerWiget::paintGL()
{
	frame() ;
}

void SingleViewerWiget::resizeGL(int w, int h)
{
	gw->getEventQueue()->windowResize(0 , 0 , w , h) ;
	gw->resized(0 , 0 , w , h) ;
}



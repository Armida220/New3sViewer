#include "multiwidget.h"
#include <QHBoxLayout>

MultiWidget::MultiWidget(osgViewer::ViewerBase::ThreadingModel threadingModel /* = osgViewer::CompositeViewer::SingleThreaded  */, osg::Node *node1 /* = NULL  */, osg::Node *node2 /* = NULL */):QWidget(),osgViewer::CompositeViewer()
{
	this->setAttribute(Qt::WA_DeleteOnClose) ;
	setThreadingModel(threadingModel) ;
	setKeyEventSetsDone(0) ;
	m_node1 = node1 ;
	m_node2 = node2 ;

	if (!m_node2)
	{
		m_widget1 = addViewWidget(createGraphicsWindow(0 , 0 , width() , height()) , m_node1) ;
		QHBoxLayout *hlayout = new QHBoxLayout ;
		hlayout->addWidget(m_widget1) ;
		setLayout(hlayout) ;
	}
	else
	{
		m_widget1 = addViewWidget(createGraphicsWindow(0 , 0 , width()/2 , height()) , m_node1) ;
		m_widget2 = addViewWidget(createGraphicsWindow(width()/2 , 0 , width()/2 , height()) , m_node2) ;

		QHBoxLayout *hlayout = new QHBoxLayout() ;
		hlayout->addWidget(m_widget1) ;
		hlayout->addWidget(m_widget2) ;
		setLayout(hlayout) ;
	}
	connect(&m_timer , SIGNAL(timeout()) , this , SLOT(update())) ;
	m_timer.start(10) ;
}

MultiWidget::~MultiWidget()
{

}

osgQt::GraphicsWindowQt *MultiWidget::createGraphicsWindow(int x , int y , int w , int h, const std::string &name /* = ""  */, bool windowDecoration /* = false */)
{
	osg::DisplaySettings *ds = osg::DisplaySettings::instance().get() ;
	osg::ref_ptr<osg::GraphicsContext::Traits> traints = new osg::GraphicsContext::Traits ;
	traints->windowName = name ;
	traints->windowDecoration = windowDecoration ;
	traints->x = x ;
	traints->y = y ;
	traints->width = w ;
	traints->height = h ;
	traints->doubleBuffer = true ;
	traints->alpha = ds->getMinimumNumAlphaBits() ;
	traints->stencil = ds->getMinimumNumStencilBits() ;
	traints->sampleBuffers = ds->getMultiSamples() ;
	traints->samples = ds->getNumMultiSamples() ;

	return new osgQt::GraphicsWindowQt(traints.get()) ;
}

QWidget *MultiWidget::addViewWidget(osgQt::GraphicsWindowQt *gw , osg::Node *scene)
{
	osgViewer::View *view = new osgViewer::View ;
	addView(view) ;

	osg::Camera *camera = view->getCamera() ; //获取视图的主相机
	camera->setGraphicsContext(gw) ;

	const osg::GraphicsContext::Traits *traints = gw->getTraits() ;
//	camera->setClearColor(osg::Vec4(0.2 , 0.2 , 0.6 , 1.0)) ;
	camera->setViewport(new osg::Viewport(0 , 0 , traints->width , traints->height)) ;
	//正交方式设置正交投影矩阵
	camera->setProjectionMatrixAsPerspective(30.f , static_cast<double>(traints->width)/static_cast<double>(traints->height) , 1.0f , 10000.0f) ;

	view->addEventHandler(new osgViewer::StatsHandler) ;
	view->setCameraManipulator(new osgGA::TrackballManipulator) ;
	view->addEventHandler(new osgViewer::ThreadingHandler) ;
	view->addEventHandler(new osgViewer::WindowSizeHandler)  ;
	view->addEventHandler(new osgViewer::RecordCameraPathHandler) ;
	view->addEventHandler(new osgViewer::LODScaleHandler) ;
	view->addEventHandler(new osgViewer::ScreenCaptureHandler) ;
	view->setSceneData(scene) ;
	return gw->getGLWidget() ;
}

void MultiWidget::paintEvent(QPaintEvent *event)
{
	frame() ;
}
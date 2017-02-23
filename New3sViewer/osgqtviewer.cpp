#include "osgqtviewer.h"
#include <QHBoxLayout>
#include "KeyboardHandler.h"
#include <QCursor>
#include <QApplication>
#include "testeventhandle.h"

OsgQtViewer::OsgQtViewer(osgViewer::ViewerBase::ThreadingModel threadingModel /* = osgViewer::CompositeViewer::SingleThreaded */)
	:QWidget(),osgViewer::CompositeViewer()
{
	this->setAttribute(Qt::WA_DeleteOnClose) ;
	setThreadingModel(threadingModel) ;
	setKeyEventSetsDone(0) ;

	connect(&m_timer , SIGNAL(timeout()) , this , SLOT(update())) ;
	m_timer.start(10) ;
}

OsgQtViewer::OsgQtViewer(QWidget * parent /* = 0 */, Qt::WindowFlags f /* = 0  */, osgViewer::ViewerBase::ThreadingModel threadingModel /* = osgViewer::CompositeViewer::SingleThreaded */)
	:QWidget(parent , f),osgViewer::CompositeViewer()
{
	this->setAttribute(Qt::WA_DeleteOnClose) ;
	setThreadingModel(threadingModel) ;
	setKeyEventSetsDone(0) ;

	connect(&m_timer , SIGNAL(timeout()) , this , SLOT(update())) ;
	m_timer.start(10) ;
}

OsgQtViewer::~OsgQtViewer()
{

}

osgQt::GraphicsWindowQt *OsgQtViewer::createGraphicsWindow(int x , int y , int w , int h, const std::string &name /* = ""  */, bool windowDecoration /* = false */)
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

void OsgQtViewer::paintEvent(QPaintEvent *event)
{
	frame() ;
}

QWidget *OsgQtViewer::createViewWidget(osgQt::GraphicsWindowQt *gw , osg::Node *model)
{
	osgViewer::View *view = new osgViewer::View ;
	addView(view) ;

	osg::Camera *camera = view->getCamera() ; //获取视图的主相机
	camera->setGraphicsContext(gw) ;

	const osg::GraphicsContext::Traits *traints = gw->getTraits() ;
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
	view->addEventHandler(new KeyboardHandler) ;
//	view->addEventHandler(new TestEventHandle) ;
	view->setSceneData(model) ;
	return gw->getGLWidget() ;
}

void OsgQtViewer::setSceneData(osg::Node *model)
{
	m_model = model ;
	m_widget = createViewWidget(createGraphicsWindow(0 , 0 , width() , height()) , m_model) ;
	QHBoxLayout *hlayout = new QHBoxLayout() ;
	hlayout->addWidget(m_widget) ;
	this->setLayout(hlayout) ;	
}

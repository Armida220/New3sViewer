#ifndef OSGQTVIEWER_H
#define OSGQTVIEWER_H

#ifdef _DEBUG
#pragma comment(lib , "OpenThreadsd.lib")
#pragma comment(lib , "osgd.lib") 
#pragma comment(lib , "osgDBd.lib")
#pragma comment(lib , "osgUtild.lib")
#pragma comment(lib , "osgGAd.lib") 
#pragma comment(lib , "osgViewerd.lib")
#pragma comment(lib , "osgTextd.lib") 
#pragma comment(lib , "osgQtd.lib")

#else
#pragma comment(lib , "OpenThreads.lib")
#pragma comment(lib , "osg.lib") 
#pragma comment(lib , "osgDB.lib")
#pragma comment(lib , "osgUtil.lib")
#pragma comment(lib , "osgGA.lib") 
#pragma comment(lib , "osgViewer.lib")
#pragma comment(lib , "osgText.lib") 
#pragma comment(lib , "osgQt.lib")

#endif 

#include <QWidget>
#include <QTimer>
#include <osgViewer/CompositeViewer>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>
#include <osgQt/GraphicsWindowQt>
#include <osgViewer/ViewerEventHandlers>
#include <QMouseEvent>

class OsgQtViewer : public QWidget , public osgViewer::CompositeViewer
{
	Q_OBJECT

public:
	OsgQtViewer(osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::CompositeViewer::SingleThreaded) ;
	OsgQtViewer(QWidget * parent = 0, Qt::WindowFlags f = 0 , osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::CompositeViewer::SingleThreaded) ;
	~OsgQtViewer();
	void setSceneData(osg::Node *model) ;

protected:
	virtual void paintEvent(QPaintEvent *event) ;
private:
	osgQt::GraphicsWindowQt *createGraphicsWindow(int x , int y , int w , int h, const std::string &name = "" , bool windowDecoration = false) ;
	QWidget *createViewWidget(osgQt::GraphicsWindowQt *gw , osg::Node *model) ;
	QTimer m_timer ;
	osg::ref_ptr<osg::Node> m_model ;
	QWidget *m_widget ;
};

#endif // OSGQTVIEWER_H

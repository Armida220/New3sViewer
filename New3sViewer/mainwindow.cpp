#include "mainwindow.h"
#include <QResizeEvent>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <osgDB/ReadFile>
#include <osgDB/ReaderWriter>
#include <osgDB/FileUtils>
#include "SingleViewerWiget.h"
#include <osgGA/TrackballManipulator>
#include <osgGA/StateSetManipulator>
#include "osgqtviewer.h"
#include <QFileInfo>
#include "new3s_io.h"
#include "new3s_PointXYZ.h"
#include <vector>
#include <osgManipulator/TrackballDragger>
#include <osgManipulator/TranslateAxisDragger>
#include <osgManipulator/ScaleAxisDragger>
#include <osg/MatrixTransform>
#include <osgUtil/Optimizer>
#include <QTime>
#include <QtWidgets/QListWidgetItem>
#include "testeventhandle.h"
#include "Qtviewer.h"


mainwindow::mainwindow(QWidget *parent)
	: QMainWindow(parent),m_i(0),m_message("")
{
	ui.setupUi(this);

	m_viewerQt = new ViewerQT ;
	m_viewerQt->setCameraManipulator(new osgGA::TrackballManipulator) ;
	m_swroot = new osg::Switch() ;
	createActions() ;
	createMenus() ;
	createTools() ;

	setCentralWidget(m_viewerQt) ;
	setUnifiedTitleAndToolBarOnMac(true) ;


}

mainwindow::~mainwindow()
{
	if (m_viewerQt)
	{
		delete m_viewerQt ;
		m_viewerQt = NULL ;
	}
}

void mainwindow::createActions()
{
	m_openAct = new QAction(tr("&Open") , this) ;
	m_openAct->setIcon(QIcon("Resources\\openFile.png")) ;
	m_openAct->setStatusTip(QStringLiteral("打开文件")) ;
	connect(m_openAct , SIGNAL(triggered()) , this , SLOT(slot_open())) ;

	m_exitAct = new QAction(tr("&Exit") , this) ;
	m_exitAct->setIcon(QIcon("Resources\\Exit.png")) ;
	m_exitAct->setStatusTip(QStringLiteral("退出")) ; 
	connect(m_exitAct , SIGNAL(triggered()) , qApp , SLOT(quit())) ;

	m_tempteratureAct = new QAction(tr("&Temperature") , this) ;
	m_tempteratureAct->setIcon(QIcon("Resources\\tempterature.png")) ;
	m_tempteratureAct->setStatusTip(QStringLiteral("温度")) ;
	connect(m_tempteratureAct , SIGNAL(triggered()) , this , SLOT(slot_tempterature())) ;

	m_windAct = new QAction(tr("&Wind") , this) ;
	m_windAct->setIcon(QIcon("Resources\\wind.png")) ;
	m_windAct->setStatusTip(QStringLiteral("风偏")) ;
	connect(m_windAct , SIGNAL(triggered()) , this , SLOT(slot_wind())) ;

	m_overrideIceAct = new QAction(tr("OverrideIce") , this) ;
	m_overrideIceAct->setIcon(QIcon("Resources\\ice.png")) ;
	m_overrideIceAct->setStatusTip(QStringLiteral("覆冰")) ;
	connect(m_overrideIceAct , SIGNAL(triggered()) , this , SLOT(slot_Ice())) ;

	connect(this , SIGNAL(sendMessage(QString)) , this , SLOT(slot_receiveMessage(const QString))) ;
}

void mainwindow::createMenus()
{
	m_fileMenu = menuBar()->addMenu(tr("File")) ;
	m_fileMenu->addAction(m_openAct) ;
	m_fileMenu->addAction(m_exitAct) ;

	m_editMenu = menuBar()->addMenu(tr("Edit")) ;

	m_analyzeMenu = menuBar()->addMenu(tr("Analyze")) ;
	m_analyzeMenu->addAction(m_tempteratureAct) ;
	m_analyzeMenu->addAction(m_windAct) ;
	m_analyzeMenu->addAction(m_overrideIceAct) ;
}

void mainwindow::createTools()
{
	ui.mainToolBar->addAction(m_openAct) ;
	ui.mainToolBar->addAction(m_exitAct) ;
	ui.mainToolBar->addSeparator() ;

	ui.mainToolBar->addAction(m_tempteratureAct) ;
	ui.mainToolBar->addAction(m_windAct) ;
	ui.mainToolBar->addAction(m_overrideIceAct) ;
}


void mainwindow::resizeEvent(QResizeEvent *event)
{
	QMainWindow::resizeEvent(event);
}

void mainwindow::slot_open()
{
	QString fileName = QFileDialog::getOpenFileName(this , QStringLiteral("打开") , QString() , QStringLiteral("点云文件 (*.las) ;;三维模型(*.osg*)")) ;
	if (fileName.isEmpty())
	{
		QMessageBox::information(this , QStringLiteral("提示") , QStringLiteral("没有选择文件，请重新选择！")) ;
		return ;
	}
	QFileInfo info(fileName) ;
	//文件名
	QString filename = info.fileName() ;
	//文件目录
	QString filedir = info.filePath() ;
	//文件后缀名
	QString suffix = info.suffix() ;
	if (suffix == "osg")
	{
		osg::ref_ptr<osg::Node> node = osgDB::readNodeFile(filename.toStdString()) ;
		unsigned int num = m_swroot->getNumChildren() ;
		if (num > 0)
		{
			m_swroot->removeChildren(0 , num) ;
		}
		m_swroot->addChild(node) ;
	}
	else if (suffix == "las")
	{
		std::vector<new3s_PointXYZ> vec_cloud ;
		new3s_io io_act ;
		io_act.lasFileRead(fileName.toLocal8Bit().constData() ,vec_cloud) ;

		osg::ref_ptr<osg::Group> groot = new osg::Group() ;
		osg::ref_ptr<osg::Vec3Array> coord = new osg::Vec3Array() ;
		osg::ref_ptr<osg::Vec4Array> color = new osg::Vec4Array() ;
		int nums = vec_cloud.size() ;
		float r(0.0) , g(0.0) , b(0.0) ;
		for (int i = 0 ; i < nums ; ++i)
		{
			coord->push_back(osg::Vec3(vec_cloud[i].get_x() , vec_cloud[i].get_y() , vec_cloud[i].get_z())) ;
			color->push_back(osg::Vec4(r , g , b , 1.0)) ;
		}

		//创建几何特征
		osg::ref_ptr<osg::Geometry> geom = new osg::Geometry() ;
		//设置顶点数组
		geom->setVertexArray(coord.get()) ;
		geom->setColorArray(color.get()) ;
		geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX) ;

		osg::Vec3Array *normals = new osg::Vec3Array ;
		normals->push_back(osg::Vec3(0.0f , 1.0f , 0.0f)) ;
		geom->setNormalArray(normals) ;
		geom->setNormalBinding(osg::Geometry::BIND_OVERALL) ;
		geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS , 0 , nums)) ;

		osg::ref_ptr<osg::Geode> geode = new osg::Geode() ;
		geode->addDrawable(geom.get()) ;

		groot->addChild(geode.get()) ;
		groot->getOrCreateStateSet()->setMode(GL_NORMALIZE , osg::StateAttribute::ON) ;

		unsigned int num = m_swroot->getNumChildren() ;
		if (num > 0)
		{
			m_swroot->removeChildren(0 , num) ;
		}
		m_swroot->addChild(groot.get()) ;
	}

	osgUtil::Optimizer optimizer ;
	optimizer.optimize(m_swroot.get()) ;

	m_viewerQt->setSceneData(m_swroot.get()) ;
	print(QString(tr("load model finished!"))) ;
}

void mainwindow::slot_tempterature()
{

}

void mainwindow::slot_wind()
{

}

void mainwindow::slot_Ice()
{

}

void mainwindow::slot_zengrong()
{

}

void mainwindow::print(QString &str)
{
	QTime mytime = QTime::currentTime() ;
	QString str1 = QString("[ %1: %2: %3]:").arg(QString::number(mytime.hour())).arg(QString::number(mytime.minute())).arg(QString::number(mytime.second())) ;

	emit sendMessage(str1 + " " + str) ;
}

void mainwindow::slot_receiveMessage(const QString &str)
{
	m_message = str ;
	QListWidgetItem *item = new QListWidgetItem(m_message) ;
	ui.listWidget->insertItem(m_i , item) ;
	m_i++ ;
}

void mainwindow::mousePressEvent(QMouseEvent *event)
{
	QString str = "(" + QString::number(event->x()) + "," + QString::number(event->y()) + ")" ;
	if (event->button() == Qt::LeftButton)
	{
		QCursor cursor ;
		cursor.setShape(Qt::ClosedHandCursor) ;
		QApplication::setOverrideCursor(cursor) ;

		statusBar()->showMessage(QStringLiteral("左键：") + str) ;
	}

	QString str1 = "(" + QString::number(event->globalX()) + "," + QString::number(event->globalY()) + ")" ;
	print(str1) ;
}

void mainwindow::mouseReleaseEvent(QMouseEvent *event)
{
	QApplication::restoreOverrideCursor() ;
}
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <osg/Switch>
#include <QMouseEvent>
class QAction ;
class QMenu ;
class OsgQtViewer ;
class ViewerQT ;

class mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	mainwindow(QWidget *parent = 0);
	~mainwindow()                  ;
	void createActions()           ;
	void createMenus()             ;
	void createTools()             ;
public slots :
	void slot_open() ;
	void slot_tempterature() ;
	void slot_wind() ;
	void slot_Ice() ;
	void slot_zengrong() ;
	void slot_receiveMessage(const QString &str) ;

signals:
	void sendMessage(QString str) ;
protected:
	void resizeEvent(QResizeEvent *event) ;
	void print(QString &str) ;
	void mousePressEvent(QMouseEvent *event) ;
	void mouseReleaseEvent(QMouseEvent *event) ;
private:
	Ui::mainwindowClass ui;

	QMenu *m_fileMenu ;
	QAction *m_openAct ;
	QAction *m_exitAct ;

	QMenu *m_editMenu ;

	QMenu *m_analyzeMenu ;
	QAction *m_tempteratureAct ;
	QAction *m_windAct ;
	QAction *m_overrideIceAct ;
	QAction *m_zengrongAct ;

	ViewerQT *m_viewerQt ;
	
	OsgQtViewer *m_osgViewer ; 
	osg::ref_ptr<osg::Switch> m_swroot ; //根开关节点
	int m_i ;
	QString m_message ;
};

#endif // MAINWINDOW_H

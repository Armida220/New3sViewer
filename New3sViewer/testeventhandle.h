#ifndef TESTEVENTHANDLE_H
#define TESTEVENTHANDLE_H

#include <QObject>
#include <osgGA/GUIEventHandler>
#include <QString>

using namespace osgGA ;
class TestEventHandle : public QObject , public osgGA::GUIEventHandler
{
	Q_OBJECT

public:
	TestEventHandle();
	~TestEventHandle();

	bool handle(const GUIEventAdapter& ea,GUIActionAdapter& aa, osg::Object* ob, osg::NodeVisitor*nv) ;
signals:
	void sendMessage(QString str) ;
private:
	
};

#endif // TESTEVENTHANDLE_H

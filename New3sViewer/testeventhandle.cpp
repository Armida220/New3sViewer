#include "testeventhandle.h"
#include <osgViewer/Viewer>

TestEventHandle::TestEventHandle()
	: QObject()
{

}

TestEventHandle::~TestEventHandle()
{

}

bool TestEventHandle::handle(const GUIEventAdapter& ea,GUIActionAdapter& aa, osg::Object* ob, osg::NodeVisitor*nv)
{
	osgViewer::Viewer *viewer = dynamic_cast<osgViewer::Viewer *>(&aa) ;
	if (!viewer)
	{
		return false ;
	}
	switch (ea.getEventType())
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
		if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Space)
		{
			int width = ea.getWindowWidth() ;
			int height = ea.getWindowHeight() ;
			viewer->requestWarpPointer(width * 0.5 , height * 0.5) ;

			QString str = "(" + QString::number(width) + "," + QString::number(height) + ")" ;
			sendMessage(str) ;
		}
		break; 
	default:
		break;
	}
	return false ;
}

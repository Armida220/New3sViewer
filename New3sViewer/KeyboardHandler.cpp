#include "KeyboardHandler.h"
#include <osgViewer/Viewer>
#include <QMessageBox>
KeyboardHandler::KeyboardHandler(void)
{
}


KeyboardHandler::~KeyboardHandler(void)
{
}

bool KeyboardHandler::handle(const osgGA::GUIEventAdapter& ea , osgGA::GUIActionAdapter& aa , osg::Object* , osg::NodeVisitor* nv)
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
			
		}
		break; 
	default:
		break;
	}
	return false ;
}
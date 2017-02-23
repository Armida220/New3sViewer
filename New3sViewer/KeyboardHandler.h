#pragma once
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIEventHandler>

class KeyboardHandler :
	public osgGA::GUIEventHandler
{
public:
	KeyboardHandler(void);
	virtual ~KeyboardHandler(void);

	virtual bool handle(const osgGA::GUIEventAdapter& ea , osgGA::GUIActionAdapter& aa , osg::Object* , osg::NodeVisitor* nv) ;
};


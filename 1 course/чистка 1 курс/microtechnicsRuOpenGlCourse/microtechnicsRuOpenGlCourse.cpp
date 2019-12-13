#include "stdafx.h"

#include <QGLWidget>

class MainScene : public QGLWidget
{
protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

public:
	Scene3D(QWidget* parent = 0);
};
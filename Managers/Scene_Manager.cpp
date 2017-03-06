#include "Scene_Manager.h"
using namespace Managers;

int font=(int)GLUT_BITMAP_8_BY_13;

void setOrthographicProjection() {

	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, 640, 0, 360);
	// invert the y axis, down is positive
	glScalef(1, -1, 1);
	// mover the origin from the bottom left corner
	// to the upper left corner
	glTranslatef(0, -360, 0);
	glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() {
	// set the current matrix to GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	// restore previous settings
	glPopMatrix();
	// get back to GL_MODELVIEW matrix
	glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font,char *string)
{
	char *c;
	// set position to start drawing fonts
	glRasterPos2f(x, y);
	// loop all the characters in the string
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}


Scene_Manager::Scene_Manager(){

	glEnable(GL_DEPTH_TEST);
	models_manager = new Models_Manager();
	insect = glm::vec3(0.0,0.0,-100.0f);


}

Scene_Manager::~Scene_Manager(){
	delete models_manager;
}

void Scene_Manager::NotifyBeginFrame(){
	models_manager->Update(insect);
}

void Scene_Manager::NotifyDisplayFrame(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the viewport to be the entire window
	 glViewport(0, 0, 640, 360);
	float ratio = 1.0f * 640.0f / 360.0f;
	// Set the clipping volume
	gluPerspective(45,ratio,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f, 25.0f,
		0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f);
	glPushMatrix();
	models_manager->Draw();
	glPopMatrix();
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0.0f,1.0f,1.0f);
	renderBitmapString(30,15,(void *)font,"3D Frog Simulation");
	renderBitmapString(30,55,(void *)font,"");
	glPopMatrix();
	resetPerspectiveProjection();

}

void Scene_Manager::NotifyEndFrame(){

}

void Scene_Manager::NotifyReshape(int width, int height, int previos_width, int previous_height){

}

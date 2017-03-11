#include "Core/Init_GLUT.h"
#include "Managers/Scene_Manager.h"
#include "Core/WindowInfo.h"

using namespace Core;
using namespace Init;
int main(int argc, char **argv){

	WindowInfo window(640, 360);
	FramebufferInfo frameBufferInfo;

	Init::Init_GLUT::Init(window, frameBufferInfo,argc,argv);

	Managers::Scene_Manager* scene = new Managers::Scene_Manager();
	scene->window = window;
	Init::Init_GLUT::SetListener(scene);

	Init::Init_GLUT::Run();

	delete scene;
	return 0;
}

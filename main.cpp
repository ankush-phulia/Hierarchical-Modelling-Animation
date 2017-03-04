#include "Core/Init_GLUT.h"
#include "Managers/Scene_Manager.h"

using namespace Core;
using namespace Init;
int main(int argc, char **argv){

	WindowInfo window(640, 360);
	FramebufferInfo frameBufferInfo;

	Init::Init_GLUT::Init(window, frameBufferInfo,argc,argv);

	IListener* scene = new Managers::Scene_Manager();
	Init::Init_GLUT::SetListener(scene);

	Init::Init_GLUT::Run();

	delete scene;
	return 0;
}

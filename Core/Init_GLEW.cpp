#include "Init_GLEW.h"
using namespace Core;
using namespace Core::Init;

Core::Init::Init_GLEW::Init_GLEW() {}

Core::Init::Init_GLEW::~Init_GLEW() {}

void Init_GLEW::Init() {
    glewExperimental = true;

    if (glewInit() == GLEW_OK) {
        std::cout << "GLEW: Initialized" << std::endl;
    }

    if (glewIsSupported("GL_VERSION_4_3")) {
        std::cout << "GLEW GL_VERSION_4_3 is 4.3\n ";
    } else {
        std::cout << " GLEW GL_VERSION_4_3 not supported\n ";
    }
}

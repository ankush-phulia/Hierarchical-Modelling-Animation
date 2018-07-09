#pragma once
#include <GL/freeglut.h>
#include <GL/glew.h>
#include <iostream>
namespace Core {
namespace Init {
class Init_GLEW {
   public:
    Init_GLEW();
    ~Init_GLEW();

    static void Init();
};
}  // namespace Init
}  // namespace Core

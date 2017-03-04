#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>

namespace Core{

	struct FramebufferInfo{
		unsigned int flags;
		bool msaa;

		FramebufferInfo(){
			flags = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
			msaa = false;
		}

		FramebufferInfo(bool color, bool depth, bool stencil, bool msaaa){
			flags = GLUT_DOUBLE;
			if (color)
				flags |= GLUT_RGBA | GLUT_ALPHA;

			if (depth)
				flags |= GLUT_DEPTH;

			if (stencil)
				flags |= GLUT_STENCIL;

			msaa = msaaa;
			if (msaa)
				flags |= GLUT_MULTISAMPLE;


		}

		void operator=(const FramebufferInfo& info)	{
			flags = info.flags;
			msaa = info.msaa;
		}
	};
}

//GlutInit.h
#pragma once
#include "FrameBufferInfo.h"
#include "WindowInfo.h"
#include <iostream>
#include "Init_GLEW.h"
#include "IListener.h"

namespace Core {
	namespace Init {
		class Init_GLUT	{

		public:
			static void Init(const Core::WindowInfo& window, const Core::FramebufferInfo& framebufferInfo,int argc, char **argv);
			static void Run(void);
			static void Close();
			void EnterFullscreen();
			void ExitFullscreen();
			static void PrintOpenGLInfo(const Core::WindowInfo& windowInfo);
			static void SetListener(Core::IListener*& iListener);

		private:
			static void IdleCallback(void);
			static void DisplayCallback(void);
			static void ReshapeCallback(int width, int height);
			static void CloseCallback();
			static Core::IListener* listener;
			static Core::WindowInfo windowInformation;

		};

	}

}

#pragma once
#include "Model.h"

namespace Rendering {

	namespace Models{

		class Frog : public Models::Model{
		public:
			Frog();
			~Frog();
			GLuint texture;
			void Create();
			virtual void Draw()   override final;
			virtual void Update() override final;

		};

	}
}

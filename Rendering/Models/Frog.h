#pragma once
#include "Model.h"

namespace Rendering {

	namespace Models{

		class Frog : public Models::Model{
		public:
			Frog();
			~Frog();
			GLuint texture;
			glm::vec3 Position;
			void Create(glm::vec3 p);
			virtual void Draw()   override final;
			virtual void Update(glm::vec3 ins) override final;

		};

	}
}

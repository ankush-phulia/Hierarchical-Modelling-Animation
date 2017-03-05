#pragma once
#include "Rendering\\Models\Model.h"
#include "Managers\Scene_Manager.h"
#define PI 3.141

namespace Rendering {
	namespace Models {

		class Cuboid : public Model {
		public:
			Cuboid();
			~Cuboid();

			void Create();
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override final;
			virtual void Update() override final;

		private:
			glm::vec3 rotation, rotation_speed;

		};
	}
}
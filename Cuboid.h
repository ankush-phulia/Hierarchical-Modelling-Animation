#pragma once
#include "Rendering\\Models\Model.h"
#include "Managers\Scene_Manager.h"
#define PI 3.141
#define time 0.001f

namespace Rendering {
	namespace Models {

		class Cuboid : public Model {
		public:
			Cuboid();
			~Cuboid();

			void Create();
			//vertices in anti-clockwise order, starting from 3rd quad
			void Create(glm::vec3 fv1, glm::vec3 fc1, glm::vec3 fv2, glm::vec3 fc2, glm::vec3 fv3, glm::vec3 fc3, glm::vec3 fv4, glm::vec3 fc4, //front
				glm::vec3 rv1, glm::vec3 rc1, glm::vec3 rv2, glm::vec3 rc2, glm::vec3 rv3, glm::vec3 rc3, glm::vec3 rv4, glm::vec3 rc4,			//right
				glm::vec3 bv1, glm::vec3 bc1, glm::vec3 bv2, glm::vec3 bc2, glm::vec3 bv3, glm::vec3 bc3, glm::vec3 bv4, glm::vec3 bc4,			//back
				glm::vec3 lv1, glm::vec3 lc1, glm::vec3 lv2, glm::vec3 lc2, glm::vec3 lv3, glm::vec3 lc3, glm::vec3 lv4, glm::vec3 lc4,			//left
				glm::vec3 tv1, glm::vec3 tc1, glm::vec3 tv2, glm::vec3 tc2, glm::vec3 tv3, glm::vec3 tc3, glm::vec3 tv4, glm::vec3 tc4,			//top
				glm::vec3 uv1, glm::vec3 uc1, glm::vec3 uv2, glm::vec3 uc2, glm::vec3 uv3, glm::vec3 uc3, glm::vec3 uv4, glm::vec3 uc4,			//under
				glm::vec3 offset, glm::vec3 speed, glm::vec3 rotation, glm::vec3 angular_speed);		
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override final;
			virtual void Update() override final;

		private:
			glm::vec3 translation, translation_speed, rotation, rotation_speed;

		};
	}
}
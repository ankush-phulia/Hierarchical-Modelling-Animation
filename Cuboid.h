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
			void CreateT();
			//vertices in anti-clockwise order, starting from 3rd quad
			void Create(glm::vec3 fv1, glm::vec4 fc1, glm::vec3 fv2, glm::vec4 fc2, glm::vec3 fv3, glm::vec4 fc3, glm::vec3 fv4, glm::vec4 fc4,
				glm::vec3 rv1, glm::vec4 rc1, glm::vec3 rv2, glm::vec4 rc2, glm::vec3 rv3, glm::vec4 rc3, glm::vec3 rv4, glm::vec4 rc4,
				glm::vec3 bv1, glm::vec4 bc1, glm::vec3 bv2, glm::vec4 bc2, glm::vec3 bv3, glm::vec4 bc3, glm::vec3 bv4, glm::vec4 bc4,
				glm::vec3 lv1, glm::vec4 lc1, glm::vec3 lv2, glm::vec4 lc2, glm::vec3 lv3, glm::vec4 lc3, glm::vec3 lv4, glm::vec4 lc4,
				glm::vec3 tv1, glm::vec4 tc1, glm::vec3 tv2, glm::vec4 tc2, glm::vec3 tv3, glm::vec4 tc3, glm::vec3 tv4, glm::vec4 tc4,
				glm::vec3 uv1, glm::vec4 uc1, glm::vec3 uv2, glm::vec4 uc2, glm::vec3 uv3, glm::vec4 uc3, glm::vec3 uv4, glm::vec4 uc4,
				glm::vec3 offset, glm::vec3 speed, glm::vec3 rot, glm::vec3 angular_speed);

			void Create(glm::vec3 fv1, glm::vec2 fc1, glm::vec3 fv2, glm::vec2 fc2, glm::vec3 fv3, glm::vec2 fc3, glm::vec3 fv4, glm::vec2 fc4, //front
				glm::vec3 rv1, glm::vec2 rc1, glm::vec3 rv2, glm::vec2 rc2, glm::vec3 rv3, glm::vec2 rc3, glm::vec3 rv4, glm::vec2 rc4,			//right
				glm::vec3 bv1, glm::vec2 bc1, glm::vec3 bv2, glm::vec2 bc2, glm::vec3 bv3, glm::vec2 bc3, glm::vec3 bv4, glm::vec2 bc4,			//back
				glm::vec3 lv1, glm::vec2 lc1, glm::vec3 lv2, glm::vec2 lc2, glm::vec3 lv3, glm::vec2 lc3, glm::vec3 lv4, glm::vec2 lc4,			//left
				glm::vec3 tv1, glm::vec2 tc1, glm::vec3 tv2, glm::vec2 tc2, glm::vec3 tv3, glm::vec2 tc3, glm::vec3 tv4, glm::vec2 tc4,			//top
				glm::vec3 uv1, glm::vec2 uc1, glm::vec3 uv2, glm::vec2 uc2, glm::vec3 uv3, glm::vec2 uc3, glm::vec3 uv4, glm::vec2 uc4,			//under
				glm::vec3 offset, glm::vec3 speed, glm::vec3 rot, glm::vec3 angular_speed);
			
			virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override final;
			virtual void Update() override final;

		private:
			glm::vec3 translation, translation_speed, rotation, rotation_speed;

		};
	}
}
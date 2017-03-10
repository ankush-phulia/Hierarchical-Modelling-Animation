#pragma once
#include "Model.h"

namespace Rendering {

	namespace Models{

		class Frog : public Models::Model{
		public:
			Frog();
			~Frog();
			GLuint texture;
			glm::vec3 Position,Direction,nPosition;;
			float velocity,tim,ang,nang;
			//GLfloat theta[10],in[10],out[10];
			GLfloat theta[10] = {0.0,75.0,-60.0,0.0,50.0,30.0,-100.0,20.0,30.0,150.0};
			GLfloat in[10] = {90.0,75.0,-60.0,0.0,50.0,30.0,-100.0,20.0,30.0,150.0}; //start-end
			GLfloat out[10] = {0.0,30.0,-30.0,0.0,60.0,30.0,-20.0,160.0,0.0,10.0};// mid-air

			GLUquadricObj *t, *gl, *h, *ua, *la, *ll, *ul;

			void torso();
			void head();
			void glass_bot();
			void shoulder_joints();
			void elbow_joints();
			void palms();
			void leg_joints();
			void knee_joints();
			void torso_disk();
			void left_upper_arm();
			void left_lower_arm();
			void right_upper_arm();
			void right_lower_arm();
			void left_upper_leg();
			void left_lower_leg();
			void right_upper_leg();
			void right_lower_leg();

			int mode;
			void Create(glm::vec3 p);
			virtual void Draw()   override final;
			virtual void Update(glm::vec3 ins,std::map<std::string, IGameObject*> passinggameModelList) override final;

		};

	}
}

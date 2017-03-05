#pragma once
#include "Model.h"

namespace Rendering {

	namespace Models{

		class Quad : public Models::Model{
		public:
			using IGameObject::Draw;
			Quad();			
			~Quad();

			void Create();
			void Create(double x1, double y1, double z1, double r1, double b1, double g1,
				double x2, double y2, double z2, double r2, double b2, double g2,
				double x3, double y3, double z3, double r3, double b3, double g3,
				double x4, double y4, double z4, double r4, double b4, double g4);
			virtual void Draw()   override final;
			virtual void Update() override final;

		};

	}
}
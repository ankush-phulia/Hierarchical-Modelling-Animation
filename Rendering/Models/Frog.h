#pragma once
#include "Model.h"

namespace Rendering {

	namespace Models{

		class Frog : public Models::Model{
		public:
			Frog();
			~Frog();

			void Create();
			virtual void Draw()   override final;
			virtual void Update() override final;

		};

	}
}

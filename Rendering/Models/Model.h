#pragma once
#include <vector>
#include "../IGameObject.h"
namespace Rendering{

	namespace Models{

		class Model :virtual public IGameObject	{

		public:
			Model();
			virtual ~Model();

			virtual void Draw()             override;
			virtual void Update(glm::vec3 ins)           override;
			virtual void Destroy()          override;

		};
	}
}

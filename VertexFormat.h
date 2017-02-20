#ifndef  VertexFormat_H
#define VertexFormat_H

#include "glm\glm.hpp"

struct VertexFormat{
	glm::vec3 position;
	VertexFormat(const glm::vec3 &pos){
		position = pos;
	}
};

#endif

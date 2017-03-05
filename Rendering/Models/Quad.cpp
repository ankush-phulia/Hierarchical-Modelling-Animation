#include "Quad.h"
using namespace Rendering;
using namespace Models;

Quad::Quad(){

}

Quad::~Quad(){

}

void Quad::Create(){
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.5, 0.0),
		glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.75, 0.0),
		glm::vec4(0, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.5, 0.0),
		glm::vec4(0, 1, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.75, 0.0),
		glm::vec4(0, 0, 1, 1)));


	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 4, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Quad::Create(double x1, double y1, double z1, double r1, double b1, double g1,
	double x2, double y2, double z2, double r2, double b2, double g2,
	double x3, double y3, double z3, double r3, double b3, double g3,
	double x4, double y4, double z4, double r4, double b4, double g4){
	
	GLuint vao;
	GLuint vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(glm::vec3(x1, y1, z1),
		glm::vec4(r1, b1, g1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(x2, y2, z2),
		glm::vec4(r2, b2, g2, 1)));
	vertices.push_back(VertexFormat(glm::vec3(x3, y3, z3),
		glm::vec4(r3, b3, g3, 1)));
	vertices.push_back(VertexFormat(glm::vec3(x4, y4, z4),
		glm::vec4(r4, b4, g4, 1)));


	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 4, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Quad::Update(){


}

void Quad::Draw(){
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
#include "Cuboid.h"

using namespace Rendering;
using namespace Models;

Cuboid::Cuboid(){

}

Cuboid::~Cuboid(){

}

void Cuboid::Create(){
	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	std::vector<unsigned int>  indices = { 0,  1,  2,  0,  2,  3,   //front
		4,  5,  6,  4,  6,  7,   //right
		8,  9,  10, 8,  10, 11,  //back
		12, 13, 14, 12, 14, 15,  //left
		16, 17, 18, 16, 18, 19,  //upper
		20, 21, 22, 20, 22, 23 }; //bottom
	//front
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec4(0, 0, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec4(1, 0, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec4(0, 1, 1, 1)));
	//right
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec4(1, 1, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec4(1, 0, 1, 1)));
	//back
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec4(0, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec4(1, 1, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec4(0, 1, 0, 1)));
	//left
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec4(0, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec4(0, 0, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec4(0, 1, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec4(0, 1, 0, 1)));
	//upper
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec4(0, 1, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec4(0, 1, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec4(1, 1, 0, 1)));
	//bottom
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec4(0, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec4(1, 0, 1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec4(0, 0, 1, 1)));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexFormat), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
	this->vbos.push_back(ibo);

	translation = glm::vec3(0.0, 0.0, 0.0);
	translation_speed = glm::vec3(0.0, 0.0, 0.0);

	rotation_speed = glm::vec3(0.0, 0.0, 0.0);
	rotation = glm::vec3(0.0, 0.0, 0.0);
}

void Cuboid::CreateT() {
	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	std::vector<unsigned int>  indices = { 0,  1,  2,  0,  2,  3,   //front
		4,  5,  6,  4,  6,  7,   //right
		8,  9,  10, 8,  10, 11 ,  //back
		12, 13, 14, 12, 14, 15,  //left
		16, 17, 18, 16, 18, 19,  //upper
		20, 21, 22, 20, 22, 23 }; //bottom
	//front
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec2(0, 1)));
	//right
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec2(0, 1)));
	//back
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec2(0, 1)));
	//left
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec2(0, 1)));
	//upper
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, 1.0), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, 1.0), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, 1.0, -1.0), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, 1.0, -1.0), glm::vec2(0, 1)));
	//bottom
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, -1.0), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, -1.0), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0, -1.0, 1.0), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0, -1.0, 1.0), glm::vec2(0, 1)));


	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexFormat), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::texture)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
	this->vbos.push_back(ibo);

	translation = glm::vec3(0.0, 0.0, 0.0);
	translation_speed = glm::vec3(0.0, 0.0, 0.0);

	rotation_speed = glm::vec3(0.0, 0.0, 0.0);
	rotation = glm::vec3(0.0, 0.0, 0.0);
}

void Cuboid::Update(){

}

void Rendering::Models::Cuboid::Create(glm::vec3 fv1, glm::vec4 fc1, glm::vec3 fv2, glm::vec4 fc2, glm::vec3 fv3, glm::vec4 fc3, glm::vec3 fv4, glm::vec4 fc4,
	glm::vec3 rv1, glm::vec4 rc1, glm::vec3 rv2, glm::vec4 rc2, glm::vec3 rv3, glm::vec4 rc3, glm::vec3 rv4, glm::vec4 rc4, 
	glm::vec3 bv1, glm::vec4 bc1, glm::vec3 bv2, glm::vec4 bc2, glm::vec3 bv3, glm::vec4 bc3, glm::vec3 bv4, glm::vec4 bc4, 
	glm::vec3 lv1, glm::vec4 lc1, glm::vec3 lv2, glm::vec4 lc2, glm::vec3 lv3, glm::vec4 lc3, glm::vec3 lv4, glm::vec4 lc4, 
	glm::vec3 tv1, glm::vec4 tc1, glm::vec3 tv2, glm::vec4 tc2, glm::vec3 tv3, glm::vec4 tc3, glm::vec3 tv4, glm::vec4 tc4, 
	glm::vec3 uv1, glm::vec4 uc1, glm::vec3 uv2, glm::vec4 uc2, glm::vec3 uv3, glm::vec4 uc3, glm::vec3 uv4, glm::vec4 uc4,
	glm::vec3 offset, glm::vec3 speed, glm::vec3 rot, glm::vec3 angular_speed)
{
	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	std::vector<unsigned int>  indices = { 0,  1,  2,  0,  2,  3,   //front
		4,  5,  6,  4,  6,  7,   //right
		8,  9,  10, 8,  10, 11,  //back
		12, 13, 14, 12, 14, 15,  //left
		16, 17, 18, 16, 18, 19,  //upper
		20, 21, 22, 20, 22, 23 }; //bottom

	//front
	vertices.push_back(VertexFormat(fv1, fc1));
	vertices.push_back(VertexFormat(fv2, fc2));
	vertices.push_back(VertexFormat(fv3, fc3));
	vertices.push_back(VertexFormat(fv4, fc4));
	//right
	vertices.push_back(VertexFormat(rv1, rc1));
	vertices.push_back(VertexFormat(rv2, rc2));
	vertices.push_back(VertexFormat(rv3, rc3));
	vertices.push_back(VertexFormat(rv4, rc4));
	//back
	vertices.push_back(VertexFormat(bv1, bc1));
	vertices.push_back(VertexFormat(bv2, bc2));
	vertices.push_back(VertexFormat(bv3, bc3));
	vertices.push_back(VertexFormat(bv4, bc4));
	//left
	vertices.push_back(VertexFormat(lv1, lc1));
	vertices.push_back(VertexFormat(lv2, lc2));
	vertices.push_back(VertexFormat(lv3, lc3));
	vertices.push_back(VertexFormat(lv4, lc4));
	//top
	vertices.push_back(VertexFormat(tv1, tc1));
	vertices.push_back(VertexFormat(tv2, tc2));
	vertices.push_back(VertexFormat(tv3, tc3));
	vertices.push_back(VertexFormat(tv4, tc4));
	//bottom
	vertices.push_back(VertexFormat(uv1, uc1));
	vertices.push_back(VertexFormat(uv2, uc2));
	vertices.push_back(VertexFormat(uv3, uc3));
	vertices.push_back(VertexFormat(uv4, uc4));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexFormat), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
	this->vbos.push_back(ibo);

	translation = offset;
	translation_speed = speed;

	rotation_speed = angular_speed;
	rotation = rot;
}

void Rendering::Models::Cuboid::Create(glm::vec3 fv1, glm::vec2 fc1, glm::vec3 fv2, glm::vec2 fc2, glm::vec3 fv3, glm::vec2 fc3, glm::vec3 fv4, glm::vec2 fc4, glm::vec3 rv1, glm::vec2 rc1, glm::vec3 rv2, glm::vec2 rc2, glm::vec3 rv3, glm::vec2 rc3, glm::vec3 rv4, glm::vec2 rc4, glm::vec3 bv1, glm::vec2 bc1, glm::vec3 bv2, glm::vec2 bc2, glm::vec3 bv3, glm::vec2 bc3, glm::vec3 bv4, glm::vec2 bc4, glm::vec3 lv1, glm::vec2 lc1, glm::vec3 lv2, glm::vec2 lc2, glm::vec3 lv3, glm::vec2 lc3, glm::vec3 lv4, glm::vec2 lc4, glm::vec3 tv1, glm::vec2 tc1, glm::vec3 tv2, glm::vec2 tc2, glm::vec3 tv3, glm::vec2 tc3, glm::vec3 tv4, glm::vec2 tc4, glm::vec3 uv1, glm::vec2 uc1, glm::vec3 uv2, glm::vec2 uc2, glm::vec3 uv3, glm::vec2 uc3, glm::vec3 uv4, glm::vec2 uc4, glm::vec3 offset, glm::vec3 speed, glm::vec3 rot, glm::vec3 angular_speed){
	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	std::vector<unsigned int>  indices = { 0,  1,  2,  0,  2,  3,   //front
		4,  5,  6,  4,  6,  7,   //right
		8,  9,  10, 8,  10, 11,  //back
		12, 13, 14, 12, 14, 15,  //left
		16, 17, 18, 16, 18, 19,  //upper
		20, 21, 22, 20, 22, 23 }; //bottom
	//front
	vertices.push_back(VertexFormat(fv1, fc1));
	vertices.push_back(VertexFormat(fv2, fc2));
	vertices.push_back(VertexFormat(fv3, fc3));
	vertices.push_back(VertexFormat(fv4, fc4));
	//right
	vertices.push_back(VertexFormat(rv1, rc1));
	vertices.push_back(VertexFormat(rv2, rc2));
	vertices.push_back(VertexFormat(rv3, rc3));
	vertices.push_back(VertexFormat(rv4, rc4));
	//back
	vertices.push_back(VertexFormat(bv1, bc1));
	vertices.push_back(VertexFormat(bv2, bc2));
	vertices.push_back(VertexFormat(bv3, bc3));
	vertices.push_back(VertexFormat(bv4, bc4));
	//left
	vertices.push_back(VertexFormat(lv1, lc1));
	vertices.push_back(VertexFormat(lv2, lc2));
	vertices.push_back(VertexFormat(lv3, lc3));
	vertices.push_back(VertexFormat(lv4, lc4));
	//top
	vertices.push_back(VertexFormat(tv1, tc1));
	vertices.push_back(VertexFormat(tv2, tc2));
	vertices.push_back(VertexFormat(tv3, tc3));
	vertices.push_back(VertexFormat(tv4, tc4));
	//bottom
	vertices.push_back(VertexFormat(uv1, uc1));
	vertices.push_back(VertexFormat(uv2, uc2));
	vertices.push_back(VertexFormat(uv3, uc3));
	vertices.push_back(VertexFormat(uv4, uc4));

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexFormat), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
	this->vbos.push_back(ibo);

	translation = offset;
	translation_speed = speed;

	rotation_speed = angular_speed;
	rotation = rot;
}

void Cuboid::Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix){

	rotation = time * rotation_speed + rotation;
	translation = time * translation_speed + translation;

	glm::vec3 rotation_sin = glm::vec3(rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180);

	glUseProgram(program);
	glBindVertexArray(vao);

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, this->GetTexture("frog"));
	//unsigned int textureLocation = glGetUniformLocation(program, "skin");
	//glUniform1i(textureLocation, 0);

	glUniform3f(glGetUniformLocation(program, "rotation"), rotation_sin.x, rotation_sin.y, rotation_sin.z);
	glUniform3f(glGetUniformLocation(program, "translation"), translation.x, translation.y, translation.z);
	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &view_matrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projection_matrix[0][0]);
		
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
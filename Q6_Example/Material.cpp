#include "Material.h"



Material::Material()
{

}


Material::~Material()
{
}

void Material::SetRubyMaterial()
{

	GLfloat matAmbient[] = { 0.1745,0.01175,0.01175, 1.0f };
	GLfloat matDiffuse[] = { 0.61424,0.04136,0.04136, 1.0f };
	GLfloat matSpecular[] = { 0.727811,0.626959,0.626959, 1.0f };
	GLfloat shininess = 0.6* 128.0f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void Material::SetWhiteMaterial()
{

	GLfloat matAmbient[] = { 0.25f, 0.20725f, 0.20725f, 0.922f };
	GLfloat matDiffuse[] = { 1.0f, 0.829f, 0.829f, 0.922f };
	GLfloat matSpecular[] = { 0.296648f, 0.296648f, 0.296648f, 0.922f };
	GLfloat shininess = 11.264f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void Material::SetBlackMaterial()
{
	GLfloat matAmbient[] = { 0.05375f, 0.05f, 0.06625f, 0.82f };
	GLfloat matDiffuse[] = { 0.18275f, 0.17f, 0.22525f, 0.82f };
	GLfloat matSpecular[] = { 0.332741f, 0.328634f, 0.346435f, 0.82f };
	GLfloat shininess = 38.4f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}


void Material::SetBrassMaterial()
{
	GLfloat matAmbient[] = { 0.329412,0.223529,0.027451, 1.0f };
	GLfloat matDiffuse[] = { 0.780392,0.568627,0.113725, 1.0f };
	GLfloat matSpecular[] = { 0.992157,0.941176,0.807843, 1.0f };
	GLfloat shininess = 0.21794872f* 128.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void Material::SetCyanMaterial()
{
	GLfloat matAmbient[] = { 0.0f,0.1f,0.06f ,1.0f };
	GLfloat matDiffuse[] = { 0.0f,0.50980392f,0.50980392f,1.0f };
	GLfloat matSpecular[] = { 0.50196078f,0.50196078f,0.50196078f,1.0f };
	GLfloat shininess = 32.0f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void Material::SetTurqoiseMaterial()
{
	GLfloat matAmbient[] = { 0.1f, 0.18725f, 0.1745f, 0.8f };
	GLfloat matDiffuse[] = { 0.396f, 0.74151f, 0.69102f, 0.8f };
	GLfloat matSpecular[] = { 0.297254f, 0.30829f, 0.306678f, 0.8f };
	GLfloat shininess = 12.8f;
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

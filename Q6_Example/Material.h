#pragma once
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

class Material
{
public:
	static void SetRubyMaterial();
	static void SetBrassMaterial();
	static void SetWhiteMaterial();
	static void SetBlackMaterial();
	static void SetCyanMaterial();
	static void SetTurqoiseMaterial();
	Material();
	~Material();
};


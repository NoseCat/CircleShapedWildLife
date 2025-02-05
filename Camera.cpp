#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera* Camera::getInstance()
{
	if (!instance) instance = new Camera();
	return instance;
}

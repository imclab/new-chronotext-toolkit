#pragma once

#include "cinder/gl/gl.h"
#include "cinder/Camera.h"

const ci::Matrix44f getPerspectiveMatrix(float fovy, float aspect, float zNear, float zFar);
const ci::Matrix44f getPerspectiveMatrix(float fovy, float zNear, float zFar, float width, float height, float panX = 0, float panY = 0, float zoom = 1);
const ci::Matrix44f getFrustumMatrix(float left, float right, float bottom, float top, float znear, float zfar);

void dumpCamera(const ci::Camera &cam, const std::string &name = "cam");

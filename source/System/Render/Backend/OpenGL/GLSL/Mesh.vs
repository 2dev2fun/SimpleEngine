#version 330 core

layout (location=0) in vec3 aPosition;
layout (location=1) in vec3 aNormal;
layout (location=2) in vec2 aTexCoord;

uniform mat4 uWorldTransform;
uniform mat4 uViewProjection;

void main() {
	gl_Position = uViewProjection * uWorldTransform * vec4(aPosition.xyz, 1.0f);
}

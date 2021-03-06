#version 130

in vec2 position;

out vec4 pos;

uniform mat4 perspective = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 model = mat4(1.0);

void main() {
	/*
	if (position.x == -0.5f && position.y == -0.5f)
		gl_Position = perspective * view * model * vec4(-0.5f, -0.5f, 0.0, 1.0);
	else if (position.x == -0.5f && position.y == 0.5f)
		gl_Position = perspective * view * model * vec4(-0.5f, 0.5f, 0.0f, 1.0f);
	else if (position.x == 0.5f && position.y == 0.5f)
		gl_Position = perspective * view * model * vec4(0.5f, 0.5f, 0.0f, 1.0f);
	else
		gl_Position = perspective * view * model * vec4(0.5f, -0.5f, 0.0f, 1.0f);
	*/
	gl_Position = perspective * view * model * vec4(position.x, position.y, 0.0f, 1.0f);
	pos = gl_Position;
}
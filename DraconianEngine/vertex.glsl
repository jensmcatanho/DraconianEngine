#version 130

in vec2 position;

out vec4 pos;

uniform mat4 perspective = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 model = mat4(1.0);

void main() {
	gl_Position = perspective * view * model * vec4(position.x, position.y, 0.0, 1.0);
	pos = gl_Position;
}
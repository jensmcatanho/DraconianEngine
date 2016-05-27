#version 130

in vec4 pos;

out vec4 outColor;

uniform vec2 light_pos;

void main() {
	float intensity = 1.0 / length(pos.xy - light_pos);
	outColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
	outColor = outColor * intensity;

}
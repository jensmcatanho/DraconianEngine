#version 130

in vec4 pos;
in vec4 col;

out vec4 outColor;

uniform vec2 light_pos;

void main() {
	float intensity = 1.0 / length(pos.xy - light_pos);
	//outColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
	
	if (pos.x <= 0 && pos.x >= -0.49f && pos.y <= 0 && pos.y >= -0.49f)
		outColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	else
		outColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	//outColor = outColor * intensity;

}
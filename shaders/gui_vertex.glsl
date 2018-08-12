#version 120
vec3 position;

varying vec3 color;
varying vec3 ourColor;

void main() {
    gl_Position = vec4(position.x, 0, position.z, 0);
    ourColor = color;
}

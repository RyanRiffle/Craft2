#version 120

uniform sampler2D sampler;
uniform bool is_sign;
uniform bool darken_background;

varying vec2 fragment_uv;

void main() {
    vec4 color = texture2D(sampler, fragment_uv);
    if (is_sign) {
        if (color == vec4(1.0)) {
            discard;
        }
    }
    else {
        if (darken_background)
            color.a = max(color.a, 0.4);
    }
    gl_FragColor = color;
}

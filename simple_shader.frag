#version 450


//El cualificador layout toma un valor de localizacion
//Lo declaramos como un output con out y lo establecemos como un vec4
//outColor es la variable que creamos

layout (location = 0) out vec4 outColor;

void main() {
	outColor = vec4(1.0, 0.0, 0.0, 1.0);
}
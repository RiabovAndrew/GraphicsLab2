#include <iostream>
#include <windows.h>
#include <cmath>
#include <numbers>
//#include "GLRenderSystem.h"
//#include "GLWindow.h"

#define GLUT_DISABLE_ATEXIT_HACK
#include "libs\GL_AL\glew.h"
#include "libs\GL_AL\glfw3.h"
#include <iso646.h>
using namespace std;

template< typename T >
void println(T i) {
	cout << i << endl;
}

void argsEcho(int argc, char** argv) {
	println("____ARGS____");
	if (argc == 0) {
		println("NO ARGS");
	}
	else {
		for (int i = 0; i < argc; i++) {
			println(argv[i]);
		}
	}
	println("____________\n");
}
int main(int argc, char** argv) {

	argsEcho(argc, argv);
	println("Hello World\nAuthor: Riabov Andrey");
	if (!glfwInit()) {
		fprintf(stderr, "Ошибка при инициализации GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(640, 480, "Lesson 01 - RAINBOW - Рябов Андрей ПА-18-2", nullptr, nullptr);

	if (!window) {
		fprintf(
			stderr,
			"Невозможно открыть окно GLFW. Если у вас Intel GPU, то он не поддерживает версию 3.3. Попробуйте версию уроков для OpenGL 2.1.\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Невозможно инициализировать GLEW\n");
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	float color_rgb = 0.0;
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS and glfwWindowShouldClose(window) == 0) {
		glClearColor(sin(color_rgb * numbers::pi / 180), abs(cos(color_rgb * numbers::pi / 180)),
		             abs(sin(color_rgb * numbers::pi / 180) + cos(color_rgb * numbers::pi / 180)), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
		color_rgb <= 180 ? color_rgb += 0.1 : color_rgb = 0;
	}

	glfwTerminate();
	return 0;
}

#include "lve_window.hpp"

#include <stdexcept>
namespace lve {

	LveWindow::LveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName(name) { //Utilizamos una lista de inicializacion de miembros
		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window); //Le pasamos el pointer a nuestra ventana
		glfwTerminate();
	}

	void LveWindow::initWindow() { 

		glfwInit(); //Inicializamos la libreria glfw

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //Evitamos que inicie un contexto de OpenGL, desactivamos esta funcionalidad con NO_API
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //Evitamos window resizing despues de la inicializacion de la ventana

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create window surface");
		}
	}

}
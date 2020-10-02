#ifndef GLWINDOW_H
#define GLWINDOW_H

namespace rory {
	class GLWindow {
	public:
		GLWindow(const std::string& title, uint32_t width, uint32_t height);
		GLWindow(const std::string& title, uint32_t width, uint32_t height, GLFWwindow* share);

		~GLWindow() {
			glfwDestroyWindow(handle);
		};
		[[nodiscard]] uint32_t getWidth() const;
		[[nodiscard]] uint32_t getHeight() const;
		[[nodiscard]] GLFWwindow* getGLFWHandle() const;
	private:
		// TODO
	};
}
#endif /* GLWINDOW_H */

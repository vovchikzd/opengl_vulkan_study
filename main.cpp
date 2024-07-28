#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <print>

using std::println;

auto main() -> int {
  if (!glfwInit()) {
    println(stderr, "GLFW Initialisation failed");
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow* main_window = glfwCreateWindow(480, 270, "First created GLFW window", NULL, NULL);
  if (!main_window) {
    println(stderr, "GLFW windod creation failed");
    glfwTerminate();
    return EXIT_FAILURE;
  }

  int buffer_width, buffer_height;
  glfwGetFramebufferSize(main_window, &buffer_width, &buffer_height);
}

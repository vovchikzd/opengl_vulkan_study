#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <print>
#include <iostream>

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

  GLFWwindow* main_window =
      glfwCreateWindow(960, 540, "OpenGL study", NULL, NULL);
  if (!main_window) {
    println(stderr, "GLFW windod creation failed");
    glfwTerminate();
    return EXIT_FAILURE;
  }

  int buffer_width, buffer_height;
  glfwGetFramebufferSize(main_window, &buffer_width, &buffer_height);

  glfwMakeContextCurrent(main_window);

  glewExperimental = GL_TRUE;

  const GLenum err = glewInit();
  if (err != GLEW_OK) {
    println(stderr, "GLEW initialisation failed");
    std::cerr << glewGetErrorString(err) << '\n';
    glfwDestroyWindow(main_window);
    glfwTerminate();
    return EXIT_FAILURE;
  }

  glViewport(0, 0, buffer_width, buffer_height);

  while(!glfwWindowShouldClose(main_window)) {
    glfwPollEvents();
    glClearColor(1.0f, 0.0f, 1.0f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(main_window);
  }

  return EXIT_SUCCESS;
}

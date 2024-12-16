#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  // Инициализация GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  // Wayland
  glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

  // Создание окна
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Hello Wayland", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // Сделать контекст текущим
  glfwMakeContextCurrent(window);

  // Основной цикл
  while (!glfwWindowShouldClose(window)) {
    // Обработка событий
    glfwPollEvents();

    // Очистка окна
    glClear(GL_COLOR_BUFFER_BIT);

    // Смена буферов
    glfwSwapBuffers(window);
  }

  // Завершение работы GLFW
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}

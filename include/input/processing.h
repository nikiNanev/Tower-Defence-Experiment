#ifndef _INPUT_PROCESSING_H
#define _INPUT_PROCESSING_H

class InputProcessing
{

public:
	InputProcessing() {}
	~InputProcessing() {}
	void keyboard_input(GLFWwindow *window, float deltaTime)
	{

		// Debug/Status
		std::cout << deltaTime << std::endl;

		glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

		const float cameraSpeed = 0.05f;

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		// Camera controls
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			cameraPos += cameraSpeed * cameraFront;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			cameraPos -= cameraSpeed * cameraFront;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

		// // Toggle Fullscreen
		// if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
		// {
		// 	if (win_manager->getState() != 0)
		// 		win_manager->toggleWindowSizes(window, 1);
		// 	else
		// 		win_manager->toggleWindowSizes(window, 0);
		// }

		// if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
		// {
		// 	if (win_manager->getState() != 2)
		// 		win_manager->toggleWindowSizes(window, 2);
		// }

		// if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
		// {
		// 	if (win_manager->getState() != 3)
		// 		win_manager->toggleWindowSizes(window, 3);
		// }
	}
};

#endif

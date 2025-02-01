#include "../include/lib/glad/glad.h"
#include "../include/lib/glm/glm.hpp"
#include "../include/lib/glm/gtc/matrix_transform.hpp"
#include "../include/lib/glm/gtc/type_ptr.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

#include "../include/map/map.h"

#include "../include/input/processing.h"

#include "../include/utils/camera.h"
#include "../include/utils/shader.h"
#include "../include/utils/callbacks.h"

#include "../include/level/level.h"

// timing
float delta_time = 0.0f;
float last_frame = 0.0f;

const std::string error_text_glfw_window = "Failed to create Window.";
const std::string error_text_glad_initialize = "Failed to initialize GLAD.";

int main(int argc, char *argv[])
{

	Callbacks *callback = new Callbacks();

	// Level *level = new Level("Starting Point One", 1, 1, 1);
	// level->setDifficulty(2);
	// glfw window creation
	// --------------------

	if (!glfwInit())
	{
		// Handle initialization failure

		const char *description;
		int code = glfwGetError(&description);

		if (description)
		{
			std::cout << "Code of glfw error: " << code << std::endl;
			std::cout << "Description of glfw error: " << description << std::endl;
		}
	}
	GLFWmonitor *primary = glfwGetPrimaryMonitor();
	GLFWwindow *window = glfwCreateWindow(
		1920, 1080, "Tower Defence Experiment v1.0.0", primary, NULL);

	if (window == NULL)
	{
		std::cout << error_text_glfw_window << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, callback->framebuffer_size);
	glfwSetCursorPosCallback(window, callback->mouse_input);
	glfwSetScrollCallback(window, callback->mouse_scroll);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << error_text_glad_initialize << std::endl;
		return -1;
	}

	Shader tdeShader("shaders/vertex_shader.glsl",
					 "shaders/fragment_shader.glsl");

	// set up vertex data ( Cube )
	// ------------------------------------------------------------------
	float vertices[] = {
		// front face
		// first triangle       	//Texture coords
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,	// top right
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom left
		// second triangle
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,	// top right
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom left
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,	// top left

		// back face
		// first triangle		//Texture coords
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,	 // top right
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f,	 // bottom right
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // bottom left
		// second triangle
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,	 // top right
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // bottom left
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,	 // top left

		// top face
		// first triangle
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, // top right
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,  // bottom right
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, // bottom left
		// second triangle
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,	// top right
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,	// bottom left
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, // top left

		// bottom face
		// first triangle
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, // top right
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,	// bottom right
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, // bottom left
		// second triangle
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f,	 // top right
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,	 // bottom left
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, // top left

		// left face
		// first triangle
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f,	 // top right
		-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,	 // bottom right
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // bottom left
		// second triangle
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f,	 // top right
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // bottom left
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,	 // top left

		// right face
		// first triangle
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,	// top right
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,	// bottom right
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // bottom left
		// second triangle
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,	// top right
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // bottom left
		0.5f, 0.5f, -0.5f, 0.0f, 1.0f,	// top left
	};

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
				 GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
						  (void *)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
						  (void *)(3 * sizeof(float)));

	InputProcessing *input = new InputProcessing();

	// Map *map = new Map();
	// Terrain *terrain = new Terrain(1);
	// map->loadMap(terrain);

	unsigned int fps = 0;
	float counter = 0.0f;
	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// per-frame time logic
		// --------------------
		float current_frame = glfwGetTime();
		delta_time = current_frame - last_frame;
		last_frame = current_frame;

		if ((counter += delta_time) > 1.0f)
		{
			std::cout << "FPS: " << fps << std::endl;
			counter = 0.0f;
			fps = 0;
		}
		else
		{
			fps++;
		}

		// input
		// -----
		input->keyboard_input(window, delta_time);

		// render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		tdeShader.use();

		// create transformations
		glm::mat4 view =
			glm::mat4(1.0f); // make sure to initialize matrix to
							 // identity matrix first
		glm::mat4 projection = glm::mat4(1.0f);

		projection =
			glm::perspective(glm::radians(mouse.fov),
							 (800.0f /
							  600.0f),
							 0.1f, 150.0f);
		view =
			glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		// note: currently we set the projection matrix each frame, but
		// since the projection matrix rarely changes it's often best
		// practice to set it outside the main loop only once.
		tdeShader.setMat4("projection", projection);
		tdeShader.setMat4("view", view);

		glBindVertexArray(VAO);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
		tdeShader.setMat4("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// glfw: swap buffers and poll IO events (keys pressed/released,
		// mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

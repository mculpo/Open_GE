#pragma once
#include <Core/tspch.h>
namespace openge {
	class Engine
	{
	public:
		Engine(float width, float height, const char* title, bool fullWidth);
		~Engine();
		void run();
	private:
		GLFWwindow* m_window;
		float width;
		float height;
	};
}


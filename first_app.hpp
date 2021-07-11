#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve {
	class FirstApp {
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;
			
			void run();
		private:
			LveWindow lveWindow{WIDTH, HEIGHT, "Vulkan Test"}; //Instancia de ventana
			LveDevice lveDevice{lveWindow}; //Creamos un device que toma la ventana como arugmento de constructor
			LvePipeline lvePipeline{
				lveDevice,
				"simple_shader.vert.spv",
				"simple_shader.frag.spv",
				LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)}; //Instancia de pipeline de graficos
	};
}
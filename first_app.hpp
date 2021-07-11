#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"

#include <memory>
#include <vector>

namespace lve {
	class FirstApp {
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			//Constructor
			FirstApp();

			//Destructor
			~FirstApp();

			FirstApp(const FirstApp&) = delete;
			FirstApp& operator=(const FirstApp&) = delete;

			void run();
		private:

			void createPipelineLayout();
			void createPipeline();
			void createCommandBuffers();
			void drawFrame();

			LveWindow lveWindow{WIDTH, HEIGHT, "Vulkan Test"}; //Instancia de ventana
			LveDevice lveDevice{lveWindow}; //Creamos un device que toma la ventana como arugmento de constructor
			LveSwapChain lveSwapChain{ lveDevice, lveWindow.getExtent() }; //Creamos la swap chain

			std::unique_ptr<LvePipeline> lvePipeline; //Creamos un smart pointer que nos libera de la responsabilidad de manejar la memoria
			VkPipelineLayout pipelineLayout;
			std::vector<VkCommandBuffer> commandBuffers;
			
			/*LvePipeline lvePipeline{
				lveDevice,
				"simple_shader.vert.spv",
				"simple_shader.frag.spv",
				LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)}; //Instancia de pipeline de graficos*/
	};
}
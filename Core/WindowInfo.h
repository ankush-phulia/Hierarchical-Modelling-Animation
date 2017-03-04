#pragma once
#include <string>

namespace Core {

	struct WindowInfo{
		std::string name;
		int width, height;
		int position_x, position_y;
		bool isReshapable;

		WindowInfo(){
			name = "OpenGL";
			width = 800; height = 600;
			isReshapable = true;
			position_x = position_y = 100;
		}

		WindowInfo(int ewidth, int eheight) {
			name = "Frog Race";
			width = ewidth;
			height = eheight;
			position_x = position_y = 100;
		}

		WindowInfo(std::string ename, int start_position_x, int start_position_y, int ewidth, int eheight, bool is_reshapable){
			name = ename;
			position_x = start_position_x;
			position_y = start_position_y;
			width = ewidth;
			height = eheight;
			isReshapable = is_reshapable;
		}

	};

};

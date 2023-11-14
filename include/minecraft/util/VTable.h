#pragma once

#define MC_VFUNC(return_type, class_type, function_name, ...)     \
	int flag_##function_name;                                     \
	return_type(*function_name)(class_type* _this, ##__VA_ARGS__)

namespace mc {
	class VTable {
	public:
		MC_VFUNC(void, void, signature);
	};
}
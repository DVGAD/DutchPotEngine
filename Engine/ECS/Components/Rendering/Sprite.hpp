#pragma once
#include <stdint.h>

namespace DPE
{
	struct Sprite
	{
		float width = 50.0f;
		float height = 50.0f;
		uint8_t r = 255;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t a = 255;
	};
}
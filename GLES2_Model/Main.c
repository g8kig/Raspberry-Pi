#include <stdbool.h>			// Neede for bool
#include <stdint.h>				// Needed for uint32_t, uint16_t etc
#include <string.h>				// Needed for memcpy
#include <stdlib.h>
#include "emb-stdio.h"			// Needed for printf
#include "rpi-smartstart.h"		// Needed for smart start API 
#include "rpi-GLES.h"
#include "SDCard.h"


int halfScrWth;
int halfScrHt;
struct obj_model_t model = { 0 };
int main (void) {
	InitV3D();														// Start 3D graphics
	ARM_setmaxspeed(NULL);											// ARM CPU to max speed no message to screen
	PiConsole_Init(0, 0, 32, NULL);									// Auto resolution console, no message to screen
	halfScrWth = GetConsole_Width() / 2;
	halfScrHt = GetConsole_Height() / 2;


	sdInitCard(printf, printf, true);

	SetupRenderer(&model, GetConsole_Width(), GetConsole_Height(), ARMaddrToGPUaddr((void*)(uintptr_t)GetConsole_FrameBuffer()));
	CreateVertexData("\\spacecraft\\runner\\spacecraft.obj", &model, &printf);
	DoRotate(0.0f, halfScrWth, halfScrHt, &model);						// Preset rotation matrix to zero

	uint64_t tick = timer_getTickCount();
	int frameCount = 0;
	while (1){
		if (tick_difference(tick, timer_getTickCount()) > 1000) {
			// setup for 1000 fps which pi3 was doing
			DoRotate(0.01f, halfScrWth, halfScrHt, &model);
			frameCount = 0;
			tick = timer_getTickCount();
		}
		RenderModel(&model,	printf);
		frameCount++;
    }

	DoneRenderer(&model);

	return(0);
}

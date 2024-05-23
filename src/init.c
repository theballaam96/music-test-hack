#include "../include/common.h"

#define MUSIC_SIZE 0x5DC0

static s8 initialized = 0;
static s8 music_storage[MUSIC_SIZE];

void initHack(void) {
    /**
     * @brief Everything you expect to run upon booting your hack up, and nowhere else.
     */
    if (!initialized) {
        // Enable stack trace upon crash
        *(s8 *)(0x807563B4) = 1;
        *(s32 *)(0x80731F78) = 0;
        *(int*)(0x8076BF38) = (int)&music_storage[0]; // Increase music storage
        initStackTrace();
        loadSingularHook(0x8071417C, &displayListCode);

        // FINISH
        initialized = 1;
    }
}

void quickInit(void) {
	/**
	 * @brief Quick Initialization Process. Initializes Hack and, if fast boot is on, transitions to Win95 Screen
	 */
	initHack();
    initiateTransitionFade(MAP_NFRTITLESCREEN, 0, 5);
    CutsceneWillPlay = 0;
    Gamemode = 5;
    Mode = 5;
    StorySkip = 1;
    *(s8*)(0x80745D20) = 1;
}
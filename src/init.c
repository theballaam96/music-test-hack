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
        writeFunction(0x80602A2C, &preventSongRestartDeadlock);
        *(int*)(0x80602A30) = 0x30E500FF; // _ANDI $a1, $a3, 0xFF (vanilla code for that location)

        // Hi-jack alEvtqPostEevent with custom function (41 calls)
        writeFunction(0x807331F4, &increment_event_count);
        writeFunction(0x8073341C, &increment_event_count);
        writeFunction(0x80733594, &increment_event_count);
        writeFunction(0x80733960, &increment_event_count);
        writeFunction(0x80733B48, &increment_event_count);
        writeFunction(0x80733ED0, &increment_event_count);
        writeFunction(0x80734204, &increment_event_count);
        writeFunction(0x807343E8, &increment_event_count);
        writeFunction(0x807345BC, &increment_event_count);
        writeFunction(0x80734638, &increment_event_count);
        writeFunction(0x80734D28, &increment_event_count);
        writeFunction(0x80735A14, &increment_event_count);
        writeFunction(0x80735A7C, &increment_event_count);
        writeFunction(0x80735CB4, &increment_event_count);
        writeFunction(0x80735D38, &increment_event_count);
        writeFunction(0x80736010, &increment_event_count);
        writeFunction(0x80736098, &increment_event_count);
        writeFunction(0x80736100, &increment_event_count);
        writeFunction(0x807365FC, &increment_event_count);
        writeFunction(0x80736684, &increment_event_count);
        writeFunction(0x80736784, &increment_event_count);
        writeFunction(0x80736EA8, &increment_event_count);
        writeFunction(0x80737084, &increment_event_count);
        writeFunction(0x807377C0, &increment_event_count);
        writeFunction(0x807377F4, &increment_event_count);
        writeFunction(0x807378E4, &increment_event_count);
        writeFunction(0x80737970, &increment_event_count);
        writeFunction(0x80737A0C, &increment_event_count);
        writeFunction(0x80737B0C, &increment_event_count);
        writeFunction(0x80737BE0, &increment_event_count);
        writeFunction(0x80737E70, &increment_event_count);
        writeFunction(0x807381B8, &increment_event_count);
        writeFunction(0x80738210, &increment_event_count);
        writeFunction(0x80738278, &increment_event_count);
        writeFunction(0x807382F4, &increment_event_count);
        writeFunction(0x80738384, &increment_event_count);
        writeFunction(0x8073844C, &increment_event_count);
        writeFunction(0x80739F20, &increment_event_count);
        writeFunction(0x80739F6C, &increment_event_count);
        writeFunction(0x80739FbC, &increment_event_count);
        writeFunction(0x8073A284, &increment_event_count);

        // Hi-jack alEvtqPostEvent with custom function
        writeFunction(0x80733A24, &decrease_event_count);
        // Hi-jack clear_events_for_voice with custom function
        writeFunction(0x8073A374, &decrease_event_count_2);
        // Hi-jack alEvtqFlushType with custom function
        writeFunction(0x8073B524, &decrease_event_count_2);
        // Hi-jack cseqp_stop_voice with custom function
        writeFunction(0x8073A1F0, &decrease_event_count_2);
        
        // Hi-jack cseqpAllocateVoice with custom function
        writeFunction(0x80733F5C, &updateVoicesUsedAllocate);
        // Hi-jack cseqpFreeVoice with custom function
        writeFunction(0x8073324C, &updateVoicesUsedFree);
        writeFunction(0x807337C8, &updateVoicesUsedFree);
        
        // Hi-jack the Synthesizer's routine function with custom function
        // writeFunction(0x8073D24C, &updateUpdatesUsed); // Recompiler makes the emulator not run this code

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
    // *(s8*)(0x80745D20) = 0;
}

assignAllSongsToBank0(){
    for(int i = 0; i < 176; i++){
        songData[i] &= 0xFFF9;
    }
}
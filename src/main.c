#include "../include/common.h"

static s8 has_loaded = 0;
static u16 previously_restarted_song = 0;
static u8 force_restart = 0; // forces the song to restart, despite it being told not to restart a song that's already playing

void cFuncLoop(void) {
	/*
		This function is run every frame. Place c code which you are wanting to be run every frame
	*/
	//initHack(); // Initialize hack
	if (CurrentMap == MAP_NFRTITLESCREEN) {
		if (ObjectModel2Timer == 5) {
			playSound(71, 0x7FFF, 63.0f, 1.0f, 0, 0);
		}
		int loaded = *(char*)(0x807F01A6);
		if ((loaded) || (ObjectModel2Timer > 800)) {
			if (!has_loaded) {
				preventSongPlaying = 0;
			}
			has_loaded = 1;
		}
		if (has_loaded) {
			menuLoop();
    		decrease_metrics_max_timers();
		}
	}
}

Gfx* displayListModifiers(Gfx* dl) {
    if (CurrentMap == MAP_NFRTITLESCREEN) {
		if (!has_loaded) {
			dl = drawPixelTextContainer(dl, 108, 100, "LOADING HACK", 0xFF, 0xFF, 0xFF, 0xFF, 0);
			return drawPixelTextContainer(dl, 112, 120, "PLEASE WAIT", 0xFF, 0xFF, 0xFF, 0xFF, 0);
		} else {
			dl = displayMusicMenu(dl);
		}
    }
    return dl;
}

// Prevent handleMusic2 from making needlessly(?) restarting the song before it even had a chance to play
void preventSongRestartDeadlock(int write_slot, int song, float volume){
	if (MusicTrackChannels[write_slot] != previously_restarted_song || force_restart){
		previously_restarted_song = MusicTrackChannels[0];
		restartSong(write_slot, song, volume);
		force_restart = 0;
	}
	// resetMetrics();
}

// This was the first solution I found when trying to make a global accessible in a different file
void forceRestart(){
	force_restart = 1;
}
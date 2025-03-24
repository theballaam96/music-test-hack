#include "../include/common.h"

static s32 song_index = 128;

typedef enum song_type {
    STYPE_BGM,
    STYPE_EVENT,
    STYPE_MAJOR,
    STYPE_MINOR,
    STYPE_OTHER,
} song_type;

typedef struct song_db_struct {
    /* 0x000 */ char* song_name;
    /* 0x004 */ u8 song_index;
    /* 0x005 */ u8 song_type;
    /* 0x006 */ s16 vanilla_volume;
} song_db_struct;

static song_db_struct song_db[] = {
    {.song_name = "100TH CB GET", .song_index = 172, .song_type=STYPE_EVENT},
    {.song_name = "ANGRY AZTEC", .song_index = 14, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <5DT>", .song_index = 26, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <BABOON BLAST>", .song_index = 55, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <BEETLE SLIDE>", .song_index = 19, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <CHUNKY KLAPTRAPS>", .song_index = 48, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <DOGADON>", .song_index = 25, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <LOBBY>", .song_index = 130, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <TEMPLE>", .song_index = 21, .song_type=STYPE_BGM},
    {.song_name = "ANGRY AZTEC <TUNNELS>", .song_index = 37, .song_type=STYPE_BGM},
    {.song_name = "AWAITING ENTERING THE BOSS", .song_index = 58, .song_type=STYPE_BGM},
    {.song_name = "BABOON BALLOON", .song_index = 107, .song_type=STYPE_EVENT},
    {.song_name = "BANANA COIN GET", .song_index = 23, .song_type=STYPE_MINOR},
    {.song_name = "BANANA MEDAL GET", .song_index = 151, .song_type=STYPE_MAJOR},
    {.song_name = "BATTLE ARENA", .song_index = 64, .song_type=STYPE_BGM},
    {.song_name = "BBLAST FINAL STAR", .song_index = 143, .song_type=STYPE_EVENT},
    {.song_name = "BEAN GET", .song_index = 147, .song_type=STYPE_MAJOR},
    {.song_name = "BLUEPRINT DROP", .song_index = 76, .song_type=STYPE_MAJOR},
    {.song_name = "BLUEPRINT GET", .song_index = 69, .song_type=STYPE_MAJOR},
    {.song_name = "BONGO BLAST", .song_index = 11, .song_type=STYPE_BGM},
    {.song_name = "BONUS BARREL INTRODUCTION", .song_index = 88, .song_type=STYPE_OTHER},
    {.song_name = "BONUS MINIGAMES", .song_index = 8, .song_type=STYPE_BGM},
    {.song_name = "BOSS DEFEAT", .song_index = 54, .song_type=STYPE_EVENT},
    {.song_name = "BOSS INTRODUCTION", .song_index = 100, .song_type=STYPE_BGM},
    {.song_name = "BOSS UNLOCK", .song_index = 57, .song_type=STYPE_EVENT},
    {.song_name = "CANDYS MUSIC SHOP", .song_index = 31, .song_type=STYPE_BGM},
    {.song_name = "CHECKPOINT", .song_index = 67, .song_type=STYPE_MINOR},
    {.song_name = "COMPANY COIN GET", .song_index = 22, .song_type=STYPE_MAJOR},
    {.song_name = "CRANKYS LAB", .song_index = 2, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE", .song_index = 105, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <BABOON BLAST>", .song_index = 165, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <BALLROOM>", .song_index = 136, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <CRYPT>", .song_index = 126, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <DUNGEON WITH CHAINS>", .song_index = 129, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <DUNGEON WITHOUT CHAINS>", .song_index = 150, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <GREENHOUSE>", .song_index = 137, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <INNER CRYPTS>", .song_index = 135, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <KUT OUT>", .song_index = 149, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <LOBBY>", .song_index = 155, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <MINECART>", .song_index = 106, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <MUSEUM>", .song_index = 142, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <SHED>", .song_index = 139, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <TRASH CAN>", .song_index = 157, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <TREE>", .song_index = 141, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <TUNNELS>", .song_index = 121, .song_type=STYPE_BGM},
    {.song_name = "CREEPY CASTLE <WIND TOWER>", .song_index = 140, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES", .song_index = 83, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <ARMY DILLO>", .song_index = 148, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <BABOON BLAST>", .song_index = 163, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <BEETLE RACE>", .song_index = 102, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <CABINS>", .song_index = 118, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <GIANT KOSHA TANTRUM>", .song_index = 84, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <IGLOOS>", .song_index = 103, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <LOBBY>", .song_index = 154, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <ROTATING ROOM>", .song_index = 119, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL CAVES <TILE FLIPPING>", .song_index = 120, .song_type=STYPE_BGM},
    {.song_name = "CRYSTAL COCONUT GET", .song_index = 35, .song_type=STYPE_MINOR},
    {.song_name = "DK ISLES", .song_index = 109, .song_type=STYPE_BGM},
    {.song_name = "DK ISLES <BANANA FAIRY ISLAND>", .song_index = 111, .song_type=STYPE_BGM},
    {.song_name = "DK ISLES <K ROOLS SHIP>", .song_index = 110, .song_type=STYPE_BGM},
    {.song_name = "DK ISLES <K-LUMSYS PRISON>", .song_index = 112, .song_type=STYPE_BGM},
    {.song_name = "DK ISLES <SNIDES ROOM>", .song_index = 166, .song_type=STYPE_BGM},
    {.song_name = "DK RAP", .song_index = 75, .song_type=STYPE_BGM},
    {.song_name = "DK TRANSITION <CLOSING>", .song_index = 44, .song_type=STYPE_OTHER},
    {.song_name = "DK TRANSITION <OPENING>", .song_index = 43, .song_type=STYPE_OTHER},
    {.song_name = "DROP COINS <MINECART>", .song_index = 65, .song_type=STYPE_MINOR},
    {.song_name = "DROP RAINBOW COIN", .song_index = 144, .song_type=STYPE_MAJOR},
    {.song_name = "END SEQUENCE", .song_index = 158, .song_type=STYPE_BGM},
    {.song_name = "ENGUARDE", .song_index = 124, .song_type=STYPE_BGM},
    {.song_name = "FAILURE", .song_index = 42, .song_type=STYPE_EVENT},
    {.song_name = "FAILURE <RACES & TRY AGAIN>", .song_index = 87, .song_type=STYPE_EVENT},
    {.song_name = "FAIRY NEARBY", .song_index = 66, .song_type=STYPE_OTHER},
    {.song_name = "FAIRY TICK", .song_index = 46, .song_type=STYPE_MINOR},
    {.song_name = "FRANTIC FACTORY", .song_index = 28, .song_type=STYPE_BGM},
    {.song_name = "FRANTIC FACTORY <CAR RACE>", .song_index = 27, .song_type=STYPE_BGM},
    {.song_name = "FRANTIC FACTORY <CRUSHER ROOM>", .song_index = 49, .song_type=STYPE_BGM},
    {.song_name = "FRANTIC FACTORY <LOBBY>", .song_index = 132, .song_type=STYPE_BGM},
    {.song_name = "FRANTIC FACTORY <MAD JACK>", .song_index = 39, .song_type=STYPE_BGM},
    {.song_name = "FRANTIC FACTORY <PRODUCTION ROOM>", .song_index = 52, .song_type=STYPE_BGM},
    {.song_name = "FRANTIC FACTORY <R&D>", .song_index = 51, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <ANTHILL>", .song_index = 93, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <BABOON BLAST>", .song_index = 164, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <BARN>", .song_index = 94, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <DAY>", .song_index = 68, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <DOGADON>", .song_index = 81, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <GIANT MUSHROOM>", .song_index = 99, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <LOBBY>", .song_index = 153, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <MILL>", .song_index = 95, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <MINECART>", .song_index = 74, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <MUSHROOM TOP ROOMS>", .song_index = 98, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <NIGHT>", .song_index = 70, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <RABBIT RACE>", .song_index = 169, .song_type=STYPE_BGM},
    {.song_name = "FUNGI FOREST <SPIDER>", .song_index = 97, .song_type=STYPE_BGM},
    {.song_name = "FUNKYS HUT", .song_index = 6, .song_type=STYPE_BGM},
    {.song_name = "GAME OVER", .song_index = 170, .song_type=STYPE_OTHER},
    {.song_name = "GB KEY GET", .song_index = 18, .song_type=STYPE_MAJOR},
    {.song_name = "GENERIC SEASIDE SOUNDS", .song_index = 96, .song_type=STYPE_OTHER},
    {.song_name = "GENERIC TWINKLY SOUNDS", .song_index = 59, .song_type=STYPE_OTHER},
    {.song_name = "GLOOMY GALLEON <2DS>", .song_index = 77, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <5DS/SUBMARINE>", .song_index = 78, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <BABOON BLAST>", .song_index = 92, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <LIGHTHOUSE>", .song_index = 63, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <LOBBY>", .song_index = 133, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <MECHANICAL FISH>", .song_index = 91, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <MERMAID PALACE>", .song_index = 80, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <OUTSIDE>", .song_index = 56, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <PEARLS CHEST>", .song_index = 79, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <PUFFTOSS>", .song_index = 60, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <SEAL RACE>", .song_index = 61, .song_type=STYPE_BGM},
    {.song_name = "GLOOMY GALLEON <TUNNELS>", .song_index = 62, .song_type=STYPE_BGM},
    {.song_name = "GOING THROUGH VULTURE RING", .song_index = 24, .song_type=STYPE_EVENT},
    {.song_name = "GORILLA GONE", .song_index = 108, .song_type=STYPE_BGM},
    {.song_name = "GUITAR GAZUMP", .song_index = 10, .song_type=STYPE_BGM},
    {.song_name = "GUN GET", .song_index = 115, .song_type=STYPE_MAJOR},
    {.song_name = "HEADPHONES GET", .song_index = 127, .song_type=STYPE_MAJOR},
    {.song_name = "HIDEOUT HELM <BLAST-O-MATIC OFF>", .song_index = 116, .song_type=STYPE_BGM},
    {.song_name = "HIDEOUT HELM <BLAST-O-MATIC ON>", .song_index = 113, .song_type=STYPE_BGM},
    {.song_name = "HIDEOUT HELM <BONUS BARRELS>", .song_index = 117, .song_type=STYPE_BGM},
    {.song_name = "HIDEOUT HELM <LOBBY>", .song_index = 156, .song_type=STYPE_BGM},
    {.song_name = "HUNKY CHUNKY", .song_index = 17, .song_type=STYPE_BGM},
    {.song_name = "INTRO STORY MEDLEY", .song_index = 122, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES", .song_index = 160, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <ARMY DILLO>", .song_index = 4, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <BABOON BLAST>", .song_index = 50, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <CAVES>", .song_index = 5, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <CRANKYS AREA>", .song_index = 161, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <LOBBY>", .song_index = 131, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <MINECART>", .song_index = 3, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <STARTING AREA>", .song_index = 1, .song_type=STYPE_BGM},
    {.song_name = "JUNGLE JAPES <TUNNELS>", .song_index = 30, .song_type=STYPE_BGM},
    {.song_name = "K ROOL TAKEOFF", .song_index = 162, .song_type=STYPE_BGM},
    {.song_name = "K ROOLS BATTLE", .song_index = 152, .song_type=STYPE_BGM},
    {.song_name = "K ROOLS DEFEAT", .song_index = 173, .song_type=STYPE_EVENT},
    {.song_name = "K ROOLS ENTRANCE", .song_index = 167, .song_type=STYPE_BGM},
    {.song_name = "K ROOLS THEME", .song_index = 138, .song_type=STYPE_BGM},
    {.song_name = "K-LUMSY CELEBRATION", .song_index = 125, .song_type=STYPE_BGM},
    {.song_name = "K-LUMSY ENDING", .song_index = 159, .song_type=STYPE_BGM},
    {.song_name = "MAD MAZE MAUL", .song_index = 82, .song_type=STYPE_BGM},
    {.song_name = "MAIN MENU", .song_index = 134, .song_type=STYPE_BGM},
    {.song_name = "MELON SLICE DROP", .song_index = 47, .song_type=STYPE_MINOR},
    {.song_name = "MELON SLICE GET", .song_index = 33, .song_type=STYPE_MINOR},
    {.song_name = "MINECART COIN GET", .song_index = 32, .song_type=STYPE_MINOR},
    {.song_name = "MINECART MAYHEM", .song_index = 90, .song_type=STYPE_BGM},
    {.song_name = "MINI BOSS", .song_index = 104, .song_type=STYPE_BGM},
    {.song_name = "MINI MONKEY", .song_index = 16, .song_type=STYPE_BGM},
    {.song_name = "MONKEY SMASH", .song_index = 168, .song_type=STYPE_BGM},
    {.song_name = "MOVE GET", .song_index = 114, .song_type=STYPE_MAJOR},
    {.song_name = "NINTENDO LOGO", .song_index = 174, .song_type=STYPE_BGM},
    {.song_name = "NINTENDO LOGO <OLD>", .song_index = 85, .song_type=STYPE_OTHER},
    {.song_name = "NORMAL STAR", .song_index = 146, .song_type=STYPE_MINOR},
    {.song_name = "OH BANANA", .song_index = 20, .song_type=STYPE_MAJOR},
    {.song_name = "ORANGSTAND SPRINT", .song_index = 73, .song_type=STYPE_BGM},
    {.song_name = "PAUSE MENU", .song_index = 34, .song_type=STYPE_BGM},
    {.song_name = "PEARL GET", .song_index = 128, .song_type=STYPE_MAJOR},
    {.song_name = "RAINBOW COIN GET", .song_index = 145, .song_type=STYPE_MAJOR},
    {.song_name = "RAMBI", .song_index = 36, .song_type=STYPE_BGM},
    {.song_name = "ROCKETBARREL BOOST", .song_index = 72, .song_type=STYPE_BGM},
    {.song_name = "SAXOPHONE SLAM", .song_index = 13, .song_type=STYPE_BGM},
    {.song_name = "SNIDES HQ", .song_index = 29, .song_type=STYPE_BGM},
    {.song_name = "START <TO PAUSE GAME>", .song_index = 41, .song_type=STYPE_OTHER},
    {.song_name = "STEALTHY SNOOP", .song_index = 89, .song_type=STYPE_BGM},
    {.song_name = "STRONG KONG", .song_index = 71, .song_type=STYPE_BGM},
    {.song_name = "SUCCESS", .song_index = 40, .song_type=STYPE_EVENT},
    {.song_name = "SUCCESS <RACES>", .song_index = 86, .song_type=STYPE_EVENT},
    {.song_name = "TAG BARREL <ALL OF THEM>", .song_index = 101, .song_type=STYPE_OTHER},
    {.song_name = "TRAINING GROUNDS", .song_index = 123, .song_type=STYPE_BGM},
    {.song_name = "TRANSFORMATION", .song_index = 15, .song_type=STYPE_EVENT},
    {.song_name = "TRIANGLE TRAMPLE", .song_index = 9, .song_type=STYPE_BGM},
    {.song_name = "TROFF N SCOFF", .song_index = 53, .song_type=STYPE_BGM},
    {.song_name = "TROMBONE TREMOR", .song_index = 12, .song_type=STYPE_BGM},
    {.song_name = "UNUSED COIN PICKUP", .song_index = 7, .song_type=STYPE_OTHER},
    {.song_name = "UNUSED HIGH-PITCHED JAPES", .song_index = 45, .song_type=STYPE_OTHER},
    {.song_name = "WATER DROPLETS", .song_index = 38, .song_type=STYPE_OTHER},
    {.song_name = "WRINKLY KONG", .song_index = 171, .song_type=STYPE_BGM},
};

void playSFX(int sfx_index) {
    playSound(sfx_index, 0x7FFF, 63.0f, 1.0f, 0, 0);
}

#define NULL_OPTION -1
typedef enum menu_options {
    /* 0x000 */ MENUOP_SONGNAME,
    /* 0x001 */ MENUOP_PLAY,
    /* 0x002 */ MENUOP_PAUSE,
    /* 0x003 */ MENUOP_STOP,
    /* 0x004 */ MENUOP_EQ,
    /* 0x005 */ MENUOP_ZIP,
} menu_options;

typedef struct menu_option_tree {
    /* 0x000 */ s8 up;
    /* 0x001 */ s8 down;
    /* 0x002 */ s8 left;
    /* 0x003 */ s8 right;
} menu_option_tree;

static menu_options selected_music_menu_option = MENUOP_SONGNAME;
static u8 changing_position = 0;
static u8 volume_equalization = 1;
static s16 playing_index = 1;
static u8 paused = 0;

#define SONG_COUNT 175
static u8 loadedSongData = 0;

#define CONTROLS_Y 60
#define MOVEMENT_DEADZONE 20

static menu_option_tree music_menu_tree[] = {
    {.up = NULL_OPTION, .down=MENUOP_PLAY, .left=NULL_OPTION, .right=NULL_OPTION}, // songsong_name
    {.up = MENUOP_SONGNAME, .down=MENUOP_EQ, .left=NULL_OPTION, .right=MENUOP_PAUSE}, // play
    {.up = MENUOP_SONGNAME, .down=MENUOP_EQ, .left=MENUOP_PLAY, .right=MENUOP_STOP}, // pause
    {.up = MENUOP_SONGNAME, .down=MENUOP_EQ, .left=MENUOP_PAUSE, .right=NULL_OPTION}, // stop
    {.up = MENUOP_PLAY, .down=NULL_OPTION, .left=NULL_OPTION, .right=MENUOP_ZIP}, // EQ
    {.up = MENUOP_PLAY, .down=NULL_OPTION, .left=MENUOP_EQ, .right=NULL_OPTION}, // Zip
};

void setSelectedOption(int option) {
    if (option == NULL_OPTION) {
        return;
    }
    selected_music_menu_option = option;
}

void playNewSong(int index) {
    for (int i = 0; i < 4; i++) {
        SongInWriteSlot[i] = 0;
    }
    for (int i = 0; i < 12; i++) {
        trackStateArray[i] = 0;
    }
    preventSongPlaying = 1;
    MusicTrackChannels[0] = index; // This is an incredibly incredibly dirty way to do it, but it yields better load times
    playing_index = index;
    paused = 0;
}

void stopSong(void) {
    // for (int i = 0; i < 4; i++) {
    //     if (SongInWriteSlot[i]) {
    //         cancelMusic(SongInWriteSlot[i], i);
    //     }
    // }
    playNewSong(0);
    playing_index = -1;
}

// Note: This functionality is not perfect. Scheduled MIDI events and unfinished notes will be flushed and stopped respectively. 
void pauseSong(void) {
    short song = MusicTrackChannels[0];
    if (song != 0){
        char slot = getSongWriteSlot(song);
        if(!paused){
            alCSPStop(SeqPlayers[slot]);
            preventSongPlaying = 0;
            paused = 1;
        } else {
            alCSPPlay(SeqPlayers[slot]);
            preventSongPlaying = 1;
            paused = 0;
        }
    }

}

void eqVolume(void) {
    for (int i = 0; i < 174; i++) {
        s32 index = song_db[i].song_index;
        song_type stype = song_db[i].song_type;
        if (stype != STYPE_OTHER) {
            s32 volume = 25000;
            if (stype == STYPE_BGM) {
                volume = 23000;
            } else if (stype == STYPE_MAJOR) {
                volume = 27000;
            }
            songVolumes[index] = volume;
        }
    }
}

void resetVolume(void) {
    for (int i = 0; i < 174; i++) {
        s32 index = song_db[i].song_index;
        songVolumes[index] = song_db[i].vanilla_volume;
    }
}

void toggleVolumeEq(void) {
    volume_equalization = 1 ^ volume_equalization;
    if (volume_equalization) {
        eqVolume();
    } else {
        resetVolume();
    }
    playNewSong(song_db[song_index].song_index);
}

void initMenu(void) {
    for (int i = 0; i < 174; i++) {
        s32 index = song_db[i].song_index;
        song_db[i].vanilla_volume = songVolumes[index];
    }
    eqVolume();
}

static u8 zip_in_progress = 0;
static s16 zip_timer = -1;
static s16 zip_stored_sample = 0;
static s16 zip_effect_bus_ct = 0;

void zipAudio(void) {
    // Massively decreases the sample rate to speed the song up to check for errors with audio loops
    if (!zip_in_progress) {
        zip_in_progress = 1;
        zip_stored_sample = synthesizer->maxAuxBusses;
        zip_effect_bus_ct = synthesizer->numPVoices;
        zip_timer = 300;
        synthesizer->maxAuxBusses = 1102; // 20x speed
        synthesizer->numPVoices = 0;
    }
}

void menuLoop(void) {
    if (!loadedSongData) {
        initMenu();
    }
    loadedSongData = 1;
    if (zip_in_progress) {
        if (zip_timer >= 0) {
            if (zip_timer == 0) {
                synthesizer->maxAuxBusses = zip_stored_sample;
                synthesizer->numPVoices = zip_effect_bus_ct;
                zip_in_progress = 0;
            }
            zip_timer--;
        }
        return;
    }
    switch (selected_music_menu_option) {
        case MENUOP_SONGNAME:
            if (NewlyPressedControllerInput.Buttons.d_up) {
                song_index -= 1;
                if (song_index < 0) {
                    song_index = 173;
                }
                playSFX(64);
            } else if (NewlyPressedControllerInput.Buttons.d_down) {
                song_index += 1;
                if (song_index >= 174) {
                    song_index = 0;
                }
                playSFX(64);
            } else if (NewlyPressedControllerInput.Buttons.a) {
                playNewSong(song_db[song_index].song_index);
            } else if (NewlyPressedControllerInput.Buttons.b) {
                stopSong();
            }
            break;
        case MENUOP_PLAY:
            if (NewlyPressedControllerInput.Buttons.a) {
                playNewSong(song_db[song_index].song_index);
            }
            break;
        case MENUOP_PAUSE:
            if (NewlyPressedControllerInput.Buttons.a) {
                pauseSong();
            }
            break;
        case MENUOP_STOP:
            if (NewlyPressedControllerInput.Buttons.a) {
                stopSong();
            }
            break;
        case MENUOP_EQ:
            if (NewlyPressedControllerInput.Buttons.a) {
                toggleVolumeEq();
            }
            break;
        case MENUOP_ZIP:
            if (NewlyPressedControllerInput.Buttons.a) {
                zipAudio();
            }
            break;
    }
    if (ControllerInput.stickY > MOVEMENT_DEADZONE) {
        if (!changing_position) {
            setSelectedOption(music_menu_tree[selected_music_menu_option].up);
        }
        changing_position = 1;
    } else if (ControllerInput.stickY < -MOVEMENT_DEADZONE) {
        if (!changing_position) {
            setSelectedOption(music_menu_tree[selected_music_menu_option].down);
        }
        changing_position = 1;
    } else if (ControllerInput.stickX < -MOVEMENT_DEADZONE) {
        if (!changing_position) {
            setSelectedOption(music_menu_tree[selected_music_menu_option].left);
        }
        changing_position = 1;
    } else if (ControllerInput.stickX > MOVEMENT_DEADZONE) {
        if (!changing_position) {
            setSelectedOption(music_menu_tree[selected_music_menu_option].right);
        }
        changing_position = 1;
    } else {
        changing_position = 0;
    }
}

Gfx* renderMenuOption(Gfx* dl, char* string, menu_options assoc_option, int x, int y) {
    u8 green = 0xFF;
    u8 blue = 0xFF;
    if (selected_music_menu_option == assoc_option) {
        green = 0xD7;
        blue = 0;
    }
    return drawPixelTextContainer(dl, x, y, string, 0xFF, green, blue, 0xFF, 0);
}

s32 getSongIndex(s32 raw_index, s32 delta) {
    s32 new_value = raw_index + delta;
    if (new_value < 0) {
        new_value += 174;
    } else if (new_value > 173) {
        new_value -= 174;
    }
    return new_value;
}

static char* pause_states[] = {
    "PAUSE",
    "RESUME"
};

static char* volume_eq_strs[] = {
    "VOLUME EQ:OFF",
    "VOLUME EQ:ON",
};
static char* zip_states[] = {
    "ZIP",
    "ZIP: IN PROGRESS",
};

static char now_playing_str[40] = "";
static char voices_in_use_str[30] = "";
static char events_in_queue_str[30] = "";
static char updates_in_use_str[30] = "";
static char lost_param_updates[10] = "";

Gfx* displayMusicMenu(Gfx* dl) {
    for (int i = 0; i < 174; i++) {
        if (song_db[i].song_index == playing_index) {
            dk_strFormat((char*)now_playing_str, "> %s", song_db[i].song_name);
        }
    }
    u8 dithered_brightness = 0x40;
    for (int i = 1; i < 4; i++) {
        u8 applied_brightness = dithered_brightness - (i * 0x10);
        if (song_db[getSongIndex(song_index, -i)].song_index == playing_index) {
            dl = drawPixelTextContainer(dl, 20, CONTROLS_Y - (12 * i), (char*)now_playing_str, applied_brightness, applied_brightness, applied_brightness, 0xFF, 0);
        } else {
            dl = drawPixelTextContainer(dl, 20, CONTROLS_Y - (12 * i), song_db[getSongIndex(song_index, -i)].song_name, applied_brightness, applied_brightness, applied_brightness, 0xFF, 0);
        }
        if (song_db[getSongIndex(song_index, i)].song_index == playing_index) {
            dl = drawPixelTextContainer(dl, 20, CONTROLS_Y + (12 * i), (char*)now_playing_str, applied_brightness, applied_brightness, applied_brightness, 0xFF, 0);
        } else {
            dl = drawPixelTextContainer(dl, 20, CONTROLS_Y + (12 * i), song_db[getSongIndex(song_index, i)].song_name, applied_brightness, applied_brightness, applied_brightness, 0xFF, 0);
        }
    }
    if (song_db[(s32)song_index].song_index == playing_index) {
        dl = renderMenuOption(dl, (char*)now_playing_str, MENUOP_SONGNAME, 20, CONTROLS_Y);
    } else {
        dl = renderMenuOption(dl, song_db[(s32)song_index].song_name, MENUOP_SONGNAME, 20, CONTROLS_Y);
    }
    int play_tray_y = CONTROLS_Y + 60;
    int stats_section_y = CONTROLS_Y + 100;
    // Options
    dl = renderMenuOption(dl, "PLAY", MENUOP_PLAY, 20, play_tray_y);
    dl = renderMenuOption(dl, pause_states[paused], MENUOP_PAUSE, 120, play_tray_y);
    dl = renderMenuOption(dl, "STOP", MENUOP_STOP, 220, play_tray_y);
    dl = renderMenuOption(dl, volume_eq_strs[volume_equalization], MENUOP_EQ, 20, CONTROLS_Y + 80);
    dl = renderMenuOption(dl, zip_states[zip_in_progress], MENUOP_ZIP, 170, CONTROLS_Y + 80);
    
    dk_strFormat(voices_in_use_str, "VOICES: %s OF 44", padNumber(getVoicesUsed(), 2));
    dk_strFormat(events_in_queue_str, "EVENT QUEUE: %s OF 64", padNumber(getEventsUsed(), 2));
    dk_strFormat(updates_in_use_str, "UPDATES: %s OF 112", padNumber(getUpdatesUsed(), 3));
    dk_strFormat(lost_param_updates, "%d", getDeadVoices());

    // Metrics
    dl = drawPixelTextContainer(dl, 20, stats_section_y, voices_in_use_str, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    dl = drawPixelTextContainer(dl, 20, stats_section_y + 12, events_in_queue_str, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    dl = drawPixelTextContainer(dl, 20, stats_section_y + 24, updates_in_use_str, 0xFF, 0xFF, 0xFF, 0xFF, 0);
    if(getDeadVoices() > 1){
        dl = drawPixelTextContainer(dl, 253, 16, lost_param_updates, 0xFF, 0x0, 0x0, 0xFF, 0);
    }
    
    // Credits
    dl = drawPixelTextContainer(dl, 20, 208, "HACK BY BALLAAM AND ALMOSTSEAGULL", 0x0D, 0x3B, 0x4F, 0xFF, 0);
    dl = drawPixelTextContainer(dl, 20, 220, "DISCORD.DK64RANDOMIZER.COM", 0x0D, 0x3B, 0x4F, 0xFF, 0);
    dl = drawPixelTextContainer(dl, 253, 220, "V1.3", 0x08, 0x77, 0xA6, 0xFF, 0);
    return dl;
}
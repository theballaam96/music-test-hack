#include "../include/common.h"

static u8 song_index = 1;

static char* song_names[] = {
    "SILENCE", // 0
    "JUNGLE JAPES <STARTING AREA>", // 1
    "CRANKYS LAB", // 2
    "JUNGLE JAPES <MINECART>", // 3
    "JUNGLE JAPES <ARMY DILLO>", // 4
    "JUNGLE JAPES <CAVES>", // 5
    "FUNKYS HUT", // 6
    "UNUSED COIN PICKUP", // 7
    "BONUS MINIGAMES", // 8
    "TRIANGLE TRAMPLE", // 9
    "GUITAR GAZUMP", // 10
    "BONGO BLAST", // 11
    "TROMBONE TREMOR", // 12
    "SAXAPHONE SLAM", // 13
    "ANGRY AZTEC", // 14
    "TRANSFORMATION", // 15
    "MINI MONKEY", // 16
    "HUNKY CHUNKY", // 17
    "GB KEY GET", // 18
    "ANGRY AZTEC <BEETLE SLIDE>", // 19
    "OH BANANA", // 20
    "ANGRY AZTEC <TEMPLE>", // 21
    "COMPANY COIN GET", // 22
    "BANANA COIN GET", // 23
    "GOING THROUGH VULTURE RING", // 24
    "ANGRY AZTEC <DOGADON>", // 25
    "ANGRY AZTEC <5DT>", // 26
    "FRANTIC FACTORY <CAR RACE>", // 27
    "FRANTIC FACTORY", // 28
    "SNIDES HQ", // 29
    "JUNGLE JAPES <TUNNELS>", // 30
    "CANDYS MUSIC SHOP", // 31
    "MINECART COIN GET", // 32
    "MELON SLICE GET", // 33
    "PAUSE MENU", // 34
    "CRYSTAL COCONUT GET", // 35
    "RAMBI", // 36
    "ANGRY AZTEC <TUNNELS>", // 37
    "WATER DROPLETS", // 38
    "FRANTIC FACTORY <MAD JACK>", // 39
    "SUCCESS", // 40
    "START <TO PAUSE GAME>", // 41
    "FAILURE", // 42
    "DK TRANSITION <OPENING>", // 43
    "DK TRANSITION <CLOSING>", // 44
    "UNUSED HIGH-PITCHED JAPES", // 45
    "FAIRY TICK", // 46
    "MELON SLICE DROP", // 47
    "ANGRY AZTEC <CHUNKY KLAPTRAPS>", // 48
    "FRANTIC FACTORY <CRUSHER ROOM>", // 49
    "JUNGLE JAPES <BABOON BLAST>", // 50
    "FRANTIC FACTORY <R&D>", // 51
    "FRANTIC FACTORY <PRODUCTION ROOM>", // 52
    "TROFF N SCOFF", // 53
    "BOSS DEFEAT", // 54
    "ANGRY AZTEC <BABOON BLAST>", // 55
    "GLOOMY GALLEON <OUTSIDE>", // 56
    "BOSS UNLOCK", // 57
    "AWAITING ENTERING THE BOSS", // 58
    "GENERIC TWINKLY SOUNDS", // 59
    "GLOOMY GALLEON <PUFFTOSS>", // 60
    "GLOOMY GALLEON <SEAL RACE>", // 61
    "GLOOMY GALLEON <TUNNELS>", // 62
    "GLOOMY GALLEON <LIGHTHOUSE>", // 63
    "BATTLE ARENA", // 64
    "DROP COINS <MINECART>", // 65
    "FAIRY NEARBY", // 66
    "CHECKPOINT", // 67
    "FUNGI FOREST <DAY>", // 68
    "BLUEPRINT GET", // 69
    "FUNGI FOREST <NIGHT>", // 70
    "STRONG KONG", // 71
    "ROCKETBARREL BOOST", // 72
    "ORANGSTAND SPRINT", // 73
    "FUNGI FOREST <MINECART>", // 74
    "DK RAP", // 75
    "BLUEPRINT DROP", // 76
    "GLOOMY GALLEON <2DS>", // 77
    "GLOOMY GALLEON <5DS/SUBMARINE>", // 78
    "GLOOMY GALLEON <PEARLS CHEST>", // 79
    "GLOOMY GALLEON <MERMAID PALACE>", // 80
    "FUNGI FOREST <DOGADON>", // 81
    "MAD MAZE MAUL", // 82
    "CRYSTAL CAVES", // 83
    "CRYSTAL CAVES <GIANT KOSHA TANTRUM>", // 84
    "NINTENDO LOGO <OLD>", // 85
    "SUCCESS <RACES>", // 86
    "FAILURE <RACES & TRY AGAIN>", // 87
    "BONUS BARREL INTRODUCTION", // 88
    "STEALTHY SNOOP", // 89
    "MINECART MAYHEM", // 90
    "GLOOMY GALLEON <MECHANICAL FISH>", // 91
    "GLOOMY GALLEON <BABOON BLAST>", // 92
    "FUNGI FOREST <ANTHILL>", // 93
    "FUNGI FOREST <BARN>", // 94
    "FUNGI FOREST <MILL>", // 95
    "GENERIC SEASIDE SOUNDS", // 96
    "FUNGI FOREST <SPIDER>", // 97
    "FUNGI FOREST <MUSHROOM TOP ROOMS>", // 98
    "FUNGI FOREST <GIANT MUSHROOM>", // 99
    "BOSS INTRODUCTION", // 100
    "TAG BARREL <ALL OF THEM>", // 101
    "CRYSTAL CAVES <BEETLE RACE>", // 102
    "CRYSTAL CAVES <IGLOOS>", // 103
    "MINI BOSS", // 104
    "CREEPY CASTLE", // 105
    "CREEPY CASTLE <MINECART>", // 106
    "BABOON BALLOON", // 107
    "GORILLA GONE", // 108
    "DK ISLES", // 109
    "DK ISLES <K ROOLS SHIP>", // 110
    "DK ISLES <BANANA FAIRY ISLAND>", // 111
    "DK ISLES <K-LUMSYS PRISON>", // 112
    "HIDEOUT HELM <BLAST-O-MATIC ON>", // 113
    "MOVE GET", // 114
    "GUN GET", // 115
    "HIDEOUT HELM <BLAST-O-MATIC OFF>", // 116
    "HIDEOUT HELM <BONUS BARRELS>", // 117
    "CRYSTAL CAVES <CABINS>", // 118
    "CRYSTAL CAVES <ROTATING ROOM>", // 119
    "CRYSTAL CAVES <TILE FLIPPING>", // 120
    "CREEPY CASTLE <TUNNELS>", // 121
    "INTRO STORY MEDLEY", // 122
    "TRAINING GROUNDS", // 123
    "ENGUARDE", // 124
    "K-LUMSY CELEBRATION", // 125
    "CREEPY CASTLE <CRYPT>", // 126
    "HEADPHONES GET", // 127
    "PEARL GET", // 128
    "CREEPY CASTLE <DUNGEON WITH CHAINS>", // 129
    "ANGRY AZTEC <LOBBY>", // 130
    "JUNGLE JAPES <LOBBY>", // 131
    "FRANTIC FACTORY <LOBBY>", // 132
    "GLOOMY GALLEON <LOBBY>", // 133
    "MAIN MENU", // 134
    "CREEPY CASTLE <INNER CRYPTS>", // 135
    "CREEPY CASTLE <BALLROOM>", // 136
    "CREEPY CASTLE <GREENHOUSE>", // 137
    "K ROOLS THEME", // 138
    "CREEPY CASTLE <SHED>", // 139
    "CREEPY CASTLE <WIND TOWER>", // 140
    "CREEPY CASTLE <TREE>", // 141
    "CREEPY CASTLE <MUSEUM>", // 142
    "BBLAST FINAL STAR", // 143
    "DROP RAINBOW COIN", // 144
    "RAINBOW COIN GET", // 145
    "NORMAL STAR", // 146
    "BEAN GET", // 147
    "CRYSTAL CAVES <ARMY DILLO>", // 148
    "CREEPY CASTLE <KUT OUT>", // 149
    "CREEPY CASTLE <DUNGEON WITHOUT CHAINS>", // 150
    "BANANA MEDAL GET", // 151
    "K ROOLS BATTLE", // 152
    "FUNGI FOREST <LOBBY>", // 153
    "CRYSTAL CAVES <LOBBY>", // 154
    "CREEPY CASTLE <LOBBY>", // 155
    "HIDEOUT HELM <LOBBY>", // 156
    "CREEPY CASTLE <TRASH CAN>", // 157
    "END SEQUENCE", // 158
    "K-LUMSY ENDING", // 159
    "JUNGLE JAPES", // 160
    "JUNGLE JAPES <CRANKYS AREA>", // 161
    "K ROOL TAKEOFF", // 162
    "CRYSTAL CAVES <BABOON BLAST>", // 163
    "FUNGI FOREST <BABOON BLAST>", // 164
    "CREEPY CASTLE <BABOON BLAST>", // 165
    "DK ISLES <SNIDES ROOM>", // 166
    "K ROOLS ENTRANCE", // 167
    "MONKEY SMASH", // 168
    "FUNGI FOREST <RABBIT RACE>", // 169
    "GAME OVER", // 170
    "WRINKLY KONG", // 171
    "100TH CB GET", // 172
    "K ROOLS DEFEAT", // 173
    "NINTENDO LOGO", // 174
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
} menu_options;

typedef struct menu_option_tree {
    /* 0x000 */ s8 up;
    /* 0x001 */ s8 down;
    /* 0x002 */ s8 left;
    /* 0x003 */ s8 right;
} menu_option_tree;

static menu_options selected_music_menu_option = MENUOP_SONGNAME;
static u8 changing_position = 0;
#define CONTROLS_Y 120
#define MOVEMENT_DEADZONE 20

static menu_option_tree music_menu_tree[] = {
    {.up = NULL_OPTION, .down=MENUOP_PLAY, .left=NULL_OPTION, .right=NULL_OPTION}, // songname
    {.up = MENUOP_SONGNAME, .down=NULL_OPTION, .left=NULL_OPTION, .right=MENUOP_PAUSE}, // play
    {.up = MENUOP_SONGNAME, .down=NULL_OPTION, .left=MENUOP_PLAY, .right=MENUOP_STOP}, // pause
    {.up = MENUOP_SONGNAME, .down=NULL_OPTION, .left=MENUOP_PAUSE, .right=NULL_OPTION}, // stop
};

void setSelectedOption(int option) {
    if (option == NULL_OPTION) {
        return;
    }
    selected_music_menu_option = option;
}

void stopSong(void) {
    for (int i = 0; i < 4; i++) {
        if (SongInWriteSlot[i]) {
            cancelMusic(SongInWriteSlot[i], i);
        }
    }
}

void playNewSong(int index) {
    for (int i = 0; i < 4; i++) {
        SongInWriteSlot[i] = 0;
        for (int j = 0; j < 0x1A; j++) {
            alEvtqFlushType(&SeqPlayers[i]->evtq, j);
        }
    }
    preventSongPlaying = 1;
    MusicTrackChannels[0] = index; // This is an incredibly incredibly dirty way to do it, but it yields better load times
}

void menuLoop(void) {
    switch (selected_music_menu_option) {
        case MENUOP_SONGNAME:
            if (NewlyPressedControllerInput.Buttons.d_left) {
                song_index -= 1;
                if (song_index == 0) {
                    song_index = 174;
                }
                playSFX(64);
            } else if (NewlyPressedControllerInput.Buttons.d_right) {
                song_index += 1;
                if (song_index == 175) {
                    song_index = 1;
                }
                playSFX(64);
            } else if (NewlyPressedControllerInput.Buttons.a) {
                playNewSong(song_index);
            } else if (NewlyPressedControllerInput.Buttons.b) {
                stopSong();
            }
            break;
        case MENUOP_PLAY:
            if (NewlyPressedControllerInput.Buttons.a) {
                playNewSong(song_index);
            }
            break;
        case MENUOP_PAUSE:
            break;
        case MENUOP_STOP:
            if (NewlyPressedControllerInput.Buttons.a) {
                stopSong();
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

Gfx* displayMusicMenu(Gfx* dl) {
    dl = renderMenuOption(dl, song_names[(s32)song_index], MENUOP_SONGNAME, 20, CONTROLS_Y);
    int play_tray_y = CONTROLS_Y + 20;
    dl = renderMenuOption(dl, "PLAY", MENUOP_PLAY, 20, play_tray_y);
    dl = renderMenuOption(dl, "PAUSE", MENUOP_PAUSE, 120, play_tray_y);
    dl = renderMenuOption(dl, "STOP", MENUOP_STOP, 220, play_tray_y);
    return dl;
}
#include "vars.h"

extern void setPermanentFlag(s16 flagIndex);
extern void setGlobalFlag(s16 flagIndex);
extern void setTemporaryFlag(s16 flagIndex);
extern void* findActorWithType(s32 search_actor_type);

// Stuff to do with Tag Anywhere and the stack trace
extern void initHack(void);
extern void initStackTrace(void);

extern void quickInit(void);
extern Gfx* displayListModifiers(Gfx* dl);
extern void menuLoop(void);

extern Gfx* drawPixelTextContainer(Gfx* dl, int x, int y, char* str, int red, int green, int blue, int alpha, int offset);
extern Gfx* displayMusicMenu(Gfx* dl);

extern const s16 kong_flags[5];
extern void displayListCode(void);
extern void preventSongRestartDeadlock(int write_slot, int song, float volume);
extern int increment_event_count(ALEventQueue* evtq, ALEvent* event, ALMicroTime delta);
extern int decrease_event_count(ALEventQueue* evtq, ALEvent* event);
extern void decrease_event_count_2(ALLink* eventListItem, ALEventQueue* evtqueue);
extern void measureEvents(ALCSPlayer* player);
extern ALVoiceState* updateVoicesUsedAllocate(ALCSPlayer* player, char note, char velocity, char channel);
extern void updateVoicesUsedFree(ALCSPlayer* player, ALVoice* voice);
extern void updateUpdatesUsed(int* pVoice, int type, int* param);
extern void updateUpdatesUsed2(int* param);
extern void voiceDies();
extern void voiceDies2();
extern void musicBugMonitor();
extern void musicBugMonitor2();
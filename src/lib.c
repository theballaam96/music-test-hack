#include "../include/common.h"

const s16 kong_flags[] = {385,6,70,66,117};

void setPermanentFlag(s16 flagIndex) {
	setFlag(flagIndex, 1, 0);
}

void setGlobalFlag(s16 flagIndex) {
	setFlag(flagIndex, 1, 1);
}

void setTemporaryFlag(s16 flagIndex) {
	setFlag(flagIndex, 1, 2);
}

void* findActorWithType(s32 search_actor_type) {
	for (s32 i = 0; i < ActorCount; i++) {
		actorData* _actor_ = (actorData*)ActorArray[i];
		if (_actor_->actorType == search_actor_type) {
			return _actor_;
		}
	}
	return 0;
}

int getVoicesUsed(){
	if (MusicTrackChannels[0] == 0){
		return 0;
	}
	int slot = getSongWriteSlot(MusicTrackChannels[0]);
	ALVoiceState* voiceList = SeqPlayers[slot]->vAllocHead;
	if (*(int*)(&voiceList) == 0){
		return 0;
	}
	for (int i = 1; i <= 44; i++){
		if (*(int*)(&voiceList) == 0){
			return i;
		} else {
			voiceList = (ALVoiceState*) &voiceList;
		}
	}
	return 44;
}

int getEventsUsed(){
	if (MusicTrackChannels[0] == 0){
		return 0;
	}
	int slot = getSongWriteSlot(MusicTrackChannels[0]);
	ALLink queue = SeqPlayers[slot]->evtq.allocList;
	if (*(int*)(&queue) == 0){
		return 0;
	}
	for (int i = 1; i <= 64; i++){
		if (*(int*)(&queue) == 0){
			return i;
		} else {
			queue = *(ALLink*) &queue;
		}
	}
	return 64;
}

int getUpdatesUsed(){
	if (MusicTrackChannels[0] == 0){
		return 0;
	}
	int* paramList = synthesizer->paramList;
	if(paramList == 0){
		return 112;
	}
	for (int i = 1; i <= 112; i++){
		if (*(int*)(&paramList) == 0){
			return i;
		} else {
			paramList = *(int*) &paramList;
		}
	}
	return 0;
}
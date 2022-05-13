#pragma once

#include "raylib.h"
#include "ADTSet.h"
#include "draw_related_funcs.h"

#include <time.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_W_G 880
#define SCREEN_W_T 400

typedef enum {
	TITLE_SCREEN, START_GAME, CHARACTER_SELECT
} StateName;

typedef struct title_screen* TitleScreen;
typedef struct game_screen* GameScreen;

// typedef struct char_select {

// }* CharSelect;

typedef struct state {
	StateName name;
	TitleScreen title_screen;
	GameScreen game_screen;
	// CharSelect char_select;
	int selected_character;
}* State;

// Πληροφορίες για το ποια πλήκτρα είναι πατημένα
typedef struct key_state {
	bool up;
	bool down;
	bool left;
	bool right;
	bool space;
	bool enter;
	bool n;
	bool p;
}* KeyState;

// STATE_CREATE

State state_create();

// STATE_INFO

void* state_info(State state);

// STATE_UPDATE

void state_update(State state, KeyState keys);

void state_destroy(State state);

void destroy_title_scr(State state);

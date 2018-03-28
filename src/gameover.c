// Game over (source)
// (c) 2018 Jani Nykänen

#include "gameover.h"

#include "game.h"
#include "stage.h"
#include "info.h"
#include "transition.h"

#include "engine/sys.h"
#include "engine/graph.h"
#include "engine/input.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// Bitmaps
static BITMAP* bmpGameOver;

// Timer
static short timer;
// Mode
static char goverMode;

// Constants
static const short TIMER_MAX = 120;


// Reset
static void reset() {

    destoy_bitmap(bmpGameOver);
    game_hard_reset();
}


// Pause loop
static void gover_loop() {

    short t;

    if(++ timer > TIMER_MAX) {

        start_transition(reset);
    }

    // Draw Game over! text
    if(timer < 64) {

        t = (64-timer) / 4;
        draw_bitmap_region(bmpGameOver,0,
            32 * (short)goverMode + t,160,32 -t*2, 160 -80, 80-16+t, FLIP_NONE);
    }
}


// Pause the game
void game_over(char mode) {

    // Load Game over! bitmap
    bmpGameOver = load_bitmap("ASSETS/BITMAPS/GOVER.BIN");

    goverMode = mode;
    timer = 0;

    // Set update function
    set_update_func(gover_loop);
}

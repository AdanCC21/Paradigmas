#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


void andanMusic(Music music,float timePlayed);

void andanMusic(Music music,float timePlayed)
{
    PlayMusicStream(music);
    UpdateMusicStream(music);

    timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

    if (timePlayed > 1.0f)
    {
        timePlayed = 1.0f;
    }
}
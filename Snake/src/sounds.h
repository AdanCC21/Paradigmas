#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

/*
    Función que reproduce la música y actualiza su estado
    @param music: la música a reproducir
    @param timePlayed: el tiempo de reproducción de la música
*/
void andanMusic(Music music, float timePlayed);

void andanMusic(Music music, float timePlayed)
{
    // Reproducir la música y actualizar su estado
    PlayMusicStream(music);
    UpdateMusicStream(music);

    // Calcular el tiempo de reproducción como porcentaje del tiempo total
    timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

    // Asegurarse de que el tiempo de reproducción no exceda el 100%
    if (timePlayed > 1.0f)
    {
        timePlayed = 1.0f;
    }
}

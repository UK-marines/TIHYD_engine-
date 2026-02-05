#include <stdio.h>
#include "tihyd_entities.h"

int loadgame(struct player *a) 
{
    FILE *f = fopen("save-game.txt", "r"); 
    if (f == NULL) {printf("Error opening file");return 1;}
    fscanf(f, "Name:%[^;];\n", a->name);
    short *stats[] = {
        &a->body.hp, &a->body.endurance, &a->body.tired, &a->body.hunger, &a->body.thirst, &a->body.bleeding, &a->mind.pain,
        &a->body.sick, &a->body.hurt, &a->mind.panic, &a->mind.stress, &a->mind.unhappy, &a->body.overloaded, 
        &a->body.temperature, &a->body.hascold, &a->mind.drunk, &a->state.dead, &a->state.knoxxed
    };

    short count = sizeof(stats) / sizeof(stats[0]);
    short buffer;

    for (char i = 0; i<count; i++)
    {
        if (fscanf(f, "%*[^:]:%hd;\n", &buffer) == 1) {*stats[i] = (short)buffer;}
        else {printf("ERROR READING STAT #%hd\n", i);}
    } 

    fclose(f);
    printf("Name: %s\n", a->name);
    for (char i = 0; i<count; i++)
    {
        printf("Stat %d: %hd\n", i, *stats[i]);
    } 
    return 0;
}

int main() {
    struct player p1 = {0}; 

    if (loadgame(&p1) == 0) {
        printf("\nGame loaded successfully!\n");
    } else {
        printf("\nFailed to load game.\n");
    }

    return 0;
}
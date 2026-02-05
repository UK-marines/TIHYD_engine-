#include <stdio.h>
#include "tihyd_entities.h"

int writegame(struct player *a) 
{
    FILE *f = fopen("save-game.txt", "w"); 
    if (f == NULL) {printf("Error opening file");return 1;}
    fprintf(f, "Name:%s;\n", a->name);
    char *stat_names[] = {
        "HP", "Endurance", "Tired", "Hunger", "Thirst", "Bleeding", "Pain",
        "Sick", "Hurt", "Panic", "Stress", "Unhappy", "Overload", 
        "Temperature", "Cold", "Drunk", "Dead", "Knoxxed"
    };

    short *stat_adr[] = {
        &a->body.hp, &a->body.endurance, &a->body.tired, &a->body.hunger, &a->body.thirst, &a->body.bleeding, &a->mind.pain,
        &a->body.sick, &a->body.hurt, &a->mind.panic, &a->mind.stress, &a->mind.unhappy, &a->body.overloaded, 
        &a->body.temperature, &a->body.hascold, &a->mind.drunk, &a->state.dead, &a->state.knoxxed
    };

    short count = sizeof(stat_adr) / sizeof(stat_adr[0]);

    for (char i = 0; i<count; i++)
    {
        if (fprintf(f, "%s:%hd;\n", stat_names[i], *stat_adr[i]) < 0) {printf("ERROR READING STAT #%hd\n", i);}
    } 

    fclose(f);
    printf("Name: %s\n", a->name);
    for (char i = 0; i<count; i++)
    {
        printf("Stat %d: %hd\n", i, *stat_adr[i]);
    } 
    return 0;
}

int main() {
    struct player p1 = {0}; 

    if (writegame(&p1) == 0) {
        printf("\nGame writed successfully!\n");
    } else {
        printf("\nFailed to write game.\n");
    }

    return 0;
}

#include <stdio.h>

struct player 
{
    char name[32];
    short hp;
    short endurance; 
    short tired;
    short hunger;
    short thirst;
    short is_bleeding;
    short have_pain;
    short is_sick;
    short is_hurt;
    short panic;
    short stress;
    short is_unhappy;
    short overloaded;
    short temperature;
    short has_a_cold;
    short is_drunk;
    short dead;
    short knoxxed;
};

int loadgame(struct player *a) 
{
    FILE *f = fopen("save-game.txt", "r"); 
    if (f == NULL) {printf("Error opening file");return 1;}
    fscanf(f, "Name:%[^;];\n", a->name);
    short *stats[] = {
        &a->hp, &a->endurance, &a->tired, &a->hunger, &a->thirst, &a->is_bleeding, &a->have_pain,
        &a->is_sick, &a->is_hurt, &a->panic, &a->stress, &a->is_unhappy, &a->overloaded, 
        &a->temperature, &a->has_a_cold, &a->is_drunk, &a->dead, &a->knoxxed
    };

    char count = 18;
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
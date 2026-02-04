#include <stdio.h>

struct player {
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

/*int main() {
    struct Zomboid zomboid = {"John_Zomboid", 100, 70, 20, 10, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0};
    
        FILE *fptr = fopen("save-game.txt", "w"); 
        if (fptr == NULL) {printf("Error opening file");return 1;}

    fprintf(fptr, "Name:%s;\nHP:%d;\nEndurance:%d;\nTired:%d;\nHunger:%d;\nThirst:%d;\nBleeding:%d;\nPain:%d;\nSick:%d;\nHurt:%d;\n", zomboid.name, zomboid.hp, zomboid.endurance, zomboid.tired, zomboid.hunger, zomboid.thirst, zomboid.is_bleeding, zomboid.have_pain, zomboid.is_sick, zomboid.is_hurt);
    fprintf(fptr, "Panic:%d;\nStress:%d;\nUnhappy:%d;\nOverload:%d;\nTemprerature:%d;\nCold:%d;\nDrunk:%d;\nDead:%d;\nInfected:%d;\n", zomboid.panic, zomboid.stress, zomboid.is_unhappy, zomboid.overloaded, zomboid.temperature, zomboid.has_a_cold, zomboid.is_drunk, zomboid.dead, zomboid.knoxxed);

    printf("Succesfully opened and writed file.\n");
    fclose(fptr);
    return 0;
}*/

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
        &a->hp, &a->endurance, &a->tired, &a->hunger, &a->thirst, &a->is_bleeding, &a->have_pain,
        &a->is_sick, &a->is_hurt, &a->panic, &a->stress, &a->is_unhappy, &a->overloaded, 
        &a->temperature, &a->has_a_cold, &a->is_drunk, &a->dead, &a->knoxxed
    };

    char count = 18;
    short buffer;

    for (char i = 0; i<count; i++)
    {
        if (fprintf(f, "%s:%hd;\n", stat_names[i], *stat_adr[i]) < 0) {*stat_adr[i] = (short)buffer;}
        else {printf("ERROR READING STAT #%hd\n", i);}
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
        printf("\nGame loaded successfully!\n");
    } else {
        printf("\nFailed to load game.\n");
    }

    return 0;
}

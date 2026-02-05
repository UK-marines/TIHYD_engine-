#ifndef TIHYD_ENTITIES_H  
#define TIHYD_ENTITIES_H  

struct body {
    short hp;
    short endurance;
    short tired;
    short hunger;
    short thirst;
    short temperature;
    short bleeding;
    short sick;
    short hascold;
    short hurt;
    short overloaded;
};

struct mind {
    short panic;
    short stress;
    short unhappy;
    short drunk; //most important lmao;
    short pain;
};

struct states {
    short dead;
    short knoxxed;
};

struct player {
    char name[32];
    
    struct body body;   
    struct mind mind;   
    struct states state; 
};

#endif 
#include <string.h>
#include <stdio.h>

struct person{
    char *v;
    char *n;
    char *nr;
    struct person *next;
};

typedef struct person item;

void add(char*, char*, char*);
void append(char*, char*, char*);
void count(void);
void xprint(void);
void read(void);

item *head = NULL;

int main(){

    read();
    // count();
    xprint();

    puts("ende");

    return 0;
}

void add(char *v, char *n, char *nr){
    item *test;
    item *e = (item *)malloc(sizeof(item));
    e->v = v;
    e->n = n;
    e->nr = nr;
    e->next = head;
    head = e;

    printf("\n%s\n%s\n%s\n", e->v, e->n, e->nr);
}

void append(char *v, char *n, char *nr){
    char t[100];
    FILE *f;
    f = fopen("kontakt.txt", "a");

    if(strlen(v) != 0 && strlen(n) != 0 && strlen(nr) != 0){
        sprintf(t,"%s %s %s\r\n", v, n, nr);
        fputs(t, f);
    }else{
        puts("kann nicht hinzugefügt werden\n");
    }

    fclose(f);
}

void count(void){
    item *e = head;
    //e = head;
    int i = 0;
    while(e){
        i++;
        e = e->next;
        printf("out -- > %s\n", e->nr);
    }

    printf("%d\n", i);
}

void xprint(){
    item *e = head;

    while(e){
        printf("out -- > %s\n", e->v);
        e = e->next;
    }
}

void read(){
    int c;
    int i = 0;
    char t[100];
    char tmpVorname[20];
    char tmpNachname[20];
    char tmpNr[20];
    FILE *f;
    f = fopen("kontakt.txt", "r");


    if(f != NULL){
        do{
            c = fgetc(f);
            if(c != 10 && c != 13){
                t[i] = c;
                i++;
            }else if(c == 10){
                t[i] = 0;
                //printf("%s\n", t);
                sscanf(t, "%s %s %s", tmpVorname, tmpNachname, tmpNr);
                add(strdup(tmpVorname), strdup(tmpNachname), strdup(tmpNr));
                i = 0;
                
            }
        }while(c != EOF);
    }else{
        puts("error");
    }

    fclose(f);
}
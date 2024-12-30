#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
char programmWeiter= 'j';
while(1){
 char stadt1[14];
 char stadt2[14];
 char zeilen[30];
 double breitengrad1;
 double langengrad1;
 double breitengrad2;
 double langengrad2;
 int gefunden1 = 0; 
 int gefunden2 = 0; 

 printf("\033[2J\033[H");
 printf("########################################################################\n");
 printf("                           Wo ist die sonne?                            \n");
 printf("                              (c) M K                                   \n");
 printf("Ich werde Ihnen helfen, herauszufinden, wo sich die Sonne befindet,     \n");
 printf("wohrend Sie swischen Staedten reisen:                                   \n");
 printf("########################################################################\n");

 FILE *datei = fopen("koordinaten.txt", "r");
while (!gefunden1) {
 printf("Von: ");
 scanf("%s", stadt1);
 datei = fopen("koordinaten.txt", "r");

    while (fgets(zeilen, sizeof(zeilen), datei) != NULL) {
     char stadtname[14];
     sscanf(zeilen, "%s", stadtname);

        if (strcmp(stadt1, stadtname) == 0) {
         sscanf(zeilen, "%s %lf %lf", stadtname, &breitengrad1, &langengrad1);
         gefunden1 = 1;
         break;
        }
    }
    
 if (gefunden1 == 0) {
 printf("Fehler, %s ist kein gultiger Stadtname. Bitte versuche es erneut. \n", stadt1);} 
 fclose(datei);
}

while (!gefunden2) {
 printf("Nach: ");
 scanf("%s", stadt2);
 datei = fopen("koordinaten.txt", "r");

    while (fgets(zeilen, sizeof(zeilen), datei) != NULL) {
     char stadtname[14];
     sscanf(zeilen, "%s", stadtname);

        if (strcmp(stadt2, stadtname) == 0) {
         sscanf(zeilen, "%s %lf %lf", stadtname, &breitengrad2, &langengrad2);
         gefunden2 = 1;
         break;
        }
    }

 if (gefunden2 == 0) {
 printf("Fehler, %s ist kein gultiger Stadtname. Bitte versuche es erneut. \n", stadt2);} 
 fclose(datei);
}

 int jetztzeit=24;  
 int endzeit=24;
while (jetztzeit < 0 || jetztzeit > 23){
 printf("Abfahrt um (0-23): ");
 scanf("%d", &jetztzeit);
}
while (endzeit < 0 || endzeit > 23){
 printf("Ankunft um (0-23): ");
 scanf("%d", &endzeit);
}

 int dauer = endzeit - jetztzeit;
 double distanz;
 double breitKM= 111*(breitengrad2 - breitengrad1);
 double langKM= (86,84)*(langengrad2 - langengrad1);
 distanz = sqrt(pow(breitKM, 2) + pow(langKM, 2));
 double geschwindigkeit= distanz/dauer;
 printf("Distanz: %lf km\n", distanz);
 printf("Durch. Geschwindigkeit: %f km/h \n", geschwindigkeit);

 int norden = 0;
 int sud = 0;
 int ost = 0;
 int westen = 0;

 if (breitKM > 0){norden=1;}
 if (breitKM < 0){sud=1;}
 if (langKM > 0){ost=1;}
 if (langKM < 0){westen=1;}

 int scheintWesten = endzeit-12;
 int scheintOsten = 12-jetztzeit; 
 if (scheintOsten >= 5){
   scheintOsten==5;
 }
 if ((norden==0 & sud==0)||endzeit <= 7 || jetztzeit >= 19 || (scheintOsten == scheintWesten)){
   printf("Die Sonne scheint nicht von den Seiten oder die Sonne scheint von beiden Seiten gleich lange.\n");
 }
 else{
 if (norden==1 & (scheintOsten > scheintWesten)){
   printf("Sonne wird meistens von der rechten Seite kommen!\nBitte kaufen Sie am linken Sitzplatz ein ticket.\n");
 }
 if (norden==1 & (scheintOsten < scheintWesten)){
   printf("Sonne wird meistens von der linken Seite kommen!\nBitte kaufen Sie am rechten Sitzplatz ein ticket.\n");
 }
 if (sud==1 & (scheintOsten > scheintWesten)){
   printf("Sonne wird meistens von der linken Seite kommen!\nBitte kaufen Sie am rechten Sitzplatz ein ticket.\n");
 }
 if (sud==1 & (scheintOsten < scheintWesten)){
   printf("Sonne wird meistens von der rechten Seite kommen!\nBitte kaufen Sie am linken Sitzplatz ein ticket.\n");
 }
}
 
   if (programmWeiter == 'j') {
    printf("Kann ich noch helfen (j/n)? ");
    scanf(" %c", &programmWeiter);
      if(programmWeiter=='n'){
       printf("Danke! Tschuess! ");
       return 0;
      }
   }
}
}
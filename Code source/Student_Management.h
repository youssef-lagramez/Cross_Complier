typedef struct{

    int id;
    char firstName[30],
            lastName[30],
            option[40],
            Level[40];

}Student;

Student shiftToLastLine(){
    FILE *F = fopen("class.txt","r");
    Student Stud;
    Stud.id = 0;
    while (fscanf(F,"%d,%[^,],%[^,],%[^,],%[^\n]\n",&Stud.id,Stud.firstName,Stud.lastName,Stud.Level,Stud.option) != EOF){}
    fclose(F);
    return Stud;
}

void add_Student(){
    Student Stud;
    FILE *F = fopen("class.txt","a+");
    if(F==NULL)
    {
        printf("you cannot create the file.");
        getchar();
    } else{
    getchar();
    printf(" - firstName : ");
    scanf("%s",&Stud.firstName);
    printf(" - lastName : ");
    scanf("%s",&Stud.lastName);
    printf(" - option : ");
    scanf("%s",&Stud.option);
    printf(" - Level : ");
    scanf("%s",&Stud.Level);
    Student Stud2 = shiftToLastLine();
    fprintf(F, "%d,%s,%s,%s,%s \n",Stud2.id+1,Stud.firstName,Stud.lastName,Stud.Level,Stud.option);
    fclose(F);
    }
}

void lecture(){
    FILE *F = fopen("class.txt","r");
    Student Stud;
    if (F == NULL){
        printf("impossible to open the data file!");
        getchar();
    } else{
    while (fscanf(F,"%d,%[^,],%[^,],%[^,],%[^\n]\n",&Stud.id,Stud.firstName,Stud.lastName,Stud.Level,Stud.option) != EOF)
    printf("%d - firstName : %s|\tlastName : %s|\tLevel : %s|\toption : %s\n",Stud.id,Stud.firstName,Stud.lastName,Stud.Level,Stud.option);
    }
    fclose(F);
}

void remove_Student(){
    FILE *F,*F2;
    int id = 0;
    Student Stud;
    F=fopen("class.txt","r");
    F2=fopen("class2.txt","w+");
    if(F==NULL || F2 == NULL)
    {
        printf("impossible to open the file!");
        getchar();
    }
    else{
        printf("iD of Student: ");
        scanf("%d",&id);
        while (fscanf(F,"%d,%[^,],%[^,],%[^,],%[^\n]\n",&Stud.id,Stud.firstName,Stud.lastName,Stud.Level,Stud.option) != EOF)
            if(Stud.id != id)
                fprintf(F2, "%d,%s,%s,%s,%s \n",Stud.id,Stud.firstName,Stud.lastName,Stud.Level,Stud.option);
        fclose(F);
        fclose(F2);
        remove("class.txt");
        rename("class2.txt","class.txt");
    }

}

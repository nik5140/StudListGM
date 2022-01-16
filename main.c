#include <stdio.h>
#include <stdlib.h>

int generateMark()
{
  //  srand(time(NULL));
    int mark;
    mark = rand()%10;
    if (mark>5)
        mark=5;
    else if (mark<4)
        mark = 3;

    return mark;
}


int main()
{
    system("chcp 1251");
    int i=0;
    struct Students
    {
        char GroupName[12];
        char SurName[13];

        struct Marks{
        int physicsMark;
        int operationSystemsMark;
        int mathMark;
        int codingMark;
           } nMark;
    };
    srand(time(NULL));
    struct Students *z;
    struct Students *zh;
    int n; // количество студентов в группе
    char *Names[12] = {"Андриенко", "Валиулин", "Хопкинс", "Перельман", "Гусейнов",
                        "Фиразмитдинов", "Алкалоидов", "Бэнсенко", "Берсерковский", "Ктулхович"};
    char *Groups[10] = {"Э9А40", "9440", "9441"};

    printf("Пожалуйста введите количество студентов в списке (3)\n");
    scanf("%d", &n);
    z = (struct Students*)malloc(sizeof(struct Students)*n);
    zh = (struct Students*)malloc(sizeof(struct Students)*n);
    int mark=0;
    for (i=0; i<n; i++)
    {
    strcpy(z[i].GroupName, Groups[rand()%2]);
    strcpy(z[i].SurName, Names[i]);
    mark=generateMark();
    z[i].nMark.physicsMark = mark;
    mark=generateMark();
    z[i].nMark.operationSystemsMark = mark;
    mark=generateMark();
    z[i].nMark.mathMark = mark;
    mark=generateMark();
    z[i].nMark.codingMark = mark;
    }

    z[3].nMark.physicsMark = 3;
    z[3].nMark.operationSystemsMark = 4;
    z[3].nMark.mathMark = 5;
    z[3].nMark.codingMark = 4;


    printf("____________________________________________________________________________________________\n");
    printf("|             |            |                          Оценки                               |\n");
    printf("| Фамилия     |   Группа   |  Физика  |  Операционные  |  Математика  |  Программирование  |\n");
    printf("|             |            |          |    системы     |              |                    |\n");
    printf("|------------------------------------------------------------------------------------------|\n");
    for (i=0; i<n; i++)
    {
        printf("|%13s|%12s| %8d |  %12d  |  %10d  |  %16d  |\n",z[i].SurName, z[i].GroupName, z[i].nMark.physicsMark, z[i].nMark.operationSystemsMark,
               z[i].nMark.mathMark,z[i].nMark.codingMark);
        printf("|------------------------------------------------------------------------------------------|\n");
    }
    int countGood=0;
    for (i=0; i<n; i++)
    {
        if (z[i].nMark.physicsMark>3&&z[i].nMark.operationSystemsMark>3&&z[i].nMark.mathMark>3&&z[i].nMark.codingMark>3)
        {
            zh[countGood] = z[i];
            countGood++;
        }
    }

    if(countGood>0)
    {
    printf("Приведем список студентов, сдавших сессию без троек\n");
    printf("____________________________________________________________________________________________\n");
    printf("|             |            |                          Оценки                               |\n");
    printf("| Фамилия     |   Группа   |  Физика  |  Операционные  |  Математика  |  Программирование  |\n");
    printf("|             |            |          |    системы     |              |                    |\n");
    printf("|------------------------------------------------------------------------------------------|\n");
    for (i=0; i<countGood; i++)
    {
        printf("|%13s|%12s| %8d |  %12d  |  %10d  |  %16d  |\n",zh[i].SurName, zh[i].GroupName, zh[i].nMark.physicsMark, zh[i].nMark.operationSystemsMark,
               zh[i].nMark.mathMark,zh[i].nMark.codingMark);
        printf("|------------------------------------------------------------------------------------------|\n");
    }
    }


 //   printf("Hello world!\n");
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct STUDENT_MANAGEMENT_SYSTEM{

    int rollNO;
    char name[50];
    char email[50];
    float cgpa;
};

struct STUDENT_MANAGEMENT_SYSTEM student[100];
int count = 0;
void addstudent(){
if (count >=100){
    printf("\n❌ data base is full\n");
    return;
}
printf("\n========== ADD STUDENT ===========\n");

printf("ENTER ROll NO");
scanf("%d",&student[count].rollNO);
printf("ENTER NAME:");
scanf("%s",student[count].name);
printf("ENTER EMAIL:");
scanf("%s",student[count].email);
printf("ENETR CGPA (0.0 - 10.00)");
scanf("%f",&student[count].cgpa);
count++;
printf("\n✅student added succesfully\n");
}


void viewallstudent() {
if(count==0){
    printf("\n❌no student found\n");
    return;
}
printf("\n==================== ALL STUDENTS ======================\n");
printf("%-10s %-20s %-30s %-8s\n", "ROLL", "NAME", "EMAIL", "CGPA");
printf("──────────────────────────────────────────────────────────\n");

for(int i=0; i<count; i++){
    printf("%-10d %-20s %-30s %-8.2f\n" ,student[i].rollNO ,student[i].name , student[i].email , student[i].cgpa);
}
printf("\n");
}
void searchstudent(){
    if(count == 0){
        printf("\n❌no student in database\n");
    return;
    }
printf("\n=================== SEARCH STUDENT ====================\n");
int rollNO;
printf("Enter roll no to search the student\n");
scanf("%d",&rollNO);
int found =0;
for(int i=0; i<count; i++){
    if(student[i].rollNO==rollNO){
        printf("\n✅ student found\n");
        printf("ROLL: %d\n", student[i].rollNO);
        printf("NAME: %s\n", student[i].name);
        printf("EMAIL: %s\n", student[i].email);
        printf("CGPA: %f\n", student[i].cgpa);
        found = 1;
        break;
    
        }
      
      }
      if (!found){
        printf("\n ❌ STUDENT NOT FOUND\n");
}
}

void deletestudent(){
if(count==0){
   printf("\n❌no student in database\n");
    return;
}
printf("===================== DELETE STUDENT ====================");
int rollNO;
scanf("%d",&rollNO);
int found =0;
for(int i=0; i<count; i++){
    if(student[i].rollNO==rollNO){
        for(int j=i; j<count -1; j++){
            student[j]=student[j+1];
        }
        count--;
         printf("\n✅ Student deleted successfully!\n\n");
         found =1;
         break;
    }

}
if (!found){
    printf("\n ❌ STUDENT NOT FOUND\n");
}
}

void saveTofile(){
    FILE *file =fopen("student.txt", "w");
    if(file==NULL){
        printf("\n❌ Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++){
       fprintf(file ,"%d %s %s %.2f\n" , student[i].rollNO , student[i].name , student[i].email , student[i].cgpa);
    }
    fclose(file);
     printf("\n✅ Data saved to students.txt!\n");
        
}

void loadfromfile(){
  FILE *file = fopen("student.txt", "r");
  if(file == NULL){
    printf("\n⚠️  No previous data found. Starting fresh.\n");
    return;
  }
  count=0;
 while (fscanf(file,"%d %s %s %f" , &student[count].rollNO ,student[count].name , student[count].email , &student[count].cgpa)==4){
    count++;
 }
  fclose (file);
  printf("\n✅ Data loaded! (%d students found)\n", count);
}

void showstaticts(){
    if (count==0){
        printf("\n❌ No students!\n");
        return;
    }
printf("\n======================  STATISTICS  ===================== \n");
printf("\ntotal students : %d\n" , count);

float totalcgpa = 0;
float maxcgpa = student[0].cgpa;
float mincgpa = student[0].cgpa;

for ( int i = 0; i < count; i++){
    totalcgpa =totalcgpa+ student[i].cgpa;
    if(student[i].cgpa>maxcgpa) maxcgpa=student[i].cgpa;
    if(student[i].cgpa<mincgpa) mincgpa=student[i].cgpa;
}
printf("AVERAGE cgpa : %.2f\n" , totalcgpa/count);
printf("MAX cgpa : %.2f\n" , maxcgpa);
printf("MIN cgpa : %.2f\n" , mincgpa);

}

int main(){
int choice;

   printf("\n╔════════════════════════════════════╗\n");
     printf("║   STUDENT MANAGEMENT SYSTEM 🎓      ║\n");
     printf("╚════════════════════════════════════╝\n");

     loadfromfile();
      while(1){
        printf("\n====================.  MAIN MENU  .=================\n");
        printf("\n1. ADD STUDENT\n");
        printf("\n2. VEIW ALL STUDENT\n");
        printf("\n3. SEARCH STUDENT\n");
        printf("\n4. DELETE STUEDNT\n");
        printf("\n5. VEIW STATISTICS\n");
        printf("\n6.SAVE AND EXIT\n");
        printf("\n7. CLEAR SCREEN\n");
        printf("\n>>>>>>. ENTER YOUR CHOICE (1 TO 7) .<<<<<<");
         
        scanf("%d" , &choice);

        switch (choice){
        case 1:
           addstudent();
            break;
            
            case 2:
            viewallstudent();
            break;

            case 3:
            searchstudent();
            break;

            case 4:
            deletestudent();
            break;

            case 5:
            showstaticts();
            break;

            case 6:
            saveTofile();
             printf("\n✅ Goodbye! Data saved.\n");
             return 0;

             case 7:
             system("clear");
             break;

             default:
             printf("\n❌ Invalid choice! Please try again.\n");
              }
    
      }




  return 0;
}
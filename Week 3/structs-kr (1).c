#define MAX_AREA_SIZE 16
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct faculty {
    char *name;
    char area[MAX_AREA_SIZE];
    int num_students;
};


// add_grad_student increments the num_students count for the faculty passed

void add_grad_student(struct faculty *f) {
    f->num_students++;
}



int main() {
    // Declare a struct faculty named p1.
    struct faculty p1;

    // Initialize p1 to represent Professor Roger Grosse, whose research area
    // is ML (Machine Learning).  He is supervising 10 graduate students.
    p1.name = "Roger";
    strncpy(p1.area, "ML", MAX_AREA_SIZE);
    p1.area[MAX_AREA_SIZE - 1] = '\0';
    p1.num_students = 10;




    struct faculty *p2_pt;

	// allocate space for the faculty on the heap
    p2_pt = malloc(sizeof(struct faculty));


    // Set the values of *p2_pt to represent Professor Sheila McIlraith.
    // Her research area is KR (Knowledge Representation).
    // She is supervising 14 graduate students.
    p2_pt->name = "Sheila";
    //(*p2_pt).name
    strncpy(p2_pt->area, "KR", MAX_AREA_SIZE);
    p2_pt->area[MAX_AREA_SIZE - 1] = '\0';
    p2_pt->num_students = 14;

    add_grad_student(p2_pt);    //A
    add_grad_student(&p2_pt);   //B
    add_grad_student(*p2_pt);   //C

    add_grad_student(p1);       //A
    add_grad_student(&p1);      //B
    add_grad_student(*p1);      //C




	return 0;
}

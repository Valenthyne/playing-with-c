#include <stdio.h>
#include <time.h>

// Core structure to host patient data
struct HealthProfile {

    char firstName[30];
    char lastName[30];
    char gender;
    int mon;
    int day;
    int year;
    float height;
    float weight;

};

// Function prototypes for later use
void viewProfile (struct HealthProfile p);
int calcAge(int m2, int d2, int y2);
int * thr (int m, int d, int y);
float bmi(float weight, float height);
void printBMI();


int main() {

    printf("\t\t%s", "Welcome to the Health Record Service!\n\n");

    struct HealthProfile patient;

    // Input processing
    printf("%s", "Please enter the patient's first name: ");
    scanf("%s", &(patient.firstName));
    printf("\n%s", "Please enter the patient's last name: ");
    scanf("%s", &(patient.lastName));
    printf("\n%s", "Please enter the patient's gender (M/F): ");
    scanf("%s", &(patient.gender));
    printf("\n%s", "Please enter the patient's date of birth (MM-DD-YYYY): ");
    scanf("%d-%d-%d", &(patient.mon), &(patient.day), &(patient.year));
    printf("\n%s", "Please enter the patient's height (inches): ");
    scanf("%f", &(patient.height));
    printf("\n%s", "Please enter the patient's weight (pounds): ");
    scanf("%f", &(patient.weight));

    // Core function to display the now-initialized struct
    viewProfile(patient);

    return 0;
}

// Print the values of the health profile structure
void viewProfile (struct HealthProfile p) {

    int * thrData;
    thrData = thr(p.mon, p.day, p.year);

    puts("\n\tPatient Health Profile\n----------------------------------------");

    printf("%15s: %s", "First Name", p.firstName);
    printf("\n%15s: %s", "Last Name", p.lastName);
    printf("\n%15s: %d-%d-%d", "Date of Birth", p.mon, p.day, p.year);
    printf("\n%15s: %d", "Age", calcAge(p.mon, p.day, p.year));
    printf("\n%15s: %c", "Gender", p.gender);
    printf("\n%15s: %.2f in.", "Height", p.height);
    printf("\n%15s: %.2f lbs.\n", "Weight", p.weight);
    printf("\n%15s: %d bpm to %d bpm", "Heart Rate", thrData[0], thrData[1]);
    printf("\n%15s: %.2f\n", "BMI", bmi(p.weight, p.height));
    printBMI();
    puts("\n\nEnd of record.\n");

}

// Calculate the age of a given user based on the current time and date
int calcAge(int m2, int d2, int y2) {

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int m1 = tm.tm_mon + 1;
    int d1 = tm.tm_mday;
    int y1 = tm.tm_year + 1900;

    if (m1 > m2 && d1 > d2) {
        return y1 - y2;
    } else {
        return y1 - y2 - 1;
    }

}

// Return an array of the bounds for one's targeted heart rate, dependent on age
int * thr(int m, int d, int y) {

    static int thr[2];

    int age = calcAge(m, d, y);

    int maxRate = 220 - age;
    thr[0] = maxRate * 0.5;
    thr[1] = maxRate * 0.85;

    return thr;

}

// Calculate the BMI when considering weight in pounds and height in inches
float bmi(float weight, float height) {

    return ((weight * 703) / (height * height));

}

// Print relevant information regarding what the BMI values mean
void printBMI() {

    printf("\n\t\tBMI Values\n");
    printf("\n%12s: less than 18.5", "Underweight");
    printf("\n%12s: between 18.5 and 24.9", "Normal");
    printf("\n%12s: between 25 and 29.9", "Overweight");
    printf("\n%12s: 30 or greater", "Obese");

}

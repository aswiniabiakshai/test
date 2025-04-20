#include <stdio.h>
#include <stdlib.h>

void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]);
void displayMenu();
void controlLights(int rooms, int lights[]);
void readTemperature(int rooms, int temp[]);
void detectMotion(int rooms, int motion[]);
void securitySystem(int rooms, int locks[]);
void analyzeHouseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);

    int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
    initializeSystem(rooms, lights, temp, motion, locks);
    
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: controlLights(rooms, lights); break;
            case 2: readTemperature(rooms, temp); break;
            case 3: detectMotion(rooms, motion); break;
            case 4: securitySystem(rooms, locks); break;
            case 5: analyzeHouseStatus(rooms, lights, temp, motion, locks); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]) {
    printf("Initializing system...\n");
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        temp[i] = 22;
        motion[i] = 0;
        locks[i] = 1;
    }
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number.\n");
    }
}

void readTemperature(int rooms, int temp[]) {
    int room;
    printf("Enter room number to check temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Room %d Temperature: %d°C\n", room, temp[room - 1]);
    } else {
        printf("Invalid room number.\n");
    }
}

void detectMotion(int rooms, int motion[]) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number.\n");
    }
}

void securitySystem(int rooms, int locks[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number.\n");
    }
}

void analyzeHouseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
               lights[i] ? "ON" : "OFF",
               temp[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
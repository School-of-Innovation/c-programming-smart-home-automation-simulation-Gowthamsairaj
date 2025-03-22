/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */
#include <stdio.h>
#include <stdlib.h>

void initializeSystem(int rooms);
void displayMenu();
void toggleLight(int rooms);
void readTemperature(int rooms);
void checkMotionSensor(int rooms);
void securitySystem(int rooms);
void houseStatusSummary(int rooms);
void autoLockCheck();
void temperatureAlert(int rooms);
void energySavingMode(int rooms);

int *lights, *motion, *securityLocks;
float *temperature;
int motionCounter = 0;

int main() {
    int rooms, choice;

    printf("Enter number of rooms: ");
    scanf("%d", &rooms);

    lights = (int *)malloc(rooms * sizeof(int));
    motion = (int *)malloc(rooms * sizeof(int));
    securityLocks = (int *)malloc(rooms * sizeof(int));
    temperature = (float *)malloc(rooms * sizeof(float));

    initializeSystem(rooms);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleLight(rooms);
                break;
            case 2:
                readTemperature(rooms);
                break;
            case 3:
                checkMotionSensor(rooms);
                break;
            case 4:
                securitySystem(rooms);
                break;
            case 5:
                houseStatusSummary(rooms);
                break;
            case 6:
                printf("Exiting program...\n");
                free(lights);
                free(motion);
                free(securityLocks);
                free(temperature);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }

        autoLockCheck();
        temperatureAlert(rooms);
        energySavingMode(rooms);
    }

    return 0;
}

void initializeSystem(int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
        motion[i] = 0;
        securityLocks[i] = 1;
        temperature[i] = 22 + (rand() % 10);
    }
    printf("System initialized. All lights OFF, doors LOCKED, no motion detected.\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
    printf("============================\n");
}

void toggleLight(int rooms) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

void readTemperature(int rooms) {
    int room;
    printf("Enter room number to check temperature (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        printf("Room %d Temperature: %.2f°C\n", room, temperature[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

void checkMotionSensor(int rooms) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        motion[room - 1] = rand() % 2;
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected ⚠️" : "None");
        if (motion[room - 1]) {
            motionCounter = 0;
        } else {
            motionCounter++;
        }
    } else {
        printf("Invalid room number!\n");
    }
}

void securitySystem(int rooms) {
    int room;
    printf("Enter room number to toggle security lock (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        securityLocks[room - 1] = !securityLocks[room - 1];
        printf("Room %d door is now %s.\n", room, securityLocks[room - 1] ? "LOCKED 🔒" : "UNLOCKED 🔓");
    } else {
        printf("Invalid room number!\n");
    }
}

void houseStatusSummary(int rooms) {
    printf("\n===== House Status =====\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %.2f°C, Motion %s, Door %s\n", i + 1,
               lights[i] ? "ON" : "OFF",
               temperature[i],
               motion[i] ? "Detected ⚠️" : "None",
               securityLocks[i] ? "LOCKED 🔒" : "UNLOCKED 🔓");
    }
    printf("========================\n");
}

void autoLockCheck() {
    if (motionCounter >= 5) {
        printf("No motion detected for a while. Auto-locking all doors...\n");
        for (int i = 0; i < 5; i++) {
            securityLocks[i] = 1;
        }
        motionCounter = 0;
    }
}

void temperatureAlert(int rooms) {
    for (int i = 0; i < rooms; i++) {
        if (temperature[i] > 30) {
            printf("⚠️ WARNING: Room %d temperature is %.2f°C! Consider cooling the room.\n", i + 1, temperature[i]);
        }
    }
}

void energySavingMode(int rooms) {
    int allLightsOn = 1;
    for (int i = 0; i < rooms; i++) {
        if (!lights[i]) {
            allLightsOn = 0;
            break;
        }
    }

    if (allLightsOn) {
        printf("🔋 All lights have been ON for a long time. Would you like to turn them OFF? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            for (int i = 0; i < rooms; i++) {
                lights[i] = 0;
            }
            printf("All lights turned OFF to save energy!\n");
        }
    }
}

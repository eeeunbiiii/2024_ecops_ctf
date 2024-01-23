#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

int sv[7] = { 67, 84, 70, 50, 48, 50, 52 };

int checkDebugger() {
    return IsDebuggerPresent();
}

int h(int* f, size_t size) {
    int randomValue1, randomValue2;

    if (checkDebugger()) {
        printf("Exiting...\n");
        return 0;
    }

    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < size; ++i) {
        do {
            rand_s(&randomValue1);
            rand_s(&randomValue2);
        } while (randomValue1 == randomValue2);

        f[i] = f[i] ^ randomValue1 ^ randomValue2;
    }

    return 1;
}

void m() {
    char user_input[256];
    int a[7];
    memcpy(a, sv, sizeof(int) * 7);

    while (1) {
        printf("Enter the flag (Type 'exit' to quit)\n");
        scanf("%s", user_input);

        if (strcmp(user_input, "exit") == 0 || strcmp(user_input, "Exit") == 0) {
            break;
        }

        if (h(a, sizeof(a) / sizeof(a[0]))) {
            for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
                printf("%c ", (char)(a[i]));
            }
            printf("\n");
            break;
        }
        else {
            break;
        }
    }
}

int main() {
    m();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRIES 250
#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    char continent[MAX_NAME];
    int isIsland;
    int isTropical;
    int populationLevel; // 1-small, 2-medium, 3-large
    int isDesert;
    int isCold;
    int isRich;
    int hasHimalayas;
} Country;

Country list[MAX_COUNTRIES];
int total = 0;

// ========== BASIC UTILITIES ==========

int ask(const char *q) {
    int ans;
    printf("%s (1 = Yes, 0 = No): ", q);
    scanf("%d", &ans);
    return ans == 1 ? 1 : 0;
}

void loadCountries() {
    FILE *fp = fopen("countries.csv", "r");
    if (!fp) {
        printf("ERROR: Could not open countries.csv\n");
        exit(1);
    }

    while (!feof(fp)) {
        Country c;
        if (fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d\n",
                   c.name,
                   c.continent,
                   &c.isIsland,
                   &c.isTropical,
                   &c.populationLevel,
                   &c.isDesert,
                   &c.isCold,
                   &c.isRich,
                   &c.hasHimalayas) == 9) {
            list[total++] = c;
        }
    }

    fclose(fp);
}

void filterByContinent(const char *continent) {
    for (int i = 0; i < total; i++) {
        if (strcmp(list[i].continent, continent) != 0) {
            for (int j = i; j < total - 1; j++)
                list[j] = list[j + 1];
            total--;
            i--;
        }
    }
}

void filterByFlag(const char *attr, int value) {
    for (int i = 0; i < total; i++) {
        int match = 1;

        if (strcmp(attr, "isIsland") == 0 && list[i].isIsland != value) match = 0;
        else if (strcmp(attr, "isTropical") == 0 && list[i].isTropical != value) match = 0;
        else if (strcmp(attr, "populationLevel") == 0 && list[i].populationLevel != value) match = 0;
        else if (strcmp(attr, "isDesert") == 0 && list[i].isDesert != value) match = 0;
        else if (strcmp(attr, "isCold") == 0 && list[i].isCold != value) match = 0;
        else if (strcmp(attr, "isRich") == 0 && list[i].isRich != value) match = 0;
        else if (strcmp(attr, "hasHimalayas") == 0 && list[i].hasHimalayas != value) match = 0;

        if (!match) {
            for (int j = i; j < total - 1; j++)
                list[j] = list[j + 1];
            total--;
            i--;
        }
    }
}

// remove all countries where attr == value (used for populationLevel)
void filterNotFlag(const char *attr, int value) {
    for (int i = 0; i < total; i++) {
        int remove = 0;

        if (strcmp(attr, "populationLevel") == 0 && list[i].populationLevel == value)
            remove = 1;

        if (remove) {
            for (int j = i; j < total - 1; j++)
                list[j] = list[j + 1];
            total--;
            i--;
        }
    }
}

void printRemaining() {
    printf("\nRemaining possible countries (%d):\n", total);
    for (int i = 0; i < total; i++) {
        printf("- %s\n", list[i].name);
    }
}

// ========== GROUP HELPERS (BY NAME) ==========

int nameInList(const Country *c, const char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(c->name, arr[i]) == 0) return 1;
    }
    return 0;
}

// Middle East
int isMiddleEast(const Country *c) {
    const char *arr[] = {
        "Bahrain","Iraq","Israel","Jordan","Kuwait","Lebanon",
        "Oman","Qatar","Saudi Arabia","Syria","UAE","Yemen",
        "Iran"
    };
    return nameInList(c, arr, sizeof(arr)/sizeof(arr[0]));
}

// Gulf
int isGulf(const Country *c) {
    const char *arr[] = {
        "Bahrain","Kuwait","Oman","Qatar","Saudi Arabia","UAE"
    };
    return nameInList(c, arr, sizeof(arr)/sizeof(arr[0]));
}

// South Asia
int isSouthAsia(const Country *c) {
    const char *arr[] = {
        "India","Pakistan","Bangladesh","Sri Lanka",
        "Nepal","Bhutan","Maldives","Afghanistan"
    };
    return nameInList(c, arr, sizeof(arr)/sizeof(arr[0]));
}

// East Asia
int isEastAsia(const Country *c) {
    const char *arr[] = {
        "China","Japan","South Korea","North Korea","Mongolia"
    };
    return nameInList(c, arr, sizeof(arr)/sizeof(arr[0]));
}

// Southeast Asia
int isSouthEastAsia(const Country *c) {
    const char *arr[] = {
        "Indonesia","Malaysia","Singapore","Thailand","Vietnam",
        "Philippines","Myanmar","Cambodia","Laos","Brunei","Timor-Leste"
    };
    return nameInList(c, arr, sizeof(arr)/sizeof(arr[0]));
}

// Central Asia
int isCentralAsia(const Country *c) {
    const char *arr[] = {
        "Kazakhstan","Kyrgyzstan","Tajikistan","Turkmenistan","Uzbekistan"
    };
    return nameInList(c, arr, sizeof(arr)/sizeof(arr[0]));
}

void filterByGroup(int (*groupFunc)(const Country *), int keepIfTrue) {
    for (int i = 0; i < total; i++) {
        int inGroup = groupFunc(&list[i]);
        if (keepIfTrue) {
            if (!inGroup) {
                for (int j = i; j < total - 1; j++)
                    list[j] = list[j + 1];
                total--;
                i--;
            }
        } else {
            if (inGroup) {
                for (int j = i; j < total - 1; j++)
                    list[j] = list[j + 1];
                total--;
                i--;
            }
        }
    }
}

// ========== CONTINENT-SPECIFIC LOGIC ==========

void handleAsia() {
    if (ask("Is your country considered part of the Middle East region?")) {
        filterByGroup(isMiddleEast, 1);

        if (ask("Is it one of the Gulf countries on the Arabian Gulf (like Saudi Arabia, Qatar, UAE)?")) {
            filterByGroup(isGulf, 1);

            int rich = ask("Is it a very rich, high-income country?");
            if (rich) filterByFlag("isRich", 1);
            else filterByFlag("isRich", 0);

            int smallPop = ask("Is it a small country with relatively low population (under 10 million)?");
            if (smallPop) filterByFlag("populationLevel", 1);
            else {
                int veryLarge = ask("Is the population very large (over 100 million)?");
                if (veryLarge) filterByFlag("populationLevel", 3);
                else filterByFlag("populationLevel", 2);
            }

        } else {
            int desert = ask("Does this country have significant desert areas?");
            if (desert) filterByFlag("isDesert", 1);
            else filterByFlag("isDesert", 0);

            int largePop = ask("Is it a large population country (over around 50–100 million)?");
            if (largePop) filterByFlag("populationLevel", 3);
            else filterNotFlag("populationLevel", 3);
        }

    } else {
        if (ask("Is your country in South Asia (India, Pakistan, Bangladesh, Nepal, Sri Lanka, etc.)?")) {
            filterByGroup(isSouthAsia, 1);

            int him = ask("Does it contain part of the Himalayan mountain range?");
            if (him) filterByFlag("hasHimalayas", 1);
            else filterByFlag("hasHimalayas", 0);

            int large = ask("Is it a very large population country (over 100 million)?");
            if (large) {
                filterByFlag("populationLevel", 3);
            } else {
                filterNotFlag("populationLevel", 3);
            }

            int island = ask("Is it an island country?");
            if (island) filterByFlag("isIsland", 1);
            else filterByFlag("isIsland", 0);

        } else if (ask("Is your country in East Asia (China, Japan, Koreas, Mongolia)?")) {
            filterByGroup(isEastAsia, 1);

            int island = ask("Is it an island nation?");
            if (island) filterByFlag("isIsland", 1);
            else filterByFlag("isIsland", 0);

            int large = ask("Is the population extremely large (over 100 million)?");
            if (large) filterByFlag("populationLevel", 3);
            else filterNotFlag("populationLevel", 3);

        } else if (ask("Is your country in Southeast Asia (Thailand, Indonesia, Malaysia, Vietnam, etc.)?")) {
            filterByGroup(isSouthEastAsia, 1);

            int manyIslands = ask("Is it mainly made of many islands?");
            if (manyIslands) filterByFlag("isIsland", 1);
            else filterByFlag("isIsland", 0);

            int trop = ask("Is the climate mostly hot and humid (tropical)?");
            if (trop) filterByFlag("isTropical", 1);
            else filterByFlag("isTropical", 0);

        } else if (ask("Is your country in Central Asia (Kazakhstan, Uzbekistan, etc.)?")) {
            filterByGroup(isCentralAsia, 1);

            int desert = ask("Does it have large desert or semi-desert regions?");
            if (desert) filterByFlag("isDesert", 1);
            else filterByFlag("isDesert", 0);

        } else {
            int island = ask("Is it an island country?");
            if (island) filterByFlag("isIsland", 1);
            else filterByFlag("isIsland", 0);
        }
    }
}

void handleEurope() {
    int cold = ask("Is your country generally cold for much of the year (northern Europe / Nordic type climate)?");
    if (cold) filterByFlag("isCold", 1);
    else filterByFlag("isCold", 0);

    int rich = ask("Is it a very rich, high-income country?");
    if (rich) filterByFlag("isRich", 1);

    int island = ask("Is it an island country?");
    if (island) filterByFlag("isIsland", 1);
}

void handleAfrica() {
    int desert = ask("Is your country located mostly in the Sahara or other desert regions of North Africa?");
    if (desert) filterByFlag("isDesert", 1);
    else filterByFlag("isDesert", 0);

    int trop = ask("Is it mainly tropical (hot and humid, near the equator)?");
    if (trop) filterByFlag("isTropical", 1);

    int bigPop = ask("Is the population very large (over 100 million)?");
    if (bigPop) filterByFlag("populationLevel", 3);
    else filterNotFlag("populationLevel", 3);
}

void handleNorthAmerica() {
    int big = ask("Is it a very large and powerful country with a big population?");
    if (big) filterByFlag("populationLevel", 3);
    else filterNotFlag("populationLevel", 3);

    int island = ask("Is it an island or group of islands in the Caribbean region?");
    if (island) {
        filterByFlag("isIsland", 1);
        filterByFlag("isTropical", 1);
    }

    int cold = ask("Is it a cold country in the far north of the continent?");
    if (cold) filterByFlag("isCold", 1);
}

void handleSouthAmerica() {
    int large = ask("Is your country very large in area and population?");
    if (large) filterByFlag("populationLevel", 3);
    else filterNotFlag("populationLevel", 3);

    int trop = ask("Is it mostly tropical and near the Amazon or equator regions?");
    if (trop) filterByFlag("isTropical", 1);

    int cold = ask("Is it known for being further south with cooler climate in parts of the country?");
    if (cold) filterByFlag("isCold", 1);
}

void handleOceania() {
    int mainland = ask("Is it a large mainland country rather than small islands?");
    if (mainland) filterByFlag("isIsland", 0); // Australia
    else filterByFlag("isIsland", 1);          // island states

    int rich = ask("Is it generally considered a developed, high-income country?");
    if (rich) filterByFlag("isRich", 1);

    int smallPop = ask("Is the population quite small (under 10 million)?");
    if (smallPop) filterByFlag("populationLevel", 1);
}

// ========== EXTRA GENERIC QUESTIONS ==========
// These run AFTER continent + region logic to tighten results further

void runExtraQuestions() {
    if (total <= 1) return;

    int ans;

    ans = ask("Is your country an island nation?");
    filterByFlag("isIsland", ans);

    if (total <= 1) return;

    ans = ask("Is your country mostly tropical (hot and humid)?");
    filterByFlag("isTropical", ans);

    if (total <= 1) return;

    ans = ask("Does your country have large desert regions?");
    filterByFlag("isDesert", ans);

    if (total <= 1) return;

    ans = ask("Is your country generally cold for much of the year?");
    filterByFlag("isCold", ans);

    if (total <= 1) return;

    ans = ask("Is your country a very rich, high-income country?");
    filterByFlag("isRich", ans);

    if (total <= 1) return;

    ans = ask("Is your country's population very large (over 100 million)?");
    if (ans) filterByFlag("populationLevel", 3);
    else filterNotFlag("populationLevel", 3);

    if (total <= 1) return;

    ans = ask("Does your country include part of the Himalayan mountain range?");
    filterByFlag("hasHimalayas", ans);
}

// ========== FINAL DISAMBIGUATION ==========

void disambiguateIfFewLeft() {
    if (total == 1) {
        printf("\nI think your country is: %s\n", list[0].name);
        return;
    }

    if (total > 1 && total <= 4) {
        printf("\nI have a few possibilities left. Let's narrow it down:\n");
        for (int i = 0; i < total; i++) {
            int ans;
            printf("Is your country %s? (1 = Yes, 0 = No): ", list[i].name);
            scanf("%d", &ans);
            if (ans == 1) {
                printf("\nGreat! Your country is: %s\n", list[i].name);
                return;
            }
        }
        printf("\nI couldn't guess exactly. Maybe some earlier answers were inconsistent.\n");
    } else if (total > 4) {
        printf("\nI still have too many possibilities.\n");
        printRemaining();
        printf("\nYou can add more attributes or refine the CSV later.\n");
    } else {
        printf("\nNo matching country found. Maybe some answers don't match the data.\n");
    }
}

// ========== MAIN ==========

int main() {
    loadCountries();

    printf("\n=====================================\n");
    printf("         ADVANCED COUNTRY AKINATOR   \n");
    printf("=====================================\n\n");

    if (ask("Is your country in Asia?")) {
        filterByContinent("Asia");
        handleAsia();
    } else if (ask("Is your country in Europe?")) {
        filterByContinent("Europe");
        handleEurope();
    } else if (ask("Is your country in Africa?")) {
        filterByContinent("Africa");
        handleAfrica();
    } else if (ask("Is your country in North America?")) {
        filterByContinent("North America");
        handleNorthAmerica();
    } else if (ask("Is your country in South America?")) {
        filterByContinent("South America");
        handleSouthAmerica();
    } else {
        filterByContinent("Oceania");
        handleOceania();
    }

    // Ask extra generic questions to tighten down further
    runExtraQuestions();

    // Final disambiguation if 2–4 countries remain
    disambiguateIfFewLeft();

    return 0;
}

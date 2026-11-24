
#include <stdio.h>
#include <stdbool.h>

#define TAB_COUNT 5

typedef struct {
    const char *name;
    const char *description;
} MenuTab;

static MenuTab tabs[TAB_COUNT] = {
    {"Player", "Player information"},
    {"Vehicle", "Vehicle information"},
    {"World", "World information"},
    {"Settings", "Overlay settings"},
    {"About", "Project information"}
};

static int selectedTab = 0;
static bool overlayVisible = true;

void drawOverlay(void)
{
    if (!overlayVisible)
        return;

    printf("\n");
    printf("================================\n");
    printf("          RDR2 OVERLAY\n");
    printf("================================\n");

    for (int i = 0; i < TAB_COUNT; i++) {
        printf("%s %s\n",
            i == selectedTab ? ">>" : "  ",
            tabs[i].name);
    }

    printf("--------------------------------\n");
    printf("%s\n", tabs[selectedTab].description);
    printf("Version: 0.1\n");
    printf("================================\n");
}

void navigateMenu(int direction)
{
    selectedTab += direction;

    if (selectedTab < 0)
        selectedTab = TAB_COUNT - 1;

    if (selectedTab >= TAB_COUNT)
        selectedTab = 0;
}

int main(void)
{
    drawOverlay();
    return 0;
}

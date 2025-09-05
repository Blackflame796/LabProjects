#include <stdio.h>
#include <locale.h>

void house() {
    puts("     /\\        ");
    puts("    /  \\       ");
    puts("   /____\\      ");
    puts("   | __ |      ");
    puts("   ||  ||      ");
    puts("   ||__||      ");
    puts("   |____|      ");
}

void boat() {
    puts("        |\\        ");
    puts("       /| \\       ");
    puts("      /_|__\\      ");
    puts("        |          ");
    puts("       / \\         ");
    puts(" ~~~~~~~~~~~~~~~~~~ ");
    puts(" \\________________/ ");
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    house();
    puts("");
    boat();
    return 0;
}

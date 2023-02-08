#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <Windows.h>

unsigned int key1 = 49;
unsigned int key2 = 50;
FILE* fp;
// FILE* debug;

void keyPress(unsigned int keycode) {
    fseek(fp, 0, SEEK_SET);
    fwrite(&keycode, sizeof(int), 1, fp);
    // fprintf(debug, "%d\n", keycode);

    INPUT press;
    press.type = INPUT_KEYBOARD;
    press.ki.wVk = keycode;
    press.ki.wScan = MapVirtualKey(keycode, 0);
    press.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;

    INPUT release;
    release.type = INPUT_KEYBOARD;
    release.ki.wVk = keycode;
    release.ki.wScan = MapVirtualKey(keycode, 0);
    release.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;

    auto inputs = new INPUT[2];
    inputs[0] = press;
    inputs[1] = release;
    SendInput(2, inputs, sizeof(INPUT));


}

int WINAPI WinMain(HINSTANCE i, HINSTANCE p, LPSTR c, int s) {
    std::vector<std::wstring> keys;

    fopen_s(&fp, "state", "r+b");

    // fopen_s(&debug, "debug", "a+");

    if (fp == NULL) {
        fopen_s(&fp, "state", "w");
    }
    if (fp == NULL) {
        return 1;
    }

    fseek(fp, 0,SEEK_SET);
    unsigned int prevKey;
    int count = fread(&prevKey, sizeof(int), 1, fp);
    // fprintf(debug,"%d,%d\n", count, prevKey);

    // first write
    if (count == 0) {
        prevKey = key1;
    }

    if (prevKey == key1) {
        keyPress(key2);
    }
    else if (prevKey == key2) {
        keyPress(key1);
    }
    else {
        keyPress(key1);
    }

    fclose(fp);
    // fclose(debug);

    return 0;
}

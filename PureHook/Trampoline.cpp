#include "Trampoline.h"
#include <windows.h>
#include <cstring>

const size_t JUMP_SIZE = 14;

void* AllocateTrampoline(void* target, void* detour) {
    void* trampoline = VirtualAlloc(nullptr, JUMP_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!trampoline) return nullptr;

    std::memcpy(trampoline, target, JUMP_SIZE);
    WriteJump((char*)trampoline + JUMP_SIZE, target);

    return trampoline;
}

void WriteJump(void* target, void* detour) {
    unsigned char jump[14] = {
        0x49, 0xBB,
        0, 0, 0, 0, 0, 0, 0, 0,
        0x41, 0xFF, 0xE3
    };

    std::memcpy(jump + 2, &detour, 8);
    DWORD oldProtect;
    VirtualProtect(target, JUMP_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect);
    std::memcpy(target, jump, JUMP_SIZE);
    VirtualProtect(target, JUMP_SIZE, oldProtect, &oldProtect);
}

void RestoreOriginal(void* target, void* trampoline) {
    DWORD oldProtect;
    VirtualProtect(target, JUMP_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect);
    std::memcpy(target, trampoline, JUMP_SIZE);
    VirtualProtect(target, JUMP_SIZE, oldProtect, &oldProtect);
}

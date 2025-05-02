#include "MemoryUtils.h"
#include <windows.h>

void ProtectMemory(void* address, size_t size) {
    DWORD oldProtect;
    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}

void RestoreMemoryProtection(void* address, size_t size) {
    DWORD oldProtect;
    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}

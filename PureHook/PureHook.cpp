/*
 * PureHook - Function hooking implementation
 *
 * This file contains the core functionality for hooking and detouring functions.
 * It includes memory allocation, trampoline management, and hook management.
 *
 * The function CreateHook creates a hook, EnableHook enables it, and DisableHook
 * restores the original function.
 */

#include "PureHook.h"
#include "MemoryUtils.h"
#include "Trampoline.h"
#include <map>
#include <windows.h>
#include <cstring>

static std::map<void*, void*> g_hooks;

HookStatus CreateHook(void* target, void* detour, void** original) {
    if (g_hooks.find(target) != g_hooks.end()) {
        return HOOK_ERROR_ALREADY_CREATED;
    }

    void* trampoline = AllocateTrampoline(target, detour);
    if (!trampoline) return HOOK_ERROR_MEMORY;

    if (original) {
        *original = trampoline;
    }

    g_hooks[target] = detour;
    return HOOK_OK;
}

HookStatus EnableHook(void* target) {
    if (g_hooks.find(target) == g_hooks.end()) {
        return HOOK_ERROR_INVALID;
    }

    void* detour = g_hooks[target];
    if (detour) {
        WriteJump(target, detour);
    }

    return HOOK_OK;
}

HookStatus DisableHook(void* target) {
    if (g_hooks.find(target) == g_hooks.end()) {
        return HOOK_ERROR_INVALID;
    }

    void* original = g_hooks[target];
    if (original) {
        RestoreOriginal(target, original);
    }

    return HOOK_OK;
}

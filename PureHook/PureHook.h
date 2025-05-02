/*
 * PureHook - Minimal function hooking library for x64 Windows
 *
 * HOW TO USE:
 *
 *  1. Create a hook using CreateHook.
 *  2. Enable the hook with EnableHook.
 *  3. Optionally, disable it with DisableHook.
 *
 * Example:
 *    int (*origAdd)(int, int) = nullptr;
 *    int HookedAdd(int a, int b) {
 *        return a * b;
 *    }
 *    CreateHook((void*)&Add, (void*)&HookedAdd, (void**)&origAdd);
 *    EnableHook((void*)&Add);
 *    DisableHook((void*)&Add);
 */

#ifndef PUREHOOK_H
#define PUREHOOK_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef enum {
        HOOK_OK = 0,
        HOOK_ERROR_ALREADY_CREATED,
        HOOK_ERROR_MEMORY,
        HOOK_ERROR_INVALID
    } HookStatus;

    HookStatus CreateHook(void* target, void* detour, void** original);
    HookStatus EnableHook(void* target);
    HookStatus DisableHook(void* target);

#ifdef __cplusplus
}
#endif

#endif // PUREHOOK_H

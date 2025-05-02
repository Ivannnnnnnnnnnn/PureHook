/*
 * Trampoline - Manages trampoline functions for detouring
 *
 * A trampoline function allows us to redirect the flow of execution to the original function.
 * We create a trampoline by saving a portion of the original function and inserting a jump to the detour.
 */

#ifndef TRAMPOLINE_H
#define TRAMPOLINE_H

#ifdef __cplusplus
extern "C" {
#endif

	void* AllocateTrampoline(void* target, void* detour);
	void WriteJump(void* target, void* detour);
	void RestoreOriginal(void* target, void* trampoline);

#ifdef __cplusplus
}
#endif

#endif // TRAMPOLINE_H

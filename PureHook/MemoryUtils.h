#ifndef MEMORYUTILS_H
#define MEMORYUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

	void ProtectMemory(void* address, size_t size);
	void RestoreMemoryProtection(void* address, size_t size);

#ifdef __cplusplus
}
#endif

#endif // MEMORYUTILS_H

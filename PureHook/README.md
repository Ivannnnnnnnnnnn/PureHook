# PureHook

**PureHook** is a minimal, efficient, and powerful function hooking library for x64 Windows. It allows you to hook functions, redirect execution, and easily integrate detours into your applications.

## How to Use

### 1. Create a Hook
To create a hook, call `CreateHook`. You need to provide the target function, the detour function, and a pointer to store the original function.

```cpp
int (*origAdd)(int, int) = nullptr;

int HookedAdd(int a, int b) {
    return a * b;
}

CreateHook((void*)&Add, (void*)&HookedAdd, (void**)&origAdd);

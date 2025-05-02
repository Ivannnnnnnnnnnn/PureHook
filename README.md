# **PureHook**

PureHook is a lightweight, high-performance, and easy-to-use C/C++ library for function hooking and detouring. It is designed to provide seamless integration with any application, allowing you to intercept and replace function calls at runtime. Perfect for game modding, debugging, or creating advanced software tools.

## **Features**
- **Minimal Dependencies:** PureHook is written in pure C and C++ without external dependencies, making it easy to integrate into any project.
- **Supports x86/x64 Platforms:** PureHook is compatible with both 32-bit and 64-bit systems.
- **Easy to Use:** A simple and intuitive API to set up hooks with minimal configuration.
- **No Runtime Overhead:** Once hooks are applied, PureHook incurs minimal performance impact.
- **Trampolines:** Supports trampoline-based hooks for more reliable interception of function calls.
- **Hook Management:** Includes features to enable and disable hooks dynamically at runtime.

## **Requirements**
- Windows (x86, x64)
- A C++11 compliant compiler (e.g., MSVC, GCC)

## **Installation**
Clone this repository:
```bash
git clone https://github.com/yourusername/PureHook.git
cd PureHook
```
Compile the source code into a static or dynamic library. This can be done using CMake:
```
mkdir build
cd build
cmake ..
cmake --build .
```
## **API**
CreateHook(targetFunction, detourFunction, origFunctionPointer): Creates a hook for the specified function, where targetFunction is the function to hook, detourFunction is the new function to call, and origFunctionPointer stores the original function.

EnableHook(targetFunction): Enables the hook for the target function.

DisableHook(targetFunction): Disables the hook and restores the original function.

RemoveHook(targetFunction): Removes the hook completely.

## **License**
PureHook is licensed under the MIT License. See LICENSE for more details.

## **Contributions**
We welcome contributions! If you find a bug or want to improve the library, feel free to fork this project and submit a pull request.

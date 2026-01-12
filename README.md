# CppProgramWorkspace

This is a repository I use to store my C++ programs and source codes for syncing between my different PC.

## File Structure Requirements

- Need to add the path of your compiler to the system environment variable "Path" for files in ".vscode" to work properly.
- The workspace is designed to work with MinGW-w64 compiler.
- Make sure to have the necessary extensions installed in VSCode for C++ development, such as "C/C++" by Microsoft.
- To compile and run the programs correctly, fixed file structure is required as follows:
  |-- CppProgramWorkspace
    |-- .vscode
        |-- c_cpp_properties.json
        |-- tasks.json
        |-- launch.json
    |-- build
    |-- include
    |-- src

Add your C++ source files in the "src" folder and header files in the "include" folder.

All the compiled binaries will be generated in the "build" folder.

## Usage and Necessary Configurations

- Press 'F5' to compile and run with debugging.
- Press 'F6' to compile and run directly with external terminal.

To bind the keyboard shortcuts 'F6', you may need to add it into your `keybindings.json` in VSCode. Carry out the following steps:

1. Press Ctrl+K, Ctrl+S to open Keyboard Shortcuts.

2. Open keybindings.json **by clicking the icon on the top right corner**.

3. Add the following JSON snippet to the array.

    ```json
    {
    "key": "f6",
    "command": "workbench.action.tasks.runTask",
    "args": "Run External"
    },
    ```

4. Don't forget to save the changes.

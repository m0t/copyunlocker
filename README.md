# copyunlocker

This BOF is a port of the LockLess tool (https://github.com/GhostPack/Lockless) to copy a locked file by searching for the handle to the file in currently running processes and then creating a duplicate handle to copy the file.

## Usage

`copyunlocker <source file> [<dest file>]`

## Build

`make`

## Credits

- https://github.com/GhostPack/Lockless
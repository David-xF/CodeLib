# CodeLib
This is a Code Library for the Minecraft Wii U Edition, which can only be used with the [`Cemu Emulator`](https://github.com/cemu-project/Cemu).

# Discord
The Discord Server can be Accessed here https://david-xf.de/discord or https://discord.com/invite/xumaYBBhJv

# Building
You need to have [`devkitPro`](https://devkitpro.org/wiki/Getting_Started) and [`Python`](https://www.python.org/) Installed. After that You can build this with the Command `make all`.

After building, your Graphic Pack is finished and can be found at [`./GraphicPack`](https://github.com/David-xF/CodeLib/tree/main/GraphicPack). Insert this Folder into your `Cemu/graphicPacks` Folder and Start Cemu. After starting Cemu go to `Options -> Graphic packs`.
There you will find your Graphis Pack which you can then Enable or Disable. `Enable/Disable it Before Starting Minecraft!`

# Information
You can set your `ASM_PATH` in the [`Makefile`](https://github.com/David-xF/CodeLib/blob/main/Makefile) to the path of your .asm File so you don't always have to replace it manually.

If any Button Checks don't Work, you might have the Wrong Input Settings set, please check if your `Emulated Controller` is set to `Wii U Gamepad` as it is required.

If you want to Fix most Pointers which are used on Wii U for example: `0x109C61B0` do `-0x502200` and you will get `0x104C3FB0`. Which can be used with Cemu. The same is for Reverse, just do `+0x502200` and then it can be used with Wii U.

# Contributors
[`David xF`](https://github.com/David-xF), [`literallyuki`](https://github.com/literallyuki), [`Syoch`](https://github.com/Syoch), [`xenona (xenrelle)`](https://github.com/xenrelle), [`Miku666`](https://github.com/NessieHax), [`PhoenixARC`](https://github.com/PhoenixARC), [`Inupong`](https://discord.gg/k4dEAu2FrM)
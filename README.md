# Game

This is meant to be a template project to create a **video game** with **OpenGL ES** for Windows PC.

At the moment it only renders **some** of the demos of the [OpenGL® ES 2.0 Programming Guide](https://github.com/nickdesaulniers/opengles2-book/tree/master).

The releases are located on this [repo releases](https://github.com/hectorhalpizar/game/releases).


## How to run the release (v0.0.0.2 and above).

Do the following:

1. Download the latest release `.zip` from the [repo releases](https://github.com/hectorhalpizar/game/releases).

2. Extract the folder to a location and go to the `Game_vW.X.Y.Z_for_Win32` folder.

3. Run the program `Game.exe` from inside the `Game_vW.X.Y.Z_for_Win32` folder.

## How to run other demos

> **Disclaimer**: <u>This is work in progress</u>. This program generates a `debug.txt` file in this same folder. This file can fill your Storage disk. Do not left this program for a long period of time otherwise it will **generate a big `debug.txt` file**. You can delete the `debug.txt` file after closing the this application.

1. After extracting and go into the `Game_vW.X.Y.Z_for_Win32`, right click to open the Folder Context Menu and click `Open in Windows Terminal`.

2. Run the Command:

On Power shell:
```
.\Game.exe <DEMO ARGUMENT>
```

On CMD shell:
```
Game <DEMO ARGUMENT>
```

The available `<DEMO ARGUMENT>` are:

```
GameTriangle
GameSimpleVertexShader
GameTexturedTriangle
GameMipMap2D
GameSimpleTexturedCubemap
GameTextureWrap
GameMultiTexture
GameMultisample
GameStencilTest
```


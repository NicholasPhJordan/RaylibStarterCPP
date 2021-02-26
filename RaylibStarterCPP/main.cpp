/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

//ElfHash class example 
//unsigned int ElfHash(unsigned char* data)
//{
//    unsigned int hash = 0;
//    unsigned int x = 0;
//
//    for (unsigned char* i = data; *i != '\0'; ++i)
//    {
//        hash =(hash << 4) + *i;
//        if ((x = hash & 0xF0000000L) != 0)
//        {
//            hash ^= (x >> 24);
//            hash &= ~x;
//        }
//    }
//
//    return (hash & 0x7FFFFFFF);
//}

//me trying to create a good hashing 
unsigned int MyHash(unsigned char* data)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        //similar to the sdbm method
        hash = (hash << 4) + (hash << 14) - *i;
        //adds some funk to the end hash value
        hash += (hash << 10);
        hash ^= (hash >> 6);


        //kept the same if just in case
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    //wasn't quite sure what the "0x7FFFFFFF" was foor so i kept it for safe keeping
    return (hash & 0x7FFFFFFF); 
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    int checkSum = 0;
    unsigned char* input = new unsigned char[0];

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        std::cin >> input;
        checkSum = MyHash(input);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(checkSum));

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
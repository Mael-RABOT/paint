/*
** EPITECH PROJECT, 2023
** base_repo
** File description:
** MACROS
*/

#ifndef MACROS
    #define MACROS

    #include "enum.h"

    #define sf_DRS sfRenderWindow_drawRectangleShape

    #define MIN(x, y)               (((x) < (y)) ? (x) : (y))
    #define MAX(x, y)               (((x) > (y)) ? (x) : (y))
    #define ABS(x)                  (((x) > 0) ? (x) : (-x))

    #define IS_NORMAL(x)            (((x) == (0)) ? (1) : (0))
    #define IS_HOVER(x)             (((x) == (1)) ? (1) : (0))
    #define IS_PRESSED(x)           (((x) == (2)) ? (1) : (0))
    #define IS_RELEASED(x)          (((x) == (3)) ? (1) : (0))

    #define GET_INDEX(x, y, i, j)   (((x + i) + (y + j) * DRAWING_WIDTH) * 4)

    #define STD_WINDOW_WIDTH        1920
    #define STD_WINDOW_HEIGHT       1080
    #define STD_WINDOW_BPP          32
    #define TITLE                   "My Paint: Unsaved"

    #define TIPS_TITLE "Tips of the day"
    #define TIPS_WIDTH 400
    #define TIPS_HEIGHT 100
    #define TIPS_FILE "tips.txt"
    #define TIPS_NUMBER 5
    #define TIPS_TITLE              "Tips of the day"
    #define TIPS_WIDTH              400
    #define TIPS_HEIGHT             100
    #define FONT            "./assets/fonts/TT_Chocolates_Trial_Regular.otf"
    #define TIPS_FILE               "tips.txt"
    #define TIPS_NUMBER             5

    #define DRAWING_ZONE            0.9
    #define DRAWING_WIDTH           (STD_WINDOW_WIDTH * DRAWING_ZONE)
    #define DRAWING_HEIGHT          (STD_WINDOW_HEIGHT * DRAWING_ZONE)
    #define DRAWING_POS_X           (STD_WINDOW_WIDTH - DRAWING_WIDTH)
    #define DRAWING_POS_Y           (STD_WINDOW_HEIGHT - DRAWING_HEIGHT)
    #define DRAWING_OFFSET_X        (STD_WINDOW_WIDTH - DRAWING_POS_X)
    #define DRAWING_OFFSET_Y        (STD_WINDOW_HEIGHT - DRAWING_POS_Y)

    #define PREVIEW_X               100
    #define PREVIEW_Y               50

    #define sf_DRS                  sfRenderWindow_drawRectangleShape

    #define MENU_SIZE {80, 30 \
    }

    #define WELCOME_BUTTON          "./assets/welcome/welcome_button.png"
    #define WELCOME_BACKGROUND      "./assets/welcome/welcome_screen.png"

    #define BLACK                    "./assets/color/black.png"
    #define WHITE                   "./assets/color/white.png"
    #define RED                     "./assets/color/red.png"
    #define GREEN                   "./assets/color/green.png"
    #define BLUE                    "./assets/color/blue.png"
    #define YELLOW                  "./assets/color/yellow.png"
    #define MAGENTA                 "./assets/color/magenta.png"
    #define CYAN                    "./assets/color/cyan.png"

    #define COLOR_PICKER_WIDTH      350
    #define COLOR_PICKER_HEIGHT     350
    #define COLOR_PICKER_TITLE      "Color picker"
    #define COLOR_PICKER_BACKGROUND "assets/color_picker_bg.png"
    #define BUTTON_POS              {70, 75 \
    }

    #define CUSTOM_BACKGROUND       "assets/ui/custom.png"
    #define CUSTOM_TITLE            "Custom color"

    #define PENCIL_POS              {866, 37 \
    }
    #define PENCIL_TEXTURE          "assets/buttons/pencil.png"
    #define ERASER_POS              {1290, 37 \
    }
    #define ERASER_TEXTURE          "assets/buttons/eraser.png"

    #define SIZE_BUTTON_POS         {54, 231 \
    }
    #define SIZE_BUTTON_TEXTURE     "assets/buttons/size_button.png"

    #define SQUARE_TITLE            "Brush size"
    #define SQUARE_BG               "assets/ui/square_size.png"
    #define SQUARE_WINDOW           {350, 150 \
    }
    #define SQUARE_POS              {26, 76 \
    }
    #define RECTANGLE_BG            "assets/ui/rectangle_size.png"
    #define RECTANGLE_WINDOW        {350, 200 \
    }
    #define RECT_POS1               {26, 62 \
    }
    #define RECT_POS2               {26, 142 \
    }

    #define SLIDE_BAR_SIZE          {300, 30 \
    }
    #define SLIDER_SIZE             {20, 30 \
    }

    #define SLIDER_OFFSET           10
    #define SLIDER_SIZE_POS         {27, 252 \
    }

    #define SQUARE_S                "./assets/buttons/square.png"
    #define CIRCLE_S                "./assets/buttons/circle.png"
    #define RECTANGLE_S             "./assets/buttons/rectangle.png"

    #define SLIDER_FOREGROUND       "assets/slide_bar/slide_bar_foreground.png"
    #define SLIDER_BACKGROUND       "assets/slide_bar/slide_bar_background.png"
    #define SLIDER_HEAD             "assets/slide_bar/slider.png"

    #define STD_BRUSH_SIZE          4
    #define STD_TOOL                SQUARE
    #define STD_BRUSH_RECT_SIZE     {20, 10 \
    }

    #define MAX_BRUSH_SIZE          250
    #define STD_BRUSH_COLOR         sfBlack
    #define STD_BACK_COLOR          sfWhite

    #define STD_FILE_PATH           "image.jpg"
    #define HELP_FILE               "help.txt"
    #define FOREGROUND              "assets/ui/main_ui.png"
    #define SLIME                   "assets/sound/slime.ogg"

    #define FILE_PATH               "./assets/buttons/file.png"
    #define SAVE_PATH               "./assets/buttons/save.png"
    #define SAVE_AS_PATH            "./assets/buttons/save_as.png"
    #define LOAD_PATH               "./assets/buttons/load.png"

    #define EDITION_PATH            "./assets/buttons/edition.png"

    #define ABOUT_PATH              "./assets/buttons/about.png"

    #define ADD_PATH                "./assets/buttons/add.png"
    #define SUB_PATH                "./assets/buttons/sub.png"

#endif //MACROS

##-----------------------------LICENSE NOTICE------------------------------------
##  This file is part of CPCtelera: An Amstrad CPC Game Engine 
##  Copyright (C) 2018 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
##
##  This program is free software: you can redistribute it and/or modify
##  it under the terms of the GNU Lesser General Public License as published by
##  the Free Software Foundation, either version 3 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU Lesser General Public License for more details.
##
##  You should have received a copy of the GNU Lesser General Public License
##  along with this program.  If not, see <http://www.gnu.org/licenses/>.
##------------------------------------------------------------------------------
############################################################################
##                        CPCTELERA ENGINE                                ##
##                 Automatic image conversion file                        ##
##------------------------------------------------------------------------##
## This file is intended for users to automate image conversion from JPG, ##
## PNG, GIF, etc. into C-arrays.                                          ##
############################################################################

##
## NEW MACROS
##

## 16 colours palette
## PALETTE=0 1 2 3 6 9 11 12 13 15 16 18 20 24 25 26
## PALETTE=0 26 25 11
PALETTE=0 1 11 23
## Default values
#$(eval $(call IMG2SP, SET_MODE        , 0                  ))  { 0, 1, 2 }
#$(eval $(call IMG2SP, SET_MASK        , none               ))  { interlaced, none }
#$(eval $(call IMG2SP, SET_FOLDER      , src/               ))
#$(eval $(call IMG2SP, SET_EXTRAPAR    ,                    ))
#$(eval $(call IMG2SP, SET_IMG_FORMAT  , sprites            ))	{ sprites, zgtiles, screen }
#$(eval $(call IMG2SP, SET_OUTPUT      , c                  ))  { bin, c }
#$(eval $(call IMG2SP, SET_PALETTE_FW  , $(PALETTE)         ))
#$(eval $(call IMG2SP, CONVERT_PALETTE , $(PALETTE), g_palette ))
#$(eval $(call IMG2SP, CONVERT         , img.png , w, h, array, palette, tileset))

$(eval $(call IMG2SP,SET_MODE,1))
$(eval $(call IMG2SP,SET_MASK,none))
$(eval $(call IMG2SP,SET_FOLDER,src/assets))
$(eval $(call IMG2SP,SET_EXTRAPAR,))
$(eval $(call IMG2SP,SET_IMG_FORMAT,sprites))
$(eval $(call IMG2SP,SET_OUTPUT,c))
$(eval $(call IMG2SP,SET_PALETTE_FW,$(PALETTE)))
$(eval $(call IMG2SP,CONVERT_PALETTE,$(PALETTE),g_palette))

## room objects
$(eval $(call IMG2SP,CONVERT,assets/lightbulb.png,24,24,g_sprite_lightbulb,,))
$(eval $(call IMG2SP,CONVERT,assets/obj_consola.png,24,24,g_sprite_obj_consola,,))
$(eval $(call IMG2SP,CONVERT,assets/obj_deportivas.png,24,24,g_sprite_obj_deportivas,,))
$(eval $(call IMG2SP,CONVERT,assets/obj_paddel.png,24,24,g_sprite_obj_paddel,,))

## pong sprites
$(eval $(call IMG2SP,CONVERT,assets/pong_odyse.png,16,24,g_sprite_pong_odyse,,))
$(eval $(call IMG2SP,CONVERT,assets/pong_title.png,80,24,g_sprite_pong_title,,))
$(eval $(call IMG2SP,CONVERT,assets/pong_ball.png,4,4,g_sprite_pong_ball,,))
$(eval $(call IMG2SP,CONVERT,assets/pong_paddel.png,4,16,g_sprite_pong_paddel,,))

## breakout sprites
$(eval $(call IMG2SP,CONVERT,assets/breakout_paddel.png,24,6,g_sprite_breakout_paddel,,))
$(eval $(call IMG2SP,CONVERT,assets/breakout_ball.png,4,4,g_sprite_breakout_ball,,g_sprite_breakout_ball_anim))
$(eval $(call IMG2SP,CONVERT,assets/breakout_medium_brick.png,16,8,g_sprite_breakout_medium_brick,,))
$(eval $(call IMG2SP,CONVERT,assets/breakout_bg.png,16,16,g_sprite_breakout_bg,,))

##
## OLD MACROS (For compatibility)
##

## Example firmware palette definition as variable in cpct_img2tileset format

# PALETTE={0 1 3 4 7 9 10 12 13 16 19 20 21 24 25 26}

## AUTOMATED IMAGE CONVERSION EXAMPLE (Uncomment EVAL line to use)
##
##    This example would convert img/example.png into src/example.{c|h} files.
##    A C-array called pre_example[24*12*2] would be generated with the definition
##    of the image example.png in mode 0 screen pixel format, with interlaced mask.
##    The palette used for conversion is given through the PALETTE variable and
##    a pre_palette[16] array will be generated with the 16 palette colours as 
##	  hardware colour values.

#$(eval $(call IMG2SPRITES,img/example.png,0,pre,24,12,$(PALETTE),mask,src/,hwpalette))



############################################################################
##              DETAILED INSTRUCTIONS AND PARAMETERS                      ##
##------------------------------------------------------------------------##
##                                                                        ##
## Macro used for conversion is IMG2SPRITES, which has up to 9 parameters:##
##  (1): Image file to be converted into C sprite (PNG, JPG, GIF, etc)    ##
##  (2): Graphics mode (0,1,2) for the generated C sprite                 ##
##  (3): Prefix to add to all C-identifiers generated                     ##
##  (4): Width in pixels of each sprite/tile/etc that will be generated   ##
##  (5): Height in pixels of each sprite/tile/etc that will be generated  ##
##  (6): Firmware palette used to convert the image file into C values    ##
##  (7): (mask / tileset / zgtiles)                                       ##
##     - "mask":    generate interlaced mask for all sprites converted    ##
##     - "tileset": generate a tileset array with pointers to all sprites ##
##     - "zgtiles": generate tiles/sprites in Zig-Zag pixel order and     ##
##                  Gray Code row order                                   ##
##  (8): Output subfolder for generated .C/.H files (in project folder)   ##
##  (9): (hwpalette)                                                      ##
##     - "hwpalette": output palette array with hardware colour values    ##
## (10): Aditional options (you can use this to pass aditional modifiers  ##
##       to cpct_img2tileset)                                             ##
##                                                                        ##
## Macro is used in this way (one line for each image to be converted):   ##
##  $(eval $(call IMG2SPRITES,(1),(2),(3),(4),(5),(6),(7),(8),(9), (10))) ##
##                                                                        ##
## Important:                                                             ##
##  * Do NOT separate macro parameters with spaces, blanks or other chars.##
##    ANY character you put into a macro parameter will be passed to the  ##
##    macro. Therefore ...,src/sprites,... will represent "src/sprites"   ##
##    folder, whereas ...,  src/sprites,... means "  src/sprites" folder. ##
##                                                                        ##
##  * You can omit parameters but leaving them empty. Therefore, if you   ##
##  wanted to specify an output folder but do not want your sprites to    ##
##  have mask and/or tileset, you may omit parameter (7) leaving it empty ##
##     $(eval $(call IMG2SPRITES,imgs/1.png,0,g,4,8,$(PAL),,src/))        ##
############################################################################

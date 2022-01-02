RESET 7282
==========

Aventura conversacional

## Dependencies
- cpctelera (https://github.com/lronaldo/cpctelera)

## Scripts
- make => builds project
- make clean => clean all obj files (needed any header file .h has been modified)
- cpct_rvm -a => launch last .dsk build with Retro Virtual Machine
- cpct_winape => launch last .dsk build with WinApe

## Game technical docs

Main objects:
```js
    [
        {
            id: 'raqueta',
            info: 'necesario para poder jugar a pong'
        },
        {
            id: 'consola',
            info: 'Magnabox Odyssey, necesaria para jugar al Pong'
        }
        {
            id: 'rana',
            info: 'rana saltadora geyper'
        }
    ]
```

Mapa
----
<pre>
    N
    |
O -   - E
    |
    S

       inventario
                             breakout -- espejo -- aseo_2
                                                    |
                                                    |
       frogger                       aseo_1        dormitorio_3
        |                             |             |
        |                             |             |
       mirilla -- entrada - salon -- pasillo_1 --- pasillo_2
                   |         |        |             |
                   |         |        |             |
         horno -- cocina    terraza  dormitorio_1  dormitorio_2
          |        |         |        |
          |        |         |        |
         pacman   almacen   cielo    consola
                   |         |
                   |         |
                  invaders  pong
</pre>
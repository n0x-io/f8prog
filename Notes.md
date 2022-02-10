# Notes regarding firmware analyzing

# Memory informatio
Most of these values have been determined from changing the firmware and looking at it with a hex-editor. All values still need to be tested and confirmed.

## Key Offsets

- 0x00005189 -> Key 1
- 0x00005181 -> Key 2
- 0x00005179 -> Key 3
- 0x00005149 -> Key 4
- 0x00005190 -> Key 5
- 0x00005182 -> Key 6
- 0x0000517A -> Key 7
- 0x0000514A -> Key 8

## Program "Key"-Codes

Set a key to this value to activate the corresponding program.

- 0xD7 Prog1
- 0xD8 Prog2
- 0xD9 Prog3
- 0xDA Prog4
- 0xDB Prog5
- 0xDC Prog6
- 0xDD Prog7
- 0xDE Prog8

## Program Offsets

- 0x0000539C -> Prog1
- 0x000056BC -> Prog2
- 0x000059DC -> Prog3
- 0x00005CFC -> Prog4
- 0x0000601C -> Prog5
- 0x0000633C -> Prog6
- 0x0000665C -> Prog7
- 0x0000697C -> Prog8

# Sources and help:
https://blog.mateusz.perlak.com/index.php/2016/12/05/max-falcon-8-keyboard-hacking/
https://github.com/benblazak/ergodox-firmware/blob/master/src/lib/usb/usage-page/keyboard.h



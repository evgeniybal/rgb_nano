# rgb_nano

IR-remote-controlled RGB LED for **Arduino Nano** (ATmega328), built with PlatformIO.

Switch between animated color effects and 12 solid colors from a standard NEC IR remote. Effects respond to button presses instantly: every delay in the animation polls the remote, so you never wait for an effect to finish.

## Features

- **Rainbow** (default): smooth loop violet → blue → cyan → green → yellow → red → pink → violet
- **Flow**: fades in red, then green, then blue
- **Solid colors**: 12 presets (red, orange, yellows, lime, green, cyan, blues, purple, violet)
- **Off**
- Instant response: effects abort as soon as a new command arrives

## Hardware

| Part | Arduino Nano pin |
|---|---|
| RGB LED — red | D9 (PWM) |
| RGB LED — green | D10 (PWM) |
| RGB LED — blue | D6 (PWM) |
| IR receiver (e.g. VS1838B / TSOP38238) signal `S` | D2 |

Use a current-limiting resistor on each LED channel. The code assumes `255 = full brightness` on each channel (common-cathode LED or a driver that is active-high).

> **Why not pins D3 and D11?** Their PWM runs on Timer2, which the IRremote library uses.

## Remote buttons

Codes are the NEC `command` field. Edit them in [`include/ir_codes.h`](include/ir_codes.h).

| Button | Code | Action |
|---|---|---|
| ON | `0x12` | Rainbow effect |
| OFF | `0x1A` | Turn off |
| M/C | `0x03` | Toggle Rainbow ↔ Flow |
| Color buttons | `0x04`–`0x0A`, `0x0C`–`0x0E`, `0x1B`, `0x1F` | Solid color (see `COLOR_BUTTONS` in [`src/remote.cpp`](src/remote.cpp)) |

`LIGHTNESS`, `4H` and `8H` codes are defined but not handled yet.

### Using a different remote

1. Uncomment `Serial.begin(9600);` in [`src/main.cpp`](src/main.cpp) and the debug print in `checkRemote()` in [`src/remote.cpp`](src/remote.cpp).
2. Upload, open the serial monitor (9600 baud) and press buttons. Each press prints `IR command: 0x..`.
3. Put the codes into [`include/ir_codes.h`](include/ir_codes.h).

## Build & upload

Requires [PlatformIO](https://platformio.org/) (VS Code extension or CLI).

Set `upload_port` / `monitor_port` in [`platformio.ini`](platformio.ini) to your board's serial port (currently `COM4`), then:

```sh
pio run -t upload      # build and flash
pio device monitor     # serial monitor (if debug output enabled)
```

Dependency: [`z3t0/IRremote`](https://github.com/Arduino-IRremote/Arduino-IRremote) `^4.4.1`, installed automatically by PlatformIO.

## Project structure

```
include/
  pins.h       LED and IR receiver pins
  ir_codes.h   remote button codes
  colors.h     Color struct and color presets
  state.h      current mode + color (single global State)
  flows.h      setColor(), flow(), flow2()
  remote.h     IR receiver setup and button handling
  timing.h     wait(): delay that aborts on a remote command
src/
  main.cpp     setup() and the mode dispatcher in loop()
  flows.cpp    effects
  remote.cpp   button → mode/color mapping
  state.cpp    State instance
  timing.cpp   wait() implementation
```

## How it works

`loop()` runs the effect for the current `state.mode`. Effects use `wait(ms)` instead of `delay()`: it busy-waits while polling the IR receiver. When a button changes the state, `wait()` returns `true`, the effect returns immediately, and the next `loop()` starts the new mode.

## License

[MIT](LICENSE)

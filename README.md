# ESP32 for Mere Mortals

A computer the size of a postage stamp
can run your program, watch a sensor,
join your Wi-Fi and report what it
found — and it costs less than the
cable that programs it. The **ESP32**
is that computer: a **microcontroller**
with the radios built in, made by
Espressif, and sold in a family of
chips and boards bewildering enough
that the first honest question is
*which one is this, actually?*

This guide answers that first. It
compares the family without sales
talk, separates chip from module from
board, and lays out the three ways a
program gets written. Then it does the
work: a real toolchain installed from
the command line, three real sketches
compiled and their build reports read
properly, the pins mapped with their
traps labelled, Wi-Fi and Bluetooth
explained as the two different tools
they are, battery life done as
arithmetic instead of hope, displays
and libraries judged like purchases,
and updates delivered over the air.
The limits are stated plainly, and so
are the safety rules, starting with
the one on this page: **the ESP32 is a
3.3 volt chip, its pins are not
5 volt tolerant, and a lithium polymer
battery is stored energy, not a coin
cell.** Chapter 1 gives the rules in
full, before anything depends on them.

The lab behind this guide ran the real
toolchain: **arduino-cli 1.5.2-rc.1**
and Espressif's **ESP32 core 3.3.12**,
installed on a small Linux machine,
and three sketches written for a
fictional workshop sensor node — a
blink, a Wi-Fi scan, and a sensor
reading formatted as JSON with the
ArduinoJson library. All three were
compiled for a generic ESP32 target,
and the build reports are quoted in
chapter 6 from the transcripts, not
from memory: 271,704 bytes for the
blink, 877,284 for the sketch that
asks for Wi-Fi, 276,812 for the one
that formats JSON.

What the lab could not do, it did not
fake. There was no board on its bench:
flashing a chip, watching an LED,
joining a real network, reading a real
sensor, measuring a sleeping current —
everything that needs the physical
board is taught from the documentation
and labelled as such wherever it
appears, and the guide repeats the
distinction until it becomes a habit
of the reader's own: *compiled* is
proven here; *running* is proven only
by the board. `criteria.md` keeps the
full ledger of what was run and what
was only read.

## What this guide covers

- [**What the ESP32 is**](what-esp32-is.md) —
  the mental model: one program on the
  metal, radios built in, and the
  safety rules before everything
- [**The family, honestly compared**](the-family.md) —
  original, S2, S3, C3, C6 and H2:
  cores, radios, and who each is for
- [**Modules, dev boards and all-in-one boards**](boards-and-modules.md) —
  the chip dressed three ways, and
  how to buy the first one
- [**Three ways in**](three-ways-in.md) —
  the Arduino core, ESP-IDF and
  MicroPython, and choosing without
  mysticism
- [**Setting up the toolchain**](setting-up-the-toolchain.md) —
  arduino-cli, the ESP32 core, board
  names, and the serial port appearing
- [**Your first compile**](your-first-compile.md) —
  building blink, reading the two
  numbers, and what a compile cannot
  promise
- [**Pins and GPIO, honestly**](pins-and-gpio.md) —
  strapping pins, input-only pins, the
  ADC's real character, and 3.3 volts
- [**Wi-Fi — client and access point**](wifi.md) —
  joining a network, being one, and
  the three shapes of a connected
  project
- [**Bluetooth and BLE**](bluetooth-and-ble.md) —
  the two Bluetooths, which chips
  carry which, and what BLE is for
- [**Deep sleep and power budgets**](deep-sleep-and-power.md) —
  the arithmetic that decides whether
  a battery project lives for days or
  seasons
- [**Displays and libraries**](displays-and-libraries.md) —
  judging a library, and matching
  screen, driver, bus and code
- [**Over-the-air updates**](over-the-air-updates.md) —
  two homes for firmware, the
  bootloader's mercy, and the security
  door an update channel is
- [**The neighbours**](the-neighbours.md) —
  the ESP8266, Pico W, a full
  Raspberry Pi, ESPHome, and the
  classic Arduino boards
- [**Limits**](limits.md) — 2.4 GHz
  forever, no Linux, modest currents,
  and a chip anyone can reflash
- [**Troubleshooting**](troubleshooting.md) —
  the charge-only cable, the brownout,
  the strapping pin, and the bare-board
  test
- [**Glossary**](glossary.md) — the
  terms, collected in one place

## What it doesn't cover

Designing circuits from nothing —
this guide connects ready-made boards,
sensors and modules, and while it
names the handful of parts that keep
them safe together (level shifters,
dividers, a transistor for real loads),
it is not an electronics course.
Soldering, PCB design, and the
certification a product needs before
it may be sold are likewise other
books. The deep end of ESP-IDF —
custom partition schemes, secure boot
signing ceremonies, factory
provisioning — is pointed at, not
taught; chapter 4 says when a project
has earned it. And nothing here is a
life-safety design: a chip this open
does not guard doors, heaters or
people, and chapter 14 says why in
full.

## How to use this guide

Read chapter 1 for the model and the
safety rules, chapter 2 before buying
anything, and chapter 7 before wiring
anything — those three prevent the
expensive mistakes. Chapters 5 and 6
are a pair: install, then compile the
same sitting, and read the size report
aloud once, because it recurs in every
later chapter. If you arrive owning a
display board, chapter 3 and chapter
11 are your shortcut, but run the
maker's demo before your own code, so
*the screen works* is a fact. The
lab's sketches live in
`esp32-lab/sketches/`; its build
transcripts are `esp32-lab/transcripts/`;
its notes are `examples/lab-notes.txt`.

---

## Part of the series

This guide is one of the [For Mere Mortals](https://paulsullivan33-dev.github.io/mere-mortals/) guides: plain-language guides to the tools programmers and makers use.

Related guides:

- [Arduino for Mere Mortals](https://paulsullivan33-dev.github.io/arduino-for-mere-mortals/)
- [MicroPython for Mere Mortals](https://paulsullivan33-dev.github.io/micropython-for-mere-mortals/)
- [PlatformIO for Mere Mortals](https://paulsullivan33-dev.github.io/platformio-for-mere-mortals/)

## License

The writing in this guide is licensed under [CC BY 4.0](https://github.com/paulsullivan33-dev/esp32-for-mere-mortals/blob/main/LICENSE). Code examples and lab scripts are licensed under the [MIT License](https://github.com/paulsullivan33-dev/esp32-for-mere-mortals/blob/main/LICENSE-CODE).

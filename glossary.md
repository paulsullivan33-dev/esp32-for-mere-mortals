# Glossary

The terms, collected in one place.
Each is defined where it first
appears in the guide as well; this is
the quick way back to one.

**Access point (AP)** — a device that
announces a Wi-Fi network others join.
An ESP32 can be one (chapter 8) as
well as join one.

**ADC (analogue-to-digital
converter)** — the part that turns a
voltage on a pin into a number
(chapter 7). It has a mirror twin, the
**DAC**, which turns a number into a
voltage.

**Antenna** — the part that actually
radiates and hears the radio: a copper
trace on the module, or a socket for
an external one (chapter 3).

**Beacon** — a BLE device that only
advertises its presence and a little
data, and never connects (chapter 9).

**BLE (Bluetooth Low Energy)** — the
younger of the two Bluetooths,
designed for small messages and long
battery life (chapter 9).

**Bootloader** — the small program
that runs first at reset and chooses
which firmware to start; the quiet
referee of over-the-air updates
(chapter 12).

**Breadboard** — the solderless grid
of holes that dev boards plug into for
experiments (chapter 3).

**Brownout** — a protective reset when
the supply voltage sags below what
the chip can run on; the radio's
transmit peaks are its usual cause
(chapter 15).

**Central / peripheral** — BLE's two
roles: the central (usually a phone)
connects and reads; the peripheral
(the sensor) is read (chapter 9).

**Characteristic** — one named, typed
value inside a BLE service — the
compartment in the drawer (chapter 9).

**Compile** — translating your sketch,
on your computer, into the machine
code the chip runs (chapter 6).

**Core** — in two senses: a processor
unit inside the chip (the original is
dual-core), and the software layer
(the Arduino core) your sketch builds
against. Context tells them apart
(chapters 2 and 4).

**Deep sleep** — the state where the
chip is nearly all off, drawing
microamps, woken by a timer or a pin —
and waking through a full reset
(chapter 10).

**eFuse** — a one-time programmable
bit inside the chip; burning one is
forever, which is why the security
features that use them are deliberate
(chapter 14).

**Firmware** — software that lives in
a device's flash and runs the device;
what a compiled sketch becomes
(chapter 1).

**Flash** — the chip's non-volatile
storage: memory that survives power
loss, sized in megabytes on the module
(chapter 3).

**FQBN** — "fully qualified board
name": the string, like
`esp32:esp32:esp32`, that tells the
Arduino tools exactly which board and
variant a build is for (chapters 5 and
6).

**FreeRTOS** — the small real-time
operating system that runs underneath
ESP32 programs, visible or not
(chapter 4).

**GPIO** — general-purpose input and
output: the pins your program reads
and drives (chapter 7).

**I2C / SPI** — the two standard
wiring patterns, or buses, by which
the chip talks to sensors and displays
over shared lines (chapter 7).

**JSON** — a plain-text format for
structured data, all braces and
labels; the shape of the lab's sensor
reading (chapter 11).

**Level shifter** — a small part that
translates signals between 3.3 V and
5 V logic safely (chapter 7).

**LiPo** — lithium polymer: the
flat rechargeable battery chemistry
of chapter 10. High energy, real
handling rules, not a coin cell.

**Logic level** — the voltage a
digital signal calls "on": 3.3 V on
this chip, 5 V on older boards, and
never the twain without translation
(chapter 7).

**Matter / Thread** — a smart-home
application standard (Matter) and the
mesh radio protocol it often rides on
(Thread); the C6 and H2 carry the
radios (chapter 2).

**Microcontroller** — a small
self-contained computer that runs one
program on the metal: the ESP32's
species (chapter 1).

**Module** — the chip plus flash and
antenna in a shielded can, ready to be
soldered into boards (chapter 3).

**MQTT** — a light publish-and-
subscribe messaging protocol, a sensor
network's usual postman (chapter 8).

**Partition table** — the map that
divides the flash into bootloader,
settings, and one or two firmware
homes (chapter 12).

**PSRAM** — an extra pool of slower
RAM some modules carry for big jobs
like camera frames (chapters 3 and 6).

**PWM** — pulse-width modulation:
switching a pin fast to fake a level
in between — dimming, servo steering
(chapter 7).

**RISC-V** — an open processor
architecture; the newer family members
are built on it (chapter 2).

**RTC** — the real-time clock domain:
a small slow corner of the chip that
stays alive in sleep and keeps the
wake-up timer (chapter 10).

**Service** — in BLE, a labelled group
of characteristics: "battery",
"heart rate" (chapter 9).

**Sketch** — an Arduino-style program:
a `setup()`, a `loop()`, and the
libraries it uses (chapter 4).

**SoC (system on a chip)** — a chip
carrying processor, memory and radios
together; the ESP32's full description
(chapter 1).

**SSID** — the name a Wi-Fi network
announces and clients join by
(chapter 8).

**Station (STA)** — Wi-Fi's word for a
client: a device in the mode of
joining a network rather than hosting
one (chapter 8).

**Strapping pin** — a pin the chip
itself reads at reset to decide how to
boot; borrowed at your peril
(chapter 7).

**TLS** — the encryption that protects
a connection end to end, certificates
and all; the S in HTTPS (chapter 8).

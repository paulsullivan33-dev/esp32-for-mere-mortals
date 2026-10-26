# Pins and GPIO, Honestly

Outcome: you can pick pins for a
project without stepping on the ones
with second jobs, feed the chip
nothing over 3.3 volts, and know what
its analogue inputs are really worth.

**GPIO** — general-purpose input and
output — is the collective name for the
chip's pins that your program can read
and drive. On a dev board they are the
two rows of pins labelled with numbers:
GPIO 2, GPIO 4, GPIO 16 and so on.
Through them the chip touches the
world: a pin can light an LED, read a
button, talk to a sensor over a shared
**bus** (the wiring pattern called
**I2C** or **SPI**, where several
devices share lines), or sing the
little pulses called **PWM** that dim
lights and steer servos. This chapter
is the honest map, because the ESP32's
pins are famously not all equal.

## The 3.3 volt rule, at pin level

Everything in this chapter sits on
chapter 1's safety rule. Every GPIO is
a 3.3 V pin: it outputs at most 3.3 V,
expects at most 3.3 V in, and is **not
5 V tolerant** — no pin, ever. A 5 V
sensor whose output pin is wired
straight to a GPIO may work for a day
and quietly cook the input. The cheap
fixes are standard: a **level shifter**
(a small board made for exactly this
translation) for bus signals, or a
pair of resistors as a **voltage
divider** for a single one-way signal.
Budget one whenever old 5 V hardware
meets this chip. Current matters too:
a pin is meant to carry signals, tens
of milliamps at most — enough for an
LED with its resistor, never for a
motor, a relay coil or a string of
lights, which get their own supply and
a transistor to switch it (chapter 14
repeats this, because it keeps needing
repeating).

## Pins with second jobs

Some pins are consulted by the chip
itself in the first milliseconds after
reset, to decide *how* to boot. These
are the **strapping pins**, and they
are the classic ESP32 trap. On the
original chip:

- **GPIO 0** must be high for a normal
  boot and low to enter the download
  mode used when uploading a sketch
  (chapter 15) — which is why
  boards put the BOOT button on it, and
  why hanging a peripheral that drags
  it low makes a board that "won't
  start".
- **GPIO 2** is watched at boot too,
  and happens to carry the dev board's
  built-in LED — convenient, and the
  reason the lab's blink sketch uses
  it, but a peripheral attached here
  must leave it free to be low at
  reset.
- **GPIO 12** decides a flash voltage
  setting on many modules; driving it
  high at reset can stop a board
  booting at all. Treat it as guilty
  until your board's pinout proves it
  innocent.
- **GPIO 15** steers the boot log's
  chatter. Harmless in most projects,
  surprising in all of them.

Then there are the reserved and the
limited. On the original chip, **GPIO
6 to 11** are wired inside the module
to its own flash memory: they exist on
the silicon and must never be used.
**GPIO 34, 35, 36 and 39** are
**input-only** — they have no output
circuit at all, which makes them fine
for buttons and sensors and a silent
failure for an LED that never lights
because `digitalWrite()` had nothing
to write with. The S3 and C3 have
their own lists, smaller and better
behaved, and the rule that survives
every variant is the same: **the board
maker's pinout diagram is part of the
hardware**. Download it before the
project, not during the debugging.

## Analogue in, honestly

Two **ADC** units (analogue-to-digital
converters) turn voltages into numbers,
and they are genuinely useful — a
light sensor, a soil probe, a battery
divider. They are also the chip's most
oversold feature. The honest notes:
the reading is **not perfectly
linear**, drifting at both ends of its
range, so treat the last stretch near
0 V and 3.3 V as approximate; nearby
Wi-Fi activity disturbs **ADC2** so
much that the Arduino core refuses to
use it while the radio is on — plan
analogue sensors on ADC1 pins (GPIO
32 to 39 on the original); and the
numbers are noisy enough that every
serious project averages several
readings. Calibrated, averaged, and
used for "is it dry yet" questions,
the ADC is a friend. Sold to yourself
as a precision voltmeter, it will
disappoint.

## Touch, pulses, and the nice extras

The original and S-series chips carry
**touch sensing** on some pins — the
pin itself is the sensor, reading a
finger's presence through a plastic
case, no button required. The chip can
also generate tidy **PWM** on almost
any output pin (the Arduino core's
`ledcWrite()` calls run it), produce a
true analogue voltage from a pair of
**DAC** pins on the original chip
(25 and 26 — the newer chips dropped
them), and keep a small **RTC** clock
domain alive in sleep that chapter 10
puts to work. None of this needs
believing in advance: the pinout
diagram names which pins carry which
gift on your board.

Check: pick the pins for a button, an
LED, and a soil sensor for a fictional
workshop node from your board's
pinout, and say out loud why each
chosen pin is safe at boot. That
exercise, done once on paper, prevents
the single most common ESP32 debugging
weekend.

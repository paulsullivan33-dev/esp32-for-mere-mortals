# The Neighbours

Outcome: for any small connected
project, you can say why the ESP32 —
or why one of its neighbours instead.

No chip is the answer to every
question, and this family has honest
neighbours in every direction. The
comparisons below are character, not
benchmarks.

## ESP8266: the older brother

The **ESP8266** is Espressif's
previous Wi-Fi chip, the one that
proved a few dollars could buy a radio.
Single core, slower, fewer pins, no
Bluetooth — and still sold, still
supported by the same Arduino core,
still entirely sufficient for the
single-sensor jobs it has done for a
decade. Buy it when the project is
small, the price difference is real,
or you are maintaining something built
on it. Buy the ESP32 when there is
any chance the project grows, wants
Bluetooth, or wants sleep it can trust;
the gap in price is smaller than the
gap in headroom.

## Raspberry Pi Pico W: the other five dollars

The **Pico W** is the Raspberry Pi
foundation's microcontroller board:
its own RP2040 chip (or the newer
RP2350 in the Pico 2 line), Wi-Fi and
BLE added on top, and two ecosystems —
C and a first-class MicroPython — with
documentation of a quality nobody else
in this price range matches. Choose it
when the job is mostly the pins and
timing (its programmable input-output
blocks do tricks no ESP32 pin can),
when its documentation style suits
you, or when the radios are a garnish
rather than the meal. Choose the ESP32
when the radios *are* the meal: more
Bluetooth, more libraries that assume
them, and sleep currents the Pico
family does not chase.

## The bigger Pi: a different species

A full **Raspberry Pi** runs Linux:
files, users, packages, Python scripts
edited on the device itself, real
databases and web servers. When the
job needs any of that — logging months
of data, serving several programs at
once, being administered like a
computer — it is not a more expensive
ESP32, it is the correct tool, and
chapter 1 said so from the other side.
The costs are the mirror: price, power
(a sleeping Pi is a contradiction in
terms), a boot measured in tens of
seconds, and an SD card as a wear item.
Many real systems end up as both: a Pi
thinking, ESP32s sensing at the edges.

## ESPHome: the neighbour who moved in

**ESPHome** is not a chip but a way of
life built on these chips: you describe
a device in a configuration file — this
sensor, that switch, these rules — and
ESPHome writes, builds and flashes the
firmware for you, aimed squarely at
home automation and fluent in its
languages. Writing no code is not a
compromise here; for a house full of
sensors reporting to a home-automation
hub, it is the fastest correct answer
and this guide says so without a
grudge. Choose the ways of chapter 4
instead when the device's behaviour is
the interesting part — a custom
instrument, a product, a lesson — or
when the thing you are building is a
program, not a configuration.

## The classic Arduino boards

The Arduino Uno and its kin are
5 volt, radio-less, gloriously simple,
with a decade of school-friendly
material behind them. For learning
what a pin *is*, and for 5 V hardware
that expects them, they remain honest
tools — remembering chapter 1's rule
before ever letting their outputs
touch an ESP32 pin. What they cannot
do is this guide's whole subject: be a
citizen of a network.

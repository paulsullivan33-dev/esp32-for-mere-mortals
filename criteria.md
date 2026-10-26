# Writing criteria for this guide

Every "for Mere Mortals" guide is written to the same nine-point
standard, so a reader who trusts one can trust the rest. Here it
is, with the verification notes for this particular guide below.

1. **Fix it first.** Reader outcomes lead, not action items: each
   chapter opens by naming the outcome it delivers, shows a check
   the reader can run to confirm they got it, and a reasonable
   reader finishes able to state what was done, what it means,
   and what to try next.
2. **Plain language.** Short sentences, everyday vocabulary,
   technical terms defined on first use. No slang, and no
   idioms that only make sense in one country — the reader may
   be translating as they go.
3. **No dead ends.** A guide never tells the reader to do
   something it cannot show them how to verify. Every claim a
   reader relies on — an install, a command, an output — is
   something this guide demonstrates or clearly labels
   documented-only below.
4. **Live-verified where it matters.** Procedures are run for
   real in the guide's lab wherever the build machine allows it,
   and the transcripts kept in the repository are the evidence.
   What could not be run is listed honestly below, never
   presented as if it had been.
5. **General audiences.** Nothing in this guide — examples,
   fixtures, names, addresses — is modelled on any particular
   reader or author's real life, network, or organisations.
   The lab's one project is an invented workshop sensor node.
6. **Standalone.** A reader needs this guide, its lab, and
   nothing else. Where another guide would genuinely help, it
   is pointed to once, by name, and the chapter still completes
   without it.
7. **Honest about limits.** Chapter 14 names what the chip
   cannot do: 5 GHz Wi-Fi that no family member will ever
   hear, a Linux it cannot run, timing the radios can
   disturb, an ADC that guides rather than gauges, pins
   that are signals and never power supplies, and firmware
   anyone holding the board can replace.
8. **The safety rules are in the text, early.** Chapter 1 and
   the README state them plainly — *3.3 volt logic, never
   5 volts into a pin; power peaks that defeat weak USB;
   and a LiPo is stored energy, not a coin cell* — before
   any wiring depends on them, and chapters 7, 10 and 14
   repeat each rule where it bites.
9. **Builds clean.** The site builds with MkDocs in strict mode
   with no warnings, and a fresh reader following the chapters
   in order reaches the stated outcome of each.

## Verification notes for this guide

The build machine is a 2-CPU, 7.7 GB Ubuntu 24.04 sandbox
with no ESP32 board attached. The toolchain was installed for
real: **arduino-cli 1.5.2-rc.1**, Espressif's **ESP32 core
3.3.12**, and the **ArduinoJson 7.4.3** library, all in a
self-contained folder, and three sketches written for the
guide (`esp32-lab/sketches/`) were compiled for the generic
original-ESP32 target, `esp32:esp32:esp32`. All transcripts
live in `esp32-lab/transcripts/`.

One install wrinkle is recorded rather than tidied away:
arduino-cli's own download checks repeatedly stalled in this
sandbox (its HEAD requests to github.com timed out while
other tools fetched the same addresses in about a second).
The lab therefore fetched the package index and every archive
named in it with curl, into the staging cache arduino-cli
itself uses, and let arduino-cli verify each archive's
checksum and perform the install — which it did, reporting
platform `esp32:esp32 3.3.12` installed. The failure, the
failed attempts, and the workaround are all in transcript
`t00-toolchain-setup.txt`.

Run for real, with transcripts as evidence:

- arduino-cli installed and reporting its version; the
  ArduinoJson library installed by name from the public
  library index (t00).
- The ESP32 core installed and listed, and the board
  catalogue queried for the family's FQBN names (t00).
- The blink sketch compiled: 271,704 bytes of program
  storage (20% of the 1,310,720-byte app partition) and
  22,116 bytes of global variables (6% of 327,680), with the
  bootloader, partition table and merged 4 MB flash image
  produced (t01).
- The Wi-Fi scan sketch compiled: 877,284 bytes (66%) and
  45,680 bytes of globals — the printed cost of linking the
  Wi-Fi stack, quoted in chapters 6 and 8 (t02).
- The JSON sensor sketch compiled against ArduinoJson:
  276,812 bytes (21%), globals unchanged at 22,116 — the
  library's price measured against the blink baseline (t03).

Documented only — described from the projects' documentation,
not run, and the text does not claim otherwise:

- Everything that needs the physical board. There was no
  board on the lab's bench: uploading and flashing, the
  serial monitor's output, an LED actually blinking,
  a Wi-Fi scan's results on real air, joining and hosting
  networks, BLE exchanges, touch and ADC behaviour,
  deep-sleep currents, displays lit, and over-the-air
  updates arriving. The sketches are compile-verified
  only, and chapters 1 and 6 make the distinction a rule
  of the guide: compiled is proven here, running is
  proven only by the board.
- The deep-sleep arithmetic in chapter 10 is worked from
  published current figures for the chip and typical
  boards; no current was measured.
- ESP-IDF and MicroPython (chapter 4) are characterised
  from their documentation; only the Arduino core path
  was installed.
- Builds for the other family members (S3, C3, and the
  rest) were not compiled; the generic original-ESP32
  target is the lab's one verified target.
- The comparison boards and ESPHome in chapter 13 are
  characterised, not benchmarked.

Fixtures are this guide's own and deliberately generic: a
fictional workshop sensor node that blinks, listens, and
formats an invented temperature reading as JSON. The
temperature is simulated in the sketch and says so in its
own comments. No example is modelled on any real person,
network, service or organisation, no real network name or
credential appears anywhere, and the display boards of
chapter 3 are described as a class, from published
specifications, not from any one unit on a bench.

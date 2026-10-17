# Compás v1.2.0

Compás v1.2 is here, full of new features.

A personal note: I like to keep my music player free of distractions, so everything has to be modular. Compás is built around that philosophy. This release brings new plugins, game emulators, eight downloadable player layouts (with more to come), themes, and more.

## New features

- **Rockbox loader:** on R1 and R3 Pro II, the bootloader automatically detects a compatible Rockbox installation on your SD card and shows a boot menu when one is found.
- **Emulators:** download QuickNES (NES), Gearboy (Game Boy and Game Boy Color), Gearsystem (Master System, Game Gear and SG-1000), gpSP (Game Boy Advance), Beetle PCE Fast (PC Engine / TurboGrafx-16), Beetle WonderSwan (WonderSwan and WonderSwan Color), and PrBoom (Doom) from More > Emulators.
- **Updates made easier than ever:** the Player Update option is now available directly in Settings > Updates, including online updates. Future player updates can replace just the player without flashing the entire firmware; the underlying update support was already present.
- **Folder playback:** play a folder or add it to the queue or a playlist from the file browsers. Navigation is unified across browsers.
- **Startup image:** choose a custom splash through the Startup Image plugin, or enable an optional accent-color tint in Appearance > Accent Color. There is also a new default boot splash—thanks to [@buymyhubs](https://github.com/buymyhubs) for [PR #157](https://github.com/Starnished66/compas-player/pull/157).
- **Music menus and Quick Drawer customization:** reorder and hide Music menu entries and Quick Drawer controls. The Kids Mode plugin uses these controls too.
- **Top bar options:** show or hide individual top bar icons and choose the clock position.
- **Six new languages:** Russian, Ukrainian, Dutch, German, Finnish and European Portuguese.
- **Regional keyboards:** AZERTY, QWERTZ, Russian and Ukrainian layouts, a Latin switch for Cyrillic, and long-press character variants such as n, ñ and ń. Themes are also accessible from Settings > Display > Appearance.
- **Crossfeed:** its own Sound screen, with five angle settings from No delay to 90°.
- **PEQ:** refined controls and layout.
- **MSEB plugin:** matches stock HiBy MSEB with native 13-filter processing.
- **Metronome plugin:** now available to download.
- **Album sorting:** remembered separately for Albums, Artists and Album Artist.
- **Repeat mode:** kept when starting another album.
- **Track Information:** shows the file’s SD location. File browsers show friendly, single-line SD paths.
- **Waveforms:** much faster previews, displayed progressively and prefetched for the next track, plus faster local FLAC seeking.
- **ID3v2.4:** fixed parsing of unsynchronized tags.
- **Now Playing:** large queue counts stay on one line.

## Fixes

- **Search:** inline search is kept when you reopen it.
- **Bluetooth:** volume fixes.
- **USB DAC:** fixes for phones, plus a new setting under Charging to disable charging while using USB DAC mode.
- **Album sorting:** applies consistently inside artist views.
- **Cover preloading:** always enabled during playback.

## Look and feel

- Standardized search and menu icons, with refined navigation spacing.
- Redesigned Wallpaper Selector plugin with a file selector and support for images up to 3 MB.
- Refined press feedback on the Home screen.

## Behind the scenes

- Faster startup: approximately 0.5 seconds saved.

Check the plugin store for plugin updates—many more features are on the way.

## How to update

1. Download the `.upt` file for your device: **r1.upt** for R1, **r3proii.upt** for R3 Pro II, or **r3ii_2025.upt** for R3II (2025).
2. Copy it to the root of your SD card, keeping its filename.
3. Open **Settings > Updates > Firmware Update > Install from SD card**.
4. Select **Update & Reboot** and let the firmware update finish without turning off the player.

Pura Vida.

# SpiriTech
SpiriTech is a repo containing four central Rapidfire technologies: Paranormal Engine, Solara Engine, Spectral UI, and
Ectoplasm.

# Motivation
Rapidfire Computer Entertainment (led by me, who's writing this) is currently developing CONNIPTION: Paranoia, a
survival horror game which  mixes the paranormal, fast-paced beat-em-up combat, and Soulslike mechanical depth and
difficulty.

Paranoia's vein of survival horror, featuring a dark yet deeply emotional story with a touch of Silent Hill style
psychological horror,  works best with high-fidelity graphics. However, the fast-paced, skill-heavy gameplay also
relies on high framerates. This unfortunate  clash of interests (high fidelity, low performance versus low fidelity,
high performance) led me to decide on developing in-house technology to power the game, rather than using off-the-shelf
solutions that are simply too slow to support the full-production game without making serious sacrifices. Instead of
choosing between high fidelity and high performance (since most engines can rarely do both), I instead have chosen to
do both with this proprietary engine.

Since Unreal Engine 5 can barely manage 30 FPS on console targets (unless you turn on the Forward Renderer, which kills
half the features I want to use it for - such as Nanite - and makes the game look like crap), I've decided that I'm
only going to use it for prototyping, and nothing more. I'm willing to pay the cost to make my game as best as it
can be.

# The Projects

## Paranormal Engine: Natural Graphics, Supernatural Performance
The Paranormal Engine is the game engine behind Paranoia's final release. It's a data-oriented game engine designed
to maximize throughput through the efficient use of data structures and heavy concurrency.

As Jeremy Behreandt states in his Medium article about quaternion math, "while computer processing power increases,
making these costs trivial, so too does the thirst for spectacle..." Paranormal Engine is designed to maintain spectacle
with its capacity to handle extreme amounts of data without losing performance.
### Goals:
- 160 FPS @2560x1600 on PS5/XSX and PC users with an AMD Radeon 780M (GTX 1650) or better
- 60 FPS on Nintendo Switch and @1920x1200 for PC users with hardware from the Kepler/Maxwell days (circa 2013-2015)
- Maintain enough graphical fidelity to maximize the immersion and fear Paranoia intends to create in players
- Reusable for future games, the open-source community, and resumes

## Solara Engine
The Solara Engine is a bring-your-own-engine rendering library, kind of like bgfx. It's also the only thing here not
named after the supernatural.
### Goals:
- Hardware-accelerated linear algebra and particles
- Support for Vulkan, DirectX, Metal, GNM (PlayStation)
- Built-in super-resolution support (either AMD FSR or a custom implementation)
- Support for Nvidia DLSS and other technologies without depending on it to achieve desired performance
- Reusable across other software projects, e.g. if I wanted to make my own Source Filmmaker or Blender or
(insert other 3D program here)

## Spectral UI
Spectral UI is a user interface framework based on ImGui. Used to create the Paranormal Engine's editor, Ectoplasm.
It's not really anything fancy, just meant to reduce some of the boilerplate ImGui naturally comes with. Kind of like
Studio Cherno's Walnut, but data-oriented.
### Goals:
- Minimal overhead, maximum flexibility
- Minimized boilerplate
- Ability to lay out UI elements, snap them to grids, etc

## Ectoplasm
Ectoplasm is the Paranormal Engine's powerful level and asset editor. Its cross-platform user interface is powered by
Spectral UI, of course.
### Goals:
- Powerful tools that cut down development time and improve iteration (terrain, foliage, mesh editing, photogrammetry
integration, etc)
- Feature-match competing AAA game engines like Unreal Engine
- A widget editor that doesn't depend on XML files and other text-based tools, instead providing a rich visual editor
(like Unreal's UMG)

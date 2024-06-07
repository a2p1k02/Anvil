<p align="center"><img height=125 align="center" src="https://static.wikia.nocookie.net/minecraft_gamepedia/images/3/3b/Anvil_%28N%29_JE3.png/revision/latest?cb=20201126085258" /></p>
<h1><p align="center">Anvil</p></h1>

## Description
Anvil is a simple 3D engine with Vulkan API.

## Features
- [x] Window system
- [x] Shader class
- [ ] Textures
- [ ] Camera
- [ ] 3D
- [ ] Mapping
- [ ] Models loading
- [ ] Text
- [ ] GUI
      

## Install dependencies
### Windows is NOT supported
### I don't have official supporting another distros
### Gentoo-based distros
```

sudo emerge --ask media-libs/vulkan-layers media-libs/vulkan-loader dev-util/vulkan-tools dev-util/glslang

```

### Arch-based distros
```

sudo pacman -S vulkan vulkan-tools vulkan-header glfw

```

## Building

```
git clone https://github.com/a2p1k02/Anvil 
cd Anvil
./compile.sh && mkdir build && cd build && cmake .. && make 
```

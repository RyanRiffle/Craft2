# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.glfw.Debug:
/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a


PostBuild.boing.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/boing.app/Contents/MacOS/boing
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/boing.app/Contents/MacOS/boing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/boing.app/Contents/MacOS/boing


PostBuild.gears.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/gears.app/Contents/MacOS/gears
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/gears.app/Contents/MacOS/gears:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/gears.app/Contents/MacOS/gears


PostBuild.heightmap.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/heightmap.app/Contents/MacOS/heightmap
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/heightmap.app/Contents/MacOS/heightmap:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/heightmap.app/Contents/MacOS/heightmap


PostBuild.particles.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/particles.app/Contents/MacOS/particles
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/particles.app/Contents/MacOS/particles:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/particles.app/Contents/MacOS/particles


PostBuild.simple.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/simple.app/Contents/MacOS/simple
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/simple.app/Contents/MacOS/simple:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/simple.app/Contents/MacOS/simple


PostBuild.splitview.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/splitview.app/Contents/MacOS/splitview
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/splitview.app/Contents/MacOS/splitview:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/splitview.app/Contents/MacOS/splitview


PostBuild.wave.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/wave.app/Contents/MacOS/wave
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/wave.app/Contents/MacOS/wave:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Debug/wave.app/Contents/MacOS/wave


PostBuild.clipboard.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/clipboard
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/clipboard:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/clipboard


PostBuild.cursor.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/cursor
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/cursor:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/cursor


PostBuild.empty.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/empty.app/Contents/MacOS/empty
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/empty.app/Contents/MacOS/empty:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/empty.app/Contents/MacOS/empty


PostBuild.events.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/events
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/events:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/events


PostBuild.gamma.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/gamma
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/gamma:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/gamma


PostBuild.glfwinfo.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/glfwinfo
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/glfwinfo:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/glfwinfo


PostBuild.iconify.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/iconify
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/iconify:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/iconify


PostBuild.joysticks.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/joysticks
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/joysticks:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/joysticks


PostBuild.monitors.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/monitors
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/monitors:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/monitors


PostBuild.msaa.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/msaa
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/msaa:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/msaa


PostBuild.reopen.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/reopen
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/reopen:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/reopen


PostBuild.sharing.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/sharing.app/Contents/MacOS/sharing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/sharing.app/Contents/MacOS/sharing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/sharing.app/Contents/MacOS/sharing


PostBuild.tearing.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/tearing.app/Contents/MacOS/tearing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/tearing.app/Contents/MacOS/tearing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/tearing.app/Contents/MacOS/tearing


PostBuild.threads.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/threads.app/Contents/MacOS/threads
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/threads.app/Contents/MacOS/threads:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/threads.app/Contents/MacOS/threads


PostBuild.title.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/title.app/Contents/MacOS/title
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/title.app/Contents/MacOS/title:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/title.app/Contents/MacOS/title


PostBuild.windows.Debug:
PostBuild.glfw.Debug: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/windows.app/Contents/MacOS/windows
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/windows.app/Contents/MacOS/windows:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Debug/windows.app/Contents/MacOS/windows


PostBuild.glfw.Release:
/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a


PostBuild.boing.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/boing.app/Contents/MacOS/boing
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/boing.app/Contents/MacOS/boing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/boing.app/Contents/MacOS/boing


PostBuild.gears.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/gears.app/Contents/MacOS/gears
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/gears.app/Contents/MacOS/gears:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/gears.app/Contents/MacOS/gears


PostBuild.heightmap.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/heightmap.app/Contents/MacOS/heightmap
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/heightmap.app/Contents/MacOS/heightmap:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/heightmap.app/Contents/MacOS/heightmap


PostBuild.particles.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/particles.app/Contents/MacOS/particles
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/particles.app/Contents/MacOS/particles:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/particles.app/Contents/MacOS/particles


PostBuild.simple.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/simple.app/Contents/MacOS/simple
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/simple.app/Contents/MacOS/simple:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/simple.app/Contents/MacOS/simple


PostBuild.splitview.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/splitview.app/Contents/MacOS/splitview
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/splitview.app/Contents/MacOS/splitview:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/splitview.app/Contents/MacOS/splitview


PostBuild.wave.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/wave.app/Contents/MacOS/wave
/Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/wave.app/Contents/MacOS/wave:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/Release/wave.app/Contents/MacOS/wave


PostBuild.clipboard.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/clipboard
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/clipboard:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/clipboard


PostBuild.cursor.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/cursor
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/cursor:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/cursor


PostBuild.empty.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/empty.app/Contents/MacOS/empty
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/empty.app/Contents/MacOS/empty:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/empty.app/Contents/MacOS/empty


PostBuild.events.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/events
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/events:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/events


PostBuild.gamma.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/gamma
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/gamma:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/gamma


PostBuild.glfwinfo.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/glfwinfo
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/glfwinfo:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/glfwinfo


PostBuild.iconify.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/iconify
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/iconify:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/iconify


PostBuild.joysticks.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/joysticks
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/joysticks:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/joysticks


PostBuild.monitors.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/monitors
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/monitors:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/monitors


PostBuild.msaa.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/msaa
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/msaa:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/msaa


PostBuild.reopen.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/reopen
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/reopen:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/reopen


PostBuild.sharing.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/sharing.app/Contents/MacOS/sharing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/sharing.app/Contents/MacOS/sharing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/sharing.app/Contents/MacOS/sharing


PostBuild.tearing.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/tearing.app/Contents/MacOS/tearing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/tearing.app/Contents/MacOS/tearing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/tearing.app/Contents/MacOS/tearing


PostBuild.threads.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/threads.app/Contents/MacOS/threads
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/threads.app/Contents/MacOS/threads:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/threads.app/Contents/MacOS/threads


PostBuild.title.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/title.app/Contents/MacOS/title
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/title.app/Contents/MacOS/title:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/title.app/Contents/MacOS/title


PostBuild.windows.Release:
PostBuild.glfw.Release: /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/windows.app/Contents/MacOS/windows
/Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/windows.app/Contents/MacOS/windows:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/Release/windows.app/Contents/MacOS/windows


PostBuild.glfw.MinSizeRel:
/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a


PostBuild.boing.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/boing.app/Contents/MacOS/boing
/Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/boing.app/Contents/MacOS/boing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/boing.app/Contents/MacOS/boing


PostBuild.gears.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/gears.app/Contents/MacOS/gears
/Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/gears.app/Contents/MacOS/gears:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/gears.app/Contents/MacOS/gears


PostBuild.heightmap.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/heightmap.app/Contents/MacOS/heightmap
/Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/heightmap.app/Contents/MacOS/heightmap:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/heightmap.app/Contents/MacOS/heightmap


PostBuild.particles.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/particles.app/Contents/MacOS/particles
/Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/particles.app/Contents/MacOS/particles:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/particles.app/Contents/MacOS/particles


PostBuild.simple.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/simple.app/Contents/MacOS/simple
/Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/simple.app/Contents/MacOS/simple:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/simple.app/Contents/MacOS/simple


PostBuild.splitview.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/splitview.app/Contents/MacOS/splitview
/Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/splitview.app/Contents/MacOS/splitview:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/splitview.app/Contents/MacOS/splitview


PostBuild.wave.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/wave.app/Contents/MacOS/wave
/Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/wave.app/Contents/MacOS/wave:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/MinSizeRel/wave.app/Contents/MacOS/wave


PostBuild.clipboard.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/clipboard
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/clipboard:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/clipboard


PostBuild.cursor.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/cursor
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/cursor:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/cursor


PostBuild.empty.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/empty.app/Contents/MacOS/empty
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/empty.app/Contents/MacOS/empty:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/empty.app/Contents/MacOS/empty


PostBuild.events.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/events
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/events:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/events


PostBuild.gamma.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/gamma
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/gamma:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/gamma


PostBuild.glfwinfo.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/glfwinfo
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/glfwinfo:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/glfwinfo


PostBuild.iconify.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/iconify
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/iconify:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/iconify


PostBuild.joysticks.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/joysticks
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/joysticks:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/joysticks


PostBuild.monitors.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/monitors
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/monitors:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/monitors


PostBuild.msaa.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/msaa
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/msaa:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/msaa


PostBuild.reopen.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/reopen
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/reopen:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/reopen


PostBuild.sharing.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/sharing.app/Contents/MacOS/sharing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/sharing.app/Contents/MacOS/sharing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/sharing.app/Contents/MacOS/sharing


PostBuild.tearing.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/tearing.app/Contents/MacOS/tearing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/tearing.app/Contents/MacOS/tearing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/tearing.app/Contents/MacOS/tearing


PostBuild.threads.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/threads.app/Contents/MacOS/threads
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/threads.app/Contents/MacOS/threads:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/threads.app/Contents/MacOS/threads


PostBuild.title.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/title.app/Contents/MacOS/title
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/title.app/Contents/MacOS/title:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/title.app/Contents/MacOS/title


PostBuild.windows.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/windows.app/Contents/MacOS/windows
/Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/windows.app/Contents/MacOS/windows:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/MinSizeRel/windows.app/Contents/MacOS/windows


PostBuild.glfw.RelWithDebInfo:
/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a


PostBuild.boing.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/boing.app/Contents/MacOS/boing
/Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/boing.app/Contents/MacOS/boing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/boing.app/Contents/MacOS/boing


PostBuild.gears.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/gears.app/Contents/MacOS/gears
/Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/gears.app/Contents/MacOS/gears:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/gears.app/Contents/MacOS/gears


PostBuild.heightmap.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/heightmap.app/Contents/MacOS/heightmap
/Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/heightmap.app/Contents/MacOS/heightmap:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/heightmap.app/Contents/MacOS/heightmap


PostBuild.particles.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/particles.app/Contents/MacOS/particles
/Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/particles.app/Contents/MacOS/particles:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/particles.app/Contents/MacOS/particles


PostBuild.simple.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/simple.app/Contents/MacOS/simple
/Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/simple.app/Contents/MacOS/simple:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/simple.app/Contents/MacOS/simple


PostBuild.splitview.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/splitview.app/Contents/MacOS/splitview
/Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/splitview.app/Contents/MacOS/splitview:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/splitview.app/Contents/MacOS/splitview


PostBuild.wave.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/wave.app/Contents/MacOS/wave
/Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/wave.app/Contents/MacOS/wave:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/examples/RelWithDebInfo/wave.app/Contents/MacOS/wave


PostBuild.clipboard.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/clipboard
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/clipboard:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/clipboard


PostBuild.cursor.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/cursor
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/cursor:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/cursor


PostBuild.empty.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/empty.app/Contents/MacOS/empty
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/empty.app/Contents/MacOS/empty:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/empty.app/Contents/MacOS/empty


PostBuild.events.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/events
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/events:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/events


PostBuild.gamma.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/gamma
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/gamma:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/gamma


PostBuild.glfwinfo.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/glfwinfo
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/glfwinfo:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/glfwinfo


PostBuild.iconify.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/iconify
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/iconify:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/iconify


PostBuild.joysticks.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/joysticks
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/joysticks:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/joysticks


PostBuild.monitors.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/monitors
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/monitors:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/monitors


PostBuild.msaa.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/msaa
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/msaa:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/msaa


PostBuild.reopen.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/reopen
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/reopen:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/reopen


PostBuild.sharing.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/sharing.app/Contents/MacOS/sharing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/sharing.app/Contents/MacOS/sharing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/sharing.app/Contents/MacOS/sharing


PostBuild.tearing.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/tearing.app/Contents/MacOS/tearing
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/tearing.app/Contents/MacOS/tearing:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/tearing.app/Contents/MacOS/tearing


PostBuild.threads.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/threads.app/Contents/MacOS/threads
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/threads.app/Contents/MacOS/threads:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/threads.app/Contents/MacOS/threads


PostBuild.title.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/title.app/Contents/MacOS/title
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/title.app/Contents/MacOS/title:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/title.app/Contents/MacOS/title


PostBuild.windows.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/windows.app/Contents/MacOS/windows
/Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/windows.app/Contents/MacOS/windows:\
	/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/ryan/code/cloned/Craft/deps/glfw/tests/RelWithDebInfo/windows.app/Contents/MacOS/windows




# For each target create a dummy ruleso the target does not have to exist
/Users/ryan/code/cloned/Craft/deps/glfw/src/Debug/libglfw3.a:
/Users/ryan/code/cloned/Craft/deps/glfw/src/MinSizeRel/libglfw3.a:
/Users/ryan/code/cloned/Craft/deps/glfw/src/RelWithDebInfo/libglfw3.a:
/Users/ryan/code/cloned/Craft/deps/glfw/src/Release/libglfw3.a:

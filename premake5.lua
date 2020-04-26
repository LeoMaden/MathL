workspace "MathL"
	architecture "x64"

	configurations {
		"Debug", "Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MathL"
	location "MathL"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")	
	objdir ("build/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"MathL/src"
	}

	filter "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines "DEBUG" 
		symbols "On"

	filter "configurations:Release"
		defines "Release"
		optimize "On"


project "MathL.Tests"
	location "MathL.Tests"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")	
	objdir ("build/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/googletest-1.10"
	}

	includedirs {
		"MathL/src",
		"MathL.Tests/vendor/googletest-1.10/googletest/include"
	}

	links {
		"MathL",
		"googletest"
	}

	filter "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines "DEBUG" 
		symbols "On"

	filter "configurations:Release"
		defines "Release"
		optimize "On"


project "googletest"
	location "MathL.Tests"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")	
	objdir ("build/" .. outputdir .. "/%{prj.name}")

	files {
		"MathL.Tests/vendor/googletest-1.10/googletest/src/**.h",
		"MathL.Tests/vendor/googletest-1.10/googletest/src/**.cc",
		"MathL.Tests/vendor/googletest-1.10/googletest/include/**.h"
	}

	includedirs {
		"MathL.Tests/vendor/googletest-1.10/googletest/include",
		"MathL.Tests/vendor/googletest-1.10/googletest"--,
		--"MathL.Tests/vendor/googletest-1.10/googlemock/include",
		--"MathL.Tests/vendor/googletest-1.10/googlemock"
	}

	filter "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines "DEBUG" 
		symbols "On"

	filter "configurations:Release"
		defines "Release"
		optimize "On"

	buildoptions {
		"/bigobj"
	}
	
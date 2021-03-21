This is a test project for the issue I'm proposing a fix for.

1. open project
2. check /Content/Movies/Cinematic and notice reference to /Content/Movies/Cinematic_Windows
3. open /Content/Maps/TestMap and notice reference in /Content/Movies/Cinematic is lost

The code is running GetLightMapsAndShadowMaps in TEST_PlatMedSource.cpp, this demonstrates the issue in the serialize function of PlatformMediaSource's.

**Fails in 4.26 but not on master**

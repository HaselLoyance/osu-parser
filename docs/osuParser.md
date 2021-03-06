## OsuParser
Please refer to [osu file format documentation](https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)) for more details
* constructor **OsuParser(stream)**: Constructs an object for parsing "\*.osu" files from input stream
    - *stream*, **istream**, input data stream
* void **Parse()**: Goes through istream and reads all data
<br>After calling **.Parse()** the following data members will be filled and available:
    - *formatVersion*, **uint8_t**, version of beatmap file
    - *audioFilename*, **string**, location of the audio file
    - *audioLeadIn*, **OsTime**, amount of time added before the audio file begins playing
    - *previewTime*, **OsTime**, when the audio file should begin playing when selected in the song selection menu
    - *countdown*, **bool**, whether or not a countdown occurs before the first hit object appears
    - *sampleSet*, **SampleSet**, what set of hit sounds will be used
    - *stackLeniency*, **double**, how often closely placed hit objects will be stacked together
    - *mode*, **GameMode**, defines the game mode
    - *letterboxInBreaks*, **bool**, whether the letterbox appears during breaks
    - *widescreenStoryboard*, **bool**, whether or not the storyboard should be widescreen
    - *bookmarks*, **vector\<OsTime>**, times of editor bookmarks
    - *distanceSpacing*, **double**, multiplier for the "Distance Snap" feature
    - *beatDivisor*, **uint8_t**, beat division for placing objects
    - *gridSize*, **uint8_t**, size of the grid for the "Grid Snap" feature
    - *gridLevel*, **uint8_t**, grid level as it appears in the editor
    - *timelineZoom*, **double**, zoom in the editor timeline
    - *title*, **string**, title of the song limited to ASCII characters
    - *titleUnicode*, **string**, title of the song with unicode support. If not present, title is used
    - *artist*, **string**, name of the song's artist limited to ASCII characters
    - *artistUnicode*, **string**, name of the song's artist with unicode support. If not present, artist is used
    - *creator*, **string**, username of the mapper
    - *version*, **string**, name of the beatmap's difficulty
    - *source*, **string**, describes the origin of the song
    - *tags*, **vector\<string>**, vector of words describing the song
    - *beatmapID*, **OsInteger**, ID of the single beatmap
    - *beatmapSetID*, **OsInteger**, ID of the beatmap set
    - *hpDrainRate*, *HP*, **double**, HP drain difficulty
    - *circleSize*, *CS*, **double**, size of hit object circles
    - *approachRate*, *AR*, **double**, amount of time allowed to click a hit object on time
    - *overallDifficulty*, *OD*, **double**, amount of time taken for the approach circle and hit object to appear
    - *circleRadiusPx*, **double**, radius of a circle based on CS in osu! pixels
    - *hitWindow300*, *hitWindow100*, *hitWindow50*, **OsTime**, how much time is allowed to hit each score
    - *requiredRPS*, **double**, harshness of spinners based on OD. Rotations per second required
    - *preemptMs*, **OsTime**, amount of time since object's start to fade in to perfect hit
    - *fadeInMs*, **OsTime**, amount of time it takes for object to completely fade in
    - *sliderMultiplier*, **double**, multiplier for the slider velocity
    - *sliderTickRate*, **double**, how often slider ticks appear
    - *events*, **vector\<Event>**, events related to background and breaks
    - *timingPoints*, **vector\<TimingPoint>**, vector of timing points that describe a number of properties regarding beats per minute and hit sounds
    - *msPerBeats*, **vector\<double>**, all values of msPerBeat in the beatmap that are inheritable
    - *lowestBPM*, **double**, lowest beatmap BPM (highest msPerBeat)
    - *highestBPM*, **double**, highest beatmap BPM (lowest msPerBeat)
    - *averageBPM*, **double**, average beatmap BPM
    - *colors*, **vector\<RGBAColor>**, vector of the colors of the combos
    - *hitObjects*, **vector\<HitObject>**, vector of all the hit objects in a beatmap

#ifndef MUSIC_ORGANIZER_H
#define MUSIC_ORGANIZER_H

#include <stdlib.h>

struct MusicLibrary *create_music_library();
const char **scan_directory(const char *directory_path);
struct MusicFile *process_music_file(const char *directory_path, const char *filename);
void update_music_library(struct MusicLibrary *library, struct MusicFile *song);

#endif
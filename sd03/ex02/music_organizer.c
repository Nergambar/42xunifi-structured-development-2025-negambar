#include "music_organizer.h"

// Creates and returns a new music library. Returns NULL on fail
struct MusicLibrary *create_music_library();
// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char **scan_directory(const char *directory_path);
// Processes a single music file. Returns a data structure representing the processed file.
struct MusicFile *process_music_file(const char *directory_path, const char *filename);
// Updates the music library with the processed music file information.
void update_music_library(struct MusicLibrary *library, struct MusicFile *song);

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    struct MusicLibrary *library = create_music_library();
    if (!library)
        return (NULL);
    const char **directory = scan_directory(directory_path);
    if (!directory)
        return (free(library), NULL);
    struct MusicFile *file;
    for (int i = 0; directory_path[i]; i++){
        file = process_music_file(directory_path, directory[i]);}
    if (!file)
    {
        for (int i = 0; directory[i]; i++){
            free(directory[i]);}
        free(file);
        free(library);
        return(NULL);
    }
    update_music_library(library, file);
    if (!file)
    {
        for (int i = 0; directory[i]; i++){
            free(directory[i]);}
        free(file);
        free(library);
        return(NULL);
    }
    return(library);
}
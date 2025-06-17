// Combine a song into a playlist given mood settings. Returns a new Playlist or NULL on failure.
struct Playlist *combine_with_mood_playlist(struct SongData *song, struct MoodSettings *mood);
// Free functions for cleanup
void free_mood_settings(struct MoodSettings *mood);
void free_filter_settings(struct FilterSettings *filters);
void free_song_data(struct SongData *song);
void free_playlist(struct Playlist *playlist);

#include "playlist_creator.h"
#include <stdlib.h>

struct Playlist *create_playlist(void)
{
    struct MoodSettings *mood;
    struct FilterSettings *filter;
    struct SongData *song;
    mood = analyze_user_mood();
    if (!mood)
        return (NULL);
    filter = default_filters();
    if (!filter)
        return (free_mood_settings(mood), NULL);
    int moodd = get_mood_variations(mood);
    if (!moodd)
        return (free_mood_settings(mood), free_filter_settings(filter), NULL);
    filter = refine_filters(filter);
    if (!filter)
        return (free_mood_settings(mood), free_filter_settings(filter), NULL);
    int pop = filters_require_popular_song(filter);
    if (pop)
        song = fetch_popular_song();
    else
        song = fetch_niche_song();
    struct Playlist *play = combine_with_mood_playlist(song, mood);
    if (!play)

    return (play)
}
#include <assert.h>

#include "font.h"
#include "../utils/vector/vector.h"

Vector* fonts;

Font* font_load(const char* path, int size)
{
	Font* font = (Font*)malloc(sizeof(Font));
	assert(font); //couldn't allocate memory
	font->font = TTF_OpenFont(path, size);
	assert(font->font); //couldn't load font
	font->size = size;
	vector_push_back(fonts, font);
	return font;
}

void _font_init()
{
	fonts = vector_create(0);
}
void _font_close()
{
	for (size_t i = 0; i < fonts->size; i++)
	{
		Font* font = vector_get(fonts, i);
		TTF_CloseFont(font->font);
		free(font);
	}
	vector_free(fonts);
}
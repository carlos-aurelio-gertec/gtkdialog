/*
 * stringman.c: Special string maniplutations.
 * Gtkdialog - A small utility for fast and easy GUI building.
 * Copyright (C) 2003-2007  L�szl� Pere <pipas@linux.pte.hu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* 
**
** $Id: stringman.c,v 1.1 2004/11/16 20:43:31 root Exp root $
** $Log: stringman.c,v $
** Revision 1.1  2004/11/16 20:43:31  root
** Initial revision
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>

#include "gtkdialog.h"
#include "stringman.h"
#include "widgets.h"

#define IN_TEXT         1
#define IN_SEPARATOR    2


#ifdef G_OS_WIN32
ssize_t
getline(char **lineptr, size_t *n, FILE *stream)
{
	g_warning("%s(): Unimplemented", __func__);
	return 0;
}
#endif

gboolean
input_is_shell_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "command:", 8) == 0;
}

const gchar *
input_get_shell_command(const gchar *command)
{
	if (input_is_shell_command(command))
		return command + 8;
	else
		return NULL;
}

gboolean
command_is_shell_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "command:", 8) == 0;
}

const gchar *
command_get_shell_command(const gchar *command)
{
	if (command_is_shell_command(command))
		return command + 8;
	else
		return NULL;
}

gboolean
command_is_exit_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "exit:", 5) == 0;
}

const gchar *
command_get_exit_command(const gchar *command)
{
	if (command_is_exit_command(command))
		return command + 5;
	else
		return NULL;
}

gboolean
command_is_closewindow_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "closewindow:", 12) == 0;
}

const gchar *
command_get_closewindow_command(const gchar *command)
{
	if (command_is_closewindow_command(command))
		return command + 12;
	else
		return NULL;
}

gboolean
command_is_launch_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "launch:", 7) == 0;
}

const gchar *
command_get_launch_command(const gchar *command)
{
	if (command_is_launch_command(command))
		return command + 7;
	else
		return NULL;
}

gboolean
command_is_enable_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "enable:", 7) == 0;
}

const gchar *
command_get_enable_command(const gchar *command)
{
	if (command_is_enable_command(command))
		return command + 7;
	else
		return NULL;
}


gboolean
command_is_disable_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "disable:", 8) == 0;
}

const gchar *
command_get_disable_command(const gchar *command)
{
	if (command_is_disable_command(command))
		return command + 8;
	else
		return NULL;
}


gboolean
command_is_refresh_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "refresh:", 8) == 0;
}

const gchar *
command_get_refresh_command(const gchar *command)
{
	if (command_is_refresh_command(command))
		return command + 8;
	else
		return NULL;
}


gboolean
command_is_save_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "save:", 5) == 0;
}

const gchar *
command_get_save_command(const gchar *command)
{
	if (command_is_save_command(command))
		return command + 5;
	else
		return NULL;
}


gboolean
command_is_fileselect_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "fileselect:", 11) == 0;
}

const gchar *
command_get_fileselect_command(const gchar *command)
{
	if (command_is_fileselect_command(command))
		return command + 11;
	else
		return NULL;
}

gboolean
command_is_clear_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "clear:", 6) == 0;
}

const gchar *
command_get_clear_command(const gchar *command)
{
	if (command_is_clear_command(command))
		return command + 6;
	else
		return NULL;
}


gboolean
command_is_removeselected_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "removeselected:", 15) == 0;
}

const gchar *
command_get_removeselected_command(const gchar *command)
{
	if (command_is_removeselected_command(command))
		return command + 15;
	else
		return NULL;
}


gboolean
command_is_insert_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "insert:", 7) == 0;
}

const gchar *
command_get_insert_command(const gchar *command)
{
	if (command_is_insert_command(command))
		return command + 7;
	else
		return NULL;
}


gboolean
command_is_append_command(const gchar *command)
{
	if (command == NULL)
		return FALSE;
	return strncasecmp(command, "append:", 7) == 0;
}

const gchar *
command_get_append_command(const gchar *command)
{
	if (command_is_append_command(command))
		return command + 7;
	else
		return NULL;
}



static gchar *prefixes[] = {
		"command", "exit",  "closewindow", "launch", "enable",
		"disable", "refresh", "save", "fileselect", "clear",
		"removeselected", "insert", "append", NULL
	};


CommandType
command_prefix_get_type(const gchar *prefix) 
{
	gint n;
	for (n = 0; prefixes[n] != NULL; ++n) 
		if (g_ascii_strcasecmp(prefix, prefixes[n]) == 0)
			return (CommandType) n;

	return CommandShellCommand;
}

void
command_get_prefix(const gchar *string, 
		gchar **prefix,
		gchar **command)
{
	gchar *separator;
	gchar *tmp;
	gint   n;

	g_assert(string != NULL && prefix != NULL && command != NULL);
	separator = g_utf8_strchr(string, -1, ':');
	if (separator == NULL) {
		*prefix = g_strdup("command");
		*command = g_strchug(g_strdup(string));
		return;
	}
	
	n = g_utf8_pointer_to_offset(string, separator);
	tmp = g_strndup(string, n);

	for (n = 0; prefixes[n] != NULL; ++n) 
		if (g_ascii_strcasecmp(tmp, prefixes[n]) == 0) {
			*prefix = tmp;
			*command = g_strchug(g_strdup(separator + 1));
			return;
		}
	
	/*
	** We found the separator, but the prefix is invalid, so it is a shell
	** command with a ':' in it.
	*/
	g_free(tmp);
	*prefix = g_strdup("command");
	*command = g_strchug(g_strdup(string));
}


char *
find_pixmap(char *filename)
{
	if (access(filename, R_OK) == 0)
		return filename;

	return "";	/* Thunor: added as missing */
}


/* Thunor: This function does not destroy the original string, rather it
 * makes duplicates of it stored within the list_t struct which possibly
 * requires freeing with list_t_free depending on who is going to own
 * the individual strings.
 * 
 * Cutting the line to substrings with the given field separator.
 */
list_t *linecutter(char *str, int fs)
{
	list_t *parts;
	int n, q;
	
	g_assert(str != NULL);
#ifdef DEBUG
	g_message("%s(%s, %c)", __func__, str, fs);
#endif

	parts = g_malloc(sizeof(list_t));
	parts->line = g_malloc(sizeof(char *) * 128);
	parts->maxlines = 128;
	parts->line[0] = str;
	parts->n_lines = 1;
	
	for(n = 0; n <= strlen(str); ++n){
		if (str[n] == fs){
			parts->line[parts->n_lines] = strdup(str + n + 1);
			++parts->n_lines;
		}
	}
	
	parts->line[parts->n_lines] = NULL;

	for (n = 0; n < parts->n_lines - 1; ++n){
		for (q = 0; q < strlen(parts->line[n]); ++q)
			if (*(parts->line[n] + q) == fs)
				*(parts->line[n] + q)= '\0';
	}
	return parts;
}

/* Thunor: The linecutter function above is allocating memory for the
 * returned list_t structure but nowhere within the project have I seen
 * these structures being freed, so I've created a function to do it */

void list_t_free(list_t *ptr)
{
	gint count;

	if (ptr != NULL) {
		for (count = 0; count < ptr->n_lines; count++)
			g_free(ptr->line[count]);
		g_free(ptr->line);
		g_free(ptr);
		ptr = NULL;
	}
}

/*
** This function will give a default name for widgets, so every
** widget can get a variable name.
*/
char *str_default_name(int itype)
{
	static int serial = 0;
	char *type;
	char *name;

	name = g_malloc(64);

	++serial;
	type = widgets_to_str(itype);
	sprintf(name, "%s%03d", type, serial);
	return (name);
}

char *
get_tag_attribute(tag_attr *attr, 
		const char *name)
{
	int q;
	
	g_assert(attr != NULL && name != NULL);
#ifdef DEBUG
	g_message("%s(): searching for name = '%s' in %p", 
			__func__, name, attr);
#endif
	for (q = 0; q < attr->n; ++q) 
		if (strcmp(attr->pairs[q].name, name) == 0)
			return attr->pairs[q].value;

	return NULL;
}

tag_attr *
add_tag_attribute(tag_attr *attr, 
		char *name, 
		char *value)
{
	g_assert(attr != NULL);
	g_assert(name != NULL && value != NULL);
#ifdef DEBUG	
	g_message("%s(): name = '%s' value = '%s'", __func__, name, value);
#endif 
		
	if (name[strlen(name) - 1] == '=')
		name[strlen(name) - 1] = '\0';
	//
	// If the store is full, we enlarge its size.
	//
	if (attr->n == attr->nmax){
		attr->nmax += 32;
		attr->pairs = g_realloc(attr->pairs,
				attr->nmax * sizeof(namevalue));
	}
	/*
	 * What if this tagattr is already exists?
	 */
	attr->pairs[attr->n].name = g_strdup(name);
	attr->pairs[attr->n].value = g_strdup(value);
	++attr->n;
	return attr;
}

/*
 * Simple functions to handle attributesets, name/value pair list.
 */
tag_attr *new_tag_attributeset(
		char *name, 
		char *value)
{
	tag_attr *New;

	g_assert(name != NULL);
	g_assert(value != NULL);
	
#ifdef DEBUG
	g_message("%s(): Name: '%s' Value: '%s'.", __func__, name, value);
#endif
	if (name[strlen(name) - 1] == '=')
		name[strlen(name) - 1] = '\0';
	
	New = g_malloc(sizeof(tag_attr));
	
	New->pairs = g_malloc(sizeof(namevalue) * 32);
	New->nmax = 32;
	New->n = 1;
	
	New->pairs[0].name = g_strdup(name);
	New->pairs[0].value = g_strdup(value);
	return New;
}


/**
 * Copyright (C) 2012 The CompilerKit contributors.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include <glib.h>
#include "CompilerKit.h"
#include "test.h"

void test_convenience_alternation(void)
{
    GObject* expression1 = compilerkit_alpha_numeric_character_class_new('0','h');
    GObject* expression2 = compilerkit_alpha_numeric_character_class_new(33,'h');
    GObject* expression3 = compilerkit_alpha_numeric_character_class_new('0',137);
    g_assert(expression1 != NULL);
    g_assert(expression2 == NULL);
    g_assert(expression3 == NULL);
    g_object_unref(expression1);
}

void test_positive_closure(void)
{
    GObject *regex, *positive_closure;
    CompilerKitConcatenation *cat;
    CompilerKitKleeneStar *star;
    
    g_test_message ("Testing positive closure");
    g_test_timer_start ();
    
    regex = compilerkit_concatenation_new (compilerkit_symbol_new('a'), compilerkit_symbol_new('b'));
    positive_closure = compilerkit_positive_closure_new (regex);
    
    g_assert (COMPILERKIT_IS_CONCATENATION(positive_closure));
    cat = COMPILERKIT_CONCATENATION(positive_closure);
    
    g_assert (compilerkit_concatenation_get_left (cat) == regex);
    
    g_assert (COMPILERKIT_IS_KLEENE_STAR (compilerkit_concatenation_get_right (cat)));
    star = COMPILERKIT_KLEENE_STAR (compilerkit_concatenation_get_right (cat));
    
    g_assert (compilerkit_kleene_star_get_node (star) == regex);

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
    
}

void test_string_concatenation(void)
{
    GObject *str;

    g_test_message ("Testing string concatenation");
    g_test_timer_start ();

    str = compilerkit_string_concatenation("hello");
    g_assert (compilerkit_regex_matches_string (str, "hello"));
    g_assert (!compilerkit_regex_matches_string (str, "world"));

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
}

void test_convenience_times (void)
{
    GObject *times;
    
    g_test_message ("Testing convenience times");
    g_test_timer_start ();

    times = compilerkit_times_new(compilerkit_regex_digits(),5);
    g_assert (compilerkit_regex_matches_string (times, "12345"));
    g_assert (compilerkit_regex_matches_string (times, "01234"));
    g_assert (!compilerkit_regex_matches_string (times, "0123"));
    g_assert (!compilerkit_regex_matches_string (times, "1"));
    g_assert (!compilerkit_regex_matches_string (times, "123456"));
    
    times = compilerkit_times_extended_new(compilerkit_regex_digits(),5,8);
    g_assert (compilerkit_regex_matches_string (times, "12345"));
    g_assert (compilerkit_regex_matches_string (times, "123456"));
    g_assert (compilerkit_regex_matches_string (times, "1234567"));
    g_assert (compilerkit_regex_matches_string (times, "12345678"));
    g_assert (!compilerkit_regex_matches_string (times, "123456789"));

    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);    
}

void test_convenience_ranges(void)
{
    GObject *range;
    
    g_test_message ("Testing convenience ranges");
    g_test_timer_start ();

    range = compilerkit_positive_closure_new(compilerkit_regex_digits());
    g_assert (compilerkit_regex_matches_string (range, "0123456789"));
    g_assert (!compilerkit_regex_matches_string (range, "abcdefghijklmnopqrstuvwxyz"));
    
    range = compilerkit_positive_closure_new (compilerkit_regex_lower());
    g_assert (compilerkit_regex_matches_string (range, "abcdefghijklmnopqrstuvwxyz"));
    g_assert (!compilerkit_regex_matches_string (range, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));

    range = compilerkit_positive_closure_new (compilerkit_regex_upper());
    g_assert (!compilerkit_regex_matches_string (range, "abcdefghijklmnopqrstuvwxyz"));
    g_assert (compilerkit_regex_matches_string (range, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));

    range = compilerkit_positive_closure_new (compilerkit_regex_punct());
    g_assert (!compilerkit_regex_matches_string (range, "abcdefghijklmnopqrstuvwxyz"));
    g_assert (compilerkit_regex_matches_string (range, "!@#$%^&*()_+=-:;',.<>/?`~[]\{}|"));
    
    // This test shouldn't take too long to run
    g_assert_cmpfloat(g_test_timer_elapsed (), <=, 1);
    
}
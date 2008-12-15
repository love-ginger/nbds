#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "map.h"

typedef struct sl skiplist_t;
typedef struct sl_iter sl_iter_t;

skiplist_t * sl_alloc (const datatype_t *key_type);
uint64_t sl_cas     (skiplist_t *sl, void *key, uint64_t expected_val, uint64_t new_val);
uint64_t sl_lookup  (skiplist_t *sl, void *key);
uint64_t sl_remove  (skiplist_t *sl, void *key);
uint64_t sl_count   (skiplist_t *sl);
void     sl_print   (skiplist_t *sl);
void     sl_free    (skiplist_t *sl);
void *   sl_min_key (skiplist_t *sl);

sl_iter_t * sl_iter_begin (skiplist_t *sl, void *key);
uint64_t    sl_iter_next  (sl_iter_t *iter, void **key_ptr);
void        sl_iter_free  (sl_iter_t *iter);

static const map_impl_t sl_map_impl = { 
    (map_alloc_t)sl_alloc, (map_cas_t)sl_cas, (map_get_t)sl_lookup, (map_remove_t)sl_remove, 
    (map_count_t)sl_count, (map_print_t)sl_print, (map_free_t)sl_free, (map_iter_begin_t)sl_iter_begin,
    (map_iter_next_t)sl_iter_next, (map_iter_free_t)sl_iter_free
};

#endif//SKIPLIST_H

#include <glib.h>
#include <stdio.h>

#define BUF_SIZE 81

gint compare_less(gchar * a, gchar * b, GHashTable* pTable) {
    return g_hash_table_lookup(pTable, b) - g_hash_table_lookup(pTable, a);
}

void print(gchar* elem, GHashTable* pTable) {
    printf("%s %d\n", (gchar *)elem, GPOINTER_TO_INT(g_hash_table_lookup(pTable, elem)));
}

int main() {
    GHashTable *pTable = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
    char buf[BUF_SIZE];

    while (fgets(buf, BUF_SIZE, stdin) != NULL) {
        gchar **words = g_strsplit_set(buf, "\t \n", 0);
        for (int i = 0; words[i] != NULL; i++) {
            if (g_strcmp0(words[i], "") == 0) continue;
            gpointer k = g_hash_table_lookup(pTable, words[i]);
            if (k == NULL) {
                g_hash_table_insert(pTable, g_strdup(words[i]), GINT_TO_POINTER(1));
            } else {
                g_hash_table_replace(pTable, g_strdup(words[i]), GINT_TO_POINTER(GPOINTER_TO_INT(k) + 1));
            }
        }
        g_strfreev(words);
    }
    GList *lst = g_hash_table_get_keys(pTable);
    lst = g_list_copy_deep(lst, (GCopyFunc)g_strdup, NULL);
    lst = g_list_sort_with_data(lst, (GCompareDataFunc)compare_less, pTable);
    g_list_foreach(lst, (GFunc) print, pTable);

    g_list_free_full(lst, g_free);
    g_hash_table_destroy(pTable);
    return 0;
}

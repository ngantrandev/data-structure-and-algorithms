#include "my_copy.h"

// sao chep data tu old_tree sang temp_tree
void saoChepMonHocTheoTen(PTRMH old_tree, PTRMH &new_tree)
{
    if (old_tree != NULL)
    {
        themMonHoc_TheoTen(new_tree, old_tree->course);
        saoChepMonHocTheoTen(old_tree->pLeft, new_tree);
        saoChepMonHocTheoTen(old_tree->pRight, new_tree);
    }
}
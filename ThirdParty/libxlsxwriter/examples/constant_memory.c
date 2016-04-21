/*
 * Example of using libxlsxwriter for writing large files in constant memory
 * mode.
 *
 * Copyright 2014-2015, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

int main() {

    lxw_row_t row;
    lxw_col_t col;
    lxw_row_t max_row = 1000;
    lxw_col_t max_col = 50;

	// 1
    lxw_workbook  *workbook;
    lxw_worksheet *worksheet;

    /* Set the worksheet options. */
    lxw_workbook_options options;
    options.constant_memory = 1;

    /* Create a new workbook with options. */
    // 1
    workbook  = workbook_new_opt("constant_memory.xlsx", &options);
    worksheet = workbook_add_worksheet(workbook, NULL);

    for (row = 0; row < max_row; row++) {
        for (col = 0; col < max_col; col++) {
            worksheet_write_number(worksheet, row, col, 123.45, NULL);
        }
    }

    return workbook_close(workbook);
}

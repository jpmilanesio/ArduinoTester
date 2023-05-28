#include <cstdio>


class LiquidCrystal_I2C {
	private:
		static const int MAX_ROWS = 16;
		static const int MAX_COLS = 20;
		int rows;
		int cols;
		char lcd_screen[MAX_ROWS][MAX_COLS];
		int actual_cursor_row = 0;
		int actual_cursor_col = 0;

		void print_on_lcd(const char* str) {
			int characters = snprintf(NULL, 0, "%s", str);
			const char* to_print = str;
			int new_cursor_r = actual_cursor_row;

			if (actual_cursor_row <= rows) {
				for (int n_chars = characters - 1; n_chars >= 0; n_chars--) {
					if (actual_cursor_row + n_chars <= 15) {
						lcd_screen[actual_cursor_row + n_chars][actual_cursor_col] = to_print[n_chars];
						new_cursor_r++;
					}
				}
			}
			actual_cursor_row = new_cursor_r;
			print_screen();
		}

		void print_screen() {
			printf("\n");
			printf("%s\n", "+----------------+");
			for (int c = 0; c < cols; c++) {
				printf("|");
				for (int r = 0; r < rows; r++) {
					printf("%c", lcd_screen[r][c]);
				}
				printf("%s\n", "|");
			}
			printf("%s\n", "+----------------+");

		}

		void init_screen() {
			for (int r = 0; r < rows; r++) {
				for (int c = 0; c < cols; c++) {
					lcd_screen[r][c] = ' ';
				}
			}
		}

	public:
		LiquidCrystal_I2C(int lcd_Addr, int lcd_rows, int lcd_cols) {
			rows = lcd_rows;
			cols = lcd_cols;
			actual_cursor_row = 0;
			actual_cursor_col = 0;
			init_screen();
		}

		void init() {
			init_screen();
		}

		void clear() {
			init_screen();
			print_screen();
		}

		void blacklight() {
			// Do nothing
		}

		void setCursor(int row, int column) {
			if (row < rows) {
				actual_cursor_row = row;
				actual_cursor_col = column;
				
			}
		}

		void print(int to_print_p) {
			char to_print[20];
			sprintf(to_print, "%d", to_print_p);
			print_on_lcd(to_print);
		}

		void print(const char* str) {
			const char* to_print = str;
			print_on_lcd(to_print);
		}

};

int main() {
	LiquidCrystal_I2C lcd(0x27, 16, 2);
	lcd.init();
	lcd.blacklight();
	lcd.clear();
	lcd.print(123);
	lcd.print(456);
	lcd.print(7890);
	lcd.print(123450);
	lcd.print(233);
	lcd.setCursor(0, 1);
	lcd.print(123);
	lcd.print(456);
	lcd.print(7890);
	lcd.print(123450);
	lcd.print(233);
	lcd.print(4);
	lcd.setCursor(5, 0);
	lcd.print("h");
	lcd.clear();
	// lcd.print_screen();
	return 0;
}


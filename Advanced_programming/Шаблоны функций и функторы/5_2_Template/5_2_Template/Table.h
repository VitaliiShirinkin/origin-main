#pragma once

template<class T>
class Table {

	int rows_;
	int cols_;
	int size;
	T** table_;
public:

	Table(int rows, int cols) :rows_(rows), cols_(cols), size(rows* cols), table_(nullptr) {

		table_ = new T* [rows_];
		for (int i = 0; i < rows_; i++)
		{
			table_[i] = new T[cols_]();
		}
	}
	Table(const Table& t) :rows_(t.rows_), cols_(t.cols_), size(t.size) {

		table_ = new T * [rows_];
		for (int i = 0; i < rows_; i++)
		{
			table_[i] = new T[cols_]();
		}
		for (int i = 0; i < rows_; i++)
		{
			for (int j = 0; j < cols_; j++) {
				table_[i][j] = t.table_[i][j];
			}
		}
	}

	~Table() {

		for (int i = 0; i < rows_; i++)
		{
			delete[] table_[i];
		}

		delete[]table_;
	}

	Table& operator=(const Table&) = delete;

	T* operator[](int index) {

		if (index >= 0 and index < row_) {

			return table_[index];
		}
	}
	T* operator[](int index) const {

		if (index >= 0 and index < row_) {

			return table_[index];
		}
	}

	int get_size()
	{
		return row_ * cols_;
	}

};

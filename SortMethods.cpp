
//Made for education
//For all types of collections and only for Student class

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <random>

class Student;

std::vector<std::string> names = { "Sanek", "Diana", "Dima", "Danek", "Lexa", "Katya", "Nastya", "Oleg", "Kostya", "Gus", "Vitya", "Stas", "Turbo", "Dusha Metelkin", "Karina"}; //You can edit
const char* message;
typedef std::vector<int> _sVi_;
typedef std::vector<double> _sVd_;
typedef std::vector<Student*> _sVS_;

#define _VECTOR_SIZE_ 15	//You can edit
#define _RANDOM_SEED_ 325	//You can edit
#define _NAMES_DIVISION_ names.size()
#define _POINTS_DIVISION_ 300 //You can edit
#define _MIN_RANDOM_ 1.0 //You can edit
#define _MAX_RANDOM_ 25.0 //You can edit


class Student {
private:
	std::string name;
	int points;
public:
	Student(std::string name, int points) : name(name), points(points) {};
	bool operator==(const Student& p) { return (this->points == p.points); }
	bool operator!=(const Student& p) { return !(*this == p); }
	bool operator>(const Student& p) { return (this->points > p.points); }
	bool operator<(const Student& p) { return (this->points < p.points); }
	void PointOutput() const { std::cout << std::setw(10) << std::setprecision(10) << this->name << ":" << std::setw(5) << std::setprecision(5) << this->points << std::endl; }
};

namespace IO_Actions {

	template<typename T> void Display(const std::vector<T> myVector);
	void Display(const _sVS_ myVector);

	template<typename T> T GenerateRandom(std::vector<T> myVector) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dist((T)(_MIN_RANDOM_), (T)(_MAX_RANDOM_));
		return dist(gen) ;
	}

	void Initialization(_sVS_& myVector) {
		srand(_RANDOM_SEED_);
		for (size_t i = 0; i < _VECTOR_SIZE_; i++)
			myVector.push_back(new Student(names[rand() % _NAMES_DIVISION_], rand() % _POINTS_DIVISION_));
		message = "Own vector points:\n";
		Display(myVector);
	}

	void Display(const _sVS_ myVector) {
		std::cout << message;
		for (size_t i = 0; i < _VECTOR_SIZE_; i++)
			myVector[i]->PointOutput();
		std::cout << std::endl;
	}

	template<typename T> void Initialization(std::vector<T>& myVector) {
		for (size_t i = 0; i < _VECTOR_SIZE_; i++)
			myVector.push_back(GenerateRandom(myVector));
		message = "Own vector:\n";
		Display(myVector);
	}

	template<typename T> void Display(const std::vector<T> myVector) {
		std::cout << message;
		for (size_t i = 0; i < _VECTOR_SIZE_; i++) {
			std::cout << myVector[i] << " ";
		}
		std::cout << std::endl;
	}

}

namespace Sort_Actions {

	template<typename T> void BubbleSort(std::vector<T>& myVector) {
		for (size_t x_i = 0; x_i + 1 < _VECTOR_SIZE_; ++x_i) {
			for (size_t x_j = 0; x_j < _VECTOR_SIZE_ - x_i - 1; ++x_j) {
				if (myVector[x_j + 1] < myVector[x_j]) {
					std::swap(myVector[x_j], myVector[x_j + 1]);
				}
			}
		}
		message = "Bubble sort:\n";
		IO_Actions::Display(myVector);
	}

	template<typename T> void ShakerSort(std::vector<T>& myVector) {
		if (myVector.empty()) return;
		size_t left = 0;
		size_t right = _VECTOR_SIZE_ - 1;
		while (left <= right) {
			for (size_t i = right; i > left; --i) {
				if (myVector[i - 1] > myVector[i]) {
					std::swap(myVector[i - 1], myVector[i]);
				}
			}
			++left;
			for (size_t i = left; i < right; ++i) {
				if (myVector[i] > myVector[i + 1]) {
					std::swap(myVector[i], myVector[i + 1]);
				}
			}
			--right;
		}
		message = "Shaker sort:\n";
		IO_Actions::Display(myVector);
	}

	template<typename T> void CombSort(std::vector<T>& myVector) {
		const double factor = 1.247;
		double step = _VECTOR_SIZE_ - 1;
		while (step >= 1) {
			for (size_t i = 0; i < _VECTOR_SIZE_ - step; ++i) {
				if (myVector[i] > myVector[i + step]) {
					std::swap(myVector[i], myVector[i + step]);
				}
			}
			step /= factor;
		}
		for (size_t x_i = 0; x_i + 1 < _VECTOR_SIZE_; ++x_i) {
			for (size_t x_j = 0; x_j < _VECTOR_SIZE_ - x_i - 1; ++x_j) {
				if (myVector[x_j + 1] < myVector[x_j]) {
					std::swap(myVector[x_j], myVector[x_j + 1]);
				}
			}
		}
		message = "Comb sort:\n";
		IO_Actions::Display(myVector);
	}

	template<typename T> void InsertionSort(std::vector<T>& myVector) {
		for (size_t i = 1; i < _VECTOR_SIZE_; ++i) {
			auto x = myVector[i];
			size_t j = i;
			while (j > 0 && myVector[j - 1] > x) {
				myVector[j] = myVector[j - 1];
				--j;
			}
			myVector[j] = x;
		}
		message = "Insertion sort:\n";
		IO_Actions::Display(myVector);
	}

	template<typename T> void SelectionSort(std::vector<T>& myVector) {
		for (size_t i = 0; i < _VECTOR_SIZE_; ++i) {
			auto j = std::min_element(myVector.begin() + i, myVector.end());
			std::swap(myVector[i], *j);
		}
		message = "Selection sort:\n";
		IO_Actions::Display(myVector);
	}
	
	namespace QuickSortNameSpace {

		template<typename T> int Partition(std::vector<T>& myVector, int l, int r) {
			T x = myVector[r]; 
			int less = l; 

			for (size_t i = l; i < r; ++i) {   
				if (myVector[i] <= x) { 
					std::swap(myVector[i], myVector[less]);  
					++less;
				}
			}
			std::swap(myVector[less], myVector[r]); 
			return less;
		}

		template<typename T> void QuickSortImpl(std::vector<T>& myVector, int l, int r) {
			if (l < r) {   
				int q = Partition(myVector, l, r); 
				QuickSortImpl(myVector, l, q - 1);   
				QuickSortImpl(myVector, q + 1, r);  
			}
		}

		template<typename T> void QuickSort(std::vector<T>& myVector) {
			if (!myVector.empty()) { 
				QuickSortImpl(myVector, 0, _VECTOR_SIZE_ - 1); 
				message = "Quick sort:\n";
				IO_Actions::Display(myVector);
			}
		}

	}

	template<typename T> void HeapSort(std::vector<T>& myVector) {
		std::make_heap(myVector.begin(), myVector.end());
		for (auto i = myVector.end(); i != myVector.begin(); --i) {
			std::pop_heap(myVector.begin(), i);
		}
		message = "Heap sort:\n";
		IO_Actions::Display(myVector);
	}

	namespace MergeSortNameSpace {

		template<typename T> void MergeSortImpl(std::vector<T>& myVector, std::vector<T>& buffer, int l, int r) {
			if (l < r) {
				int m = (l + r) / 2;
				MergeSortImpl(myVector, buffer, l, m);
				MergeSortImpl(myVector, buffer, m + 1, r);

				int k = l;
				for (int i = l, j = m + 1; i <= m || j <= r; ) {
					if (j > r || (i <= m && myVector[i] < myVector[j])) {
						buffer[k] = myVector[i];
						++i;
					}
					else {
						buffer[k] = myVector[j];
						++j;
					}
					++k;
				}
				for (int i = l; i <= r; ++i) {
					myVector[i] = buffer[i];
				}
			}
		}

		template<typename T> void MergeSort(std::vector<T>& myVector) {
			if (!myVector.empty()) {
				std::vector<T> buffer(myVector.size());
				MergeSortImpl(myVector, buffer, 0, _VECTOR_SIZE_ - 1);
				message = "Merge sort:\n";
				IO_Actions::Display(myVector);
			}
		}
	}

	template<typename T> void PredicateSort(std::vector<T>& myVector) {
		std::sort(myVector.begin(), myVector.end(), [](T a, T b) -> bool {
			return a < b;
		});
		message = "std::sort function with predicate:\n";
		IO_Actions::Display(myVector);
	}

	void PredicateSortClass(_sVS_& myVector) {
		std::sort(myVector.begin(), myVector.end(), [](Student* s1, Student* s2) {return *s1 > *s2;});
		message = "std::sort function with predicate and class:\n";
		IO_Actions::Display(myVector);
	}
}

namespace Application {
	
	void StartMenu() {
		std::cout << "Select the sorting option:\n"
			<< "1. Bubble sort\n"
			<< "2. Shaker sort\n"
			<< "3. Comb sort\n"
			<< "4. Insertion sort\n"
			<< "5. Selection sort\n"
			<< "6. Quick sort\n"
			<< "7. Heap sort\n"
			<< "8. Merge sort\n"
			<< "9. Function std::sort\n"
			<< "10. Function std::sort with class\n"
			<< "0. Exit\n";

		int option;

		_sVi_ myVector; //You can edit type of vector (_sVd_ - vector with double type of elements)
		IO_Actions::Initialization(myVector);
		_sVS_ myVector1;
		IO_Actions::Initialization(myVector1);

		while (true) {
			std::cout << ">>> ";
			std::cin >> option;

			switch (option) {
			case 0: std::cout << "Exiting the program" << std::endl; exit(0);
			case 1:
				Sort_Actions::BubbleSort(myVector);
				break;
			case 2:
				Sort_Actions::ShakerSort(myVector);
				break;
			case 3:
				Sort_Actions::CombSort(myVector);
				break;
			case 4:
				Sort_Actions::InsertionSort(myVector);
				break;
			case 5:
				Sort_Actions::SelectionSort(myVector);
				break;
			case 6:
				Sort_Actions::QuickSortNameSpace::QuickSort(myVector);
				break;
			case 7:
				Sort_Actions::HeapSort(myVector);
				break;
			case 8:
				Sort_Actions::MergeSortNameSpace::MergeSort(myVector);
				break;
			case 9:
				Sort_Actions::PredicateSort(myVector);
				break;
			case 10:
				Sort_Actions::PredicateSortClass(myVector1);
				break;
			default:
				std::cout << "Invalid option selected. Please choose a number between 1 and 10.\n";
				break;
			}
		}
	}
}

int main() {
	Application::StartMenu();
}
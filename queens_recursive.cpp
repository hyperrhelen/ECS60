// Written by: Helen Chac
// 
// Finds ALL the possible placements where you can place a queen onto the chess
// board.

#include <iostream>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;


// If we wanted to make this more efficient, we would only check the incoming
// one instead of continuously checking things that we already have.
bool check(vector<std::pair<int, int>> board_coords) {
	unordered_set<int> determine_dups;

  int length = board_coords.size();
	for (int i = 0; i < length; ++i) {
		// If the first and the second of the current piece is the same, that means
		// that it is a diagonal piece. None of them are allowed to be on the 
		// diagonal.
    if (determine_dups.find(board_coords[i].second) != determine_dups.end()) {
			return false;
		}
    for (int j = i + 1; j < length; ++j) { 
      // Checks all the diagonals.
      if (abs(board_coords[i].first - board_coords[j].first) == 
          abs(board_coords[i].second - board_coords[j].second)) {
        return false;
      }    
    }
    determine_dups.insert(board_coords[i].second);
	}
	// If it didn't match any of them, it must mean that it is valid.
	return true;
}

// Checks if a specific spot is able to be put into the board.
bool CheckSpt(vector<std::pair<int,int>> board_coords, int first, int second) {

  for (auto& b : board_coords) {
    if (abs(b.first - first) == abs(b.second - second) || 
        b.first == first || b.second == second) {
      return false;
    }
  }
  return true;
}

// Prints out the board so that we can get a visual.
void PrintBoard(vector<std::pair<int,int>> coords) {
  int length = coords.size();
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < length; ++j) {
      if (coords[i].second == j) {
       cout << "Q";
      } else {
        cout << "x";
      }
    }
    cout << endl;
  }
  cout << "/////////////////////////////////////////" << endl;
}

// Prints out the coordinates of the points for if we don't want to see it in
// grid form.
void PrintCoords(vector<std::pair<int, int>> coords) {
  for (auto& x : coords) {
    cout << "(" << x.first << ", " << x.second << ")" << endl;
  }
}



// First we call a check and make sure that this is valid. If this is 
// valid then we want to print it out. If not, then we want to recurse
// back. But we also want to make sure that the very last thing that we
// put in the vector is like (8,8) or something.
void Queen(int n, int index, vector<std::pair<int, int>> current) {
  if (index == n) {
    // Then we have reached the end and we just need to print it out.
    PrintCoords(current);
    PrintBoard(current);
    return;
  }
    for (int j = 0; j < n; ++j) {
      
      if (CheckSpt(current, index, j)) { 
        current.push_back(std::make_pair(index, j));
        Queen(n, index + 1, current);
        current.pop_back();
      }
      // current.push_back(std::make_pair(index,j));
      // if (check(current) == true) {
      //   Queen(n, index+1, current);
      //   // then there was a match, then we want to move onto the next;
      // }
      // current.pop_back();
    }

  // If we check the current spot and it is valid, then we move onto the next
  // row in the board. But when we reach the end and it is not valid then we 
  // want to return from the function becuase there are no more valid places 
  // to place the queen.
}

int main() {
  int n;
  cout << "N: " ;
  cin >> n;


  vector<std::pair<int, int>> curr;
  Queen(n, 0, curr);

  return 0;
}

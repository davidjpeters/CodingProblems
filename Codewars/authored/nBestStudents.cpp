/* Description

Your teacher knows you've done some programming, and has tasked you with creating a program that calculates the N best students in the class.

You will be given an array students with the names of the students in the class, and a 2 dimensional array grades, containing the grades of the corresponding students.

Ex.

students = {"Ben", "Jane"}
grades = {{75, 80}, {77, 89}}

Bens grades = 75, 80
Jane's grades = 77, 89
Your program should return an array of the names of the n highest scoring students based on the average of their grades.

n >= 1
students.size() == grades.size()
You can assume that you will be given valid input, i.e.

students and grades will never be empty
n will never be greater than the number of students
students will all have the same number of grades to calculate
students grade averages will be unique


*/

// Solution

#include <map>
#include <vector>
#include <string>

std::vector<std::string> nBestStudents(std::vector<std::string> students, std::vector<std::vector<float>> grades, int n) {
  
  std::map<float, std::string, std::greater<float>> map;
    
  for (size_t i = 0; i < students.size(); ++i) {
      float total = 0.0f;
      for (size_t j = 0; j < grades[i].size(); ++j) {
          total += grades[i][j];
      }
      map[total/grades[i].size()] = students[i];
  }

  std::vector<std::string> bestStudents;
  auto it = map.begin();
  for (int i = 0; i < n; ++i, ++it) {
      bestStudents.push_back(it->second);
  }

  return bestStudents;
}

/* Tests (commented out to avoid errors for missing test framework)

#include <random>
#include <algorithm>
#include <sstream>

std::vector<std::string> generateRandomNames(int count) {
    std::vector<std::string> names = {
        "Alice", "Bob", "Charlie", "David", "Emma",
        "Frank", "Grace", "Henry", "Isabel", "Jack",
        "Kelly", "Liam", "Maya", "Noah", "Olivia",
        "Peter", "Quinn", "Rachel", "Sam", "Tara"
    };
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(names.begin(), names.end(), gen);
    return std::vector<std::string>(names.begin(), names.begin() + count);
}

std::vector<std::vector<float>> generateRandomGrades(int numStudents, int numGrades) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::vector<std::vector<float>> grades;
    std::vector<float> averages;
    
    for (int i = 0; i < numStudents; ++i) {
        float newAverage;
        std::vector<float> studentGrades;
        
        do {
            studentGrades.clear();
            float total = 0.0f;
            
            for (int j = 0; j < numGrades; ++j) {
                std::uniform_real_distribution<float> dis(60.0f, 100.0f);
                float grade = std::round(dis(gen) * 10.0f) / 10.0f;
                studentGrades.push_back(grade);
                total += grade;
            }
            
            newAverage = total / numGrades;
            
        } while (std::find(averages.begin(), averages.end(), newAverage) != averages.end());
        
        averages.push_back(newAverage);
        grades.push_back(studentGrades);
    }
    
    return grades;
} // note to self: do not specify that no two averages will be the same, make it
  // a problem for the user next time lol (maybe do similar question requiring priority queue?)

std::vector<std::string> calculateExpectedResult(const std::vector<std::string>& students,
                                               const std::vector<std::vector<float>>& grades,
                                               int n) {
    std::vector<std::pair<float, std::string>> averages;
    
    for (size_t i = 0; i < students.size(); ++i) {
        float total = 0.0f;
        for (size_t j = 0; j < grades[i].size(); ++j) {
          total += grades[i][j];
      }
        float average = total / grades[i].size();
        averages.push_back({average, students[i]});
    }
    
    std::sort(averages.begin(), averages.end(),
              [](const auto& a, const auto& b) { return a.first > b.first; });
    
    std::vector<std::string> bestStudents;
    for (int i = 0; i < n; ++i) {
        bestStudents.push_back(averages[i].second);
    }
    return bestStudents;
}


Describe(tests)
{
    It(exampleTests)
    {
        Assert::That(nBestStudents({"Ben", "Kai"}, {{75, 80}, {77, 89}}, 1), Equals(std::vector<std::string>{"Kai"}));
        Assert::That(nBestStudents({"Dave", "Lisa", "Jen"},
                                  {{60, 65, 70}, {71, 88, 76}, {81, 82, 88}}, 2), Equals(std::vector<std::string>{"Jen", "Lisa"}));
        Assert::That(nBestStudents({"Katie"}, {{66, 74, 71}}, 1), Equals(std::vector<std::string>{"Katie"}));
    }
    It(randomTests)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        
        for (int test = 0; test < 50; ++test) {
            std::uniform_int_distribution<> numStudentsDis(2, 9);
            int numStudents = numStudentsDis(gen);
            
            std::uniform_int_distribution<> numGradesDis(2, 9);
            int numGrades = numGradesDis(gen);
            
            std::uniform_int_distribution<> nDis(1, numStudents);
            int n = nDis(gen);
            
            std::vector<std::string> students = generateRandomNames(numStudents);
            std::vector<std::vector<float>> grades = generateRandomGrades(numStudents, numGrades);
            
            std::vector<std::string> expected = calculateExpectedResult(students, grades, n);
            
            std::vector<std::string> result = nBestStudents(students, grades, n);
            
            std::stringstream msg;
            msg << "Failed with " << numStudents << " students, " << numGrades << " grades, n=" << n;
            
            Assert::That(result, Equals(expected));
        }
    }
    
};

*/
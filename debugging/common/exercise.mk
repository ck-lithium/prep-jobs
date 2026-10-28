# Build rules shared by the debugging exercises; each exercise's Makefile
# includes this file. Run these from inside an exercise folder:
#
#   make test           build and run the visible tests
#   make test T=Merge   run only the tests whose name contains "Merge"
#   make check          run the visible and the hidden tests: your final score
#   make clean          delete the build folder

COMMON   := $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))
CXXFLAGS := -std=c++17 -g -O0 -Wall -Wextra -Isrc -I$(COMMON)
BUILD    := build
VPATH    := src tests $(COMMON)

APP_OBJS := $(patsubst src/%.cpp,$(BUILD)/%.o,$(wildcard src/*.cpp))
RUNNER   := $(BUILD)/minitest_main.o

.PHONY: test check clean

test: $(BUILD)/visible_tests
	@./$(BUILD)/visible_tests $(T)

check: $(BUILD)/all_tests
	@./$(BUILD)/all_tests $(T)

$(BUILD)/visible_tests: $(APP_OBJS) $(RUNNER) $(BUILD)/visible_tests.o
	@$(CXX) $^ -o $@

$(BUILD)/all_tests: $(APP_OBJS) $(RUNNER) $(BUILD)/visible_tests.o $(BUILD)/hidden_tests.o
	@$(CXX) $^ -o $@

$(BUILD)/%.o: %.cpp | $(BUILD)
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD):
	@mkdir -p $@

clean:
	rm -rf $(BUILD)

-include $(wildcard $(BUILD)/*.d)

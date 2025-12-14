TARGET_EXEC := iter_template

BUILD_DIR := ./build
SRC_DIRS := ./src


SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Wextra -Werror -std=c++98 $(ADDITIONALFLAGS)
LDFLAGS:=
CXX:= c++

all: $(TARGET_EXEC)
debug:
	make ADDITIONALFLAGS="-g3"

$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(CPPFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(TARGET_EXEC)

re:: fclean
re:: all


-include $(DEPS)
.PHONY: clean fclean re all


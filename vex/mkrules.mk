# VEXcode mkrules.mk 2019_03_26_01

# compile C files
$(BUILD)/%.o: %.c $(SRC_H)
	$(Q)$(MKDIR)
	$(ECHO) "CC  $<"
	$(Q)$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	
# compile C++ files
$(BUILD)/src/rc.o:src/rc.cpp $(SRC_H) $(SRC_A)
	$(Q)$(MKDIR)
	$(ECHO) "CXX src/rc.cpp"
	$(Q)$(CXX) $(CXX_FLAGS) $(INC) -c -o $(BUILD)/src/rc.o src/rc.cpp 

$(BUILD)/src/main.o:src/main.cpp $(SRC_H) $(SRC_A)
	$(Q)$(MKDIR)
	$(ECHO) "CXX src/main.cpp"
	$(Q)$(CXX) $(CXX_FLAGS) $(INC) -c -o $(BUILD)/src/main.o src/main.cpp 

$(BUILD)/src/auto.o:src/auto.cpp $(SRC_H) $(SRC_A)
	$(Q)$(MKDIR)
	$(ECHO) "CXX src/auto.cpp"
	$(Q)$(CXX) $(CXX_FLAGS) $(INC) -c -o $(BUILD)/src/auto.o src/auto.cpp

$(BUILD)/src/robot-config.o:src/robot-config.cpp $(SRC_H) $(SRC_A)
	$(Q)$(MKDIR)
	$(ECHO) "CXX src/robot-config.cpp"
	$(Q)$(CXX) $(CXX_FLAGS) $(INC) -c -o $(BUILD)/src/robot-config.o src/robot-config.cpp
	
# create executable 
$(BUILD)/$(PROJECT).elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(LINK) $(LNK_FLAGS) -o $@ $^ $(LIBS)
	$(Q)$(SIZE) $@

# create binary 
$(BUILD)/$(PROJECT).bin: $(BUILD)/$(PROJECT).elf
	$(Q)$(OBJCOPY) -O binary $(BUILD)/$(PROJECT).elf $(BUILD)/$(PROJECT).bin

# create archive
$(BUILD)/$(PROJECTLIB).a: $(OBJ)
	$(Q)$(ARCH) $(ARCH_FLAGS) $@ $^

# clean project
clean:
	$(info clean project)
	$(Q)$(CLEAN)

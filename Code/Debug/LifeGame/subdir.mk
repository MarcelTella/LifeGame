################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LifeGame/main.cpp 

CC_SRCS += \
../LifeGame/LifeGame.cc 

OBJS += \
./LifeGame/LifeGame.o \
./LifeGame/main.o 

CC_DEPS += \
./LifeGame/LifeGame.d 

CPP_DEPS += \
./LifeGame/main.d 


# Each subdirectory must supply rules for building sources it contributes
LifeGame/%.o: ../LifeGame/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/marcel/Desktop/eigen-eigen-10219c95fe65/Eigen/src -I/home/marcel/workspace/research-computing-with-cpp-demo/research-computing-with-cpp-demo-build/Eigen/b9c1a/src/Eigen -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

LifeGame/%.o: ../LifeGame/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/marcel/Desktop/eigen-eigen-10219c95fe65/Eigen/src -I/home/marcel/workspace/research-computing-with-cpp-demo/research-computing-with-cpp-demo-build/Eigen/b9c1a/src/Eigen -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



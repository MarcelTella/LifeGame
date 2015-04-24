################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../LifeGameTest.cc 

OBJS += \
./LifeGameTest.o 

CC_DEPS += \
./LifeGameTest.d 


# Each subdirectory must supply rules for building sources it contributes
LifeGameTest.o: ../LifeGameTest.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/marcel/workspace/research-computing-with-cpp-demo/Code/LifeGame/Include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"LifeGameTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



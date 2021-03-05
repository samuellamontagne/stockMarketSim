################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bond.cpp \
../src/Customer.cpp \
../src/Instruments.cpp \
../src/Market.cpp \
../src/Stock.cpp \
../src/stockMarketSim.cpp 

OBJS += \
./src/Bond.o \
./src/Customer.o \
./src/Instruments.o \
./src/Market.o \
./src/Stock.o \
./src/stockMarketSim.o 

CPP_DEPS += \
./src/Bond.d \
./src/Customer.d \
./src/Instruments.d \
./src/Market.d \
./src/Stock.d \
./src/stockMarketSim.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



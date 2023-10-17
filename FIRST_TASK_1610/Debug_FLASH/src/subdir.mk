################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clock.c \
../src/gpio.c \
../src/lpit.c \
../src/lpuart.c \
../src/main.c 

OBJS += \
./src/clock.o \
./src/gpio.o \
./src/lpit.o \
./src/lpuart.o \
./src/main.o 

C_DEPS += \
./src/clock.d \
./src/gpio.d \
./src/lpit.d \
./src/lpuart.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/clock.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



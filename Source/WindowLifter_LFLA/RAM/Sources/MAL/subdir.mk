################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MAL/MAL_WL_System.c" \

C_SRCS += \
../Sources/MAL/MAL_WL_System.c \

OBJS += \
./Sources/MAL/MAL_WL_System_c.obj \

OBJS_QUOTED += \
"./Sources/MAL/MAL_WL_System_c.obj" \

C_DEPS += \
./Sources/MAL/MAL_WL_System_c.d \

OBJS_OS_FORMAT += \
./Sources/MAL/MAL_WL_System_c.obj \

C_DEPS_QUOTED += \
"./Sources/MAL/MAL_WL_System_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/MAL/MAL_WL_System_c.obj: ../Sources/MAL/MAL_WL_System.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/MAL_WL_System.args" -o "Sources/MAL/MAL_WL_System_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MAL/%.d: ../Sources/MAL/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '



#######################################################################
# Include the common makefiles:
#   - Variables:     Sets up the variables with some default values
include make_utils/common_variables.mk
#######################################################################

# Project Name
PROJECT_NAME = move_sematics

POST_BUILD_TASKS  = cd $(BIN_DIR);
POST_BUILD_TASKS += ./$(OUTPUT_FILE);

#######################################################################
# Include the common makefiles:
#   - shared_lib:     Sets the shared library options
#   - warnings:       Set the warning flags for various targets
#   - var_expansions: Generates lists of source, objects etc
#   - rules:          The build rules
include make_utils/common_executable.mk
include make_utils/common_warnings.mk
include make_utils/common_var_autofill.mk
include make_utils/common_rules.mk
#######################################################################

LINKER_CMD = 
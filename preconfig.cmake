#PACK_NAME, PACK_VERSION, PACK_ROOT, and PACK_CONFIG_DIR are all predefined for pre and post config.

find_dependency(glm)

#set(${PACK_NAME}_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")
set(${PACK_NAME}_LIB_DIR "${PACKAGE_PREFIX_DIR}/lib")
set(${PACK_NAME}_SHARE_DIR "${PACKAGE_PREFIX_DIR}/share")
set(${PACK_NAME}_CMAKE_DIR "${PACKAGE_PREFIX_DIR}/share/${PACK_NAME}/cmake")
